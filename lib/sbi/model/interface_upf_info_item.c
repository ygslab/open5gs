#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "interface_upf_info_item.h"



interface_upf_info_item_t *interface_upf_info_item_create(
    up_interface_type_t *interface_type,
    list_t *ipv4_endpoint_addresses,
    list_t *ipv6_endpoint_addresses,
    char *endpoint_fqdn,
    char *network_instance
    ) {
    interface_upf_info_item_t *interface_upf_info_item_local_var = malloc(sizeof(interface_upf_info_item_t));
    if (!interface_upf_info_item_local_var) {
        return NULL;
    }
    interface_upf_info_item_local_var->interface_type = interface_type;
    interface_upf_info_item_local_var->ipv4_endpoint_addresses = ipv4_endpoint_addresses;
    interface_upf_info_item_local_var->ipv6_endpoint_addresses = ipv6_endpoint_addresses;
    interface_upf_info_item_local_var->endpoint_fqdn = endpoint_fqdn;
    interface_upf_info_item_local_var->network_instance = network_instance;

    return interface_upf_info_item_local_var;
}


void interface_upf_info_item_free(interface_upf_info_item_t *interface_upf_info_item) {
    if(NULL == interface_upf_info_item){
        return ;
    }
    listEntry_t *listEntry;
    up_interface_type_free(interface_upf_info_item->interface_type);
    list_ForEach(listEntry, interface_upf_info_item->ipv4_endpoint_addresses) {
        free(listEntry->data);
    }
    list_free(interface_upf_info_item->ipv4_endpoint_addresses);
    list_ForEach(listEntry, interface_upf_info_item->ipv6_endpoint_addresses) {
        ipv6_addr_free(listEntry->data);
    }
    list_free(interface_upf_info_item->ipv6_endpoint_addresses);
    free(interface_upf_info_item->endpoint_fqdn);
    free(interface_upf_info_item->network_instance);
    free(interface_upf_info_item);
}

