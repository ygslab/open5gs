#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nf_service.h"



nf_service_t *nf_service_create(
    char *service_instance_id,
    service_name_t *service_name,
    list_t *versions,
    uri_scheme_t *scheme,
    nf_service_status_t *nf_service_status,
    char *fqdn,
    char *inter_plmn_fqdn,
    list_t *ip_end_points,
    char *api_prefix,
    list_t *default_notification_subscriptions,
    list_t *allowed_plmns,
    list_t *allowed_nf_types,
    list_t *allowed_nf_domains,
    list_t *allowed_nssais,
    int priority,
    int capacity,
    int load,
    char *recovery_time,
    chf_service_info_t *chf_service_info,
    char *supported_features
    ) {
    nf_service_t *nf_service_local_var = malloc(sizeof(nf_service_t));
    if (!nf_service_local_var) {
        return NULL;
    }
    nf_service_local_var->service_instance_id = service_instance_id;
    nf_service_local_var->service_name = service_name;
    nf_service_local_var->versions = versions;
    nf_service_local_var->scheme = scheme;
    nf_service_local_var->nf_service_status = nf_service_status;
    nf_service_local_var->fqdn = fqdn;
    nf_service_local_var->inter_plmn_fqdn = inter_plmn_fqdn;
    nf_service_local_var->ip_end_points = ip_end_points;
    nf_service_local_var->api_prefix = api_prefix;
    nf_service_local_var->default_notification_subscriptions = default_notification_subscriptions;
    nf_service_local_var->allowed_plmns = allowed_plmns;
    nf_service_local_var->allowed_nf_types = allowed_nf_types;
    nf_service_local_var->allowed_nf_domains = allowed_nf_domains;
    nf_service_local_var->allowed_nssais = allowed_nssais;
    nf_service_local_var->priority = priority;
    nf_service_local_var->capacity = capacity;
    nf_service_local_var->load = load;
    nf_service_local_var->recovery_time = recovery_time;
    nf_service_local_var->chf_service_info = chf_service_info;
    nf_service_local_var->supported_features = supported_features;

    return nf_service_local_var;
}


void nf_service_free(nf_service_t *nf_service) {
    if(NULL == nf_service){
        return ;
    }
    listEntry_t *listEntry;
    free(nf_service->service_instance_id);
    service_name_free(nf_service->service_name);
    list_ForEach(listEntry, nf_service->versions) {
        nf_service_version_free(listEntry->data);
    }
    list_free(nf_service->versions);
    uri_scheme_free(nf_service->scheme);
    nf_service_status_free(nf_service->nf_service_status);
    free(nf_service->fqdn);
    free(nf_service->inter_plmn_fqdn);
    list_ForEach(listEntry, nf_service->ip_end_points) {
        ip_end_point_free(listEntry->data);
    }
    list_free(nf_service->ip_end_points);
    free(nf_service->api_prefix);
    list_ForEach(listEntry, nf_service->default_notification_subscriptions) {
        default_notification_subscription_free(listEntry->data);
    }
    list_free(nf_service->default_notification_subscriptions);
    list_ForEach(listEntry, nf_service->allowed_plmns) {
        plmn_id_free(listEntry->data);
    }
    list_free(nf_service->allowed_plmns);
    list_ForEach(listEntry, nf_service->allowed_nf_types) {
        free(listEntry->data);
    }
    list_free(nf_service->allowed_nf_types);
    list_ForEach(listEntry, nf_service->allowed_nf_domains) {
        free(listEntry->data);
    }
    list_free(nf_service->allowed_nf_domains);
    list_ForEach(listEntry, nf_service->allowed_nssais) {
        snssai_free(listEntry->data);
    }
    list_free(nf_service->allowed_nssais);
    free(nf_service->recovery_time);
    chf_service_info_free(nf_service->chf_service_info);
    free(nf_service->supported_features);
    free(nf_service);
}

