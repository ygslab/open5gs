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

#ifndef OGS_NAS_COMMON_TYPES_H
#define OGS_NAS_COMMON_TYPES_H

#include "ogs-core.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OGS_NAS_CLEAR_DATA(__dATA) \
    do { \
        ogs_assert((__dATA)); \
        if ((__dATA)->buffer) { \
            ogs_free((__dATA)->buffer); \
            (__dATA)->buffer = NULL; \
            (__dATA)->length = 0; \
        } \
    } while(0)
#define OGS_NAS_STORE_DATA(__dST, __sRC) \
    do { \
        ogs_assert((__sRC)); \
        ogs_assert((__sRC)->buffer); \
        ogs_assert((__dST)); \
        OGS_NAS_CLEAR_DATA(__dST); \
        (__dST)->length = (__sRC)->length; \
        (__dST)->buffer = ogs_calloc((__dST)->length, sizeof(uint8_t)); \
        memcpy((__dST)->buffer, (__sRC)->buffer, (__dST)->length); \
    } while(0)

#define OGS_NAS_KSI_NO_KEY_IS_AVAILABLE             0x7

/**********************************
 * NAS PLMN_ID Structure             */
typedef struct ogs_nas_plmn_id_s {
ED2(uint8_t mcc2:4;,
    uint8_t mcc1:4;)
ED2(uint8_t mnc3:4;,
    uint8_t mcc3:4;)
ED2(uint8_t mnc2:4;,
    uint8_t mnc1:4;)
} __attribute__ ((packed)) ogs_nas_plmn_id_t;

void *ogs_nas_from_plmn_id(
        ogs_nas_plmn_id_t *ogs_nas_plmn_id, ogs_plmn_id_t *plmn_id);
void *ogs_nas_to_plmn_id(
        ogs_plmn_id_t *plmn_id, ogs_nas_plmn_id_t *ogs_nas_plmn_id);

typedef struct ogs_nas_guti_s {
    ogs_nas_plmn_id_t nas_plmn_id;
    uint16_t mme_gid;
    uint8_t mme_code;
    uint32_t m_tmsi;
} __attribute__ ((packed)) ogs_nas_guti_t;

/* 9.9.2.0 Additional information
 * O TLV 3-n */
#define NAX_MAX_ADDITIONAL_INFORMATION_LEN 255
typedef struct ogs_nas_additional_information_s {
    uint8_t length;
    uint8_t buffer[NAX_MAX_ADDITIONAL_INFORMATION_LEN];
} __attribute__ ((packed)) ogs_nas_additional_information_t;

/* 9.9.2.1 EPS bearer context status
 * O TLV 4 */
typedef struct ogs_nas_eps_bearer_context_status_s {
    uint8_t length;
ED8(uint8_t ebi7:1;,
    uint8_t ebi6:1;,
    uint8_t ebi5:1;,
    uint8_t ebi4:1;,
    uint8_t ebi3:1;,
    uint8_t ebi2:1;,
    uint8_t ebi1:1;,
    uint8_t ebi0:1;)
ED8(uint8_t ebi15:1;,
    uint8_t ebi14:1;,
    uint8_t ebi13:1;,
    uint8_t ebi12:1;,
    uint8_t ebi11:1;,
    uint8_t ebi10:1;,
    uint8_t ebi9:1;,
    uint8_t ebi8:1;)
} __attribute__ ((packed)) ogs_nas_eps_bearer_context_status_t;

/* 9.9.2.3 Mobile identity
 * See subclause 10.5.1.4 in 3GPP TS 24.008 [13].
 * O TLV 7-10 */
