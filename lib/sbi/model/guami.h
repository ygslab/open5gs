/*
 * guami.h
 *
 * 
 */

#ifndef _guami_H_
#define _guami_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct guami_t guami_t;

#include "plmn_id.h"



typedef struct guami_t {
    struct plmn_id_t *plmn_id; //model
    char *amf_id; // string

} guami_t;

guami_t *guami_create(
    plmn_id_t *plmn_id,
    char *amf_id
);

void guami_free(guami_t *guami);

guami_t *guami_parseFromJSON(cJSON *guamiJSON);

cJSON *guami_convertToJSON(guami_t *guami);

#endif /* _guami_H_ */

