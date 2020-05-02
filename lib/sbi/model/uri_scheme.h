/*
 * uri_scheme.h
 *
 *
 */

#ifndef _uri_scheme_H_
#define _uri_scheme_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct uri_scheme_t uri_scheme_t;
typedef struct uri_scheme_t {
} uri_scheme_t;

uri_scheme_t *uri_scheme_create(
    );
void uri_scheme_free(uri_scheme_t *uri_scheme);
uri_scheme_t *uri_scheme_parseFromJSON(cJSON *uri_schemeJSON);
cJSON *uri_scheme_convertToJSON(uri_scheme_t *uri_scheme);
#endif /* _uri_scheme_H_ */

