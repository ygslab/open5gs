/*
 * identity_range.h
 *
 * 
 */

#ifndef _identity_range_H_
#define _identity_range_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct identity_range_t identity_range_t;




typedef struct identity_range_t {
    char *start; // string
    char *end; // string
    char *pattern; // string

} identity_range_t;

identity_range_t *identity_range_create(
    char *start,
    char *end,
    char *pattern
);

void identity_range_free(identity_range_t *identity_range);

identity_range_t *identity_range_parseFromJSON(cJSON *identity_rangeJSON);

cJSON *identity_range_convertToJSON(identity_range_t *identity_range);

#endif /* _identity_range_H_ */

