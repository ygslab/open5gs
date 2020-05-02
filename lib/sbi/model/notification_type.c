
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "notification_type.h"

notification_type_t *notification_type_create(
    )
{
    notification_type_t *notification_type_local_var = ogs_malloc(sizeof(notification_type_t));
    if (!notification_type_local_var) {
        return NULL;
    }

    return notification_type_local_var;
}

void notification_type_free(notification_type_t *notification_type)
{
    if(NULL == notification_type) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(notification_type);
}

cJSON *notification_type_convertToJSON(notification_type_t *notification_type)
{
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

notification_type_t *notification_type_parseFromJSON(cJSON *notification_typeJSON)
{
    notification_type_t *notification_type_local_var = NULL;
    notification_type_local_var = notification_type_create (
        );

    return notification_type_local_var;
end:
    return NULL;
}

