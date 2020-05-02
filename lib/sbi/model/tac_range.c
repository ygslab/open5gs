
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tac_range.h"

tac_range_t *tac_range_create(
    char *start,
    char *end,
    char *pattern
    )
{
    tac_range_t *tac_range_local_var = ogs_malloc(sizeof(tac_range_t));
    if (!tac_range_local_var) {
        return NULL;
    }
    tac_range_local_var->start = start;
    tac_range_local_var->end = end;
    tac_range_local_var->pattern = pattern;

    return tac_range_local_var;
}

void tac_range_free(tac_range_t *tac_range)
{
    if(NULL == tac_range) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(tac_range->start);
    ogs_free(tac_range->end);
    ogs_free(tac_range->pattern);
    ogs_free(tac_range);
}

cJSON *tac_range_convertToJSON(tac_range_t *tac_range)
{
    cJSON *item = cJSON_CreateObject();
    if (tac_range->start) {
        if(cJSON_AddStringToObject(item, "start", tac_range->start) == NULL) {
            goto fail;
        }
    }

    if (tac_range->end) {
        if(cJSON_AddStringToObject(item, "end", tac_range->end) == NULL) {
            goto fail;
        }
    }

    if (tac_range->pattern) {
        if(cJSON_AddStringToObject(item, "pattern", tac_range->pattern) == NULL) {
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

tac_range_t *tac_range_parseFromJSON(cJSON *tac_rangeJSON)
{
    tac_range_t *tac_range_local_var = NULL;
    cJSON *start = cJSON_GetObjectItemCaseSensitive(tac_rangeJSON, "start");

    if (start) {
        if(!cJSON_IsString(start))
        {
            goto end;
        }
    }

    cJSON *end = cJSON_GetObjectItemCaseSensitive(tac_rangeJSON, "end");

    if (end) {
        if(!cJSON_IsString(end))
        {
            goto end;
        }
    }

    cJSON *pattern = cJSON_GetObjectItemCaseSensitive(tac_rangeJSON, "pattern");

    if (pattern) {
        if(!cJSON_IsString(pattern))
        {
            goto end;
        }
    }

    tac_range_local_var = tac_range_create (
        start ? ogs_strdup(start->valuestring) : NULL,
        end ? ogs_strdup(end->valuestring) : NULL,
        pattern ? ogs_strdup(pattern->valuestring) : NULL
        );

    return tac_range_local_var;
end:
    return NULL;
}

