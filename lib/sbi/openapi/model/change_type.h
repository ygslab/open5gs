/*
 * change_type.h
 *
 *
 */

#ifndef _ogs_sbi_change_type_H_
#define _ogs_sbi_change_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { ogs_sbi_change_type_NULL = 0, ogs_sbi_change_type_ADD, ogs_sbi_change_type_MOVE, ogs_sbi_change_type__REMOVE, ogs_sbi_change_type_REPLACE } ogs_sbi_change_type_e;

char* ogs_sbi_change_type_ToString(ogs_sbi_change_type_e change_type);

ogs_sbi_change_type_e ogs_sbi_change_type_FromString(char* change_type);

#ifdef __cplusplus
}
#endif

#endif /* _ogs_sbi_change_type_H_ */

