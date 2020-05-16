
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "udm_info.h"

OpenAPI_udm_info_t *OpenAPI_udm_info_create(
    char *group_id,
    OpenAPI_list_t *supi_ranges,
    OpenAPI_list_t *gpsi_ranges,
    OpenAPI_list_t *external_group_identifiers_ranges,
    OpenAPI_list_t *routing_indicators
    )
{
    OpenAPI_udm_info_t *udm_info_local_var = OpenAPI_malloc(sizeof(OpenAPI_udm_info_t));
    if (!udm_info_local_var) {
        return NULL;
    }
    udm_info_local_var->group_id = group_id;
    udm_info_local_var->supi_ranges = supi_ranges;
    udm_info_local_var->gpsi_ranges = gpsi_ranges;
    udm_info_local_var->external_group_identifiers_ranges = external_group_identifiers_ranges;
    udm_info_local_var->routing_indicators = routing_indicators;

    return udm_info_local_var;
}

void OpenAPI_udm_info_free(OpenAPI_udm_info_t *udm_info)
{
    if (NULL == udm_info) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(udm_info->group_id);
    OpenAPI_list_for_each(udm_info->supi_ranges, node) {
        OpenAPI_supi_range_free(node->data);
    }
    OpenAPI_list_free(udm_info->supi_ranges);
    OpenAPI_list_for_each(udm_info->gpsi_ranges, node) {
        OpenAPI_identity_range_free(node->data);
    }
    OpenAPI_list_free(udm_info->gpsi_ranges);
    OpenAPI_list_for_each(udm_info->external_group_identifiers_ranges, node) {
        OpenAPI_identity_range_free(node->data);
    }
    OpenAPI_list_free(udm_info->external_group_identifiers_ranges);
    OpenAPI_list_for_each(udm_info->routing_indicators, node) {
        ogs_free(node->data);
    }
    OpenAPI_list_free(udm_info->routing_indicators);
    ogs_free(udm_info);
}

