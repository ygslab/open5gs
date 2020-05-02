/*
 * plmn_snssai.h
 *
 *
 */

#ifndef _plmn_snssai_H_
#define _plmn_snssai_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "plmn_id.h"
#include "snssai.h"

typedef struct plmn_snssai_t plmn_snssai_t;
typedef struct plmn_snssai_t {
    struct plmn_id_t *plmn_id;
    list_t *s_nssai_list;
} plmn_snssai_t;

plmn_snssai_t *plmn_snssai_create(
    plmn_id_t *plmn_id,
    list_t *s_nssai_list
    );
void plmn_snssai_free(plmn_snssai_t *plmn_snssai);
plmn_snssai_t *plmn_snssai_parseFromJSON(cJSON *plmn_snssaiJSON);
cJSON *plmn_snssai_convertToJSON(plmn_snssai_t *plmn_snssai);
#endif /* _plmn_snssai_H_ */

