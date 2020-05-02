/*
 * nf_profile.h
 *
 *
 */

#ifndef _nf_profile_H_
#define _nf_profile_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "amf_info.h"
#include "ausf_info.h"
#include "bsf_info.h"
#include "chf_info.h"
#include "default_notification_subscription.h"
#include "ipv6_addr.h"
#include "nf_service.h"
#include "nf_status.h"
#include "nf_type.h"
#include "nrf_info.h"
#include "nwdaf_info.h"
#include "object.h"
#include "pcf_info.h"
#include "plmn_id.h"
#include "plmn_snssai.h"
#include "smf_info.h"
#include "snssai.h"
#include "udm_info.h"
#include "udr_info.h"
#include "upf_info.h"

typedef struct nf_profile_t nf_profile_t;
typedef struct nf_profile_t {
    char *nf_instance_id;
    char *nf_instance_name;
    nf_type_e nf_type;
    nf_status_e nf_status;
    int heart_beat_timer;
    list_t *plmn_list;
    list_t *s_nssais;
    list_t *per_plmn_snssai_list;
    list_t *nsi_list;
    char *fqdn;
    char *inter_plmn_fqdn;
    list_t *ipv4_addresses;
    list_t *ipv6_addresses;
    list_t *allowed_plmns;
    list_t *allowed_nf_types;
    list_t *allowed_nf_domains;
    list_t *allowed_nssais;
    int priority;
    int capacity;
    int load;
    char *locality;
    struct udr_info_t *udr_info;
    list_t *udr_info_ext;
    struct udm_info_t *udm_info;
    list_t *udm_info_ext;
    struct ausf_info_t *ausf_info;
    list_t *ausf_info_ext;
    struct amf_info_t *amf_info;
    list_t *amf_info_ext;
    struct smf_info_t *smf_info;
    list_t *smf_info_ext;
    struct upf_info_t *upf_info;
    list_t *upf_info_ext;
    struct pcf_info_t *pcf_info;
    list_t *pcf_info_ext;
    struct bsf_info_t *bsf_info;
    list_t *bsf_info_ext;
    struct chf_info_t *chf_info;
    list_t *chf_info_ext;
    struct nrf_info_t *nrf_info;
    struct nwdaf_info_t *nwdaf_info;
    object_t *custom_info;
    char *recovery_time;
    int nf_service_persistence;
    list_t *nf_services;
    int nf_profile_changes_support_ind;
    int nf_profile_changes_ind;
    list_t *default_notification_subscriptions;
} nf_profile_t;

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
    );
void nf_profile_free(nf_profile_t *nf_profile);
nf_profile_t *nf_profile_parseFromJSON(cJSON *nf_profileJSON);
cJSON *nf_profile_convertToJSON(nf_profile_t *nf_profile);
#endif /* _nf_profile_H_ */

