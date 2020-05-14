/*
 * notification_type.h
 *
 *
 */

#ifndef _ogs_sbi_notification_type_H_
#define _ogs_sbi_notification_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { ogs_sbi_notification_type_NULL = 0, ogs_sbi_notification_type_N1_MESSAGES, ogs_sbi_notification_type_N2_INFORMATION, ogs_sbi_notification_type_LOCATION_NOTIFICATION, ogs_sbi_notification_type_DATA_REMOVAL_NOTIFICATION, ogs_sbi_notification_type_DATA_CHANGE_NOTIFICATION } ogs_sbi_notification_type_e;

char* ogs_sbi_notification_type_ToString(ogs_sbi_notification_type_e notification_type);

ogs_sbi_notification_type_e ogs_sbi_notification_type_FromString(char* notification_type);

#ifdef __cplusplus
}
#endif

#endif /* _ogs_sbi_notification_type_H_ */

