/*
 * pcf_info.h
 *
 * 
 */

#ifndef _pcf_info_H_
#define _pcf_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pcf_info_t pcf_info_t;

#include "identity_range.h"
#include "supi_range.h"



typedef struct pcf_info_t {
    char *group_id; // string
    list_t *dnn_list; //primitive container
    list_t *supi_ranges; //nonprimitive container
    list_t *gpsi_ranges; //nonprimitive container
    char *rx_diam_host; // string
    char *rx_diam_realm; // string

} pcf_info_t;

pcf_info_t *pcf_info_create(
    char *group_id,
    list_t *dnn_list,
    list_t *supi_ranges,
    list_t *gpsi_ranges,
    char *rx_diam_host,
    char *rx_diam_realm
);

void pcf_info_free(pcf_info_t *pcf_info);

pcf_info_t *pcf_info_parseFromJSON(cJSON *pcf_infoJSON);

cJSON *pcf_info_convertToJSON(pcf_info_t *pcf_info);

#endif /* _pcf_info_H_ */

