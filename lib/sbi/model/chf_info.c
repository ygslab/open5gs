#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chf_info.h"



chf_info_t *chf_info_create(
    list_t *supi_range_list,
    list_t *gpsi_range_list,
    list_t *plmn_range_list
    ) {
    chf_info_t *chf_info_local_var = malloc(sizeof(chf_info_t));
    if (!chf_info_local_var) {
        return NULL;
    }
    chf_info_local_var->supi_range_list = supi_range_list;
    chf_info_local_var->gpsi_range_list = gpsi_range_list;
    chf_info_local_var->plmn_range_list = plmn_range_list;

    return chf_info_local_var;
}


void chf_info_free(chf_info_t *chf_info) {
    if(NULL == chf_info){
        return ;
    }
    listEntry_t *listEntry;
    list_ForEach(listEntry, chf_info->supi_range_list) {
        supi_range_free(listEntry->data);
    }
    list_free(chf_info->supi_range_list);
    list_ForEach(listEntry, chf_info->gpsi_range_list) {
        identity_range_free(listEntry->data);
    }
    list_free(chf_info->gpsi_range_list);
    list_ForEach(listEntry, chf_info->plmn_range_list) {
        plmn_range_free(listEntry->data);
    }
    list_free(chf_info->plmn_range_list);
    free(chf_info);
}

cJSON *chf_info_convertToJSON(chf_info_t *chf_info) {
    cJSON *item = cJSON_CreateObject();

    // chf_info->supi_range_list
    if(chf_info->supi_range_list) { 
    cJSON *supi_range_list = cJSON_AddArrayToObject(item, "supiRangeList");
    if(supi_range_list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *supi_range_listListEntry;
    if (chf_info->supi_range_list) {
    list_ForEach(supi_range_listListEntry, chf_info->supi_range_list) {
    cJSON *itemLocal = supi_range_convertToJSON(supi_range_listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(supi_range_list, itemLocal);
    }
    }
     } 


    // chf_info->gpsi_range_list
    if(chf_info->gpsi_range_list) { 
    cJSON *gpsi_range_list = cJSON_AddArrayToObject(item, "gpsiRangeList");
    if(gpsi_range_list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *gpsi_range_listListEntry;
    if (chf_info->gpsi_range_list) {
    list_ForEach(gpsi_range_listListEntry, chf_info->gpsi_range_list) {
    cJSON *itemLocal = identity_range_convertToJSON(gpsi_range_listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(gpsi_range_list, itemLocal);
    }
    }
     } 


    // chf_info->plmn_range_list
    if(chf_info->plmn_range_list) { 
    cJSON *plmn_range_list = cJSON_AddArrayToObject(item, "plmnRangeList");
    if(plmn_range_list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *plmn_range_listListEntry;
    if (chf_info->plmn_range_list) {
    list_ForEach(plmn_range_listListEntry, chf_info->plmn_range_list) {
    cJSON *itemLocal = plmn_range_convertToJSON(plmn_range_listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(plmn_range_list, itemLocal);
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

chf_info_t *chf_info_parseFromJSON(cJSON *chf_infoJSON){

    chf_info_t *chf_info_local_var = NULL;

    // chf_info->supi_range_list
    cJSON *supi_range_list = cJSON_GetObjectItemCaseSensitive(chf_infoJSON, "supiRangeList");
    list_t *supi_range_listList;
    if (supi_range_list) { 
    cJSON *supi_range_list_local_nonprimitive;
    if(!cJSON_IsArray(supi_range_list)){
        goto end; //nonprimitive container
    }

    supi_range_listList = list_create();

    cJSON_ArrayForEach(supi_range_list_local_nonprimitive,supi_range_list )
    {
        if(!cJSON_IsObject(supi_range_list_local_nonprimitive)){
            goto end;
        }
        supi_range_t *supi_range_listItem = supi_range_parseFromJSON(supi_range_list_local_nonprimitive);

        list_addElement(supi_range_listList, supi_range_listItem);
    }
    }

    // chf_info->gpsi_range_list
    cJSON *gpsi_range_list = cJSON_GetObjectItemCaseSensitive(chf_infoJSON, "gpsiRangeList");
    list_t *gpsi_range_listList;
    if (gpsi_range_list) { 
    cJSON *gpsi_range_list_local_nonprimitive;
    if(!cJSON_IsArray(gpsi_range_list)){
        goto end; //nonprimitive container
    }

    gpsi_range_listList = list_create();

    cJSON_ArrayForEach(gpsi_range_list_local_nonprimitive,gpsi_range_list )
    {
        if(!cJSON_IsObject(gpsi_range_list_local_nonprimitive)){
            goto end;
        }
        identity_range_t *gpsi_range_listItem = identity_range_parseFromJSON(gpsi_range_list_local_nonprimitive);

        list_addElement(gpsi_range_listList, gpsi_range_listItem);
    }
    }

    // chf_info->plmn_range_list
    cJSON *plmn_range_list = cJSON_GetObjectItemCaseSensitive(chf_infoJSON, "plmnRangeList");
    list_t *plmn_range_listList;
    if (plmn_range_list) { 
    cJSON *plmn_range_list_local_nonprimitive;
    if(!cJSON_IsArray(plmn_range_list)){
        goto end; //nonprimitive container
    }

    plmn_range_listList = list_create();

    cJSON_ArrayForEach(plmn_range_list_local_nonprimitive,plmn_range_list )
    {
        if(!cJSON_IsObject(plmn_range_list_local_nonprimitive)){
            goto end;
        }
        plmn_range_t *plmn_range_listItem = plmn_range_parseFromJSON(plmn_range_list_local_nonprimitive);

        list_addElement(plmn_range_listList, plmn_range_listItem);
    }
    }


    chf_info_local_var = chf_info_create (
        supi_range_list ? supi_range_listList : NULL,
        gpsi_range_list ? gpsi_range_listList : NULL,
        plmn_range_list ? plmn_range_listList : NULL
        );

    return chf_info_local_var;
end:
    return NULL;

}
