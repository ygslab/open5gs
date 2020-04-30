#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bsf_info.h"



bsf_info_t *bsf_info_create(
    list_t *dnn_list,
    list_t *ip_domain_list,
    list_t *ipv4_address_ranges,
    list_t *ipv6_prefix_ranges
    ) {
    bsf_info_t *bsf_info_local_var = malloc(sizeof(bsf_info_t));
    if (!bsf_info_local_var) {
        return NULL;
    }
    bsf_info_local_var->dnn_list = dnn_list;
    bsf_info_local_var->ip_domain_list = ip_domain_list;
    bsf_info_local_var->ipv4_address_ranges = ipv4_address_ranges;
    bsf_info_local_var->ipv6_prefix_ranges = ipv6_prefix_ranges;

    return bsf_info_local_var;
}


void bsf_info_free(bsf_info_t *bsf_info) {
    if(NULL == bsf_info){
        return ;
    }
    listEntry_t *listEntry;
    list_ForEach(listEntry, bsf_info->dnn_list) {
        free(listEntry->data);
    }
    list_free(bsf_info->dnn_list);
    list_ForEach(listEntry, bsf_info->ip_domain_list) {
        free(listEntry->data);
    }
    list_free(bsf_info->ip_domain_list);
    list_ForEach(listEntry, bsf_info->ipv4_address_ranges) {
        ipv4_address_range_free(listEntry->data);
    }
    list_free(bsf_info->ipv4_address_ranges);
    list_ForEach(listEntry, bsf_info->ipv6_prefix_ranges) {
        ipv6_prefix_range_free(listEntry->data);
    }
    list_free(bsf_info->ipv6_prefix_ranges);
    free(bsf_info);
}