#define OGS_NAS_MOBILE_IDENTITY_NONE 0
#define OGS_NAS_MOBILE_IDENTITY_IMSI 1
#define OGS_NAS_MOBILE_IDENTITY_IMEI 2
#define OGS_NAS_MOBILE_IDENTITY_IMEISV 3
#define OGS_NAS_MOBILE_IDENTITY_TMSI 4
#define OGS_NAS_MOBILE_IDENTITY_TMGI 5
#define OGS_NAS_MOBILE_IDENTITY_GUTI 6
typedef struct ogs_nas_mobile_identity_imsi_s {
ED3(uint8_t digit1:4;,
    uint8_t odd_even:1;,
    uint8_t type:3;)
ED2(uint8_t digit3:4;,
    uint8_t digit2:4;)
ED2(uint8_t digit5:4;,
    uint8_t digit4:4;)
ED2(uint8_t digit7:4;,
    uint8_t digit6:4;)
ED2(uint8_t digit9:4;,
    uint8_t digit8:4;)
ED2(uint8_t digit11:4;,
    uint8_t digit10:4;)
ED2(uint8_t digit13:4;,
    uint8_t digit12:4;)
ED2(uint8_t digit15:4;,
    uint8_t digit14:4;)
} __attribute__ ((packed)) ogs_nas_mobile_identity_imsi_t;

typedef struct ogs_nas_mobile_identity_tmsi_s {
ED3(uint8_t spare:4;,
    uint8_t odd_even:1;,
    uint8_t type:3;)
    uint32_t tmsi;
} __attribute__ ((packed)) ogs_nas_mobile_identity_tmsi_t;

typedef struct ogs_nas_mobile_identity_tmgi_s {
ED5(uint8_t spare:2;,
    uint8_t mbms_session_id:1;,
    uint8_t mcc_mnc:1;,
    uint8_t odd_even:1;,
    uint8_t type:3;)
    uint8_t mbms_servicec_id[3];
    ogs_nas_plmn_id_t nas_plmn_id;
    uint8_t mbms_session_identity;
} __attribute__ ((packed)) ogs_nas_mobile_identity_tmgi_t;

typedef struct ogs_nas_mobile_identity_imeisv_s {
ED3(uint8_t digit1:4;,
    uint8_t odd_even:1;,
    uint8_t type:3;)
ED2(uint8_t digit3:4;,
    uint8_t digit2:4;)
ED2(uint8_t digit5:4;,
    uint8_t digit4:4;)
ED2(uint8_t digit7:4;,
    uint8_t digit6:4;)
ED2(uint8_t digit9:4;,
    uint8_t digit8:4;)
ED2(uint8_t digit11:4;,
    uint8_t digit10:4;)
ED2(uint8_t digit13:4;,
    uint8_t digit12:4;)
ED2(uint8_t digit15:4;,
    uint8_t digit14:4;)
ED2(uint8_t digit17:4;,
    uint8_t digit16:4;)
} __attribute__ ((packed)) ogs_nas_mobile_identity_imeisv_t;

typedef struct ogs_nas_mobile_identity_s {
    uint8_t length;
    union {
        ogs_nas_mobile_identity_imsi_t imsi;
        ogs_nas_mobile_identity_tmsi_t tmsi;
        ogs_nas_mobile_identity_tmgi_t tmgi;
        ogs_nas_mobile_identity_imeisv_t imeisv;
    };
} ogs_nas_mobile_identity_t;

/* 9.9.2.4 Mobile station classmark 2
 * See subclause 10.5.1.6 in 3GPP TS 24.008
 * O TLV 5 */
#define OGS_NAS_MS_CLASSMARK_2_REVISION_GSM_PHASE1 0
#define OGS_NAS_MS_CLASSMARK_2_REVISION_GSM_PHASE2 1
#define OGS_NAS_MS_CLASSMARK_2_REVISION_R99 2
#define OGS_NAS_MS_CLASSMARK_2_REVISION_RESERVED 2

#define OGS_NAS_MS_CLASSMARK_2_RF_CLASS1 0
#define OGS_NAS_MS_CLASSMARK_2_RF_CLASS2 1
#define OGS_NAS_MS_CLASSMARK_2_RF_CLASS3 2
#define OGS_NAS_MS_CLASSMARK_2_RF_CLASS4 3
#define OGS_NAS_MS_CLASSMARK_2_RF_CLASS5 4
#define OGS_NAS_MS_CLASSMARK_2_RF_IRRELEVANT 7
typedef struct ogs_nas_mobile_station_classmark_2_t {
    uint8_t length;
ED5(uint8_t spare1:1;,
    uint8_t revision_level:2;, 
    uint8_t es_ind:1;,
    uint8_t a5_1:1;,
    uint8_t rf_power_capability:3;)
ED7(uint8_t spare:1;,
    uint8_t ps_capa:1;,
    uint8_t ss_screen_indicator:2;,
    uint8_t sm_capabi:1;,
    uint8_t vbs:1;,
    uint8_t vgcs:1;,
    uint8_t fc:1;)
ED8(uint8_t cm3:1;,
    uint8_t spare2:1;,
    uint8_t lcsva_cap:1;,
    uint8_t ucs2:1;,
    uint8_t solsa:1;,
    uint8_t cmsp:1;,
    uint8_t a5_3:1;,
    uint8_t a5_2:1;)
} __attribute__ ((packed)) ogs_nas_mobile_station_classmark_2_t;

