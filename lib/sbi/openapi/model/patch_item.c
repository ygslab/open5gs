
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_item.h"

ogs_sbi_patch_item_t *ogs_sbi_patch_item_create(
    ogs_sbi_patch_operation_e op,
    char *path,
    char *from,
    char *value
    )
{
    ogs_sbi_patch_item_t *patch_item_local_var = ogs_sbi_malloc(sizeof(ogs_sbi_patch_item_t));
    if (!patch_item_local_var) {
        return NULL;
    }
    patch_item_local_var->op = op;
    patch_item_local_var->path = path;
    patch_item_local_var->from = from;
    patch_item_local_var->value = value;

    return patch_item_local_var;
}

void ogs_sbi_patch_item_free(ogs_sbi_patch_item_t *patch_item)
{
    if (NULL == patch_item) {
        return;
    }
    ogs_sbi_lnode_t *node;
    ogs_free(patch_item->path);
    ogs_free(patch_item->from);
    ogs_free(patch_item->value);
    ogs_free(patch_item);
}

cJSON *ogs_sbi_patch_item_convertToJSON(ogs_sbi_patch_item_t *patch_item)
{
    cJSON *item = cJSON_CreateObject();
    if (!patch_item->op) {
        ogs_error("ogs_sbi_patch_item_convertToJSON() failed [op]");
        goto end;
    }
    if (cJSON_AddStringToObject(item, "op", ogs_sbi_patch_operation_ToString(patch_item->op)) == NULL) {
        ogs_error("ogs_sbi_patch_item_convertToJSON() failed [op]");
        goto end;
    }

    if (!patch_item->path) {
        ogs_error("ogs_sbi_patch_item_convertToJSON() failed [path]");
        goto end;
    }
    if (cJSON_AddStringToObject(item, "path", patch_item->path) == NULL) {
        ogs_error("ogs_sbi_patch_item_convertToJSON() failed [path]");
        goto end;
    }

    if (patch_item->from) {
        if (cJSON_AddStringToObject(item, "from", patch_item->from) == NULL) {
            ogs_error("ogs_sbi_patch_item_convertToJSON() failed [from]");
            goto end;
        }
    }

    if (patch_item->value) {
        if (cJSON_AddStringToObject(item, "value", patch_item->value) == NULL) {
            ogs_error("ogs_sbi_patch_item_convertToJSON() failed [value]");
            goto end;
        }
    }

end:
    return item;
}

ogs_sbi_patch_item_t *ogs_sbi_patch_item_parseFromJSON(cJSON *patch_itemJSON)
{
    ogs_sbi_patch_item_t *patch_item_local_var = NULL;
    cJSON *op = cJSON_GetObjectItemCaseSensitive(patch_itemJSON, "op");
    if (!op) {
        ogs_error("ogs_sbi_patch_item_parseFromJSON() failed [op]");
        goto end;
    }

    ogs_sbi_patch_operation_e opVariable;

    if (!cJSON_IsString(op)) {
        ogs_error("ogs_sbi_patch_item_parseFromJSON() failed [op]");
        goto end;
    }
    opVariable = ogs_sbi_patch_operation_FromString(op->valuestring);

    cJSON *path = cJSON_GetObjectItemCaseSensitive(patch_itemJSON, "path");
    if (!path) {
        ogs_error("ogs_sbi_patch_item_parseFromJSON() failed [path]");
        goto end;
    }


    if (!cJSON_IsString(path)) {
        ogs_error("ogs_sbi_patch_item_parseFromJSON() failed [path]");
        goto end;
    }

    cJSON *from = cJSON_GetObjectItemCaseSensitive(patch_itemJSON, "from");

    if (from) {
        if (!cJSON_IsString(from)) {
            ogs_error("ogs_sbi_patch_item_parseFromJSON() failed [from]");
            goto end;
        }
    }

    cJSON *value = cJSON_GetObjectItemCaseSensitive(patch_itemJSON, "value");

    if (value) {
        if (!cJSON_IsString(value)) {
            ogs_error("ogs_sbi_patch_item_parseFromJSON() failed [value]");
            goto end;
        }
    }

    patch_item_local_var = ogs_sbi_patch_item_create (
        opVariable,
        ogs_strdup(path->valuestring),
        from ? ogs_strdup(from->valuestring) : NULL,
        value ? ogs_strdup(value->valuestring) : NULL
        );

    return patch_item_local_var;
end:
    return NULL;
}

