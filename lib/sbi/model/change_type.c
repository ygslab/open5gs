
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "change_type.h"

change_type_t *change_type_create(
    )
{
    change_type_t *change_type_local_var = ogs_malloc(sizeof(change_type_t));
    if (!change_type_local_var) {
        return NULL;
    }

    return change_type_local_var;
}

void change_type_free(change_type_t *change_type)
{
    if(NULL == change_type) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(change_type);
}

cJSON *change_type_convertToJSON(change_type_t *change_type)
{
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

change_type_t *change_type_parseFromJSON(cJSON *change_typeJSON)
{
    change_type_t *change_type_local_var = NULL;
    change_type_local_var = change_type_create (
        );

    return change_type_local_var;
end:
    return NULL;
}

