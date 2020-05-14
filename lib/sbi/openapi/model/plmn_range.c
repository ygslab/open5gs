
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plmn_range.h"

ogs_sbi_plmn_range_t *ogs_sbi_plmn_range_create(
    char *start,
    char *end,
    char *pattern
    )
{
    ogs_sbi_plmn_range_t *plmn_range_local_var = ogs_sbi_malloc(sizeof(ogs_sbi_plmn_range_t));
    if (!plmn_range_local_var) {
        return NULL;
    }
    plmn_range_local_var->start = start;
    plmn_range_local_var->end = end;
    plmn_range_local_var->pattern = pattern;

    return plmn_range_local_var;
}

void ogs_sbi_plmn_range_free(ogs_sbi_plmn_range_t *plmn_range)
{
    if (NULL == plmn_range) {
        return;
    }
    ogs_sbi_lnode_t *node;
    ogs_free(plmn_range->start);
    ogs_free(plmn_range->end);
    ogs_free(plmn_range->pattern);
    ogs_free(plmn_range);
}

cJSON *ogs_sbi_plmn_range_convertToJSON(ogs_sbi_plmn_range_t *plmn_range)
{
    cJSON *item = cJSON_CreateObject();
    if (plmn_range->start) {
        if (cJSON_AddStringToObject(item, "start", plmn_range->start) == NULL) {
            ogs_error("ogs_sbi_plmn_range_convertToJSON() failed [start]");
            goto end;
        }
    }

    if (plmn_range->end) {
        if (cJSON_AddStringToObject(item, "end", plmn_range->end) == NULL) {
            ogs_error("ogs_sbi_plmn_range_convertToJSON() failed [end]");
            goto end;
        }
    }

    if (plmn_range->pattern) {
        if (cJSON_AddStringToObject(item, "pattern", plmn_range->pattern) == NULL) {
            ogs_error("ogs_sbi_plmn_range_convertToJSON() failed [pattern]");
            goto end;
        }
    }

end:
    return item;
}

ogs_sbi_plmn_range_t *ogs_sbi_plmn_range_parseFromJSON(cJSON *plmn_rangeJSON)
{
    ogs_sbi_plmn_range_t *plmn_range_local_var = NULL;
    cJSON *start = cJSON_GetObjectItemCaseSensitive(plmn_rangeJSON, "start");

    if (start) {
        if (!cJSON_IsString(start)) {
            ogs_error("ogs_sbi_plmn_range_parseFromJSON() failed [start]");
            goto end;
        }
    }

    cJSON *end = cJSON_GetObjectItemCaseSensitive(plmn_rangeJSON, "end");

    if (end) {
        if (!cJSON_IsString(end)) {
            ogs_error("ogs_sbi_plmn_range_parseFromJSON() failed [end]");
            goto end;
        }
    }

    cJSON *pattern = cJSON_GetObjectItemCaseSensitive(plmn_rangeJSON, "pattern");

    if (pattern) {
        if (!cJSON_IsString(pattern)) {
            ogs_error("ogs_sbi_plmn_range_parseFromJSON() failed [pattern]");
            goto end;
        }
    }

    plmn_range_local_var = ogs_sbi_plmn_range_create (
        start ? ogs_strdup(start->valuestring) : NULL,
        end ? ogs_strdup(end->valuestring) : NULL,
        pattern ? ogs_strdup(pattern->valuestring) : NULL
        );

    return plmn_range_local_var;
end:
    return NULL;
}

