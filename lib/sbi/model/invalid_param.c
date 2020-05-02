
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invalid_param.h"

invalid_param_t *invalid_param_create(
    char *param,
    char *reason
    )
{
    invalid_param_t *invalid_param_local_var = ogs_malloc(sizeof(invalid_param_t));
    if (!invalid_param_local_var) {
        return NULL;
    }
    invalid_param_local_var->param = param;
    invalid_param_local_var->reason = reason;

    return invalid_param_local_var;
}

void invalid_param_free(invalid_param_t *invalid_param)
{
    if(NULL == invalid_param) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(invalid_param->param);
    ogs_free(invalid_param->reason);
    ogs_free(invalid_param);
}

cJSON *invalid_param_convertToJSON(invalid_param_t *invalid_param)
{
    cJSON *item = cJSON_CreateObject();
    if (!invalid_param->param) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "param", invalid_param->param) == NULL) {
        goto fail;
    }

    if (invalid_param->reason) {
        if(cJSON_AddStringToObject(item, "reason", invalid_param->reason) == NULL) {
            goto fail;
        }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

invalid_param_t *invalid_param_parseFromJSON(cJSON *invalid_paramJSON)
{
    invalid_param_t *invalid_param_local_var = NULL;
    cJSON *param = cJSON_GetObjectItemCaseSensitive(invalid_paramJSON, "param");
    if (!param) {
        goto end;
    }


    if(!cJSON_IsString(param))
    {
        goto end;
    }

    cJSON *reason = cJSON_GetObjectItemCaseSensitive(invalid_paramJSON, "reason");

    if (reason) {
        if(!cJSON_IsString(reason))
        {
            goto end;
        }
    }

    invalid_param_local_var = invalid_param_create (
        ogs_strdup(param->valuestring),
        reason ? ogs_strdup(reason->valuestring) : NULL
        );

    return invalid_param_local_var;
end:
    return NULL;
}

