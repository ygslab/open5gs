/*
 * n1_message_class.h
 *
 * 
 */

#ifndef _n1_message_class_H_
#define _n1_message_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct n1_message_class_t n1_message_class_t;




typedef struct n1_message_class_t {

} n1_message_class_t;

n1_message_class_t *n1_message_class_create(
);

void n1_message_class_free(n1_message_class_t *n1_message_class);

n1_message_class_t *n1_message_class_parseFromJSON(cJSON *n1_message_classJSON);

cJSON *n1_message_class_convertToJSON(n1_message_class_t *n1_message_class);

#endif /* _n1_message_class_H_ */