cJSON *nf_service_convertToJSON(nf_service_t *nf_service) {
    cJSON *item = cJSON_CreateObject();

    // nf_service->service_instance_id
    if (!nf_service->service_instance_id) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "serviceInstanceId", nf_service->service_instance_id) == NULL) {
    goto fail; //String
    }


    // nf_service->service_name
    if (!nf_service->service_name) {
        goto fail;
    }
    
    cJSON *service_name_local_JSON = service_name_convertToJSON(nf_service->service_name);
    if(service_name_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "serviceName", service_name_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // nf_service->versions
    if (!nf_service->versions) {
        goto fail;
    }
    
    cJSON *versions = cJSON_AddArrayToObject(item, "versions");
    if(versions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *versionsListEntry;
    if (nf_service->versions) {
    list_ForEach(versionsListEntry, nf_service->versions) {
    cJSON *itemLocal = nf_service_version_convertToJSON(versionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(versions, itemLocal);
    }
    }


    // nf_service->scheme
    if (!nf_service->scheme) {
        goto fail;
    }
    
    cJSON *scheme_local_JSON = uri_scheme_convertToJSON(nf_service->scheme);
    if(scheme_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scheme", scheme_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // nf_service->nf_service_status
    if (!nf_service->nf_service_status) {
        goto fail;
    }
    
    cJSON *nf_service_status_local_JSON = nf_service_status_convertToJSON(nf_service->nf_service_status);
    if(nf_service_status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nfServiceStatus", nf_service_status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // nf_service->fqdn
    if(nf_service->fqdn) { 
    if(cJSON_AddStringToObject(item, "fqdn", nf_service->fqdn) == NULL) {
    goto fail; //String
    }
     } 


    // nf_service->inter_plmn_fqdn
    if(nf_service->inter_plmn_fqdn) { 
    if(cJSON_AddStringToObject(item, "interPlmnFqdn", nf_service->inter_plmn_fqdn) == NULL) {
    goto fail; //String
    }
     } 


    // nf_service->ip_end_points
    if(nf_service->ip_end_points) { 
    cJSON *ip_end_points = cJSON_AddArrayToObject(item, "ipEndPoints");
    if(ip_end_points == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ip_end_pointsListEntry;
    if (nf_service->ip_end_points) {
    list_ForEach(ip_end_pointsListEntry, nf_service->ip_end_points) {
    cJSON *itemLocal = ip_end_point_convertToJSON(ip_end_pointsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ip_end_points, itemLocal);
    }
    }
     } 


    // nf_service->api_prefix
    if(nf_service->api_prefix) { 
    if(cJSON_AddStringToObject(item, "apiPrefix", nf_service->api_prefix) == NULL) {
    goto fail; //String
    }
     } 


    // nf_service->default_notification_subscriptions
    if(nf_service->default_notification_subscriptions) { 
    cJSON *default_notification_subscriptions = cJSON_AddArrayToObject(item, "defaultNotificationSubscriptions");
    if(default_notification_subscriptions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *default_notification_subscriptionsListEntry;
    if (nf_service->default_notification_subscriptions) {
    list_ForEach(default_notification_subscriptionsListEntry, nf_service->default_notification_subscriptions) {
    cJSON *itemLocal = default_notification_subscription_convertToJSON(default_notification_subscriptionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(default_notification_subscriptions, itemLocal);
    }
    }
     } 


    // nf_service->allowed_plmns
    if(nf_service->allowed_plmns) { 
    cJSON *allowed_plmns = cJSON_AddArrayToObject(item, "allowedPlmns");
    if(allowed_plmns == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *allowed_plmnsListEntry;
    if (nf_service->allowed_plmns) {
    list_ForEach(allowed_plmnsListEntry, nf_service->allowed_plmns) {
    cJSON *itemLocal = plmn_id_convertToJSON(allowed_plmnsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(allowed_plmns, itemLocal);
    }
    }
     } 


    // nf_service->allowed_nf_types
    if(nf_service->allowed_nf_types) { 
    cJSON *allowed_nf_types = cJSON_AddArrayToObject(item, "allowedNfTypes");
    if(allowed_nf_types == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *allowed_nf_typesListEntry;
    list_ForEach(allowed_nf_typesListEntry, nf_service->allowed_nf_types) {
    if(cJSON_AddStringToObject(allowed_nf_types, "", (char*)allowed_nf_typesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // nf_service->allowed_nf_domains
    if(nf_service->allowed_nf_domains) { 
    cJSON *allowed_nf_domains = cJSON_AddArrayToObject(item, "allowedNfDomains");
    if(allowed_nf_domains == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *allowed_nf_domainsListEntry;
    list_ForEach(allowed_nf_domainsListEntry, nf_service->allowed_nf_domains) {
    if(cJSON_AddStringToObject(allowed_nf_domains, "", (char*)allowed_nf_domainsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // nf_service->allowed_nssais
    if(nf_service->allowed_nssais) { 
    cJSON *allowed_nssais = cJSON_AddArrayToObject(item, "allowedNssais");
    if(allowed_nssais == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *allowed_nssaisListEntry;
    if (nf_service->allowed_nssais) {
    list_ForEach(allowed_nssaisListEntry, nf_service->allowed_nssais) {
    cJSON *itemLocal = snssai_convertToJSON(allowed_nssaisListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(allowed_nssais, itemLocal);
    }
    }
     } 


    // nf_service->priority
    if(nf_service->priority) { 
    if(cJSON_AddNumberToObject(item, "priority", nf_service->priority) == NULL) {
    goto fail; //Numeric
    }
     } 


    // nf_service->capacity
    if(nf_service->capacity) { 
    if(cJSON_AddNumberToObject(item, "capacity", nf_service->capacity) == NULL) {
    goto fail; //Numeric
    }
     } 


    // nf_service->load
    if(nf_service->load) { 
    if(cJSON_AddNumberToObject(item, "load", nf_service->load) == NULL) {
    goto fail; //Numeric
    }
     } 


    // nf_service->recovery_time
    if(nf_service->recovery_time) { 
    if(cJSON_AddStringToObject(item, "recoveryTime", nf_service->recovery_time) == NULL) {
    goto fail; //Date-Time
    }
     } 


    // nf_service->chf_service_info
    if(nf_service->chf_service_info) { 
    cJSON *chf_service_info_local_JSON = chf_service_info_convertToJSON(nf_service->chf_service_info);
    if(chf_service_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chfServiceInfo", chf_service_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // nf_service->supported_features
    if(nf_service->supported_features) { 
    if(cJSON_AddStringToObject(item, "supportedFeatures", nf_service->supported_features) == NULL) {
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

nf_service_t *nf_service_parseFromJSON(cJSON *nf_serviceJSON){

    nf_service_t *nf_service_local_var = NULL;

    // nf_service->service_instance_id
    cJSON *service_instance_id = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "serviceInstanceId");
    if (!service_instance_id) {
        goto end;
    }

    
    if(!cJSON_IsString(service_instance_id))
    {
    goto end; //String
    }

    // nf_service->service_name
    cJSON *service_name = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "serviceName");
    if (!service_name) {
        goto end;
    }

    service_name_t *service_name_local_nonprim = NULL;
    
    service_name_local_nonprim = service_name_parseFromJSON(service_name); //nonprimitive

    // nf_service->versions
    cJSON *versions = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "versions");
    if (!versions) {
        goto end;
    }

    list_t *versionsList;
    
    cJSON *versions_local_nonprimitive;
    if(!cJSON_IsArray(versions)){
        goto end; //nonprimitive container
    }

    versionsList = list_create();

    cJSON_ArrayForEach(versions_local_nonprimitive,versions )
    {
        if(!cJSON_IsObject(versions_local_nonprimitive)){
            goto end;
        }
        nf_service_version_t *versionsItem = nf_service_version_parseFromJSON(versions_local_nonprimitive);

        list_addElement(versionsList, versionsItem);
    }

    // nf_service->scheme
    cJSON *scheme = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "scheme");
    if (!scheme) {
        goto end;
    }

    uri_scheme_t *scheme_local_nonprim = NULL;
    
    scheme_local_nonprim = uri_scheme_parseFromJSON(scheme); //nonprimitive

    // nf_service->nf_service_status
    cJSON *nf_service_status = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "nfServiceStatus");
    if (!nf_service_status) {
        goto end;
    }

    nf_service_status_t *nf_service_status_local_nonprim = NULL;
    
    nf_service_status_local_nonprim = nf_service_status_parseFromJSON(nf_service_status); //nonprimitive

    // nf_service->fqdn
    cJSON *fqdn = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "fqdn");
    if (fqdn) { 
    if(!cJSON_IsString(fqdn))
    {
    goto end; //String
    }
    }

    // nf_service->inter_plmn_fqdn
    cJSON *inter_plmn_fqdn = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "interPlmnFqdn");
    if (inter_plmn_fqdn) { 
    if(!cJSON_IsString(inter_plmn_fqdn))
    {
    goto end; //String
    }
    }

    // nf_service->ip_end_points
    cJSON *ip_end_points = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "ipEndPoints");
    list_t *ip_end_pointsList;
    if (ip_end_points) { 
    cJSON *ip_end_points_local_nonprimitive;
    if(!cJSON_IsArray(ip_end_points)){
        goto end; //nonprimitive container
    }

    ip_end_pointsList = list_create();

    cJSON_ArrayForEach(ip_end_points_local_nonprimitive,ip_end_points )
    {
        if(!cJSON_IsObject(ip_end_points_local_nonprimitive)){
            goto end;
        }
        ip_end_point_t *ip_end_pointsItem = ip_end_point_parseFromJSON(ip_end_points_local_nonprimitive);

        list_addElement(ip_end_pointsList, ip_end_pointsItem);
    }
    }

    // nf_service->api_prefix
    cJSON *api_prefix = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "apiPrefix");
    if (api_prefix) { 
    if(!cJSON_IsString(api_prefix))
    {
    goto end; //String
    }
    }

    // nf_service->default_notification_subscriptions
    cJSON *default_notification_subscriptions = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "defaultNotificationSubscriptions");
    list_t *default_notification_subscriptionsList;
    if (default_notification_subscriptions) { 
    cJSON *default_notification_subscriptions_local_nonprimitive;
    if(!cJSON_IsArray(default_notification_subscriptions)){
        goto end; //nonprimitive container
    }

    default_notification_subscriptionsList = list_create();

    cJSON_ArrayForEach(default_notification_subscriptions_local_nonprimitive,default_notification_subscriptions )
    {
        if(!cJSON_IsObject(default_notification_subscriptions_local_nonprimitive)){
            goto end;
        }
        default_notification_subscription_t *default_notification_subscriptionsItem = default_notification_subscription_parseFromJSON(default_notification_subscriptions_local_nonprimitive);

        list_addElement(default_notification_subscriptionsList, default_notification_subscriptionsItem);
    }
    }

    // nf_service->allowed_plmns
    cJSON *allowed_plmns = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "allowedPlmns");
    list_t *allowed_plmnsList;
    if (allowed_plmns) { 
    cJSON *allowed_plmns_local_nonprimitive;
    if(!cJSON_IsArray(allowed_plmns)){
        goto end; //nonprimitive container
    }

    allowed_plmnsList = list_create();

    cJSON_ArrayForEach(allowed_plmns_local_nonprimitive,allowed_plmns )
    {
        if(!cJSON_IsObject(allowed_plmns_local_nonprimitive)){
            goto end;
        }
        plmn_id_t *allowed_plmnsItem = plmn_id_parseFromJSON(allowed_plmns_local_nonprimitive);

        list_addElement(allowed_plmnsList, allowed_plmnsItem);
    }
    }

    // nf_service->allowed_nf_types
    cJSON *allowed_nf_types = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "allowedNfTypes");
    list_t *allowed_nf_typesList;
    if (allowed_nf_types) { 
    cJSON *allowed_nf_types_local;
    if(!cJSON_IsArray(allowed_nf_types)) {
        goto end;//primitive container
    }
    allowed_nf_typesList = list_create();

    cJSON_ArrayForEach(allowed_nf_types_local, allowed_nf_types)
    {
        if(!cJSON_IsString(allowed_nf_types_local))
        {
            goto end;
        }
        list_addElement(allowed_nf_typesList , strdup(allowed_nf_types_local->valuestring));
    }
    }

    // nf_service->allowed_nf_domains
    cJSON *allowed_nf_domains = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "allowedNfDomains");
    list_t *allowed_nf_domainsList;
    if (allowed_nf_domains) { 
    cJSON *allowed_nf_domains_local;
    if(!cJSON_IsArray(allowed_nf_domains)) {
        goto end;//primitive container
    }
    allowed_nf_domainsList = list_create();

    cJSON_ArrayForEach(allowed_nf_domains_local, allowed_nf_domains)
    {
        if(!cJSON_IsString(allowed_nf_domains_local))
        {
            goto end;
        }
        list_addElement(allowed_nf_domainsList , strdup(allowed_nf_domains_local->valuestring));
    }
    }

    // nf_service->allowed_nssais
    cJSON *allowed_nssais = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "allowedNssais");
    list_t *allowed_nssaisList;
    if (allowed_nssais) { 
    cJSON *allowed_nssais_local_nonprimitive;
    if(!cJSON_IsArray(allowed_nssais)){
        goto end; //nonprimitive container
    }

    allowed_nssaisList = list_create();

    cJSON_ArrayForEach(allowed_nssais_local_nonprimitive,allowed_nssais )
    {
        if(!cJSON_IsObject(allowed_nssais_local_nonprimitive)){
            goto end;
        }
        snssai_t *allowed_nssaisItem = snssai_parseFromJSON(allowed_nssais_local_nonprimitive);

        list_addElement(allowed_nssaisList, allowed_nssaisItem);
    }
    }

    // nf_service->priority
    cJSON *priority = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "priority");
    if (priority) { 
    if(!cJSON_IsNumber(priority))
    {
    goto end; //Numeric
    }
    }

    // nf_service->capacity
    cJSON *capacity = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "capacity");
    if (capacity) { 
    if(!cJSON_IsNumber(capacity))
    {
    goto end; //Numeric
    }
    }

    // nf_service->load
    cJSON *load = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "load");
    if (load) { 
    if(!cJSON_IsNumber(load))
    {
    goto end; //Numeric
    }
    }

    // nf_service->recovery_time
    cJSON *recovery_time = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "recoveryTime");
    if (recovery_time) { 
    if(!cJSON_IsString(recovery_time))
    {
    goto end; //DateTime
    }
    }

    // nf_service->chf_service_info
    cJSON *chf_service_info = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "chfServiceInfo");
    chf_service_info_t *chf_service_info_local_nonprim = NULL;
    if (chf_service_info) { 
    chf_service_info_local_nonprim = chf_service_info_parseFromJSON(chf_service_info); //nonprimitive
    }

    // nf_service->supported_features
    cJSON *supported_features = cJSON_GetObjectItemCaseSensitive(nf_serviceJSON, "supportedFeatures");
    if (supported_features) { 
    if(!cJSON_IsString(supported_features))
    {
    goto end; //String
    }
    }


    nf_service_local_var = nf_service_create (
        strdup(service_instance_id->valuestring),
        service_name_local_nonprim,
        versionsList,
        scheme_local_nonprim,
        nf_service_status_local_nonprim,
        fqdn ? strdup(fqdn->valuestring) : NULL,
        inter_plmn_fqdn ? strdup(inter_plmn_fqdn->valuestring) : NULL,
        ip_end_points ? ip_end_pointsList : NULL,
        api_prefix ? strdup(api_prefix->valuestring) : NULL,
        default_notification_subscriptions ? default_notification_subscriptionsList : NULL,
        allowed_plmns ? allowed_plmnsList : NULL,
        allowed_nf_types ? allowed_nf_typesList : NULL,
        allowed_nf_domains ? allowed_nf_domainsList : NULL,
        allowed_nssais ? allowed_nssaisList : NULL,
        priority ? priority->valuedouble : 0,
        capacity ? capacity->valuedouble : 0,
        load ? load->valuedouble : 0,
        recovery_time ? strdup(recovery_time->valuestring) : NULL,
        chf_service_info ? chf_service_info_local_nonprim : NULL,
        supported_features ? strdup(supported_features->valuestring) : NULL
        );

    return nf_service_local_var;
end:
    return NULL;

}
