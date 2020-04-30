#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ausf_info.h"



ausf_info_t *ausf_info_create(
    char *group_id,
    list_t *supi_ranges,
    list_t *routing_indicators
    ) {
    ausf_info_t *ausf_info_local_var = malloc(sizeof(ausf_info_t));
    if (!ausf_info_local_var) {
        return NULL;
    }
    ausf_info_local_var->group_id = group_id;
    ausf_info_local_var->supi_ranges = supi_ranges;
    ausf_info_local_var->routing_indicators = routing_indicators;

    return ausf_info_local_var;
}


void ausf_info_free(ausf_info_t *ausf_info) {
    if(NULL == ausf_info){
        return ;
    }
    listEntry_t *listEntry;
    free(ausf_info->group_id);
    list_ForEach(listEntry, ausf_info->supi_ranges) {
        supi_range_free(listEntry->data);
    }
    list_free(ausf_info->supi_ranges);
    list_ForEach(listEntry, ausf_info->routing_indicators) {
        free(listEntry->data);
    }
    list_free(ausf_info->routing_indicators);
    free(ausf_info);
}

cJSON *ausf_info_convertToJSON(ausf_info_t *ausf_info) {
    cJSON *item = cJSON_CreateObject();

    // ausf_info->group_id
    if(ausf_info->group_id) { 
    if(cJSON_AddStringToObject(item, "groupId", ausf_info->group_id) == NULL) {
    goto fail; //String
    }
     } 


    // ausf_info->supi_ranges
    if(ausf_info->supi_ranges) { 
    cJSON *supi_ranges = cJSON_AddArrayToObject(item, "supiRanges");
    if(supi_ranges == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *supi_rangesListEntry;
    if (ausf_info->supi_ranges) {
    list_ForEach(supi_rangesListEntry, ausf_info->supi_ranges) {
    cJSON *itemLocal = supi_range_convertToJSON(supi_rangesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(supi_ranges, itemLocal);
    }
    }
     } 


    // ausf_info->routing_indicators
    if(ausf_info->routing_indicators) { 
    cJSON *routing_indicators = cJSON_AddArrayToObject(item, "routingIndicators");
    if(routing_indicators == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *routing_indicatorsListEntry;
    list_ForEach(routing_indicatorsListEntry, ausf_info->routing_indicators) {
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

ausf_info_t *ausf_info_parseFromJSON(cJSON *ausf_infoJSON){

    ausf_info_t *ausf_info_local_var = NULL;

    // ausf_info->group_id
    cJSON *group_id = cJSON_GetObjectItemCaseSensitive(ausf_infoJSON, "groupId");
    if (group_id) { 
    if(!cJSON_IsString(group_id))
    {
    goto end; //String
    }
    }

    // ausf_info->supi_ranges
    cJSON *supi_ranges = cJSON_GetObjectItemCaseSensitive(ausf_infoJSON, "supiRanges");
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

    // ausf_info->routing_indicators
    cJSON *routing_indicators = cJSON_GetObjectItemCaseSensitive(ausf_infoJSON, "routingIndicators");
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


    ausf_info_local_var = ausf_info_create (
        group_id ? strdup(group_id->valuestring) : NULL,
        supi_ranges ? supi_rangesList : NULL,
        routing_indicators ? routing_indicatorsList : NULL
        );

    return ausf_info_local_var;
end:
    return NULL;

}
