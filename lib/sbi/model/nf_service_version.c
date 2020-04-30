#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nf_service_version.h"



nf_service_version_t *nf_service_version_create(
    char *api_version_in_uri,
    char *api_full_version,
    char *expiry
    ) {
    nf_service_version_t *nf_service_version_local_var = malloc(sizeof(nf_service_version_t));
    if (!nf_service_version_local_var) {
        return NULL;
    }
    nf_service_version_local_var->api_version_in_uri = api_version_in_uri;
    nf_service_version_local_var->api_full_version = api_full_version;
    nf_service_version_local_var->expiry = expiry;

    return nf_service_version_local_var;
}


void nf_service_version_free(nf_service_version_t *nf_service_version) {
    if(NULL == nf_service_version){
        return ;
    }
    listEntry_t *listEntry;
    free(nf_service_version->api_version_in_uri);
    free(nf_service_version->api_full_version);
    free(nf_service_version->expiry);
    free(nf_service_version);
}

cJSON *nf_service_version_convertToJSON(nf_service_version_t *nf_service_version) {
    cJSON *item = cJSON_CreateObject();

    // nf_service_version->api_version_in_uri
    if (!nf_service_version->api_version_in_uri) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "apiVersionInUri", nf_service_version->api_version_in_uri) == NULL) {
    goto fail; //String
    }


    // nf_service_version->api_full_version
    if (!nf_service_version->api_full_version) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "apiFullVersion", nf_service_version->api_full_version) == NULL) {
    goto fail; //String
    }


    // nf_service_version->expiry
    if(nf_service_version->expiry) { 
    if(cJSON_AddStringToObject(item, "expiry", nf_service_version->expiry) == NULL) {
    goto fail; //Date-Time
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

nf_service_version_t *nf_service_version_parseFromJSON(cJSON *nf_service_versionJSON){

    nf_service_version_t *nf_service_version_local_var = NULL;

    // nf_service_version->api_version_in_uri
    cJSON *api_version_in_uri = cJSON_GetObjectItemCaseSensitive(nf_service_versionJSON, "apiVersionInUri");
    if (!api_version_in_uri) {
        goto end;
    }

    
    if(!cJSON_IsString(api_version_in_uri))
    {
    goto end; //String
    }

    // nf_service_version->api_full_version
    cJSON *api_full_version = cJSON_GetObjectItemCaseSensitive(nf_service_versionJSON, "apiFullVersion");
    if (!api_full_version) {
        goto end;
    }

    
    if(!cJSON_IsString(api_full_version))
    {
    goto end; //String
    }

    // nf_service_version->expiry
    cJSON *expiry = cJSON_GetObjectItemCaseSensitive(nf_service_versionJSON, "expiry");
    if (expiry) { 
    if(!cJSON_IsString(expiry))
    {
    goto end; //DateTime
    }
    }


    nf_service_version_local_var = nf_service_version_create (
        strdup(api_version_in_uri->valuestring),
        strdup(api_full_version->valuestring),
        expiry ? strdup(expiry->valuestring) : NULL
        );

    return nf_service_version_local_var;
end:
    return NULL;

}
