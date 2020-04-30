/*
 * network_slice_cond.h
 *
 * 
 */

#ifndef _network_slice_cond_H_
#define _network_slice_cond_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct network_slice_cond_t network_slice_cond_t;

#include "snssai.h"



typedef struct network_slice_cond_t {
    list_t *snssai_list; //nonprimitive container
    list_t *nsi_list; //primitive container

} network_slice_cond_t;

network_slice_cond_t *network_slice_cond_create(
    list_t *snssai_list,
    list_t *nsi_list
);

void network_slice_cond_free(network_slice_cond_t *network_slice_cond);

network_slice_cond_t *network_slice_cond_parseFromJSON(cJSON *network_slice_condJSON);

cJSON *network_slice_cond_convertToJSON(network_slice_cond_t *network_slice_cond);

#endif /* _network_slice_cond_H_ */

