
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nrf_info.h"

nrf_info_t *nrf_info_create(
    list_t* served_udr_info,
    list_t* served_udm_info,
    list_t* served_ausf_info,
    list_t* served_amf_info,
    list_t* served_smf_info,
    list_t* served_upf_info,
    list_t* served_pcf_info,
    list_t* served_bsf_info,
    list_t* served_chf_info,
    list_t* served_nwdaf_info
    )
{
    nrf_info_t *nrf_info_local_var = ogs_malloc(sizeof(nrf_info_t));
    if (!nrf_info_local_var) {
        return NULL;
    }
    nrf_info_local_var->served_udr_info = served_udr_info;
    nrf_info_local_var->served_udm_info = served_udm_info;
    nrf_info_local_var->served_ausf_info = served_ausf_info;
    nrf_info_local_var->served_amf_info = served_amf_info;
    nrf_info_local_var->served_smf_info = served_smf_info;
    nrf_info_local_var->served_upf_info = served_upf_info;
    nrf_info_local_var->served_pcf_info = served_pcf_info;
    nrf_info_local_var->served_bsf_info = served_bsf_info;
    nrf_info_local_var->served_chf_info = served_chf_info;
    nrf_info_local_var->served_nwdaf_info = served_nwdaf_info;

    return nrf_info_local_var;
}

void nrf_info_free(nrf_info_t *nrf_info)
{
    if(NULL == nrf_info) {
        return;
    }
    listEntry_t *listEntry;
    list_ForEach(listEntry, nrf_info->served_udr_info) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
        udr_info_free(localKeyValue->value);
        ogs_free(localKeyValue);
    }
    list_free(nrf_info->served_udr_info);
    list_ForEach(listEntry, nrf_info->served_udm_info) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
        udm_info_free(localKeyValue->value);
        ogs_free(localKeyValue);
    }
    list_free(nrf_info->served_udm_info);
    list_ForEach(listEntry, nrf_info->served_ausf_info) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
        ausf_info_free(localKeyValue->value);
        ogs_free(localKeyValue);
    }
    list_free(nrf_info->served_ausf_info);
    list_ForEach(listEntry, nrf_info->served_amf_info) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
        amf_info_free(localKeyValue->value);
        ogs_free(localKeyValue);
    }
    list_free(nrf_info->served_amf_info);
    list_ForEach(listEntry, nrf_info->served_smf_info) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
        smf_info_free(localKeyValue->value);
        ogs_free(localKeyValue);
    }
    list_free(nrf_info->served_smf_info);
    list_ForEach(listEntry, nrf_info->served_upf_info) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
        upf_info_free(localKeyValue->value);
        ogs_free(localKeyValue);
    }
    list_free(nrf_info->served_upf_info);
    list_ForEach(listEntry, nrf_info->served_pcf_info) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
        pcf_info_free(localKeyValue->value);
        ogs_free(localKeyValue);
    }
    list_free(nrf_info->served_pcf_info);
    list_ForEach(listEntry, nrf_info->served_bsf_info) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
        bsf_info_free(localKeyValue->value);
        ogs_free(localKeyValue);
    }
    list_free(nrf_info->served_bsf_info);
    list_ForEach(listEntry, nrf_info->served_chf_info) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
        chf_info_free(localKeyValue->value);
        ogs_free(localKeyValue);
    }
    list_free(nrf_info->served_chf_info);
    list_ForEach(listEntry, nrf_info->served_nwdaf_info) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
        nwdaf_info_free(localKeyValue->value);
        ogs_free(localKeyValue);
    }
    list_free(nrf_info->served_nwdaf_info);
    ogs_free(nrf_info);
}

