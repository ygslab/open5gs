#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tac_range.h"



tac_range_t *tac_range_create(
    char *start,
    char *end,
    char *pattern
    ) {
    tac_range_t *tac_range_local_var = malloc(sizeof(tac_range_t));
    if (!tac_range_local_var) {
        return NULL;
    }
    tac_range_local_var->start = start;
    tac_range_local_var->end = end;
    tac_range_local_var->pattern = pattern;

    return tac_range_local_var;
}


void tac_range_free(tac_range_t *tac_range) {
    if(NULL == tac_range){
        return ;
    }
    listEntry_t *listEntry;
    free(tac_range->start);
    free(tac_range->end);
    free(tac_range->pattern);
    free(tac_range);
}

cJSON *tac_range_convertToJSON(tac_range_t *tac_range) {
    cJSON *item = cJSON_CreateObject();

    // tac_range->start
    if(tac_range->start) { 
    if(cJSON_AddStringToObject(item, "start", tac_range->start) == NULL) {
    goto fail; //String
    }
     } 


    // tac_range->end
    if(tac_range->end) { 
    if(cJSON_AddStringToObject(item, "end", tac_range->end) == NULL) {
    goto fail; //String
    }
     } 


    // tac_range->pattern
    if(tac_range->pattern) { 
    if(cJSON_AddStringToObject(item, "pattern", tac_range->pattern) == NULL) {
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

tac_range_t *tac_range_parseFromJSON(cJSON *tac_rangeJSON){

    tac_range_t *tac_range_local_var = NULL;

    // tac_range->start
    cJSON *start = cJSON_GetObjectItemCaseSensitive(tac_rangeJSON, "start");
    if (start) { 
    if(!cJSON_IsString(start))
    {
    goto end; //String
    }
    }

    // tac_range->end
    cJSON *end = cJSON_GetObjectItemCaseSensitive(tac_rangeJSON, "end");
    if (end) { 
    if(!cJSON_IsString(end))
    {
    goto end; //String
    }
    }

    // tac_range->pattern
    cJSON *pattern = cJSON_GetObjectItemCaseSensitive(tac_rangeJSON, "pattern");
    if (pattern) { 
    if(!cJSON_IsString(pattern))
    {
    goto end; //String
    }
    }


    tac_range_local_var = tac_range_create (
        start ? strdup(start->valuestring) : NULL,
        end ? strdup(end->valuestring) : NULL,
        pattern ? strdup(pattern->valuestring) : NULL
        );

    return tac_range_local_var;
end:
    return NULL;

}
