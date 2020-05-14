
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "smf_info.h"

ogs_sbi_smf_info_t *ogs_sbi_smf_info_create(
    ogs_sbi_list_t *s_nssai_smf_info_list,
    ogs_sbi_list_t *tai_list,
    ogs_sbi_list_t *tai_range_list,
    char *pgw_fqdn,
    ogs_sbi_list_t *access_type
    )
{
    ogs_sbi_smf_info_t *smf_info_local_var = ogs_sbi_malloc(sizeof(ogs_sbi_smf_info_t));
    if (!smf_info_local_var) {
        return NULL;
    }
    smf_info_local_var->s_nssai_smf_info_list = s_nssai_smf_info_list;
    smf_info_local_var->tai_list = tai_list;
    smf_info_local_var->tai_range_list = tai_range_list;
    smf_info_local_var->pgw_fqdn = pgw_fqdn;
    smf_info_local_var->access_type = access_type;

    return smf_info_local_var;
}

void ogs_sbi_smf_info_free(ogs_sbi_smf_info_t *smf_info)
{
    if (NULL == smf_info) {
        return;
    }
    ogs_sbi_lnode_t *node;
    ogs_sbi_list_for_each(smf_info->s_nssai_smf_info_list, node) {
        ogs_sbi_snssai_smf_info_item_free(node->data);
    }
    ogs_sbi_list_free(smf_info->s_nssai_smf_info_list);
    ogs_sbi_list_for_each(smf_info->tai_list, node) {
        ogs_sbi_tai_free(node->data);
    }
    ogs_sbi_list_free(smf_info->tai_list);
    ogs_sbi_list_for_each(smf_info->tai_range_list, node) {
        ogs_sbi_tai_range_free(node->data);
    }
    ogs_sbi_list_free(smf_info->tai_range_list);
    ogs_free(smf_info->pgw_fqdn);
    ogs_sbi_list_free(smf_info->access_type);
    ogs_free(smf_info);
}

cJSON *ogs_sbi_smf_info_convertToJSON(ogs_sbi_smf_info_t *smf_info)
{
    cJSON *item = cJSON_CreateObject();
    if (!smf_info->s_nssai_smf_info_list) {
        ogs_error("ogs_sbi_smf_info_convertToJSON() failed [s_nssai_smf_info_list]");
        goto end;
    }
    cJSON *s_nssai_smf_info_list = cJSON_AddArrayToObject(item, "sNssaiSmfInfoList");
    if (s_nssai_smf_info_list == NULL) {
        ogs_error("ogs_sbi_smf_info_convertToJSON() failed [s_nssai_smf_info_list]");
        goto end;
    }

    ogs_sbi_lnode_t *s_nssai_smf_info_list_node;
    if (smf_info->s_nssai_smf_info_list) {
        ogs_sbi_list_for_each(smf_info->s_nssai_smf_info_list, s_nssai_smf_info_list_node) {
            cJSON *itemLocal = ogs_sbi_snssai_smf_info_item_convertToJSON(s_nssai_smf_info_list_node->data);
            if (itemLocal == NULL) {
                ogs_error("ogs_sbi_smf_info_convertToJSON() failed [s_nssai_smf_info_list]");
                goto end;
            }
            cJSON_AddItemToArray(s_nssai_smf_info_list, itemLocal);
        }
    }

    if (smf_info->tai_list) {
        cJSON *tai_list = cJSON_AddArrayToObject(item, "taiList");
        if (tai_list == NULL) {
            ogs_error("ogs_sbi_smf_info_convertToJSON() failed [tai_list]");
            goto end;
        }

        ogs_sbi_lnode_t *tai_list_node;
        if (smf_info->tai_list) {
            ogs_sbi_list_for_each(smf_info->tai_list, tai_list_node) {
                cJSON *itemLocal = ogs_sbi_tai_convertToJSON(tai_list_node->data);
                if (itemLocal == NULL) {
                    ogs_error("ogs_sbi_smf_info_convertToJSON() failed [tai_list]");
                    goto end;
                }
                cJSON_AddItemToArray(tai_list, itemLocal);
            }
        }
    }

    if (smf_info->tai_range_list) {
        cJSON *tai_range_list = cJSON_AddArrayToObject(item, "taiRangeList");
        if (tai_range_list == NULL) {
            ogs_error("ogs_sbi_smf_info_convertToJSON() failed [tai_range_list]");
            goto end;
        }

        ogs_sbi_lnode_t *tai_range_list_node;
        if (smf_info->tai_range_list) {
            ogs_sbi_list_for_each(smf_info->tai_range_list, tai_range_list_node) {
                cJSON *itemLocal = ogs_sbi_tai_range_convertToJSON(tai_range_list_node->data);
                if (itemLocal == NULL) {
                    ogs_error("ogs_sbi_smf_info_convertToJSON() failed [tai_range_list]");
                    goto end;
                }
                cJSON_AddItemToArray(tai_range_list, itemLocal);
            }
        }
    }

    if (smf_info->pgw_fqdn) {
        if (cJSON_AddStringToObject(item, "pgwFqdn", smf_info->pgw_fqdn) == NULL) {
            ogs_error("ogs_sbi_smf_info_convertToJSON() failed [pgw_fqdn]");
            goto end;
        }
    }

    if (smf_info->access_type) {
        cJSON *access_type = cJSON_AddArrayToObject(item, "accessType");
        if (access_type == NULL) {
            ogs_error("ogs_sbi_smf_info_convertToJSON() failed [access_type]");
            goto end;
        }
        ogs_sbi_lnode_t *access_type_node;
        ogs_sbi_list_for_each(smf_info->access_type, access_type_node) {
            if (cJSON_AddStringToObject(access_type, "", ogs_sbi_access_type_ToString((ogs_sbi_access_type_e)access_type_node->data)) == NULL) {
                ogs_error("ogs_sbi_smf_info_convertToJSON() failed [access_type]");
                goto end;
            }
        }
    }

end:
    return item;
}

