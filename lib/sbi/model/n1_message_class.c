
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "n1_message_class.h"

n1_message_class_t *n1_message_class_create(
    )
{
    n1_message_class_t *n1_message_class_local_var = ogs_malloc(sizeof(n1_message_class_t));
    if (!n1_message_class_local_var) {
        return NULL;
    }

    return n1_message_class_local_var;
}

void n1_message_class_free(n1_message_class_t *n1_message_class)
{
    if(NULL == n1_message_class) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(n1_message_class);
}

cJSON *n1_message_class_convertToJSON(n1_message_class_t *n1_message_class)
{
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

n1_message_class_t *n1_message_class_parseFromJSON(cJSON *n1_message_classJSON)
{
    n1_message_class_t *n1_message_class_local_var = NULL;
    n1_message_class_local_var = n1_message_class_create (
        );

    return n1_message_class_local_var;
end:
    return NULL;
}

