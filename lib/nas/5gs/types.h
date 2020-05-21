/*
 * Copyright (C) 2019 by Sukchan Lee <acetcom@gmail.com>
 *
 * This file is part of Open5GS.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#if !defined(OGS_NAS_INSIDE) && !defined(OGS_NAS_COMPILATION)
#error "This header cannot be included directly."
#endif

#ifndef OGS_NAS_5GS_TYPES_H
#define OGS_NAS_5GS_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/* 9.11.2.1A DNN
 * O TLV 3-102 */
typedef struct ogs_nas_dnn_s {
    uint8_t length;
    char value[OGS_MAX_DNN_LEN];
} ogs_nas_dnn_t;

/* 9.11.2.2 EAP message
 * O TLV-E 7-1503 */
typedef struct ogs_nas_eap_message_s {
    uint16_t length;
    uint8_t *buffer;
} ogs_nas_eap_message_t;

/* 9.11.2.8.1 S-NSSAI
 * O TLV 3-10 */
#define OGS_NAS_S_NSSAI_SST_LEN 1
#define OGS_NAS_S_NSSAI_SST_AND_MAPPED_HPLMN_SST_LEN 2
#define OGS_NAS_S_NSSAI_SST_AND_SD 4
#define OGS_NAS_S_NSSAI_SST_SD_AND_MAPPED_HPLMN_SST_LEN 5
#define OGS_NAS_MAX_S_NSSAI_LEN 8
typedef struct ogs_nas_s_nssai_s {
    uint8_t length;
    uint32_t sst_sd;
    uint32_t mapped_sst_sd;
} __attribute__ ((packed)) ogs_nas_s_nssai_t;

/* 9.11.3.1 5GMM capability
 * O TLV 3-15 */
typedef struct ogs_nas_5gmm_capability_s {
    uint8_t length;
ED4(uint8_t spare:5;,
    uint8_t lpp:1;,
    uint8_t ho:1;,
    uint8_t s1:1;)
} __attribute__ ((packed)) ogs_nas_5gmm_capability_t;

/* 9.11.3.2 5GMM cause
 * M V 1 */
#define OGS_NAS_GMM_ILLEGAL_UE 3
#define OGS_NAS_GMM_PEI_NOT_ACCEPTED 5
#define OGS_NAS_GMM_ILLEGAL_ME 6
#define OGS_NAS_GMM_5GS_SERVICES_NOT_ALLOWED 7
#define OGS_NAS_GMM_UE_IDENTITY_CANNOT_BE_DERIVED_BY_THE_NETWORK 9
#define OGS_NAS_GMM_IMPLICITLY_DE_REGISTERED 10
#define OGS_NAS_GMM_PLMN_NOT_ALLOWED 11
#define OGS_NAS_GMM_TRACKING_AREA_NOT_ALLOWED 12
#define OGS_NAS_GMM_ROAMING_NOT_ALLOWED_IN_THIS_TRACKING_AREA 13
#define OGS_NAS_GMM_NO_SUITABLE_CELLS_IN_TRACKING_AREA 15
#define OGS_NAS_GMM_MAC_FAILURE 20
#define OGS_NAS_GMM_SYNCH_FAILURE 21
#define OGS_NAS_GMM_CONGESTION 22
#define OGS_NAS_GMM_UE_SECURITY_CAPABILITIES_MISMATCH 23
#define OGS_NAS_GMM_SECURITY_MODE_REJECTED_UNSPECIFIED 24
#define OGS_NAS_GMM_NON_5G_AUTHENTICATION_UNACCEPTABLE 26
#define OGS_NAS_GMM_N1_MODE_NOT_ALLOWED 27
#define OGS_NAS_GMM_RESTRICTED_SERVICE_AREA 28
#define OGS_NAS_GMM_LADN_NOT_AVAILABLE 43
#define OGS_NAS_GMM_MAXIMUM_NUMBER_OF_PDU_SESSIONS_REACHED 65
#define OGS_NAS_GMM_INSUFFICIENT_RESOURCES_FOR_SPECIFIC_SLICE_AND_DNN 67
#define OGS_NAS_GMM_INSUFFICIENT_RESOURCES_FOR_SPECIFIC_SLICE 69
#define OGS_NAS_GMM_NGKSI_ALREADY_IN_USE 71
#define OGS_NAS_GMM_NON_3GPP_ACCESS_TO_5GCN_NOT_ALLOWED 72
#define OGS_NAS_GMM_SERVING_NETWORK_NOT_AUTHORIZED 73
#define OGS_NAS_GMM_PAYLOAD_WAS_NOT_FORWARDED 90
#define OGS_NAS_GMM_DNN_NOT_SUPPORTED_OR_NOT_SUBSCRIBED_IN_THE_SLICE 91
#define OGS_NAS_GMM_INSUFFICIENT_USER_PLANE_RESOURCES_FOR_THE_PDU_SESSION 92
#define OGS_NAS_GMM_SEMANTICALLY_INCORRECT_MESSAGE 95
#define OGS_NAS_GMM_INVALID_MANDATORY_INFORMATION 96
#define OGS_NAS_GMM_MESSAGE_TYPE_NON_EXISTENT_OR_NOT_IMPLEMENTED 97
#define OGS_NAS_GMM_MESSAGE_TYPE_NOT_COMPATIBLE_WITH_THE_PROTOCOL_STATE 98
#define OGS_NAS_GMM_INFORMATION_ELEMENT_NON_EXISTENT_OR_NOT_IMPLEMENTED 99
#define OGS_NAS_GMM_CONDITIONAL_IE_ERROR 100
#define OGS_NAS_GMM_MESSAGE_NOT_COMPATIBLE_WITH_THE_PROTOCOL_STATE 101
#define OGS_NAS_GMM_PROTOCOL_ERROR_UNSPECIFIED 111
typedef uint8_t ogs_nas_5gmm_cause_t;

/* 9.11.3.2A 5GS DRX parameters
 * O TLV 3 */
