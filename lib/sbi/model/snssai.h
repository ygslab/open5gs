/*
 * snssai.h
 *
 *
 */

#ifndef _snssai_H_
#define _snssai_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct snssai_t snssai_t;
typedef struct snssai_t {
    int sst;
    char *sd;
} snssai_t;

snssai_t *snssai_create(
    int sst,
    char *sd
    );
void snssai_free(snssai_t *snssai);
snssai_t *snssai_parseFromJSON(cJSON *snssaiJSON);
cJSON *snssai_convertToJSON(snssai_t *snssai);
#endif /* _snssai_H_ */

