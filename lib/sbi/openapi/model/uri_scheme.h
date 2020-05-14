/*
 * uri_scheme.h
 *
 *
 */

#ifndef _ogs_sbi_uri_scheme_H_
#define _ogs_sbi_uri_scheme_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { ogs_sbi_uri_scheme_NULL = 0, ogs_sbi_uri_scheme_http, ogs_sbi_uri_scheme_https } ogs_sbi_uri_scheme_e;

char* ogs_sbi_uri_scheme_ToString(ogs_sbi_uri_scheme_e uri_scheme);

ogs_sbi_uri_scheme_e ogs_sbi_uri_scheme_FromString(char* uri_scheme);

#ifdef __cplusplus
}
#endif

#endif /* _ogs_sbi_uri_scheme_H_ */

