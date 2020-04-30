#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "udr_info.h"



udr_info_t *udr_info_create(
    char *group_id,
    list_t *supi_ranges,
    list_t *gpsi_ranges,
    list_t *external_group_identifiers_ranges,
    list_t *supported_data_sets
    ) {
    udr_info_t *udr_info_local_var = malloc(sizeof(udr_info_t));
    if (!udr_info_local_var) {
        return NULL;
    }
    udr_info_local_var->group_id = group_id;
    udr_info_local_var->supi_ranges = supi_ranges;
    udr_info_local_var->gpsi_ranges = gpsi_ranges;
    udr_info_local_var->external_group_identifiers_ranges = external_group_identifiers_ranges;
    udr_info_local_var->supported_data_sets = supported_data_sets;

    return udr_info_local_var;
}


void udr_info_free(udr_info_t *udr_info) {
    if(NULL == udr_info){
        return ;
    }
    listEntry_t *listEntry;
    free(udr_info->group_id);
    list_ForEach(listEntry, udr_info->supi_ranges) {
        supi_range_free(listEntry->data);
    }
    list_free(udr_info->supi_ranges);
    list_ForEach(listEntry, udr_info->gpsi_ranges) {
        identity_range_free(listEntry->data);
    }
    list_free(udr_info->gpsi_ranges);
    list_ForEach(listEntry, udr_info->external_group_identifiers_ranges) {
        identity_range_free(listEntry->data);
    }
    list_free(udr_info->external_group_identifiers_ranges);
    list_ForEach(listEntry, udr_info->supported_data_sets) {
        data_set_id_free(listEntry->data);
    }
    list_free(udr_info->supported_data_sets);
    free(udr_info);
}

