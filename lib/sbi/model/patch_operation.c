
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_operation.h"

patch_operation_t *patch_operation_create(
    )
{
    patch_operation_t *patch_operation_local_var = ogs_malloc(sizeof(patch_operation_t));
    if (!patch_operation_local_var) {
        return NULL;
    }

    return patch_operation_local_var;
}

void patch_operation_free(patch_operation_t *patch_operation)
{
    if(NULL == patch_operation) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(patch_operation);
}

cJSON *patch_operation_convertToJSON(patch_operation_t *patch_operation)
{
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

patch_operation_t *patch_operation_parseFromJSON(cJSON *patch_operationJSON)
{
    patch_operation_t *patch_operation_local_var = NULL;
    patch_operation_local_var = patch_operation_create (
        );

    return patch_operation_local_var;
end:
    return NULL;
}

