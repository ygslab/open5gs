/*
 * ip_end_point.h
 *
 * 
 */

#ifndef _ip_end_point_H_
#define _ip_end_point_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ip_end_point_t ip_end_point_t;

#include "ipv6_addr.h"
#include "transport_protocol.h"



typedef struct ip_end_point_t {
    char *ipv4_address; // string
    struct ipv6_addr_t *ipv6_address; //model
    struct transport_protocol_t *transport; //model
    int port; //numeric

} ip_end_point_t;

ip_end_point_t *ip_end_point_create(
    char *ipv4_address,
    ipv6_addr_t *ipv6_address,
    transport_protocol_t *transport,
    int port
);

void ip_end_point_free(ip_end_point_t *ip_end_point);

ip_end_point_t *ip_end_point_parseFromJSON(cJSON *ip_end_pointJSON);

cJSON *ip_end_point_convertToJSON(ip_end_point_t *ip_end_point);

#endif /* _ip_end_point_H_ */