#define OGS_NAS_DRX_CYCLE_PARAMETER_T_32 1
#define OGS_NAS_DRX_CYCLE_PARAMETER_T_64 2
#define OGS_NAS_DRX_CYCLE_PARAMETER_T_128 3
#define OGS_NAS_DRX_CYCLE_PARAMETER_T_256 4
typedef struct ogs_nas_5gs_drx_parameters_s {
    uint8_t length;
ED2(uint8_t spare:4;,
    uint8_t value:4;)
} __attribute__ ((packed)) ogs_nas_5gs_drx_parameters_t;

/* 9.11.3.3 5GS identity type
 * M V 1/2 */
#define OGS_NAS_5GS_MOBILE_IDENTITY_SUCI 1
#define OGS_NAS_5GS_MOBILE_IDENTITY_5G_GUTI 2
#define OGS_NAS_5GS_MOBILE_IDENTITY_IMEI 3
#define OGS_NAS_5GS_MOBILE_IDENTITY_5G_S_TMSI 4
#define OGS_NAS_5GS_MOBILE_IDENTITY_IMEISV 5
typedef struct ogs_nas_5gs_identity_type_s {
ED3(uint8_t type:4;,
    uint8_t spare:1;,
    uint8_t value:3;)
} __attribute__ ((packed)) ogs_nas_5gs_identity_type_t;

/* 9.11.3.4 5GS mobile identity
 * M LV-E 6-n */
#define OGS_NAS_5GS_MOBILE_IDENTITY_EVEN 0
#define OGS_NAS_5GS_MOBILE_IDENTITY_ODD 1
typedef struct ogs_nas_5gs_mobile_identity_5g_guti_s {
ED3(uint8_t spare:4;,
    uint8_t odd_even:1;,
    uint8_t type:3;)
    ogs_nas_plmn_id_t nas_plmn_id;
    uint16_t amf_region_id;
    uint8_t amf_set_id1;
ED2(uint8_t amf_set_id2:2;,
    uint8_t amf_pointer:6;)
    uint32_t m_tmsi;
} __attribute__ ((packed)) ogs_nas_5gs_mobile_identity_5g_guti_t;

typedef ogs_nas_mobile_identity_imsi_t ogs_nas_5gs_mobile_identity_imsi_t;
typedef ogs_nas_mobile_identity_imsi_t ogs_nas_5gs_mobile_identity_imei_t;

typedef struct ogs_nas_5gs_mobile_identity_s {
    uint8_t length;
    uint8_t *buffer;
} ogs_nas_5gs_mobile_identity_t;

/* 9.11.3.5 5GS network feature support
 * M LV 2 */
typedef struct ogs_nas_5gs_network_feature_support_s {
    uint8_t length;
ED6(uint8_t mpsi:1;,
    uint8_t iwk_n26:1;,
    uint8_t emf:2;,
    uint8_t msc:2;,
    uint8_t ims_vops_n3gpp:1;,
    uint8_t ims_vops_3gpp:1;)
ED3(uint8_t spare:6;,
    uint8_t mcsi:1;,
    uint8_t emcn :1;)
} ogs_nas_5gs_network_feature_support_t;

/* 9.11.3.6 5GS registration result
 * O TLV 3-5 */
#define OGS_NAS_5GS_REGISTRATION_TYPE_3GPP_ACCESS 0
#define OGS_NAS_5GS_REGISTRATION_TYPE_NON_3GPP_ACCESS 1
#define OGS_NAS_5GS_REGISTRATION_TYPE_3GPP_AND_NON_3GPP_ACCESS 2
typedef struct ogs_nas_5gs_registration_result_s {
    uint8_t length;
ED3(uint8_t spare:4;,
    uint8_t sms_allowed:1;,
    uint8_t value:3;)
} ogs_nas_5gs_registration_result_t;

/* 9.11.3.7 5GS registration type
 * M V 1/2 */
#define OGS_NAS_5GS_REGISTRATION_TYPE_INITIAL 1
#define OGS_NAS_5GS_REGISTRATION_TYPE_MOBILITY_UPDATING 2
#define OGS_NAS_5GS_REGISTRATION_TYPE_PERIODIC_UPDATING 3
#define OGS_NAS_5GS_REGISTRATION_TYPE_EMERGENCY 4
typedef struct ogs_nas_5gs_registration_type_s {
ED3(uint8_t type:4;,
    uint8_t follow_on_request:1;,
    uint8_t value:3;)
} ogs_nas_5gs_registration_type_t;

/* 9.11.3.8 5GS tracking area identity
 * O TV 6 */
typedef ogs_nas_tracking_area_identity_t ogs_nas_5gs_tracking_area_identity_t;

/* 9.11.3.9 5GS tracking area identity list
 * O TLV 9-114 */
typedef ogs_nas_tracking_area_identity_list_t ogs_nas_5gs_tracking_area_identity_list_t;

/* 9.11.3.9A 5GS update type
 * O TLV 3 */
typedef struct ogs_nas_5gs_update_type_s {
    uint8_t length;
ED6(uint8_t spare:2;,
    uint8_t pnb_ciot_eps:1;,
    uint8_t pnb_ciot_5gs:1;,
    uint8_t ng_ran_rcu:1;,
    uint8_t sms_requested:1;,
    uint8_t amf_pointer_value:2;)
} __attribute__ ((packed)) ogs_nas_5gs_update_type_t;

/* 9.11.3.10 ABBA
 * M LV 3-n */
#define OGS_NAS_ABBA_LEN 255
typedef struct ogs_nas_abba_s {
    uint8_t length;
    uint8_t abba[OGS_NAS_ABBA_LEN];
} ogs_nas_abba_t;

/* 9.11.3.11 Access Type
 * M V 1/2 */
