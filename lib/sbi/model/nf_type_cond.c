#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nf_type_cond.h"



nf_type_cond_t *nf_type_cond_create(
    char *nf_type
    ) {
    nf_type_cond_t *nf_type_cond_local_var = malloc(sizeof(nf_type_cond_t));
    if (!nf_type_cond_local_var) {
        return NULL;
    }
    nf_type_cond_local_var->nf_type = nf_type;

    return nf_type_cond_local_var;
}


void nf_type_cond_free(nf_type_cond_t *nf_type_cond) {
    if(NULL == nf_type_cond){
        return ;
    }
    listEntry_t *listEntry;
    free(nf_type_cond->nf_type);
    free(nf_type_cond);
}

cJSON *nf_type_cond_convertToJSON(nf_type_cond_t *nf_type_cond) {
    cJSON *item = cJSON_CreateObject();

    // nf_type_cond->nf_type
    if (!nf_type_cond->nf_type) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "nfType", nf_type_cond->nf_type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

nf_type_cond_t *nf_type_cond_parseFromJSON(cJSON *nf_type_condJSON){

    nf_type_cond_t *nf_type_cond_local_var = NULL;

    // nf_type_cond->nf_type
    cJSON *nf_type = cJSON_GetObjectItemCaseSensitive(nf_type_condJSON, "nfType");
    if (!nf_type) {
        goto end;
    }

    
    if(!cJSON_IsString(nf_type))
    {
    goto end; //String
    }


    nf_type_cond_local_var = nf_type_cond_create (
        strdup(nf_type->valuestring)
        );

    return nf_type_cond_local_var;
end:
    return NULL;

}
