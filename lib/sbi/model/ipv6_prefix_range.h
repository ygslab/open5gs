/*
 * ipv6_prefix_range.h
 *
 *
 */

#ifndef _ipv6_prefix_range_H_
#define _ipv6_prefix_range_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ipv6_prefix.h"

typedef struct ipv6_prefix_range_t ipv6_prefix_range_t;
typedef struct ipv6_prefix_range_t {
    struct ipv6_prefix_t *start;
    struct ipv6_prefix_t *end;
} ipv6_prefix_range_t;

ipv6_prefix_range_t *ipv6_prefix_range_create(
    ipv6_prefix_t *start,
    ipv6_prefix_t *end
    );
void ipv6_prefix_range_free(ipv6_prefix_range_t *ipv6_prefix_range);
ipv6_prefix_range_t *ipv6_prefix_range_parseFromJSON(cJSON *ipv6_prefix_rangeJSON);
cJSON *ipv6_prefix_range_convertToJSON(ipv6_prefix_range_t *ipv6_prefix_range);
#endif /* _ipv6_prefix_range_H_ */

