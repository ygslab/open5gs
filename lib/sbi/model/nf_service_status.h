/*
 * nf_service_status.h
 *
 *
 */

#ifndef _nf_service_status_H_
#define _nf_service_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct nf_service_status_t nf_service_status_t;
typedef struct nf_service_status_t {
} nf_service_status_t;

nf_service_status_t *nf_service_status_create(
    );
void nf_service_status_free(nf_service_status_t *nf_service_status);
nf_service_status_t *nf_service_status_parseFromJSON(cJSON *nf_service_statusJSON);
cJSON *nf_service_status_convertToJSON(nf_service_status_t *nf_service_status);
#endif /* _nf_service_status_H_ */

