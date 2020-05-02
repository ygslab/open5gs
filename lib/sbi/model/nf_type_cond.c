
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nf_type_cond.h"

nf_type_cond_t *nf_type_cond_create(
    nf_type_e nf_type
    )
{
    nf_type_cond_t *nf_type_cond_local_var = ogs_malloc(sizeof(nf_type_cond_t));
    if (!nf_type_cond_local_var) {
        return NULL;
    }
    nf_type_cond_local_var->nf_type = nf_type;

    return nf_type_cond_local_var;
}

void nf_type_cond_free(nf_type_cond_t *nf_type_cond)
{
    if(NULL == nf_type_cond) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(nf_type_cond);
}

cJSON *nf_type_cond_convertToJSON(nf_type_cond_t *nf_type_cond)
{
    cJSON *item = cJSON_CreateObject();
    if (!nf_type_cond->nf_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "nfType", nf_type_ToString(nf_type_cond->nf_type)) == NULL) {
        goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

nf_type_cond_t *nf_type_cond_parseFromJSON(cJSON *nf_type_condJSON)
{
    nf_type_cond_t *nf_type_cond_local_var = NULL;
    cJSON *nf_type = cJSON_GetObjectItemCaseSensitive(nf_type_condJSON, "nfType");
    if (!nf_type) {
        goto end;
    }

    nf_type_e nf_typeVariable;

    if(!cJSON_IsString(nf_type)) {
        goto end;
    }
    nf_typeVariable = nf_type_FromString(nf_type->valuestring);

    nf_type_cond_local_var = nf_type_cond_create (
        nf_typeVariable
        );

    return nf_type_cond_local_var;
end:
    return NULL;
}