#define OGS_NAS_NOTIFICATION_ACCESS_TYPE_3GPP           1
#define OGS_NAS_NOTIFICATION_ACCESS_TYPE_NON_3GPP       2
typedef struct ogs_nas_access_type_s {
ED2(uint8_t spare:5;,
    uint8_t value:3;)
} __attribute__ ((packed)) ogs_nas_access_type_t;

/* 9.11.3.12 Additional 5G security information
 * O TLV 3 */
typedef struct ogs_nas_additional_5g_security_information_s {
    uint8_t length;
ED3(uint8_t spare:6;,
    uint8_t rinmr:1;,
    uint8_t hdr:1;)
} __attribute__ ((packed)) ogs_nas_additional_5g_security_information_t;

/* 9.11.3.12A Additional information requested
 * O TLV 3 */
typedef struct ogs_nas_additional_information_requested_s {
    uint8_t length;
ED2(uint8_t spare:7;,
    uint8_t cipher_key:1;)
} ogs_nas_additional_information_requested_t;

/* 9.11.3.13 Allowed PDU session status
 * O TLV 4-34 */
typedef struct ogs_nas_allowed_pdu_session_status_s {
    uint8_t length;
ED8(uint8_t psi7:1;,
    uint8_t psi6:1;,
    uint8_t psi5:1;,
    uint8_t psi4:1;,
    uint8_t psi3:1;,
    uint8_t psi2:1;,
    uint8_t psi1:1;,
    uint8_t hdr0:1;)
ED8(uint8_t psi15:1;,
    uint8_t psi14:1;,
    uint8_t psi13:1;,
    uint8_t psi12:1;,
    uint8_t psi11:1;,
    uint8_t psi10:1;,
    uint8_t psi9:1;,
    uint8_t psi8:1;)
} __attribute__ ((packed)) ogs_nas_allowed_pdu_session_status_t;

/* 9.11.3.18 Configuration update indication
 * O TV 1 */
typedef struct ogs_nas_configuration_update_indication_s {
ED4(uint8_t type:4;,
    uint8_t spare:2;,
    uint8_t red:1;,
    uint8_t ack:1;)
} __attribute__ ((packed)) ogs_nas_configuration_update_indication_t;

/* 9.11.3.18A CAG information list
 * O TLV-E 3-n */
typedef struct ogs_nas_cag_information_list_s {
    uint8_t length;
    uint8_t *buffer;
} ogs_nas_cag_information_list_t;

/* 9.11.3.18B CIoT small data container
 * O TLV 4-257 */
#define OGS_NAS_MAX_CIOT_SMALL_DATA_CONTAINER_LEN 254
typedef struct ogs_nas_ciot_small_data_container_s {
    uint8_t length;
ED3(uint8_t data_type:3;,
    uint8_t ddx:2;,
    uint8_t pdu_session_identity:1;)
    uint8_t buffer[OGS_NAS_MAX_CIOT_SMALL_DATA_CONTAINER_LEN];
} __attribute__ ((packed)) ogs_nas_ciot_small_data_container_t;

/* 9.11.3.18C Ciphering key data
 * O TLV-E x-n */
typedef struct ogs_nas_ciphering_key_data_s {
    uint8_t length;
    uint8_t *buffer;
} ogs_nas_ciphering_key_data_t;

/* 9.11.3.18D Control plane service type
 * M V 1/2 */
typedef struct ogs_nas_control_plane_service_type_s {
ED3(uint8_t type:4;,
    uint8_t spare:1;,
    uint8_t value:1;)
} __attribute__ ((packed)) ogs_nas_control_plane_service_type_t;

/* 9.11.3.20 De-registration type
 * M V 1/2 */
typedef struct ogs_nas_de_registration_type_s {
ED4(uint8_t type:4;,
    uint8_t switch_off:1;,
    uint8_t re_registration_required:1;,
    uint8_t value:1;)
} __attribute__ ((packed)) ogs_nas_de_registration_type_t;

/* 9.11.3.24 EPS NAS message container
 * O TLV-E 4-n */
typedef struct ogs_nas_eps_nas_message_container_s {
    uint8_t length;
    uint8_t *buffer;
} ogs_nas_eps_nas_message_container_t;

/* 9.11.3.25 EPS NAS security algorithms
 * O TV 2 */
#define OGS_NAS_SECURITY_ALGORITHMS_EIA0        0
#define OGS_NAS_SECURITY_ALGORITHMS_128_EIA1    1
#define OGS_NAS_SECURITY_ALGORITHMS_128_EIA2    2
#define OGS_NAS_SECURITY_ALGORITHMS_128_EIA3    3
#define OGS_NAS_SECURITY_ALGORITHMS_EEA0        0
#define OGS_NAS_SECURITY_ALGORITHMS_128_EEA1    1
#define OGS_NAS_SECURITY_ALGORITHMS_128_EEA2    2
#define OGS_NAS_SECURITY_ALGORITHMS_128_EEA3    3
typedef struct ogs_nas_eps_nas_security_algorithms_s {
ED4(uint8_t spare1:1;,
    uint8_t type_of_ciphering_algorithm:3;,
    uint8_t spare2:1;,
    uint8_t type_of_integrity_protection_algorithm:3;)
} __attribute__ ((packed)) ogs_nas_eps_nas_security_algorithms_t;

/* 9.11.3.29 LADN indication
 * O TLV-E 3-811 */
typedef struct ogs_nas_ladn_indication_s {
    uint16_t length;
    uint8_t *buffer;
} ogs_nas_ladn_indication_t;

/* 9.11.3.30 LADN information
 * O TLV-E 12-1715 */
typedef struct ogs_nas_ladn_information_s {
    uint16_t length;
    uint8_t *buffer;
} ogs_nas_ladn_information_t;

/* 9.11.3.31 MICO indication
 * O TV 1 */
typedef struct ogs_nas_mico_indication_s {
ED3(uint8_t type:4;,
    uint8_t spare:3;,
    uint8_t raai:1;)
} __attribute__ ((packed)) ogs_nas_mico_indication_t;

/* 9.11.3.31A MA PDU session information
 * O TV 1 */
