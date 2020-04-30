#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ip_end_point.h"



ip_end_point_t *ip_end_point_create(
    char *ipv4_address,
    ipv6_addr_t *ipv6_address,
    transport_protocol_t *transport,
    int port
    ) {
    ip_end_point_t *ip_end_point_local_var = malloc(sizeof(ip_end_point_t));
    if (!ip_end_point_local_var) {
        return NULL;
    }
    ip_end_point_local_var->ipv4_address = ipv4_address;
    ip_end_point_local_var->ipv6_address = ipv6_address;
    ip_end_point_local_var->transport = transport;
    ip_end_point_local_var->port = port;

    return ip_end_point_local_var;
}


void ip_end_point_free(ip_end_point_t *ip_end_point) {
    if(NULL == ip_end_point){
        return ;
    }
    listEntry_t *listEntry;
    free(ip_end_point->ipv4_address);
    ipv6_addr_free(ip_end_point->ipv6_address);
    transport_protocol_free(ip_end_point->transport);
    free(ip_end_point);
}

cJSON *ip_end_point_convertToJSON(ip_end_point_t *ip_end_point) {
    cJSON *item = cJSON_CreateObject();

    // ip_end_point->ipv4_address
    if(ip_end_point->ipv4_address) { 
    if(cJSON_AddStringToObject(item, "ipv4Address", ip_end_point->ipv4_address) == NULL) {
    goto fail; //String
    }
     } 


    // ip_end_point->ipv6_address
    if(ip_end_point->ipv6_address) { 
    cJSON *ipv6_address_local_JSON = ipv6_addr_convertToJSON(ip_end_point->ipv6_address);
    if(ipv6_address_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ipv6Address", ipv6_address_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // ip_end_point->transport
    if(ip_end_point->transport) { 
    cJSON *transport_local_JSON = transport_protocol_convertToJSON(ip_end_point->transport);
    if(transport_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "transport", transport_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // ip_end_point->port
    if(ip_end_point->port) { 
    if(cJSON_AddNumberToObject(item, "port", ip_end_point->port) == NULL) {
    goto fail; //Numeric
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ip_end_point_t *ip_end_point_parseFromJSON(cJSON *ip_end_pointJSON){

    ip_end_point_t *ip_end_point_local_var = NULL;

    // ip_end_point->ipv4_address
    cJSON *ipv4_address = cJSON_GetObjectItemCaseSensitive(ip_end_pointJSON, "ipv4Address");
    if (ipv4_address) { 
    if(!cJSON_IsString(ipv4_address))
    {
    goto end; //String
    }
    }

    // ip_end_point->ipv6_address
    cJSON *ipv6_address = cJSON_GetObjectItemCaseSensitive(ip_end_pointJSON, "ipv6Address");
    ipv6_addr_t *ipv6_address_local_nonprim = NULL;
    if (ipv6_address) { 
    ipv6_address_local_nonprim = ipv6_addr_parseFromJSON(ipv6_address); //nonprimitive
    }

    // ip_end_point->transport
    cJSON *transport = cJSON_GetObjectItemCaseSensitive(ip_end_pointJSON, "transport");
    transport_protocol_t *transport_local_nonprim = NULL;
    if (transport) { 
    transport_local_nonprim = transport_protocol_parseFromJSON(transport); //nonprimitive
    }

    // ip_end_point->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(ip_end_pointJSON, "port");
    if (port) { 
    if(!cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }
    }


    ip_end_point_local_var = ip_end_point_create (
        ipv4_address ? strdup(ipv4_address->valuestring) : NULL,
        ipv6_address ? ipv6_address_local_nonprim : NULL,
        transport ? transport_local_nonprim : NULL,
        port ? port->valuedouble : 0
        );

    return ip_end_point_local_var;
end:
    return NULL;

}