/* 9.9.2.8 PLMN list
 * See subclause 10.5.1.13 in 3GPP TS 24.008 [13].
 * O TLV 5-47 */
#define OGS_NAS_MAX_PLMN 15
typedef struct ogs_nas_plmn_list_s {
    uint8_t length;
    ogs_nas_plmn_id_t nas_plmn_id[OGS_NAS_MAX_PLMN];
} __attribute__ ((packed)) ogs_nas_plmn_list_t;

/* 9.9.2.10 Supported codec list
 * See subclause 10.5.4.32 in 3GPP TS 24.008 [13].
 * O TLV 5-n */
typedef struct ogs_nas_supported_codec_item_s {
    uint8_t system_identification;
    uint8_t length_of_bitmap;
    uint16_t codec_bitmap;
} __attribute__ ((packed)) ogs_nas_supported_codec_item_t;

#define OGS_NAS_MAX_SUPPORTED_CODECS 8
typedef struct ogs_nas_supported_codec_list_s {
    uint8_t length;
    ogs_nas_supported_codec_item_t item[OGS_NAS_MAX_SUPPORTED_CODECS];
} __attribute__ ((packed)) ogs_nas_supported_codec_list_t;

/* 9.9.3.1 Authentication failure parameter
 * See subclause 10.5.3.2.2 in 3GPP TS 24.008 [13].
 * O TLV 16 */
typedef struct ogs_nas_authentication_failure_parameter_s {
    uint8_t length;
    uint8_t auts[OGS_AUTS_LEN];
} __attribute__ ((packed)) ogs_nas_authentication_failure_parameter_t;

/* 9.9.3.2 Authentication parameter AUTN
 * See subclause 10.5.3.1.1 in 3GPP TS 24.008 [13].
 * M LV 17 */
typedef struct ogs_nas_authentication_parameter_autn_s {
    uint8_t length;
    uint8_t autn[OGS_AUTN_LEN];
} ogs_nas_authentication_parameter_autn_t;

/* 9.9.3.3 Authentication parameter RAND
 * See subclause 10.5.3.1 in 3GPP TS 24.008 [13].
 * M V 16 */
typedef struct ogs_nas_authentication_parameter_rand_s {
    uint8_t rand[OGS_RAND_LEN];
} ogs_nas_authentication_parameter_rand_t;

/* 9.9.3.4 Authentication response parameter
 * M LV 5-17 */
typedef struct ogs_nas_authentication_response_parameter_s {
    uint8_t length;
    uint8_t res[OGS_MAX_RES_LEN];
} ogs_nas_authentication_response_parameter_t;

/* 9.9.3.6 Daylight saving time
 * See subclause 10.5.3.12 in 3GPP TS 24.008 [13].
 * O TLV 3 */
#define OGS_NAS_NO_ADJUSTMENT_FOR_DAYLIGHT_SAVING_TIME              0
#define OGS_NAS_PLUS_1_HOUR_ADJUSTMENT_FOR_DAYLIGHT_SAVING_TIME     1
#define OGS_NAS_PLUS_2_HOURS_ADJUSTMENT_FOR_DAYLIGHT_SAVING_TIME    2
typedef struct ogs_nas_daylight_saving_time_s {
    uint8_t length;
ED2(uint8_t spare:6;,
    uint8_t value:2;)
} __attribute__ ((packed)) ogs_nas_daylight_saving_time_t;

/* 9.9.3.16 GPRS timer
 * See subclause 10.5.7.3 in 3GPP TS 24.008 [13].
 * M V 1 or  O TV 2 */
