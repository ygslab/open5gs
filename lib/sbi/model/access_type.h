/*
 * access_type.h
 *
 *
 */

#ifndef _access_type_H_
#define _access_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef enum { access_type_NULL = 0, access_type_3GPP_ACCESS, access_type_NON_3GPP_ACCESS } access_type_e;

char* access_type_ToString(access_type_e access_type);

access_type_e access_type_FromString(char* access_type);
#endif /* _access_type_H_ */

