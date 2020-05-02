
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nwdaf_info.h"

nwdaf_info_t *nwdaf_info_create(
    list_t *event_ids,
    list_t *nwdaf_events,
    list_t *tai_list,
    list_t *tai_range_list
    )
{
    nwdaf_info_t *nwdaf_info_local_var = ogs_malloc(sizeof(nwdaf_info_t));
    if (!nwdaf_info_local_var) {
        return NULL;
    }
    nwdaf_info_local_var->event_ids = event_ids;
    nwdaf_info_local_var->nwdaf_events = nwdaf_events;
    nwdaf_info_local_var->tai_list = tai_list;
    nwdaf_info_local_var->tai_range_list = tai_range_list;

    return nwdaf_info_local_var;
}

void nwdaf_info_free(nwdaf_info_t *nwdaf_info)
{
    if(NULL == nwdaf_info) {
        return;
    }
    listEntry_t *listEntry;
    list_ForEach(listEntry, nwdaf_info->event_ids) {
        event_id_free(listEntry->data);
    }
    list_free(nwdaf_info->event_ids);
    list_ForEach(listEntry, nwdaf_info->nwdaf_events) {
        nwdaf_event_free(listEntry->data);
    }
    list_free(nwdaf_info->nwdaf_events);
    list_ForEach(listEntry, nwdaf_info->tai_list) {
        tai_free(listEntry->data);
    }
    list_free(nwdaf_info->tai_list);
    list_ForEach(listEntry, nwdaf_info->tai_range_list) {
        tai_range_free(listEntry->data);
    }
    list_free(nwdaf_info->tai_range_list);
    ogs_free(nwdaf_info);
}

cJSON *nwdaf_info_convertToJSON(nwdaf_info_t *nwdaf_info)
{
    cJSON *item = cJSON_CreateObject();
    if (nwdaf_info->event_ids) {
        cJSON *event_ids = cJSON_AddArrayToObject(item, "eventIds");
        if(event_ids == NULL) {
            goto fail;
        }

        listEntry_t *event_idsListEntry;
        if (nwdaf_info->event_ids) {
            list_ForEach(event_idsListEntry, nwdaf_info->event_ids) {
                cJSON *itemLocal = event_id_convertToJSON(event_idsListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(event_ids, itemLocal);
            }
        }
    }

    if (nwdaf_info->nwdaf_events) {
        cJSON *nwdaf_events = cJSON_AddArrayToObject(item, "nwdafEvents");
        if(nwdaf_events == NULL) {
            goto fail;
        }

        listEntry_t *nwdaf_eventsListEntry;
        if (nwdaf_info->nwdaf_events) {
            list_ForEach(nwdaf_eventsListEntry, nwdaf_info->nwdaf_events) {
                cJSON *itemLocal = nwdaf_event_convertToJSON(nwdaf_eventsListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(nwdaf_events, itemLocal);
            }
        }
    }

    if (nwdaf_info->tai_list) {
        cJSON *tai_list = cJSON_AddArrayToObject(item, "taiList");
        if(tai_list == NULL) {
            goto fail;
        }

        listEntry_t *tai_listListEntry;
        if (nwdaf_info->tai_list) {
            list_ForEach(tai_listListEntry, nwdaf_info->tai_list) {
                cJSON *itemLocal = tai_convertToJSON(tai_listListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(tai_list, itemLocal);
            }
        }
    }

    if (nwdaf_info->tai_range_list) {
        cJSON *tai_range_list = cJSON_AddArrayToObject(item, "taiRangeList");
        if(tai_range_list == NULL) {
            goto fail;
        }

        listEntry_t *tai_range_listListEntry;
        if (nwdaf_info->tai_range_list) {
            list_ForEach(tai_range_listListEntry, nwdaf_info->tai_range_list) {
                cJSON *itemLocal = tai_range_convertToJSON(tai_range_listListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(tai_range_list, itemLocal);
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

nwdaf_info_t *nwdaf_info_parseFromJSON(cJSON *nwdaf_infoJSON)
{
    nwdaf_info_t *nwdaf_info_local_var = NULL;
    cJSON *event_ids = cJSON_GetObjectItemCaseSensitive(nwdaf_infoJSON, "eventIds");

    list_t *event_idsList;
    if (event_ids) {
        cJSON *event_ids_local_nonprimitive;
        if(!cJSON_IsArray(event_ids)) {
            goto end;
        }

        event_idsList = list_create();

        cJSON_ArrayForEach(event_ids_local_nonprimitive,event_ids ) {
            if(!cJSON_IsObject(event_ids_local_nonprimitive)) {
                goto end;
            }
            event_id_t *event_idsItem = event_id_parseFromJSON(event_ids_local_nonprimitive);

            list_addElement(event_idsList, event_idsItem);
        }
    }

    cJSON *nwdaf_events = cJSON_GetObjectItemCaseSensitive(nwdaf_infoJSON, "nwdafEvents");

    list_t *nwdaf_eventsList;
    if (nwdaf_events) {
        cJSON *nwdaf_events_local_nonprimitive;
        if(!cJSON_IsArray(nwdaf_events)) {
            goto end;
        }

        nwdaf_eventsList = list_create();

        cJSON_ArrayForEach(nwdaf_events_local_nonprimitive,nwdaf_events ) {
            if(!cJSON_IsObject(nwdaf_events_local_nonprimitive)) {
                goto end;
            }
            nwdaf_event_t *nwdaf_eventsItem = nwdaf_event_parseFromJSON(nwdaf_events_local_nonprimitive);

            list_addElement(nwdaf_eventsList, nwdaf_eventsItem);
        }
    }

    cJSON *tai_list = cJSON_GetObjectItemCaseSensitive(nwdaf_infoJSON, "taiList");

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

    cJSON *tai_range_list = cJSON_GetObjectItemCaseSensitive(nwdaf_infoJSON, "taiRangeList");

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

    nwdaf_info_local_var = nwdaf_info_create (
        event_ids ? event_idsList : NULL,
        nwdaf_events ? nwdaf_eventsList : NULL,
        tai_list ? tai_listList : NULL,
        tai_range_list ? tai_range_listList : NULL
        );

    return nwdaf_info_local_var;
end:
    return NULL;
}

