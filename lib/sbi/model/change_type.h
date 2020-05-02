/*
 * change_type.h
 *
 *
 */

#ifndef _change_type_H_
#define _change_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct change_type_t change_type_t;
typedef struct change_type_t {
} change_type_t;

change_type_t *change_type_create(
    );
void change_type_free(change_type_t *change_type);
change_type_t *change_type_parseFromJSON(cJSON *change_typeJSON);
cJSON *change_type_convertToJSON(change_type_t *change_type);
#endif /* _change_type_H_ */

