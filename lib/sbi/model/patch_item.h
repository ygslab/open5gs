/*
 * patch_item.h
 *
 *
 */

#ifndef _patch_item_H_
#define _patch_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "patch_operation.h"

typedef struct patch_item_t patch_item_t;
typedef struct patch_item_t {
    struct patch_operation_t *op;
    char *path;
    char *from;
    char *value;
} patch_item_t;

patch_item_t *patch_item_create(
    patch_operation_t *op,
    char *path,
    char *from,
    char *value
    );
void patch_item_free(patch_item_t *patch_item);
patch_item_t *patch_item_parseFromJSON(cJSON *patch_itemJSON);
cJSON *patch_item_convertToJSON(patch_item_t *patch_item);
#endif /* _patch_item_H_ */