cJSON *OpenAPI_udm_info_convertToJSON(OpenAPI_udm_info_t *udm_info)
{
    cJSON *item = NULL;

    if (udm_info == NULL) {
        ogs_error("OpenAPI_udm_info_convertToJSON() failed [UdmInfo]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (udm_info->group_id) {
        if (cJSON_AddStringToObject(item, "groupId", udm_info->group_id) == NULL) {
            ogs_error("OpenAPI_udm_info_convertToJSON() failed [group_id]");
            goto end;
        }
    }

    if (udm_info->supi_ranges) {
        cJSON *supi_ranges = cJSON_AddArrayToObject(item, "supiRanges");
        if (supi_ranges == NULL) {
            ogs_error("OpenAPI_udm_info_convertToJSON() failed [supi_ranges]");
            goto end;
        }

        OpenAPI_lnode_t *supi_ranges_node;
        if (udm_info->supi_ranges) {
            OpenAPI_list_for_each(udm_info->supi_ranges, supi_ranges_node) {
                cJSON *itemLocal = OpenAPI_supi_range_convertToJSON(supi_ranges_node->data);
                if (itemLocal == NULL) {
                    ogs_error("OpenAPI_udm_info_convertToJSON() failed [supi_ranges]");
                    goto end;
                }
                cJSON_AddItemToArray(supi_ranges, itemLocal);
            }
        }
    }

    if (udm_info->gpsi_ranges) {
        cJSON *gpsi_ranges = cJSON_AddArrayToObject(item, "gpsiRanges");
        if (gpsi_ranges == NULL) {
            ogs_error("OpenAPI_udm_info_convertToJSON() failed [gpsi_ranges]");
            goto end;
        }

        OpenAPI_lnode_t *gpsi_ranges_node;
        if (udm_info->gpsi_ranges) {
            OpenAPI_list_for_each(udm_info->gpsi_ranges, gpsi_ranges_node) {
                cJSON *itemLocal = OpenAPI_identity_range_convertToJSON(gpsi_ranges_node->data);
                if (itemLocal == NULL) {
                    ogs_error("OpenAPI_udm_info_convertToJSON() failed [gpsi_ranges]");
                    goto end;
                }
                cJSON_AddItemToArray(gpsi_ranges, itemLocal);
            }
        }
    }

    if (udm_info->external_group_identifiers_ranges) {
        cJSON *external_group_identifiers_ranges = cJSON_AddArrayToObject(item, "externalGroupIdentifiersRanges");
        if (external_group_identifiers_ranges == NULL) {
            ogs_error("OpenAPI_udm_info_convertToJSON() failed [external_group_identifiers_ranges]");
            goto end;
        }

        OpenAPI_lnode_t *external_group_identifiers_ranges_node;
        if (udm_info->external_group_identifiers_ranges) {
            OpenAPI_list_for_each(udm_info->external_group_identifiers_ranges, external_group_identifiers_ranges_node) {
                cJSON *itemLocal = OpenAPI_identity_range_convertToJSON(external_group_identifiers_ranges_node->data);
                if (itemLocal == NULL) {
                    ogs_error("OpenAPI_udm_info_convertToJSON() failed [external_group_identifiers_ranges]");
                    goto end;
                }
                cJSON_AddItemToArray(external_group_identifiers_ranges, itemLocal);
            }
        }
    }

    if (udm_info->routing_indicators) {
        cJSON *routing_indicators = cJSON_AddArrayToObject(item, "routingIndicators");
        if (routing_indicators == NULL) {
            ogs_error("OpenAPI_udm_info_convertToJSON() failed [routing_indicators]");
            goto end;
        }

        OpenAPI_lnode_t *routing_indicators_node;
        OpenAPI_list_for_each(udm_info->routing_indicators, routing_indicators_node)  {
            if (cJSON_AddStringToObject(routing_indicators, "", (char*)routing_indicators_node->data) == NULL) {
                ogs_error("OpenAPI_udm_info_convertToJSON() failed [routing_indicators]");
                goto end;
            }
        }
    }

end:
    return item;
}

OpenAPI_udm_info_t *OpenAPI_udm_info_parseFromJSON(cJSON *udm_infoJSON)
{
    OpenAPI_udm_info_t *udm_info_local_var = NULL;
    cJSON *group_id = cJSON_GetObjectItemCaseSensitive(udm_infoJSON, "groupId");

    if (group_id) {
        if (!cJSON_IsString(group_id)) {
            ogs_error("OpenAPI_udm_info_parseFromJSON() failed [group_id]");
            goto end;
        }
    }

    cJSON *supi_ranges = cJSON_GetObjectItemCaseSensitive(udm_infoJSON, "supiRanges");

    OpenAPI_list_t *supi_rangesList;
    if (supi_ranges) {
        cJSON *supi_ranges_local_nonprimitive;
        if (!cJSON_IsArray(supi_ranges)) {
            ogs_error("OpenAPI_udm_info_parseFromJSON() failed [supi_ranges]");
            goto end;
        }

        supi_rangesList = OpenAPI_list_create();

        cJSON_ArrayForEach(supi_ranges_local_nonprimitive, supi_ranges ) {
            if (!cJSON_IsObject(supi_ranges_local_nonprimitive)) {
                ogs_error("OpenAPI_udm_info_parseFromJSON() failed [supi_ranges]");
                goto end;
            }
            OpenAPI_supi_range_t *supi_rangesItem = OpenAPI_supi_range_parseFromJSON(supi_ranges_local_nonprimitive);

            OpenAPI_list_add(supi_rangesList, supi_rangesItem);
        }
    }

    cJSON *gpsi_ranges = cJSON_GetObjectItemCaseSensitive(udm_infoJSON, "gpsiRanges");

    OpenAPI_list_t *gpsi_rangesList;
    if (gpsi_ranges) {
        cJSON *gpsi_ranges_local_nonprimitive;
        if (!cJSON_IsArray(gpsi_ranges)) {
            ogs_error("OpenAPI_udm_info_parseFromJSON() failed [gpsi_ranges]");
            goto end;
        }

        gpsi_rangesList = OpenAPI_list_create();

        cJSON_ArrayForEach(gpsi_ranges_local_nonprimitive, gpsi_ranges ) {
            if (!cJSON_IsObject(gpsi_ranges_local_nonprimitive)) {
                ogs_error("OpenAPI_udm_info_parseFromJSON() failed [gpsi_ranges]");
                goto end;
            }
            OpenAPI_identity_range_t *gpsi_rangesItem = OpenAPI_identity_range_parseFromJSON(gpsi_ranges_local_nonprimitive);

            OpenAPI_list_add(gpsi_rangesList, gpsi_rangesItem);
        }
    }

    cJSON *external_group_identifiers_ranges = cJSON_GetObjectItemCaseSensitive(udm_infoJSON, "externalGroupIdentifiersRanges");

    OpenAPI_list_t *external_group_identifiers_rangesList;
    if (external_group_identifiers_ranges) {
        cJSON *external_group_identifiers_ranges_local_nonprimitive;
        if (!cJSON_IsArray(external_group_identifiers_ranges)) {
            ogs_error("OpenAPI_udm_info_parseFromJSON() failed [external_group_identifiers_ranges]");
            goto end;
        }

        external_group_identifiers_rangesList = OpenAPI_list_create();

        cJSON_ArrayForEach(external_group_identifiers_ranges_local_nonprimitive, external_group_identifiers_ranges ) {
            if (!cJSON_IsObject(external_group_identifiers_ranges_local_nonprimitive)) {
                ogs_error("OpenAPI_udm_info_parseFromJSON() failed [external_group_identifiers_ranges]");
                goto end;
            }
            OpenAPI_identity_range_t *external_group_identifiers_rangesItem = OpenAPI_identity_range_parseFromJSON(external_group_identifiers_ranges_local_nonprimitive);

            OpenAPI_list_add(external_group_identifiers_rangesList, external_group_identifiers_rangesItem);
        }
    }

    cJSON *routing_indicators = cJSON_GetObjectItemCaseSensitive(udm_infoJSON, "routingIndicators");

    OpenAPI_list_t *routing_indicatorsList;
    if (routing_indicators) {
        cJSON *routing_indicators_local;
        if (!cJSON_IsArray(routing_indicators)) {
            ogs_error("OpenAPI_udm_info_parseFromJSON() failed [routing_indicators]");
            goto end;
        }
        routing_indicatorsList = OpenAPI_list_create();

        cJSON_ArrayForEach(routing_indicators_local, routing_indicators) {
            if (!cJSON_IsString(routing_indicators_local)) {
                ogs_error("OpenAPI_udm_info_parseFromJSON() failed [routing_indicators]");
                goto end;
            }
            OpenAPI_list_add(routing_indicatorsList, ogs_strdup(routing_indicators_local->valuestring));
        }
    }

    udm_info_local_var = OpenAPI_udm_info_create (
        group_id ? ogs_strdup(group_id->valuestring) : NULL,
        supi_ranges ? supi_rangesList : NULL,
        gpsi_ranges ? gpsi_rangesList : NULL,
        external_group_identifiers_ranges ? external_group_identifiers_rangesList : NULL,
        routing_indicators ? routing_indicatorsList : NULL
        );

    return udm_info_local_var;
end:
    return NULL;
}

