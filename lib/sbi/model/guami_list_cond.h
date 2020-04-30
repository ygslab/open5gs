/*
 * guami_list_cond.h
 *
 * 
 */

#ifndef _guami_list_cond_H_
#define _guami_list_cond_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct guami_list_cond_t guami_list_cond_t;

#include "guami.h"



typedef struct guami_list_cond_t {
    list_t *guami_list; //nonprimitive container

} guami_list_cond_t;

guami_list_cond_t *guami_list_cond_create(
    list_t *guami_list
);

void guami_list_cond_free(guami_list_cond_t *guami_list_cond);

guami_list_cond_t *guami_list_cond_parseFromJSON(cJSON *guami_list_condJSON);

cJSON *guami_list_cond_convertToJSON(guami_list_cond_t *guami_list_cond);

#endif /* _guami_list_cond_H_ */

