/*
 * n2_information_class.h
 *
 *
 */

#ifndef _n2_information_class_H_
#define _n2_information_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct n2_information_class_t n2_information_class_t;
typedef struct n2_information_class_t {
} n2_information_class_t;

n2_information_class_t *n2_information_class_create(
    );
void n2_information_class_free(n2_information_class_t *n2_information_class);
n2_information_class_t *n2_information_class_parseFromJSON(cJSON *n2_information_classJSON);
cJSON *n2_information_class_convertToJSON(n2_information_class_t *n2_information_class);
#endif /* _n2_information_class_H_ */