typedef struct ogs_nas_ma_pdu_session_information_s {
ED2(uint8_t type:4;,
    uint8_t value:4;)
} __attribute__ ((packed)) ogs_nas_ma_pdu_session_information_t;

/* 9.11.3.31B Mapped NSSAI
 * O TLV 3-42 */
#define OGS_NAS_MAX_MAPPED_NSSAI_LEN 40
typedef struct ogs_nas_mapped_nssai_s {
    uint8_t length;
    uint8_t buffer[OGS_NAS_MAX_MAPPED_NSSAI_LEN];
} ogs_nas_mapped_nssai_t;

/* 9.11.3.33 message container
 * O TLV-E 4-n */
typedef struct ogs_nas_message_container_s {
    uint16_t length;
    uint8_t *buffer;
} __attribute__ ((packed)) ogs_nas_message_container_t;

/* 9.11.3.34 security algorithms
 * M V 1 */
#define OGS_NAS_SECURITY_ALGORITHMS_IA0         0
#define OGS_NAS_SECURITY_ALGORITHMS_128_IA1     1
#define OGS_NAS_SECURITY_ALGORITHMS_128_IA2     2
#define OGS_NAS_SECURITY_ALGORITHMS_128_IA3     3
#define OGS_NAS_SECURITY_ALGORITHMS_IA4         4
#define OGS_NAS_SECURITY_ALGORITHMS_IA5         5
#define OGS_NAS_SECURITY_ALGORITHMS_IA6         6
#define OGS_NAS_SECURITY_ALGORITHMS_IA7         7
#define OGS_NAS_SECURITY_ALGORITHMS_EA0         0
#define OGS_NAS_SECURITY_ALGORITHMS_128_EA1     1
#define OGS_NAS_SECURITY_ALGORITHMS_128_EA2     2
#define OGS_NAS_SECURITY_ALGORITHMS_128_EA3     3
#define OGS_NAS_SECURITY_ALGORITHMS_EA4         4
#define OGS_NAS_SECURITY_ALGORITHMS_EA5         5
#define OGS_NAS_SECURITY_ALGORITHMS_EA6         6
#define OGS_NAS_SECURITY_ALGORITHMS_EA7         7
typedef struct ogs_nas_security_algorithms_s {
ED4(uint8_t spare1:1;,
    uint8_t type_of_ciphering_algorithm:3;,
    uint8_t spare2:1;,
    uint8_t type_of_integrity_protection_algorithm:3;)
} __attribute__ ((packed)) ogs_nas_security_algorithms_t;

/* 9.11.3.36 Network slicing indication
 * O TV 1 */
typedef struct ogs_nas_network_slicing_indication_s {
ED4(uint8_t type:4;,
    uint8_t spare:2;,
    uint8_t dcni:1;,
    uint8_t nssci:1;)
}  __attribute__ ((packed)) ogs_nas_network_slicing_indication_t;

/* 9.11.3.37 NSSAI
 * O TLV 4-72 */
#define MAX_NAS_NSSAI_LEN 72
typedef struct ogs_nas_nssai_s {
    uint8_t length;
    uint8_t buffer[MAX_NAS_NSSAI_LEN];
} __attribute__ ((packed)) ogs_nas_nssai_t;

/* 9.11.3.37A NSSAI inclusion mode
 * O TV 1 */
#define OGS_NAS_NSSAI_INCLUSION_MODE_A 0
#define OGS_NAS_NSSAI_INCLUSION_MODE_B 1
#define OGS_NAS_NSSAI_INCLUSION_MODE_C 2
#define OGS_NAS_NSSAI_INCLUSION_MODE_D 3
typedef struct ogs_nas_nssai_inclusion_mode_s {
ED3(uint8_t type:4;,
    uint8_t spare:2;,
    uint8_t value:2;)
} __attribute__ ((packed)) ogs_nas_nssai_inclusion_mode_t;

/* 9.11.3.38 Operator-defined access category definitions
 * O TLV-E 3-n */
typedef struct ogs_nas_operator_defined_access_category_definitions_s {
    uint16_t length;
    uint8_t *buffer;
} ogs_nas_operator_defined_access_category_definitions_t;

/* 9.11.3.39 Payload container
 * O TLV-E 4-65535 */
typedef struct ogs_nas_payload_container_s {
    uint16_t length;
    uint8_t *buffer;
} ogs_nas_payload_container_t;

/* 9.11.3.40 Payload container type
 * O TV 1 */
typedef struct ogs_nas_payload_container_type_s {
ED2(uint8_t type:4;,
    uint8_t value:4;)
}  __attribute__ ((packed)) ogs_nas_payload_container_type_t;

/* 9.11.3.41 PDU session identity 2
 * C TV 2 */
typedef struct ogs_nas_pdu_session_identity_2_s {
    uint8_t type;
    uint8_t value;
}  __attribute__ ((packed)) ogs_nas_pdu_session_identity_2_t;

/* 9.11.3.42 PDU session reactivation result
 * O TLV 4-34 */
typedef ogs_nas_allowed_pdu_session_status_t ogs_nas_pdu_session_reactivation_result_t;

/* 9.11.3.43 PDU session reactivation result error cause
 * O TLV-E 5-515 */
typedef struct ogs_nas_pdu_session_reactivation_result_error_cause_s {
    uint8_t length;
    uint8_t *buffer;
} ogs_nas_pdu_session_reactivation_result_error_cause_t;

/* 9.11.3.44 PDU session status
 * O TLV 4-34 */
typedef ogs_nas_allowed_pdu_session_status_t ogs_nas_pdu_session_status_t;

/* 9.11.3.46 Rejected NSSAI
 * O TLV 4-42 */
#define OGS_MAX_NAS_REJECTED_NSSAI_LEN 40
typedef struct ogs_nas_rejected_nssai_s {
    uint8_t length;
    uint8_t buffer[OGS_MAX_NAS_REJECTED_NSSAI_LEN];
} ogs_nas_rejected_nssai_t;

