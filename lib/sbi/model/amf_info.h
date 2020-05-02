/*
 * amf_info.h
 *
 *
 */

#ifndef _amf_info_H_
#define _amf_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "guami.h"
#include "n2_interface_amf_info.h"
#include "tai.h"
#include "tai_range.h"

typedef struct amf_info_t amf_info_t;
typedef struct amf_info_t {
    char *amf_set_id;
    char *amf_region_id;
    list_t *guami_list;
    list_t *tai_list;
    list_t *tai_range_list;
    list_t *backup_info_amf_failure;
    list_t *backup_info_amf_removal;
    struct n2_interface_amf_info_t *n2_interface_amf_info;
} amf_info_t;

amf_info_t *amf_info_create(
    char *amf_set_id,
    char *amf_region_id,
    list_t *guami_list,
    list_t *tai_list,
    list_t *tai_range_list,
    list_t *backup_info_amf_failure,
    list_t *backup_info_amf_removal,
    n2_interface_amf_info_t *n2_interface_amf_info
    );
void amf_info_free(amf_info_t *amf_info);
amf_info_t *amf_info_parseFromJSON(cJSON *amf_infoJSON);
cJSON *amf_info_convertToJSON(amf_info_t *amf_info);
#endif /* _amf_info_H_ */

