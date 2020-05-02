
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "guami_list_cond.h"

guami_list_cond_t *guami_list_cond_create(
    list_t *guami_list
    )
{
    guami_list_cond_t *guami_list_cond_local_var = ogs_malloc(sizeof(guami_list_cond_t));
    if (!guami_list_cond_local_var) {
        return NULL;
    }
    guami_list_cond_local_var->guami_list = guami_list;

    return guami_list_cond_local_var;
}

void guami_list_cond_free(guami_list_cond_t *guami_list_cond)
{
    if(NULL == guami_list_cond) {
        return;
    }
    listEntry_t *listEntry;
    list_ForEach(listEntry, guami_list_cond->guami_list) {
        guami_free(listEntry->data);
    }
    list_free(guami_list_cond->guami_list);
    ogs_free(guami_list_cond);
}

cJSON *guami_list_cond_convertToJSON(guami_list_cond_t *guami_list_cond)
{
    cJSON *item = cJSON_CreateObject();
    if (!guami_list_cond->guami_list) {
        goto fail;
    }
    cJSON *guami_list = cJSON_AddArrayToObject(item, "guamiList");
    if(guami_list == NULL) {
        goto fail;
    }

    listEntry_t *guami_listListEntry;
    if (guami_list_cond->guami_list) {
        list_ForEach(guami_listListEntry, guami_list_cond->guami_list) {
            cJSON *itemLocal = guami_convertToJSON(guami_listListEntry->data);
            if(itemLocal == NULL) {
                goto fail;
            }
            cJSON_AddItemToArray(guami_list, itemLocal);
        }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

guami_list_cond_t *guami_list_cond_parseFromJSON(cJSON *guami_list_condJSON)
{
    guami_list_cond_t *guami_list_cond_local_var = NULL;
    cJSON *guami_list = cJSON_GetObjectItemCaseSensitive(guami_list_condJSON, "guamiList");
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

    guami_list_cond_local_var = guami_list_cond_create (
        guami_listList
        );

    return guami_list_cond_local_var;
end:
    return NULL;
}