#define OGS_NAS_GRPS_TIMER_UNIT_MULTIPLES_OF_2_SS       0
#define OGS_NAS_GRPS_TIMER_UNIT_MULTIPLES_OF_1_MM       1
#define OGS_NAS_GRPS_TIMER_UNIT_MULTIPLES_OF_DECI_HH    2
#define OGS_NAS_GRPS_TIMER_UNIT_DEACTIVATED             7
typedef struct ogs_nas_gprs_timer_s {
ED2(uint8_t unit:3;,
    uint8_t value:5;)
} __attribute__ ((packed)) ogs_nas_gprs_timer_t;

/* 9.9.3.16A GPRS timer 2
 * See subclause 10.5.7.4 in 3GPP TS 24.008 [13].
 * O TLV 3 */
typedef struct ogs_nas_gprs_timer_2_s {
    uint8_t length;
    uint8_t gprs_timer_2_value;
} __attribute__ ((packed)) ogs_nas_gprs_timer_2_t;

/* 9.9.3.16B GPRS timer 3
 * See subclause 10.5.7.4a in 3GPP TS 24.008 [13].
 * O TLV 3 */
#define OGS_NAS_GRPS_TIMER_3_UNIT_MULTIPLES_OF_10_MM    0
#define OGS_NAS_GRPS_TIMER_3_UNIT_MULTIPLES_OF_1_HH     1
#define OGS_NAS_GRPS_TIMER_3_UNIT_MULTIPLES_OF_10_HH    2
#define OGS_NAS_GRPS_TIMER_3_UNIT_MULTIPLES_OF_2_SS     3 
#define OGS_NAS_GRPS_TIMER_3_UNIT_MULTIPLES_OF_30_SS    4
#define OGS_NAS_GRPS_TIMER_3_UNIT_MULTIPLES_OF_1_MM     5
#define OGS_NAS_GRPS_TIMER_3_UNIT_MULTIPLES_OF_320_HH   6
#define OGS_NAS_GRPS_TIMER_3_UNIT_DEACTIVATED           7

typedef struct ogs_nas_gprs_timer_3_s {
    uint8_t length;
ED2(uint8_t unit:3;,
    uint8_t timer_value:5;)
} __attribute__ ((packed)) ogs_nas_gprs_timer_3_t;

/* 9.9.3.18 IMEISV request
 * See subclause 10.5.5.10 in 3GPP TS 24.008 [13].
 * O TV 1 */
typedef struct ogs_nas_imeisv_request_s {
#define OGS_NAS_IMEISV_TYPE                     0xc
ED3(uint8_t type:4;,
    uint8_t spare:1;,
#define OGS_NAS_IMEISV_NOT_REQUESTED            0
#define OGS_NAS_IMEISV_REQUESTED                1
    uint8_t imeisv_request_value:3;)
} __attribute__ ((packed)) ogs_nas_imeisv_request_t;

/* 9.9.3.21 NAS key set identifier
 * M V 1/2
 * 9.9.2.9 Spare half octet
 * M V 1/2 */
typedef struct ogs_nas_key_set_identifier_s {
ED3(uint8_t type:4;,
    uint8_t tsc:1;,
    uint8_t value:3;)
} __attribute__ ((packed)) ogs_nas_key_set_identifier_t;

/* 9.9.3.24 Network name
 * See subclause 10.5.3.5a in 3GPP TS 24.008 [13].
 * O TLV 3-n */
#define OGS_NAS_MAX_NETWORK_NAME_LEN 255
typedef struct ogs_nas_network_name_s {
    uint8_t length;
ED4(uint8_t ext:1;,
    uint8_t coding_scheme:3;,
    uint8_t add_ci:1;,
    uint8_t number_of_spare_bits_in_last_octet:3;)
    uint8_t name[OGS_NAS_MAX_NETWORK_NAME_LEN];
} __attribute__ ((packed)) ogs_nas_network_name_t;

/* 9.9.3.29 Time zone
 * See subclause 10.5.3.8 in 3GPP TS 24.008 [13].
 * O TV 2 */
typedef uint8_t ogs_nas_time_zone_t;

