/*
 * nwdaf_info.h
 *
 * 
 */

#ifndef _nwdaf_info_H_
#define _nwdaf_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct nwdaf_info_t nwdaf_info_t;

#include "event_id.h"
#include "nwdaf_event.h"
#include "tai.h"
#include "tai_range.h"



typedef struct nwdaf_info_t {
    list_t *event_ids; //nonprimitive container
    list_t *nwdaf_events; //nonprimitive container
    list_t *tai_list; //nonprimitive container
    list_t *tai_range_list; //nonprimitive container

} nwdaf_info_t;

nwdaf_info_t *nwdaf_info_create(
    list_t *event_ids,
    list_t *nwdaf_events,
    list_t *tai_list,
    list_t *tai_range_list
);

void nwdaf_info_free(nwdaf_info_t *nwdaf_info);

nwdaf_info_t *nwdaf_info_parseFromJSON(cJSON *nwdaf_infoJSON);

cJSON *nwdaf_info_convertToJSON(nwdaf_info_t *nwdaf_info);

#endif /* _nwdaf_info_H_ */