cJSON *bsf_info_convertToJSON(bsf_info_t *bsf_info) {
    cJSON *item = cJSON_CreateObject();

    // bsf_info->dnn_list
    if(bsf_info->dnn_list) { 
    cJSON *dnn_list = cJSON_AddArrayToObject(item, "dnnList");
    if(dnn_list == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *dnn_listListEntry;
    list_ForEach(dnn_listListEntry, bsf_info->dnn_list) {
    if(cJSON_AddStringToObject(dnn_list, "", (char*)dnn_listListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // bsf_info->ip_domain_list
    if(bsf_info->ip_domain_list) { 
    cJSON *ip_domain_list = cJSON_AddArrayToObject(item, "ipDomainList");
    if(ip_domain_list == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *ip_domain_listListEntry;
    list_ForEach(ip_domain_listListEntry, bsf_info->ip_domain_list) {
    if(cJSON_AddStringToObject(ip_domain_list, "", (char*)ip_domain_listListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // bsf_info->ipv4_address_ranges
    if(bsf_info->ipv4_address_ranges) { 
    cJSON *ipv4_address_ranges = cJSON_AddArrayToObject(item, "ipv4AddressRanges");
    if(ipv4_address_ranges == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ipv4_address_rangesListEntry;
    if (bsf_info->ipv4_address_ranges) {
    list_ForEach(ipv4_address_rangesListEntry, bsf_info->ipv4_address_ranges) {
    cJSON *itemLocal = ipv4_address_range_convertToJSON(ipv4_address_rangesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ipv4_address_ranges, itemLocal);
    }
    }
     } 


    // bsf_info->ipv6_prefix_ranges
    if(bsf_info->ipv6_prefix_ranges) { 
    cJSON *ipv6_prefix_ranges = cJSON_AddArrayToObject(item, "ipv6PrefixRanges");
    if(ipv6_prefix_ranges == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ipv6_prefix_rangesListEntry;
    if (bsf_info->ipv6_prefix_ranges) {
    list_ForEach(ipv6_prefix_rangesListEntry, bsf_info->ipv6_prefix_ranges) {
    cJSON *itemLocal = ipv6_prefix_range_convertToJSON(ipv6_prefix_rangesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ipv6_prefix_ranges, itemLocal);
    }
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

bsf_info_t *bsf_info_parseFromJSON(cJSON *bsf_infoJSON){

    bsf_info_t *bsf_info_local_var = NULL;

    // bsf_info->dnn_list
    cJSON *dnn_list = cJSON_GetObjectItemCaseSensitive(bsf_infoJSON, "dnnList");
    list_t *dnn_listList;
    if (dnn_list) { 
    cJSON *dnn_list_local;
    if(!cJSON_IsArray(dnn_list)) {
        goto end;//primitive container
    }
    dnn_listList = list_create();

    cJSON_ArrayForEach(dnn_list_local, dnn_list)
    {
        if(!cJSON_IsString(dnn_list_local))
        {
            goto end;
        }
        list_addElement(dnn_listList , strdup(dnn_list_local->valuestring));
    }
    }

    // bsf_info->ip_domain_list
    cJSON *ip_domain_list = cJSON_GetObjectItemCaseSensitive(bsf_infoJSON, "ipDomainList");
    list_t *ip_domain_listList;
    if (ip_domain_list) { 
    cJSON *ip_domain_list_local;
    if(!cJSON_IsArray(ip_domain_list)) {
        goto end;//primitive container
    }
    ip_domain_listList = list_create();

    cJSON_ArrayForEach(ip_domain_list_local, ip_domain_list)
    {
        if(!cJSON_IsString(ip_domain_list_local))
        {
            goto end;
        }
        list_addElement(ip_domain_listList , strdup(ip_domain_list_local->valuestring));
    }
    }

    // bsf_info->ipv4_address_ranges
    cJSON *ipv4_address_ranges = cJSON_GetObjectItemCaseSensitive(bsf_infoJSON, "ipv4AddressRanges");
    list_t *ipv4_address_rangesList;
    if (ipv4_address_ranges) { 
    cJSON *ipv4_address_ranges_local_nonprimitive;
    if(!cJSON_IsArray(ipv4_address_ranges)){
        goto end; //nonprimitive container
    }

    ipv4_address_rangesList = list_create();

    cJSON_ArrayForEach(ipv4_address_ranges_local_nonprimitive,ipv4_address_ranges )
    {
        if(!cJSON_IsObject(ipv4_address_ranges_local_nonprimitive)){
            goto end;
        }
        ipv4_address_range_t *ipv4_address_rangesItem = ipv4_address_range_parseFromJSON(ipv4_address_ranges_local_nonprimitive);

        list_addElement(ipv4_address_rangesList, ipv4_address_rangesItem);
    }
    }

    // bsf_info->ipv6_prefix_ranges
    cJSON *ipv6_prefix_ranges = cJSON_GetObjectItemCaseSensitive(bsf_infoJSON, "ipv6PrefixRanges");
    list_t *ipv6_prefix_rangesList;
    if (ipv6_prefix_ranges) { 
    cJSON *ipv6_prefix_ranges_local_nonprimitive;
    if(!cJSON_IsArray(ipv6_prefix_ranges)){
        goto end; //nonprimitive container
    }

    ipv6_prefix_rangesList = list_create();

    cJSON_ArrayForEach(ipv6_prefix_ranges_local_nonprimitive,ipv6_prefix_ranges )
    {
        if(!cJSON_IsObject(ipv6_prefix_ranges_local_nonprimitive)){
            goto end;
        }
        ipv6_prefix_range_t *ipv6_prefix_rangesItem = ipv6_prefix_range_parseFromJSON(ipv6_prefix_ranges_local_nonprimitive);

        list_addElement(ipv6_prefix_rangesList, ipv6_prefix_rangesItem);
    }
    }


    bsf_info_local_var = bsf_info_create (
        dnn_list ? dnn_listList : NULL,
        ip_domain_list ? ip_domain_listList : NULL,
        ipv4_address_ranges ? ipv4_address_rangesList : NULL,
        ipv6_prefix_ranges ? ipv6_prefix_rangesList : NULL
        );

    return bsf_info_local_var;
end:
    return NULL;

}
