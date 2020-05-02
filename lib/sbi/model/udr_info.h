/*
 * udr_info.h
 *
 *
 */

#ifndef _udr_info_H_
#define _udr_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "data_set_id.h"
#include "identity_range.h"
#include "supi_range.h"

typedef struct udr_info_t udr_info_t;
typedef struct udr_info_t {
    char *group_id;
    list_t *supi_ranges;
    list_t *gpsi_ranges;
    list_t *external_group_identifiers_ranges;
    list_t *supported_data_sets;
} udr_info_t;

udr_info_t *udr_info_create(
    char *group_id,
    list_t *supi_ranges,
    list_t *gpsi_ranges,
    list_t *external_group_identifiers_ranges,
    list_t *supported_data_sets
    );
void udr_info_free(udr_info_t *udr_info);
udr_info_t *udr_info_parseFromJSON(cJSON *udr_infoJSON);
cJSON *udr_info_convertToJSON(udr_info_t *udr_info);
#endif /* _udr_info_H_ */

