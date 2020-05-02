/*
 * nf_instance_id_cond.h
 *
 *
 */

#ifndef _nf_instance_id_cond_H_
#define _nf_instance_id_cond_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct nf_instance_id_cond_t nf_instance_id_cond_t;
typedef struct nf_instance_id_cond_t {
    char *nf_instance_id;
} nf_instance_id_cond_t;

nf_instance_id_cond_t *nf_instance_id_cond_create(
    char *nf_instance_id
    );
void nf_instance_id_cond_free(nf_instance_id_cond_t *nf_instance_id_cond);
nf_instance_id_cond_t *nf_instance_id_cond_parseFromJSON(cJSON *nf_instance_id_condJSON);
cJSON *nf_instance_id_cond_convertToJSON(nf_instance_id_cond_t *nf_instance_id_cond);
#endif /* _nf_instance_id_cond_H_ */