/* 9.11.3.47 Request type
 * O TV 1 */
#define OGS_NAS_REQUEST_TYPE_INITIAL 1
#define OGS_NAS_REQUEST_TYPE_EXISTING_PDU_SESSION 2
#define OGS_NAS_REQUEST_TYPE_INITIAL_EMERGENCY 3
#define OGS_NAS_REQUEST_TYPE_EXISTING_PDU_SESSION_EMERGENCY 4
#define OGS_NAS_REQUEST_TYPE_MODIFICATION 5
typedef struct ogs_nas_request_type_s {
ED3(uint8_t type:4;,
    uint8_t spare:1;,
    uint8_t value:3;)
} __attribute__ ((packed)) ogs_nas_request_type_t;

/* 9.11.3.48 S1 UE network capability
 * O TLV 4-15 */
typedef struct ogs_nas_ue_network_capability_s ogs_nas_s1_ue_network_capability_t;

/* 9.11.3.48A S1 UE security capability
 * O TLV 4-7 */
typedef struct ogs_nas_s1_ue_security_capability_s {
    uint8_t length;
    union { 
        struct {
        ED8(uint8_t eea0:1;,
            uint8_t eea1:1;,
            uint8_t eea2:1;,
            uint8_t eea3:1;,
            uint8_t eea4:1;,
            uint8_t eea5:1;,
            uint8_t eea6:1;,
            uint8_t eea7:1;)
        };
        uint8_t eea; 
    };
    union { 
        struct {
        ED8(uint8_t eia0:1;,
            uint8_t eia1:1;,
            uint8_t eia2:1;,
            uint8_t eia3:1;,
            uint8_t eia4:1;,
            uint8_t eia5:1;,
            uint8_t eia6:1;,
            uint8_t eia7:1;)
        };
        uint8_t eia; 
    };
    union { 
        struct {
        ED8(uint8_t uea0:1;,
            uint8_t uea1:1;,
            uint8_t uea2:1;,
            uint8_t uea3:1;,
            uint8_t uea4:1;,
            uint8_t uea5:1;,
            uint8_t uea6:1;,
            uint8_t uea7:1;)
        };
        uint8_t uea; 
    };
    union { 
        struct {
        ED8(uint8_t spare1:1;,
            uint8_t uia1:1;,
            uint8_t uia2:1;,
            uint8_t uia3:1;,
            uint8_t uia4:1;,
            uint8_t uia5:1;,
            uint8_t uia6:1;,
            uint8_t uia7:1;)
        };
        uint8_t uia; 
    };
    union { 
        struct {
        ED8(uint8_t spare2:1;,
            uint8_t gea1:1;,
            uint8_t gea2:1;,
            uint8_t gea3:1;,
            uint8_t gea4:1;,
            uint8_t gea5:1;,
            uint8_t gea6:1;,
            uint8_t gea7:1;)
        };
        uint8_t gea; 
    };
} __attribute__ ((packed)) ogs_nas_s1_ue_security_capability_t;

/* 9.11.3.49 Service area list
 * O TLV 6-114 */
#define OGS_NAS_MAX_SERVICE_AREA_LIST_LEN 112
typedef struct ogs_nas_service_area_list_s {
    uint8_t length;
    uint8_t buffer[112];
} ogs_nas_service_area_list_t;

/* 9.11.3.50 Service type
 * M V 1/2 */
#define OGS_NAS_SERVICE_TYPE_SIGNALLING 0
#define OGS_NAS_SERVICE_TYPE_DATA 1
#define OGS_NAS_SERVICE_TYPE_MOBILE_TERMINATED_SERVICES 2
#define OGS_NAS_SERVICE_TYPE_EMERGENCY_SERVICES 3
#define OGS_NAS_SERVICE_TYPE_EMERGENCY_SERVICES_FALLBACK 4
#define OGS_NAS_SERVICE_TYPE_HIGH_PRIORITY_ACCESS 5
#define OGS_NAS_SERVICE_TYPE_ELEVATED_SIGNALLING 6
/* 7(unused) shall be interpreted as "signalling", if received by the network
 * 8(unused) shall be interpreted as "signalling", if received by the network
 * 9(unused) shall be interpreted as "signalling", if received by the network
 * 10(unused) shall be interpreted as "data", if received by the network
 * 11(unused) shall be interpreted as "data", if received by the network */
typedef struct ogs_nas_service_type_s {
ED2(uint8_t type:4;,
    uint8_t value:4;)
} __attribute__ ((packed)) ogs_nas_service_type_t;

/* 9.11.3.50A SMS indication
 * O TV 1 */
typedef struct ogs_nas_sms_indication_s {
ED2(uint8_t type:4;,
    uint8_t sai:4;)
} ogs_nas_sms_indication_t;

/* 9.11.3.51 SOR transparent container
 * O TLV-E 20-n */
typedef struct ogs_nas_sor_transparent_container_s {
    uint8_t length;
    uint8_t *buffer;
} ogs_nas_sor_transparent_container_t;

/* 9.11.3.54 UE security capability
 * O TLV 4-10 */
