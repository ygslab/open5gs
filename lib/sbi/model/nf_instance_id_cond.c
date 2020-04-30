#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nf_instance_id_cond.h"



nf_instance_id_cond_t *nf_instance_id_cond_create(
    char *nf_instance_id
    ) {
    nf_instance_id_cond_t *nf_instance_id_cond_local_var = malloc(sizeof(nf_instance_id_cond_t));
    if (!nf_instance_id_cond_local_var) {
        return NULL;
    }
    nf_instance_id_cond_local_var->nf_instance_id = nf_instance_id;

    return nf_instance_id_cond_local_var;
}


void nf_instance_id_cond_free(nf_instance_id_cond_t *nf_instance_id_cond) {
    if(NULL == nf_instance_id_cond){
        return ;
    }
    listEntry_t *listEntry;
    free(nf_instance_id_cond->nf_instance_id);
    free(nf_instance_id_cond);
}

cJSON *nf_instance_id_cond_convertToJSON(nf_instance_id_cond_t *nf_instance_id_cond) {
    cJSON *item = cJSON_CreateObject();

    // nf_instance_id_cond->nf_instance_id
    if (!nf_instance_id_cond->nf_instance_id) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "nfInstanceId", nf_instance_id_cond->nf_instance_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

nf_instance_id_cond_t *nf_instance_id_cond_parseFromJSON(cJSON *nf_instance_id_condJSON){

    nf_instance_id_cond_t *nf_instance_id_cond_local_var = NULL;

    // nf_instance_id_cond->nf_instance_id
    cJSON *nf_instance_id = cJSON_GetObjectItemCaseSensitive(nf_instance_id_condJSON, "nfInstanceId");
    if (!nf_instance_id) {
        goto end;
    }

    
    if(!cJSON_IsString(nf_instance_id))
    {
    goto end; //String
    }


    nf_instance_id_cond_local_var = nf_instance_id_cond_create (
        strdup(nf_instance_id->valuestring)
        );

    return nf_instance_id_cond_local_var;
end:
    return NULL;

}
