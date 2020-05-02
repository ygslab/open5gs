
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "service_name.h"

service_name_t *service_name_create(
    )
{
    service_name_t *service_name_local_var = ogs_malloc(sizeof(service_name_t));
    if (!service_name_local_var) {
        return NULL;
    }

    return service_name_local_var;
}

void service_name_free(service_name_t *service_name)
{
    if(NULL == service_name) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(service_name);
}

cJSON *service_name_convertToJSON(service_name_t *service_name)
{
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

service_name_t *service_name_parseFromJSON(cJSON *service_nameJSON)
{
    service_name_t *service_name_local_var = NULL;
    service_name_local_var = service_name_create (
        );

    return service_name_local_var;
end:
    return NULL;
}

