#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "udm_info.h"



udm_info_t *udm_info_create(
    char *group_id,
    list_t *supi_ranges,
    list_t *gpsi_ranges,
    list_t *external_group_identifiers_ranges,
    list_t *routing_indicators
    ) {
    udm_info_t *udm_info_local_var = malloc(sizeof(udm_info_t));
    if (!udm_info_local_var) {
        return NULL;
    }
    udm_info_local_var->group_id = group_id;
    udm_info_local_var->supi_ranges = supi_ranges;
    udm_info_local_var->gpsi_ranges = gpsi_ranges;
    udm_info_local_var->external_group_identifiers_ranges = external_group_identifiers_ranges;
    udm_info_local_var->routing_indicators = routing_indicators;

    return udm_info_local_var;
}


void udm_info_free(udm_info_t *udm_info) {
    if(NULL == udm_info){
        return ;
    }
    listEntry_t *listEntry;
    free(udm_info->group_id);
    list_ForEach(listEntry, udm_info->supi_ranges) {
        supi_range_free(listEntry->data);
    }
    list_free(udm_info->supi_ranges);
    list_ForEach(listEntry, udm_info->gpsi_ranges) {
        identity_range_free(listEntry->data);
    }
    list_free(udm_info->gpsi_ranges);
    list_ForEach(listEntry, udm_info->external_group_identifiers_ranges) {
        identity_range_free(listEntry->data);
    }
    list_free(udm_info->external_group_identifiers_ranges);
    list_ForEach(listEntry, udm_info->routing_indicators) {
        free(listEntry->data);
    }
    list_free(udm_info->routing_indicators);
    free(udm_info);
}

cJSON *udm_info_convertToJSON(udm_info_t *udm_info) {
    cJSON *item = cJSON_CreateObject();

    // udm_info->group_id
    if(udm_info->group_id) { 
    if(cJSON_AddStringToObject(item, "groupId", udm_info->group_id) == NULL) {
    goto fail; //String
    }
     } 


    // udm_info->supi_ranges
    if(udm_info->supi_ranges) { 
    cJSON *supi_ranges = cJSON_AddArrayToObject(item, "supiRanges");
    if(supi_ranges == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *supi_rangesListEntry;
    if (udm_info->supi_ranges) {
    list_ForEach(supi_rangesListEntry, udm_info->supi_ranges) {
    cJSON *itemLocal = supi_range_convertToJSON(supi_rangesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(supi_ranges, itemLocal);
    }
    }
     } 


    // udm_info->gpsi_ranges
    if(udm_info->gpsi_ranges) { 
    cJSON *gpsi_ranges = cJSON_AddArrayToObject(item, "gpsiRanges");
    if(gpsi_ranges == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *gpsi_rangesListEntry;
    if (udm_info->gpsi_ranges) {
    list_ForEach(gpsi_rangesListEntry, udm_info->gpsi_ranges) {
    cJSON *itemLocal = identity_range_convertToJSON(gpsi_rangesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(gpsi_ranges, itemLocal);
    }
    }
     } 


    // udm_info->external_group_identifiers_ranges
    if(udm_info->external_group_identifiers_ranges) { 
    cJSON *external_group_identifiers_ranges = cJSON_AddArrayToObject(item, "externalGroupIdentifiersRanges");
    if(external_group_identifiers_ranges == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *external_group_identifiers_rangesListEntry;
    if (udm_info->external_group_identifiers_ranges) {
    list_ForEach(external_group_identifiers_rangesListEntry, udm_info->external_group_identifiers_ranges) {
    cJSON *itemLocal = identity_range_convertToJSON(external_group_identifiers_rangesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(external_group_identifiers_ranges, itemLocal);
    }
    }
     } 


    // udm_info->routing_indicators
    if(udm_info->routing_indicators) { 
    cJSON *routing_indicators = cJSON_AddArrayToObject(item, "routingIndicators");
    if(routing_indicators == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *routing_indicatorsListEntry;
    list_ForEach(routing_indicatorsListEntry, udm_info->routing_indicators) {
    if(cJSON_AddStringToObject(routing_indicators, "", (char*)routing_indicatorsListEntry->data) == NULL)
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

udm_info_t *udm_info_parseFromJSON(cJSON *udm_infoJSON){

    udm_info_t *udm_info_local_var = NULL;

    // udm_info->group_id
    cJSON *group_id = cJSON_GetObjectItemCaseSensitive(udm_infoJSON, "groupId");
    if (group_id) { 
    if(!cJSON_IsString(group_id))
    {
    goto end; //String
    }
    }

    // udm_info->supi_ranges
    cJSON *supi_ranges = cJSON_GetObjectItemCaseSensitive(udm_infoJSON, "supiRanges");
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

    // udm_info->gpsi_ranges
    cJSON *gpsi_ranges = cJSON_GetObjectItemCaseSensitive(udm_infoJSON, "gpsiRanges");
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

    // udm_info->external_group_identifiers_ranges
    cJSON *external_group_identifiers_ranges = cJSON_GetObjectItemCaseSensitive(udm_infoJSON, "externalGroupIdentifiersRanges");
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

    // udm_info->routing_indicators
    cJSON *routing_indicators = cJSON_GetObjectItemCaseSensitive(udm_infoJSON, "routingIndicators");
    list_t *routing_indicatorsList;
    if (routing_indicators) { 
    cJSON *routing_indicators_local;
    if(!cJSON_IsArray(routing_indicators)) {
        goto end;//primitive container
    }
    routing_indicatorsList = list_create();

    cJSON_ArrayForEach(routing_indicators_local, routing_indicators)
    {
        if(!cJSON_IsString(routing_indicators_local))
        {
            goto end;
        }
        list_addElement(routing_indicatorsList , strdup(routing_indicators_local->valuestring));
    }
    }


    udm_info_local_var = udm_info_create (
        group_id ? strdup(group_id->valuestring) : NULL,
        supi_ranges ? supi_rangesList : NULL,
        gpsi_ranges ? gpsi_rangesList : NULL,
        external_group_identifiers_ranges ? external_group_identifiers_rangesList : NULL,
        routing_indicators ? routing_indicatorsList : NULL
        );

    return udm_info_local_var;
end:
    return NULL;

}