typedef struct ogs_nas_ue_security_capability_s {
    uint8_t length;
    union { 
        struct {
        ED8(uint8_t ea0_5g:1;,
            uint8_t ea1_5g_128:1;,
            uint8_t ea2_5g_128:1;,
            uint8_t ea3_5g_128:1;,
            uint8_t ea4_5g:1;,
            uint8_t ea5_5g:1;,
            uint8_t ea6_5g:1;,
            uint8_t ea7_5g:1;)
        };
        uint8_t ea_5g; 
    };
    union { 
        struct {
        ED8(uint8_t ia0_5g:1;,
            uint8_t ia1_5g_128:1;,
            uint8_t ia2_5g_128:1;,
            uint8_t ia3_5g_128:1;,
            uint8_t ia4_5g:1;,
            uint8_t ia5_5g:1;,
            uint8_t ia6_5g:1;,
            uint8_t ia7_5g:1;)
        };
        uint8_t ia_5g; 
    };
    union { 
        struct {
        ED8(uint8_t eea0:1;,
            uint8_t eea1_128:1;,
            uint8_t eea2_128:1;,
            uint8_t eea3_128:1;,
            uint8_t eea4:1;,
            uint8_t eea5:1;,
            uint8_t eea6:1;,
            uint8_t eea7:1;)
        };
        uint8_t ea; 
    };
    union { 
        struct {
        ED8(uint8_t eia0:1;,
            uint8_t eia1_128:1;,
            uint8_t eia2_128:1;,
            uint8_t eia3_128:1;,
            uint8_t eia4:1;,
            uint8_t eia5:1;,
            uint8_t eia6:1;,
            uint8_t eia7:1;)
        };
        uint8_t ia; 
    };
} __attribute__ ((packed)) ogs_nas_ue_security_capability_t;

/* 9.11.3.55 UE usage setting
 * O TLV 3 */
typedef struct ogs_nas_ue_usage_setting_s {
    uint8_t length;
ED2(uint8_t spare:6;,
    uint8_t value:2;)
} __attribute__ ((packed)) ogs_nas_ue_usage_setting_t;

/* 9.11.3.56 UE status
 * O TLV 3 */
typedef struct ogs_nas_ue_status_s {
    uint8_t length;
ED3(uint8_t spare:6;,
    uint8_t n1:1;,
    uint8_t s1:1;)
} __attribute__ ((packed)) ogs_nas_ue_status_t;

/* 9.11.3.57 Uplink data status
 * O TLV 4-34 */
typedef ogs_nas_allowed_pdu_session_status_t ogs_nas_uplink_data_status_t;

/* 9.11.3.68 UE radio capability ID
 * O TLV 3-n */
#define OGS_NAS_MAX_UE_RADIO_CAPABILITY_ID_LEN 255
typedef struct ogs_nas_ue_radio_capability_id_s {
    uint8_t length;
    uint8_t buffer[OGS_NAS_MAX_UE_RADIO_CAPABILITY_ID_LEN];
} ogs_nas_ue_radio_capability_id_t;

/* 9.11.3.69 UE radio capability ID deletion infication
 * O TV 1 */
typedef struct ogs_nas_ue_radio_capability_id_deletion_indication_s {
ED3(uint8_t type:4;,
    uint8_t spare:1;,
    uint8_t value:3;)
} __attribute__ ((packed)) ogs_nas_ue_radio_capability_id_deletion_indication_t;

/* 9.11.3.70 Truncated 5G-S-TMSI configuration
 * O TLV 3 */
typedef struct ogs_nas_truncated_5g_s_tmsi_configuration_s {
    uint8_t length;
ED2(uint8_t amf_set_id:4;,
    uint8_t amf_pointer_value:4;)
} __attribute__ ((packed))  ogs_nas_truncated_5g_s_tmsi_configuration_t;

/* 9.11.4.1 5GSM capability
 * O TLV 3-15 */
typedef struct ogs_nas_5gsm_capability_s {
    uint8_t length;
ED3(uint8_t spare:6;,
    uint8_t mh6_pdu:1;,
    uint8_t rqos:1;)
} __attribute__ ((packed)) ogs_nas_5gsm_capability_t;

/* 9.11.4.2 5GSM cause
 * O TV 2 */
#define OGS_NAS_GSM_OPERATOR_DETERMINED_BARRING 8
#define OGS_NAS_GSM_INSUFFICIENT_RESOURCES 26
#define OGS_NAS_GSM_MISSING_OR_UNKNOWN_DNN 27
#define OGS_NAS_GSM_UNKNOWN_PDU_SESSION_TYPE 28
#define OGS_NAS_GSM_USER_AUTHENTICATION_OR_AUTHORIZATION_FAILED 29
#define OGS_NAS_GSM_REQUEST_REJECTED_UNSPECIFIED 31
#define OGS_NAS_GSM_SERVICE_OPTION_NOT_SUPPORTED 32
#define OGS_NAS_GSM_REQUESTED_SERVICE_OPTION_NOT_SUBSCRIBED 33
#define OGS_NAS_GSM_SERVICE_OPTION_TEMPORARILY_OUT_OF_ORDER 34
#define OGS_NAS_GSM_PTI_ALREADY_IN_USE 35
#define OGS_NAS_GSM_REGULAR_DEACTIVATION 36
#define OGS_NAS_GSM_NETWORK_FAILURE 38
#define OGS_NAS_GSM_REACTIVATION_REQUESTED 39
#define OGS_NAS_GSM_INVALID_PDU_SESSION_IDENTITY 43
#define OGS_NAS_GSM_SEMANTIC_ERRORS_IN_PACKET_FILTERS 44
#define OGS_NAS_GSM_SYNTACTICAL_ERROR_IN_PACKET_FILTERS 45
#define OGS_NAS_GSM_OUT_OF_LADN_SERVICE_AREA  46
#define OGS_NAS_GSM_PTI_MISMATCH 47
#define OGS_NAS_GSM_PDU_SESSION_TYPE_IPV4_ONLY_ALLOWED 50
#define OGS_NAS_GSM_PDU_SESSION_TYPE_IPV6_ONLY_ALLOWED 51
#define OGS_NAS_GSM_PDU_SESSION_DOES_NOT_EXIST 54
#define OGS_NAS_GSM_INSUFFICIENT_RESOURCES_FOR_SPECIFIC_SLICE_AND_DNN 67
#define OGS_NAS_GSM_NOT_SUPPORTED_SSC_MODE 68
#define OGS_NAS_GSM_INSUFFICIENT_RESOURCES_FOR_SPECIFIC_SLICE 69
#define OGS_NAS_GSM_MISSING_OR_UNKNOWN_DNN_IN_A_SLICE 70
#define OGS_NAS_GSM_INVALID_PTI_VALUE 81
#define OGS_NAS_GSM_MAXIMUM_DATA_RATE_PER_UE_FOR_USER_PLANE_INTEGRITY_PROTECTION_IS_TOO_LOW 82
#define OGS_NAS_GSM_SEMANTIC_ERROR_IN_THE_QOS_OPERATION 83
#define OGS_NAS_GSM_SYNTACTICAL_ERROR_IN_THE_QOS_OPERATION 84
#define OGS_NAS_GSM_INVALID_MAPPED_EPS_BEARER_IDENTITY 85
#define OGS_NAS_GSM_SEMANTICALLY_INCORRECT_MESSAGE 95
#define OGS_NAS_GSM_INVALID_MANDATORY_INFORMATION 96
#define OGS_NAS_GSM_MESSAGE_TYPE_NON_EXISTENT_OR_NOT_IMPLEMENTED 97
#define OGS_NAS_GSM_MESSAGE_TYPE_NOT_COMPATIBLE_WITH_THE_PROTOCOL_STATE 98
#define OGS_NAS_GSM_INFORMATION_ELEMENT_NON_EXISTENT_OR_NOT IMPLEMENTED 99
#define OGS_NAS_GSM_CONDITIONAL_IE_ERROR 100
#define OGS_NAS_GSM_MESSAGE_NOT_COMPATIBLE_WITH_THE_PROTOCOL_STATE 101
#define OGS_NAS_GSM_PROTOCOL_ERROR_UNSPECIFIED 111
typedef uint8_t ogs_nas_5gsm_cause_t;

