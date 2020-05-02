
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "amf_info.h"

amf_info_t *amf_info_create(
    char *amf_set_id,
    char *amf_region_id,
    list_t *guami_list,
    list_t *tai_list,
    list_t *tai_range_list,
    list_t *backup_info_amf_failure,
    list_t *backup_info_amf_removal,
    n2_interface_amf_info_t *n2_interface_amf_info
    )
{
    amf_info_t *amf_info_local_var = ogs_malloc(sizeof(amf_info_t));
    if (!amf_info_local_var) {
        return NULL;
    }
    amf_info_local_var->amf_set_id = amf_set_id;
    amf_info_local_var->amf_region_id = amf_region_id;
    amf_info_local_var->guami_list = guami_list;
    amf_info_local_var->tai_list = tai_list;
    amf_info_local_var->tai_range_list = tai_range_list;
    amf_info_local_var->backup_info_amf_failure = backup_info_amf_failure;
    amf_info_local_var->backup_info_amf_removal = backup_info_amf_removal;
    amf_info_local_var->n2_interface_amf_info = n2_interface_amf_info;

    return amf_info_local_var;
}

void amf_info_free(amf_info_t *amf_info)
{
    if(NULL == amf_info) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(amf_info->amf_set_id);
    ogs_free(amf_info->amf_region_id);
    list_ForEach(listEntry, amf_info->guami_list) {
        guami_free(listEntry->data);
    }
    list_free(amf_info->guami_list);
    list_ForEach(listEntry, amf_info->tai_list) {
        tai_free(listEntry->data);
    }
    list_free(amf_info->tai_list);
    list_ForEach(listEntry, amf_info->tai_range_list) {
        tai_range_free(listEntry->data);
    }
    list_free(amf_info->tai_range_list);
    list_ForEach(listEntry, amf_info->backup_info_amf_failure) {
        guami_free(listEntry->data);
    }
    list_free(amf_info->backup_info_amf_failure);
    list_ForEach(listEntry, amf_info->backup_info_amf_removal) {
        guami_free(listEntry->data);
    }
    list_free(amf_info->backup_info_amf_removal);
    n2_interface_amf_info_free(amf_info->n2_interface_amf_info);
    ogs_free(amf_info);
}

