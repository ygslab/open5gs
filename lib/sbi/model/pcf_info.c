
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pcf_info.h"

pcf_info_t *pcf_info_create(
    char *group_id,
    list_t *dnn_list,
    list_t *supi_ranges,
    list_t *gpsi_ranges,
    char *rx_diam_host,
    char *rx_diam_realm
    )
{
    pcf_info_t *pcf_info_local_var = ogs_malloc(sizeof(pcf_info_t));
    if (!pcf_info_local_var) {
        return NULL;
    }
    pcf_info_local_var->group_id = group_id;
    pcf_info_local_var->dnn_list = dnn_list;
    pcf_info_local_var->supi_ranges = supi_ranges;
    pcf_info_local_var->gpsi_ranges = gpsi_ranges;
    pcf_info_local_var->rx_diam_host = rx_diam_host;
    pcf_info_local_var->rx_diam_realm = rx_diam_realm;

    return pcf_info_local_var;
}

void pcf_info_free(pcf_info_t *pcf_info)
{
    if(NULL == pcf_info) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(pcf_info->group_id);
    list_ForEach(listEntry, pcf_info->dnn_list) {
        ogs_free(listEntry->data);
    }
    list_free(pcf_info->dnn_list);
    list_ForEach(listEntry, pcf_info->supi_ranges) {
        supi_range_free(listEntry->data);
    }
    list_free(pcf_info->supi_ranges);
    list_ForEach(listEntry, pcf_info->gpsi_ranges) {
        identity_range_free(listEntry->data);
    }
    list_free(pcf_info->gpsi_ranges);
    ogs_free(pcf_info->rx_diam_host);
    ogs_free(pcf_info->rx_diam_realm);
    ogs_free(pcf_info);
}

cJSON *pcf_info_convertToJSON(pcf_info_t *pcf_info)
{
    cJSON *item = cJSON_CreateObject();
    if (pcf_info->group_id) {
        if(cJSON_AddStringToObject(item, "groupId", pcf_info->group_id) == NULL) {
            goto fail;
        }
    }

    if (pcf_info->dnn_list) {
        cJSON *dnn_list = cJSON_AddArrayToObject(item, "dnnList");
        if(dnn_list == NULL) {
            goto fail;
        }

        listEntry_t *dnn_listListEntry;
        list_ForEach(dnn_listListEntry, pcf_info->dnn_list) {
            if(cJSON_AddStringToObject(dnn_list, "", (char*)dnn_listListEntry->data) == NULL) {
                goto fail;
            }
        }
    }

    if (pcf_info->supi_ranges) {
        cJSON *supi_ranges = cJSON_AddArrayToObject(item, "supiRanges");
        if(supi_ranges == NULL) {
            goto fail;
        }

        listEntry_t *supi_rangesListEntry;
        if (pcf_info->supi_ranges) {
            list_ForEach(supi_rangesListEntry, pcf_info->supi_ranges) {
                cJSON *itemLocal = supi_range_convertToJSON(supi_rangesListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(supi_ranges, itemLocal);
            }
        }
    }

    if (pcf_info->gpsi_ranges) {
        cJSON *gpsi_ranges = cJSON_AddArrayToObject(item, "gpsiRanges");
        if(gpsi_ranges == NULL) {
            goto fail;
        }

        listEntry_t *gpsi_rangesListEntry;
        if (pcf_info->gpsi_ranges) {
            list_ForEach(gpsi_rangesListEntry, pcf_info->gpsi_ranges) {
                cJSON *itemLocal = identity_range_convertToJSON(gpsi_rangesListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(gpsi_ranges, itemLocal);
            }
        }
    }

    if (pcf_info->rx_diam_host) {
        if(cJSON_AddStringToObject(item, "rxDiamHost", pcf_info->rx_diam_host) == NULL) {
            goto fail;
        }
    }

    if (pcf_info->rx_diam_realm) {
        if(cJSON_AddStringToObject(item, "rxDiamRealm", pcf_info->rx_diam_realm) == NULL) {
            goto fail;
        }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

pcf_info_t *pcf_info_parseFromJSON(cJSON *pcf_infoJSON)
{
    pcf_info_t *pcf_info_local_var = NULL;
    cJSON *group_id = cJSON_GetObjectItemCaseSensitive(pcf_infoJSON, "groupId");

    if (group_id) {
        if(!cJSON_IsString(group_id))
        {
            goto end;
        }
    }

    cJSON *dnn_list = cJSON_GetObjectItemCaseSensitive(pcf_infoJSON, "dnnList");

    list_t *dnn_listList;
    if (dnn_list) {
        cJSON *dnn_list_local;
        if(!cJSON_IsArray(dnn_list)) {
            goto end;
        }
        dnn_listList = list_create();

        cJSON_ArrayForEach(dnn_list_local, dnn_list) {
            if(!cJSON_IsString(dnn_list_local)) {
                goto end;
            }
            list_addElement(dnn_listList, ogs_strdup(dnn_list_local->valuestring));
        }
    }

    cJSON *supi_ranges = cJSON_GetObjectItemCaseSensitive(pcf_infoJSON, "supiRanges");

    list_t *supi_rangesList;
    if (supi_ranges) {
        cJSON *supi_ranges_local_nonprimitive;
        if(!cJSON_IsArray(supi_ranges)) {
            goto end;
        }

        supi_rangesList = list_create();

        cJSON_ArrayForEach(supi_ranges_local_nonprimitive,supi_ranges ) {
            if(!cJSON_IsObject(supi_ranges_local_nonprimitive)) {
                goto end;
            }
            supi_range_t *supi_rangesItem = supi_range_parseFromJSON(supi_ranges_local_nonprimitive);

            list_addElement(supi_rangesList, supi_rangesItem);
        }
    }

    cJSON *gpsi_ranges = cJSON_GetObjectItemCaseSensitive(pcf_infoJSON, "gpsiRanges");

    list_t *gpsi_rangesList;
    if (gpsi_ranges) {
        cJSON *gpsi_ranges_local_nonprimitive;
        if(!cJSON_IsArray(gpsi_ranges)) {
            goto end;
        }

        gpsi_rangesList = list_create();

        cJSON_ArrayForEach(gpsi_ranges_local_nonprimitive,gpsi_ranges ) {
            if(!cJSON_IsObject(gpsi_ranges_local_nonprimitive)) {
                goto end;
            }
            identity_range_t *gpsi_rangesItem = identity_range_parseFromJSON(gpsi_ranges_local_nonprimitive);

            list_addElement(gpsi_rangesList, gpsi_rangesItem);
        }
    }

    cJSON *rx_diam_host = cJSON_GetObjectItemCaseSensitive(pcf_infoJSON, "rxDiamHost");

    if (rx_diam_host) {
        if(!cJSON_IsString(rx_diam_host))
        {
            goto end;
        }
    }

    cJSON *rx_diam_realm = cJSON_GetObjectItemCaseSensitive(pcf_infoJSON, "rxDiamRealm");

    if (rx_diam_realm) {
        if(!cJSON_IsString(rx_diam_realm))
        {
            goto end;
        }
    }

    pcf_info_local_var = pcf_info_create (
        group_id ? ogs_strdup(group_id->valuestring) : NULL,
        dnn_list ? dnn_listList : NULL,
        supi_ranges ? supi_rangesList : NULL,
        gpsi_ranges ? gpsi_rangesList : NULL,
        rx_diam_host ? ogs_strdup(rx_diam_host->valuestring) : NULL,
        rx_diam_realm ? ogs_strdup(rx_diam_realm->valuestring) : NULL
        );

    return pcf_info_local_var;
end:
    return NULL;
}