cJSON *interface_upf_info_item_convertToJSON(interface_upf_info_item_t *interface_upf_info_item) {
    cJSON *item = cJSON_CreateObject();

    // interface_upf_info_item->interface_type
    if (!interface_upf_info_item->interface_type) {
        goto fail;
    }
    
    cJSON *interface_type_local_JSON = up_interface_type_convertToJSON(interface_upf_info_item->interface_type);
    if(interface_type_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "interfaceType", interface_type_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // interface_upf_info_item->ipv4_endpoint_addresses
    if(interface_upf_info_item->ipv4_endpoint_addresses) { 
    cJSON *ipv4_endpoint_addresses = cJSON_AddArrayToObject(item, "ipv4EndpointAddresses");
    if(ipv4_endpoint_addresses == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *ipv4_endpoint_addressesListEntry;
    list_ForEach(ipv4_endpoint_addressesListEntry, interface_upf_info_item->ipv4_endpoint_addresses) {
    if(cJSON_AddStringToObject(ipv4_endpoint_addresses, "", (char*)ipv4_endpoint_addressesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // interface_upf_info_item->ipv6_endpoint_addresses
    if(interface_upf_info_item->ipv6_endpoint_addresses) { 
    cJSON *ipv6_endpoint_addresses = cJSON_AddArrayToObject(item, "ipv6EndpointAddresses");
    if(ipv6_endpoint_addresses == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ipv6_endpoint_addressesListEntry;
    if (interface_upf_info_item->ipv6_endpoint_addresses) {
    list_ForEach(ipv6_endpoint_addressesListEntry, interface_upf_info_item->ipv6_endpoint_addresses) {
    cJSON *itemLocal = ipv6_addr_convertToJSON(ipv6_endpoint_addressesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ipv6_endpoint_addresses, itemLocal);
    }
    }
     } 


    // interface_upf_info_item->endpoint_fqdn
    if(interface_upf_info_item->endpoint_fqdn) { 
    if(cJSON_AddStringToObject(item, "endpointFqdn", interface_upf_info_item->endpoint_fqdn) == NULL) {
    goto fail; //String
    }
     } 


    // interface_upf_info_item->network_instance
    if(interface_upf_info_item->network_instance) { 
    if(cJSON_AddStringToObject(item, "networkInstance", interface_upf_info_item->network_instance) == NULL) {
    goto fail; //String
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

interface_upf_info_item_t *interface_upf_info_item_parseFromJSON(cJSON *interface_upf_info_itemJSON){

    interface_upf_info_item_t *interface_upf_info_item_local_var = NULL;

    // interface_upf_info_item->interface_type
    cJSON *interface_type = cJSON_GetObjectItemCaseSensitive(interface_upf_info_itemJSON, "interfaceType");
    if (!interface_type) {
        goto end;
    }

    up_interface_type_t *interface_type_local_nonprim = NULL;
    
    interface_type_local_nonprim = up_interface_type_parseFromJSON(interface_type); //nonprimitive

    // interface_upf_info_item->ipv4_endpoint_addresses
    cJSON *ipv4_endpoint_addresses = cJSON_GetObjectItemCaseSensitive(interface_upf_info_itemJSON, "ipv4EndpointAddresses");
    list_t *ipv4_endpoint_addressesList;
    if (ipv4_endpoint_addresses) { 
    cJSON *ipv4_endpoint_addresses_local;
    if(!cJSON_IsArray(ipv4_endpoint_addresses)) {
        goto end;//primitive container
    }
    ipv4_endpoint_addressesList = list_create();

    cJSON_ArrayForEach(ipv4_endpoint_addresses_local, ipv4_endpoint_addresses)
    {
        if(!cJSON_IsString(ipv4_endpoint_addresses_local))
        {
            goto end;
        }
        list_addElement(ipv4_endpoint_addressesList , strdup(ipv4_endpoint_addresses_local->valuestring));
    }
    }

    // interface_upf_info_item->ipv6_endpoint_addresses
    cJSON *ipv6_endpoint_addresses = cJSON_GetObjectItemCaseSensitive(interface_upf_info_itemJSON, "ipv6EndpointAddresses");
    list_t *ipv6_endpoint_addressesList;
    if (ipv6_endpoint_addresses) { 
    cJSON *ipv6_endpoint_addresses_local_nonprimitive;
    if(!cJSON_IsArray(ipv6_endpoint_addresses)){
        goto end; //nonprimitive container
    }

    ipv6_endpoint_addressesList = list_create();

    cJSON_ArrayForEach(ipv6_endpoint_addresses_local_nonprimitive,ipv6_endpoint_addresses )
    {
        if(!cJSON_IsObject(ipv6_endpoint_addresses_local_nonprimitive)){
            goto end;
        }
        ipv6_addr_t *ipv6_endpoint_addressesItem = ipv6_addr_parseFromJSON(ipv6_endpoint_addresses_local_nonprimitive);

        list_addElement(ipv6_endpoint_addressesList, ipv6_endpoint_addressesItem);
    }
    }

    // interface_upf_info_item->endpoint_fqdn
    cJSON *endpoint_fqdn = cJSON_GetObjectItemCaseSensitive(interface_upf_info_itemJSON, "endpointFqdn");
    if (endpoint_fqdn) { 
    if(!cJSON_IsString(endpoint_fqdn))
    {
    goto end; //String
    }
    }

    // interface_upf_info_item->network_instance
    cJSON *network_instance = cJSON_GetObjectItemCaseSensitive(interface_upf_info_itemJSON, "networkInstance");
    if (network_instance) { 
    if(!cJSON_IsString(network_instance))
    {
    goto end; //String
    }
    }


    interface_upf_info_item_local_var = interface_upf_info_item_create (
        interface_type_local_nonprim,
        ipv4_endpoint_addresses ? ipv4_endpoint_addressesList : NULL,
        ipv6_endpoint_addresses ? ipv6_endpoint_addressesList : NULL,
        endpoint_fqdn ? strdup(endpoint_fqdn->valuestring) : NULL,
        network_instance ? strdup(network_instance->valuestring) : NULL
        );

    return interface_upf_info_item_local_var;
end:
    return NULL;

}
