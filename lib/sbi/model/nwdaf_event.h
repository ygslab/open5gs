/*
 * nwdaf_event.h
 *
 * Possible values are - SLICE_LOAD_LEVEL: Indicates that the event subscribed is load level information of Network Slice instance - NETWORK_PERFORMANCE: Indicates that the event subscribed is network performance information. - NF_LOAD: Indicates that the event subscribed is load level and status of one or several Network Functions. - SERVICE_EXPERIENCE: Indicates that the event subscribed is service experience. - UE_MOBILITY: Indicates that the event subscribed is UE mobility information. - UE_COMMUNICATION: Indicates that the event subscribed is UE communication information. - QOS_SUSTAINABILITY: Indicates that the event subscribed is QoS sustainability. - ABNORMAL_BEHAVIOUR: Indicates that the event subscribed is abnormal behaviour. - USER_DATA_CONGESTION: Indicates that the event subscribed is user data congestion information.
 */

#ifndef _nwdaf_event_H_
#define _nwdaf_event_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct nwdaf_event_t nwdaf_event_t;
typedef struct nwdaf_event_t {
} nwdaf_event_t;

nwdaf_event_t *nwdaf_event_create(
    );
void nwdaf_event_free(nwdaf_event_t *nwdaf_event);
nwdaf_event_t *nwdaf_event_parseFromJSON(cJSON *nwdaf_eventJSON);
cJSON *nwdaf_event_convertToJSON(nwdaf_event_t *nwdaf_event);
#endif /* _nwdaf_event_H_ */

