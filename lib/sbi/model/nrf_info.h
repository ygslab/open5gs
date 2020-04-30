/*
 * nrf_info.h
 *
 * 
 */

#ifndef _nrf_info_H_
#define _nrf_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct nrf_info_t nrf_info_t;

#include "amf_info.h"
#include "ausf_info.h"
#include "bsf_info.h"
#include "chf_info.h"
#include "nwdaf_info.h"
#include "pcf_info.h"
#include "smf_info.h"
#include "udm_info.h"
#include "udr_info.h"
#include "upf_info.h"



typedef struct nrf_info_t {
    list_t* served_udr_info; //map
    list_t* served_udm_info; //map
    list_t* served_ausf_info; //map
    list_t* served_amf_info; //map
    list_t* served_smf_info; //map
    list_t* served_upf_info; //map
    list_t* served_pcf_info; //map
    list_t* served_bsf_info; //map
    list_t* served_chf_info; //map
    list_t* served_nwdaf_info; //map

} nrf_info_t;

nrf_info_t *nrf_info_create(
    list_t* served_udr_info,
    list_t* served_udm_info,
    list_t* served_ausf_info,
    list_t* served_amf_info,
    list_t* served_smf_info,
    list_t* served_upf_info,
    list_t* served_pcf_info,
    list_t* served_bsf_info,
    list_t* served_chf_info,
    list_t* served_nwdaf_info
);

void nrf_info_free(nrf_info_t *nrf_info);

nrf_info_t *nrf_info_parseFromJSON(cJSON *nrf_infoJSON);

cJSON *nrf_info_convertToJSON(nrf_info_t *nrf_info);

#endif /* _nrf_info_H_ */

