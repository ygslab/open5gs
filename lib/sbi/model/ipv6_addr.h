/*
 * ipv6_addr.h
 *
 * 
 */

#ifndef _ipv6_addr_H_
#define _ipv6_addr_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipv6_addr_t ipv6_addr_t;




typedef struct ipv6_addr_t {

} ipv6_addr_t;

ipv6_addr_t *ipv6_addr_create(
);

void ipv6_addr_free(ipv6_addr_t *ipv6_addr);

ipv6_addr_t *ipv6_addr_parseFromJSON(cJSON *ipv6_addrJSON);

cJSON *ipv6_addr_convertToJSON(ipv6_addr_t *ipv6_addr);

#endif /* _ipv6_addr_H_ */

