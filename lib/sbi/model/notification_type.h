/*
 * notification_type.h
 *
 * 
 */

#ifndef _notification_type_H_
#define _notification_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct notification_type_t notification_type_t;




typedef struct notification_type_t {

} notification_type_t;

notification_type_t *notification_type_create(
);

void notification_type_free(notification_type_t *notification_type);

notification_type_t *notification_type_parseFromJSON(cJSON *notification_typeJSON);

cJSON *notification_type_convertToJSON(notification_type_t *notification_type);

#endif /* _notification_type_H_ */

