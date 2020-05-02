
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "guami.h"

guami_t *guami_create(
    plmn_id_t *plmn_id,
    char *amf_id
    )
{
    guami_t *guami_local_var = ogs_malloc(sizeof(guami_t));
    if (!guami_local_var) {
        return NULL;
    }
    guami_local_var->plmn_id = plmn_id;
    guami_local_var->amf_id = amf_id;

    return guami_local_var;
}

void guami_free(guami_t *guami)
{
    if(NULL == guami) {
        return;
    }
    listEntry_t *listEntry;
    plmn_id_free(guami->plmn_id);
    ogs_free(guami->amf_id);
    ogs_free(guami);
}

cJSON *guami_convertToJSON(guami_t *guami)
{
    cJSON *item = cJSON_CreateObject();
    if (!guami->plmn_id) {
        goto fail;
    }
    cJSON *plmn_id_local_JSON = plmn_id_convertToJSON(guami->plmn_id);
    if(plmn_id_local_JSON == NULL) {
        goto fail;
    }
    cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }

    if (!guami->amf_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "amfId", guami->amf_id) == NULL) {
        goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

guami_t *guami_parseFromJSON(cJSON *guamiJSON)
{
    guami_t *guami_local_var = NULL;
    cJSON *plmn_id = cJSON_GetObjectItemCaseSensitive(guamiJSON, "plmnId");
    if (!plmn_id) {
        goto end;
    }

    plmn_id_t *plmn_id_local_nonprim = NULL;

    plmn_id_local_nonprim = plmn_id_parseFromJSON(plmn_id);

    cJSON *amf_id = cJSON_GetObjectItemCaseSensitive(guamiJSON, "amfId");
    if (!amf_id) {
        goto end;
    }


    if(!cJSON_IsString(amf_id))
    {
        goto end;
    }

    guami_local_var = guami_create (
        plmn_id_local_nonprim,
        ogs_strdup(amf_id->valuestring)
        );

    return guami_local_var;
end:
    return NULL;
}

