
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snssai_smf_info_item.h"

OpenAPI_snssai_smf_info_item_t *OpenAPI_snssai_smf_info_item_create(
    OpenAPI_snssai_t *s_nssai,
    OpenAPI_list_t *dnn_smf_info_list
    )
{
    OpenAPI_snssai_smf_info_item_t *snssai_smf_info_item_local_var = OpenAPI_malloc(sizeof(OpenAPI_snssai_smf_info_item_t));
    if (!snssai_smf_info_item_local_var) {
        return NULL;
    }
    snssai_smf_info_item_local_var->s_nssai = s_nssai;
    snssai_smf_info_item_local_var->dnn_smf_info_list = dnn_smf_info_list;

    return snssai_smf_info_item_local_var;
}

void OpenAPI_snssai_smf_info_item_free(OpenAPI_snssai_smf_info_item_t *snssai_smf_info_item)
{
    if (NULL == snssai_smf_info_item) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_snssai_free(snssai_smf_info_item->s_nssai);
    OpenAPI_list_for_each(snssai_smf_info_item->dnn_smf_info_list, node) {
        OpenAPI_dnn_smf_info_item_free(node->data);
    }
    OpenAPI_list_free(snssai_smf_info_item->dnn_smf_info_list);
    ogs_free(snssai_smf_info_item);
}

cJSON *OpenAPI_snssai_smf_info_item_convertToJSON(OpenAPI_snssai_smf_info_item_t *snssai_smf_info_item)
{
    cJSON *item = NULL;

    if (snssai_smf_info_item == NULL) {
        ogs_error("OpenAPI_snssai_smf_info_item_convertToJSON() failed [SnssaiSmfInfoItem]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (!snssai_smf_info_item->s_nssai) {
        ogs_error("OpenAPI_snssai_smf_info_item_convertToJSON() failed [s_nssai]");
        goto end;
    }
    cJSON *s_nssai_local_JSON = OpenAPI_snssai_convertToJSON(snssai_smf_info_item->s_nssai);
    if (s_nssai_local_JSON == NULL) {
        ogs_error("OpenAPI_snssai_smf_info_item_convertToJSON() failed [s_nssai]");
        goto end;
    }
    cJSON_AddItemToObject(item, "sNssai", s_nssai_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_snssai_smf_info_item_convertToJSON() failed [s_nssai]");
        goto end;
    }

    if (!snssai_smf_info_item->dnn_smf_info_list) {
        ogs_error("OpenAPI_snssai_smf_info_item_convertToJSON() failed [dnn_smf_info_list]");
        goto end;
    }
    cJSON *dnn_smf_info_list = cJSON_AddArrayToObject(item, "dnnSmfInfoList");
    if (dnn_smf_info_list == NULL) {
        ogs_error("OpenAPI_snssai_smf_info_item_convertToJSON() failed [dnn_smf_info_list]");
        goto end;
    }

    OpenAPI_lnode_t *dnn_smf_info_list_node;
    if (snssai_smf_info_item->dnn_smf_info_list) {
        OpenAPI_list_for_each(snssai_smf_info_item->dnn_smf_info_list, dnn_smf_info_list_node) {
            cJSON *itemLocal = OpenAPI_dnn_smf_info_item_convertToJSON(dnn_smf_info_list_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_snssai_smf_info_item_convertToJSON() failed [dnn_smf_info_list]");
                goto end;
            }
            cJSON_AddItemToArray(dnn_smf_info_list, itemLocal);
        }
    }

end:
    return item;
}

OpenAPI_snssai_smf_info_item_t *OpenAPI_snssai_smf_info_item_parseFromJSON(cJSON *snssai_smf_info_itemJSON)
{
    OpenAPI_snssai_smf_info_item_t *snssai_smf_info_item_local_var = NULL;
    cJSON *s_nssai = cJSON_GetObjectItemCaseSensitive(snssai_smf_info_itemJSON, "sNssai");
    if (!s_nssai) {
        ogs_error("OpenAPI_snssai_smf_info_item_parseFromJSON() failed [s_nssai]");
        goto end;
    }

    OpenAPI_snssai_t *s_nssai_local_nonprim = NULL;

    s_nssai_local_nonprim = OpenAPI_snssai_parseFromJSON(s_nssai);

    cJSON *dnn_smf_info_list = cJSON_GetObjectItemCaseSensitive(snssai_smf_info_itemJSON, "dnnSmfInfoList");
    if (!dnn_smf_info_list) {
        ogs_error("OpenAPI_snssai_smf_info_item_parseFromJSON() failed [dnn_smf_info_list]");
        goto end;
    }

    OpenAPI_list_t *dnn_smf_info_listList;

    cJSON *dnn_smf_info_list_local_nonprimitive;
    if (!cJSON_IsArray(dnn_smf_info_list)) {
        ogs_error("OpenAPI_snssai_smf_info_item_parseFromJSON() failed [dnn_smf_info_list]");
        goto end;
    }

    dnn_smf_info_listList = OpenAPI_list_create();

    cJSON_ArrayForEach(dnn_smf_info_list_local_nonprimitive, dnn_smf_info_list ) {
        if (!cJSON_IsObject(dnn_smf_info_list_local_nonprimitive)) {
            ogs_error("OpenAPI_snssai_smf_info_item_parseFromJSON() failed [dnn_smf_info_list]");
            goto end;
        }
        OpenAPI_dnn_smf_info_item_t *dnn_smf_info_listItem = OpenAPI_dnn_smf_info_item_parseFromJSON(dnn_smf_info_list_local_nonprimitive);

        OpenAPI_list_add(dnn_smf_info_listList, dnn_smf_info_listItem);
    }

    snssai_smf_info_item_local_var = OpenAPI_snssai_smf_info_item_create (
        s_nssai_local_nonprim,
        dnn_smf_info_listList
        );

    return snssai_smf_info_item_local_var;
end:
    return NULL;
}

