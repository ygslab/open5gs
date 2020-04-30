/*
 * bsf_info.h
 *
 * 
 */

#ifndef _bsf_info_H_
#define _bsf_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bsf_info_t bsf_info_t;

#include "ipv4_address_range.h"
#include "ipv6_prefix_range.h"



typedef struct bsf_info_t {
    list_t *dnn_list; //primitive container
    list_t *ip_domain_list; //primitive container
    list_t *ipv4_address_ranges; //nonprimitive container
    list_t *ipv6_prefix_ranges; //nonprimitive container

} bsf_info_t;

bsf_info_t *bsf_info_create(
    list_t *dnn_list,
    list_t *ip_domain_list,
    list_t *ipv4_address_ranges,
    list_t *ipv6_prefix_ranges
);

void bsf_info_free(bsf_info_t *bsf_info);

bsf_info_t *bsf_info_parseFromJSON(cJSON *bsf_infoJSON);

cJSON *bsf_info_convertToJSON(bsf_info_t *bsf_info);

#endif /* _bsf_info_H_ */

