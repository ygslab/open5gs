
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "upf_info.h"

upf_info_t *upf_info_create(
    list_t *s_nssai_upf_info_list,
    list_t *smf_serving_area,
    list_t *interface_upf_info_list,
    int iwk_eps_ind,
    list_t *pdu_session_types,
    atsss_capability_t *atsss_capability,
    int ue_ip_addr_ind
    )
{
    upf_info_t *upf_info_local_var = ogs_malloc(sizeof(upf_info_t));
    if (!upf_info_local_var) {
        return NULL;
    }
    upf_info_local_var->s_nssai_upf_info_list = s_nssai_upf_info_list;
    upf_info_local_var->smf_serving_area = smf_serving_area;
    upf_info_local_var->interface_upf_info_list = interface_upf_info_list;
    upf_info_local_var->iwk_eps_ind = iwk_eps_ind;
    upf_info_local_var->pdu_session_types = pdu_session_types;
    upf_info_local_var->atsss_capability = atsss_capability;
    upf_info_local_var->ue_ip_addr_ind = ue_ip_addr_ind;

    return upf_info_local_var;
}

void upf_info_free(upf_info_t *upf_info)
{
    if(NULL == upf_info) {
        return;
    }
    listEntry_t *listEntry;
    list_ForEach(listEntry, upf_info->s_nssai_upf_info_list) {
        snssai_upf_info_item_free(listEntry->data);
    }
    list_free(upf_info->s_nssai_upf_info_list);
    list_ForEach(listEntry, upf_info->smf_serving_area) {
        ogs_free(listEntry->data);
    }
    list_free(upf_info->smf_serving_area);
    list_ForEach(listEntry, upf_info->interface_upf_info_list) {
        interface_upf_info_item_free(listEntry->data);
    }
    list_free(upf_info->interface_upf_info_list);
    list_ForEach(listEntry, upf_info->pdu_session_types) {
        pdu_session_type_free(listEntry->data);
    }
    list_free(upf_info->pdu_session_types);
    atsss_capability_free(upf_info->atsss_capability);
    ogs_free(upf_info);
}

