/*
 * notification_event_type.h
 *
 *
 */

#ifndef _ogs_sbi_notification_event_type_H_
#define _ogs_sbi_notification_event_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { ogs_sbi_notification_event_type_NULL = 0, ogs_sbi_notification_event_type_NF_REGISTERED, ogs_sbi_notification_event_type_NF_DEREGISTERED, ogs_sbi_notification_event_type_NF_PROFILE_CHANGED } ogs_sbi_notification_event_type_e;

char* ogs_sbi_notification_event_type_ToString(ogs_sbi_notification_event_type_e notification_event_type);

ogs_sbi_notification_event_type_e ogs_sbi_notification_event_type_FromString(char* notification_event_type);

#ifdef __cplusplus
}
#endif

#endif /* _ogs_sbi_notification_event_type_H_ */

