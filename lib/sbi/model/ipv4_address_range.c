#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipv4_address_range.h"



ipv4_address_range_t *ipv4_address_range_create(
    char *start,
    char *end
    ) {
    ipv4_address_range_t *ipv4_address_range_local_var = malloc(sizeof(ipv4_address_range_t));
    if (!ipv4_address_range_local_var) {
        return NULL;
    }
    ipv4_address_range_local_var->start = start;
    ipv4_address_range_local_var->end = end;

    return ipv4_address_range_local_var;
}


void ipv4_address_range_free(ipv4_address_range_t *ipv4_address_range) {
    if(NULL == ipv4_address_range){
        return ;
    }
    listEntry_t *listEntry;
    free(ipv4_address_range->start);
    free(ipv4_address_range->end);
    free(ipv4_address_range);
}

cJSON *ipv4_address_range_convertToJSON(ipv4_address_range_t *ipv4_address_range) {
    cJSON *item = cJSON_CreateObject();

    // ipv4_address_range->start
    if(ipv4_address_range->start) { 
    if(cJSON_AddStringToObject(item, "start", ipv4_address_range->start) == NULL) {
    goto fail; //String
    }
     } 


    // ipv4_address_range->end
    if(ipv4_address_range->end) { 
    if(cJSON_AddStringToObject(item, "end", ipv4_address_range->end) == NULL) {
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

ipv4_address_range_t *ipv4_address_range_parseFromJSON(cJSON *ipv4_address_rangeJSON){

    ipv4_address_range_t *ipv4_address_range_local_var = NULL;

    // ipv4_address_range->start
    cJSON *start = cJSON_GetObjectItemCaseSensitive(ipv4_address_rangeJSON, "start");
    if (start) { 
    if(!cJSON_IsString(start))
    {
    goto end; //String
    }
    }

    // ipv4_address_range->end
    cJSON *end = cJSON_GetObjectItemCaseSensitive(ipv4_address_rangeJSON, "end");
    if (end) { 
    if(!cJSON_IsString(end))
    {
    goto end; //String
    }
    }


    ipv4_address_range_local_var = ipv4_address_range_create (
        start ? strdup(start->valuestring) : NULL,
        end ? strdup(end->valuestring) : NULL
        );

    return ipv4_address_range_local_var;
end:
    return NULL;

}
