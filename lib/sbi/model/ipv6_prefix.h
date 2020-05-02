/*
 * ipv6_prefix.h
 *
 *
 */

#ifndef _ipv6_prefix_H_
#define _ipv6_prefix_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipv6_prefix_t ipv6_prefix_t;
typedef struct ipv6_prefix_t {
} ipv6_prefix_t;

ipv6_prefix_t *ipv6_prefix_create(
    );
void ipv6_prefix_free(ipv6_prefix_t *ipv6_prefix);
ipv6_prefix_t *ipv6_prefix_parseFromJSON(cJSON *ipv6_prefixJSON);
cJSON *ipv6_prefix_convertToJSON(ipv6_prefix_t *ipv6_prefix);
#endif /* _ipv6_prefix_H_ */

