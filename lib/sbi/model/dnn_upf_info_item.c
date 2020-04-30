#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dnn_upf_info_item.h"



dnn_upf_info_item_t *dnn_upf_info_item_create(
    char *dnn,
    list_t *dnai_list,
    list_t *pdu_session_types
    ) {
    dnn_upf_info_item_t *dnn_upf_info_item_local_var = malloc(sizeof(dnn_upf_info_item_t));
    if (!dnn_upf_info_item_local_var) {
        return NULL;
    }
    dnn_upf_info_item_local_var->dnn = dnn;
    dnn_upf_info_item_local_var->dnai_list = dnai_list;
    dnn_upf_info_item_local_var->pdu_session_types = pdu_session_types;

    return dnn_upf_info_item_local_var;
}


void dnn_upf_info_item_free(dnn_upf_info_item_t *dnn_upf_info_item) {
    if(NULL == dnn_upf_info_item){
        return ;
    }
    listEntry_t *listEntry;
    free(dnn_upf_info_item->dnn);
    list_ForEach(listEntry, dnn_upf_info_item->dnai_list) {
        free(listEntry->data);
    }
    list_free(dnn_upf_info_item->dnai_list);
    list_ForEach(listEntry, dnn_upf_info_item->pdu_session_types) {
        pdu_session_type_free(listEntry->data);
    }
    list_free(dnn_upf_info_item->pdu_session_types);
    free(dnn_upf_info_item);
}

cJSON *dnn_upf_info_item_convertToJSON(dnn_upf_info_item_t *dnn_upf_info_item) {
    cJSON *item = cJSON_CreateObject();

    // dnn_upf_info_item->dnn
    if (!dnn_upf_info_item->dnn) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "dnn", dnn_upf_info_item->dnn) == NULL) {
    goto fail; //String
    }


    // dnn_upf_info_item->dnai_list
    if(dnn_upf_info_item->dnai_list) { 
    cJSON *dnai_list = cJSON_AddArrayToObject(item, "dnaiList");
    if(dnai_list == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *dnai_listListEntry;
    list_ForEach(dnai_listListEntry, dnn_upf_info_item->dnai_list) {
    if(cJSON_AddStringToObject(dnai_list, "", (char*)dnai_listListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // dnn_upf_info_item->pdu_session_types
    if(dnn_upf_info_item->pdu_session_types) { 
    cJSON *pdu_session_types = cJSON_AddArrayToObject(item, "pduSessionTypes");
    if(pdu_session_types == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *pdu_session_typesListEntry;
    if (dnn_upf_info_item->pdu_session_types) {
    list_ForEach(pdu_session_typesListEntry, dnn_upf_info_item->pdu_session_types) {
    cJSON *itemLocal = pdu_session_type_convertToJSON(pdu_session_typesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(pdu_session_types, itemLocal);
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

dnn_upf_info_item_t *dnn_upf_info_item_parseFromJSON(cJSON *dnn_upf_info_itemJSON){

    dnn_upf_info_item_t *dnn_upf_info_item_local_var = NULL;

    // dnn_upf_info_item->dnn
    cJSON *dnn = cJSON_GetObjectItemCaseSensitive(dnn_upf_info_itemJSON, "dnn");
    if (!dnn) {
        goto end;
    }

    
    if(!cJSON_IsString(dnn))
    {
    goto end; //String
    }

    // dnn_upf_info_item->dnai_list
    cJSON *dnai_list = cJSON_GetObjectItemCaseSensitive(dnn_upf_info_itemJSON, "dnaiList");
    list_t *dnai_listList;
    if (dnai_list) { 
    cJSON *dnai_list_local;
    if(!cJSON_IsArray(dnai_list)) {
        goto end;//primitive container
    }
    dnai_listList = list_create();

    cJSON_ArrayForEach(dnai_list_local, dnai_list)
    {
        if(!cJSON_IsString(dnai_list_local))
        {
            goto end;
        }
        list_addElement(dnai_listList , strdup(dnai_list_local->valuestring));
    }
    }

    // dnn_upf_info_item->pdu_session_types
    cJSON *pdu_session_types = cJSON_GetObjectItemCaseSensitive(dnn_upf_info_itemJSON, "pduSessionTypes");
    list_t *pdu_session_typesList;
    if (pdu_session_types) { 
    cJSON *pdu_session_types_local_nonprimitive;
    if(!cJSON_IsArray(pdu_session_types)){
        goto end; //nonprimitive container
    }

    pdu_session_typesList = list_create();

    cJSON_ArrayForEach(pdu_session_types_local_nonprimitive,pdu_session_types )
    {
        if(!cJSON_IsObject(pdu_session_types_local_nonprimitive)){
            goto end;
        }
        pdu_session_type_t *pdu_session_typesItem = pdu_session_type_parseFromJSON(pdu_session_types_local_nonprimitive);

        list_addElement(pdu_session_typesList, pdu_session_typesItem);
    }
    }


    dnn_upf_info_item_local_var = dnn_upf_info_item_create (
        strdup(dnn->valuestring),
        dnai_list ? dnai_listList : NULL,
        pdu_session_types ? pdu_session_typesList : NULL
        );

    return dnn_upf_info_item_local_var;
end:
    return NULL;

}
