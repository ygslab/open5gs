/*
 * nf_group_cond.h
 *
 * 
 */

#ifndef _nf_group_cond_H_
#define _nf_group_cond_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct nf_group_cond_t nf_group_cond_t;


// Enum NFTYPE for nf_group_cond

typedef enum  { nrf_nfmanagement_service_nf_group_cond_NFTYPE_NULL = 0, nrf_nfmanagement_service_nf_group_cond_NFTYPE_UDM, nrf_nfmanagement_service_nf_group_cond_NFTYPE_AUSF, nrf_nfmanagement_service_nf_group_cond_NFTYPE_UDR, nrf_nfmanagement_service_nf_group_cond_NFTYPE_PCF } nrf_nfmanagement_service_nf_group_cond_NFTYPE_e;

char* nf_group_cond_nf_type_ToString(nrf_nfmanagement_service_nf_group_cond_NFTYPE_e nf_type);

nrf_nfmanagement_service_nf_group_cond_NFTYPE_e nf_group_cond_nf_type_FromString(char* nf_type);



typedef struct nf_group_cond_t {
    nrf_nfmanagement_service_nf_group_cond_NFTYPE_e nf_type; //enum
    char *nf_group_id; // string

} nf_group_cond_t;

nf_group_cond_t *nf_group_cond_create(
    nrf_nfmanagement_service_nf_group_cond_NFTYPE_e nf_type,
    char *nf_group_id
);

void nf_group_cond_free(nf_group_cond_t *nf_group_cond);

nf_group_cond_t *nf_group_cond_parseFromJSON(cJSON *nf_group_condJSON);

cJSON *nf_group_cond_convertToJSON(nf_group_cond_t *nf_group_cond);

#endif /* _nf_group_cond_H_ */

