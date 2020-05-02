/*
 * ipv4_address_range.h
 *
 *
 */

#ifndef _ipv4_address_range_H_
#define _ipv4_address_range_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipv4_address_range_t ipv4_address_range_t;
typedef struct ipv4_address_range_t {
    char *start;
    char *end;
} ipv4_address_range_t;

ipv4_address_range_t *ipv4_address_range_create(
    char *start,
    char *end
    );
void ipv4_address_range_free(ipv4_address_range_t *ipv4_address_range);
ipv4_address_range_t *ipv4_address_range_parseFromJSON(cJSON *ipv4_address_rangeJSON);
cJSON *ipv4_address_range_convertToJSON(ipv4_address_range_t *ipv4_address_range);
#endif /* _ipv4_address_range_H_ */