/* 9.9.3.30 Time zone and time
 * See subclause 10.5.3.9 in 3GPP TS 24.008 [13].
 * 9.2.3.11 TPServiceCentreTimeStamp (TPSCTS) in 3GPP TS 23.040 [90]
 * O TV 8 */
#define OGS_OGS_NAS_TIME_TO_BCD(x) OGS_TIME_TO_BCD(x)
typedef struct ogs_nas_time_zone_and_time_s {
    uint8_t year;
    uint8_t mon;
    uint8_t mday;
    uint8_t hour;
    uint8_t min;
    uint8_t sec;
    /* The Time Zone indicates the difference, expressed in quarters of an hour,
     * between the local time and GMT. In the first of the two semi-octets, 
     * the first bit (bit 3 of the seventh octet of 
     * the TP-Service-Centre-Time-Stamp field) represents 
     * the algebraic sign of this difference (0: positive, 1: negative). */
    uint8_t timezone;  
} ogs_nas_time_zone_and_time_t;

/* 9.9.3.32 Tracking area identity
 * O TV 6 */
typedef struct ogs_nas_tracking_area_identity_s {
    ogs_nas_plmn_id_t nas_plmn_id;
    uint16_t tac;
} __attribute__ ((packed)) ogs_nas_tracking_area_identity_t;

typedef ogs_nas_tracking_area_identity_t ogs_nas_tai_t;

/* 9.9.3.33 Tracking area identity list
 * M LV 7-97 */
#define OGS_NAS_MAX_TAI_LIST_LEN        96
#define TAI0_TYPE                   0
#define TAI1_TYPE                   1
#define TAI2_TYPE                   2
typedef struct tai0_list_s {
    struct {
    ED3(uint8_t spare:1;,
        uint8_t type:2;,
        uint8_t num:5;)
        /*
         * Do not change 'ogs_plmn_id_t' to 'ogs_nas_plmn_id_t'.
         * Use 'ogs_plmn_id_t' for easy implementation.
         * ogs_nas_tai_list_build() changes to NAS format(ogs_nas_plmn_id_t)
         * and is sent to the UE.
         */
        ogs_plmn_id_t plmn_id;
        uint16_t tac[OGS_MAX_NUM_OF_TAI];
    } __attribute__ ((packed)) tai[OGS_MAX_NUM_OF_TAI];
} __attribute__ ((packed)) tai0_list_t;

typedef struct tai2_list_s {
ED3(uint8_t spare:1;,
    uint8_t type:2;,
    uint8_t num:5;)
    /*
     * Do not change 'ogs_tai_t' to 'ogs_nas_tracking_area_identity_t'.
     * Use 'ogs_tai_t' for easy implementation.
     * ogs_nas_tai_list_build() changes to NAS 
     * format(ogs_nas_tracking_area_identity_t)
     * and is sent to the UE.
     */
    ogs_tai_t tai[OGS_MAX_NUM_OF_TAI];
} __attribute__ ((packed)) tai2_list_t;

typedef struct ogs_nas_tracking_area_identity_list_s {
    uint8_t length;
    uint8_t buffer[OGS_NAS_MAX_TAI_LIST_LEN];
} __attribute__ ((packed)) ogs_nas_tracking_area_identity_list_t;

void ogs_nas_tai_list_build(
        ogs_nas_tracking_area_identity_list_t *target,
        tai0_list_t *source0, tai2_list_t *source2);

/* 9.9.3.34 UE network capability
 * M LV  3-14 */
