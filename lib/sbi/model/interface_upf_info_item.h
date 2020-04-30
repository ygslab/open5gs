/*
 * interface_upf_info_item.h
 *
 * 
 */

#ifndef _interface_upf_info_item_H_
#define _interface_upf_info_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct interface_upf_info_item_t interface_upf_info_item_t;

#include "ipv6_addr.h"
#include "up_interface_type.h"



typedef struct interface_upf_info_item_t {
    struct up_interface_type_t *interface_type; //model
    list_t *ipv4_endpoint_addresses; //primitive container
    list_t *ipv6_endpoint_addresses; //nonprimitive container
    char *endpoint_fqdn; // string
    char *network_instance; // string

} interface_upf_info_item_t;

interface_upf_info_item_t *interface_upf_info_item_create(
    up_interface_type_t *interface_type,
    list_t *ipv4_endpoint_addresses,
    list_t *ipv6_endpoint_addresses,
    char *endpoint_fqdn,
    char *network_instance
);

void interface_upf_info_item_free(interface_upf_info_item_t *interface_upf_info_item);

interface_upf_info_item_t *interface_upf_info_item_parseFromJSON(cJSON *interface_upf_info_itemJSON);

cJSON *interface_upf_info_item_convertToJSON(interface_upf_info_item_t *interface_upf_info_item);

#endif /* _interface_upf_info_item_H_ */

