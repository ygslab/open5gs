#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "notification_data.h"



notification_data_t *notification_data_create(
    notification_event_type_t *event,
    char *nf_instance_uri,
    nf_profile_t *nf_profile,
    list_t *profile_changes
    ) {
    notification_data_t *notification_data_local_var = malloc(sizeof(notification_data_t));
    if (!notification_data_local_var) {
        return NULL;
    }
    notification_data_local_var->event = event;
    notification_data_local_var->nf_instance_uri = nf_instance_uri;
    notification_data_local_var->nf_profile = nf_profile;
    notification_data_local_var->profile_changes = profile_changes;

    return notification_data_local_var;
}


void notification_data_free(notification_data_t *notification_data) {
    if(NULL == notification_data){
        return ;
    }
    listEntry_t *listEntry;
    notification_event_type_free(notification_data->event);
    free(notification_data->nf_instance_uri);
    nf_profile_free(notification_data->nf_profile);
    list_ForEach(listEntry, notification_data->profile_changes) {
        change_item_free(listEntry->data);
    }
    list_free(notification_data->profile_changes);
    free(notification_data);
}

cJSON *notification_data_convertToJSON(notification_data_t *notification_data) {
    cJSON *item = cJSON_CreateObject();

    // notification_data->event
    if (!notification_data->event) {
        goto fail;
    }
    
    cJSON *event_local_JSON = notification_event_type_convertToJSON(notification_data->event);
    if(event_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "event", event_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // notification_data->nf_instance_uri
    if (!notification_data->nf_instance_uri) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "nfInstanceUri", notification_data->nf_instance_uri) == NULL) {
    goto fail; //String
    }


    // notification_data->nf_profile
    if(notification_data->nf_profile) { 
    cJSON *nf_profile_local_JSON = nf_profile_convertToJSON(notification_data->nf_profile);
    if(nf_profile_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nfProfile", nf_profile_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // notification_data->profile_changes
    if(notification_data->profile_changes) { 
    cJSON *profile_changes = cJSON_AddArrayToObject(item, "profileChanges");
    if(profile_changes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *profile_changesListEntry;
    if (notification_data->profile_changes) {
    list_ForEach(profile_changesListEntry, notification_data->profile_changes) {
    cJSON *itemLocal = change_item_convertToJSON(profile_changesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(profile_changes, itemLocal);
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

notification_data_t *notification_data_parseFromJSON(cJSON *notification_dataJSON){

    notification_data_t *notification_data_local_var = NULL;

    // notification_data->event
    cJSON *event = cJSON_GetObjectItemCaseSensitive(notification_dataJSON, "event");
    if (!event) {
        goto end;
    }

    notification_event_type_t *event_local_nonprim = NULL;
    
    event_local_nonprim = notification_event_type_parseFromJSON(event); //nonprimitive

    // notification_data->nf_instance_uri
    cJSON *nf_instance_uri = cJSON_GetObjectItemCaseSensitive(notification_dataJSON, "nfInstanceUri");
    if (!nf_instance_uri) {
        goto end;
    }

    
    if(!cJSON_IsString(nf_instance_uri))
    {
    goto end; //String
    }

    // notification_data->nf_profile
    cJSON *nf_profile = cJSON_GetObjectItemCaseSensitive(notification_dataJSON, "nfProfile");
    nf_profile_t *nf_profile_local_nonprim = NULL;
    if (nf_profile) { 
    nf_profile_local_nonprim = nf_profile_parseFromJSON(nf_profile); //nonprimitive
    }

    // notification_data->profile_changes
    cJSON *profile_changes = cJSON_GetObjectItemCaseSensitive(notification_dataJSON, "profileChanges");
    list_t *profile_changesList;
    if (profile_changes) { 
    cJSON *profile_changes_local_nonprimitive;
    if(!cJSON_IsArray(profile_changes)){
        goto end; //nonprimitive container
    }

    profile_changesList = list_create();

    cJSON_ArrayForEach(profile_changes_local_nonprimitive,profile_changes )
    {
        if(!cJSON_IsObject(profile_changes_local_nonprimitive)){
            goto end;
        }
        change_item_t *profile_changesItem = change_item_parseFromJSON(profile_changes_local_nonprimitive);

        list_addElement(profile_changesList, profile_changesItem);
    }
    }


    notification_data_local_var = notification_data_create (
        event_local_nonprim,
        strdup(nf_instance_uri->valuestring),
        nf_profile ? nf_profile_local_nonprim : NULL,
        profile_changes ? profile_changesList : NULL
        );

    return notification_data_local_var;
end:
    return NULL;

}
