
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dnn_smf_info_item.h"

dnn_smf_info_item_t *dnn_smf_info_item_create(
    char *dnn
    )
{
    dnn_smf_info_item_t *dnn_smf_info_item_local_var = ogs_malloc(sizeof(dnn_smf_info_item_t));
    if (!dnn_smf_info_item_local_var) {
        return NULL;
    }
    dnn_smf_info_item_local_var->dnn = dnn;

    return dnn_smf_info_item_local_var;
}

void dnn_smf_info_item_free(dnn_smf_info_item_t *dnn_smf_info_item)
{
    if(NULL == dnn_smf_info_item) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(dnn_smf_info_item->dnn);
    ogs_free(dnn_smf_info_item);
}

cJSON *dnn_smf_info_item_convertToJSON(dnn_smf_info_item_t *dnn_smf_info_item)
{
    cJSON *item = cJSON_CreateObject();
    if (!dnn_smf_info_item->dnn) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "dnn", dnn_smf_info_item->dnn) == NULL) {
        goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

dnn_smf_info_item_t *dnn_smf_info_item_parseFromJSON(cJSON *dnn_smf_info_itemJSON)
{
    dnn_smf_info_item_t *dnn_smf_info_item_local_var = NULL;
    cJSON *dnn = cJSON_GetObjectItemCaseSensitive(dnn_smf_info_itemJSON, "dnn");
    if (!dnn) {
        goto end;
    }


    if(!cJSON_IsString(dnn))
    {
        goto end;
    }

    dnn_smf_info_item_local_var = dnn_smf_info_item_create (
        ogs_strdup(dnn->valuestring)
        );

    return dnn_smf_info_item_local_var;
end:
    return NULL;
}

