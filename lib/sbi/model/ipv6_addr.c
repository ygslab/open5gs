
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipv6_addr.h"

ipv6_addr_t *ipv6_addr_create(
    )
{
    ipv6_addr_t *ipv6_addr_local_var = ogs_malloc(sizeof(ipv6_addr_t));
    if (!ipv6_addr_local_var) {
        return NULL;
    }

    return ipv6_addr_local_var;
}

void ipv6_addr_free(ipv6_addr_t *ipv6_addr)
{
    if(NULL == ipv6_addr) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(ipv6_addr);
}

cJSON *ipv6_addr_convertToJSON(ipv6_addr_t *ipv6_addr)
{
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ipv6_addr_t *ipv6_addr_parseFromJSON(cJSON *ipv6_addrJSON)
{
    ipv6_addr_t *ipv6_addr_local_var = NULL;
    ipv6_addr_local_var = ipv6_addr_create (
        );

    return ipv6_addr_local_var;
end:
    return NULL;
}

