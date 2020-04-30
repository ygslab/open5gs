#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipv6_prefix.h"



ipv6_prefix_t *ipv6_prefix_create(
    ) {
    ipv6_prefix_t *ipv6_prefix_local_var = malloc(sizeof(ipv6_prefix_t));
    if (!ipv6_prefix_local_var) {
        return NULL;
    }

    return ipv6_prefix_local_var;
}


void ipv6_prefix_free(ipv6_prefix_t *ipv6_prefix) {
    if(NULL == ipv6_prefix){
        return ;
    }
    listEntry_t *listEntry;
    free(ipv6_prefix);
}

cJSON *ipv6_prefix_convertToJSON(ipv6_prefix_t *ipv6_prefix) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ipv6_prefix_t *ipv6_prefix_parseFromJSON(cJSON *ipv6_prefixJSON){

    ipv6_prefix_t *ipv6_prefix_local_var = NULL;


    ipv6_prefix_local_var = ipv6_prefix_create (
        );

    return ipv6_prefix_local_var;
end:
    return NULL;

}
