#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "up_interface_type.h"



up_interface_type_t *up_interface_type_create(
    ) {
    up_interface_type_t *up_interface_type_local_var = malloc(sizeof(up_interface_type_t));
    if (!up_interface_type_local_var) {
        return NULL;
    }

    return up_interface_type_local_var;
}


void up_interface_type_free(up_interface_type_t *up_interface_type) {
    if(NULL == up_interface_type){
        return ;
    }
    listEntry_t *listEntry;
    free(up_interface_type);
}

cJSON *up_interface_type_convertToJSON(up_interface_type_t *up_interface_type) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

up_interface_type_t *up_interface_type_parseFromJSON(cJSON *up_interface_typeJSON){

    up_interface_type_t *up_interface_type_local_var = NULL;


    up_interface_type_local_var = up_interface_type_create (
        );

    return up_interface_type_local_var;
end:
    return NULL;

}
