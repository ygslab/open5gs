
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipv4_address_range.h"

ipv4_address_range_t *ipv4_address_range_create(
    char *start,
    char *end
    )
{
    ipv4_address_range_t *ipv4_address_range_local_var = ogs_malloc(sizeof(ipv4_address_range_t));
    if (!ipv4_address_range_local_var) {
        return NULL;
    }
    ipv4_address_range_local_var->start = start;
    ipv4_address_range_local_var->end = end;

    return ipv4_address_range_local_var;
}

void ipv4_address_range_free(ipv4_address_range_t *ipv4_address_range)
{
    if(NULL == ipv4_address_range) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(ipv4_address_range->start);
    ogs_free(ipv4_address_range->end);
    ogs_free(ipv4_address_range);
}

cJSON *ipv4_address_range_convertToJSON(ipv4_address_range_t *ipv4_address_range)
{
    cJSON *item = cJSON_CreateObject();
    if (ipv4_address_range->start) {
        if(cJSON_AddStringToObject(item, "start", ipv4_address_range->start) == NULL) {
            goto fail;
        }
    }

    if (ipv4_address_range->end) {
        if(cJSON_AddStringToObject(item, "end", ipv4_address_range->end) == NULL) {
            goto fail;
        }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ipv4_address_range_t *ipv4_address_range_parseFromJSON(cJSON *ipv4_address_rangeJSON)
{
    ipv4_address_range_t *ipv4_address_range_local_var = NULL;
    cJSON *start = cJSON_GetObjectItemCaseSensitive(ipv4_address_rangeJSON, "start");

    if (start) {
        if(!cJSON_IsString(start))
        {
            goto end;
        }
    }

    cJSON *end = cJSON_GetObjectItemCaseSensitive(ipv4_address_rangeJSON, "end");

    if (end) {
        if(!cJSON_IsString(end))
        {
            goto end;
        }
    }

    ipv4_address_range_local_var = ipv4_address_range_create (
        start ? ogs_strdup(start->valuestring) : NULL,
        end ? ogs_strdup(end->valuestring) : NULL
        );

    return ipv4_address_range_local_var;
end:
    return NULL;
}

