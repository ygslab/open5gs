
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "change_item.h"

ogs_sbi_change_item_t *ogs_sbi_change_item_create(
    ogs_sbi_change_type_e op,
    char *path,
    char *from,
    char *orig_value,
    char *new_value
    )
{
    ogs_sbi_change_item_t *change_item_local_var = ogs_sbi_malloc(sizeof(ogs_sbi_change_item_t));
    if (!change_item_local_var) {
        return NULL;
    }
    change_item_local_var->op = op;
    change_item_local_var->path = path;
    change_item_local_var->from = from;
    change_item_local_var->orig_value = orig_value;
    change_item_local_var->new_value = new_value;

    return change_item_local_var;
}

void ogs_sbi_change_item_free(ogs_sbi_change_item_t *change_item)
{
    if (NULL == change_item) {
        return;
    }
    ogs_sbi_lnode_t *node;
    ogs_free(change_item->path);
    ogs_free(change_item->from);
    ogs_free(change_item->orig_value);
    ogs_free(change_item->new_value);
    ogs_free(change_item);
}

cJSON *ogs_sbi_change_item_convertToJSON(ogs_sbi_change_item_t *change_item)
{
    cJSON *item = cJSON_CreateObject();
    if (!change_item->op) {
        ogs_error("ogs_sbi_change_item_convertToJSON() failed [op]");
        goto end;
    }
    if (cJSON_AddStringToObject(item, "op", ogs_sbi_change_type_ToString(change_item->op)) == NULL) {
        ogs_error("ogs_sbi_change_item_convertToJSON() failed [op]");
        goto end;
    }

    if (!change_item->path) {
        ogs_error("ogs_sbi_change_item_convertToJSON() failed [path]");
        goto end;
    }
    if (cJSON_AddStringToObject(item, "path", change_item->path) == NULL) {
        ogs_error("ogs_sbi_change_item_convertToJSON() failed [path]");
        goto end;
    }

    if (change_item->from) {
        if (cJSON_AddStringToObject(item, "from", change_item->from) == NULL) {
            ogs_error("ogs_sbi_change_item_convertToJSON() failed [from]");
            goto end;
        }
    }

    if (change_item->orig_value) {
        if (cJSON_AddStringToObject(item, "origValue", change_item->orig_value) == NULL) {
            ogs_error("ogs_sbi_change_item_convertToJSON() failed [orig_value]");
            goto end;
        }
    }

    if (change_item->new_value) {
        if (cJSON_AddStringToObject(item, "newValue", change_item->new_value) == NULL) {
            ogs_error("ogs_sbi_change_item_convertToJSON() failed [new_value]");
            goto end;
        }
    }

end:
    return item;
}

ogs_sbi_change_item_t *ogs_sbi_change_item_parseFromJSON(cJSON *change_itemJSON)
{
    ogs_sbi_change_item_t *change_item_local_var = NULL;
    cJSON *op = cJSON_GetObjectItemCaseSensitive(change_itemJSON, "op");
    if (!op) {
        ogs_error("ogs_sbi_change_item_parseFromJSON() failed [op]");
        goto end;
    }

    ogs_sbi_change_type_e opVariable;

    if (!cJSON_IsString(op)) {
        ogs_error("ogs_sbi_change_item_parseFromJSON() failed [op]");
        goto end;
    }
    opVariable = ogs_sbi_change_type_FromString(op->valuestring);

    cJSON *path = cJSON_GetObjectItemCaseSensitive(change_itemJSON, "path");
    if (!path) {
        ogs_error("ogs_sbi_change_item_parseFromJSON() failed [path]");
        goto end;
    }


    if (!cJSON_IsString(path)) {
        ogs_error("ogs_sbi_change_item_parseFromJSON() failed [path]");
        goto end;
    }

    cJSON *from = cJSON_GetObjectItemCaseSensitive(change_itemJSON, "from");

    if (from) {
        if (!cJSON_IsString(from)) {
            ogs_error("ogs_sbi_change_item_parseFromJSON() failed [from]");
            goto end;
        }
    }

    cJSON *orig_value = cJSON_GetObjectItemCaseSensitive(change_itemJSON, "origValue");

    if (orig_value) {
        if (!cJSON_IsString(orig_value)) {
            ogs_error("ogs_sbi_change_item_parseFromJSON() failed [orig_value]");
            goto end;
        }
    }

    cJSON *new_value = cJSON_GetObjectItemCaseSensitive(change_itemJSON, "newValue");

    if (new_value) {
        if (!cJSON_IsString(new_value)) {
            ogs_error("ogs_sbi_change_item_parseFromJSON() failed [new_value]");
            goto end;
        }
    }

    change_item_local_var = ogs_sbi_change_item_create (
        opVariable,
        ogs_strdup(path->valuestring),
        from ? ogs_strdup(from->valuestring) : NULL,
        orig_value ? ogs_strdup(orig_value->valuestring) : NULL,
        new_value ? ogs_strdup(new_value->valuestring) : NULL
        );

    return change_item_local_var;
end:
    return NULL;
}

