#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "notif_condition.h"



notif_condition_t *notif_condition_create(
    list_t *monitored_attributes,
    list_t *unmonitored_attributes
    ) {
    notif_condition_t *notif_condition_local_var = malloc(sizeof(notif_condition_t));
    if (!notif_condition_local_var) {
        return NULL;
    }
    notif_condition_local_var->monitored_attributes = monitored_attributes;
    notif_condition_local_var->unmonitored_attributes = unmonitored_attributes;

    return notif_condition_local_var;
}


void notif_condition_free(notif_condition_t *notif_condition) {
    if(NULL == notif_condition){
        return ;
    }
    listEntry_t *listEntry;
    list_ForEach(listEntry, notif_condition->monitored_attributes) {
        free(listEntry->data);
    }
    list_free(notif_condition->monitored_attributes);
    list_ForEach(listEntry, notif_condition->unmonitored_attributes) {
        free(listEntry->data);
    }
    list_free(notif_condition->unmonitored_attributes);
    free(notif_condition);
}

cJSON *notif_condition_convertToJSON(notif_condition_t *notif_condition) {
    cJSON *item = cJSON_CreateObject();

    // notif_condition->monitored_attributes
    if(notif_condition->monitored_attributes) { 
    cJSON *monitored_attributes = cJSON_AddArrayToObject(item, "monitoredAttributes");
    if(monitored_attributes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *monitored_attributesListEntry;
    list_ForEach(monitored_attributesListEntry, notif_condition->monitored_attributes) {
    if(cJSON_AddStringToObject(monitored_attributes, "", (char*)monitored_attributesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // notif_condition->unmonitored_attributes
    if(notif_condition->unmonitored_attributes) { 
    cJSON *unmonitored_attributes = cJSON_AddArrayToObject(item, "unmonitoredAttributes");
    if(unmonitored_attributes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *unmonitored_attributesListEntry;
    list_ForEach(unmonitored_attributesListEntry, notif_condition->unmonitored_attributes) {
    if(cJSON_AddStringToObject(unmonitored_attributes, "", (char*)unmonitored_attributesListEntry->data) == NULL)
    {
        goto fail;
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

notif_condition_t *notif_condition_parseFromJSON(cJSON *notif_conditionJSON){

    notif_condition_t *notif_condition_local_var = NULL;

    // notif_condition->monitored_attributes
    cJSON *monitored_attributes = cJSON_GetObjectItemCaseSensitive(notif_conditionJSON, "monitoredAttributes");
    list_t *monitored_attributesList;
    if (monitored_attributes) { 
    cJSON *monitored_attributes_local;
    if(!cJSON_IsArray(monitored_attributes)) {
        goto end;//primitive container
    }
    monitored_attributesList = list_create();

    cJSON_ArrayForEach(monitored_attributes_local, monitored_attributes)
    {
        if(!cJSON_IsString(monitored_attributes_local))
        {
            goto end;
        }
        list_addElement(monitored_attributesList , strdup(monitored_attributes_local->valuestring));
    }
    }

    // notif_condition->unmonitored_attributes
    cJSON *unmonitored_attributes = cJSON_GetObjectItemCaseSensitive(notif_conditionJSON, "unmonitoredAttributes");
    list_t *unmonitored_attributesList;
    if (unmonitored_attributes) { 
    cJSON *unmonitored_attributes_local;
    if(!cJSON_IsArray(unmonitored_attributes)) {
        goto end;//primitive container
    }
    unmonitored_attributesList = list_create();

    cJSON_ArrayForEach(unmonitored_attributes_local, unmonitored_attributes)
    {
        if(!cJSON_IsString(unmonitored_attributes_local))
        {
            goto end;
        }
        list_addElement(unmonitored_attributesList , strdup(unmonitored_attributes_local->valuestring));
    }
    }


    notif_condition_local_var = notif_condition_create (
        monitored_attributes ? monitored_attributesList : NULL,
        unmonitored_attributes ? unmonitored_attributesList : NULL
        );

    return notif_condition_local_var;
end:
    return NULL;

}
