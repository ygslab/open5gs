/*
 * nf_type_cond.h
 *
 * 
 */

#ifndef _nf_type_cond_H_
#define _nf_type_cond_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct nf_type_cond_t nf_type_cond_t;




typedef struct nf_type_cond_t {
    char *nf_type; // string

} nf_type_cond_t;

nf_type_cond_t *nf_type_cond_create(
    char *nf_type
);

void nf_type_cond_free(nf_type_cond_t *nf_type_cond);

nf_type_cond_t *nf_type_cond_parseFromJSON(cJSON *nf_type_condJSON);

cJSON *nf_type_cond_convertToJSON(nf_type_cond_t *nf_type_cond);

#endif /* _nf_type_cond_H_ */

