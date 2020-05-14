
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "service_name_cond.h"

ogs_sbi_service_name_cond_t *ogs_sbi_service_name_cond_create(
    char *service_name
    )
{
    ogs_sbi_service_name_cond_t *service_name_cond_local_var = ogs_sbi_malloc(sizeof(ogs_sbi_service_name_cond_t));
    if (!service_name_cond_local_var) {
        return NULL;
    }
    service_name_cond_local_var->service_name = service_name;

    return service_name_cond_local_var;
}

void ogs_sbi_service_name_cond_free(ogs_sbi_service_name_cond_t *service_name_cond)
{
    if (NULL == service_name_cond) {
        return;
    }
    ogs_sbi_lnode_t *node;
    ogs_free(service_name_cond->service_name);
    ogs_free(service_name_cond);
}

cJSON *ogs_sbi_service_name_cond_convertToJSON(ogs_sbi_service_name_cond_t *service_name_cond)
{
    cJSON *item = cJSON_CreateObject();
    if (!service_name_cond->service_name) {
        ogs_error("ogs_sbi_service_name_cond_convertToJSON() failed [service_name]");
        goto end;
    }
    if (cJSON_AddStringToObject(item, "serviceName", service_name_cond->service_name) == NULL) {
        ogs_error("ogs_sbi_service_name_cond_convertToJSON() failed [service_name]");
        goto end;
    }

end:
    return item;
}

ogs_sbi_service_name_cond_t *ogs_sbi_service_name_cond_parseFromJSON(cJSON *service_name_condJSON)
{
    ogs_sbi_service_name_cond_t *service_name_cond_local_var = NULL;
    cJSON *service_name = cJSON_GetObjectItemCaseSensitive(service_name_condJSON, "serviceName");
    if (!service_name) {
        ogs_error("ogs_sbi_service_name_cond_parseFromJSON() failed [service_name]");
        goto end;
    }


    if (!cJSON_IsString(service_name)) {
        ogs_error("ogs_sbi_service_name_cond_parseFromJSON() failed [service_name]");
        goto end;
    }

    service_name_cond_local_var = ogs_sbi_service_name_cond_create (
        ogs_strdup(service_name->valuestring)
        );

    return service_name_cond_local_var;
end:
    return NULL;
}

