#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transport_protocol.h"



transport_protocol_t *transport_protocol_create(
    ) {
    transport_protocol_t *transport_protocol_local_var = malloc(sizeof(transport_protocol_t));
    if (!transport_protocol_local_var) {
        return NULL;
    }

    return transport_protocol_local_var;
}


void transport_protocol_free(transport_protocol_t *transport_protocol) {
    if(NULL == transport_protocol){
        return ;
    }
    listEntry_t *listEntry;
    free(transport_protocol);
}

cJSON *transport_protocol_convertToJSON(transport_protocol_t *transport_protocol) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

transport_protocol_t *transport_protocol_parseFromJSON(cJSON *transport_protocolJSON){

    transport_protocol_t *transport_protocol_local_var = NULL;


    transport_protocol_local_var = transport_protocol_create (
        );

    return transport_protocol_local_var;
end:
    return NULL;

}
