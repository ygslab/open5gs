#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "n2_interface_amf_info.h"



n2_interface_amf_info_t *n2_interface_amf_info_create(
    list_t *ipv4_endpoint_address,
    list_t *ipv6_endpoint_address,
    char *amf_name
    ) {
    n2_interface_amf_info_t *n2_interface_amf_info_local_var = malloc(sizeof(n2_interface_amf_info_t));
    if (!n2_interface_amf_info_local_var) {
        return NULL;
    }
    n2_interface_amf_info_local_var->ipv4_endpoint_address = ipv4_endpoint_address;
    n2_interface_amf_info_local_var->ipv6_endpoint_address = ipv6_endpoint_address;
    n2_interface_amf_info_local_var->amf_name = amf_name;

    return n2_interface_amf_info_local_var;
}


void n2_interface_amf_info_free(n2_interface_amf_info_t *n2_interface_amf_info) {
    if(NULL == n2_interface_amf_info){
        return ;
    }
    listEntry_t *listEntry;
    list_ForEach(listEntry, n2_interface_amf_info->ipv4_endpoint_address) {
        free(listEntry->data);
    }
    list_free(n2_interface_amf_info->ipv4_endpoint_address);
    list_ForEach(listEntry, n2_interface_amf_info->ipv6_endpoint_address) {
        ipv6_addr_free(listEntry->data);
    }
    list_free(n2_interface_amf_info->ipv6_endpoint_address);
    free(n2_interface_amf_info->amf_name);
    free(n2_interface_amf_info);
}

cJSON *n2_interface_amf_info_convertToJSON(n2_interface_amf_info_t *n2_interface_amf_info) {
    cJSON *item = cJSON_CreateObject();

    // n2_interface_amf_info->ipv4_endpoint_address
    if(n2_interface_amf_info->ipv4_endpoint_address) { 
    cJSON *ipv4_endpoint_address = cJSON_AddArrayToObject(item, "ipv4EndpointAddress");
    if(ipv4_endpoint_address == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *ipv4_endpoint_addressListEntry;
    list_ForEach(ipv4_endpoint_addressListEntry, n2_interface_amf_info->ipv4_endpoint_address) {
    if(cJSON_AddStringToObject(ipv4_endpoint_address, "", (char*)ipv4_endpoint_addressListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // n2_interface_amf_info->ipv6_endpoint_address
    if(n2_interface_amf_info->ipv6_endpoint_address) { 
    cJSON *ipv6_endpoint_address = cJSON_AddArrayToObject(item, "ipv6EndpointAddress");
    if(ipv6_endpoint_address == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ipv6_endpoint_addressListEntry;
    if (n2_interface_amf_info->ipv6_endpoint_address) {
    list_ForEach(ipv6_endpoint_addressListEntry, n2_interface_amf_info->ipv6_endpoint_address) {
    cJSON *itemLocal = ipv6_addr_convertToJSON(ipv6_endpoint_addressListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ipv6_endpoint_address, itemLocal);
    }
    }
     } 


    // n2_interface_amf_info->amf_name
    if(n2_interface_amf_info->amf_name) { 
    if(cJSON_AddStringToObject(item, "amfName", n2_interface_amf_info->amf_name) == NULL) {
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

n2_interface_amf_info_t *n2_interface_amf_info_parseFromJSON(cJSON *n2_interface_amf_infoJSON){

    n2_interface_amf_info_t *n2_interface_amf_info_local_var = NULL;

    // n2_interface_amf_info->ipv4_endpoint_address
    cJSON *ipv4_endpoint_address = cJSON_GetObjectItemCaseSensitive(n2_interface_amf_infoJSON, "ipv4EndpointAddress");
    list_t *ipv4_endpoint_addressList;
    if (ipv4_endpoint_address) { 
    cJSON *ipv4_endpoint_address_local;
    if(!cJSON_IsArray(ipv4_endpoint_address)) {
        goto end;//primitive container
    }
    ipv4_endpoint_addressList = list_create();

    cJSON_ArrayForEach(ipv4_endpoint_address_local, ipv4_endpoint_address)
    {
        if(!cJSON_IsString(ipv4_endpoint_address_local))
        {
            goto end;
        }
        list_addElement(ipv4_endpoint_addressList , strdup(ipv4_endpoint_address_local->valuestring));
    }
    }

    // n2_interface_amf_info->ipv6_endpoint_address
    cJSON *ipv6_endpoint_address = cJSON_GetObjectItemCaseSensitive(n2_interface_amf_infoJSON, "ipv6EndpointAddress");
    list_t *ipv6_endpoint_addressList;
    if (ipv6_endpoint_address) { 
    cJSON *ipv6_endpoint_address_local_nonprimitive;
    if(!cJSON_IsArray(ipv6_endpoint_address)){
        goto end; //nonprimitive container
    }

    ipv6_endpoint_addressList = list_create();

    cJSON_ArrayForEach(ipv6_endpoint_address_local_nonprimitive,ipv6_endpoint_address )
    {
        if(!cJSON_IsObject(ipv6_endpoint_address_local_nonprimitive)){
            goto end;
        }
        ipv6_addr_t *ipv6_endpoint_addressItem = ipv6_addr_parseFromJSON(ipv6_endpoint_address_local_nonprimitive);

        list_addElement(ipv6_endpoint_addressList, ipv6_endpoint_addressItem);
    }
    }

    // n2_interface_amf_info->amf_name
    cJSON *amf_name = cJSON_GetObjectItemCaseSensitive(n2_interface_amf_infoJSON, "amfName");
    if (amf_name) { 
    if(!cJSON_IsString(amf_name))
    {
    goto end; //String
    }
    }


    n2_interface_amf_info_local_var = n2_interface_amf_info_create (
        ipv4_endpoint_address ? ipv4_endpoint_addressList : NULL,
        ipv6_endpoint_address ? ipv6_endpoint_addressList : NULL,
        amf_name ? strdup(amf_name->valuestring) : NULL
        );

    return n2_interface_amf_info_local_var;
end:
    return NULL;

}
