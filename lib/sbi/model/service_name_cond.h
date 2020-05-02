/*
 * service_name_cond.h
 *
 *
 */

#ifndef _service_name_cond_H_
#define _service_name_cond_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "service_name.h"

typedef struct service_name_cond_t service_name_cond_t;
typedef struct service_name_cond_t {
    struct service_name_t *service_name;
} service_name_cond_t;

service_name_cond_t *service_name_cond_create(
    service_name_t *service_name
    );
void service_name_cond_free(service_name_cond_t *service_name_cond);
service_name_cond_t *service_name_cond_parseFromJSON(cJSON *service_name_condJSON);
cJSON *service_name_cond_convertToJSON(service_name_cond_t *service_name_cond);
#endif /* _service_name_cond_H_ */

