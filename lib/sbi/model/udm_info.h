/*
 * udm_info.h
 *
 * 
 */

#ifndef _udm_info_H_
#define _udm_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct udm_info_t udm_info_t;

#include "identity_range.h"
#include "supi_range.h"



typedef struct udm_info_t {
    char *group_id; // string
    list_t *supi_ranges; //nonprimitive container
    list_t *gpsi_ranges; //nonprimitive container
    list_t *external_group_identifiers_ranges; //nonprimitive container
    list_t *routing_indicators; //primitive container

} udm_info_t;

udm_info_t *udm_info_create(
    char *group_id,
    list_t *supi_ranges,
    list_t *gpsi_ranges,
    list_t *external_group_identifiers_ranges,
    list_t *routing_indicators
);

void udm_info_free(udm_info_t *udm_info);

udm_info_t *udm_info_parseFromJSON(cJSON *udm_infoJSON);

cJSON *udm_info_convertToJSON(udm_info_t *udm_info);

#endif /* _udm_info_H_ */

