
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pdu_session_type.h"

pdu_session_type_t *pdu_session_type_create(
    )
{
    pdu_session_type_t *pdu_session_type_local_var = ogs_malloc(sizeof(pdu_session_type_t));
    if (!pdu_session_type_local_var) {
        return NULL;
    }

    return pdu_session_type_local_var;
}

void pdu_session_type_free(pdu_session_type_t *pdu_session_type)
{
    if(NULL == pdu_session_type) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(pdu_session_type);
}

cJSON *pdu_session_type_convertToJSON(pdu_session_type_t *pdu_session_type)
{
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

pdu_session_type_t *pdu_session_type_parseFromJSON(cJSON *pdu_session_typeJSON)
{
    pdu_session_type_t *pdu_session_type_local_var = NULL;
    pdu_session_type_local_var = pdu_session_type_create (
        );

    return pdu_session_type_local_var;
end:
    return NULL;
}

