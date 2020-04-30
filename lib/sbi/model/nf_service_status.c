#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nf_service_status.h"



nf_service_status_t *nf_service_status_create(
    ) {
    nf_service_status_t *nf_service_status_local_var = malloc(sizeof(nf_service_status_t));
    if (!nf_service_status_local_var) {
        return NULL;
    }

    return nf_service_status_local_var;
}


void nf_service_status_free(nf_service_status_t *nf_service_status) {
    if(NULL == nf_service_status){
        return ;
    }
    listEntry_t *listEntry;
    free(nf_service_status);
}

cJSON *nf_service_status_convertToJSON(nf_service_status_t *nf_service_status) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

nf_service_status_t *nf_service_status_parseFromJSON(cJSON *nf_service_statusJSON){

    nf_service_status_t *nf_service_status_local_var = NULL;


    nf_service_status_local_var = nf_service_status_create (
        );

    return nf_service_status_local_var;
end:
    return NULL;

}
