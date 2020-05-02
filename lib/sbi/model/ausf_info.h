/*
 * ausf_info.h
 *
 *
 */

#ifndef _ausf_info_H_
#define _ausf_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "supi_range.h"

typedef struct ausf_info_t ausf_info_t;
typedef struct ausf_info_t {
    char *group_id;
    list_t *supi_ranges;
    list_t *routing_indicators;
} ausf_info_t;

ausf_info_t *ausf_info_create(
    char *group_id,
    list_t *supi_ranges,
    list_t *routing_indicators
    );
void ausf_info_free(ausf_info_t *ausf_info);
ausf_info_t *ausf_info_parseFromJSON(cJSON *ausf_infoJSON);
cJSON *ausf_info_convertToJSON(ausf_info_t *ausf_info);
#endif /* _ausf_info_H_ */