/* 9.11.4.21 5GSM congestion re-attempt indicator
 * O TLV 3 */
typedef struct ogs_nas_5gsm_congestion_re_attempt_indicator_s {
    uint8_t length;
ED2(uint8_t spare:7;,
    uint8_t abo:1;)
} __attribute__ ((packed)) ogs_nas_5gsm_congestion_re_attempt_indicator_t;

/* 9.11.4.3 Always-on PDU session indication
 * O TV 1 */
typedef struct ogs_nas_always_on_pdu_session_indication_s {
ED3(uint8_t type:4;,
    uint8_t spare:1;,
    uint8_t apsi:3;)
} __attribute__ ((packed)) ogs_nas_always_on_pdu_session_indication_t;

/* 9.11.4.4 Always-on PDU session requested
 * O TV 1 */
typedef struct ogs_nas_always_on_pdu_session_requested_s {
ED3(uint8_t type:4;,
    uint8_t spare:3;,
    uint8_t apsr:1;)
} __attribute__ ((packed)) ogs_nas_always_on_pdu_session_requested_t;

/* 9.11.4.5 Allowed SSC mode
 * O TV 1 */
typedef struct ogs_nas_allowed_ssc_mode_s {
ED5(uint8_t type:4;,
    uint8_t spare:1;,
    uint8_t ssc3:1;,
    uint8_t ssc2:1;,
    uint8_t ssc1:1;)
} __attribute__ ((packed)) ogs_nas_allowed_ssc_mode_t;

/* 9.11.4.7 Integrity protection maximum data rate
 * M V 2 */
typedef struct ogs_nas_integrity_protection_maximum_data_rate_s {
    uint8_t ul;
    uint8_t dl;
} __attribute__ ((packed)) ogs_nas_integrity_protection_maximum_data_rate_t;

/* 9.11.4.8 Mapped EPS bearer contexts
 * O TLV-E 7-65535 */
typedef struct ogs_nas_mapped_eps_bearer_contexts_s {
    uint8_t length;
    uint8_t *buffer;
} __attribute__ ((packed)) ogs_nas_mapped_eps_bearer_contexts_t;

/* 9.11.4.9 Maximum number of supported packet filters
 * O TV 3 */
typedef struct ogs_nas_maximum_number_of_supported_packet_filters_s {
    uint8_t max1;
ED2(uint8_t max2:3;,
    uint8_t spare:5;)
} __attribute__ ((packed)) ogs_nas_maximum_number_of_supported_packet_filters_t;

/* 9.11.4.10 PDU address
 * O TLV 7, 11 or 15 */
#define OGS_NAS_PDU_ADDRESS_TYPE_IPV4 1
#define OGS_NAS_PDU_ADDRESS_TYPE_IPV6 2
#define OGS_NAS_PDU_ADDRESS_TYPE_IPV4V6 3
typedef struct ogs_nas_pdu_address_s {
    uint8_t length;
ED2(uint8_t reserved:5;,
    uint8_t type:3;)
    union {
        uint32_t addr;      
        struct {
            uint8_t addr6[OGS_IPV6_LEN>>1]; /* Interface Identifer Only */
        };
        struct {
            uint8_t addr6[OGS_IPV6_LEN>>1]; /* Interface Identifer Only */
            uint32_t addr;      
        } both;
    };
} __attribute__ ((packed)) ogs_nas_pdu_address_t;

/* 9.11.4.11 PDU session type
 * O TV 1 */
#define OGS_NAS_PDU_SESSION_TYPE_IPV4 1
#define OGS_NAS_PDU_SESSION_TYPE_IPV6 2
#define OGS_NAS_PDU_SESSION_TYPE_IPV4V6 3
#define OGS_NAS_PDU_SESSION_TYPE_UNSTRUCTURED 4
#define OGS_NAS_PDU_SESSION_TYPE_ETHERNET 5
typedef struct ogs_nas_pdu_session_type_s {
ED3(uint8_t type:4;,
    uint8_t spare:1;,
    uint8_t value:3;)
} __attribute__ ((packed)) ogs_nas_pdu_session_type_t;

/* 9.11.4.12 QoS flow descriptions
 * O TLV-E 6-65535 */
typedef struct ogs_nas_qos_flow_descriptions_s {
    uint8_t length;
    uint8_t *buffer;
} ogs_nas_qos_flow_descriptions_t;

/* 9.11.4.13 QoS rules
 * M LV-E 6-65535 */
