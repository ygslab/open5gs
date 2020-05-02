/*
 * dnn_upf_info_item.h
 *
 *
 */

#ifndef _dnn_upf_info_item_H_
#define _dnn_upf_info_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "pdu_session_type.h"

typedef struct dnn_upf_info_item_t dnn_upf_info_item_t;
typedef struct dnn_upf_info_item_t {
    char *dnn;
    list_t *dnai_list;
    list_t *pdu_session_types;
} dnn_upf_info_item_t;

dnn_upf_info_item_t *dnn_upf_info_item_create(
    char *dnn,
    list_t *dnai_list,
    list_t *pdu_session_types
    );
void dnn_upf_info_item_free(dnn_upf_info_item_t *dnn_upf_info_item);
dnn_upf_info_item_t *dnn_upf_info_item_parseFromJSON(cJSON *dnn_upf_info_itemJSON);
cJSON *dnn_upf_info_item_convertToJSON(dnn_upf_info_item_t *dnn_upf_info_item);
#endif /* _dnn_upf_info_item_H_ */

