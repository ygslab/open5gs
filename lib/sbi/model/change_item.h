/*
 * change_item.h
 *
 * 
 */

#ifndef _change_item_H_
#define _change_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct change_item_t change_item_t;

#include "change_type.h"



typedef struct change_item_t {
    struct change_type_t *op; //model
    char *path; // string
    char *from; // string
    char *orig_value; // string
    char *new_value; // string

} change_item_t;

change_item_t *change_item_create(
    change_type_t *op,
    char *path,
    char *from,
    char *orig_value,
    char *new_value
);

void change_item_free(change_item_t *change_item);

change_item_t *change_item_parseFromJSON(cJSON *change_itemJSON);

cJSON *change_item_convertToJSON(change_item_t *change_item);

#endif /* _change_item_H_ */