ogs_sbi_smf_info_t *ogs_sbi_smf_info_parseFromJSON(cJSON *smf_infoJSON)
{
    ogs_sbi_smf_info_t *smf_info_local_var = NULL;
    cJSON *s_nssai_smf_info_list = cJSON_GetObjectItemCaseSensitive(smf_infoJSON, "sNssaiSmfInfoList");
    if (!s_nssai_smf_info_list) {
        ogs_error("ogs_sbi_smf_info_parseFromJSON() failed [s_nssai_smf_info_list]");
        goto end;
    }

    ogs_sbi_list_t *s_nssai_smf_info_listList;

    cJSON *s_nssai_smf_info_list_local_nonprimitive;
    if (!cJSON_IsArray(s_nssai_smf_info_list)) {
        ogs_error("ogs_sbi_smf_info_parseFromJSON() failed [s_nssai_smf_info_list]");
        goto end;
    }

    s_nssai_smf_info_listList = ogs_sbi_list_create();

    cJSON_ArrayForEach(s_nssai_smf_info_list_local_nonprimitive, s_nssai_smf_info_list ) {
        if (!cJSON_IsObject(s_nssai_smf_info_list_local_nonprimitive)) {
            ogs_error("ogs_sbi_smf_info_parseFromJSON() failed [s_nssai_smf_info_list]");
            goto end;
        }
        ogs_sbi_snssai_smf_info_item_t *s_nssai_smf_info_listItem = ogs_sbi_snssai_smf_info_item_parseFromJSON(s_nssai_smf_info_list_local_nonprimitive);

        ogs_sbi_list_add(s_nssai_smf_info_listList, s_nssai_smf_info_listItem);
    }

    cJSON *tai_list = cJSON_GetObjectItemCaseSensitive(smf_infoJSON, "taiList");

    ogs_sbi_list_t *tai_listList;
    if (tai_list) {
        cJSON *tai_list_local_nonprimitive;
        if (!cJSON_IsArray(tai_list)) {
            ogs_error("ogs_sbi_smf_info_parseFromJSON() failed [tai_list]");
            goto end;
        }

        tai_listList = ogs_sbi_list_create();

        cJSON_ArrayForEach(tai_list_local_nonprimitive, tai_list ) {
            if (!cJSON_IsObject(tai_list_local_nonprimitive)) {
                ogs_error("ogs_sbi_smf_info_parseFromJSON() failed [tai_list]");
                goto end;
            }
            ogs_sbi_tai_t *tai_listItem = ogs_sbi_tai_parseFromJSON(tai_list_local_nonprimitive);

            ogs_sbi_list_add(tai_listList, tai_listItem);
        }
    }

    cJSON *tai_range_list = cJSON_GetObjectItemCaseSensitive(smf_infoJSON, "taiRangeList");

    ogs_sbi_list_t *tai_range_listList;
    if (tai_range_list) {
        cJSON *tai_range_list_local_nonprimitive;
        if (!cJSON_IsArray(tai_range_list)) {
            ogs_error("ogs_sbi_smf_info_parseFromJSON() failed [tai_range_list]");
            goto end;
        }

        tai_range_listList = ogs_sbi_list_create();

        cJSON_ArrayForEach(tai_range_list_local_nonprimitive, tai_range_list ) {
            if (!cJSON_IsObject(tai_range_list_local_nonprimitive)) {
                ogs_error("ogs_sbi_smf_info_parseFromJSON() failed [tai_range_list]");
                goto end;
            }
            ogs_sbi_tai_range_t *tai_range_listItem = ogs_sbi_tai_range_parseFromJSON(tai_range_list_local_nonprimitive);

            ogs_sbi_list_add(tai_range_listList, tai_range_listItem);
        }
    }

    cJSON *pgw_fqdn = cJSON_GetObjectItemCaseSensitive(smf_infoJSON, "pgwFqdn");

    if (pgw_fqdn) {
        if (!cJSON_IsString(pgw_fqdn)) {
            ogs_error("ogs_sbi_smf_info_parseFromJSON() failed [pgw_fqdn]");
            goto end;
        }
    }

    cJSON *access_type = cJSON_GetObjectItemCaseSensitive(smf_infoJSON, "accessType");

    ogs_sbi_list_t *access_typeList;
    if (access_type) {
        cJSON *access_type_local_nonprimitive;
        if (!cJSON_IsArray(access_type)) {
            ogs_error("ogs_sbi_smf_info_parseFromJSON() failed [access_type]");
            goto end;
        }

        access_typeList = ogs_sbi_list_create();

        cJSON_ArrayForEach(access_type_local_nonprimitive, access_type ) {
            if (!cJSON_IsString(access_type_local_nonprimitive)) {
                ogs_error("ogs_sbi_smf_info_parseFromJSON() failed [access_type]");
                goto end;
            }

            ogs_sbi_list_add(access_typeList, (void *)ogs_sbi_access_type_FromString(access_type_local_nonprimitive->valuestring));
        }
    }

    smf_info_local_var = ogs_sbi_smf_info_create (
        s_nssai_smf_info_listList,
        tai_list ? tai_listList : NULL,
        tai_range_list ? tai_range_listList : NULL,
        pgw_fqdn ? ogs_strdup(pgw_fqdn->valuestring) : NULL,
        access_type ? access_typeList : NULL
        );

    return smf_info_local_var;
end:
    return NULL;
}

