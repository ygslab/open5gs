#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_item.h"



patch_item_t *patch_item_create(
    patch_operation_t *op,
    char *path,
    char *from,
    char *value
    ) {
    patch_item_t *patch_item_local_var = malloc(sizeof(patch_item_t));
    if (!patch_item_local_var) {
        return NULL;
    }
    patch_item_local_var->op = op;
    patch_item_local_var->path = path;
    patch_item_local_var->from = from;
    patch_item_local_var->value = value;

    return patch_item_local_var;
}


void patch_item_free(patch_item_t *patch_item) {
    if(NULL == patch_item){
        return ;
    }
    listEntry_t *listEntry;
    patch_operation_free(patch_item->op);
    free(patch_item->path);
    free(patch_item->from);
    free(patch_item->value);
    free(patch_item);
}

cJSON *patch_item_convertToJSON(patch_item_t *patch_item) {
    cJSON *item = cJSON_CreateObject();

    // patch_item->op
    if (!patch_item->op) {
        goto fail;
    }
    
    cJSON *op_local_JSON = patch_operation_convertToJSON(patch_item->op);
    if(op_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "op", op_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // patch_item->path
    if (!patch_item->path) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "path", patch_item->path) == NULL) {
    goto fail; //String
    }


    // patch_item->from
    if(patch_item->from) { 
    if(cJSON_AddStringToObject(item, "from", patch_item->from) == NULL) {
    goto fail; //String
    }
     } 


    // patch_item->value
    if(patch_item->value) { 
    if(cJSON_AddStringToObject(item, "value", patch_item->value) == NULL) {
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

patch_item_t *patch_item_parseFromJSON(cJSON *patch_itemJSON){

    patch_item_t *patch_item_local_var = NULL;

    // patch_item->op
    cJSON *op = cJSON_GetObjectItemCaseSensitive(patch_itemJSON, "op");
    if (!op) {
        goto end;
    }

    patch_operation_t *op_local_nonprim = NULL;
    
    op_local_nonprim = patch_operation_parseFromJSON(op); //nonprimitive

    // patch_item->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(patch_itemJSON, "path");
    if (!path) {
        goto end;
    }

    
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }

    // patch_item->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(patch_itemJSON, "from");
    if (from) { 
    if(!cJSON_IsString(from))
    {
    goto end; //String
    }
    }

    // patch_item->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(patch_itemJSON, "value");
    if (value) { 
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }
    }


    patch_item_local_var = patch_item_create (
        op_local_nonprim,
        strdup(path->valuestring),
        from ? strdup(from->valuestring) : NULL,
        value ? strdup(value->valuestring) : NULL
        );

    return patch_item_local_var;
end:
    return NULL;

}
