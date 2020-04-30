/*
 * amf_cond.h
 *
 * 
 */

#ifndef _amf_cond_H_
#define _amf_cond_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct amf_cond_t amf_cond_t;




typedef struct amf_cond_t {
    char *amf_set_id; // string
    char *amf_region_id; // string

} amf_cond_t;

amf_cond_t *amf_cond_create(
    char *amf_set_id,
    char *amf_region_id
);

void amf_cond_free(amf_cond_t *amf_cond);

amf_cond_t *amf_cond_parseFromJSON(cJSON *amf_condJSON);

cJSON *amf_cond_convertToJSON(amf_cond_t *amf_cond);

#endif /* _amf_cond_H_ */

