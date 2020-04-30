#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "notification_event_type.h"



notification_event_type_t *notification_event_type_create(
    ) {
    notification_event_type_t *notification_event_type_local_var = malloc(sizeof(notification_event_type_t));
    if (!notification_event_type_local_var) {
        return NULL;
    }

    return notification_event_type_local_var;
}


void notification_event_type_free(notification_event_type_t *notification_event_type) {
    if(NULL == notification_event_type){
        return ;
    }
    listEntry_t *listEntry;
    free(notification_event_type);
}

cJSON *notification_event_type_convertToJSON(notification_event_type_t *notification_event_type) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

notification_event_type_t *notification_event_type_parseFromJSON(cJSON *notification_event_typeJSON){

    notification_event_type_t *notification_event_type_local_var = NULL;


    notification_event_type_local_var = notification_event_type_create (
        );

    return notification_event_type_local_var;
end:
    return NULL;

}
