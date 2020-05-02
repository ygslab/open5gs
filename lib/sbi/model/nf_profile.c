
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nf_profile.h"

nf_profile_t *nf_profile_create(
    char *nf_instance_id,
    char *nf_instance_name,
    nf_type_e nf_type,
    nf_status_e nf_status,
    int heart_beat_timer,
    list_t *plmn_list,
    list_t *s_nssais,
    list_t *per_plmn_snssai_list,
    list_t *nsi_list,
    char *fqdn,
    char *inter_plmn_fqdn,
    list_t *ipv4_addresses,
    list_t *ipv6_addresses,
    list_t *allowed_plmns,
    list_t *allowed_nf_types,
    list_t *allowed_nf_domains,
    list_t *allowed_nssais,
    int priority,
    int capacity,
    int load,
    char *locality,
    udr_info_t *udr_info,
    list_t *udr_info_ext,
    udm_info_t *udm_info,
    list_t *udm_info_ext,
    ausf_info_t *ausf_info,
    list_t *ausf_info_ext,
    amf_info_t *amf_info,
    list_t *amf_info_ext,
    smf_info_t *smf_info,
    list_t *smf_info_ext,
    upf_info_t *upf_info,
    list_t *upf_info_ext,
    pcf_info_t *pcf_info,
    list_t *pcf_info_ext,
    bsf_info_t *bsf_info,
    list_t *bsf_info_ext,
    chf_info_t *chf_info,
    list_t *chf_info_ext,
    nrf_info_t *nrf_info,
    nwdaf_info_t *nwdaf_info,
    object_t *custom_info,
    char *recovery_time,
    int nf_service_persistence,
    list_t *nf_services,
    int nf_profile_changes_support_ind,
    int nf_profile_changes_ind,
    list_t *default_notification_subscriptions
    )
{
    nf_profile_t *nf_profile_local_var = ogs_malloc(sizeof(nf_profile_t));
    if (!nf_profile_local_var) {
        return NULL;
    }
    nf_profile_local_var->nf_instance_id = nf_instance_id;
    nf_profile_local_var->nf_instance_name = nf_instance_name;
    nf_profile_local_var->nf_type = nf_type;
    nf_profile_local_var->nf_status = nf_status;
    nf_profile_local_var->heart_beat_timer = heart_beat_timer;
    nf_profile_local_var->plmn_list = plmn_list;
    nf_profile_local_var->s_nssais = s_nssais;
    nf_profile_local_var->per_plmn_snssai_list = per_plmn_snssai_list;
    nf_profile_local_var->nsi_list = nsi_list;
    nf_profile_local_var->fqdn = fqdn;
    nf_profile_local_var->inter_plmn_fqdn = inter_plmn_fqdn;
    nf_profile_local_var->ipv4_addresses = ipv4_addresses;
    nf_profile_local_var->ipv6_addresses = ipv6_addresses;
    nf_profile_local_var->allowed_plmns = allowed_plmns;
    nf_profile_local_var->allowed_nf_types = allowed_nf_types;
    nf_profile_local_var->allowed_nf_domains = allowed_nf_domains;
    nf_profile_local_var->allowed_nssais = allowed_nssais;
    nf_profile_local_var->priority = priority;
    nf_profile_local_var->capacity = capacity;
    nf_profile_local_var->load = load;
    nf_profile_local_var->locality = locality;
    nf_profile_local_var->udr_info = udr_info;
    nf_profile_local_var->udr_info_ext = udr_info_ext;
    nf_profile_local_var->udm_info = udm_info;
    nf_profile_local_var->udm_info_ext = udm_info_ext;
    nf_profile_local_var->ausf_info = ausf_info;
    nf_profile_local_var->ausf_info_ext = ausf_info_ext;
    nf_profile_local_var->amf_info = amf_info;
    nf_profile_local_var->amf_info_ext = amf_info_ext;
    nf_profile_local_var->smf_info = smf_info;
    nf_profile_local_var->smf_info_ext = smf_info_ext;
    nf_profile_local_var->upf_info = upf_info;
    nf_profile_local_var->upf_info_ext = upf_info_ext;
    nf_profile_local_var->pcf_info = pcf_info;
    nf_profile_local_var->pcf_info_ext = pcf_info_ext;
    nf_profile_local_var->bsf_info = bsf_info;
    nf_profile_local_var->bsf_info_ext = bsf_info_ext;
    nf_profile_local_var->chf_info = chf_info;
    nf_profile_local_var->chf_info_ext = chf_info_ext;
    nf_profile_local_var->nrf_info = nrf_info;
    nf_profile_local_var->nwdaf_info = nwdaf_info;
    nf_profile_local_var->custom_info = custom_info;
    nf_profile_local_var->recovery_time = recovery_time;
    nf_profile_local_var->nf_service_persistence = nf_service_persistence;
    nf_profile_local_var->nf_services = nf_services;
    nf_profile_local_var->nf_profile_changes_support_ind = nf_profile_changes_support_ind;
    nf_profile_local_var->nf_profile_changes_ind = nf_profile_changes_ind;
    nf_profile_local_var->default_notification_subscriptions = default_notification_subscriptions;

    return nf_profile_local_var;
}

