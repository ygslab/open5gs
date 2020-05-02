/*
 * service_name.h
 *
 *
 */

#ifndef _service_name_H_
#define _service_name_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct service_name_t service_name_t;
typedef struct service_name_t {
} service_name_t;

service_name_t *service_name_create(
    );
void service_name_free(service_name_t *service_name);
service_name_t *service_name_parseFromJSON(cJSON *service_nameJSON);
cJSON *service_name_convertToJSON(service_name_t *service_name);
#endif /* _service_name_H_ */

