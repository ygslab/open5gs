/*
 * default_notification_subscription.h
 *
 * 
 */

#ifndef _default_notification_subscription_H_
#define _default_notification_subscription_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct default_notification_subscription_t default_notification_subscription_t;

#include "n1_message_class.h"
#include "n2_information_class.h"
#include "notification_type.h"



typedef struct default_notification_subscription_t {
    struct notification_type_t *notification_type; //model
    char *callback_uri; // string
    struct n1_message_class_t *n1_message_class; //model
    struct n2_information_class_t *n2_information_class; //model

} default_notification_subscription_t;

default_notification_subscription_t *default_notification_subscription_create(
    notification_type_t *notification_type,
    char *callback_uri,
    n1_message_class_t *n1_message_class,
    n2_information_class_t *n2_information_class
);

void default_notification_subscription_free(default_notification_subscription_t *default_notification_subscription);

default_notification_subscription_t *default_notification_subscription_parseFromJSON(cJSON *default_notification_subscriptionJSON);

cJSON *default_notification_subscription_convertToJSON(default_notification_subscription_t *default_notification_subscription);

#endif /* _default_notification_subscription_H_ */

