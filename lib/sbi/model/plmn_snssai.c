#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plmn_snssai.h"



plmn_snssai_t *plmn_snssai_create(
    plmn_id_t *plmn_id,
    list_t *s_nssai_list
    ) {
    plmn_snssai_t *plmn_snssai_local_var = malloc(sizeof(plmn_snssai_t));
    if (!plmn_snssai_local_var) {
        return NULL;
    }
    plmn_snssai_local_var->plmn_id = plmn_id;
    plmn_snssai_local_var->s_nssai_list = s_nssai_list;

    return plmn_snssai_local_var;
}


void plmn_snssai_free(plmn_snssai_t *plmn_snssai) {
    if(NULL == plmn_snssai){
        return ;
    }
    listEntry_t *listEntry;
    plmn_id_free(plmn_snssai->plmn_id);
    list_ForEach(listEntry, plmn_snssai->s_nssai_list) {
        snssai_free(listEntry->data);
    }
    list_free(plmn_snssai->s_nssai_list);
    free(plmn_snssai);
}

cJSON *plmn_snssai_convertToJSON(plmn_snssai_t *plmn_snssai) {
    cJSON *item = cJSON_CreateObject();

    // plmn_snssai->plmn_id
    if (!plmn_snssai->plmn_id) {
        goto fail;
    }
    
    cJSON *plmn_id_local_JSON = plmn_id_convertToJSON(plmn_snssai->plmn_id);
    if(plmn_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // plmn_snssai->s_nssai_list
    if (!plmn_snssai->s_nssai_list) {
        goto fail;
    }
    
    cJSON *s_nssai_list = cJSON_AddArrayToObject(item, "sNssaiList");
    if(s_nssai_list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *s_nssai_listListEntry;
    if (plmn_snssai->s_nssai_list) {
    list_ForEach(s_nssai_listListEntry, plmn_snssai->s_nssai_list) {
    cJSON *itemLocal = snssai_convertToJSON(s_nssai_listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(s_nssai_list, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

plmn_snssai_t *plmn_snssai_parseFromJSON(cJSON *plmn_snssaiJSON){

    plmn_snssai_t *plmn_snssai_local_var = NULL;

    // plmn_snssai->plmn_id
    cJSON *plmn_id = cJSON_GetObjectItemCaseSensitive(plmn_snssaiJSON, "plmnId");
    if (!plmn_id) {
        goto end;
    }

    plmn_id_t *plmn_id_local_nonprim = NULL;
    
    plmn_id_local_nonprim = plmn_id_parseFromJSON(plmn_id); //nonprimitive

    // plmn_snssai->s_nssai_list
    cJSON *s_nssai_list = cJSON_GetObjectItemCaseSensitive(plmn_snssaiJSON, "sNssaiList");
    if (!s_nssai_list) {
        goto end;
    }

    list_t *s_nssai_listList;
    
    cJSON *s_nssai_list_local_nonprimitive;
    if(!cJSON_IsArray(s_nssai_list)){
        goto end; //nonprimitive container
    }

    s_nssai_listList = list_create();

    cJSON_ArrayForEach(s_nssai_list_local_nonprimitive,s_nssai_list )
    {
        if(!cJSON_IsObject(s_nssai_list_local_nonprimitive)){
            goto end;
        }
        snssai_t *s_nssai_listItem = snssai_parseFromJSON(s_nssai_list_local_nonprimitive);

        list_addElement(s_nssai_listList, s_nssai_listItem);
    }


    plmn_snssai_local_var = plmn_snssai_create (
        plmn_id_local_nonprim,
        s_nssai_listList
        );

    return plmn_snssai_local_var;
end:
    return NULL;

}
