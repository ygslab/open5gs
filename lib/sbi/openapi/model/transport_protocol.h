/*
 * transport_protocol.h
 *
 *
 */

#ifndef _ogs_sbi_transport_protocol_H_
#define _ogs_sbi_transport_protocol_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { ogs_sbi_transport_protocol_NULL = 0, ogs_sbi_transport_protocol_TCP } ogs_sbi_transport_protocol_e;

char* ogs_sbi_transport_protocol_ToString(ogs_sbi_transport_protocol_e transport_protocol);

ogs_sbi_transport_protocol_e ogs_sbi_transport_protocol_FromString(char* transport_protocol);

#ifdef __cplusplus
}
#endif

#endif /* _ogs_sbi_transport_protocol_H_ */

