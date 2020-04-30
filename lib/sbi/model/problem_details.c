#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "problem_details.h"



problem_details_t *problem_details_create(
    char *type,
    char *title,
    int status,
    char *detail,
    char *instance,
    char *cause,
    list_t *invalid_params,
    char *supported_features
    ) {
    problem_details_t *problem_details_local_var = malloc(sizeof(problem_details_t));
    if (!problem_details_local_var) {
        return NULL;
    }
    problem_details_local_var->type = type;
    problem_details_local_var->title = title;
    problem_details_local_var->status = status;
    problem_details_local_var->detail = detail;
    problem_details_local_var->instance = instance;
    problem_details_local_var->cause = cause;
    problem_details_local_var->invalid_params = invalid_params;
    problem_details_local_var->supported_features = supported_features;

    return problem_details_local_var;
}


void problem_details_free(problem_details_t *problem_details) {
    if(NULL == problem_details){
        return ;
    }
    listEntry_t *listEntry;
    free(problem_details->type);
    free(problem_details->title);
    free(problem_details->detail);
    free(problem_details->instance);
    free(problem_details->cause);
    list_ForEach(listEntry, problem_details->invalid_params) {
        invalid_param_free(listEntry->data);
    }
    list_free(problem_details->invalid_params);
    free(problem_details->supported_features);
    free(problem_details);
}

cJSON *problem_details_convertToJSON(problem_details_t *problem_details) {
    cJSON *item = cJSON_CreateObject();

    // problem_details->type
    if(problem_details->type) { 
    if(cJSON_AddStringToObject(item, "type", problem_details->type) == NULL) {
    goto fail; //String
    }
     } 


    // problem_details->title
    if(problem_details->title) { 
    if(cJSON_AddStringToObject(item, "title", problem_details->title) == NULL) {
    goto fail; //String
    }
     } 


    // problem_details->status
    if(problem_details->status) { 
    if(cJSON_AddNumberToObject(item, "status", problem_details->status) == NULL) {
    goto fail; //Numeric
    }
     } 


    // problem_details->detail
    if(problem_details->detail) { 
    if(cJSON_AddStringToObject(item, "detail", problem_details->detail) == NULL) {
    goto fail; //String
    }
     } 


    // problem_details->instance
    if(problem_details->instance) { 
    if(cJSON_AddStringToObject(item, "instance", problem_details->instance) == NULL) {
    goto fail; //String
    }
     } 


    // problem_details->cause
    if(problem_details->cause) { 
    if(cJSON_AddStringToObject(item, "cause", problem_details->cause) == NULL) {
    goto fail; //String
    }
     } 


    // problem_details->invalid_params
    if(problem_details->invalid_params) { 
    cJSON *invalid_params = cJSON_AddArrayToObject(item, "invalidParams");
    if(invalid_params == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *invalid_paramsListEntry;
    if (problem_details->invalid_params) {
    list_ForEach(invalid_paramsListEntry, problem_details->invalid_params) {
    cJSON *itemLocal = invalid_param_convertToJSON(invalid_paramsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(invalid_params, itemLocal);
    }
    }
     } 


    // problem_details->supported_features
    if(problem_details->supported_features) { 
    if(cJSON_AddStringToObject(item, "supportedFeatures", problem_details->supported_features) == NULL) {
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

problem_details_t *problem_details_parseFromJSON(cJSON *problem_detailsJSON){

    problem_details_t *problem_details_local_var = NULL;

    // problem_details->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }

    // problem_details->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }
    }

    // problem_details->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "status");
    if (status) { 
    if(!cJSON_IsNumber(status))
    {
    goto end; //Numeric
    }
    }

    // problem_details->detail
    cJSON *detail = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "detail");
    if (detail) { 
    if(!cJSON_IsString(detail))
    {
    goto end; //String
    }
    }

    // problem_details->instance
    cJSON *instance = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "instance");
    if (instance) { 
    if(!cJSON_IsString(instance))
    {
    goto end; //String
    }
    }

    // problem_details->cause
    cJSON *cause = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "cause");
    if (cause) { 
    if(!cJSON_IsString(cause))
    {
    goto end; //String
    }
    }

    // problem_details->invalid_params
    cJSON *invalid_params = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "invalidParams");
    list_t *invalid_paramsList;
    if (invalid_params) { 
    cJSON *invalid_params_local_nonprimitive;
    if(!cJSON_IsArray(invalid_params)){
        goto end; //nonprimitive container
    }

    invalid_paramsList = list_create();

    cJSON_ArrayForEach(invalid_params_local_nonprimitive,invalid_params )
    {
        if(!cJSON_IsObject(invalid_params_local_nonprimitive)){
            goto end;
        }
        invalid_param_t *invalid_paramsItem = invalid_param_parseFromJSON(invalid_params_local_nonprimitive);

        list_addElement(invalid_paramsList, invalid_paramsItem);
    }
    }

    // problem_details->supported_features
    cJSON *supported_features = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "supportedFeatures");
    if (supported_features) { 
    if(!cJSON_IsString(supported_features))
    {
    goto end; //String
    }
    }


    problem_details_local_var = problem_details_create (
        type ? strdup(type->valuestring) : NULL,
        title ? strdup(title->valuestring) : NULL,
        status ? status->valuedouble : 0,
        detail ? strdup(detail->valuestring) : NULL,
        instance ? strdup(instance->valuestring) : NULL,
        cause ? strdup(cause->valuestring) : NULL,
        invalid_params ? invalid_paramsList : NULL,
        supported_features ? strdup(supported_features->valuestring) : NULL
        );

    return problem_details_local_var;
end:
    return NULL;

}
