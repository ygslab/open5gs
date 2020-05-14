
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "notification_data.h"

ogs_sbi_notification_data_t *ogs_sbi_notification_data_create(
    ogs_sbi_notification_event_type_e event,
    char *nf_instance_uri,
    ogs_sbi_nf_profile_t *nf_profile,
    ogs_sbi_list_t *profile_changes
    )
{
    ogs_sbi_notification_data_t *notification_data_local_var = ogs_sbi_malloc(sizeof(ogs_sbi_notification_data_t));
    if (!notification_data_local_var) {
        return NULL;
    }
    notification_data_local_var->event = event;
    notification_data_local_var->nf_instance_uri = nf_instance_uri;
    notification_data_local_var->nf_profile = nf_profile;
    notification_data_local_var->profile_changes = profile_changes;

    return notification_data_local_var;
}

void ogs_sbi_notification_data_free(ogs_sbi_notification_data_t *notification_data)
{
    if (NULL == notification_data) {
        return;
    }
    ogs_sbi_lnode_t *node;
    ogs_free(notification_data->nf_instance_uri);
    ogs_sbi_nf_profile_free(notification_data->nf_profile);
    ogs_sbi_list_for_each(notification_data->profile_changes, node) {
        ogs_sbi_change_item_free(node->data);
    }
    ogs_sbi_list_free(notification_data->profile_changes);
    ogs_free(notification_data);
}

cJSON *ogs_sbi_notification_data_convertToJSON(ogs_sbi_notification_data_t *notification_data)
{
    cJSON *item = cJSON_CreateObject();
    if (!notification_data->event) {
        ogs_error("ogs_sbi_notification_data_convertToJSON() failed [event]");
        goto end;
    }
    if (cJSON_AddStringToObject(item, "event", ogs_sbi_notification_event_type_ToString(notification_data->event)) == NULL) {
        ogs_error("ogs_sbi_notification_data_convertToJSON() failed [event]");
        goto end;
    }

    if (!notification_data->nf_instance_uri) {
        ogs_error("ogs_sbi_notification_data_convertToJSON() failed [nf_instance_uri]");
        goto end;
    }
    if (cJSON_AddStringToObject(item, "nfInstanceUri", notification_data->nf_instance_uri) == NULL) {
        ogs_error("ogs_sbi_notification_data_convertToJSON() failed [nf_instance_uri]");
        goto end;
    }

    if (notification_data->nf_profile) {
        cJSON *nf_profile_local_JSON = ogs_sbi_nf_profile_convertToJSON(notification_data->nf_profile);
        if (nf_profile_local_JSON == NULL) {
            ogs_error("ogs_sbi_notification_data_convertToJSON() failed [nf_profile]");
            goto end;
        }
        cJSON_AddItemToObject(item, "nfProfile", nf_profile_local_JSON);
        if (item->child == NULL) {
            ogs_error("ogs_sbi_notification_data_convertToJSON() failed [nf_profile]");
            goto end;
        }
    }

    if (notification_data->profile_changes) {
        cJSON *profile_changes = cJSON_AddArrayToObject(item, "profileChanges");
        if (profile_changes == NULL) {
            ogs_error("ogs_sbi_notification_data_convertToJSON() failed [profile_changes]");
            goto end;
        }

        ogs_sbi_lnode_t *profile_changes_node;
        if (notification_data->profile_changes) {
            ogs_sbi_list_for_each(notification_data->profile_changes, profile_changes_node) {
                cJSON *itemLocal = ogs_sbi_change_item_convertToJSON(profile_changes_node->data);
                if (itemLocal == NULL) {
                    ogs_error("ogs_sbi_notification_data_convertToJSON() failed [profile_changes]");
                    goto end;
                }
                cJSON_AddItemToArray(profile_changes, itemLocal);
            }
        }
    }

end:
    return item;
}

ogs_sbi_notification_data_t *ogs_sbi_notification_data_parseFromJSON(cJSON *notification_dataJSON)
{
    ogs_sbi_notification_data_t *notification_data_local_var = NULL;
    cJSON *event = cJSON_GetObjectItemCaseSensitive(notification_dataJSON, "event");
    if (!event) {
        ogs_error("ogs_sbi_notification_data_parseFromJSON() failed [event]");
        goto end;
    }

    ogs_sbi_notification_event_type_e eventVariable;

    if (!cJSON_IsString(event)) {
        ogs_error("ogs_sbi_notification_data_parseFromJSON() failed [event]");
        goto end;
    }
    eventVariable = ogs_sbi_notification_event_type_FromString(event->valuestring);

    cJSON *nf_instance_uri = cJSON_GetObjectItemCaseSensitive(notification_dataJSON, "nfInstanceUri");
    if (!nf_instance_uri) {
        ogs_error("ogs_sbi_notification_data_parseFromJSON() failed [nf_instance_uri]");
        goto end;
    }


    if (!cJSON_IsString(nf_instance_uri)) {
        ogs_error("ogs_sbi_notification_data_parseFromJSON() failed [nf_instance_uri]");
        goto end;
    }

    cJSON *nf_profile = cJSON_GetObjectItemCaseSensitive(notification_dataJSON, "nfProfile");

    ogs_sbi_nf_profile_t *nf_profile_local_nonprim = NULL;
    if (nf_profile) {
        nf_profile_local_nonprim = ogs_sbi_nf_profile_parseFromJSON(nf_profile);
    }

    cJSON *profile_changes = cJSON_GetObjectItemCaseSensitive(notification_dataJSON, "profileChanges");

    ogs_sbi_list_t *profile_changesList;
    if (profile_changes) {
        cJSON *profile_changes_local_nonprimitive;
        if (!cJSON_IsArray(profile_changes)) {
            ogs_error("ogs_sbi_notification_data_parseFromJSON() failed [profile_changes]");
            goto end;
        }

        profile_changesList = ogs_sbi_list_create();

        cJSON_ArrayForEach(profile_changes_local_nonprimitive, profile_changes ) {
            if (!cJSON_IsObject(profile_changes_local_nonprimitive)) {
                ogs_error("ogs_sbi_notification_data_parseFromJSON() failed [profile_changes]");
                goto end;
            }
            ogs_sbi_change_item_t *profile_changesItem = ogs_sbi_change_item_parseFromJSON(profile_changes_local_nonprimitive);

            ogs_sbi_list_add(profile_changesList, profile_changesItem);
        }
    }

    notification_data_local_var = ogs_sbi_notification_data_create (
        eventVariable,
        ogs_strdup(nf_instance_uri->valuestring),
        nf_profile ? nf_profile_local_nonprim : NULL,
        profile_changes ? profile_changesList : NULL
        );

    return notification_data_local_var;
end:
    return NULL;
}

