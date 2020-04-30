#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_slice_cond.h"



network_slice_cond_t *network_slice_cond_create(
    list_t *snssai_list,
    list_t *nsi_list
    ) {
    network_slice_cond_t *network_slice_cond_local_var = malloc(sizeof(network_slice_cond_t));
    if (!network_slice_cond_local_var) {
        return NULL;
    }
    network_slice_cond_local_var->snssai_list = snssai_list;
    network_slice_cond_local_var->nsi_list = nsi_list;

    return network_slice_cond_local_var;
}


void network_slice_cond_free(network_slice_cond_t *network_slice_cond) {
    if(NULL == network_slice_cond){
        return ;
    }
    listEntry_t *listEntry;
    list_ForEach(listEntry, network_slice_cond->snssai_list) {
        snssai_free(listEntry->data);
    }
    list_free(network_slice_cond->snssai_list);
    list_ForEach(listEntry, network_slice_cond->nsi_list) {
        free(listEntry->data);
    }
    list_free(network_slice_cond->nsi_list);
    free(network_slice_cond);
}

cJSON *network_slice_cond_convertToJSON(network_slice_cond_t *network_slice_cond) {
    cJSON *item = cJSON_CreateObject();

    // network_slice_cond->snssai_list
    if (!network_slice_cond->snssai_list) {
        goto fail;
    }
    
    cJSON *snssai_list = cJSON_AddArrayToObject(item, "snssaiList");
    if(snssai_list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *snssai_listListEntry;
    if (network_slice_cond->snssai_list) {
    list_ForEach(snssai_listListEntry, network_slice_cond->snssai_list) {
    cJSON *itemLocal = snssai_convertToJSON(snssai_listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(snssai_list, itemLocal);
    }
    }


    // network_slice_cond->nsi_list
    if(network_slice_cond->nsi_list) { 
    cJSON *nsi_list = cJSON_AddArrayToObject(item, "nsiList");
    if(nsi_list == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *nsi_listListEntry;
    list_ForEach(nsi_listListEntry, network_slice_cond->nsi_list) {
    if(cJSON_AddStringToObject(nsi_list, "", (char*)nsi_listListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

network_slice_cond_t *network_slice_cond_parseFromJSON(cJSON *network_slice_condJSON){

    network_slice_cond_t *network_slice_cond_local_var = NULL;

    // network_slice_cond->snssai_list
    cJSON *snssai_list = cJSON_GetObjectItemCaseSensitive(network_slice_condJSON, "snssaiList");
    if (!snssai_list) {
        goto end;
    }

    list_t *snssai_listList;
    
    cJSON *snssai_list_local_nonprimitive;
    if(!cJSON_IsArray(snssai_list)){
        goto end; //nonprimitive container
    }

    snssai_listList = list_create();

    cJSON_ArrayForEach(snssai_list_local_nonprimitive,snssai_list )
    {
        if(!cJSON_IsObject(snssai_list_local_nonprimitive)){
            goto end;
        }
        snssai_t *snssai_listItem = snssai_parseFromJSON(snssai_list_local_nonprimitive);

        list_addElement(snssai_listList, snssai_listItem);
    }

    // network_slice_cond->nsi_list
    cJSON *nsi_list = cJSON_GetObjectItemCaseSensitive(network_slice_condJSON, "nsiList");
    list_t *nsi_listList;
    if (nsi_list) { 
    cJSON *nsi_list_local;
    if(!cJSON_IsArray(nsi_list)) {
        goto end;//primitive container
    }
    nsi_listList = list_create();

    cJSON_ArrayForEach(nsi_list_local, nsi_list)
    {
        if(!cJSON_IsString(nsi_list_local))
        {
            goto end;
        }
        list_addElement(nsi_listList , strdup(nsi_list_local->valuestring));
    }
    }


    network_slice_cond_local_var = network_slice_cond_create (
        snssai_listList,
        nsi_list ? nsi_listList : NULL
        );

    return network_slice_cond_local_var;
end:
    return NULL;

}
