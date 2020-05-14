/*
 * patch_operation.h
 *
 *
 */

#ifndef _ogs_sbi_patch_operation_H_
#define _ogs_sbi_patch_operation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { ogs_sbi_patch_operation_NULL = 0, ogs_sbi_patch_operation_add, ogs_sbi_patch_operation_copy, ogs_sbi_patch_operation_move, ogs_sbi_patch_operation__remove, ogs_sbi_patch_operation_replace, ogs_sbi_patch_operation_test } ogs_sbi_patch_operation_e;

char* ogs_sbi_patch_operation_ToString(ogs_sbi_patch_operation_e patch_operation);

ogs_sbi_patch_operation_e ogs_sbi_patch_operation_FromString(char* patch_operation);

#ifdef __cplusplus
}
#endif

#endif /* _ogs_sbi_patch_operation_H_ */

