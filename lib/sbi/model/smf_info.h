/*
 * smf_info.h
 *
 *
 */

#ifndef _smf_info_H_
#define _smf_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "access_type.h"
#include "snssai_smf_info_item.h"
#include "tai.h"
#include "tai_range.h"

typedef struct smf_info_t smf_info_t;
typedef struct smf_info_t {
    list_t *s_nssai_smf_info_list;
    list_t *tai_list;
    list_t *tai_range_list;
    char *pgw_fqdn;
    list_t *access_type;
} smf_info_t;

smf_info_t *smf_info_create(
    list_t *s_nssai_smf_info_list,
    list_t *tai_list,
    list_t *tai_range_list,
    char *pgw_fqdn,
    list_t *access_type
    );
void smf_info_free(smf_info_t *smf_info);
smf_info_t *smf_info_parseFromJSON(cJSON *smf_infoJSON);
cJSON *smf_info_convertToJSON(smf_info_t *smf_info);
#endif /* _smf_info_H_ */