typedef struct ogs_nas_ue_network_capability_s {
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
        ED8(uint8_t ucs2:1;,
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
ED8(uint8_t prose_dd:1;,
    uint8_t prose:1;,
    uint8_t h_245_ash:1;,
    uint8_t acc_csfb:1;,
    uint8_t lpp:1;,
    uint8_t lcs:1;,
    uint8_t srvcc:1;,
    uint8_t nf:1;)
ED8(uint8_t epco:1;,
    uint8_t hc_cp_ciot:1;,
    uint8_t erw_opdn:1;,
    uint8_t s1u_data:1;,
    uint8_t up_ciot:1;,
    uint8_t cp_ciot:1;,
    uint8_t prose_relay:1;,
    uint8_t prose_dc:1;)
ED2(uint8_t spare:7;,
    uint8_t multiple_drb:1;)
} __attribute__ ((packed)) ogs_nas_ue_network_capability_t;

/* 9.9.3.62 WUS assistance information
 * O TLV 3-n */
#define OGS_MAX_NAS_WUS_ASSISTANCE_INFORAMTION_LEN 255
typedef struct ogs_nas_wus_assistance_information_s {
    uint8_t length;
    uint8_t buffer[OGS_MAX_NAS_WUS_ASSISTANCE_INFORAMTION_LEN];
} ogs_nas_wus_assistance_information_t;

/* 9.11.3.36A Non-3GPP NW provided policies
 * See subclause 10.5.5.37 in 3GPP TS 24.008 [12].
 * O TV 1 */
typedef struct ogs_nas_non_3gpp_nw_provided_policies_s {
ED3(uint8_t type:4;,
    uint8_t apre:3;,
    uint8_t value:3;)
} ogs_nas_non_3gpp_nw_provided_policies_t;

/* buffer : 9.9.3.37 Emergency number list
 * See subclause 10.5.3.13 in 3GPP TS 24.008 [13].
 * O TLV 5-50 */
#define OGS_NAS_MAX_EMERGENCY_NUMBER_LIST_LEN 48
typedef struct ogs_nas_emergency_number_list_s {
    uint16_t length;
    uint8_t buffer[OGS_NAS_MAX_EMERGENCY_NUMBER_LIST_LEN];
} __attribute__ ((packed)) ogs_nas_emergency_number_list_t;

/* 9.9.3.37A Extended emergency number list
 * O TLV-E 7-65535 */
typedef struct ogs_nas_extended_emergency_number_list_s {
    uint8_t length;
    uint8_t *buffer;
} ogs_nas_extended_emergency_number_list_t;

/* 9.9.3.46 Extended DRX parameters
 * See subclause 10.5.5.32 in 3GPP TS 24.008 [13].
 * O TLV 3 */
typedef struct ogs_nas_extended_drx_parameters_s {
    uint8_t length;
ED2(uint8_t paging_time_window:4;,
    uint8_t e_drx_value:4;)
} __attribute__ ((packed)) ogs_nas_extended_drx_parameters_t;

/* 9.9.4.2 APN aggregate maximum bit rate
 * O TLV 4-8  */
typedef struct ogs_nas_apn_aggregate_maximum_bit_rate_s {
    uint8_t length;
    uint8_t dl_apn_ambr;
    uint8_t ul_apn_ambr;
    uint8_t dl_apn_ambr_extended;
    uint8_t ul_apn_ambr_extended;
    uint8_t dl_apn_ambr_extended2;
    uint8_t ul_apn_ambr_extended2;
} __attribute__ ((packed)) ogs_nas_apn_aggregate_maximum_bit_rate_t;

void apn_ambr_build(
    ogs_nas_apn_aggregate_maximum_bit_rate_t * apn_aggregate_maximum_bit_rate,
    uint32_t dl_ambr, uint32_t ul_ambr);

/* 9.9.4.3 EPS quality of service
 * M LV 2-14 */
typedef struct ogs_nas_eps_quality_of_service_s {
    uint8_t length;
    uint8_t qci;
    uint8_t ul_mbr;
    uint8_t dl_mbr;
    uint8_t ul_gbr;
    uint8_t dl_gbr;
    uint8_t ul_mbr_extended;
    uint8_t dl_mbr_extended;
    uint8_t ul_gbr_extended;
    uint8_t dl_gbr_extended;
    uint8_t ul_mbr_extended2;
    uint8_t dl_mbr_extended2;
    uint8_t ul_gbr_extended2;
    uint8_t dl_gbr_extended2;
} ogs_nas_eps_quality_of_service_t;

void eps_qos_build(ogs_nas_eps_quality_of_service_t *eps_qos,
    uint8_t qci,
    uint64_t dl_mbr, uint64_t ul_mbr, uint64_t dl_gbr, uint64_t ul_gbr);

/* 9.9.4.13A Re-attempt indicator
 * O TLV 3 */
typedef struct ogs_nas_re_attempt_indicator_s {
    uint8_t length;
ED3(uint8_t spare:3;,  /* allowed in A/Gb mode or Iu mode */
    uint8_t eplmnc:1;, /* allowed in an equivalent PLMN */
    uint8_t ratc:1;) 
} __attribute__ ((packed)) ogs_nas_re_attempt_indicator_t;

/* 9.9.4.19 NBIFOM container
 * See subclause 10.5.6.21 in 3GPP TS 24.008 [4].
 * O TLV 3-257 */
#define MAX_OGS_NAS_NBIFOM_CONTAINER_LEN 255
typedef struct ogs_nas_nbifom_container_s {
    uint8_t length;
    uint8_t buffer[MAX_OGS_NAS_NBIFOM_CONTAINER_LEN];
} __attribute__ ((packed)) ogs_nas_nbifom_container_t;

/* 9.9.4.22 Header compression configuration
 * O TLV 5-257 */
#define MAX_OGS_NAS_HEADER_COMPRESSION_CONTAINER_LEN 251
typedef struct ogs_nas_header_compression_configuration_s {
    uint8_t length;
ED8(uint8_t spare:1;,
    uint8_t profile0x0104:1;,
    uint8_t profile0x0103:1;,
    uint8_t profile0x0102:1;,
    uint8_t profile0x0006:1;,
    uint8_t profile0x0004:1;,
    uint8_t profile0x0003:1;,
    uint8_t profile0x0002:1;)
    uint16_t max_cid;
#define OGS_NAS_HEADER_COMPRESSION_NO_COMPRESSION           0
#define OGS_NAS_HEADER_COMPRESSION_PROFILE_0x0002_UDP_IP    1
#define OGS_NAS_HEADER_COMPRESSION_PROFILE_0x0003_ESP_IP    2
#define OGS_NAS_HEADER_COMPRESSION_PROFILE_0x0004           3
#define OGS_NAS_HEADER_COMPRESSION_PROFILE_0x0006           4
#define OGS_NAS_HEADER_COMPRESSION_PROFILE_0x0102_UDP_IP    5
#define OGS_NAS_HEADER_COMPRESSION_PROFILE_0x0103_ESP_IP    6
#define OGS_NAS_HEADER_COMPRESSION_PROFILE_0x0104_IP        7
    uint8_t type;
    uint8_t container[MAX_OGS_NAS_NBIFOM_CONTAINER_LEN];
} __attribute__ ((packed)) ogs_nas_header_compression_configuration_t;

/* 9.9.4.23 Control plane only indication
 * O TV 1 */
typedef struct ogs_nas_control_plane_only_indication_s {
ED3(uint8_t type:4;,
    uint8_t spare:3;,
    uint8_t ciot_eps_optimization:1;)
} __attribute__ ((packed)) ogs_nas_control_plane_only_indication_t;

/* 9.9.4.26 Extended protocol configuration options
 * See subclause 10.5.6.3A in 3GPP TS 24.008 [12]
 * O TLV-E 4-65538 */
typedef struct ogs_nas_extended_protocol_configuration_options_s {
    uint16_t length;
    uint8_t *buffer;
} __attribute__ ((packed)) ogs_nas_extended_protocol_configuration_options_t;

/* 9.9.4.28 Serving PLMN rate control
 * O TLV 4 */
typedef struct ogs_nas_serving_plmn_rate_control_s {
    uint8_t length;
ED8(uint8_t ebi7:1;,
    uint8_t ebi6:1;,
    uint8_t ebi5:1;,
    uint8_t ebi4:1;,
    uint8_t ebi3:1;,
    uint8_t ebi2:1;,
    uint8_t ebi1:1;,
    uint8_t ebi0:1;)
ED8(uint8_t ebi15:1;,
    uint8_t ebi14:1;,
    uint8_t ebi13:1;,
    uint8_t ebi12:1;,
    uint8_t ebi11:1;,
    uint8_t ebi10:1;,
    uint8_t ebi9:1;,
    uint8_t ebi8:1;)
} __attribute__ ((packed)) ogs_nas_serving_plmn_rate_control_t;

#ifdef __cplusplus
}
#endif

#endif /* OGS_NAS_COMMON_TYPES_H */