cJSON *amf_info_convertToJSON(amf_info_t *amf_info)
{
    cJSON *item = cJSON_CreateObject();
    if (!amf_info->amf_set_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "amfSetId", amf_info->amf_set_id) == NULL) {
        goto fail;
    }

    if (!amf_info->amf_region_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "amfRegionId", amf_info->amf_region_id) == NULL) {
        goto fail;
    }

    if (!amf_info->guami_list) {
        goto fail;
    }
    cJSON *guami_list = cJSON_AddArrayToObject(item, "guamiList");
    if(guami_list == NULL) {
        goto fail;
    }

    listEntry_t *guami_listListEntry;
    if (amf_info->guami_list) {
        list_ForEach(guami_listListEntry, amf_info->guami_list) {
            cJSON *itemLocal = guami_convertToJSON(guami_listListEntry->data);
            if(itemLocal == NULL) {
                goto fail;
            }
            cJSON_AddItemToArray(guami_list, itemLocal);
        }
    }

    if (amf_info->tai_list) {
        cJSON *tai_list = cJSON_AddArrayToObject(item, "taiList");
        if(tai_list == NULL) {
            goto fail;
        }

        listEntry_t *tai_listListEntry;
        if (amf_info->tai_list) {
            list_ForEach(tai_listListEntry, amf_info->tai_list) {
                cJSON *itemLocal = tai_convertToJSON(tai_listListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(tai_list, itemLocal);
            }
        }
    }

    if (amf_info->tai_range_list) {
        cJSON *tai_range_list = cJSON_AddArrayToObject(item, "taiRangeList");
        if(tai_range_list == NULL) {
            goto fail;
        }

        listEntry_t *tai_range_listListEntry;
        if (amf_info->tai_range_list) {
            list_ForEach(tai_range_listListEntry, amf_info->tai_range_list) {
                cJSON *itemLocal = tai_range_convertToJSON(tai_range_listListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(tai_range_list, itemLocal);
            }
        }
    }

    if (amf_info->backup_info_amf_failure) {
        cJSON *backup_info_amf_failure = cJSON_AddArrayToObject(item, "backupInfoAmfFailure");
        if(backup_info_amf_failure == NULL) {
            goto fail;
        }

        listEntry_t *backup_info_amf_failureListEntry;
        if (amf_info->backup_info_amf_failure) {
            list_ForEach(backup_info_amf_failureListEntry, amf_info->backup_info_amf_failure) {
                cJSON *itemLocal = guami_convertToJSON(backup_info_amf_failureListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(backup_info_amf_failure, itemLocal);
            }
        }
    }

    if (amf_info->backup_info_amf_removal) {
        cJSON *backup_info_amf_removal = cJSON_AddArrayToObject(item, "backupInfoAmfRemoval");
        if(backup_info_amf_removal == NULL) {
            goto fail;
        }

        listEntry_t *backup_info_amf_removalListEntry;
        if (amf_info->backup_info_amf_removal) {
            list_ForEach(backup_info_amf_removalListEntry, amf_info->backup_info_amf_removal) {
                cJSON *itemLocal = guami_convertToJSON(backup_info_amf_removalListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(backup_info_amf_removal, itemLocal);
            }
        }
    }

    if (amf_info->n2_interface_amf_info) {
        cJSON *n2_interface_amf_info_local_JSON = n2_interface_amf_info_convertToJSON(amf_info->n2_interface_amf_info);
        if(n2_interface_amf_info_local_JSON == NULL) {
            goto fail;
        }
        cJSON_AddItemToObject(item, "n2InterfaceAmfInfo", n2_interface_amf_info_local_JSON);
        if(item->child == NULL) {
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

amf_info_t *amf_info_parseFromJSON(cJSON *amf_infoJSON)
{
    amf_info_t *amf_info_local_var = NULL;
    cJSON *amf_set_id = cJSON_GetObjectItemCaseSensitive(amf_infoJSON, "amfSetId");
    if (!amf_set_id) {
        goto end;
    }


    if(!cJSON_IsString(amf_set_id))
    {
        goto end;
    }

    cJSON *amf_region_id = cJSON_GetObjectItemCaseSensitive(amf_infoJSON, "amfRegionId");
    if (!amf_region_id) {
        goto end;
    }


    if(!cJSON_IsString(amf_region_id))
    {
        goto end;
    }

    cJSON *guami_list = cJSON_GetObjectItemCaseSensitive(amf_infoJSON, "guamiList");
    if (!guami_list) {
        goto end;
    }

    list_t *guami_listList;

    cJSON *guami_list_local_nonprimitive;
    if(!cJSON_IsArray(guami_list)) {
        goto end;
    }

    guami_listList = list_create();

    cJSON_ArrayForEach(guami_list_local_nonprimitive,guami_list ) {
        if(!cJSON_IsObject(guami_list_local_nonprimitive)) {
            goto end;
        }
        guami_t *guami_listItem = guami_parseFromJSON(guami_list_local_nonprimitive);

        list_addElement(guami_listList, guami_listItem);
    }

    cJSON *tai_list = cJSON_GetObjectItemCaseSensitive(amf_infoJSON, "taiList");

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

    cJSON *tai_range_list = cJSON_GetObjectItemCaseSensitive(amf_infoJSON, "taiRangeList");

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

    cJSON *backup_info_amf_failure = cJSON_GetObjectItemCaseSensitive(amf_infoJSON, "backupInfoAmfFailure");

    list_t *backup_info_amf_failureList;
    if (backup_info_amf_failure) {
        cJSON *backup_info_amf_failure_local_nonprimitive;
        if(!cJSON_IsArray(backup_info_amf_failure)) {
            goto end;
        }

        backup_info_amf_failureList = list_create();

        cJSON_ArrayForEach(backup_info_amf_failure_local_nonprimitive,backup_info_amf_failure ) {
            if(!cJSON_IsObject(backup_info_amf_failure_local_nonprimitive)) {
                goto end;
            }
            guami_t *backup_info_amf_failureItem = guami_parseFromJSON(backup_info_amf_failure_local_nonprimitive);

            list_addElement(backup_info_amf_failureList, backup_info_amf_failureItem);
        }
    }

    cJSON *backup_info_amf_removal = cJSON_GetObjectItemCaseSensitive(amf_infoJSON, "backupInfoAmfRemoval");

    list_t *backup_info_amf_removalList;
    if (backup_info_amf_removal) {
        cJSON *backup_info_amf_removal_local_nonprimitive;
        if(!cJSON_IsArray(backup_info_amf_removal)) {
            goto end;
        }

        backup_info_amf_removalList = list_create();

        cJSON_ArrayForEach(backup_info_amf_removal_local_nonprimitive,backup_info_amf_removal ) {
            if(!cJSON_IsObject(backup_info_amf_removal_local_nonprimitive)) {
                goto end;
            }
            guami_t *backup_info_amf_removalItem = guami_parseFromJSON(backup_info_amf_removal_local_nonprimitive);

            list_addElement(backup_info_amf_removalList, backup_info_amf_removalItem);
        }
    }

    cJSON *n2_interface_amf_info = cJSON_GetObjectItemCaseSensitive(amf_infoJSON, "n2InterfaceAmfInfo");

    n2_interface_amf_info_t *n2_interface_amf_info_local_nonprim = NULL;
    if (n2_interface_amf_info) {
        n2_interface_amf_info_local_nonprim = n2_interface_amf_info_parseFromJSON(n2_interface_amf_info);
    }

    amf_info_local_var = amf_info_create (
        ogs_strdup(amf_set_id->valuestring),
        ogs_strdup(amf_region_id->valuestring),
        guami_listList,
        tai_list ? tai_listList : NULL,
        tai_range_list ? tai_range_listList : NULL,
        backup_info_amf_failure ? backup_info_amf_failureList : NULL,
        backup_info_amf_removal ? backup_info_amf_removalList : NULL,
        n2_interface_amf_info ? n2_interface_amf_info_local_nonprim : NULL
        );

    return amf_info_local_var;
end:
    return NULL;
}

