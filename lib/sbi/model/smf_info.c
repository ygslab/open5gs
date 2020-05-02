
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "smf_info.h"

smf_info_t *smf_info_create(
    list_t *s_nssai_smf_info_list,
    list_t *tai_list,
    list_t *tai_range_list,
    char *pgw_fqdn,
    list_t *access_type
    )
{
    smf_info_t *smf_info_local_var = ogs_malloc(sizeof(smf_info_t));
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

void smf_info_free(smf_info_t *smf_info)
{
    if(NULL == smf_info) {
        return;
    }
    listEntry_t *listEntry;
    list_ForEach(listEntry, smf_info->s_nssai_smf_info_list) {
        snssai_smf_info_item_free(listEntry->data);
    }
    list_free(smf_info->s_nssai_smf_info_list);
    list_ForEach(listEntry, smf_info->tai_list) {
        tai_free(listEntry->data);
    }
    list_free(smf_info->tai_list);
    list_ForEach(listEntry, smf_info->tai_range_list) {
        tai_range_free(listEntry->data);
    }
    list_free(smf_info->tai_range_list);
    ogs_free(smf_info->pgw_fqdn);
    list_free(smf_info->access_type);
    ogs_free(smf_info);
}

cJSON *smf_info_convertToJSON(smf_info_t *smf_info)
{
    cJSON *item = cJSON_CreateObject();
    if (!smf_info->s_nssai_smf_info_list) {
        goto fail;
    }
    cJSON *s_nssai_smf_info_list = cJSON_AddArrayToObject(item, "sNssaiSmfInfoList");
    if(s_nssai_smf_info_list == NULL) {
        goto fail;
    }

    listEntry_t *s_nssai_smf_info_listListEntry;
    if (smf_info->s_nssai_smf_info_list) {
        list_ForEach(s_nssai_smf_info_listListEntry, smf_info->s_nssai_smf_info_list) {
            cJSON *itemLocal = snssai_smf_info_item_convertToJSON(s_nssai_smf_info_listListEntry->data);
            if(itemLocal == NULL) {
                goto fail;
            }
            cJSON_AddItemToArray(s_nssai_smf_info_list, itemLocal);
        }
    }

    if (smf_info->tai_list) {
        cJSON *tai_list = cJSON_AddArrayToObject(item, "taiList");
        if(tai_list == NULL) {
            goto fail;
        }

        listEntry_t *tai_listListEntry;
        if (smf_info->tai_list) {
            list_ForEach(tai_listListEntry, smf_info->tai_list) {
                cJSON *itemLocal = tai_convertToJSON(tai_listListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(tai_list, itemLocal);
            }
        }
    }

    if (smf_info->tai_range_list) {
        cJSON *tai_range_list = cJSON_AddArrayToObject(item, "taiRangeList");
        if(tai_range_list == NULL) {
            goto fail;
        }

        listEntry_t *tai_range_listListEntry;
        if (smf_info->tai_range_list) {
            list_ForEach(tai_range_listListEntry, smf_info->tai_range_list) {
                cJSON *itemLocal = tai_range_convertToJSON(tai_range_listListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(tai_range_list, itemLocal);
            }
        }
    }

    if (smf_info->pgw_fqdn) {
        if(cJSON_AddStringToObject(item, "pgwFqdn", smf_info->pgw_fqdn) == NULL) {
            goto fail;
        }
    }

    if (smf_info->access_type) {
        cJSON *access_type = cJSON_AddArrayToObject(item, "accessType");
        if(access_type == NULL) {
            goto fail;
        }
        listEntry_t *access_typeListEntry;
        list_ForEach(access_typeListEntry, smf_info->access_type) {
            if(cJSON_AddStringToObject(access_type, "", access_type_ToString((access_type_e)access_typeListEntry->data)) == NULL) {
                goto fail;
            }
        }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

smf_info_t *smf_info_parseFromJSON(cJSON *smf_infoJSON)
{
    smf_info_t *smf_info_local_var = NULL;
    cJSON *s_nssai_smf_info_list = cJSON_GetObjectItemCaseSensitive(smf_infoJSON, "sNssaiSmfInfoList");
    if (!s_nssai_smf_info_list) {
        goto end;
    }

    list_t *s_nssai_smf_info_listList;

    cJSON *s_nssai_smf_info_list_local_nonprimitive;
    if(!cJSON_IsArray(s_nssai_smf_info_list)) {
        goto end;
    }

    s_nssai_smf_info_listList = list_create();

    cJSON_ArrayForEach(s_nssai_smf_info_list_local_nonprimitive,s_nssai_smf_info_list ) {
        if(!cJSON_IsObject(s_nssai_smf_info_list_local_nonprimitive)) {
            goto end;
        }
        snssai_smf_info_item_t *s_nssai_smf_info_listItem = snssai_smf_info_item_parseFromJSON(s_nssai_smf_info_list_local_nonprimitive);

        list_addElement(s_nssai_smf_info_listList, s_nssai_smf_info_listItem);
    }

    cJSON *tai_list = cJSON_GetObjectItemCaseSensitive(smf_infoJSON, "taiList");

    list_t *tai_listList;
    if (tai_list) {
        cJSON *tai_list_local_nonprimitive;
        if(!cJSON_IsArray(tai_list)) {
            goto end;
        }

        tai_listList = list_create();

        cJSON_ArrayForEach(tai_list_local_nonprimitive,tai_list ) {
            if(!cJSON_IsObject(tai_list_local_nonprimitive)) {
                goto end;
            }
            tai_t *tai_listItem = tai_parseFromJSON(tai_list_local_nonprimitive);

            list_addElement(tai_listList, tai_listItem);
        }
    }

    cJSON *tai_range_list = cJSON_GetObjectItemCaseSensitive(smf_infoJSON, "taiRangeList");

    list_t *tai_range_listList;
    if (tai_range_list) {
        cJSON *tai_range_list_local_nonprimitive;
        if(!cJSON_IsArray(tai_range_list)) {
            goto end;
        }

        tai_range_listList = list_create();

        cJSON_ArrayForEach(tai_range_list_local_nonprimitive,tai_range_list ) {
            if(!cJSON_IsObject(tai_range_list_local_nonprimitive)) {
                goto end;
            }
            tai_range_t *tai_range_listItem = tai_range_parseFromJSON(tai_range_list_local_nonprimitive);

            list_addElement(tai_range_listList, tai_range_listItem);
        }
    }

    cJSON *pgw_fqdn = cJSON_GetObjectItemCaseSensitive(smf_infoJSON, "pgwFqdn");

    if (pgw_fqdn) {
        if(!cJSON_IsString(pgw_fqdn))
        {
            goto end;
        }
    }

    cJSON *access_type = cJSON_GetObjectItemCaseSensitive(smf_infoJSON, "accessType");

    list_t *access_typeList;
    if (access_type) {
        cJSON *access_type_local_nonprimitive;
        if(!cJSON_IsArray(access_type)) {
            goto end;
        }

        access_typeList = list_create();

        cJSON_ArrayForEach(access_type_local_nonprimitive, access_type ) {
            if(!cJSON_IsString(access_type_local_nonprimitive)) {
                goto end;
            }

            list_addElement(access_typeList, (void *)access_type_FromString(access_type_local_nonprimitive->valuestring));
        }
    }

    smf_info_local_var = smf_info_create (
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

