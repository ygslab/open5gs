/*
 * chf_info.h
 *
 * 
 */

#ifndef _chf_info_H_
#define _chf_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chf_info_t chf_info_t;

#include "identity_range.h"
#include "plmn_range.h"
#include "supi_range.h"



typedef struct chf_info_t {
    list_t *supi_range_list; //nonprimitive container
    list_t *gpsi_range_list; //nonprimitive container
    list_t *plmn_range_list; //nonprimitive container

} chf_info_t;

chf_info_t *chf_info_create(
    list_t *supi_range_list,
    list_t *gpsi_range_list,
    list_t *plmn_range_list
);

void chf_info_free(chf_info_t *chf_info);

chf_info_t *chf_info_parseFromJSON(cJSON *chf_infoJSON);

cJSON *chf_info_convertToJSON(chf_info_t *chf_info);

#endif /* _chf_info_H_ */

