#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tai.h"



tai_t *tai_create(
    plmn_id_t *plmn_id,
    char *tac
    ) {
    tai_t *tai_local_var = malloc(sizeof(tai_t));
    if (!tai_local_var) {
        return NULL;
    }
    tai_local_var->plmn_id = plmn_id;
    tai_local_var->tac = tac;

    return tai_local_var;
}


void tai_free(tai_t *tai) {
    if(NULL == tai){
        return ;
    }
    listEntry_t *listEntry;
    plmn_id_free(tai->plmn_id);
    free(tai->tac);
    free(tai);
}

cJSON *tai_convertToJSON(tai_t *tai) {
    cJSON *item = cJSON_CreateObject();

    // tai->plmn_id
    if (!tai->plmn_id) {
        goto fail;
    }
    
    cJSON *plmn_id_local_JSON = plmn_id_convertToJSON(tai->plmn_id);
    if(plmn_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // tai->tac
    if (!tai->tac) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "tac", tai->tac) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

tai_t *tai_parseFromJSON(cJSON *taiJSON){

    tai_t *tai_local_var = NULL;

    // tai->plmn_id
    cJSON *plmn_id = cJSON_GetObjectItemCaseSensitive(taiJSON, "plmnId");
    if (!plmn_id) {
        goto end;
    }

    plmn_id_t *plmn_id_local_nonprim = NULL;
    
    plmn_id_local_nonprim = plmn_id_parseFromJSON(plmn_id); //nonprimitive

    // tai->tac
    cJSON *tac = cJSON_GetObjectItemCaseSensitive(taiJSON, "tac");
    if (!tac) {
        goto end;
    }

    
    if(!cJSON_IsString(tac))
    {
    goto end; //String
    }


    tai_local_var = tai_create (
        plmn_id_local_nonprim,
        strdup(tac->valuestring)
        );

    return tai_local_var;
end:
    return NULL;

}
