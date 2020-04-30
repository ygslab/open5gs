/*
 * upf_info.h
 *
 * 
 */

#ifndef _upf_info_H_
#define _upf_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct upf_info_t upf_info_t;

#include "atsss_capability.h"
#include "interface_upf_info_item.h"
#include "pdu_session_type.h"
#include "snssai_upf_info_item.h"



typedef struct upf_info_t {
    list_t *s_nssai_upf_info_list; //nonprimitive container
    list_t *smf_serving_area; //primitive container
    list_t *interface_upf_info_list; //nonprimitive container
    int iwk_eps_ind; //boolean
    list_t *pdu_session_types; //nonprimitive container
    struct atsss_capability_t *atsss_capability; //model
    int ue_ip_addr_ind; //boolean

} upf_info_t;

upf_info_t *upf_info_create(
    list_t *s_nssai_upf_info_list,
    list_t *smf_serving_area,
    list_t *interface_upf_info_list,
    int iwk_eps_ind,
    list_t *pdu_session_types,
    atsss_capability_t *atsss_capability,
    int ue_ip_addr_ind
);

void upf_info_free(upf_info_t *upf_info);

upf_info_t *upf_info_parseFromJSON(cJSON *upf_infoJSON);

cJSON *upf_info_convertToJSON(upf_info_t *upf_info);

#endif /* _upf_info_H_ */

