#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chf_service_info.h"



chf_service_info_t *chf_service_info_create(
    char *primary_chf_service_instance,
    char *secondary_chf_service_instance
    ) {
    chf_service_info_t *chf_service_info_local_var = malloc(sizeof(chf_service_info_t));
    if (!chf_service_info_local_var) {
        return NULL;
    }
    chf_service_info_local_var->primary_chf_service_instance = primary_chf_service_instance;
    chf_service_info_local_var->secondary_chf_service_instance = secondary_chf_service_instance;

    return chf_service_info_local_var;
}


void chf_service_info_free(chf_service_info_t *chf_service_info) {
    if(NULL == chf_service_info){
        return ;
    }
    listEntry_t *listEntry;
    free(chf_service_info->primary_chf_service_instance);
    free(chf_service_info->secondary_chf_service_instance);
    free(chf_service_info);
}

cJSON *chf_service_info_convertToJSON(chf_service_info_t *chf_service_info) {
    cJSON *item = cJSON_CreateObject();

    // chf_service_info->primary_chf_service_instance
    if(chf_service_info->primary_chf_service_instance) { 
    if(cJSON_AddStringToObject(item, "primaryChfServiceInstance", chf_service_info->primary_chf_service_instance) == NULL) {
    goto fail; //String
    }
     } 


    // chf_service_info->secondary_chf_service_instance
    if(chf_service_info->secondary_chf_service_instance) { 
    if(cJSON_AddStringToObject(item, "secondaryChfServiceInstance", chf_service_info->secondary_chf_service_instance) == NULL) {
    goto fail; //String
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

chf_service_info_t *chf_service_info_parseFromJSON(cJSON *chf_service_infoJSON){

    chf_service_info_t *chf_service_info_local_var = NULL;

    // chf_service_info->primary_chf_service_instance
    cJSON *primary_chf_service_instance = cJSON_GetObjectItemCaseSensitive(chf_service_infoJSON, "primaryChfServiceInstance");
    if (primary_chf_service_instance) { 
    if(!cJSON_IsString(primary_chf_service_instance))
    {
    goto end; //String
    }
    }

    // chf_service_info->secondary_chf_service_instance
    cJSON *secondary_chf_service_instance = cJSON_GetObjectItemCaseSensitive(chf_service_infoJSON, "secondaryChfServiceInstance");
    if (secondary_chf_service_instance) { 
    if(!cJSON_IsString(secondary_chf_service_instance))
    {
    goto end; //String
    }
    }


    chf_service_info_local_var = chf_service_info_create (
        primary_chf_service_instance ? strdup(primary_chf_service_instance->valuestring) : NULL,
        secondary_chf_service_instance ? strdup(secondary_chf_service_instance->valuestring) : NULL
        );

    return chf_service_info_local_var;
end:
    return NULL;

}
