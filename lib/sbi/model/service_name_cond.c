
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "service_name_cond.h"

service_name_cond_t *service_name_cond_create(
    service_name_t *service_name
    )
{
    service_name_cond_t *service_name_cond_local_var = ogs_malloc(sizeof(service_name_cond_t));
    if (!service_name_cond_local_var) {
        return NULL;
    }
    service_name_cond_local_var->service_name = service_name;

    return service_name_cond_local_var;
}

void service_name_cond_free(service_name_cond_t *service_name_cond)
{
    if(NULL == service_name_cond) {
        return;
    }
    listEntry_t *listEntry;
    service_name_free(service_name_cond->service_name);
    ogs_free(service_name_cond);
}

cJSON *service_name_cond_convertToJSON(service_name_cond_t *service_name_cond)
{
    cJSON *item = cJSON_CreateObject();
    if (!service_name_cond->service_name) {
        goto fail;
    }
    cJSON *service_name_local_JSON = service_name_convertToJSON(service_name_cond->service_name);
    if(service_name_local_JSON == NULL) {
        goto fail;
    }
    cJSON_AddItemToObject(item, "serviceName", service_name_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

service_name_cond_t *service_name_cond_parseFromJSON(cJSON *service_name_condJSON)
{
    service_name_cond_t *service_name_cond_local_var = NULL;
    cJSON *service_name = cJSON_GetObjectItemCaseSensitive(service_name_condJSON, "serviceName");
    if (!service_name) {
        goto end;
    }

    service_name_t *service_name_local_nonprim = NULL;

    service_name_local_nonprim = service_name_parseFromJSON(service_name);

    service_name_cond_local_var = service_name_cond_create (
        service_name_local_nonprim
        );

    return service_name_cond_local_var;
end:
    return NULL;
}

