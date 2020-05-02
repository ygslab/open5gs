/*
 * tai.h
 *
 *
 */

#ifndef _tai_H_
#define _tai_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "plmn_id.h"

typedef struct tai_t tai_t;
typedef struct tai_t {
    struct plmn_id_t *plmn_id;
    char *tac;
} tai_t;

tai_t *tai_create(
    plmn_id_t *plmn_id,
    char *tac
    );
void tai_free(tai_t *tai);
tai_t *tai_parseFromJSON(cJSON *taiJSON);
cJSON *tai_convertToJSON(tai_t *tai);
#endif /* _tai_H_ */

