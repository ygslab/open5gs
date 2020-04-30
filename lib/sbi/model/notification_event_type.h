/*
 * notification_event_type.h
 *
 * 
 */

#ifndef _notification_event_type_H_
#define _notification_event_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct notification_event_type_t notification_event_type_t;




typedef struct notification_event_type_t {

} notification_event_type_t;

notification_event_type_t *notification_event_type_create(
);

void notification_event_type_free(notification_event_type_t *notification_event_type);

notification_event_type_t *notification_event_type_parseFromJSON(cJSON *notification_event_typeJSON);

cJSON *notification_event_type_convertToJSON(notification_event_type_t *notification_event_type);

#endif /* _notification_event_type_H_ */

