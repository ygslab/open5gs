#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plmn_range.h"



plmn_range_t *plmn_range_create(
    char *start,
    char *end,
    char *pattern
    ) {
    plmn_range_t *plmn_range_local_var = malloc(sizeof(plmn_range_t));
    if (!plmn_range_local_var) {
        return NULL;
    }
    plmn_range_local_var->start = start;
    plmn_range_local_var->end = end;
    plmn_range_local_var->pattern = pattern;

    return plmn_range_local_var;
}


void plmn_range_free(plmn_range_t *plmn_range) {
    if(NULL == plmn_range){
        return ;
    }
    listEntry_t *listEntry;
    free(plmn_range->start);
    free(plmn_range->end);
    free(plmn_range->pattern);
    free(plmn_range);
}

cJSON *plmn_range_convertToJSON(plmn_range_t *plmn_range) {
    cJSON *item = cJSON_CreateObject();

    // plmn_range->start
    if(plmn_range->start) { 
    if(cJSON_AddStringToObject(item, "start", plmn_range->start) == NULL) {
    goto fail; //String
    }
     } 


    // plmn_range->end
    if(plmn_range->end) { 
    if(cJSON_AddStringToObject(item, "end", plmn_range->end) == NULL) {
    goto fail; //String
    }
     } 


    // plmn_range->pattern
    if(plmn_range->pattern) { 
    if(cJSON_AddStringToObject(item, "pattern", plmn_range->pattern) == NULL) {
    goto fail; //String
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

plmn_range_t *plmn_range_parseFromJSON(cJSON *plmn_rangeJSON){

    plmn_range_t *plmn_range_local_var = NULL;

    // plmn_range->start
    cJSON *start = cJSON_GetObjectItemCaseSensitive(plmn_rangeJSON, "start");
    if (start) { 
    if(!cJSON_IsString(start))
    {
    goto end; //String
    }
    }

    // plmn_range->end
    cJSON *end = cJSON_GetObjectItemCaseSensitive(plmn_rangeJSON, "end");
    if (end) { 
    if(!cJSON_IsString(end))
    {
    goto end; //String
    }
    }

    // plmn_range->pattern
    cJSON *pattern = cJSON_GetObjectItemCaseSensitive(plmn_rangeJSON, "pattern");
    if (pattern) { 
    if(!cJSON_IsString(pattern))
    {
    goto end; //String
    }
    }


    plmn_range_local_var = plmn_range_create (
        start ? strdup(start->valuestring) : NULL,
        end ? strdup(end->valuestring) : NULL,
        pattern ? strdup(pattern->valuestring) : NULL
        );

    return plmn_range_local_var;
end:
    return NULL;

}
