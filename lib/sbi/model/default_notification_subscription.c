#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "default_notification_subscription.h"



default_notification_subscription_t *default_notification_subscription_create(
    notification_type_t *notification_type,
    char *callback_uri,
    n1_message_class_t *n1_message_class,
    n2_information_class_t *n2_information_class
    ) {
    default_notification_subscription_t *default_notification_subscription_local_var = malloc(sizeof(default_notification_subscription_t));
    if (!default_notification_subscription_local_var) {
        return NULL;
    }
    default_notification_subscription_local_var->notification_type = notification_type;
    default_notification_subscription_local_var->callback_uri = callback_uri;
    default_notification_subscription_local_var->n1_message_class = n1_message_class;
    default_notification_subscription_local_var->n2_information_class = n2_information_class;

    return default_notification_subscription_local_var;
}


void default_notification_subscription_free(default_notification_subscription_t *default_notification_subscription) {
    if(NULL == default_notification_subscription){
        return ;
    }
    listEntry_t *listEntry;
    notification_type_free(default_notification_subscription->notification_type);
    free(default_notification_subscription->callback_uri);
    n1_message_class_free(default_notification_subscription->n1_message_class);
    n2_information_class_free(default_notification_subscription->n2_information_class);
    free(default_notification_subscription);
}

cJSON *default_notification_subscription_convertToJSON(default_notification_subscription_t *default_notification_subscription) {
    cJSON *item = cJSON_CreateObject();

    // default_notification_subscription->notification_type
    if (!default_notification_subscription->notification_type) {
        goto fail;
    }
    
    cJSON *notification_type_local_JSON = notification_type_convertToJSON(default_notification_subscription->notification_type);
    if(notification_type_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "notificationType", notification_type_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // default_notification_subscription->callback_uri
    if (!default_notification_subscription->callback_uri) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "callbackUri", default_notification_subscription->callback_uri) == NULL) {
    goto fail; //String
    }


    // default_notification_subscription->n1_message_class
    if(default_notification_subscription->n1_message_class) { 
    cJSON *n1_message_class_local_JSON = n1_message_class_convertToJSON(default_notification_subscription->n1_message_class);
    if(n1_message_class_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "n1MessageClass", n1_message_class_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // default_notification_subscription->n2_information_class
    if(default_notification_subscription->n2_information_class) { 
    cJSON *n2_information_class_local_JSON = n2_information_class_convertToJSON(default_notification_subscription->n2_information_class);
    if(n2_information_class_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "n2InformationClass", n2_information_class_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

default_notification_subscription_t *default_notification_subscription_parseFromJSON(cJSON *default_notification_subscriptionJSON){

    default_notification_subscription_t *default_notification_subscription_local_var = NULL;

    // default_notification_subscription->notification_type
    cJSON *notification_type = cJSON_GetObjectItemCaseSensitive(default_notification_subscriptionJSON, "notificationType");
    if (!notification_type) {
        goto end;
    }

    notification_type_t *notification_type_local_nonprim = NULL;
    
    notification_type_local_nonprim = notification_type_parseFromJSON(notification_type); //nonprimitive

    // default_notification_subscription->callback_uri
    cJSON *callback_uri = cJSON_GetObjectItemCaseSensitive(default_notification_subscriptionJSON, "callbackUri");
    if (!callback_uri) {
        goto end;
    }

    
    if(!cJSON_IsString(callback_uri))
    {
    goto end; //String
    }

    // default_notification_subscription->n1_message_class
    cJSON *n1_message_class = cJSON_GetObjectItemCaseSensitive(default_notification_subscriptionJSON, "n1MessageClass");
    n1_message_class_t *n1_message_class_local_nonprim = NULL;
    if (n1_message_class) { 
    n1_message_class_local_nonprim = n1_message_class_parseFromJSON(n1_message_class); //nonprimitive
    }

    // default_notification_subscription->n2_information_class
    cJSON *n2_information_class = cJSON_GetObjectItemCaseSensitive(default_notification_subscriptionJSON, "n2InformationClass");
    n2_information_class_t *n2_information_class_local_nonprim = NULL;
    if (n2_information_class) { 
    n2_information_class_local_nonprim = n2_information_class_parseFromJSON(n2_information_class); //nonprimitive
    }


    default_notification_subscription_local_var = default_notification_subscription_create (
        notification_type_local_nonprim,
        strdup(callback_uri->valuestring),
        n1_message_class ? n1_message_class_local_nonprim : NULL,
        n2_information_class ? n2_information_class_local_nonprim : NULL
        );

    return default_notification_subscription_local_var;
end:
    return NULL;

}
