
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200.h"

inline_response_200_t *inline_response_200_create(
    list_t* _links
    )
{
    inline_response_200_t *inline_response_200_local_var = ogs_malloc(sizeof(inline_response_200_t));
    if (!inline_response_200_local_var) {
        return NULL;
    }
    inline_response_200_local_var->_links = _links;

    return inline_response_200_local_var;
}

void inline_response_200_free(inline_response_200_t *inline_response_200)
{
    if(NULL == inline_response_200) {
        return;
    }
    listEntry_t *listEntry;
    list_ForEach(listEntry, inline_response_200->_links) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
        links_value_schema_free(localKeyValue->value);
        ogs_free(localKeyValue);
    }
    list_free(inline_response_200->_links);
    ogs_free(inline_response_200);
}

cJSON *inline_response_200_convertToJSON(inline_response_200_t *inline_response_200)
{
    cJSON *item = cJSON_CreateObject();
    if (inline_response_200->_links) {
        cJSON *_links = cJSON_AddObjectToObject(item, "_links");
        if(_links == NULL) {
            goto fail;
        }
        cJSON *localMapObject = _links;
        listEntry_t *_linksListEntry;
        if (inline_response_200->_links) {
            list_ForEach(_linksListEntry, inline_response_200->_links) {
                keyValuePair_t *localKeyValue = (keyValuePair_t*)_linksListEntry->data;
                cJSON *itemLocal = links_value_schema_convertToJSON(localKeyValue->value);
                if (itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToObject(_links, localKeyValue->key, itemLocal);
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

inline_response_200_t *inline_response_200_parseFromJSON(cJSON *inline_response_200JSON)
{
    inline_response_200_t *inline_response_200_local_var = NULL;
    cJSON *_links = cJSON_GetObjectItemCaseSensitive(inline_response_200JSON, "_links");

    list_t *_linksList;
    if (_links) {
        cJSON *_links_local_map;
        if(!cJSON_IsObject(_links)) {
            goto end;
        }
        _linksList = list_create();
        keyValuePair_t *localMapKeyPair = NULL;
        cJSON_ArrayForEach(_links_local_map, _links) {
            cJSON *localMapObject = _links_local_map;
            if(!cJSON_IsObject(_links_local_map)) {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(
                localMapObject->string, links_value_schema_parseFromJSON(localMapObject));
            list_addElement(_linksList, localMapKeyPair);
        }
    }

    inline_response_200_local_var = inline_response_200_create (
        _links ? _linksList : NULL
        );

    return inline_response_200_local_var;
end:
    return NULL;
}

