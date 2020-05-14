
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nf_type_cond.h"

ogs_sbi_nf_type_cond_t *ogs_sbi_nf_type_cond_create(
    ogs_sbi_nf_type_e nf_type
    )
{
    ogs_sbi_nf_type_cond_t *nf_type_cond_local_var = ogs_sbi_malloc(sizeof(ogs_sbi_nf_type_cond_t));
    if (!nf_type_cond_local_var) {
        return NULL;
    }
    nf_type_cond_local_var->nf_type = nf_type;

    return nf_type_cond_local_var;
}

void ogs_sbi_nf_type_cond_free(ogs_sbi_nf_type_cond_t *nf_type_cond)
{
    if (NULL == nf_type_cond) {
        return;
    }
    ogs_sbi_lnode_t *node;
    ogs_free(nf_type_cond);
}

cJSON *ogs_sbi_nf_type_cond_convertToJSON(ogs_sbi_nf_type_cond_t *nf_type_cond)
{
    cJSON *item = cJSON_CreateObject();
    if (!nf_type_cond->nf_type) {
        ogs_error("ogs_sbi_nf_type_cond_convertToJSON() failed [nf_type]");
        goto end;
    }
    if (cJSON_AddStringToObject(item, "nfType", ogs_sbi_nf_type_ToString(nf_type_cond->nf_type)) == NULL) {
        ogs_error("ogs_sbi_nf_type_cond_convertToJSON() failed [nf_type]");
        goto end;
    }

end:
    return item;
}

ogs_sbi_nf_type_cond_t *ogs_sbi_nf_type_cond_parseFromJSON(cJSON *nf_type_condJSON)
{
    ogs_sbi_nf_type_cond_t *nf_type_cond_local_var = NULL;
    cJSON *nf_type = cJSON_GetObjectItemCaseSensitive(nf_type_condJSON, "nfType");
    if (!nf_type) {
        ogs_error("ogs_sbi_nf_type_cond_parseFromJSON() failed [nf_type]");
        goto end;
    }

    ogs_sbi_nf_type_e nf_typeVariable;

    if (!cJSON_IsString(nf_type)) {
        ogs_error("ogs_sbi_nf_type_cond_parseFromJSON() failed [nf_type]");
        goto end;
    }
    nf_typeVariable = ogs_sbi_nf_type_FromString(nf_type->valuestring);

    nf_type_cond_local_var = ogs_sbi_nf_type_cond_create (
        nf_typeVariable
        );

    return nf_type_cond_local_var;
end:
    return NULL;
}

