#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snssai_smf_info_item.h"



snssai_smf_info_item_t *snssai_smf_info_item_create(
    snssai_t *s_nssai,
    list_t *dnn_smf_info_list
    ) {
    snssai_smf_info_item_t *snssai_smf_info_item_local_var = malloc(sizeof(snssai_smf_info_item_t));
    if (!snssai_smf_info_item_local_var) {
        return NULL;
    }
    snssai_smf_info_item_local_var->s_nssai = s_nssai;
    snssai_smf_info_item_local_var->dnn_smf_info_list = dnn_smf_info_list;

    return snssai_smf_info_item_local_var;
}


void snssai_smf_info_item_free(snssai_smf_info_item_t *snssai_smf_info_item) {
    if(NULL == snssai_smf_info_item){
        return ;
    }
    listEntry_t *listEntry;
    snssai_free(snssai_smf_info_item->s_nssai);
    list_ForEach(listEntry, snssai_smf_info_item->dnn_smf_info_list) {
        dnn_smf_info_item_free(listEntry->data);
    }
    list_free(snssai_smf_info_item->dnn_smf_info_list);
    free(snssai_smf_info_item);
}

cJSON *snssai_smf_info_item_convertToJSON(snssai_smf_info_item_t *snssai_smf_info_item) {
    cJSON *item = cJSON_CreateObject();

    // snssai_smf_info_item->s_nssai
    if (!snssai_smf_info_item->s_nssai) {
        goto fail;
    }
    
    cJSON *s_nssai_local_JSON = snssai_convertToJSON(snssai_smf_info_item->s_nssai);
    if(s_nssai_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sNssai", s_nssai_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // snssai_smf_info_item->dnn_smf_info_list
    if (!snssai_smf_info_item->dnn_smf_info_list) {
        goto fail;
    }
    
    cJSON *dnn_smf_info_list = cJSON_AddArrayToObject(item, "dnnSmfInfoList");
    if(dnn_smf_info_list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *dnn_smf_info_listListEntry;
    if (snssai_smf_info_item->dnn_smf_info_list) {
    list_ForEach(dnn_smf_info_listListEntry, snssai_smf_info_item->dnn_smf_info_list) {
    cJSON *itemLocal = dnn_smf_info_item_convertToJSON(dnn_smf_info_listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(dnn_smf_info_list, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

snssai_smf_info_item_t *snssai_smf_info_item_parseFromJSON(cJSON *snssai_smf_info_itemJSON){

    snssai_smf_info_item_t *snssai_smf_info_item_local_var = NULL;

    // snssai_smf_info_item->s_nssai
    cJSON *s_nssai = cJSON_GetObjectItemCaseSensitive(snssai_smf_info_itemJSON, "sNssai");
    if (!s_nssai) {
        goto end;
    }

    snssai_t *s_nssai_local_nonprim = NULL;
    
    s_nssai_local_nonprim = snssai_parseFromJSON(s_nssai); //nonprimitive

    // snssai_smf_info_item->dnn_smf_info_list
    cJSON *dnn_smf_info_list = cJSON_GetObjectItemCaseSensitive(snssai_smf_info_itemJSON, "dnnSmfInfoList");
    if (!dnn_smf_info_list) {
        goto end;
    }

    list_t *dnn_smf_info_listList;
    
    cJSON *dnn_smf_info_list_local_nonprimitive;
    if(!cJSON_IsArray(dnn_smf_info_list)){
        goto end; //nonprimitive container
    }

    dnn_smf_info_listList = list_create();

    cJSON_ArrayForEach(dnn_smf_info_list_local_nonprimitive,dnn_smf_info_list )
    {
        if(!cJSON_IsObject(dnn_smf_info_list_local_nonprimitive)){
            goto end;
        }
        dnn_smf_info_item_t *dnn_smf_info_listItem = dnn_smf_info_item_parseFromJSON(dnn_smf_info_list_local_nonprimitive);

        list_addElement(dnn_smf_info_listList, dnn_smf_info_listItem);
    }


    snssai_smf_info_item_local_var = snssai_smf_info_item_create (
        s_nssai_local_nonprim,
        dnn_smf_info_listList
        );

    return snssai_smf_info_item_local_var;
end:
    return NULL;

}
