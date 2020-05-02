/*
 * snssai_upf_info_item.h
 *
 *
 */

#ifndef _snssai_upf_info_item_H_
#define _snssai_upf_info_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "dnn_upf_info_item.h"
#include "snssai.h"

typedef struct snssai_upf_info_item_t snssai_upf_info_item_t;
typedef struct snssai_upf_info_item_t {
    struct snssai_t *s_nssai;
    list_t *dnn_upf_info_list;
} snssai_upf_info_item_t;

snssai_upf_info_item_t *snssai_upf_info_item_create(
    snssai_t *s_nssai,
    list_t *dnn_upf_info_list
    );
void snssai_upf_info_item_free(snssai_upf_info_item_t *snssai_upf_info_item);
snssai_upf_info_item_t *snssai_upf_info_item_parseFromJSON(cJSON *snssai_upf_info_itemJSON);
cJSON *snssai_upf_info_item_convertToJSON(snssai_upf_info_item_t *snssai_upf_info_item);
#endif /* _snssai_upf_info_item_H_ */

