
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipv4_address_range.h"

ogs_sbi_ipv4_address_range_t *ogs_sbi_ipv4_address_range_create(
    char *start,
    char *end
    )
{
    ogs_sbi_ipv4_address_range_t *ipv4_address_range_local_var = ogs_sbi_malloc(sizeof(ogs_sbi_ipv4_address_range_t));
    if (!ipv4_address_range_local_var) {
        return NULL;
    }
    ipv4_address_range_local_var->start = start;
    ipv4_address_range_local_var->end = end;

    return ipv4_address_range_local_var;
}

void ogs_sbi_ipv4_address_range_free(ogs_sbi_ipv4_address_range_t *ipv4_address_range)
{
    if (NULL == ipv4_address_range) {
        return;
    }
    ogs_sbi_lnode_t *node;
    ogs_free(ipv4_address_range->start);
    ogs_free(ipv4_address_range->end);
    ogs_free(ipv4_address_range);
}

cJSON *ogs_sbi_ipv4_address_range_convertToJSON(ogs_sbi_ipv4_address_range_t *ipv4_address_range)
{
    cJSON *item = cJSON_CreateObject();
    if (ipv4_address_range->start) {
        if (cJSON_AddStringToObject(item, "start", ipv4_address_range->start) == NULL) {
            ogs_error("ogs_sbi_ipv4_address_range_convertToJSON() failed [start]");
            goto end;
        }
    }

    if (ipv4_address_range->end) {
        if (cJSON_AddStringToObject(item, "end", ipv4_address_range->end) == NULL) {
            ogs_error("ogs_sbi_ipv4_address_range_convertToJSON() failed [end]");
            goto end;
        }
    }

end:
    return item;
}

ogs_sbi_ipv4_address_range_t *ogs_sbi_ipv4_address_range_parseFromJSON(cJSON *ipv4_address_rangeJSON)
{
    ogs_sbi_ipv4_address_range_t *ipv4_address_range_local_var = NULL;
    cJSON *start = cJSON_GetObjectItemCaseSensitive(ipv4_address_rangeJSON, "start");

    if (start) {
        if (!cJSON_IsString(start)) {
            ogs_error("ogs_sbi_ipv4_address_range_parseFromJSON() failed [start]");
            goto end;
        }
    }

    cJSON *end = cJSON_GetObjectItemCaseSensitive(ipv4_address_rangeJSON, "end");

    if (end) {
        if (!cJSON_IsString(end)) {
            ogs_error("ogs_sbi_ipv4_address_range_parseFromJSON() failed [end]");
            goto end;
        }
    }

    ipv4_address_range_local_var = ogs_sbi_ipv4_address_range_create (
        start ? ogs_strdup(start->valuestring) : NULL,
        end ? ogs_strdup(end->valuestring) : NULL
        );

    return ipv4_address_range_local_var;
end:
    return NULL;
}

