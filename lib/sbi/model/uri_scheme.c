
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "uri_scheme.h"

uri_scheme_t *uri_scheme_create(
    )
{
    uri_scheme_t *uri_scheme_local_var = ogs_malloc(sizeof(uri_scheme_t));
    if (!uri_scheme_local_var) {
        return NULL;
    }

    return uri_scheme_local_var;
}

void uri_scheme_free(uri_scheme_t *uri_scheme)
{
    if(NULL == uri_scheme) {
        return;
    }
    listEntry_t *listEntry;
    ogs_free(uri_scheme);
}

cJSON *uri_scheme_convertToJSON(uri_scheme_t *uri_scheme)
{
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

uri_scheme_t *uri_scheme_parseFromJSON(cJSON *uri_schemeJSON)
{
    uri_scheme_t *uri_scheme_local_var = NULL;
    uri_scheme_local_var = uri_scheme_create (
        );

    return uri_scheme_local_var;
end:
    return NULL;
}