typedef struct ogs_nas_qos_rules_s {
    uint8_t length;
    uint8_t *buffer;
} ogs_nas_qos_rules_t;

/* 9.11.4.14 Session-AMBR
 * M LV 7 */
#define OGS_NAS_BR_UNIT_1K      1
#define OGS_NAS_BR_UNIT_4K      2
#define OGS_NAS_BR_UNIT_16K     3
#define OGS_NAS_BR_UNIT_64K     4
#define OGS_NAS_BR_UNIT_256K    5
#define OGS_NAS_BR_UNIT_1M      6
#define OGS_NAS_BR_UNIT_4M      7
#define OGS_NAS_BR_UNIT_16M     8
#define OGS_NAS_BR_UNIT_64M     9
#define OGS_NAS_BR_UNIT_256M    10
#define OGS_NAS_BR_UNIT_1G      11
#define OGS_NAS_BR_UNIT_4G      12
#define OGS_NAS_BR_UNIT_16G     13
#define OGS_NAS_BR_UNIT_64G     14
#define OGS_NAS_BR_UNIT_256G    15
#define OGS_NAS_BR_UNIT_1T      16
#define OGS_NAS_BR_UNIT_4T      17
#define OGS_NAS_BR_UNIT_16T     18
#define OGS_NAS_BR_UNIT_64T     19
#define OGS_NAS_BR_UNIT_256T    20
#define OGS_NAS_BR_UNIT_1P      21
#define OGS_NAS_BR_UNIT_4P      22
#define OGS_NAS_BR_UNIT_16P     23
#define OGS_NAS_BR_UNIT_64P     24
#define OGS_NAS_BR_UNIT_256P    25
typedef struct ogs_nas_session_ambr_s {
    uint8_t length;
    uint8_t dl_unit;
    uint16_t dl;
    uint8_t ul_unit;
    uint16_t ul;
} __attribute__ ((packed)) ogs_nas_session_ambr_t;

/* 9.11.4.15 SM PDU DN request container
 * O TLV 3-255 */
#define OGS_NAX_MAX_SM_PDU_DN_REQUESTER_CONTAINER 255
typedef struct ogs_nas_sm_pdu_dn_request_container_s {
    uint8_t length;
    uint8_t buffer[OGS_NAX_MAX_SM_PDU_DN_REQUESTER_CONTAINER];
} ogs_nas_sm_pdu_dn_request_container_t;

/* 9.11.4.16 SSC mode
 * O TV 1 */
#define OGS_NAS_SSC_MODE_1 1
#define OGS_NAS_SSC_MODE_2 2
#define OGS_NAS_SSC_MODE_3 3
/* 4(unused) shall be interpreted as "SSC mode 1", if received by the network */
/* 5(unused) shall be interpreted as "SSC mode 2", if received by the network */
/* 6(unused) shall be interpreted as "SSC mode 3", if received by the network */
typedef struct ogs_nas_ssc_mode_s {
ED3(uint8_t type:4;,
    uint8_t spare:1;,
    uint8_t value:3;)
} __attribute__ ((packed)) ogs_nas_ssc_mode_t;

/* 9.11.4.18 5GSM network feature support
 * O TLV 3-15 */
typedef struct ogs_nas_5gsm_network_feature_support_s {
    uint8_t length;
ED2(uint8_t spare:7;,
    uint8_t s1:1;)
} __attribute__ ((packed)) ogs_nas_5gsm_network_feature_support_t;

/* 9.11.4.22 ATSSS container
 * O TLV-E 3-65535 */
typedef struct ogs_nas_atsss_container_s {
    uint8_t length;
    uint8_t *buffer;
} ogs_nas_atsss_container_t;

/* 9.9.4.25 Release assistance indication
 * O TV 1
 *
 * Release assistance indication value
 *
 * Downlink data expected (DDX)
 *
 * Bits
 * 0 0 No information regarding DDX is conveyed by the information element.
 *     If received it shall be interpreted as 'neither value "01" nor "10"
 *     applies
 * 0 1 No further uplink or downlink data transmission subsequent to the
 *     uplink data transmission is expected
 * 1 0 Only a single downlink data transmission and no further uplink data
 *     transmission subsequent to the uplink data transmission is expected
 * 1 1 reserved */
typedef struct ogs_nas_release_assistance_indication_s {
ED3(uint8_t type:4;,
    uint8_t spare:2;,
    uint8_t value:2;)
} __attribute__ ((packed)) ogs_nas_release_assistance_indication_t;

/* 9.11.4.25 DS-TT Ethernet port MAC address
 * O TLV 8 */
#define OGS_NAX_MAX_EHTERNET_MAC_ADDRESS_LEN 6
typedef struct ogs_nas_ds_tt_ethernet_port_mac_address_s {
    uint8_t length;
    uint8_t buffer[OGS_NAX_MAX_EHTERNET_MAC_ADDRESS_LEN];
} ogs_nas_ds_tt_ethernet_port_mac_address_t;

/* 9.11.4.26 UE-DS-TT residence time
 * O TLV 10 */
#define OGS_NAS_MAX_UE_DS_TT_REDISENCE_TIME_LEN 8
typedef struct ogs_nas_ue_ds_tt_residence_time_s {
    uint8_t length;
    uint8_t buffer[OGS_NAS_MAX_UE_DS_TT_REDISENCE_TIME_LEN];
} ogs_nas_ue_ds_tt_residence_time_t;

/* 9.11.4.27 Port management information container
 * O TLV-E 4-65535 */
typedef struct ogs_nas_port_management_information_container_s {
    uint8_t length;
    uint8_t *buffer;
} ogs_nas_port_management_information_container_t;









/* 9.11.3.72 N5GC indication
 * O T 1 */
typedef struct ogs_nas_n5gc_indication_s {
    uint8_t length;
} ogs_nas_n5gc_indication_t;


#ifdef __cplusplus
}
#endif

#endif /* OGS_NAS_5GS_TYPES_H */
