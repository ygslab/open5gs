/*
 * links_value_schema.h
 *
 *
 */

#ifndef _links_value_schema_H_
#define _links_value_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "link.h"

typedef struct links_value_schema_t links_value_schema_t;
typedef struct links_value_schema_t {
    char *href;
} links_value_schema_t;

links_value_schema_t *links_value_schema_create(
    char *href
    );
void links_value_schema_free(links_value_schema_t *links_value_schema);
links_value_schema_t *links_value_schema_parseFromJSON(cJSON *links_value_schemaJSON);
cJSON *links_value_schema_convertToJSON(links_value_schema_t *links_value_schema);
#endif /* _links_value_schema_H_ */

