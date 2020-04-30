/*
 * plmn_range.h
 *
 * 
 */

#ifndef _plmn_range_H_
#define _plmn_range_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plmn_range_t plmn_range_t;




typedef struct plmn_range_t {
    char *start; // string
    char *end; // string
    char *pattern; // string

} plmn_range_t;

plmn_range_t *plmn_range_create(
    char *start,
    char *end,
    char *pattern
);

void plmn_range_free(plmn_range_t *plmn_range);

plmn_range_t *plmn_range_parseFromJSON(cJSON *plmn_rangeJSON);

cJSON *plmn_range_convertToJSON(plmn_range_t *plmn_range);

#endif /* _plmn_range_H_ */

