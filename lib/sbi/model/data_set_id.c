
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "data_set_id.h"

data_set_id_t *data_set_id_create(
    )
{
    data_set_id_t *data_set_id_local_var = ogs_malloc(sizeof(data_set_id_t));
    if (!data_set_id_local_var) {
        return NULL;
    }

    return data_set_id_local_var;
}

void data_set_id_free(data_set_id_t *data_set_id)
{
    if(NULL == data_set_id) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(data_set_id);
}

cJSON *data_set_id_convertToJSON(data_set_id_t *data_set_id)
{
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

data_set_id_t *data_set_id_parseFromJSON(cJSON *data_set_idJSON)
{
    data_set_id_t *data_set_id_local_var = NULL;
    data_set_id_local_var = data_set_id_create (
        );

    return data_set_id_local_var;
end:
    return NULL;
}

