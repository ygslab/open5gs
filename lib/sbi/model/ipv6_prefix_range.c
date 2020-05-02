
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipv6_prefix_range.h"

ipv6_prefix_range_t *ipv6_prefix_range_create(
    ipv6_prefix_t *start,
    ipv6_prefix_t *end
    )
{
    ipv6_prefix_range_t *ipv6_prefix_range_local_var = ogs_malloc(sizeof(ipv6_prefix_range_t));
    if (!ipv6_prefix_range_local_var) {
        return NULL;
    }
    ipv6_prefix_range_local_var->start = start;
    ipv6_prefix_range_local_var->end = end;

    return ipv6_prefix_range_local_var;
}

void ipv6_prefix_range_free(ipv6_prefix_range_t *ipv6_prefix_range)
{
    if(NULL == ipv6_prefix_range) {
        return;
    }
    listEntry_t *listEntry;
    ipv6_prefix_free(ipv6_prefix_range->start);
    ipv6_prefix_free(ipv6_prefix_range->end);
    ogs_free(ipv6_prefix_range);
}

cJSON *ipv6_prefix_range_convertToJSON(ipv6_prefix_range_t *ipv6_prefix_range)
{
    cJSON *item = cJSON_CreateObject();
    if (ipv6_prefix_range->start) {
        cJSON *start_local_JSON = ipv6_prefix_convertToJSON(ipv6_prefix_range->start);
        if(start_local_JSON == NULL) {
            goto fail;
        }
        cJSON_AddItemToObject(item, "start", start_local_JSON);
        if(item->child == NULL) {
            goto fail;
        }
    }

    if (ipv6_prefix_range->end) {
        cJSON *end_local_JSON = ipv6_prefix_convertToJSON(ipv6_prefix_range->end);
        if(end_local_JSON == NULL) {
            goto fail;
        }
        cJSON_AddItemToObject(item, "end", end_local_JSON);
        if(item->child == NULL) {
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

ipv6_prefix_range_t *ipv6_prefix_range_parseFromJSON(cJSON *ipv6_prefix_rangeJSON)
{
    ipv6_prefix_range_t *ipv6_prefix_range_local_var = NULL;
    cJSON *start = cJSON_GetObjectItemCaseSensitive(ipv6_prefix_rangeJSON, "start");

    ipv6_prefix_t *start_local_nonprim = NULL;
    if (start) {
        start_local_nonprim = ipv6_prefix_parseFromJSON(start);
    }

    cJSON *end = cJSON_GetObjectItemCaseSensitive(ipv6_prefix_rangeJSON, "end");

    ipv6_prefix_t *end_local_nonprim = NULL;
    if (end) {
        end_local_nonprim = ipv6_prefix_parseFromJSON(end);
    }

    ipv6_prefix_range_local_var = ipv6_prefix_range_create (
        start ? start_local_nonprim : NULL,
        end ? end_local_nonprim : NULL
        );

    return ipv6_prefix_range_local_var;
end:
    return NULL;
}

