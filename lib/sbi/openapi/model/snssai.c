
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snssai.h"

ogs_sbi_snssai_t *ogs_sbi_snssai_create(
    int sst,
    char *sd
    )
{
    ogs_sbi_snssai_t *snssai_local_var = ogs_sbi_malloc(sizeof(ogs_sbi_snssai_t));
    if (!snssai_local_var) {
        return NULL;
    }
    snssai_local_var->sst = sst;
    snssai_local_var->sd = sd;

    return snssai_local_var;
}

void ogs_sbi_snssai_free(ogs_sbi_snssai_t *snssai)
{
    if (NULL == snssai) {
        return;
    }
    ogs_sbi_lnode_t *node;
    ogs_free(snssai->sd);
    ogs_free(snssai);
}

cJSON *ogs_sbi_snssai_convertToJSON(ogs_sbi_snssai_t *snssai)
{
    cJSON *item = cJSON_CreateObject();
    if (!snssai->sst) {
        ogs_error("ogs_sbi_snssai_convertToJSON() failed [sst]");
        goto end;
    }
    if (cJSON_AddNumberToObject(item, "sst", snssai->sst) == NULL) {
        ogs_error("ogs_sbi_snssai_convertToJSON() failed [sst]");
        goto end;
    }

    if (snssai->sd) {
        if (cJSON_AddStringToObject(item, "sd", snssai->sd) == NULL) {
            ogs_error("ogs_sbi_snssai_convertToJSON() failed [sd]");
            goto end;
        }
    }

end:
    return item;
}

ogs_sbi_snssai_t *ogs_sbi_snssai_parseFromJSON(cJSON *snssaiJSON)
{
    ogs_sbi_snssai_t *snssai_local_var = NULL;
    cJSON *sst = cJSON_GetObjectItemCaseSensitive(snssaiJSON, "sst");
    if (!sst) {
        ogs_error("ogs_sbi_snssai_parseFromJSON() failed [sst]");
        goto end;
    }


    if (!cJSON_IsNumber(sst)) {
        ogs_error("ogs_sbi_snssai_parseFromJSON() failed [sst]");
        goto end;
    }

    cJSON *sd = cJSON_GetObjectItemCaseSensitive(snssaiJSON, "sd");

    if (sd) {
        if (!cJSON_IsString(sd)) {
            ogs_error("ogs_sbi_snssai_parseFromJSON() failed [sd]");
            goto end;
        }
    }

    snssai_local_var = ogs_sbi_snssai_create (
        sst->valuedouble,
        sd ? ogs_strdup(sd->valuestring) : NULL
        );

    return snssai_local_var;
end:
    return NULL;
}

