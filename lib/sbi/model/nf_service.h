/*
 * nf_service.h
 *
 *
 */

#ifndef _nf_service_H_
#define _nf_service_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "chf_service_info.h"
#include "default_notification_subscription.h"
#include "ip_end_point.h"
#include "nf_service_status.h"
#include "nf_service_version.h"
#include "nf_type.h"
#include "plmn_id.h"
#include "service_name.h"
#include "snssai.h"
#include "uri_scheme.h"

typedef struct nf_service_t nf_service_t;
typedef struct nf_service_t {
    char *service_instance_id;
    struct service_name_t *service_name;
    list_t *versions;
    struct uri_scheme_t *scheme;
    struct nf_service_status_t *nf_service_status;
    char *fqdn;
    char *inter_plmn_fqdn;
    list_t *ip_end_points;
    char *api_prefix;
    list_t *default_notification_subscriptions;
    list_t *allowed_plmns;
    list_t *allowed_nf_types;
    list_t *allowed_nf_domains;
    list_t *allowed_nssais;
    int priority;
    int capacity;
    int load;
    char *recovery_time;
    struct chf_service_info_t *chf_service_info;
    char *supported_features;
} nf_service_t;

nf_service_t *nf_service_create(
    char *service_instance_id,
    service_name_t *service_name,
    list_t *versions,
    uri_scheme_t *scheme,
    nf_service_status_t *nf_service_status,
    char *fqdn,
    char *inter_plmn_fqdn,
    list_t *ip_end_points,
    char *api_prefix,
    list_t *default_notification_subscriptions,
    list_t *allowed_plmns,
    list_t *allowed_nf_types,
    list_t *allowed_nf_domains,
    list_t *allowed_nssais,
    int priority,
    int capacity,
    int load,
    char *recovery_time,
    chf_service_info_t *chf_service_info,
    char *supported_features
    );
void nf_service_free(nf_service_t *nf_service);
nf_service_t *nf_service_parseFromJSON(cJSON *nf_serviceJSON);
cJSON *nf_service_convertToJSON(nf_service_t *nf_service);
#endif /* _nf_service_H_ */

