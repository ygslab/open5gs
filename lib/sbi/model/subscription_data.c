
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "subscription_data.h"

subscription_data_t *subscription_data_create(
    char *nf_status_notification_uri,
    char *req_nf_instance_id,
    char *subscription_id,
    char *validity_time,
    list_t *req_notif_events,
    plmn_id_t *plmn_id,
    notif_condition_t *notif_condition,
    nf_type_e req_nf_type,
    char *req_nf_fqdn,
    list_t *req_snssais
    )
{
    subscription_data_t *subscription_data_local_var = ogs_malloc(sizeof(subscription_data_t));
    if (!subscription_data_local_var) {
        return NULL;
    }
    subscription_data_local_var->nf_status_notification_uri = nf_status_notification_uri;
    subscription_data_local_var->req_nf_instance_id = req_nf_instance_id;
    subscription_data_local_var->subscription_id = subscription_id;
    subscription_data_local_var->validity_time = validity_time;
    subscription_data_local_var->req_notif_events = req_notif_events;
    subscription_data_local_var->plmn_id = plmn_id;
    subscription_data_local_var->notif_condition = notif_condition;
    subscription_data_local_var->req_nf_type = req_nf_type;
    subscription_data_local_var->req_nf_fqdn = req_nf_fqdn;
    subscription_data_local_var->req_snssais = req_snssais;

    return subscription_data_local_var;
}

void subscription_data_free(subscription_data_t *subscription_data)
{
    if(NULL == subscription_data) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(subscription_data->nf_status_notification_uri);
    ogs_free(subscription_data->req_nf_instance_id);
    ogs_free(subscription_data->subscription_id);
    ogs_free(subscription_data->validity_time);
    list_ForEach(listEntry, subscription_data->req_notif_events) {
        notification_event_type_free(listEntry->data);
    }
    list_free(subscription_data->req_notif_events);
    plmn_id_free(subscription_data->plmn_id);
    notif_condition_free(subscription_data->notif_condition);
    ogs_free(subscription_data->req_nf_fqdn);
    list_ForEach(listEntry, subscription_data->req_snssais) {
        snssai_free(listEntry->data);
    }
    list_free(subscription_data->req_snssais);
    ogs_free(subscription_data);
}

