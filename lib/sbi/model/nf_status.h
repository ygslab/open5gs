/*
 * nf_status.h
 *
 *
 */

#ifndef _nf_status_H_
#define _nf_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef enum { nf_status_NULL = 0, nf_status_REGISTERED, nf_status_SUSPENDED, nf_status_UNDISCOVERABLE } nf_status_e;

char* nf_status_ToString(nf_status_e nf_status);

nf_status_e nf_status_FromString(char* nf_status);
#endif /* _nf_status_H_ */

