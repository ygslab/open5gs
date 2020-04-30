/*
 * notif_condition.h
 *
 * 
 */

#ifndef _notif_condition_H_
#define _notif_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct notif_condition_t notif_condition_t;




typedef struct notif_condition_t {
    list_t *monitored_attributes; //primitive container
    list_t *unmonitored_attributes; //primitive container

} notif_condition_t;

notif_condition_t *notif_condition_create(
    list_t *monitored_attributes,
    list_t *unmonitored_attributes
);

void notif_condition_free(notif_condition_t *notif_condition);

notif_condition_t *notif_condition_parseFromJSON(cJSON *notif_conditionJSON);

cJSON *notif_condition_convertToJSON(notif_condition_t *notif_condition);

#endif /* _notif_condition_H_ */

