/*
 * data_set_id.h
 *
 * 
 */

#ifndef _data_set_id_H_
#define _data_set_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct data_set_id_t data_set_id_t;




typedef struct data_set_id_t {

} data_set_id_t;

data_set_id_t *data_set_id_create(
);

void data_set_id_free(data_set_id_t *data_set_id);

data_set_id_t *data_set_id_parseFromJSON(cJSON *data_set_idJSON);

cJSON *data_set_id_convertToJSON(data_set_id_t *data_set_id);

#endif /* _data_set_id_H_ */