cJSON *nrf_info_convertToJSON(nrf_info_t *nrf_info)
{
    cJSON *item = cJSON_CreateObject();
    if (nrf_info->served_udr_info) {
        cJSON *served_udr_info = cJSON_AddObjectToObject(item, "servedUdrInfo");
        if(served_udr_info == NULL) {
            goto fail;
        }
        cJSON *localMapObject = served_udr_info;
        listEntry_t *served_udr_infoListEntry;
        if (nrf_info->served_udr_info) {
            list_ForEach(served_udr_infoListEntry, nrf_info->served_udr_info) {
                keyValuePair_t *localKeyValue = (keyValuePair_t*)served_udr_infoListEntry->data;
                cJSON *itemLocal = udr_info_convertToJSON(localKeyValue->value);
                if (itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToObject(served_udr_info, localKeyValue->key, itemLocal);
            }
        }
    }

    if (nrf_info->served_udm_info) {
        cJSON *served_udm_info = cJSON_AddObjectToObject(item, "servedUdmInfo");
        if(served_udm_info == NULL) {
            goto fail;
        }
        cJSON *localMapObject = served_udm_info;
        listEntry_t *served_udm_infoListEntry;
        if (nrf_info->served_udm_info) {
            list_ForEach(served_udm_infoListEntry, nrf_info->served_udm_info) {
                keyValuePair_t *localKeyValue = (keyValuePair_t*)served_udm_infoListEntry->data;
                cJSON *itemLocal = udm_info_convertToJSON(localKeyValue->value);
                if (itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToObject(served_udm_info, localKeyValue->key, itemLocal);
            }
        }
    }

    if (nrf_info->served_ausf_info) {
        cJSON *served_ausf_info = cJSON_AddObjectToObject(item, "servedAusfInfo");
        if(served_ausf_info == NULL) {
            goto fail;
        }
        cJSON *localMapObject = served_ausf_info;
        listEntry_t *served_ausf_infoListEntry;
        if (nrf_info->served_ausf_info) {
            list_ForEach(served_ausf_infoListEntry, nrf_info->served_ausf_info) {
                keyValuePair_t *localKeyValue = (keyValuePair_t*)served_ausf_infoListEntry->data;
                cJSON *itemLocal = ausf_info_convertToJSON(localKeyValue->value);
                if (itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToObject(served_ausf_info, localKeyValue->key, itemLocal);
            }
        }
    }

    if (nrf_info->served_amf_info) {
        cJSON *served_amf_info = cJSON_AddObjectToObject(item, "servedAmfInfo");
        if(served_amf_info == NULL) {
            goto fail;
        }
        cJSON *localMapObject = served_amf_info;
        listEntry_t *served_amf_infoListEntry;
        if (nrf_info->served_amf_info) {
            list_ForEach(served_amf_infoListEntry, nrf_info->served_amf_info) {
                keyValuePair_t *localKeyValue = (keyValuePair_t*)served_amf_infoListEntry->data;
                cJSON *itemLocal = amf_info_convertToJSON(localKeyValue->value);
                if (itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToObject(served_amf_info, localKeyValue->key, itemLocal);
            }
        }
    }

    if (nrf_info->served_smf_info) {
        cJSON *served_smf_info = cJSON_AddObjectToObject(item, "servedSmfInfo");
        if(served_smf_info == NULL) {
            goto fail;
        }
        cJSON *localMapObject = served_smf_info;
        listEntry_t *served_smf_infoListEntry;
        if (nrf_info->served_smf_info) {
            list_ForEach(served_smf_infoListEntry, nrf_info->served_smf_info) {
                keyValuePair_t *localKeyValue = (keyValuePair_t*)served_smf_infoListEntry->data;
                cJSON *itemLocal = smf_info_convertToJSON(localKeyValue->value);
                if (itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToObject(served_smf_info, localKeyValue->key, itemLocal);
            }
        }
    }

    if (nrf_info->served_upf_info) {
        cJSON *served_upf_info = cJSON_AddObjectToObject(item, "servedUpfInfo");
        if(served_upf_info == NULL) {
            goto fail;
        }
        cJSON *localMapObject = served_upf_info;
        listEntry_t *served_upf_infoListEntry;
        if (nrf_info->served_upf_info) {
            list_ForEach(served_upf_infoListEntry, nrf_info->served_upf_info) {
                keyValuePair_t *localKeyValue = (keyValuePair_t*)served_upf_infoListEntry->data;
                cJSON *itemLocal = upf_info_convertToJSON(localKeyValue->value);
                if (itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToObject(served_upf_info, localKeyValue->key, itemLocal);
            }
        }
    }

    if (nrf_info->served_pcf_info) {
        cJSON *served_pcf_info = cJSON_AddObjectToObject(item, "servedPcfInfo");
        if(served_pcf_info == NULL) {
            goto fail;
        }
        cJSON *localMapObject = served_pcf_info;
        listEntry_t *served_pcf_infoListEntry;
        if (nrf_info->served_pcf_info) {
            list_ForEach(served_pcf_infoListEntry, nrf_info->served_pcf_info) {
                keyValuePair_t *localKeyValue = (keyValuePair_t*)served_pcf_infoListEntry->data;
                cJSON *itemLocal = pcf_info_convertToJSON(localKeyValue->value);
                if (itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToObject(served_pcf_info, localKeyValue->key, itemLocal);
            }
        }
    }

    if (nrf_info->served_bsf_info) {
        cJSON *served_bsf_info = cJSON_AddObjectToObject(item, "servedBsfInfo");
        if(served_bsf_info == NULL) {
            goto fail;
        }
        cJSON *localMapObject = served_bsf_info;
        listEntry_t *served_bsf_infoListEntry;
        if (nrf_info->served_bsf_info) {
            list_ForEach(served_bsf_infoListEntry, nrf_info->served_bsf_info) {
                keyValuePair_t *localKeyValue = (keyValuePair_t*)served_bsf_infoListEntry->data;
                cJSON *itemLocal = bsf_info_convertToJSON(localKeyValue->value);
                if (itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToObject(served_bsf_info, localKeyValue->key, itemLocal);
            }
        }
    }

    if (nrf_info->served_chf_info) {
        cJSON *served_chf_info = cJSON_AddObjectToObject(item, "servedChfInfo");
        if(served_chf_info == NULL) {
            goto fail;
        }
        cJSON *localMapObject = served_chf_info;
        listEntry_t *served_chf_infoListEntry;
        if (nrf_info->served_chf_info) {
            list_ForEach(served_chf_infoListEntry, nrf_info->served_chf_info) {
                keyValuePair_t *localKeyValue = (keyValuePair_t*)served_chf_infoListEntry->data;
                cJSON *itemLocal = chf_info_convertToJSON(localKeyValue->value);
                if (itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToObject(served_chf_info, localKeyValue->key, itemLocal);
            }
        }
    }

    if (nrf_info->served_nwdaf_info) {
        cJSON *served_nwdaf_info = cJSON_AddObjectToObject(item, "servedNwdafInfo");
        if(served_nwdaf_info == NULL) {
            goto fail;
        }
        cJSON *localMapObject = served_nwdaf_info;
        listEntry_t *served_nwdaf_infoListEntry;
        if (nrf_info->served_nwdaf_info) {
            list_ForEach(served_nwdaf_infoListEntry, nrf_info->served_nwdaf_info) {
                keyValuePair_t *localKeyValue = (keyValuePair_t*)served_nwdaf_infoListEntry->data;
                cJSON *itemLocal = nwdaf_info_convertToJSON(localKeyValue->value);
                if (itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToObject(served_nwdaf_info, localKeyValue->key, itemLocal);
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

nrf_info_t *nrf_info_parseFromJSON(cJSON *nrf_infoJSON)
{
    nrf_info_t *nrf_info_local_var = NULL;
    cJSON *served_udr_info = cJSON_GetObjectItemCaseSensitive(nrf_infoJSON, "servedUdrInfo");

    list_t *served_udr_infoList;
    if (served_udr_info) {
        cJSON *served_udr_info_local_map;
        if(!cJSON_IsObject(served_udr_info)) {
            goto end;
        }
        served_udr_infoList = list_create();
        keyValuePair_t *localMapKeyPair = NULL;
        cJSON_ArrayForEach(served_udr_info_local_map, served_udr_info) {
            cJSON *localMapObject = served_udr_info_local_map;
            if(!cJSON_IsObject(served_udr_info_local_map)) {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(
                localMapObject->string, udr_info_parseFromJSON(localMapObject));
            list_addElement(served_udr_infoList, localMapKeyPair);
        }
    }

    cJSON *served_udm_info = cJSON_GetObjectItemCaseSensitive(nrf_infoJSON, "servedUdmInfo");

    list_t *served_udm_infoList;
    if (served_udm_info) {
        cJSON *served_udm_info_local_map;
        if(!cJSON_IsObject(served_udm_info)) {
            goto end;
        }
        served_udm_infoList = list_create();
        keyValuePair_t *localMapKeyPair = NULL;
        cJSON_ArrayForEach(served_udm_info_local_map, served_udm_info) {
            cJSON *localMapObject = served_udm_info_local_map;
            if(!cJSON_IsObject(served_udm_info_local_map)) {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(
                localMapObject->string, udm_info_parseFromJSON(localMapObject));
            list_addElement(served_udm_infoList, localMapKeyPair);
        }
    }

    cJSON *served_ausf_info = cJSON_GetObjectItemCaseSensitive(nrf_infoJSON, "servedAusfInfo");

    list_t *served_ausf_infoList;
    if (served_ausf_info) {
        cJSON *served_ausf_info_local_map;
        if(!cJSON_IsObject(served_ausf_info)) {
            goto end;
        }
        served_ausf_infoList = list_create();
        keyValuePair_t *localMapKeyPair = NULL;
        cJSON_ArrayForEach(served_ausf_info_local_map, served_ausf_info) {
            cJSON *localMapObject = served_ausf_info_local_map;
            if(!cJSON_IsObject(served_ausf_info_local_map)) {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(
                localMapObject->string, ausf_info_parseFromJSON(localMapObject));
            list_addElement(served_ausf_infoList, localMapKeyPair);
        }
    }

    cJSON *served_amf_info = cJSON_GetObjectItemCaseSensitive(nrf_infoJSON, "servedAmfInfo");

    list_t *served_amf_infoList;
    if (served_amf_info) {
        cJSON *served_amf_info_local_map;
        if(!cJSON_IsObject(served_amf_info)) {
            goto end;
        }
        served_amf_infoList = list_create();
        keyValuePair_t *localMapKeyPair = NULL;
        cJSON_ArrayForEach(served_amf_info_local_map, served_amf_info) {
            cJSON *localMapObject = served_amf_info_local_map;
            if(!cJSON_IsObject(served_amf_info_local_map)) {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(
                localMapObject->string, amf_info_parseFromJSON(localMapObject));
            list_addElement(served_amf_infoList, localMapKeyPair);
        }
    }

    cJSON *served_smf_info = cJSON_GetObjectItemCaseSensitive(nrf_infoJSON, "servedSmfInfo");

    list_t *served_smf_infoList;
    if (served_smf_info) {
        cJSON *served_smf_info_local_map;
        if(!cJSON_IsObject(served_smf_info)) {
            goto end;
        }
        served_smf_infoList = list_create();
        keyValuePair_t *localMapKeyPair = NULL;
        cJSON_ArrayForEach(served_smf_info_local_map, served_smf_info) {
            cJSON *localMapObject = served_smf_info_local_map;
            if(!cJSON_IsObject(served_smf_info_local_map)) {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(
                localMapObject->string, smf_info_parseFromJSON(localMapObject));
            list_addElement(served_smf_infoList, localMapKeyPair);
        }
    }

    cJSON *served_upf_info = cJSON_GetObjectItemCaseSensitive(nrf_infoJSON, "servedUpfInfo");

    list_t *served_upf_infoList;
    if (served_upf_info) {
        cJSON *served_upf_info_local_map;
        if(!cJSON_IsObject(served_upf_info)) {
            goto end;
        }
        served_upf_infoList = list_create();
        keyValuePair_t *localMapKeyPair = NULL;
        cJSON_ArrayForEach(served_upf_info_local_map, served_upf_info) {
            cJSON *localMapObject = served_upf_info_local_map;
            if(!cJSON_IsObject(served_upf_info_local_map)) {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(
                localMapObject->string, upf_info_parseFromJSON(localMapObject));
            list_addElement(served_upf_infoList, localMapKeyPair);
        }
    }

    cJSON *served_pcf_info = cJSON_GetObjectItemCaseSensitive(nrf_infoJSON, "servedPcfInfo");

    list_t *served_pcf_infoList;
    if (served_pcf_info) {
        cJSON *served_pcf_info_local_map;
        if(!cJSON_IsObject(served_pcf_info)) {
            goto end;
        }
        served_pcf_infoList = list_create();
        keyValuePair_t *localMapKeyPair = NULL;
        cJSON_ArrayForEach(served_pcf_info_local_map, served_pcf_info) {
            cJSON *localMapObject = served_pcf_info_local_map;
            if(!cJSON_IsObject(served_pcf_info_local_map)) {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(
                localMapObject->string, pcf_info_parseFromJSON(localMapObject));
            list_addElement(served_pcf_infoList, localMapKeyPair);
        }
    }

    cJSON *served_bsf_info = cJSON_GetObjectItemCaseSensitive(nrf_infoJSON, "servedBsfInfo");

    list_t *served_bsf_infoList;
    if (served_bsf_info) {
        cJSON *served_bsf_info_local_map;
        if(!cJSON_IsObject(served_bsf_info)) {
            goto end;
        }
        served_bsf_infoList = list_create();
        keyValuePair_t *localMapKeyPair = NULL;
        cJSON_ArrayForEach(served_bsf_info_local_map, served_bsf_info) {
            cJSON *localMapObject = served_bsf_info_local_map;
            if(!cJSON_IsObject(served_bsf_info_local_map)) {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(
                localMapObject->string, bsf_info_parseFromJSON(localMapObject));
            list_addElement(served_bsf_infoList, localMapKeyPair);
        }
    }

    cJSON *served_chf_info = cJSON_GetObjectItemCaseSensitive(nrf_infoJSON, "servedChfInfo");

    list_t *served_chf_infoList;
    if (served_chf_info) {
        cJSON *served_chf_info_local_map;
        if(!cJSON_IsObject(served_chf_info)) {
            goto end;
        }
        served_chf_infoList = list_create();
        keyValuePair_t *localMapKeyPair = NULL;
        cJSON_ArrayForEach(served_chf_info_local_map, served_chf_info) {
            cJSON *localMapObject = served_chf_info_local_map;
            if(!cJSON_IsObject(served_chf_info_local_map)) {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(
                localMapObject->string, chf_info_parseFromJSON(localMapObject));
            list_addElement(served_chf_infoList, localMapKeyPair);
        }
    }

    cJSON *served_nwdaf_info = cJSON_GetObjectItemCaseSensitive(nrf_infoJSON, "servedNwdafInfo");

    list_t *served_nwdaf_infoList;
    if (served_nwdaf_info) {
        cJSON *served_nwdaf_info_local_map;
        if(!cJSON_IsObject(served_nwdaf_info)) {
            goto end;
        }
        served_nwdaf_infoList = list_create();
        keyValuePair_t *localMapKeyPair = NULL;
        cJSON_ArrayForEach(served_nwdaf_info_local_map, served_nwdaf_info) {
            cJSON *localMapObject = served_nwdaf_info_local_map;
            if(!cJSON_IsObject(served_nwdaf_info_local_map)) {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(
                localMapObject->string, nwdaf_info_parseFromJSON(localMapObject));
            list_addElement(served_nwdaf_infoList, localMapKeyPair);
        }
    }

    nrf_info_local_var = nrf_info_create (
        served_udr_info ? served_udr_infoList : NULL,
        served_udm_info ? served_udm_infoList : NULL,
        served_ausf_info ? served_ausf_infoList : NULL,
        served_amf_info ? served_amf_infoList : NULL,
        served_smf_info ? served_smf_infoList : NULL,
        served_upf_info ? served_upf_infoList : NULL,
        served_pcf_info ? served_pcf_infoList : NULL,
        served_bsf_info ? served_bsf_infoList : NULL,
        served_chf_info ? served_chf_infoList : NULL,
        served_nwdaf_info ? served_nwdaf_infoList : NULL
        );

    return nrf_info_local_var;
end:
    return NULL;
}

