
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "n2_information_class.h"

n2_information_class_t *n2_information_class_create(
    )
{
    n2_information_class_t *n2_information_class_local_var = ogs_malloc(sizeof(n2_information_class_t));
    if (!n2_information_class_local_var) {
        return NULL;
    }

    return n2_information_class_local_var;
}

void n2_information_class_free(n2_information_class_t *n2_information_class)
{
    if(NULL == n2_information_class) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(n2_information_class);
}

cJSON *n2_information_class_convertToJSON(n2_information_class_t *n2_information_class)
{
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

n2_information_class_t *n2_information_class_parseFromJSON(cJSON *n2_information_classJSON)
{
    n2_information_class_t *n2_information_class_local_var = NULL;
    n2_information_class_local_var = n2_information_class_create (
        );

    return n2_information_class_local_var;
end:
    return NULL;
}

