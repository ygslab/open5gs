/*
 * notification_data.h
 *
 * 
 */

#ifndef _notification_data_H_
#define _notification_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct notification_data_t notification_data_t;

#include "change_item.h"
#include "nf_profile.h"
#include "notification_event_type.h"



typedef struct notification_data_t {
    struct notification_event_type_t *event; //model
    char *nf_instance_uri; // string
    struct nf_profile_t *nf_profile; //model
    list_t *profile_changes; //nonprimitive container

} notification_data_t;

notification_data_t *notification_data_create(
    notification_event_type_t *event,
    char *nf_instance_uri,
    nf_profile_t *nf_profile,
    list_t *profile_changes
);

void notification_data_free(notification_data_t *notification_data);

notification_data_t *notification_data_parseFromJSON(cJSON *notification_dataJSON);

cJSON *notification_data_convertToJSON(notification_data_t *notification_data);

#endif /* _notification_data_H_ */

