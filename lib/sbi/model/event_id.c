
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "event_id.h"

event_id_t *event_id_create(
    )
{
    event_id_t *event_id_local_var = ogs_malloc(sizeof(event_id_t));
    if (!event_id_local_var) {
        return NULL;
    }

    return event_id_local_var;
}

void event_id_free(event_id_t *event_id)
{
    if(NULL == event_id) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(event_id);
}

cJSON *event_id_convertToJSON(event_id_t *event_id)
{
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

event_id_t *event_id_parseFromJSON(cJSON *event_idJSON)
{
    event_id_t *event_id_local_var = NULL;
    event_id_local_var = event_id_create (
        );

    return event_id_local_var;
end:
    return NULL;
}

