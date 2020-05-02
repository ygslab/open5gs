
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nwdaf_event.h"

nwdaf_event_t *nwdaf_event_create(
    )
{
    nwdaf_event_t *nwdaf_event_local_var = ogs_malloc(sizeof(nwdaf_event_t));
    if (!nwdaf_event_local_var) {
        return NULL;
    }

    return nwdaf_event_local_var;
}

void nwdaf_event_free(nwdaf_event_t *nwdaf_event)
{
    if(NULL == nwdaf_event) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(nwdaf_event);
}

cJSON *nwdaf_event_convertToJSON(nwdaf_event_t *nwdaf_event)
{
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

nwdaf_event_t *nwdaf_event_parseFromJSON(cJSON *nwdaf_eventJSON)
{
    nwdaf_event_t *nwdaf_event_local_var = NULL;
    nwdaf_event_local_var = nwdaf_event_create (
        );

    return nwdaf_event_local_var;
end:
    return NULL;
}

