
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "links.h"

cJSON *ogs_sbi_links_convertToJSON(ogs_sbi_links_t *links)
{
    cJSON *root = NULL;
    cJSON *linksJSON = NULL;
    cJSON *itemsJSON = NULL;
    cJSON *self = NULL;
    cJSON *object = NULL;

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
        if (!node->data) continue;

        object = cJSON_CreateObject();
        ogs_assert(object);

        cJSON_AddItemToObject(object, "href", cJSON_CreateString(node->data));
        cJSON_AddItemToArray(itemsJSON, object);
    }

    self = cJSON_CreateObject();
    ogs_assert(self);

    ogs_assert(links->self);
    object = cJSON_CreateString(links->self);
    ogs_assert(object);

    cJSON_AddItemToObject(self, "href", object);
    cJSON_AddItemToObject(linksJSON, "self", self);

    return root;
}
