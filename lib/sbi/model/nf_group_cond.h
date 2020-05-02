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
typedef enum { nf_group_cond_NFTYPE_NULL = 0, nf_group_cond_NFTYPE_UDM, nf_group_cond_NFTYPE_AUSF, nf_group_cond_NFTYPE_UDR, nf_group_cond_NFTYPE_PCF } nf_group_cond_nf_type_e;

char* nf_group_cond_nf_type_ToString(nf_group_cond_nf_type_e nf_type);

nf_group_cond_nf_type_e nf_group_cond_nf_type_FromString(char* nf_type);
typedef struct nf_group_cond_t {
    nf_group_cond_nf_type_e nf_type;
    char *nf_group_id;
} nf_group_cond_t;

nf_group_cond_t *nf_group_cond_create(
    nf_group_cond_nf_type_e nf_type,
    char *nf_group_id
    );
void nf_group_cond_free(nf_group_cond_t *nf_group_cond);
nf_group_cond_t *nf_group_cond_parseFromJSON(cJSON *nf_group_condJSON);
cJSON *nf_group_cond_convertToJSON(nf_group_cond_t *nf_group_cond);
#endif /* _nf_group_cond_H_ */