void nf_profile_free(nf_profile_t *nf_profile)
{
    if(NULL == nf_profile) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(nf_profile->nf_instance_id);
    ogs_free(nf_profile->nf_instance_name);
    list_ForEach(listEntry, nf_profile->plmn_list) {
        plmn_id_free(listEntry->data);
    }
    list_free(nf_profile->plmn_list);
    list_ForEach(listEntry, nf_profile->s_nssais) {
        snssai_free(listEntry->data);
    }
    list_free(nf_profile->s_nssais);
    list_ForEach(listEntry, nf_profile->per_plmn_snssai_list) {
        plmn_snssai_free(listEntry->data);
    }
    list_free(nf_profile->per_plmn_snssai_list);
    list_ForEach(listEntry, nf_profile->nsi_list) {
        ogs_free(listEntry->data);
    }
    list_free(nf_profile->nsi_list);
    ogs_free(nf_profile->fqdn);
    ogs_free(nf_profile->inter_plmn_fqdn);
    list_ForEach(listEntry, nf_profile->ipv4_addresses) {
        ogs_free(listEntry->data);
    }
    list_free(nf_profile->ipv4_addresses);
    list_ForEach(listEntry, nf_profile->ipv6_addresses) {
        ipv6_addr_free(listEntry->data);
    }
    list_free(nf_profile->ipv6_addresses);
    list_ForEach(listEntry, nf_profile->allowed_plmns) {
        plmn_id_free(listEntry->data);
    }
    list_free(nf_profile->allowed_plmns);
    list_free(nf_profile->allowed_nf_types);
    list_ForEach(listEntry, nf_profile->allowed_nf_domains) {
        ogs_free(listEntry->data);
    }
    list_free(nf_profile->allowed_nf_domains);
    list_ForEach(listEntry, nf_profile->allowed_nssais) {
        snssai_free(listEntry->data);
    }
    list_free(nf_profile->allowed_nssais);
    ogs_free(nf_profile->locality);
    udr_info_free(nf_profile->udr_info);
    list_ForEach(listEntry, nf_profile->udr_info_ext) {
        udr_info_free(listEntry->data);
    }
    list_free(nf_profile->udr_info_ext);
    udm_info_free(nf_profile->udm_info);
    list_ForEach(listEntry, nf_profile->udm_info_ext) {
        udm_info_free(listEntry->data);
    }
    list_free(nf_profile->udm_info_ext);
    ausf_info_free(nf_profile->ausf_info);
    list_ForEach(listEntry, nf_profile->ausf_info_ext) {
        ausf_info_free(listEntry->data);
    }
    list_free(nf_profile->ausf_info_ext);
    amf_info_free(nf_profile->amf_info);
    list_ForEach(listEntry, nf_profile->amf_info_ext) {
        amf_info_free(listEntry->data);
    }
    list_free(nf_profile->amf_info_ext);
    smf_info_free(nf_profile->smf_info);
    list_ForEach(listEntry, nf_profile->smf_info_ext) {
        smf_info_free(listEntry->data);
    }
    list_free(nf_profile->smf_info_ext);
    upf_info_free(nf_profile->upf_info);
    list_ForEach(listEntry, nf_profile->upf_info_ext) {
        upf_info_free(listEntry->data);
    }
    list_free(nf_profile->upf_info_ext);
    pcf_info_free(nf_profile->pcf_info);
    list_ForEach(listEntry, nf_profile->pcf_info_ext) {
        pcf_info_free(listEntry->data);
    }
    list_free(nf_profile->pcf_info_ext);
    bsf_info_free(nf_profile->bsf_info);
    list_ForEach(listEntry, nf_profile->bsf_info_ext) {
        bsf_info_free(listEntry->data);
    }
    list_free(nf_profile->bsf_info_ext);
    chf_info_free(nf_profile->chf_info);
    list_ForEach(listEntry, nf_profile->chf_info_ext) {
        chf_info_free(listEntry->data);
    }
    list_free(nf_profile->chf_info_ext);
    nrf_info_free(nf_profile->nrf_info);
    nwdaf_info_free(nf_profile->nwdaf_info);
    object_free(nf_profile->custom_info);
    ogs_free(nf_profile->recovery_time);
    list_ForEach(listEntry, nf_profile->nf_services) {
        nf_service_free(listEntry->data);
    }
    list_free(nf_profile->nf_services);
    list_ForEach(listEntry, nf_profile->default_notification_subscriptions) {
        default_notification_subscription_free(listEntry->data);
    }
    list_free(nf_profile->default_notification_subscriptions);
    ogs_free(nf_profile);
}

