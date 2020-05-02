/*
 * dnn_smf_info_item.h
 *
 *
 */

#ifndef _dnn_smf_info_item_H_
#define _dnn_smf_info_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct dnn_smf_info_item_t dnn_smf_info_item_t;
typedef struct dnn_smf_info_item_t {
    char *dnn;
} dnn_smf_info_item_t;

dnn_smf_info_item_t *dnn_smf_info_item_create(
    char *dnn
    );
void dnn_smf_info_item_free(dnn_smf_info_item_t *dnn_smf_info_item);
dnn_smf_info_item_t *dnn_smf_info_item_parseFromJSON(cJSON *dnn_smf_info_itemJSON);
cJSON *dnn_smf_info_item_convertToJSON(dnn_smf_info_item_t *dnn_smf_info_item);
#endif /* _dnn_smf_info_item_H_ */

