/*
 * pdu_session_type.h
 *
 * 
 */

#ifndef _pdu_session_type_H_
#define _pdu_session_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pdu_session_type_t pdu_session_type_t;




typedef struct pdu_session_type_t {

} pdu_session_type_t;

pdu_session_type_t *pdu_session_type_create(
);

void pdu_session_type_free(pdu_session_type_t *pdu_session_type);

pdu_session_type_t *pdu_session_type_parseFromJSON(cJSON *pdu_session_typeJSON);

cJSON *pdu_session_type_convertToJSON(pdu_session_type_t *pdu_session_type);

#endif /* _pdu_session_type_H_ */