cJSON *subscription_data_convertToJSON(subscription_data_t *subscription_data)
{
    cJSON *item = cJSON_CreateObject();
    if (!subscription_data->nf_status_notification_uri) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "nfStatusNotificationUri", subscription_data->nf_status_notification_uri) == NULL) {
        goto fail;
    }

    if (subscription_data->req_nf_instance_id) {
        if(cJSON_AddStringToObject(item, "reqNfInstanceId", subscription_data->req_nf_instance_id) == NULL) {
            goto fail;
        }
    }

    if (!subscription_data->subscription_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "subscriptionId", subscription_data->subscription_id) == NULL) {
        goto fail;
    }

    if (subscription_data->validity_time) {
        if(cJSON_AddStringToObject(item, "validityTime", subscription_data->validity_time) == NULL) {
            goto fail;
        }
    }

    if (subscription_data->req_notif_events) {
        cJSON *req_notif_events = cJSON_AddArrayToObject(item, "reqNotifEvents");
        if(req_notif_events == NULL) {
            goto fail;
        }

        listEntry_t *req_notif_eventsListEntry;
        if (subscription_data->req_notif_events) {
            list_ForEach(req_notif_eventsListEntry, subscription_data->req_notif_events) {
                cJSON *itemLocal = notification_event_type_convertToJSON(req_notif_eventsListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(req_notif_events, itemLocal);
            }
        }
    }

    if (subscription_data->plmn_id) {
        cJSON *plmn_id_local_JSON = plmn_id_convertToJSON(subscription_data->plmn_id);
        if(plmn_id_local_JSON == NULL) {
            goto fail;
        }
        cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
        if(item->child == NULL) {
            goto fail;
        }
    }

    if (subscription_data->notif_condition) {
        cJSON *notif_condition_local_JSON = notif_condition_convertToJSON(subscription_data->notif_condition);
        if(notif_condition_local_JSON == NULL) {
            goto fail;
        }
        cJSON_AddItemToObject(item, "notifCondition", notif_condition_local_JSON);
        if(item->child == NULL) {
            goto fail;
        }
    }

    if (subscription_data->req_nf_type) {
        if(cJSON_AddStringToObject(item, "reqNfType", nf_type_ToString(subscription_data->req_nf_type)) == NULL) {
            goto fail;
        }
    }

    if (subscription_data->req_nf_fqdn) {
        if(cJSON_AddStringToObject(item, "reqNfFqdn", subscription_data->req_nf_fqdn) == NULL) {
            goto fail;
        }
    }

    if (subscription_data->req_snssais) {
        cJSON *req_snssais = cJSON_AddArrayToObject(item, "reqSnssais");
        if(req_snssais == NULL) {
            goto fail;
        }

        listEntry_t *req_snssaisListEntry;
        if (subscription_data->req_snssais) {
            list_ForEach(req_snssaisListEntry, subscription_data->req_snssais) {
                cJSON *itemLocal = snssai_convertToJSON(req_snssaisListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(req_snssais, itemLocal);
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

subscription_data_t *subscription_data_parseFromJSON(cJSON *subscription_dataJSON)
{
    subscription_data_t *subscription_data_local_var = NULL;
    cJSON *nf_status_notification_uri = cJSON_GetObjectItemCaseSensitive(subscription_dataJSON, "nfStatusNotificationUri");
    if (!nf_status_notification_uri) {
        goto end;
    }


    if(!cJSON_IsString(nf_status_notification_uri))
    {
        goto end;
    }

    cJSON *req_nf_instance_id = cJSON_GetObjectItemCaseSensitive(subscription_dataJSON, "reqNfInstanceId");

    if (req_nf_instance_id) {
        if(!cJSON_IsString(req_nf_instance_id))
        {
            goto end;
        }
    }

    cJSON *subscription_id = cJSON_GetObjectItemCaseSensitive(subscription_dataJSON, "subscriptionId");
    if (!subscription_id) {
        goto end;
    }


    if(!cJSON_IsString(subscription_id))
    {
        goto end;
    }

    cJSON *validity_time = cJSON_GetObjectItemCaseSensitive(subscription_dataJSON, "validityTime");

    if (validity_time) {
        if(!cJSON_IsString(validity_time)) {
            goto end;
        }
    }

    cJSON *req_notif_events = cJSON_GetObjectItemCaseSensitive(subscription_dataJSON, "reqNotifEvents");

    list_t *req_notif_eventsList;
    if (req_notif_events) {
        cJSON *req_notif_events_local_nonprimitive;
        if(!cJSON_IsArray(req_notif_events)) {
            goto end;
        }

        req_notif_eventsList = list_create();

        cJSON_ArrayForEach(req_notif_events_local_nonprimitive,req_notif_events ) {
            if(!cJSON_IsObject(req_notif_events_local_nonprimitive)) {
                goto end;
            }
            notification_event_type_t *req_notif_eventsItem = notification_event_type_parseFromJSON(req_notif_events_local_nonprimitive);

            list_addElement(req_notif_eventsList, req_notif_eventsItem);
        }
    }

    cJSON *plmn_id = cJSON_GetObjectItemCaseSensitive(subscription_dataJSON, "plmnId");

    plmn_id_t *plmn_id_local_nonprim = NULL;
    if (plmn_id) {
        plmn_id_local_nonprim = plmn_id_parseFromJSON(plmn_id);
    }

    cJSON *notif_condition = cJSON_GetObjectItemCaseSensitive(subscription_dataJSON, "notifCondition");

    notif_condition_t *notif_condition_local_nonprim = NULL;
    if (notif_condition) {
        notif_condition_local_nonprim = notif_condition_parseFromJSON(notif_condition);
    }

    cJSON *req_nf_type = cJSON_GetObjectItemCaseSensitive(subscription_dataJSON, "reqNfType");

    nf_type_e req_nf_typeVariable;
    if (req_nf_type) {
        if(!cJSON_IsString(req_nf_type)) {
            goto end;
        }
        req_nf_typeVariable = nf_type_FromString(req_nf_type->valuestring);
    }

    cJSON *req_nf_fqdn = cJSON_GetObjectItemCaseSensitive(subscription_dataJSON, "reqNfFqdn");

    if (req_nf_fqdn) {
        if(!cJSON_IsString(req_nf_fqdn))
        {
            goto end;
        }
    }

    cJSON *req_snssais = cJSON_GetObjectItemCaseSensitive(subscription_dataJSON, "reqSnssais");

    list_t *req_snssaisList;
    if (req_snssais) {
        cJSON *req_snssais_local_nonprimitive;
        if(!cJSON_IsArray(req_snssais)) {
            goto end;
        }

        req_snssaisList = list_create();

        cJSON_ArrayForEach(req_snssais_local_nonprimitive,req_snssais ) {
            if(!cJSON_IsObject(req_snssais_local_nonprimitive)) {
                goto end;
            }
            snssai_t *req_snssaisItem = snssai_parseFromJSON(req_snssais_local_nonprimitive);

            list_addElement(req_snssaisList, req_snssaisItem);
        }
    }

    subscription_data_local_var = subscription_data_create (
        ogs_strdup(nf_status_notification_uri->valuestring),
        req_nf_instance_id ? ogs_strdup(req_nf_instance_id->valuestring) : NULL,
        ogs_strdup(subscription_id->valuestring),
        validity_time ? ogs_strdup(validity_time->valuestring) : NULL,
        req_notif_events ? req_notif_eventsList : NULL,
        plmn_id ? plmn_id_local_nonprim : NULL,
        notif_condition ? notif_condition_local_nonprim : NULL,
        req_nf_type ? req_nf_typeVariable : -1,
        req_nf_fqdn ? ogs_strdup(req_nf_fqdn->valuestring) : NULL,
        req_snssais ? req_snssaisList : NULL
        );

    return subscription_data_local_var;
end:
    return NULL;
}

