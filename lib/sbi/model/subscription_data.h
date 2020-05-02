/*
 * subscription_data.h
 *
 *
 */

#ifndef _subscription_data_H_
#define _subscription_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "nf_type.h"
#include "notif_condition.h"
#include "notification_event_type.h"
#include "plmn_id.h"
#include "snssai.h"

typedef struct subscription_data_t subscription_data_t;
typedef struct subscription_data_t {
    char *nf_status_notification_uri;
    char *req_nf_instance_id;
    char *subscription_id;
    char *validity_time;
    list_t *req_notif_events;
    struct plmn_id_t *plmn_id;
    struct notif_condition_t *notif_condition;
    nf_type_e req_nf_type;
    char *req_nf_fqdn;
    list_t *req_snssais;
} subscription_data_t;

subscription_data_t *subscription_data_create(
    char *nf_status_notification_uri,
    char *req_nf_instance_id,
    char *subscription_id,
    char *validity_time,
    list_t *req_notif_events,
    plmn_id_t *plmn_id,
    notif_condition_t *notif_condition,
    nf_type_e req_nf_type,
    char *req_nf_fqdn,
    list_t *req_snssais
    );
void subscription_data_free(subscription_data_t *subscription_data);
subscription_data_t *subscription_data_parseFromJSON(cJSON *subscription_dataJSON);
cJSON *subscription_data_convertToJSON(subscription_data_t *subscription_data);
#endif /* _subscription_data_H_ */

