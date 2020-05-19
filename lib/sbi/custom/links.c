
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "links.h"

cJSON *ogs_sbi_links_convertToJSON(ogs_sbi_links_t *links)
{
    cJSON *root = NULL;
    cJSON *linksJSON = NULL;
    cJSON *itemsJSON = NULL;
    cJSON *selfJSON = NULL;
    OpenAPI_lnode_t *node;

    ogs_assert(links);
    ogs_assert(links->self);

    root = cJSON_CreateObject();
    ogs_assert(root);

    linksJSON = cJSON_AddObjectToObject(root, "_links");
    ogs_assert(linksJSON);

    itemsJSON = cJSON_AddArrayToObject(linksJSON, "items");
    ogs_assert(itemsJSON);

    OpenAPI_list_for_each(links->items, node) {
        cJSON *object = NULL;

        if (!node->data) continue;

        object = cJSON_CreateObject();
        ogs_assert(object);

        cJSON_AddItemToObject(object, "href", cJSON_CreateString(node->data));
        cJSON_AddItemToArray(itemsJSON, object);
    }

    selfJSON = cJSON_AddObjectToObject(linksJSON, "self");
    ogs_assert(selfJSON);
    cJSON_AddStringToObject(selfJSON, "href", links->self);

    return root;
}
