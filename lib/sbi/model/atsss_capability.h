/*
 * atsss_capability.h
 *
 *
 */

#ifndef _atsss_capability_H_
#define _atsss_capability_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct atsss_capability_t atsss_capability_t;
typedef struct atsss_capability_t {
    int atsss_ll;
    int mptcp;
} atsss_capability_t;

atsss_capability_t *atsss_capability_create(
    int atsss_ll,
    int mptcp
    );
void atsss_capability_free(atsss_capability_t *atsss_capability);
atsss_capability_t *atsss_capability_parseFromJSON(cJSON *atsss_capabilityJSON);
cJSON *atsss_capability_convertToJSON(atsss_capability_t *atsss_capability);
#endif /* _atsss_capability_H_ */

