/*
 * chf_service_info.h
 *
 * 
 */

#ifndef _chf_service_info_H_
#define _chf_service_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chf_service_info_t chf_service_info_t;




typedef struct chf_service_info_t {
    char *primary_chf_service_instance; // string
    char *secondary_chf_service_instance; // string

} chf_service_info_t;

chf_service_info_t *chf_service_info_create(
    char *primary_chf_service_instance,
    char *secondary_chf_service_instance
);

void chf_service_info_free(chf_service_info_t *chf_service_info);

chf_service_info_t *chf_service_info_parseFromJSON(cJSON *chf_service_infoJSON);

cJSON *chf_service_info_convertToJSON(chf_service_info_t *chf_service_info);

#endif /* _chf_service_info_H_ */

