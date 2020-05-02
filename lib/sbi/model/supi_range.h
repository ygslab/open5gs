/*
 * supi_range.h
 *
 *
 */

#ifndef _supi_range_H_
#define _supi_range_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct supi_range_t supi_range_t;
typedef struct supi_range_t {
    char *start;
    char *end;
    char *pattern;
} supi_range_t;

supi_range_t *supi_range_create(
    char *start,
    char *end,
    char *pattern
    );
void supi_range_free(supi_range_t *supi_range);
supi_range_t *supi_range_parseFromJSON(cJSON *supi_rangeJSON);
cJSON *supi_range_convertToJSON(supi_range_t *supi_range);
#endif /* _supi_range_H_ */

