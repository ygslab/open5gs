#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "supi_range.h"



supi_range_t *supi_range_create(
    char *start,
    char *end,
    char *pattern
    ) {
    supi_range_t *supi_range_local_var = malloc(sizeof(supi_range_t));
    if (!supi_range_local_var) {
        return NULL;
    }
    supi_range_local_var->start = start;
    supi_range_local_var->end = end;
    supi_range_local_var->pattern = pattern;

    return supi_range_local_var;
}


void supi_range_free(supi_range_t *supi_range) {
    if(NULL == supi_range){
        return ;
    }
    listEntry_t *listEntry;
    free(supi_range->start);
    free(supi_range->end);
    free(supi_range->pattern);
    free(supi_range);
}

cJSON *supi_range_convertToJSON(supi_range_t *supi_range) {
    cJSON *item = cJSON_CreateObject();

    // supi_range->start
    if(supi_range->start) { 
    if(cJSON_AddStringToObject(item, "start", supi_range->start) == NULL) {
    goto fail; //String
    }
     } 


    // supi_range->end
    if(supi_range->end) { 
    if(cJSON_AddStringToObject(item, "end", supi_range->end) == NULL) {
    goto fail; //String
    }
     } 


    // supi_range->pattern
    if(supi_range->pattern) { 
    if(cJSON_AddStringToObject(item, "pattern", supi_range->pattern) == NULL) {
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

supi_range_t *supi_range_parseFromJSON(cJSON *supi_rangeJSON){

    supi_range_t *supi_range_local_var = NULL;

    // supi_range->start
    cJSON *start = cJSON_GetObjectItemCaseSensitive(supi_rangeJSON, "start");
    if (start) { 
    if(!cJSON_IsString(start))
    {
    goto end; //String
    }
    }

    // supi_range->end
    cJSON *end = cJSON_GetObjectItemCaseSensitive(supi_rangeJSON, "end");
    if (end) { 
    if(!cJSON_IsString(end))
    {
    goto end; //String
    }
    }

    // supi_range->pattern
    cJSON *pattern = cJSON_GetObjectItemCaseSensitive(supi_rangeJSON, "pattern");
    if (pattern) { 
    if(!cJSON_IsString(pattern))
    {
    goto end; //String
    }
    }


    supi_range_local_var = supi_range_create (
        start ? strdup(start->valuestring) : NULL,
        end ? strdup(end->valuestring) : NULL,
        pattern ? strdup(pattern->valuestring) : NULL
        );

    return supi_range_local_var;
end:
    return NULL;

}