cJSON *upf_info_convertToJSON(upf_info_t *upf_info)
{
    cJSON *item = cJSON_CreateObject();
    if (!upf_info->s_nssai_upf_info_list) {
        goto fail;
    }
    cJSON *s_nssai_upf_info_list = cJSON_AddArrayToObject(item, "sNssaiUpfInfoList");
    if(s_nssai_upf_info_list == NULL) {
        goto fail;
    }

    listEntry_t *s_nssai_upf_info_listListEntry;
    if (upf_info->s_nssai_upf_info_list) {
        list_ForEach(s_nssai_upf_info_listListEntry, upf_info->s_nssai_upf_info_list) {
            cJSON *itemLocal = snssai_upf_info_item_convertToJSON(s_nssai_upf_info_listListEntry->data);
            if(itemLocal == NULL) {
                goto fail;
            }
            cJSON_AddItemToArray(s_nssai_upf_info_list, itemLocal);
        }
    }

    if (upf_info->smf_serving_area) {
        cJSON *smf_serving_area = cJSON_AddArrayToObject(item, "smfServingArea");
        if(smf_serving_area == NULL) {
            goto fail;
        }

        listEntry_t *smf_serving_areaListEntry;
        list_ForEach(smf_serving_areaListEntry, upf_info->smf_serving_area) {
            if(cJSON_AddStringToObject(smf_serving_area, "", (char*)smf_serving_areaListEntry->data) == NULL) {
                goto fail;
            }
        }
    }

    if (upf_info->interface_upf_info_list) {
        cJSON *interface_upf_info_list = cJSON_AddArrayToObject(item, "interfaceUpfInfoList");
        if(interface_upf_info_list == NULL) {
            goto fail;
        }

        listEntry_t *interface_upf_info_listListEntry;
        if (upf_info->interface_upf_info_list) {
            list_ForEach(interface_upf_info_listListEntry, upf_info->interface_upf_info_list) {
                cJSON *itemLocal = interface_upf_info_item_convertToJSON(interface_upf_info_listListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(interface_upf_info_list, itemLocal);
            }
        }
    }

    if (upf_info->iwk_eps_ind) {
        if(cJSON_AddBoolToObject(item, "iwkEpsInd", upf_info->iwk_eps_ind) == NULL) {
            goto fail;
        }
    }

    if (upf_info->pdu_session_types) {
        cJSON *pdu_session_types = cJSON_AddArrayToObject(item, "pduSessionTypes");
        if(pdu_session_types == NULL) {
            goto fail;
        }

        listEntry_t *pdu_session_typesListEntry;
        if (upf_info->pdu_session_types) {
            list_ForEach(pdu_session_typesListEntry, upf_info->pdu_session_types) {
                cJSON *itemLocal = pdu_session_type_convertToJSON(pdu_session_typesListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(pdu_session_types, itemLocal);
            }
        }
    }

    if (upf_info->atsss_capability) {
        cJSON *atsss_capability_local_JSON = atsss_capability_convertToJSON(upf_info->atsss_capability);
        if(atsss_capability_local_JSON == NULL) {
            goto fail;
        }
        cJSON_AddItemToObject(item, "atsssCapability", atsss_capability_local_JSON);
        if(item->child == NULL) {
            goto fail;
        }
    }

    if (upf_info->ue_ip_addr_ind) {
        if(cJSON_AddBoolToObject(item, "ueIpAddrInd", upf_info->ue_ip_addr_ind) == NULL) {
            goto fail;
        }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

upf_info_t *upf_info_parseFromJSON(cJSON *upf_infoJSON)
{
    upf_info_t *upf_info_local_var = NULL;
    cJSON *s_nssai_upf_info_list = cJSON_GetObjectItemCaseSensitive(upf_infoJSON, "sNssaiUpfInfoList");
    if (!s_nssai_upf_info_list) {
        goto end;
    }

    list_t *s_nssai_upf_info_listList;

    cJSON *s_nssai_upf_info_list_local_nonprimitive;
    if(!cJSON_IsArray(s_nssai_upf_info_list)) {
        goto end;
    }

    s_nssai_upf_info_listList = list_create();

    cJSON_ArrayForEach(s_nssai_upf_info_list_local_nonprimitive,s_nssai_upf_info_list ) {
        if(!cJSON_IsObject(s_nssai_upf_info_list_local_nonprimitive)) {
            goto end;
        }
        snssai_upf_info_item_t *s_nssai_upf_info_listItem = snssai_upf_info_item_parseFromJSON(s_nssai_upf_info_list_local_nonprimitive);

        list_addElement(s_nssai_upf_info_listList, s_nssai_upf_info_listItem);
    }

    cJSON *smf_serving_area = cJSON_GetObjectItemCaseSensitive(upf_infoJSON, "smfServingArea");

    list_t *smf_serving_areaList;
    if (smf_serving_area) {
        cJSON *smf_serving_area_local;
        if(!cJSON_IsArray(smf_serving_area)) {
            goto end;
        }
        smf_serving_areaList = list_create();

        cJSON_ArrayForEach(smf_serving_area_local, smf_serving_area) {
            if(!cJSON_IsString(smf_serving_area_local)) {
                goto end;
            }
            list_addElement(smf_serving_areaList, ogs_strdup(smf_serving_area_local->valuestring));
        }
    }

    cJSON *interface_upf_info_list = cJSON_GetObjectItemCaseSensitive(upf_infoJSON, "interfaceUpfInfoList");

    list_t *interface_upf_info_listList;
    if (interface_upf_info_list) {
        cJSON *interface_upf_info_list_local_nonprimitive;
        if(!cJSON_IsArray(interface_upf_info_list)) {
            goto end;
        }

        interface_upf_info_listList = list_create();

        cJSON_ArrayForEach(interface_upf_info_list_local_nonprimitive,interface_upf_info_list ) {
            if(!cJSON_IsObject(interface_upf_info_list_local_nonprimitive)) {
                goto end;
            }
            interface_upf_info_item_t *interface_upf_info_listItem = interface_upf_info_item_parseFromJSON(interface_upf_info_list_local_nonprimitive);

            list_addElement(interface_upf_info_listList, interface_upf_info_listItem);
        }
    }

    cJSON *iwk_eps_ind = cJSON_GetObjectItemCaseSensitive(upf_infoJSON, "iwkEpsInd");

    if (iwk_eps_ind) {
        if(!cJSON_IsBool(iwk_eps_ind)) {
            goto end;
        }
    }

    cJSON *pdu_session_types = cJSON_GetObjectItemCaseSensitive(upf_infoJSON, "pduSessionTypes");

    list_t *pdu_session_typesList;
    if (pdu_session_types) {
        cJSON *pdu_session_types_local_nonprimitive;
        if(!cJSON_IsArray(pdu_session_types)) {
            goto end;
        }

        pdu_session_typesList = list_create();

        cJSON_ArrayForEach(pdu_session_types_local_nonprimitive,pdu_session_types ) {
            if(!cJSON_IsObject(pdu_session_types_local_nonprimitive)) {
                goto end;
            }
            pdu_session_type_t *pdu_session_typesItem = pdu_session_type_parseFromJSON(pdu_session_types_local_nonprimitive);

            list_addElement(pdu_session_typesList, pdu_session_typesItem);
        }
    }

    cJSON *atsss_capability = cJSON_GetObjectItemCaseSensitive(upf_infoJSON, "atsssCapability");

    atsss_capability_t *atsss_capability_local_nonprim = NULL;
    if (atsss_capability) {
        atsss_capability_local_nonprim = atsss_capability_parseFromJSON(atsss_capability);
    }

    cJSON *ue_ip_addr_ind = cJSON_GetObjectItemCaseSensitive(upf_infoJSON, "ueIpAddrInd");

    if (ue_ip_addr_ind) {
        if(!cJSON_IsBool(ue_ip_addr_ind)) {
            goto end;
        }
    }

    upf_info_local_var = upf_info_create (
        s_nssai_upf_info_listList,
        smf_serving_area ? smf_serving_areaList : NULL,
        interface_upf_info_list ? interface_upf_info_listList : NULL,
        iwk_eps_ind ? iwk_eps_ind->valueint : 0,
        pdu_session_types ? pdu_session_typesList : NULL,
        atsss_capability ? atsss_capability_local_nonprim : NULL,
        ue_ip_addr_ind ? ue_ip_addr_ind->valueint : 0
        );

    return upf_info_local_var;
end:
    return NULL;
}