cJSON *nf_profile_convertToJSON(nf_profile_t *nf_profile)
{
    cJSON *item = cJSON_CreateObject();
    if (!nf_profile->nf_instance_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "nfInstanceId", nf_profile->nf_instance_id) == NULL) {
        goto fail;
    }

    if (nf_profile->nf_instance_name) {
        if(cJSON_AddStringToObject(item, "nfInstanceName", nf_profile->nf_instance_name) == NULL) {
            goto fail;
        }
    }

    if (!nf_profile->nf_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "nfType", nf_type_ToString(nf_profile->nf_type)) == NULL) {
        goto fail;
    }

    if (!nf_profile->nf_status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "nfStatus", nf_status_ToString(nf_profile->nf_status)) == NULL) {
        goto fail;
    }

    if (nf_profile->heart_beat_timer) {
        if(cJSON_AddNumberToObject(item, "heartBeatTimer", nf_profile->heart_beat_timer) == NULL) {
            goto fail;
        }
    }

    if (nf_profile->plmn_list) {
        cJSON *plmn_list = cJSON_AddArrayToObject(item, "plmnList");
        if(plmn_list == NULL) {
            goto fail;
        }

        listEntry_t *plmn_listListEntry;
        if (nf_profile->plmn_list) {
            list_ForEach(plmn_listListEntry, nf_profile->plmn_list) {
                cJSON *itemLocal = plmn_id_convertToJSON(plmn_listListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(plmn_list, itemLocal);
            }
        }
    }

    if (nf_profile->s_nssais) {
        cJSON *s_nssais = cJSON_AddArrayToObject(item, "sNssais");
        if(s_nssais == NULL) {
            goto fail;
        }

        listEntry_t *s_nssaisListEntry;
        if (nf_profile->s_nssais) {
            list_ForEach(s_nssaisListEntry, nf_profile->s_nssais) {
                cJSON *itemLocal = snssai_convertToJSON(s_nssaisListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(s_nssais, itemLocal);
            }
        }
    }

    if (nf_profile->per_plmn_snssai_list) {
        cJSON *per_plmn_snssai_list = cJSON_AddArrayToObject(item, "perPlmnSnssaiList");
        if(per_plmn_snssai_list == NULL) {
            goto fail;
        }

        listEntry_t *per_plmn_snssai_listListEntry;
        if (nf_profile->per_plmn_snssai_list) {
            list_ForEach(per_plmn_snssai_listListEntry, nf_profile->per_plmn_snssai_list) {
                cJSON *itemLocal = plmn_snssai_convertToJSON(per_plmn_snssai_listListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(per_plmn_snssai_list, itemLocal);
            }
        }
    }

    if (nf_profile->nsi_list) {
        cJSON *nsi_list = cJSON_AddArrayToObject(item, "nsiList");
        if(nsi_list == NULL) {
            goto fail;
        }

        listEntry_t *nsi_listListEntry;
        list_ForEach(nsi_listListEntry, nf_profile->nsi_list) {
            if(cJSON_AddStringToObject(nsi_list, "", (char*)nsi_listListEntry->data) == NULL) {
                goto fail;
            }
        }
    }

    if (nf_profile->fqdn) {
        if(cJSON_AddStringToObject(item, "fqdn", nf_profile->fqdn) == NULL) {
            goto fail;
        }
    }

    if (nf_profile->inter_plmn_fqdn) {
        if(cJSON_AddStringToObject(item, "interPlmnFqdn", nf_profile->inter_plmn_fqdn) == NULL) {
            goto fail;
        }
    }

    if (nf_profile->ipv4_addresses) {
        cJSON *ipv4_addresses = cJSON_AddArrayToObject(item, "ipv4Addresses");
        if(ipv4_addresses == NULL) {
            goto fail;
        }

        listEntry_t *ipv4_addressesListEntry;
        list_ForEach(ipv4_addressesListEntry, nf_profile->ipv4_addresses) {
            if(cJSON_AddStringToObject(ipv4_addresses, "", (char*)ipv4_addressesListEntry->data) == NULL) {
                goto fail;
            }
        }
    }

    if (nf_profile->ipv6_addresses) {
        cJSON *ipv6_addresses = cJSON_AddArrayToObject(item, "ipv6Addresses");
        if(ipv6_addresses == NULL) {
            goto fail;
        }

        listEntry_t *ipv6_addressesListEntry;
        if (nf_profile->ipv6_addresses) {
            list_ForEach(ipv6_addressesListEntry, nf_profile->ipv6_addresses) {
                cJSON *itemLocal = ipv6_addr_convertToJSON(ipv6_addressesListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(ipv6_addresses, itemLocal);
            }
        }
    }

    if (nf_profile->allowed_plmns) {
        cJSON *allowed_plmns = cJSON_AddArrayToObject(item, "allowedPlmns");
        if(allowed_plmns == NULL) {
            goto fail;
        }

        listEntry_t *allowed_plmnsListEntry;
        if (nf_profile->allowed_plmns) {
            list_ForEach(allowed_plmnsListEntry, nf_profile->allowed_plmns) {
                cJSON *itemLocal = plmn_id_convertToJSON(allowed_plmnsListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(allowed_plmns, itemLocal);
            }
        }
    }

    if (nf_profile->allowed_nf_types) {
        cJSON *allowed_nf_types = cJSON_AddArrayToObject(item, "allowedNfTypes");
        if(allowed_nf_types == NULL) {
            goto fail;
        }
        listEntry_t *allowed_nf_typesListEntry;
        list_ForEach(allowed_nf_typesListEntry, nf_profile->allowed_nf_types) {
            if(cJSON_AddStringToObject(allowed_nf_types, "", nf_type_ToString((nf_type_e)allowed_nf_typesListEntry->data)) == NULL) {
                goto fail;
            }
        }
    }

    if (nf_profile->allowed_nf_domains) {
        cJSON *allowed_nf_domains = cJSON_AddArrayToObject(item, "allowedNfDomains");
        if(allowed_nf_domains == NULL) {
            goto fail;
        }

        listEntry_t *allowed_nf_domainsListEntry;
        list_ForEach(allowed_nf_domainsListEntry, nf_profile->allowed_nf_domains) {
            if(cJSON_AddStringToObject(allowed_nf_domains, "", (char*)allowed_nf_domainsListEntry->data) == NULL) {
                goto fail;
            }
        }
    }

    if (nf_profile->allowed_nssais) {
        cJSON *allowed_nssais = cJSON_AddArrayToObject(item, "allowedNssais");
        if(allowed_nssais == NULL) {
            goto fail;
        }

        listEntry_t *allowed_nssaisListEntry;
        if (nf_profile->allowed_nssais) {
            list_ForEach(allowed_nssaisListEntry, nf_profile->allowed_nssais) {
                cJSON *itemLocal = snssai_convertToJSON(allowed_nssaisListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(allowed_nssais, itemLocal);
            }
        }
    }

    if (nf_profile->priority) {
        if(cJSON_AddNumberToObject(item, "priority", nf_profile->priority) == NULL) {
            goto fail;
        }
    }

    if (nf_profile->capacity) {
        if(cJSON_AddNumberToObject(item, "capacity", nf_profile->capacity) == NULL) {
            goto fail;
        }
    }

    if (nf_profile->load) {
        if(cJSON_AddNumberToObject(item, "load", nf_profile->load) == NULL) {
            goto fail;
        }
    }

    if (nf_profile->locality) {
        if(cJSON_AddStringToObject(item, "locality", nf_profile->locality) == NULL) {
            goto fail;
        }
    }

    if (nf_profile->udr_info) {
        cJSON *udr_info_local_JSON = udr_info_convertToJSON(nf_profile->udr_info);
        if(udr_info_local_JSON == NULL) {
            goto fail;
        }
        cJSON_AddItemToObject(item, "udrInfo", udr_info_local_JSON);
        if(item->child == NULL) {
            goto fail;
        }
    }

    if (nf_profile->udr_info_ext) {
        cJSON *udr_info_ext = cJSON_AddArrayToObject(item, "udrInfoExt");
        if(udr_info_ext == NULL) {
            goto fail;
        }

        listEntry_t *udr_info_extListEntry;
        if (nf_profile->udr_info_ext) {
            list_ForEach(udr_info_extListEntry, nf_profile->udr_info_ext) {
                cJSON *itemLocal = udr_info_convertToJSON(udr_info_extListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(udr_info_ext, itemLocal);
            }
        }
    }

    if (nf_profile->udm_info) {
        cJSON *udm_info_local_JSON = udm_info_convertToJSON(nf_profile->udm_info);
        if(udm_info_local_JSON == NULL) {
            goto fail;
        }
        cJSON_AddItemToObject(item, "udmInfo", udm_info_local_JSON);
        if(item->child == NULL) {
            goto fail;
        }
    }

    if (nf_profile->udm_info_ext) {
        cJSON *udm_info_ext = cJSON_AddArrayToObject(item, "udmInfoExt");
        if(udm_info_ext == NULL) {
            goto fail;
        }

        listEntry_t *udm_info_extListEntry;
        if (nf_profile->udm_info_ext) {
            list_ForEach(udm_info_extListEntry, nf_profile->udm_info_ext) {
                cJSON *itemLocal = udm_info_convertToJSON(udm_info_extListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(udm_info_ext, itemLocal);
            }
        }
    }

    if (nf_profile->ausf_info) {
        cJSON *ausf_info_local_JSON = ausf_info_convertToJSON(nf_profile->ausf_info);
        if(ausf_info_local_JSON == NULL) {
            goto fail;
        }
        cJSON_AddItemToObject(item, "ausfInfo", ausf_info_local_JSON);
        if(item->child == NULL) {
            goto fail;
        }
    }

    if (nf_profile->ausf_info_ext) {
        cJSON *ausf_info_ext = cJSON_AddArrayToObject(item, "ausfInfoExt");
        if(ausf_info_ext == NULL) {
            goto fail;
        }

        listEntry_t *ausf_info_extListEntry;
        if (nf_profile->ausf_info_ext) {
            list_ForEach(ausf_info_extListEntry, nf_profile->ausf_info_ext) {
                cJSON *itemLocal = ausf_info_convertToJSON(ausf_info_extListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(ausf_info_ext, itemLocal);
            }
        }
    }

    if (nf_profile->amf_info) {
        cJSON *amf_info_local_JSON = amf_info_convertToJSON(nf_profile->amf_info);
        if(amf_info_local_JSON == NULL) {
            goto fail;
        }
        cJSON_AddItemToObject(item, "amfInfo", amf_info_local_JSON);
        if(item->child == NULL) {
            goto fail;
        }
    }

    if (nf_profile->amf_info_ext) {
        cJSON *amf_info_ext = cJSON_AddArrayToObject(item, "amfInfoExt");
        if(amf_info_ext == NULL) {
            goto fail;
        }

        listEntry_t *amf_info_extListEntry;
        if (nf_profile->amf_info_ext) {
            list_ForEach(amf_info_extListEntry, nf_profile->amf_info_ext) {
                cJSON *itemLocal = amf_info_convertToJSON(amf_info_extListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(amf_info_ext, itemLocal);
            }
        }
    }

    if (nf_profile->smf_info) {
        cJSON *smf_info_local_JSON = smf_info_convertToJSON(nf_profile->smf_info);
        if(smf_info_local_JSON == NULL) {
            goto fail;
        }
        cJSON_AddItemToObject(item, "smfInfo", smf_info_local_JSON);
        if(item->child == NULL) {
            goto fail;
        }
    }

    if (nf_profile->smf_info_ext) {
        cJSON *smf_info_ext = cJSON_AddArrayToObject(item, "smfInfoExt");
        if(smf_info_ext == NULL) {
            goto fail;
        }

        listEntry_t *smf_info_extListEntry;
        if (nf_profile->smf_info_ext) {
            list_ForEach(smf_info_extListEntry, nf_profile->smf_info_ext) {
                cJSON *itemLocal = smf_info_convertToJSON(smf_info_extListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(smf_info_ext, itemLocal);
            }
        }
    }

    if (nf_profile->upf_info) {
        cJSON *upf_info_local_JSON = upf_info_convertToJSON(nf_profile->upf_info);
        if(upf_info_local_JSON == NULL) {
            goto fail;
        }
        cJSON_AddItemToObject(item, "upfInfo", upf_info_local_JSON);
        if(item->child == NULL) {
            goto fail;
        }
    }

    if (nf_profile->upf_info_ext) {
        cJSON *upf_info_ext = cJSON_AddArrayToObject(item, "upfInfoExt");
        if(upf_info_ext == NULL) {
            goto fail;
        }

        listEntry_t *upf_info_extListEntry;
        if (nf_profile->upf_info_ext) {
            list_ForEach(upf_info_extListEntry, nf_profile->upf_info_ext) {
                cJSON *itemLocal = upf_info_convertToJSON(upf_info_extListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(upf_info_ext, itemLocal);
            }
        }
    }

    if (nf_profile->pcf_info) {
        cJSON *pcf_info_local_JSON = pcf_info_convertToJSON(nf_profile->pcf_info);
        if(pcf_info_local_JSON == NULL) {
            goto fail;
        }
        cJSON_AddItemToObject(item, "pcfInfo", pcf_info_local_JSON);
        if(item->child == NULL) {
            goto fail;
        }
    }

    if (nf_profile->pcf_info_ext) {
        cJSON *pcf_info_ext = cJSON_AddArrayToObject(item, "pcfInfoExt");
        if(pcf_info_ext == NULL) {
            goto fail;
        }

        listEntry_t *pcf_info_extListEntry;
        if (nf_profile->pcf_info_ext) {
            list_ForEach(pcf_info_extListEntry, nf_profile->pcf_info_ext) {
                cJSON *itemLocal = pcf_info_convertToJSON(pcf_info_extListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(pcf_info_ext, itemLocal);
            }
        }
    }

    if (nf_profile->bsf_info) {
        cJSON *bsf_info_local_JSON = bsf_info_convertToJSON(nf_profile->bsf_info);
        if(bsf_info_local_JSON == NULL) {
            goto fail;
        }
        cJSON_AddItemToObject(item, "bsfInfo", bsf_info_local_JSON);
        if(item->child == NULL) {
            goto fail;
        }
    }

    if (nf_profile->bsf_info_ext) {
        cJSON *bsf_info_ext = cJSON_AddArrayToObject(item, "bsfInfoExt");
        if(bsf_info_ext == NULL) {
            goto fail;
        }

        listEntry_t *bsf_info_extListEntry;
        if (nf_profile->bsf_info_ext) {
            list_ForEach(bsf_info_extListEntry, nf_profile->bsf_info_ext) {
                cJSON *itemLocal = bsf_info_convertToJSON(bsf_info_extListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(bsf_info_ext, itemLocal);
            }
        }
    }

    if (nf_profile->chf_info) {
        cJSON *chf_info_local_JSON = chf_info_convertToJSON(nf_profile->chf_info);
        if(chf_info_local_JSON == NULL) {
            goto fail;
        }
        cJSON_AddItemToObject(item, "chfInfo", chf_info_local_JSON);
        if(item->child == NULL) {
            goto fail;
        }
    }

    if (nf_profile->chf_info_ext) {
        cJSON *chf_info_ext = cJSON_AddArrayToObject(item, "chfInfoExt");
        if(chf_info_ext == NULL) {
            goto fail;
        }

        listEntry_t *chf_info_extListEntry;
        if (nf_profile->chf_info_ext) {
            list_ForEach(chf_info_extListEntry, nf_profile->chf_info_ext) {
                cJSON *itemLocal = chf_info_convertToJSON(chf_info_extListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(chf_info_ext, itemLocal);
            }
        }
    }

    if (nf_profile->nrf_info) {
        cJSON *nrf_info_local_JSON = nrf_info_convertToJSON(nf_profile->nrf_info);
        if(nrf_info_local_JSON == NULL) {
            goto fail;
        }
        cJSON_AddItemToObject(item, "nrfInfo", nrf_info_local_JSON);
        if(item->child == NULL) {
            goto fail;
        }
    }

    if (nf_profile->nwdaf_info) {
        cJSON *nwdaf_info_local_JSON = nwdaf_info_convertToJSON(nf_profile->nwdaf_info);
        if(nwdaf_info_local_JSON == NULL) {
            goto fail;
        }
        cJSON_AddItemToObject(item, "nwdafInfo", nwdaf_info_local_JSON);
        if(item->child == NULL) {
            goto fail;
        }
    }

    if (nf_profile->custom_info) {
        cJSON *custom_info_object = object_convertToJSON(nf_profile->custom_info);
        if(custom_info_object == NULL) {
            goto fail;
        }
        cJSON_AddItemToObject(item, "customInfo", custom_info_object);
        if(item->child == NULL) {
            goto fail;
        }
    }

    if (nf_profile->recovery_time) {
        if(cJSON_AddStringToObject(item, "recoveryTime", nf_profile->recovery_time) == NULL) {
            goto fail;
        }
    }

    if (nf_profile->nf_service_persistence) {
        if(cJSON_AddBoolToObject(item, "nfServicePersistence", nf_profile->nf_service_persistence) == NULL) {
            goto fail;
        }
    }

    if (nf_profile->nf_services) {
        cJSON *nf_services = cJSON_AddArrayToObject(item, "nfServices");
        if(nf_services == NULL) {
            goto fail;
        }

        listEntry_t *nf_servicesListEntry;
        if (nf_profile->nf_services) {
            list_ForEach(nf_servicesListEntry, nf_profile->nf_services) {
                cJSON *itemLocal = nf_service_convertToJSON(nf_servicesListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(nf_services, itemLocal);
            }
        }
    }

    if (nf_profile->nf_profile_changes_support_ind) {
        if(cJSON_AddBoolToObject(item, "nfProfileChangesSupportInd", nf_profile->nf_profile_changes_support_ind) == NULL) {
            goto fail;
        }
    }

    if (nf_profile->nf_profile_changes_ind) {
        if(cJSON_AddBoolToObject(item, "nfProfileChangesInd", nf_profile->nf_profile_changes_ind) == NULL) {
            goto fail;
        }
    }

    if (nf_profile->default_notification_subscriptions) {
        cJSON *default_notification_subscriptions = cJSON_AddArrayToObject(item, "defaultNotificationSubscriptions");
        if(default_notification_subscriptions == NULL) {
            goto fail;
        }

        listEntry_t *default_notification_subscriptionsListEntry;
        if (nf_profile->default_notification_subscriptions) {
            list_ForEach(default_notification_subscriptionsListEntry, nf_profile->default_notification_subscriptions) {
                cJSON *itemLocal = default_notification_subscription_convertToJSON(default_notification_subscriptionsListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(default_notification_subscriptions, itemLocal);
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

nf_profile_t *nf_profile_parseFromJSON(cJSON *nf_profileJSON)
{
    nf_profile_t *nf_profile_local_var = NULL;
    cJSON *nf_instance_id = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "nfInstanceId");
    if (!nf_instance_id) {
        goto end;
    }


    if(!cJSON_IsString(nf_instance_id))
    {
        goto end;
    }

    cJSON *nf_instance_name = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "nfInstanceName");

    if (nf_instance_name) {
        if(!cJSON_IsString(nf_instance_name))
        {
            goto end;
        }
    }

    cJSON *nf_type = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "nfType");
    if (!nf_type) {
        goto end;
    }

    nf_type_e nf_typeVariable;

    if(!cJSON_IsString(nf_type)) {
        goto end;
    }
    nf_typeVariable = nf_type_FromString(nf_type->valuestring);

    cJSON *nf_status = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "nfStatus");
    if (!nf_status) {
        goto end;
    }

    nf_status_e nf_statusVariable;

    if(!cJSON_IsString(nf_status)) {
        goto end;
    }
    nf_statusVariable = nf_status_FromString(nf_status->valuestring);

    cJSON *heart_beat_timer = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "heartBeatTimer");

    if (heart_beat_timer) {
        if(!cJSON_IsNumber(heart_beat_timer)) {
            goto end;
        }
    }

    cJSON *plmn_list = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "plmnList");

    list_t *plmn_listList;
    if (plmn_list) {
        cJSON *plmn_list_local_nonprimitive;
        if(!cJSON_IsArray(plmn_list)) {
            goto end;
        }

        plmn_listList = list_create();

        cJSON_ArrayForEach(plmn_list_local_nonprimitive,plmn_list ) {
            if(!cJSON_IsObject(plmn_list_local_nonprimitive)) {
                goto end;
            }
            plmn_id_t *plmn_listItem = plmn_id_parseFromJSON(plmn_list_local_nonprimitive);

            list_addElement(plmn_listList, plmn_listItem);
        }
    }

    cJSON *s_nssais = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "sNssais");

    list_t *s_nssaisList;
    if (s_nssais) {
        cJSON *s_nssais_local_nonprimitive;
        if(!cJSON_IsArray(s_nssais)) {
            goto end;
        }

        s_nssaisList = list_create();

        cJSON_ArrayForEach(s_nssais_local_nonprimitive,s_nssais ) {
            if(!cJSON_IsObject(s_nssais_local_nonprimitive)) {
                goto end;
            }
            snssai_t *s_nssaisItem = snssai_parseFromJSON(s_nssais_local_nonprimitive);

            list_addElement(s_nssaisList, s_nssaisItem);
        }
    }

    cJSON *per_plmn_snssai_list = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "perPlmnSnssaiList");

    list_t *per_plmn_snssai_listList;
    if (per_plmn_snssai_list) {
        cJSON *per_plmn_snssai_list_local_nonprimitive;
        if(!cJSON_IsArray(per_plmn_snssai_list)) {
            goto end;
        }

        per_plmn_snssai_listList = list_create();

        cJSON_ArrayForEach(per_plmn_snssai_list_local_nonprimitive,per_plmn_snssai_list ) {
            if(!cJSON_IsObject(per_plmn_snssai_list_local_nonprimitive)) {
                goto end;
            }
            plmn_snssai_t *per_plmn_snssai_listItem = plmn_snssai_parseFromJSON(per_plmn_snssai_list_local_nonprimitive);

            list_addElement(per_plmn_snssai_listList, per_plmn_snssai_listItem);
        }
    }

    cJSON *nsi_list = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "nsiList");

    list_t *nsi_listList;
    if (nsi_list) {
        cJSON *nsi_list_local;
        if(!cJSON_IsArray(nsi_list)) {
            goto end;
        }
        nsi_listList = list_create();

        cJSON_ArrayForEach(nsi_list_local, nsi_list) {
            if(!cJSON_IsString(nsi_list_local)) {
                goto end;
            }
            list_addElement(nsi_listList, ogs_strdup(nsi_list_local->valuestring));
        }
    }

    cJSON *fqdn = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "fqdn");

    if (fqdn) {
        if(!cJSON_IsString(fqdn))
        {
            goto end;
        }
    }

    cJSON *inter_plmn_fqdn = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "interPlmnFqdn");

    if (inter_plmn_fqdn) {
        if(!cJSON_IsString(inter_plmn_fqdn))
        {
            goto end;
        }
    }

    cJSON *ipv4_addresses = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "ipv4Addresses");

    list_t *ipv4_addressesList;
    if (ipv4_addresses) {
        cJSON *ipv4_addresses_local;
        if(!cJSON_IsArray(ipv4_addresses)) {
            goto end;
        }
        ipv4_addressesList = list_create();

        cJSON_ArrayForEach(ipv4_addresses_local, ipv4_addresses) {
            if(!cJSON_IsString(ipv4_addresses_local)) {
                goto end;
            }
            list_addElement(ipv4_addressesList, ogs_strdup(ipv4_addresses_local->valuestring));
        }
    }

    cJSON *ipv6_addresses = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "ipv6Addresses");

    list_t *ipv6_addressesList;
    if (ipv6_addresses) {
        cJSON *ipv6_addresses_local_nonprimitive;
        if(!cJSON_IsArray(ipv6_addresses)) {
            goto end;
        }

        ipv6_addressesList = list_create();

        cJSON_ArrayForEach(ipv6_addresses_local_nonprimitive,ipv6_addresses ) {
            if(!cJSON_IsObject(ipv6_addresses_local_nonprimitive)) {
                goto end;
            }
            ipv6_addr_t *ipv6_addressesItem = ipv6_addr_parseFromJSON(ipv6_addresses_local_nonprimitive);

            list_addElement(ipv6_addressesList, ipv6_addressesItem);
        }
    }

    cJSON *allowed_plmns = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "allowedPlmns");

    list_t *allowed_plmnsList;
    if (allowed_plmns) {
        cJSON *allowed_plmns_local_nonprimitive;
        if(!cJSON_IsArray(allowed_plmns)) {
            goto end;
        }

        allowed_plmnsList = list_create();

        cJSON_ArrayForEach(allowed_plmns_local_nonprimitive,allowed_plmns ) {
            if(!cJSON_IsObject(allowed_plmns_local_nonprimitive)) {
                goto end;
            }
            plmn_id_t *allowed_plmnsItem = plmn_id_parseFromJSON(allowed_plmns_local_nonprimitive);

            list_addElement(allowed_plmnsList, allowed_plmnsItem);
        }
    }

    cJSON *allowed_nf_types = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "allowedNfTypes");

    list_t *allowed_nf_typesList;
    if (allowed_nf_types) {
        cJSON *allowed_nf_types_local_nonprimitive;
        if(!cJSON_IsArray(allowed_nf_types)) {
            goto end;
        }

        allowed_nf_typesList = list_create();

        cJSON_ArrayForEach(allowed_nf_types_local_nonprimitive, allowed_nf_types ) {
            if(!cJSON_IsString(allowed_nf_types_local_nonprimitive)) {
                goto end;
            }

            list_addElement(allowed_nf_typesList, (void *)nf_type_FromString(allowed_nf_types_local_nonprimitive->valuestring));
        }
    }

    cJSON *allowed_nf_domains = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "allowedNfDomains");

    list_t *allowed_nf_domainsList;
    if (allowed_nf_domains) {
        cJSON *allowed_nf_domains_local;
        if(!cJSON_IsArray(allowed_nf_domains)) {
            goto end;
        }
        allowed_nf_domainsList = list_create();

        cJSON_ArrayForEach(allowed_nf_domains_local, allowed_nf_domains) {
            if(!cJSON_IsString(allowed_nf_domains_local)) {
                goto end;
            }
            list_addElement(allowed_nf_domainsList, ogs_strdup(allowed_nf_domains_local->valuestring));
        }
    }

    cJSON *allowed_nssais = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "allowedNssais");

    list_t *allowed_nssaisList;
    if (allowed_nssais) {
        cJSON *allowed_nssais_local_nonprimitive;
        if(!cJSON_IsArray(allowed_nssais)) {
            goto end;
        }

        allowed_nssaisList = list_create();

        cJSON_ArrayForEach(allowed_nssais_local_nonprimitive,allowed_nssais ) {
            if(!cJSON_IsObject(allowed_nssais_local_nonprimitive)) {
                goto end;
            }
            snssai_t *allowed_nssaisItem = snssai_parseFromJSON(allowed_nssais_local_nonprimitive);

            list_addElement(allowed_nssaisList, allowed_nssaisItem);
        }
    }

    cJSON *priority = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "priority");

    if (priority) {
        if(!cJSON_IsNumber(priority)) {
            goto end;
        }
    }

    cJSON *capacity = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "capacity");

    if (capacity) {
        if(!cJSON_IsNumber(capacity)) {
            goto end;
        }
    }

    cJSON *load = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "load");

    if (load) {
        if(!cJSON_IsNumber(load)) {
            goto end;
        }
    }

    cJSON *locality = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "locality");

    if (locality) {
        if(!cJSON_IsString(locality))
        {
            goto end;
        }
    }

    cJSON *udr_info = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "udrInfo");

    udr_info_t *udr_info_local_nonprim = NULL;
    if (udr_info) {
        udr_info_local_nonprim = udr_info_parseFromJSON(udr_info);
    }

    cJSON *udr_info_ext = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "udrInfoExt");

    list_t *udr_info_extList;
    if (udr_info_ext) {
        cJSON *udr_info_ext_local_nonprimitive;
        if(!cJSON_IsArray(udr_info_ext)) {
            goto end;
        }

        udr_info_extList = list_create();

        cJSON_ArrayForEach(udr_info_ext_local_nonprimitive,udr_info_ext ) {
            if(!cJSON_IsObject(udr_info_ext_local_nonprimitive)) {
                goto end;
            }
            udr_info_t *udr_info_extItem = udr_info_parseFromJSON(udr_info_ext_local_nonprimitive);

            list_addElement(udr_info_extList, udr_info_extItem);
        }
    }

    cJSON *udm_info = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "udmInfo");

    udm_info_t *udm_info_local_nonprim = NULL;
    if (udm_info) {
        udm_info_local_nonprim = udm_info_parseFromJSON(udm_info);
    }

    cJSON *udm_info_ext = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "udmInfoExt");

    list_t *udm_info_extList;
    if (udm_info_ext) {
        cJSON *udm_info_ext_local_nonprimitive;
        if(!cJSON_IsArray(udm_info_ext)) {
            goto end;
        }

        udm_info_extList = list_create();

        cJSON_ArrayForEach(udm_info_ext_local_nonprimitive,udm_info_ext ) {
            if(!cJSON_IsObject(udm_info_ext_local_nonprimitive)) {
                goto end;
            }
            udm_info_t *udm_info_extItem = udm_info_parseFromJSON(udm_info_ext_local_nonprimitive);

            list_addElement(udm_info_extList, udm_info_extItem);
        }
    }

    cJSON *ausf_info = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "ausfInfo");

    ausf_info_t *ausf_info_local_nonprim = NULL;
    if (ausf_info) {
        ausf_info_local_nonprim = ausf_info_parseFromJSON(ausf_info);
    }

    cJSON *ausf_info_ext = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "ausfInfoExt");

    list_t *ausf_info_extList;
    if (ausf_info_ext) {
        cJSON *ausf_info_ext_local_nonprimitive;
        if(!cJSON_IsArray(ausf_info_ext)) {
            goto end;
        }

        ausf_info_extList = list_create();

        cJSON_ArrayForEach(ausf_info_ext_local_nonprimitive,ausf_info_ext ) {
            if(!cJSON_IsObject(ausf_info_ext_local_nonprimitive)) {
                goto end;
            }
            ausf_info_t *ausf_info_extItem = ausf_info_parseFromJSON(ausf_info_ext_local_nonprimitive);

            list_addElement(ausf_info_extList, ausf_info_extItem);
        }
    }

    cJSON *amf_info = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "amfInfo");

    amf_info_t *amf_info_local_nonprim = NULL;
    if (amf_info) {
        amf_info_local_nonprim = amf_info_parseFromJSON(amf_info);
    }

    cJSON *amf_info_ext = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "amfInfoExt");

    list_t *amf_info_extList;
    if (amf_info_ext) {
        cJSON *amf_info_ext_local_nonprimitive;
        if(!cJSON_IsArray(amf_info_ext)) {
            goto end;
        }

        amf_info_extList = list_create();

        cJSON_ArrayForEach(amf_info_ext_local_nonprimitive,amf_info_ext ) {
            if(!cJSON_IsObject(amf_info_ext_local_nonprimitive)) {
                goto end;
            }
            amf_info_t *amf_info_extItem = amf_info_parseFromJSON(amf_info_ext_local_nonprimitive);

            list_addElement(amf_info_extList, amf_info_extItem);
        }
    }

    cJSON *smf_info = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "smfInfo");

    smf_info_t *smf_info_local_nonprim = NULL;
    if (smf_info) {
        smf_info_local_nonprim = smf_info_parseFromJSON(smf_info);
    }

    cJSON *smf_info_ext = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "smfInfoExt");

    list_t *smf_info_extList;
    if (smf_info_ext) {
        cJSON *smf_info_ext_local_nonprimitive;
        if(!cJSON_IsArray(smf_info_ext)) {
            goto end;
        }

        smf_info_extList = list_create();

        cJSON_ArrayForEach(smf_info_ext_local_nonprimitive,smf_info_ext ) {
            if(!cJSON_IsObject(smf_info_ext_local_nonprimitive)) {
                goto end;
            }
            smf_info_t *smf_info_extItem = smf_info_parseFromJSON(smf_info_ext_local_nonprimitive);

            list_addElement(smf_info_extList, smf_info_extItem);
        }
    }

    cJSON *upf_info = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "upfInfo");

    upf_info_t *upf_info_local_nonprim = NULL;
    if (upf_info) {
        upf_info_local_nonprim = upf_info_parseFromJSON(upf_info);
    }

    cJSON *upf_info_ext = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "upfInfoExt");

    list_t *upf_info_extList;
    if (upf_info_ext) {
        cJSON *upf_info_ext_local_nonprimitive;
        if(!cJSON_IsArray(upf_info_ext)) {
            goto end;
        }

        upf_info_extList = list_create();

        cJSON_ArrayForEach(upf_info_ext_local_nonprimitive,upf_info_ext ) {
            if(!cJSON_IsObject(upf_info_ext_local_nonprimitive)) {
                goto end;
            }
            upf_info_t *upf_info_extItem = upf_info_parseFromJSON(upf_info_ext_local_nonprimitive);

            list_addElement(upf_info_extList, upf_info_extItem);
        }
    }

    cJSON *pcf_info = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "pcfInfo");

    pcf_info_t *pcf_info_local_nonprim = NULL;
    if (pcf_info) {
        pcf_info_local_nonprim = pcf_info_parseFromJSON(pcf_info);
    }

    cJSON *pcf_info_ext = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "pcfInfoExt");

    list_t *pcf_info_extList;
    if (pcf_info_ext) {
        cJSON *pcf_info_ext_local_nonprimitive;
        if(!cJSON_IsArray(pcf_info_ext)) {
            goto end;
        }

        pcf_info_extList = list_create();

        cJSON_ArrayForEach(pcf_info_ext_local_nonprimitive,pcf_info_ext ) {
            if(!cJSON_IsObject(pcf_info_ext_local_nonprimitive)) {
                goto end;
            }
            pcf_info_t *pcf_info_extItem = pcf_info_parseFromJSON(pcf_info_ext_local_nonprimitive);

            list_addElement(pcf_info_extList, pcf_info_extItem);
        }
    }

    cJSON *bsf_info = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "bsfInfo");

    bsf_info_t *bsf_info_local_nonprim = NULL;
    if (bsf_info) {
        bsf_info_local_nonprim = bsf_info_parseFromJSON(bsf_info);
    }

    cJSON *bsf_info_ext = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "bsfInfoExt");

    list_t *bsf_info_extList;
    if (bsf_info_ext) {
        cJSON *bsf_info_ext_local_nonprimitive;
        if(!cJSON_IsArray(bsf_info_ext)) {
            goto end;
        }

        bsf_info_extList = list_create();

        cJSON_ArrayForEach(bsf_info_ext_local_nonprimitive,bsf_info_ext ) {
            if(!cJSON_IsObject(bsf_info_ext_local_nonprimitive)) {
                goto end;
            }
            bsf_info_t *bsf_info_extItem = bsf_info_parseFromJSON(bsf_info_ext_local_nonprimitive);

            list_addElement(bsf_info_extList, bsf_info_extItem);
        }
    }

    cJSON *chf_info = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "chfInfo");

    chf_info_t *chf_info_local_nonprim = NULL;
    if (chf_info) {
        chf_info_local_nonprim = chf_info_parseFromJSON(chf_info);
    }

    cJSON *chf_info_ext = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "chfInfoExt");

    list_t *chf_info_extList;
    if (chf_info_ext) {
        cJSON *chf_info_ext_local_nonprimitive;
        if(!cJSON_IsArray(chf_info_ext)) {
            goto end;
        }

        chf_info_extList = list_create();

        cJSON_ArrayForEach(chf_info_ext_local_nonprimitive,chf_info_ext ) {
            if(!cJSON_IsObject(chf_info_ext_local_nonprimitive)) {
                goto end;
            }
            chf_info_t *chf_info_extItem = chf_info_parseFromJSON(chf_info_ext_local_nonprimitive);

            list_addElement(chf_info_extList, chf_info_extItem);
        }
    }

    cJSON *nrf_info = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "nrfInfo");

    nrf_info_t *nrf_info_local_nonprim = NULL;
    if (nrf_info) {
        nrf_info_local_nonprim = nrf_info_parseFromJSON(nrf_info);
    }

    cJSON *nwdaf_info = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "nwdafInfo");

    nwdaf_info_t *nwdaf_info_local_nonprim = NULL;
    if (nwdaf_info) {
        nwdaf_info_local_nonprim = nwdaf_info_parseFromJSON(nwdaf_info);
    }

    cJSON *custom_info = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "customInfo");

    object_t *custom_info_local_object = NULL;
    if (custom_info) {
        custom_info_local_object = object_parseFromJSON(custom_info);
    }

    cJSON *recovery_time = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "recoveryTime");

    if (recovery_time) {
        if(!cJSON_IsString(recovery_time)) {
            goto end;
        }
    }

    cJSON *nf_service_persistence = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "nfServicePersistence");

    if (nf_service_persistence) {
        if(!cJSON_IsBool(nf_service_persistence)) {
            goto end;
        }
    }

    cJSON *nf_services = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "nfServices");

    list_t *nf_servicesList;
    if (nf_services) {
        cJSON *nf_services_local_nonprimitive;
        if(!cJSON_IsArray(nf_services)) {
            goto end;
        }

        nf_servicesList = list_create();

        cJSON_ArrayForEach(nf_services_local_nonprimitive,nf_services ) {
            if(!cJSON_IsObject(nf_services_local_nonprimitive)) {
                goto end;
            }
            nf_service_t *nf_servicesItem = nf_service_parseFromJSON(nf_services_local_nonprimitive);

            list_addElement(nf_servicesList, nf_servicesItem);
        }
    }

    cJSON *nf_profile_changes_support_ind = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "nfProfileChangesSupportInd");

    if (nf_profile_changes_support_ind) {
        if(!cJSON_IsBool(nf_profile_changes_support_ind)) {
            goto end;
        }
    }

    cJSON *nf_profile_changes_ind = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "nfProfileChangesInd");

    if (nf_profile_changes_ind) {
        if(!cJSON_IsBool(nf_profile_changes_ind)) {
            goto end;
        }
    }

    cJSON *default_notification_subscriptions = cJSON_GetObjectItemCaseSensitive(nf_profileJSON, "defaultNotificationSubscriptions");

    list_t *default_notification_subscriptionsList;
    if (default_notification_subscriptions) {
        cJSON *default_notification_subscriptions_local_nonprimitive;
        if(!cJSON_IsArray(default_notification_subscriptions)) {
            goto end;
        }

        default_notification_subscriptionsList = list_create();

        cJSON_ArrayForEach(default_notification_subscriptions_local_nonprimitive,default_notification_subscriptions ) {
            if(!cJSON_IsObject(default_notification_subscriptions_local_nonprimitive)) {
                goto end;
            }
            default_notification_subscription_t *default_notification_subscriptionsItem = default_notification_subscription_parseFromJSON(default_notification_subscriptions_local_nonprimitive);

            list_addElement(default_notification_subscriptionsList, default_notification_subscriptionsItem);
        }
    }

    nf_profile_local_var = nf_profile_create (
        ogs_strdup(nf_instance_id->valuestring),
        nf_instance_name ? ogs_strdup(nf_instance_name->valuestring) : NULL,
        nf_typeVariable,
        nf_statusVariable,
        heart_beat_timer ? heart_beat_timer->valuedouble : 0,
        plmn_list ? plmn_listList : NULL,
        s_nssais ? s_nssaisList : NULL,
        per_plmn_snssai_list ? per_plmn_snssai_listList : NULL,
        nsi_list ? nsi_listList : NULL,
        fqdn ? ogs_strdup(fqdn->valuestring) : NULL,
        inter_plmn_fqdn ? ogs_strdup(inter_plmn_fqdn->valuestring) : NULL,
        ipv4_addresses ? ipv4_addressesList : NULL,
        ipv6_addresses ? ipv6_addressesList : NULL,
        allowed_plmns ? allowed_plmnsList : NULL,
        allowed_nf_types ? allowed_nf_typesList : NULL,
        allowed_nf_domains ? allowed_nf_domainsList : NULL,
        allowed_nssais ? allowed_nssaisList : NULL,
        priority ? priority->valuedouble : 0,
        capacity ? capacity->valuedouble : 0,
        load ? load->valuedouble : 0,
        locality ? ogs_strdup(locality->valuestring) : NULL,
        udr_info ? udr_info_local_nonprim : NULL,
        udr_info_ext ? udr_info_extList : NULL,
        udm_info ? udm_info_local_nonprim : NULL,
        udm_info_ext ? udm_info_extList : NULL,
        ausf_info ? ausf_info_local_nonprim : NULL,
        ausf_info_ext ? ausf_info_extList : NULL,
        amf_info ? amf_info_local_nonprim : NULL,
        amf_info_ext ? amf_info_extList : NULL,
        smf_info ? smf_info_local_nonprim : NULL,
        smf_info_ext ? smf_info_extList : NULL,
        upf_info ? upf_info_local_nonprim : NULL,
        upf_info_ext ? upf_info_extList : NULL,
        pcf_info ? pcf_info_local_nonprim : NULL,
        pcf_info_ext ? pcf_info_extList : NULL,
        bsf_info ? bsf_info_local_nonprim : NULL,
        bsf_info_ext ? bsf_info_extList : NULL,
        chf_info ? chf_info_local_nonprim : NULL,
        chf_info_ext ? chf_info_extList : NULL,
        nrf_info ? nrf_info_local_nonprim : NULL,
        nwdaf_info ? nwdaf_info_local_nonprim : NULL,
        custom_info ? custom_info_local_object : NULL,
        recovery_time ? ogs_strdup(recovery_time->valuestring) : NULL,
        nf_service_persistence ? nf_service_persistence->valueint : 0,
        nf_services ? nf_servicesList : NULL,
        nf_profile_changes_support_ind ? nf_profile_changes_support_ind->valueint : 0,
        nf_profile_changes_ind ? nf_profile_changes_ind->valueint : 0,
        default_notification_subscriptions ? default_notification_subscriptionsList : NULL
        );

    return nf_profile_local_var;
end:
    return NULL;
}

