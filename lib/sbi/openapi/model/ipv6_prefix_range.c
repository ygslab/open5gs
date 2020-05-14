
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipv6_prefix_range.h"

ogs_sbi_ipv6_prefix_range_t *ogs_sbi_ipv6_prefix_range_create(
    char *start,
    char *end
    )
{
    ogs_sbi_ipv6_prefix_range_t *ipv6_prefix_range_local_var = ogs_sbi_malloc(sizeof(ogs_sbi_ipv6_prefix_range_t));
    if (!ipv6_prefix_range_local_var) {
        return NULL;
    }
    ipv6_prefix_range_local_var->start = start;
    ipv6_prefix_range_local_var->end = end;

    return ipv6_prefix_range_local_var;
}

void ogs_sbi_ipv6_prefix_range_free(ogs_sbi_ipv6_prefix_range_t *ipv6_prefix_range)
{
    if (NULL == ipv6_prefix_range) {
        return;
    }
    ogs_sbi_lnode_t *node;
    ogs_free(ipv6_prefix_range->start);
    ogs_free(ipv6_prefix_range->end);
    ogs_free(ipv6_prefix_range);
}

cJSON *ogs_sbi_ipv6_prefix_range_convertToJSON(ogs_sbi_ipv6_prefix_range_t *ipv6_prefix_range)
{
    cJSON *item = cJSON_CreateObject();
    if (ipv6_prefix_range->start) {
        if (cJSON_AddStringToObject(item, "start", ipv6_prefix_range->start) == NULL) {
            ogs_error("ogs_sbi_ipv6_prefix_range_convertToJSON() failed [start]");
            goto end;
        }
    }

    if (ipv6_prefix_range->end) {
        if (cJSON_AddStringToObject(item, "end", ipv6_prefix_range->end) == NULL) {
            ogs_error("ogs_sbi_ipv6_prefix_range_convertToJSON() failed [end]");
            goto end;
        }
    }

end:
    return item;
}

ogs_sbi_ipv6_prefix_range_t *ogs_sbi_ipv6_prefix_range_parseFromJSON(cJSON *ipv6_prefix_rangeJSON)
{
    ogs_sbi_ipv6_prefix_range_t *ipv6_prefix_range_local_var = NULL;
    cJSON *start = cJSON_GetObjectItemCaseSensitive(ipv6_prefix_rangeJSON, "start");

    if (start) {
        if (!cJSON_IsString(start)) {
            ogs_error("ogs_sbi_ipv6_prefix_range_parseFromJSON() failed [start]");
            goto end;
        }
    }

    cJSON *end = cJSON_GetObjectItemCaseSensitive(ipv6_prefix_rangeJSON, "end");

    if (end) {
        if (!cJSON_IsString(end)) {
            ogs_error("ogs_sbi_ipv6_prefix_range_parseFromJSON() failed [end]");
            goto end;
        }
    }

    ipv6_prefix_range_local_var = ogs_sbi_ipv6_prefix_range_create (
        start ? ogs_strdup(start->valuestring) : NULL,
        end ? ogs_strdup(end->valuestring) : NULL
        );

    return ipv6_prefix_range_local_var;
end:
    return NULL;
}

