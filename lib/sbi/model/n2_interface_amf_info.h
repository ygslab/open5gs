/*
 * n2_interface_amf_info.h
 *
 *
 */

#ifndef _n2_interface_amf_info_H_
#define _n2_interface_amf_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ipv6_addr.h"

typedef struct n2_interface_amf_info_t n2_interface_amf_info_t;
typedef struct n2_interface_amf_info_t {
    list_t *ipv4_endpoint_address;
    list_t *ipv6_endpoint_address;
    char *amf_name;
} n2_interface_amf_info_t;

n2_interface_amf_info_t *n2_interface_amf_info_create(
    list_t *ipv4_endpoint_address,
    list_t *ipv6_endpoint_address,
    char *amf_name
    );
void n2_interface_amf_info_free(n2_interface_amf_info_t *n2_interface_amf_info);
n2_interface_amf_info_t *n2_interface_amf_info_parseFromJSON(cJSON *n2_interface_amf_infoJSON);
cJSON *n2_interface_amf_info_convertToJSON(n2_interface_amf_info_t *n2_interface_amf_info);
#endif /* _n2_interface_amf_info_H_ */

