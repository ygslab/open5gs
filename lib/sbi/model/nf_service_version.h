/*
 * nf_service_version.h
 *
 * 
 */

#ifndef _nf_service_version_H_
#define _nf_service_version_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct nf_service_version_t nf_service_version_t;




typedef struct nf_service_version_t {
    char *api_version_in_uri; // string
    char *api_full_version; // string
    char *expiry; //date time

} nf_service_version_t;

nf_service_version_t *nf_service_version_create(
    char *api_version_in_uri,
    char *api_full_version,
    char *expiry
);

void nf_service_version_free(nf_service_version_t *nf_service_version);

nf_service_version_t *nf_service_version_parseFromJSON(cJSON *nf_service_versionJSON);

cJSON *nf_service_version_convertToJSON(nf_service_version_t *nf_service_version);

#endif /* _nf_service_version_H_ */

