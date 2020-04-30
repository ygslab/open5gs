/*
 * up_interface_type.h
 *
 * 
 */

#ifndef _up_interface_type_H_
#define _up_interface_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct up_interface_type_t up_interface_type_t;




typedef struct up_interface_type_t {

} up_interface_type_t;

up_interface_type_t *up_interface_type_create(
);

void up_interface_type_free(up_interface_type_t *up_interface_type);

up_interface_type_t *up_interface_type_parseFromJSON(cJSON *up_interface_typeJSON);

cJSON *up_interface_type_convertToJSON(up_interface_type_t *up_interface_type);

#endif /* _up_interface_type_H_ */

