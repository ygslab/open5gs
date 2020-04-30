#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "identity_range.h"



identity_range_t *identity_range_create(
    char *start,
    char *end,
    char *pattern
    ) {
    identity_range_t *identity_range_local_var = malloc(sizeof(identity_range_t));
    if (!identity_range_local_var) {
        return NULL;
    }
    identity_range_local_var->start = start;
    identity_range_local_var->end = end;
    identity_range_local_var->pattern = pattern;

    return identity_range_local_var;
}


void identity_range_free(identity_range_t *identity_range) {
    if(NULL == identity_range){
        return ;
    }
    listEntry_t *listEntry;
    free(identity_range->start);
    free(identity_range->end);
    free(identity_range->pattern);
    free(identity_range);
}

cJSON *identity_range_convertToJSON(identity_range_t *identity_range) {
    cJSON *item = cJSON_CreateObject();

    // identity_range->start
    if(identity_range->start) { 
    if(cJSON_AddStringToObject(item, "start", identity_range->start) == NULL) {
    goto fail; //String
    }
     } 


    // identity_range->end
    if(identity_range->end) { 
    if(cJSON_AddStringToObject(item, "end", identity_range->end) == NULL) {
    goto fail; //String
    }
     } 


    // identity_range->pattern
    if(identity_range->pattern) { 
    if(cJSON_AddStringToObject(item, "pattern", identity_range->pattern) == NULL) {
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

identity_range_t *identity_range_parseFromJSON(cJSON *identity_rangeJSON){

    identity_range_t *identity_range_local_var = NULL;

    // identity_range->start
    cJSON *start = cJSON_GetObjectItemCaseSensitive(identity_rangeJSON, "start");
    if (start) { 
    if(!cJSON_IsString(start))
    {
    goto end; //String
    }
    }

    // identity_range->end
    cJSON *end = cJSON_GetObjectItemCaseSensitive(identity_rangeJSON, "end");
    if (end) { 
    if(!cJSON_IsString(end))
    {
    goto end; //String
    }
    }

    // identity_range->pattern
    cJSON *pattern = cJSON_GetObjectItemCaseSensitive(identity_rangeJSON, "pattern");
    if (pattern) { 
    if(!cJSON_IsString(pattern))
    {
    goto end; //String
    }
    }


    identity_range_local_var = identity_range_create (
        start ? strdup(start->valuestring) : NULL,
        end ? strdup(end->valuestring) : NULL,
        pattern ? strdup(pattern->valuestring) : NULL
        );

    return identity_range_local_var;
end:
    return NULL;

}
