/*
 * n1_message_class.h
 *
 *
 */

#ifndef _ogs_sbi_n1_message_class_H_
#define _ogs_sbi_n1_message_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { ogs_sbi_n1_message_class_NULL = 0, ogs_sbi_n1_message_class_5GMM, ogs_sbi_n1_message_class_SM, ogs_sbi_n1_message_class_LPP, ogs_sbi_n1_message_class_SMS, ogs_sbi_n1_message_class_UPDP } ogs_sbi_n1_message_class_e;

char* ogs_sbi_n1_message_class_ToString(ogs_sbi_n1_message_class_e n1_message_class);

ogs_sbi_n1_message_class_e ogs_sbi_n1_message_class_FromString(char* n1_message_class);

#ifdef __cplusplus
}
#endif

#endif /* _ogs_sbi_n1_message_class_H_ */

