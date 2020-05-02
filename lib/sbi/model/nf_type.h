/*
 * nf_type.h
 *
 *
 */

#ifndef _nf_type_H_
#define _nf_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef enum { nf_type_NULL = 0, nf_type_NRF, nf_type_UDM, nf_type_AMF, nf_type_SMF, nf_type_AUSF, nf_type_NEF, nf_type_PCF, nf_type_SMSF, nf_type_NSSF, nf_type_UDR, nf_type_LMF, nf_type_GMLC, nf_type_5G_EIR, nf_type_SEPP, nf_type_UPF, nf_type_N3IWF, nf_type_AF, nf_type_UDSF, nf_type_BSF, nf_type_CHF, nf_type_NWDAF } nf_type_e;

char* nf_type_ToString(nf_type_e nf_type);

nf_type_e nf_type_FromString(char* nf_type);
#endif /* _nf_type_H_ */

