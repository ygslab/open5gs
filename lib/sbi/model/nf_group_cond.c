
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nf_group_cond.h"

char* nf_typenf_group_cond_ToString(nf_group_cond_nf_type_e nf_type) {
    char* nf_typeArray[] =  { "NULL", "UDM", "AUSF", "UDR", "PCF" };
    return nf_typeArray[nf_type];
}

nf_group_cond_nf_type_e nf_typenf_group_cond_FromString(char* nf_type){
    int stringToReturn = 0;
    char *nf_typeArray[] =  { "NULL", "UDM", "AUSF", "UDR", "PCF" };
    size_t sizeofArray = sizeof(nf_typeArray) / sizeof(nf_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(nf_type, nf_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
nf_group_cond_t *nf_group_cond_create(
    nf_group_cond_nf_type_e nf_type,
    char *nf_group_id
    )
{
    nf_group_cond_t *nf_group_cond_local_var = ogs_malloc(sizeof(nf_group_cond_t));
    if (!nf_group_cond_local_var) {
        return NULL;
    }
    nf_group_cond_local_var->nf_type = nf_type;
    nf_group_cond_local_var->nf_group_id = nf_group_id;

    return nf_group_cond_local_var;
}

void nf_group_cond_free(nf_group_cond_t *nf_group_cond)
{
    if(NULL == nf_group_cond) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(nf_group_cond->nf_group_id);
    ogs_free(nf_group_cond);
}

cJSON *nf_group_cond_convertToJSON(nf_group_cond_t *nf_group_cond)
{
    cJSON *item = cJSON_CreateObject();
    if (!nf_group_cond->nf_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "nfType", nf_typenf_group_cond_ToString(nf_group_cond->nf_type)) == NULL) {
        goto fail;
    }

    if (!nf_group_cond->nf_group_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "nfGroupId", nf_group_cond->nf_group_id) == NULL) {
        goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

nf_group_cond_t *nf_group_cond_parseFromJSON(cJSON *nf_group_condJSON)
{
    nf_group_cond_t *nf_group_cond_local_var = NULL;
    cJSON *nf_type = cJSON_GetObjectItemCaseSensitive(nf_group_condJSON, "nfType");
    if (!nf_type) {
        goto end;
    }

    nf_group_cond_nf_type_e nf_typeVariable;

    if(!cJSON_IsString(nf_type)) {
        goto end;
    }
    nf_typeVariable = nf_typenf_group_cond_FromString(nf_type->valuestring);

    cJSON *nf_group_id = cJSON_GetObjectItemCaseSensitive(nf_group_condJSON, "nfGroupId");
    if (!nf_group_id) {
        goto end;
    }


    if(!cJSON_IsString(nf_group_id))
    {
        goto end;
    }

    nf_group_cond_local_var = nf_group_cond_create (
        nf_typeVariable,
        ogs_strdup(nf_group_id->valuestring)
        );

    return nf_group_cond_local_var;
end:
    return NULL;
}