cJSON *udr_info_convertToJSON(udr_info_t *udr_info) {
    cJSON *item = cJSON_CreateObject();

    // udr_info->group_id
    if(udr_info->group_id) { 
    if(cJSON_AddStringToObject(item, "groupId", udr_info->group_id) == NULL) {
    goto fail; //String
    }
     } 


    // udr_info->supi_ranges
    if(udr_info->supi_ranges) { 
    cJSON *supi_ranges = cJSON_AddArrayToObject(item, "supiRanges");
    if(supi_ranges == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *supi_rangesListEntry;
    if (udr_info->supi_ranges) {
    list_ForEach(supi_rangesListEntry, udr_info->supi_ranges) {
    cJSON *itemLocal = supi_range_convertToJSON(supi_rangesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(supi_ranges, itemLocal);
    }
    }
     } 


    // udr_info->gpsi_ranges
    if(udr_info->gpsi_ranges) { 
    cJSON *gpsi_ranges = cJSON_AddArrayToObject(item, "gpsiRanges");
    if(gpsi_ranges == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *gpsi_rangesListEntry;
    if (udr_info->gpsi_ranges) {
    list_ForEach(gpsi_rangesListEntry, udr_info->gpsi_ranges) {
    cJSON *itemLocal = identity_range_convertToJSON(gpsi_rangesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(gpsi_ranges, itemLocal);
    }
    }
     } 


    // udr_info->external_group_identifiers_ranges
    if(udr_info->external_group_identifiers_ranges) { 
    cJSON *external_group_identifiers_ranges = cJSON_AddArrayToObject(item, "externalGroupIdentifiersRanges");
    if(external_group_identifiers_ranges == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *external_group_identifiers_rangesListEntry;
    if (udr_info->external_group_identifiers_ranges) {
    list_ForEach(external_group_identifiers_rangesListEntry, udr_info->external_group_identifiers_ranges) {
    cJSON *itemLocal = identity_range_convertToJSON(external_group_identifiers_rangesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(external_group_identifiers_ranges, itemLocal);
    }
    }
     } 


    // udr_info->supported_data_sets
    if(udr_info->supported_data_sets) { 
    cJSON *supported_data_sets = cJSON_AddArrayToObject(item, "supportedDataSets");
    if(supported_data_sets == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *supported_data_setsListEntry;
    if (udr_info->supported_data_sets) {
    list_ForEach(supported_data_setsListEntry, udr_info->supported_data_sets) {
    cJSON *itemLocal = data_set_id_convertToJSON(supported_data_setsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(supported_data_sets, itemLocal);
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

udr_info_t *udr_info_parseFromJSON(cJSON *udr_infoJSON){

    udr_info_t *udr_info_local_var = NULL;

    // udr_info->group_id
    cJSON *group_id = cJSON_GetObjectItemCaseSensitive(udr_infoJSON, "groupId");
    if (group_id) { 
    if(!cJSON_IsString(group_id))
    {
    goto end; //String
    }
    }

    // udr_info->supi_ranges
    cJSON *supi_ranges = cJSON_GetObjectItemCaseSensitive(udr_infoJSON, "supiRanges");
    list_t *supi_rangesList;
    if (supi_ranges) { 
    cJSON *supi_ranges_local_nonprimitive;
    if(!cJSON_IsArray(supi_ranges)){
        goto end; //nonprimitive container
    }

    supi_rangesList = list_create();

    cJSON_ArrayForEach(supi_ranges_local_nonprimitive,supi_ranges )
    {
        if(!cJSON_IsObject(supi_ranges_local_nonprimitive)){
            goto end;
        }
        supi_range_t *supi_rangesItem = supi_range_parseFromJSON(supi_ranges_local_nonprimitive);

        list_addElement(supi_rangesList, supi_rangesItem);
    }
    }

    // udr_info->gpsi_ranges
    cJSON *gpsi_ranges = cJSON_GetObjectItemCaseSensitive(udr_infoJSON, "gpsiRanges");
    list_t *gpsi_rangesList;
    if (gpsi_ranges) { 
    cJSON *gpsi_ranges_local_nonprimitive;
    if(!cJSON_IsArray(gpsi_ranges)){
        goto end; //nonprimitive container
    }

    gpsi_rangesList = list_create();

    cJSON_ArrayForEach(gpsi_ranges_local_nonprimitive,gpsi_ranges )
    {
        if(!cJSON_IsObject(gpsi_ranges_local_nonprimitive)){
            goto end;
        }
        identity_range_t *gpsi_rangesItem = identity_range_parseFromJSON(gpsi_ranges_local_nonprimitive);

        list_addElement(gpsi_rangesList, gpsi_rangesItem);
    }
    }

    // udr_info->external_group_identifiers_ranges
    cJSON *external_group_identifiers_ranges = cJSON_GetObjectItemCaseSensitive(udr_infoJSON, "externalGroupIdentifiersRanges");
    list_t *external_group_identifiers_rangesList;
    if (external_group_identifiers_ranges) { 
    cJSON *external_group_identifiers_ranges_local_nonprimitive;
    if(!cJSON_IsArray(external_group_identifiers_ranges)){
        goto end; //nonprimitive container
    }

    external_group_identifiers_rangesList = list_create();

    cJSON_ArrayForEach(external_group_identifiers_ranges_local_nonprimitive,external_group_identifiers_ranges )
    {
        if(!cJSON_IsObject(external_group_identifiers_ranges_local_nonprimitive)){
            goto end;
        }
        identity_range_t *external_group_identifiers_rangesItem = identity_range_parseFromJSON(external_group_identifiers_ranges_local_nonprimitive);

        list_addElement(external_group_identifiers_rangesList, external_group_identifiers_rangesItem);
    }
    }

    // udr_info->supported_data_sets
    cJSON *supported_data_sets = cJSON_GetObjectItemCaseSensitive(udr_infoJSON, "supportedDataSets");
    list_t *supported_data_setsList;
    if (supported_data_sets) { 
    cJSON *supported_data_sets_local_nonprimitive;
    if(!cJSON_IsArray(supported_data_sets)){
        goto end; //nonprimitive container
    }

    supported_data_setsList = list_create();

    cJSON_ArrayForEach(supported_data_sets_local_nonprimitive,supported_data_sets )
    {
        if(!cJSON_IsObject(supported_data_sets_local_nonprimitive)){
            goto end;
        }
        data_set_id_t *supported_data_setsItem = data_set_id_parseFromJSON(supported_data_sets_local_nonprimitive);

        list_addElement(supported_data_setsList, supported_data_setsItem);
    }
    }


    udr_info_local_var = udr_info_create (
        group_id ? strdup(group_id->valuestring) : NULL,
        supi_ranges ? supi_rangesList : NULL,
        gpsi_ranges ? gpsi_rangesList : NULL,
        external_group_identifiers_ranges ? external_group_identifiers_rangesList : NULL,
        supported_data_sets ? supported_data_setsList : NULL
        );

    return udr_info_local_var;
end:
    return NULL;

}
