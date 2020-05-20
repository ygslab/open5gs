/*
 * The MIT License
 *
 * Copyright (C) 2019,2020 by Sukchan Lee <acetcom@gmail.com>
 *
 * This file is part of Open5GS.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/*******************************************************************************
 * This file had been created by nas-message.py script v0.2.0
 * Please do not modify this file but regenerate it via script.
 * Created on: 2020-05-20 16:57:29.665115 by acetcom
 * from 24501-g41.docx
 ******************************************************************************/

#include "ogs-nas.h"

int ogs_nas_decode_registration_request(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_registration_accept(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_registration_complete(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_registration_reject(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_deregistration_request_from_ue(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_deregistration_request_to_ue(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_service_request(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_service_reject(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_service_accept(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_configuration_update_command(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_configuration_update_complete(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_authentication_request(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_authentication_response(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_authentication_reject(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_authentication_failure(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_authentication_result(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_identity_request(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_identity_response(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_security_mode_command(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_security_mode_complete(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_security_mode_reject(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_5gmm_status(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_notification(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_notification_response(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_ul_nas_transport(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_dl_nas_transport(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_pdu_session_establishment_request(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_pdu_session_establishment_accept(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_pdu_session_establishment_reject(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_pdu_session_authentication_command(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_pdu_session_authentication_complete(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_pdu_session_authentication_result(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_pdu_session_modification_request(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_pdu_session_modification_reject(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_pdu_session_modification_command(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_pdu_session_modification_complete(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_pdu_session_modification_command_reject(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_pdu_session_release_request(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_pdu_session_release_reject(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_pdu_session_release_command(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_pdu_session_release_complete(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_5gsm_status(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_registration_request(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_registration_request_t *registration_request = &message->emm.registration_request;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode REGISTRATION_REQUEST\n");

    size = ogs_nas_decode_5gs_registration_type(&registration_request->5gs_registration_type, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    size = ogs_nas_decode_5gs_mobile_identity(&registration_request->5gs_mobile_identity, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_REGISTRATION_REQUEST_NON_CURRENT_NATIVE_NAS_KEY_SET_IDENTIFIER_TYPE:
                 size = ogs_nas_decode_key_set_identifier(&registration_request->non_current_native_nas_key_set_identifier, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_NON_CURRENT_NATIVE_NAS_KEY_SET_IDENTIFIER_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_5GMM_CAPABILITY_TYPE:
                 size = ogs_nas_decode_5gmm_capability(&registration_request->5gmm_capability, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_5GMM_CAPABILITY_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_UE_SECURITY_CAPABILITY_TYPE:
                 size = ogs_nas_decode_ue_security_capability(&registration_request->ue_security_capability, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_UE_SECURITY_CAPABILITY_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_REQUESTED_NSSAI_TYPE:
                 size = ogs_nas_decode_nssai(&registration_request->requested_nssai, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_REQUESTED_NSSAI_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_LAST_VISITED_REGISTERED_TAI_TYPE:
                 size = ogs_nas_decode_5gs_tracking_area_identity(&registration_request->last_visited_registered_tai, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_LAST_VISITED_REGISTERED_TAI_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_S1_UE_NETWORK_CAPABILITY_TYPE:
                 size = ogs_nas_decode_s1_ue_network_capability(&registration_request->s1_ue_network_capability, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_S1_UE_NETWORK_CAPABILITY_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_UPLINK_DATA_STATUS_TYPE:
                 size = ogs_nas_decode_uplink_data_status(&registration_request->uplink_data_status, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_UPLINK_DATA_STATUS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_PDU_SESSION_STATUS_TYPE:
                 size = ogs_nas_decode_pdu_session_status(&registration_request->pdu_session_status, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_PDU_SESSION_STATUS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_MICO_INDICATION_TYPE:
                 size = ogs_nas_decode_mico_indication(&registration_request->mico_indication, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_MICO_INDICATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_UE_STATUS_TYPE:
                 size = ogs_nas_decode_ue_status(&registration_request->ue_status, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_UE_STATUS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_ADDITIONAL_GUTI_TYPE:
                 size = ogs_nas_decode_5gs_mobile_identity(&registration_request->additional_guti, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_ADDITIONAL_GUTI_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_ALLOWED_PDU_SESSION_STATUS_TYPE:
                 size = ogs_nas_decode_allowed_pdu_session_status(&registration_request->allowed_pdu_session_status, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_ALLOWED_PDU_SESSION_STATUS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_UE_USAGE_SETTING_TYPE:
                 size = ogs_nas_decode_ue_usage_setting(&registration_request->ue_usage_setting, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_UE_USAGE_SETTING_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_REQUESTED_DRX_PARAMETERS_TYPE:
                 size = ogs_nas_decode_5gs_drx_parameters(&registration_request->requested_drx_parameters, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_REQUESTED_DRX_PARAMETERS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_EPS_NAS_MESSAGE_CONTAINER_TYPE:
                 size = ogs_nas_decode_eps_nas_message_container(&registration_request->eps_nas_message_container, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_EPS_NAS_MESSAGE_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_LADN_INDICATION_TYPE:
                 size = ogs_nas_decode_ladn_indication(&registration_request->ladn_indication, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_LADN_INDICATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_PAYLOAD_CONTAINER_TYPE_TYPE:
                 size = ogs_nas_decode_payload_container_type(&registration_request->payload_container_type, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_PAYLOAD_CONTAINER_TYPE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_PAYLOAD_CONTAINER_TYPE:
                 size = ogs_nas_decode_payload_container(&registration_request->payload_container, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_PAYLOAD_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_NETWORK_SLICING_INDICATION_TYPE:
                 size = ogs_nas_decode_network_slicing_indication(&registration_request->network_slicing_indication, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_NETWORK_SLICING_INDICATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_5GS_UPDATE_TYPE_TYPE:
                 size = ogs_nas_decode_5gs_update_type(&registration_request->5gs_update_type, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_5GS_UPDATE_TYPE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_MOBILE_STATION_CLASSMARK_2_TYPE:
                 size = ogs_nas_decode_mobile_station_classmark_2(&registration_request->mobile_station_classmark_2, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_MOBILE_STATION_CLASSMARK_2_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_SUPPORTED_CODECS_TYPE:
                 size = ogs_nas_decode_supported_codec_list(&registration_request->supported_codecs, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_SUPPORTED_CODECS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_NAS_MESSAGE_CONTAINER_TYPE:
                 size = ogs_nas_decode_message_container(&registration_request->nas_message_container, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_NAS_MESSAGE_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_EPS_BEARER_CONTEXT_STATUS_TYPE:
                 size = ogs_nas_decode_eps_bearer_context_status(&registration_request->eps_bearer_context_status, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_EPS_BEARER_CONTEXT_STATUS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_REQUESTED_EXTENDED_DRX_PARAMETERS_TYPE:
                 size = ogs_nas_decode_extended_drx_parameters(&registration_request->requested_extended_drx_parameters, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_REQUESTED_EXTENDED_DRX_PARAMETERS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_T3324_VALUE_TYPE:
                 size = ogs_nas_decode_gprs_timer_3(&registration_request->t3324_value, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_T3324_VALUE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_UE_RADIO_CAPABILITY_ID_TYPE:
                 size = ogs_nas_decode_ue_radio_capability_id(&registration_request->ue_radio_capability_id, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_UE_RADIO_CAPABILITY_ID_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_REQUESTED_MAPPED_NSSAI_TYPE:
                 size = ogs_nas_decode_mapped_nssai(&registration_request->requested_mapped_nssai, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_REQUESTED_MAPPED_NSSAI_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_ADDITIONAL_INFORMATION_REQUESTED_TYPE:
                 size = ogs_nas_decode_additional_information_requested(&registration_request->additional_information_requested, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_ADDITIONAL_INFORMATION_REQUESTED_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_REQUESTED_WUS_ASSISTANCE_INFORMATION_TYPE:
                 size = ogs_nas_decode_wus_assistance_information(&registration_request->requested_wus_assistance_information, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_REQUESTED_WUS_ASSISTANCE_INFORMATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REQUEST_N5GC_INDICATION_TYPE:
                 size = ogs_nas_decode_n5gc_indication(&registration_request->n5gc_indication, pkbuf);
                 ogs_assert(size >= 0);
                 registration_request->presencemask |= OGS_NAS_REGISTRATION_REQUEST_N5GC_INDICATION_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_registration_accept(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_registration_accept_t *registration_accept = &message->emm.registration_accept;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode REGISTRATION_ACCEPT\n");

    size = ogs_nas_decode_5gs_registration_result(&registration_accept->5gs_registration_result, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_REGISTRATION_ACCEPT_5G_GUTI_TYPE:
                 size = ogs_nas_decode_5gs_mobile_identity(&registration_accept->5g_guti, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_5G_GUTI_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_EQUIVALENT_PLMNS_TYPE:
                 size = ogs_nas_decode_plmn_list(&registration_accept->equivalent_plmns, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_EQUIVALENT_PLMNS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_TAI_LIST_TYPE:
                 size = ogs_nas_decode_5gs_tracking_area_identity_list(&registration_accept->tai_list, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_TAI_LIST_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_ALLOWED_NSSAI_TYPE:
                 size = ogs_nas_decode_nssai(&registration_accept->allowed_nssai, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_ALLOWED_NSSAI_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_REJECTED_NSSAI_TYPE:
                 size = ogs_nas_decode_rejected_nssai(&registration_accept->rejected_nssai, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_REJECTED_NSSAI_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_CONFIGURED_NSSAI_TYPE:
                 size = ogs_nas_decode_nssai(&registration_accept->configured_nssai, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_CONFIGURED_NSSAI_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_5GS_NETWORK_FEATURE_SUPPORT_TYPE:
                 size = ogs_nas_decode_5gs_network_feature_support(&registration_accept->5gs_network_feature_support, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_5GS_NETWORK_FEATURE_SUPPORT_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_PDU_SESSION_STATUS_TYPE:
                 size = ogs_nas_decode_pdu_session_status(&registration_accept->pdu_session_status, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_PDU_SESSION_STATUS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_PDU_SESSION_REACTIVATION_RESULT_TYPE:
                 size = ogs_nas_decode_pdu_session_reactivation_result(&registration_accept->pdu_session_reactivation_result, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_PDU_SESSION_REACTIVATION_RESULT_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_PDU_SESSION_REACTIVATION_RESULT_ERROR_CAUSE_TYPE:
                 size = ogs_nas_decode_pdu_session_reactivation_result_error_cause(&registration_accept->pdu_session_reactivation_result_error_cause, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_PDU_SESSION_REACTIVATION_RESULT_ERROR_CAUSE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_LADN_INFORMATION_TYPE:
                 size = ogs_nas_decode_ladn_information(&registration_accept->ladn_information, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_LADN_INFORMATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_MICO_INDICATION_TYPE:
                 size = ogs_nas_decode_mico_indication(&registration_accept->mico_indication, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_MICO_INDICATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_NETWORK_SLICING_INDICATION_TYPE:
                 size = ogs_nas_decode_network_slicing_indication(&registration_accept->network_slicing_indication, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_NETWORK_SLICING_INDICATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_SERVICE_AREA_LIST_TYPE:
                 size = ogs_nas_decode_service_area_list(&registration_accept->service_area_list, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_SERVICE_AREA_LIST_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_T3512_VALUE_TYPE:
                 size = ogs_nas_decode_gprs_timer_3(&registration_accept->t3512_value, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_T3512_VALUE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_NON_3GPP_DE_REGISTRATION_TIMER_VALUE_TYPE:
                 size = ogs_nas_decode_gprs_timer_2(&registration_accept->non_3gpp_de_registration_timer_value, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_NON_3GPP_DE_REGISTRATION_TIMER_VALUE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_T3502_VALUE_TYPE:
                 size = ogs_nas_decode_gprs_timer_2(&registration_accept->t3502_value, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_T3502_VALUE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_EMERGENCY_NUMBER_LIST_TYPE:
                 size = ogs_nas_decode_emergency_number_list(&registration_accept->emergency_number_list, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_EMERGENCY_NUMBER_LIST_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_EXTENDED_EMERGENCY_NUMBER_LIST_TYPE:
                 size = ogs_nas_decode_extended_emergency_number_list(&registration_accept->extended_emergency_number_list, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_EXTENDED_EMERGENCY_NUMBER_LIST_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_SOR_TRANSPARENT_CONTAINER_TYPE:
                 size = ogs_nas_decode_sor_transparent_container(&registration_accept->sor_transparent_container, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_SOR_TRANSPARENT_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_EAP_MESSAGE_TYPE:
                 size = ogs_nas_decode_eap_message(&registration_accept->eap_message, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_EAP_MESSAGE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_NSSAI_INCLUSION_MODE_TYPE:
                 size = ogs_nas_decode_nssai_inclusion_mode(&registration_accept->nssai_inclusion_mode, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_NSSAI_INCLUSION_MODE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_OPERATOR_DEFINED_ACCESS_CATEGORY_DEFINITIONS_TYPE:
                 size = ogs_nas_decode_operator_defined_access_category_definitions(&registration_accept->operator_defined_access_category_definitions, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_OPERATOR_DEFINED_ACCESS_CATEGORY_DEFINITIONS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_NEGOTIATED_DRX_PARAMETERS_TYPE:
                 size = ogs_nas_decode_5gs_drx_parameters(&registration_accept->negotiated_drx_parameters, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_NEGOTIATED_DRX_PARAMETERS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_NON_3GPP_NW_POLICIES_TYPE:
                 size = ogs_nas_decode_non_3gpp_nw_provided_policies(&registration_accept->non_3gpp_nw_policies, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_NON_3GPP_NW_POLICIES_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_EPS_BEARER_CONTEXT_STATUS_TYPE:
                 size = ogs_nas_decode_eps_bearer_context_status(&registration_accept->eps_bearer_context_status, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_EPS_BEARER_CONTEXT_STATUS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_NEGOTIATED_EXTENDED_DRX_PARAMETERS_TYPE:
                 size = ogs_nas_decode_extended_drx_parameters(&registration_accept->negotiated_extended_drx_parameters, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_NEGOTIATED_EXTENDED_DRX_PARAMETERS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_T3447_VALUE_TYPE:
                 size = ogs_nas_decode_gprs_timer_3(&registration_accept->t3447_value, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_T3447_VALUE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_T3448_VALUE_TYPE:
                 size = ogs_nas_decode_gprs_timer_3(&registration_accept->t3448_value, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_T3448_VALUE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_T3324_VALUE_TYPE:
                 size = ogs_nas_decode_gprs_timer_3(&registration_accept->t3324_value, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_T3324_VALUE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_UE_RADIO_CAPABILITY_ID_TYPE:
                 size = ogs_nas_decode_ue_radio_capability_id(&registration_accept->ue_radio_capability_id, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_UE_RADIO_CAPABILITY_ID_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_UE_RADIO_CAPABILITY_ID_DELETION_INDICATION_TYPE:
                 size = ogs_nas_decode_ue_radio_capability_id_deletion_indication(&registration_accept->ue_radio_capability_id_deletion_indication, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_UE_RADIO_CAPABILITY_ID_DELETION_INDICATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_PENDING_NSSAI_TYPE:
                 size = ogs_nas_decode_nssai(&registration_accept->pending_nssai, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_PENDING_NSSAI_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_CIPHERING_KEY_DATA_TYPE:
                 size = ogs_nas_decode_ciphering_key_data(&registration_accept->ciphering_key_data, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_CIPHERING_KEY_DATA_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_CAG_INFORMATION_LIST_TYPE:
                 size = ogs_nas_decode_cag_information_list(&registration_accept->cag_information_list, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_CAG_INFORMATION_LIST_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_TRUNCATED_5G_S_TMSI_CONFIGURATION_TYPE:
                 size = ogs_nas_decode_truncated_5g_s_tmsi_configuration(&registration_accept->truncated_5g_s_tmsi_configuration, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_TRUNCATED_5G_S_TMSI_CONFIGURATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_ACCEPT_NEGOTIATED_WUS_ASSISTANCE_INFORMATION_TYPE:
                 size = ogs_nas_decode_wus_assistance_information(&registration_accept->negotiated_wus_assistance_information, pkbuf);
                 ogs_assert(size >= 0);
                 registration_accept->presencemask |= OGS_NAS_REGISTRATION_ACCEPT_NEGOTIATED_WUS_ASSISTANCE_INFORMATION_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_registration_complete(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_registration_complete_t *registration_complete = &message->emm.registration_complete;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode REGISTRATION_COMPLETE\n");

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_REGISTRATION_COMPLETE_SOR_TRANSPARENT_CONTAINER_TYPE:
                 size = ogs_nas_decode_sor_transparent_container(&registration_complete->sor_transparent_container, pkbuf);
                 ogs_assert(size >= 0);
                 registration_complete->presencemask |= OGS_NAS_REGISTRATION_COMPLETE_SOR_TRANSPARENT_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_registration_reject(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_registration_reject_t *registration_reject = &message->emm.registration_reject;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode REGISTRATION_REJECT\n");

    size = ogs_nas_decode_5gmm_cause(&registration_reject->5gmm_cause, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_REGISTRATION_REJECT_T3346_VALUE_TYPE:
                 size = ogs_nas_decode_gprs_timer_2(&registration_reject->t3346_value, pkbuf);
                 ogs_assert(size >= 0);
                 registration_reject->presencemask |= OGS_NAS_REGISTRATION_REJECT_T3346_VALUE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REJECT_T3502_VALUE_TYPE:
                 size = ogs_nas_decode_gprs_timer_2(&registration_reject->t3502_value, pkbuf);
                 ogs_assert(size >= 0);
                 registration_reject->presencemask |= OGS_NAS_REGISTRATION_REJECT_T3502_VALUE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REJECT_EAP_MESSAGE_TYPE:
                 size = ogs_nas_decode_eap_message(&registration_reject->eap_message, pkbuf);
                 ogs_assert(size >= 0);
                 registration_reject->presencemask |= OGS_NAS_REGISTRATION_REJECT_EAP_MESSAGE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_REGISTRATION_REJECT_REJECTED_NSSAI_TYPE:
                 size = ogs_nas_decode_rejected_nssai(&registration_reject->rejected_nssai, pkbuf);
                 ogs_assert(size >= 0);
                 registration_reject->presencemask |= OGS_NAS_REGISTRATION_REJECT_REJECTED_NSSAI_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_deregistration_request_from_ue(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_deregistration_request_from_ue_t *deregistration_request_from_ue = &message->emm.deregistration_request_from_ue;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode DEREGISTRATION_REQUEST\n");

    size = ogs_nas_decode_de_registration_type(&deregistration_request_from_ue->de_registration_type, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    size = ogs_nas_decode_5gs_mobile_identity(&deregistration_request_from_ue->5gs_mobile_identity, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    return decoded;
}

int ogs_nas_decode_deregistration_request_to_ue(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_deregistration_request_to_ue_t *deregistration_request_to_ue = &message->emm.deregistration_request_to_ue;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode DEREGISTRATION_REQUEST\n");

    size = ogs_nas_decode_de_registration_type(&deregistration_request_to_ue->de_registration_type, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_DEREGISTRATION_REQUEST_5GMM_CAUSE_TYPE:
                 size = ogs_nas_decode_5gmm_cause(&deregistration_request_to_ue->5gmm_cause, pkbuf);
                 ogs_assert(size >= 0);
                 deregistration_request_to_ue->presencemask |= OGS_NAS_DEREGISTRATION_REQUEST_5GMM_CAUSE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_DEREGISTRATION_REQUEST_T3346_VALUE_TYPE:
                 size = ogs_nas_decode_gprs_timer_2(&deregistration_request_to_ue->t3346_value, pkbuf);
                 ogs_assert(size >= 0);
                 deregistration_request_to_ue->presencemask |= OGS_NAS_DEREGISTRATION_REQUEST_T3346_VALUE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_DEREGISTRATION_REQUEST_REJECTED_NSSAI_TYPE:
                 size = ogs_nas_decode_rejected_nssai(&deregistration_request_to_ue->rejected_nssai, pkbuf);
                 ogs_assert(size >= 0);
                 deregistration_request_to_ue->presencemask |= OGS_NAS_DEREGISTRATION_REQUEST_REJECTED_NSSAI_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_service_request(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_service_request_t *service_request = &message->emm.service_request;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode SERVICE_REQUEST\n");

    size = ogs_nas_decode_key_set_identifier(&service_request->ngksi, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    size = ogs_nas_decode_5gs_mobile_identity(&service_request->5g_s_tmsi, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_SERVICE_REQUEST_UPLINK_DATA_STATUS_TYPE:
                 size = ogs_nas_decode_uplink_data_status(&service_request->uplink_data_status, pkbuf);
                 ogs_assert(size >= 0);
                 service_request->presencemask |= OGS_NAS_SERVICE_REQUEST_UPLINK_DATA_STATUS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_SERVICE_REQUEST_PDU_SESSION_STATUS_TYPE:
                 size = ogs_nas_decode_pdu_session_status(&service_request->pdu_session_status, pkbuf);
                 ogs_assert(size >= 0);
                 service_request->presencemask |= OGS_NAS_SERVICE_REQUEST_PDU_SESSION_STATUS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_SERVICE_REQUEST_ALLOWED_PDU_SESSION_STATUS_TYPE:
                 size = ogs_nas_decode_allowed_pdu_session_status(&service_request->allowed_pdu_session_status, pkbuf);
                 ogs_assert(size >= 0);
                 service_request->presencemask |= OGS_NAS_SERVICE_REQUEST_ALLOWED_PDU_SESSION_STATUS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_SERVICE_REQUEST_NAS_MESSAGE_CONTAINER_TYPE:
                 size = ogs_nas_decode_message_container(&service_request->nas_message_container, pkbuf);
                 ogs_assert(size >= 0);
                 service_request->presencemask |= OGS_NAS_SERVICE_REQUEST_NAS_MESSAGE_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_service_reject(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_service_reject_t *service_reject = &message->emm.service_reject;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode SERVICE_REJECT\n");

    size = ogs_nas_decode_5gmm_cause(&service_reject->5gmm_cause, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_SERVICE_REJECT_PDU_SESSION_STATUS_TYPE:
                 size = ogs_nas_decode_pdu_session_status(&service_reject->pdu_session_status, pkbuf);
                 ogs_assert(size >= 0);
                 service_reject->presencemask |= OGS_NAS_SERVICE_REJECT_PDU_SESSION_STATUS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_SERVICE_REJECT_T3346_VALUE_TYPE:
                 size = ogs_nas_decode_gprs_timer_2(&service_reject->t3346_value, pkbuf);
                 ogs_assert(size >= 0);
                 service_reject->presencemask |= OGS_NAS_SERVICE_REJECT_T3346_VALUE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_SERVICE_REJECT_EAP_MESSAGE_TYPE:
                 size = ogs_nas_decode_eap_message(&service_reject->eap_message, pkbuf);
                 ogs_assert(size >= 0);
                 service_reject->presencemask |= OGS_NAS_SERVICE_REJECT_EAP_MESSAGE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_SERVICE_REJECT_T3448_VALUE_TYPE:
                 size = ogs_nas_decode_gprs_timer_3(&service_reject->t3448_value, pkbuf);
                 ogs_assert(size >= 0);
                 service_reject->presencemask |= OGS_NAS_SERVICE_REJECT_T3448_VALUE_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_service_accept(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_service_accept_t *service_accept = &message->emm.service_accept;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode SERVICE_ACCEPT\n");

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_SERVICE_ACCEPT_PDU_SESSION_STATUS_TYPE:
                 size = ogs_nas_decode_pdu_session_status(&service_accept->pdu_session_status, pkbuf);
                 ogs_assert(size >= 0);
                 service_accept->presencemask |= OGS_NAS_SERVICE_ACCEPT_PDU_SESSION_STATUS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_SERVICE_ACCEPT_PDU_SESSION_REACTIVATION_RESULT_TYPE:
                 size = ogs_nas_decode_pdu_session_reactivation_result(&service_accept->pdu_session_reactivation_result, pkbuf);
                 ogs_assert(size >= 0);
                 service_accept->presencemask |= OGS_NAS_SERVICE_ACCEPT_PDU_SESSION_REACTIVATION_RESULT_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_SERVICE_ACCEPT_PDU_SESSION_REACTIVATION_RESULT_ERROR_CAUSE_TYPE:
                 size = ogs_nas_decode_pdu_session_reactivation_result_error_cause(&service_accept->pdu_session_reactivation_result_error_cause, pkbuf);
                 ogs_assert(size >= 0);
                 service_accept->presencemask |= OGS_NAS_SERVICE_ACCEPT_PDU_SESSION_REACTIVATION_RESULT_ERROR_CAUSE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_SERVICE_ACCEPT_EAP_MESSAGE_TYPE:
                 size = ogs_nas_decode_eap_message(&service_accept->eap_message, pkbuf);
                 ogs_assert(size >= 0);
                 service_accept->presencemask |= OGS_NAS_SERVICE_ACCEPT_EAP_MESSAGE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_SERVICE_ACCEPT_T3448_VALUE_TYPE:
                 size = ogs_nas_decode_gprs_timer_3(&service_accept->t3448_value, pkbuf);
                 ogs_assert(size >= 0);
                 service_accept->presencemask |= OGS_NAS_SERVICE_ACCEPT_T3448_VALUE_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_configuration_update_command(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_configuration_update_command_t *configuration_update_command = &message->emm.configuration_update_command;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode CONFIGURATION_UPDATE_COMMAND\n");

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_CONFIGURATION_UPDATE_INDICATION_TYPE:
                 size = ogs_nas_decode_configuration_update_indication(&configuration_update_command->configuration_update_indication, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_CONFIGURATION_UPDATE_INDICATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_5G_GUTI_TYPE:
                 size = ogs_nas_decode_5gs_mobile_identity(&configuration_update_command->5g_guti, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_5G_GUTI_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_TAI_LIST_TYPE:
                 size = ogs_nas_decode_5gs_tracking_area_identity_list(&configuration_update_command->tai_list, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_TAI_LIST_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_ALLOWED_NSSAI_TYPE:
                 size = ogs_nas_decode_nssai(&configuration_update_command->allowed_nssai, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_ALLOWED_NSSAI_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_SERVICE_AREA_LIST_TYPE:
                 size = ogs_nas_decode_service_area_list(&configuration_update_command->service_area_list, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_SERVICE_AREA_LIST_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_FULL_NAME_FOR_NETWORK_TYPE:
                 size = ogs_nas_decode_network_name(&configuration_update_command->full_name_for_network, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_FULL_NAME_FOR_NETWORK_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_SHORT_NAME_FOR_NETWORK_TYPE:
                 size = ogs_nas_decode_network_name(&configuration_update_command->short_name_for_network, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_SHORT_NAME_FOR_NETWORK_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_LOCAL_TIME_ZONE_TYPE:
                 size = ogs_nas_decode_time_zone(&configuration_update_command->local_time_zone, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_LOCAL_TIME_ZONE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_UNIVERSAL_TIME_AND_LOCAL_TIME_ZONE_TYPE:
                 size = ogs_nas_decode_time_zone_and_time(&configuration_update_command->universal_time_and_local_time_zone, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_UNIVERSAL_TIME_AND_LOCAL_TIME_ZONE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_NETWORK_DAYLIGHT_SAVING_TIME_TYPE:
                 size = ogs_nas_decode_daylight_saving_time(&configuration_update_command->network_daylight_saving_time, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_NETWORK_DAYLIGHT_SAVING_TIME_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_LADN_INFORMATION_TYPE:
                 size = ogs_nas_decode_ladn_information(&configuration_update_command->ladn_information, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_LADN_INFORMATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_MICO_INDICATION_TYPE:
                 size = ogs_nas_decode_mico_indication(&configuration_update_command->mico_indication, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_MICO_INDICATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_NETWORK_SLICING_INDICATION_TYPE:
                 size = ogs_nas_decode_network_slicing_indication(&configuration_update_command->network_slicing_indication, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_NETWORK_SLICING_INDICATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_CONFIGURED_NSSAI_TYPE:
                 size = ogs_nas_decode_nssai(&configuration_update_command->configured_nssai, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_CONFIGURED_NSSAI_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_REJECTED_NSSAI_TYPE:
                 size = ogs_nas_decode_rejected_nssai(&configuration_update_command->rejected_nssai, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_REJECTED_NSSAI_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_OPERATOR_DEFINED_ACCESS_CATEGORY_DEFINITIONS_TYPE:
                 size = ogs_nas_decode_operator_defined_access_category_definitions(&configuration_update_command->operator_defined_access_category_definitions, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_OPERATOR_DEFINED_ACCESS_CATEGORY_DEFINITIONS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_SMS_INDICATION_TYPE:
                 size = ogs_nas_decode_sms_indication(&configuration_update_command->sms_indication, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_SMS_INDICATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_T3447_VALUE_TYPE:
                 size = ogs_nas_decode_gprs_timer_3(&configuration_update_command->t3447_value, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_T3447_VALUE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_CAG_INFORMATION_LIST_TYPE:
                 size = ogs_nas_decode_cag_information_list(&configuration_update_command->cag_information_list, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_CAG_INFORMATION_LIST_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_UE_RADIO_CAPABILITY_ID_TYPE:
                 size = ogs_nas_decode_ue_radio_capability_id(&configuration_update_command->ue_radio_capability_id, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_UE_RADIO_CAPABILITY_ID_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_UE_RADIO_CAPABILITY_ID_DELETION_INDICATION_TYPE:
                 size = ogs_nas_decode_ue_radio_capability_id_deletion_indication(&configuration_update_command->ue_radio_capability_id_deletion_indication, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_UE_RADIO_CAPABILITY_ID_DELETION_INDICATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_5GS_REGISTRATION_RESULT_TYPE:
                 size = ogs_nas_decode_5gs_registration_result(&configuration_update_command->5gs_registration_result, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_5GS_REGISTRATION_RESULT_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMMAND_TRUNCATED_5G_S_TMSI_CONFIGURATION_TYPE:
                 size = ogs_nas_decode_truncated_5g_s_tmsi_configuration(&configuration_update_command->truncated_5g_s_tmsi_configuration, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_command->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMMAND_TRUNCATED_5G_S_TMSI_CONFIGURATION_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_configuration_update_complete(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_configuration_update_complete_t *configuration_update_complete = &message->emm.configuration_update_complete;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode CONFIGURATION_UPDATE_COMPLETE\n");

    size = ogs_nas_decode_control_plane_service_type(&configuration_update_complete->control_plane_service_type, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_CONFIGURATION_UPDATE_COMPLETE_CIOT_SMALL_DATA_CONTAINER_TYPE:
                 size = ogs_nas_decode_ciot_small_data_container(&configuration_update_complete->ciot_small_data_container, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_complete->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMPLETE_CIOT_SMALL_DATA_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMPLETE_PAYLOAD_CONTAINER_TYPE_TYPE:
                 size = ogs_nas_decode_payload_container_type(&configuration_update_complete->payload_container_type, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_complete->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMPLETE_PAYLOAD_CONTAINER_TYPE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMPLETE_PAYLOAD_CONTAINER_TYPE:
                 size = ogs_nas_decode_payload_container(&configuration_update_complete->payload_container, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_complete->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMPLETE_PAYLOAD_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMPLETE_PDU_SESSION_STATUS_TYPE:
                 size = ogs_nas_decode_pdu_session_status(&configuration_update_complete->pdu_session_status, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_complete->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMPLETE_PDU_SESSION_STATUS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMPLETE_RELEASE_ASSISTANCE_INDICATION_TYPE:
                 size = ogs_nas_decode_release_assistance_indication(&configuration_update_complete->release_assistance_indication, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_complete->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMPLETE_RELEASE_ASSISTANCE_INDICATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMPLETE_UPLINK_DATA_STATUS_TYPE:
                 size = ogs_nas_decode_uplink_data_status(&configuration_update_complete->uplink_data_status, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_complete->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMPLETE_UPLINK_DATA_STATUS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMPLETE_NAS_MESSAGE_CONTAINER_TYPE:
                 size = ogs_nas_decode_message_container(&configuration_update_complete->nas_message_container, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_complete->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMPLETE_NAS_MESSAGE_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_CONFIGURATION_UPDATE_COMPLETE_ADDITIONAL_INFORMATION_TYPE:
                 size = ogs_nas_decode_additional_information(&configuration_update_complete->additional_information, pkbuf);
                 ogs_assert(size >= 0);
                 configuration_update_complete->presencemask |= OGS_NAS_CONFIGURATION_UPDATE_COMPLETE_ADDITIONAL_INFORMATION_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_authentication_request(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_authentication_request_t *authentication_request = &message->emm.authentication_request;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode AUTHENTICATION_REQUEST\n");

    size = ogs_nas_decode_key_set_identifier(&authentication_request->ngksi, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    size = ogs_nas_decode_abba(&authentication_request->abba, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_AUTHENTICATION_REQUEST_AUTHENTICATION_PARAMETER_RAND_TYPE:
                 size = ogs_nas_decode_authentication_parameter_rand(&authentication_request->authentication_parameter_rand, pkbuf);
                 ogs_assert(size >= 0);
                 authentication_request->presencemask |= OGS_NAS_AUTHENTICATION_REQUEST_AUTHENTICATION_PARAMETER_RAND_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_AUTHENTICATION_REQUEST_AUTHENTICATION_PARAMETER_AUTN_TYPE:
                 size = ogs_nas_decode_authentication_parameter_autn(&authentication_request->authentication_parameter_autn, pkbuf);
                 ogs_assert(size >= 0);
                 authentication_request->presencemask |= OGS_NAS_AUTHENTICATION_REQUEST_AUTHENTICATION_PARAMETER_AUTN_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_AUTHENTICATION_REQUEST_EAP_MESSAGE_TYPE:
                 size = ogs_nas_decode_eap_message(&authentication_request->eap_message, pkbuf);
                 ogs_assert(size >= 0);
                 authentication_request->presencemask |= OGS_NAS_AUTHENTICATION_REQUEST_EAP_MESSAGE_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_authentication_response(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_authentication_response_t *authentication_response = &message->emm.authentication_response;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode AUTHENTICATION_RESPONSE\n");

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_AUTHENTICATION_RESPONSE_AUTHENTICATION_RESPONSE_PARAMETER_TYPE:
                 size = ogs_nas_decode_authentication_response_parameter(&authentication_response->authentication_response_parameter, pkbuf);
                 ogs_assert(size >= 0);
                 authentication_response->presencemask |= OGS_NAS_AUTHENTICATION_RESPONSE_AUTHENTICATION_RESPONSE_PARAMETER_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_AUTHENTICATION_RESPONSE_EAP_MESSAGE_TYPE:
                 size = ogs_nas_decode_eap_message(&authentication_response->eap_message, pkbuf);
                 ogs_assert(size >= 0);
                 authentication_response->presencemask |= OGS_NAS_AUTHENTICATION_RESPONSE_EAP_MESSAGE_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_authentication_reject(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_authentication_reject_t *authentication_reject = &message->emm.authentication_reject;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode AUTHENTICATION_REJECT\n");

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_AUTHENTICATION_REJECT_EAP_MESSAGE_TYPE:
                 size = ogs_nas_decode_eap_message(&authentication_reject->eap_message, pkbuf);
                 ogs_assert(size >= 0);
                 authentication_reject->presencemask |= OGS_NAS_AUTHENTICATION_REJECT_EAP_MESSAGE_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_authentication_failure(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_authentication_failure_t *authentication_failure = &message->emm.authentication_failure;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode AUTHENTICATION_FAILURE\n");

    size = ogs_nas_decode_5gmm_cause(&authentication_failure->5gmm_cause, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_AUTHENTICATION_FAILURE_AUTHENTICATION_FAILURE_PARAMETER_TYPE:
                 size = ogs_nas_decode_authentication_failure_parameter(&authentication_failure->authentication_failure_parameter, pkbuf);
                 ogs_assert(size >= 0);
                 authentication_failure->presencemask |= OGS_NAS_AUTHENTICATION_FAILURE_AUTHENTICATION_FAILURE_PARAMETER_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_authentication_result(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_authentication_result_t *authentication_result = &message->emm.authentication_result;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode AUTHENTICATION_RESULT\n");

    size = ogs_nas_decode_key_set_identifier(&authentication_result->ngksi, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    size = ogs_nas_decode_eap_message(&authentication_result->eap_message, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_AUTHENTICATION_RESULT_ABBA_TYPE:
                 size = ogs_nas_decode_abba(&authentication_result->abba, pkbuf);
                 ogs_assert(size >= 0);
                 authentication_result->presencemask |= OGS_NAS_AUTHENTICATION_RESULT_ABBA_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_identity_request(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_identity_request_t *identity_request = &message->emm.identity_request;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode IDENTITY_REQUEST\n");

    size = ogs_nas_decode_5gs_identity_type(&identity_request->identity_type, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    return decoded;
}

int ogs_nas_decode_identity_response(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_identity_response_t *identity_response = &message->emm.identity_response;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode IDENTITY_RESPONSE\n");

    size = ogs_nas_decode_5gs_mobile_identity(&identity_response->mobile_identity, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    return decoded;
}

int ogs_nas_decode_security_mode_command(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_security_mode_command_t *security_mode_command = &message->emm.security_mode_command;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode SECURITY_MODE_COMMAND\n");

    size = ogs_nas_decode_security_algorithms(&security_mode_command->selected_nas_security_algorithms, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    size = ogs_nas_decode_key_set_identifier(&security_mode_command->ngksi, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    size = ogs_nas_decode_ue_security_capability(&security_mode_command->replayed_ue_security_capabilities, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_SECURITY_MODE_COMMAND_IMEISV_REQUEST_TYPE:
                 size = ogs_nas_decode_imeisv_request(&security_mode_command->imeisv_request, pkbuf);
                 ogs_assert(size >= 0);
                 security_mode_command->presencemask |= OGS_NAS_SECURITY_MODE_COMMAND_IMEISV_REQUEST_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_SECURITY_MODE_COMMAND_SELECTED_EPS_NAS_SECURITY_ALGORITHMS_TYPE:
                 size = ogs_nas_decode_eps_nas_security_algorithms(&security_mode_command->selected_eps_nas_security_algorithms, pkbuf);
                 ogs_assert(size >= 0);
                 security_mode_command->presencemask |= OGS_NAS_SECURITY_MODE_COMMAND_SELECTED_EPS_NAS_SECURITY_ALGORITHMS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_SECURITY_MODE_COMMAND_ADDITIONAL_5G_SECURITY_INFORMATION_TYPE:
                 size = ogs_nas_decode_additional_5g_security_information(&security_mode_command->additional_5g_security_information, pkbuf);
                 ogs_assert(size >= 0);
                 security_mode_command->presencemask |= OGS_NAS_SECURITY_MODE_COMMAND_ADDITIONAL_5G_SECURITY_INFORMATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_SECURITY_MODE_COMMAND_EAP_MESSAGE_TYPE:
                 size = ogs_nas_decode_eap_message(&security_mode_command->eap_message, pkbuf);
                 ogs_assert(size >= 0);
                 security_mode_command->presencemask |= OGS_NAS_SECURITY_MODE_COMMAND_EAP_MESSAGE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_SECURITY_MODE_COMMAND_ABBA_TYPE:
                 size = ogs_nas_decode_abba(&security_mode_command->abba, pkbuf);
                 ogs_assert(size >= 0);
                 security_mode_command->presencemask |= OGS_NAS_SECURITY_MODE_COMMAND_ABBA_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_SECURITY_MODE_COMMAND_REPLAYED_S1_UE_SECURITY_CAPABILITIES_TYPE:
                 size = ogs_nas_decode_s1_ue_security_capability(&security_mode_command->replayed_s1_ue_security_capabilities, pkbuf);
                 ogs_assert(size >= 0);
                 security_mode_command->presencemask |= OGS_NAS_SECURITY_MODE_COMMAND_REPLAYED_S1_UE_SECURITY_CAPABILITIES_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_security_mode_complete(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_security_mode_complete_t *security_mode_complete = &message->emm.security_mode_complete;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode SECURITY_MODE_COMPLETE\n");

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_SECURITY_MODE_COMPLETE_IMEISV_TYPE:
                 size = ogs_nas_decode_5gs_mobile_identity(&security_mode_complete->imeisv, pkbuf);
                 ogs_assert(size >= 0);
                 security_mode_complete->presencemask |= OGS_NAS_SECURITY_MODE_COMPLETE_IMEISV_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_SECURITY_MODE_COMPLETE_NAS_MESSAGE_CONTAINER_TYPE:
                 size = ogs_nas_decode_message_container(&security_mode_complete->nas_message_container, pkbuf);
                 ogs_assert(size >= 0);
                 security_mode_complete->presencemask |= OGS_NAS_SECURITY_MODE_COMPLETE_NAS_MESSAGE_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_SECURITY_MODE_COMPLETE_NON_IMEISV_PEI_TYPE:
                 size = ogs_nas_decode_5gs_mobile_identity(&security_mode_complete->non_imeisv_pei, pkbuf);
                 ogs_assert(size >= 0);
                 security_mode_complete->presencemask |= OGS_NAS_SECURITY_MODE_COMPLETE_NON_IMEISV_PEI_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_security_mode_reject(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_security_mode_reject_t *security_mode_reject = &message->emm.security_mode_reject;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode SECURITY_MODE_REJECT\n");

    size = ogs_nas_decode_5gmm_cause(&security_mode_reject->5gmm_cause, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    return decoded;
}

int ogs_nas_decode_5gmm_status(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_5gmm_status_t *5gmm_status = &message->emm.5gmm_status;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode 5GMM_STATUS\n");

    size = ogs_nas_decode_5gmm_cause(&5gmm_status->5gmm_cause, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    return decoded;
}

int ogs_nas_decode_notification(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_notification_t *notification = &message->emm.notification;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode NOTIFICATION\n");

    size = ogs_nas_decode_access_type(&notification->access_type, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    return decoded;
}

int ogs_nas_decode_notification_response(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_notification_response_t *notification_response = &message->emm.notification_response;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode NOTIFICATION_RESPONSE\n");

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_NOTIFICATION_RESPONSE_PDU_SESSION_STATUS_TYPE:
                 size = ogs_nas_decode_pdu_session_status(&notification_response->pdu_session_status, pkbuf);
                 ogs_assert(size >= 0);
                 notification_response->presencemask |= OGS_NAS_NOTIFICATION_RESPONSE_PDU_SESSION_STATUS_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_ul_nas_transport(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_ul_nas_transport_t *ul_nas_transport = &message->emm.ul_nas_transport;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode UL_NAS_TRANSPORT\n");

    size = ogs_nas_decode_payload_container_type(&ul_nas_transport->payload_container_type, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    size = ogs_nas_decode_payload_container(&ul_nas_transport->payload_container, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_UL_NAS_TRANSPORT_OLD_PDU_SESSION_ID_TYPE:
                 size = ogs_nas_decode_pdu_session_identity_2(&ul_nas_transport->old_pdu_session_id, pkbuf);
                 ogs_assert(size >= 0);
                 ul_nas_transport->presencemask |= OGS_NAS_UL_NAS_TRANSPORT_OLD_PDU_SESSION_ID_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_UL_NAS_TRANSPORT_REQUEST_TYPE_TYPE:
                 size = ogs_nas_decode_request_type(&ul_nas_transport->request_type, pkbuf);
                 ogs_assert(size >= 0);
                 ul_nas_transport->presencemask |= OGS_NAS_UL_NAS_TRANSPORT_REQUEST_TYPE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_UL_NAS_TRANSPORT_S_NSSAI_TYPE:
                 size = ogs_nas_decode_s_nssai(&ul_nas_transport->s_nssai, pkbuf);
                 ogs_assert(size >= 0);
                 ul_nas_transport->presencemask |= OGS_NAS_UL_NAS_TRANSPORT_S_NSSAI_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_UL_NAS_TRANSPORT_DNN_TYPE:
                 size = ogs_nas_decode_dnn(&ul_nas_transport->dnn, pkbuf);
                 ogs_assert(size >= 0);
                 ul_nas_transport->presencemask |= OGS_NAS_UL_NAS_TRANSPORT_DNN_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_UL_NAS_TRANSPORT_ADDITIONAL_INFORMATION_TYPE:
                 size = ogs_nas_decode_additional_information(&ul_nas_transport->additional_information, pkbuf);
                 ogs_assert(size >= 0);
                 ul_nas_transport->presencemask |= OGS_NAS_UL_NAS_TRANSPORT_ADDITIONAL_INFORMATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_UL_NAS_TRANSPORT_MA_PDU_SESSION_INFORMATION_TYPE:
                 size = ogs_nas_decode_ma_pdu_session_information(&ul_nas_transport->ma_pdu_session_information, pkbuf);
                 ogs_assert(size >= 0);
                 ul_nas_transport->presencemask |= OGS_NAS_UL_NAS_TRANSPORT_MA_PDU_SESSION_INFORMATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_UL_NAS_TRANSPORT_RELEASE_ASSISTANCE_INDICATION_TYPE:
                 size = ogs_nas_decode_release_assistance_indication(&ul_nas_transport->release_assistance_indication, pkbuf);
                 ogs_assert(size >= 0);
                 ul_nas_transport->presencemask |= OGS_NAS_UL_NAS_TRANSPORT_RELEASE_ASSISTANCE_INDICATION_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_dl_nas_transport(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_dl_nas_transport_t *dl_nas_transport = &message->emm.dl_nas_transport;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode DL_NAS_TRANSPORT\n");

    size = ogs_nas_decode_payload_container_type(&dl_nas_transport->payload_container_type, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    size = ogs_nas_decode_payload_container(&dl_nas_transport->payload_container, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_DL_NAS_TRANSPORT_ADDITIONAL_INFORMATION_TYPE:
                 size = ogs_nas_decode_additional_information(&dl_nas_transport->additional_information, pkbuf);
                 ogs_assert(size >= 0);
                 dl_nas_transport->presencemask |= OGS_NAS_DL_NAS_TRANSPORT_ADDITIONAL_INFORMATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_DL_NAS_TRANSPORT_5GMM_CAUSE_TYPE:
                 size = ogs_nas_decode_5gmm_cause(&dl_nas_transport->5gmm_cause, pkbuf);
                 ogs_assert(size >= 0);
                 dl_nas_transport->presencemask |= OGS_NAS_DL_NAS_TRANSPORT_5GMM_CAUSE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_DL_NAS_TRANSPORT_BACK_OFF_TIMER_VALUE_TYPE:
                 size = ogs_nas_decode_gprs_timer_3(&dl_nas_transport->back_off_timer_value, pkbuf);
                 ogs_assert(size >= 0);
                 dl_nas_transport->presencemask |= OGS_NAS_DL_NAS_TRANSPORT_BACK_OFF_TIMER_VALUE_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_pdu_session_establishment_request(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_pdu_session_establishment_request_t *pdu_session_establishment_request = &message->esm.pdu_session_establishment_request;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode PDU_SESSION_ESTABLISHMENT_REQUEST\n");

    size = ogs_nas_decode_control_plane_service_type(&pdu_session_establishment_request->control_plane_service_type, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_PDU_SESSION_ESTABLISHMENT_REQUEST_CIOT_SMALL_DATA_CONTAINER_TYPE:
                 size = ogs_nas_decode_ciot_small_data_container(&pdu_session_establishment_request->ciot_small_data_container, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_establishment_request->presencemask |= OGS_NAS_PDU_SESSION_ESTABLISHMENT_REQUEST_CIOT_SMALL_DATA_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_ESTABLISHMENT_REQUEST_PAYLOAD_CONTAINER_TYPE_TYPE:
                 size = ogs_nas_decode_payload_container_type(&pdu_session_establishment_request->payload_container_type, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_establishment_request->presencemask |= OGS_NAS_PDU_SESSION_ESTABLISHMENT_REQUEST_PAYLOAD_CONTAINER_TYPE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_ESTABLISHMENT_REQUEST_PAYLOAD_CONTAINER_TYPE:
                 size = ogs_nas_decode_payload_container(&pdu_session_establishment_request->payload_container, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_establishment_request->presencemask |= OGS_NAS_PDU_SESSION_ESTABLISHMENT_REQUEST_PAYLOAD_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_ESTABLISHMENT_REQUEST_PDU_SESSION_STATUS_TYPE:
                 size = ogs_nas_decode_pdu_session_status(&pdu_session_establishment_request->pdu_session_status, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_establishment_request->presencemask |= OGS_NAS_PDU_SESSION_ESTABLISHMENT_REQUEST_PDU_SESSION_STATUS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_ESTABLISHMENT_REQUEST_RELEASE_ASSISTANCE_INDICATION_TYPE:
                 size = ogs_nas_decode_release_assistance_indication(&pdu_session_establishment_request->release_assistance_indication, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_establishment_request->presencemask |= OGS_NAS_PDU_SESSION_ESTABLISHMENT_REQUEST_RELEASE_ASSISTANCE_INDICATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_ESTABLISHMENT_REQUEST_UPLINK_DATA_STATUS_TYPE:
                 size = ogs_nas_decode_uplink_data_status(&pdu_session_establishment_request->uplink_data_status, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_establishment_request->presencemask |= OGS_NAS_PDU_SESSION_ESTABLISHMENT_REQUEST_UPLINK_DATA_STATUS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_ESTABLISHMENT_REQUEST_NAS_MESSAGE_CONTAINER_TYPE:
                 size = ogs_nas_decode_message_container(&pdu_session_establishment_request->nas_message_container, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_establishment_request->presencemask |= OGS_NAS_PDU_SESSION_ESTABLISHMENT_REQUEST_NAS_MESSAGE_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_ESTABLISHMENT_REQUEST_ADDITIONAL_INFORMATION_TYPE:
                 size = ogs_nas_decode_additional_information(&pdu_session_establishment_request->additional_information, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_establishment_request->presencemask |= OGS_NAS_PDU_SESSION_ESTABLISHMENT_REQUEST_ADDITIONAL_INFORMATION_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_pdu_session_establishment_accept(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_pdu_session_establishment_accept_t *pdu_session_establishment_accept = &message->esm.pdu_session_establishment_accept;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode PDU_SESSION_ESTABLISHMENT_ACCEPT\n");

    size = ogs_nas_decode_s_nssai(&pdu_session_establishment_accept->s_nssai, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    size = ogs_nas_decode_eap_message(&pdu_session_establishment_accept->eap_message, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    return decoded;
}

int ogs_nas_decode_pdu_session_establishment_reject(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_pdu_session_establishment_reject_t *pdu_session_establishment_reject = &message->esm.pdu_session_establishment_reject;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode PDU_SESSION_ESTABLISHMENT_REJECT\n");

    size = ogs_nas_decode_s_nssai(&pdu_session_establishment_reject->s_nssai, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    size = ogs_nas_decode_eap_message(&pdu_session_establishment_reject->eap_message, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    return decoded;
}

int ogs_nas_decode_pdu_session_authentication_command(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_pdu_session_authentication_command_t *pdu_session_authentication_command = &message->esm.pdu_session_authentication_command;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode PDU_SESSION_AUTHENTICATION_COMMAND\n");

    size = ogs_nas_decode_s_nssai(&pdu_session_authentication_command->s_nssai, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    size = ogs_nas_decode_eap_message(&pdu_session_authentication_command->eap_message, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    return decoded;
}

int ogs_nas_decode_pdu_session_authentication_complete(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_pdu_session_authentication_complete_t *pdu_session_authentication_complete = &message->esm.pdu_session_authentication_complete;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode PDU_SESSION_AUTHENTICATION_COMPLETE\n");

    size = ogs_nas_decode_integrity_protection_maximum_data_rate(&pdu_session_authentication_complete->integrity_protection_maximum_data_rate, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_PDU_SESSION_TYPE_TYPE:
                 size = ogs_nas_decode_pdu_session_type(&pdu_session_authentication_complete->pdu_session_type, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_complete->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_PDU_SESSION_TYPE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_SSC_MODE_TYPE:
                 size = ogs_nas_decode_ssc_mode(&pdu_session_authentication_complete->ssc_mode, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_complete->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_SSC_MODE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_5GSM_CAPABILITY_TYPE:
                 size = ogs_nas_decode_5gsm_capability(&pdu_session_authentication_complete->5gsm_capability, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_complete->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_5GSM_CAPABILITY_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_MAXIMUM_NUMBER_OF_SUPPORTED_PACKET_FILTERS_TYPE:
                 size = ogs_nas_decode_maximum_number_of_supported_packet_filters(&pdu_session_authentication_complete->maximum_number_of_supported_packet_filters, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_complete->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_MAXIMUM_NUMBER_OF_SUPPORTED_PACKET_FILTERS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_ALWAYS_ON_PDU_SESSION_REQUESTED_TYPE:
                 size = ogs_nas_decode_always_on_pdu_session_requested(&pdu_session_authentication_complete->always_on_pdu_session_requested, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_complete->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_ALWAYS_ON_PDU_SESSION_REQUESTED_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_SM_PDU_DN_REQUEST_CONTAINER_TYPE:
                 size = ogs_nas_decode_sm_pdu_dn_request_container(&pdu_session_authentication_complete->sm_pdu_dn_request_container, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_complete->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_SM_PDU_DN_REQUEST_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_TYPE:
                 size = ogs_nas_decode_extended_protocol_configuration_options(&pdu_session_authentication_complete->extended_protocol_configuration_options, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_complete->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_HEADER_COMPRESSION_CONFIGURATION_TYPE:
                 size = ogs_nas_decode_header_compression_configuration(&pdu_session_authentication_complete->header_compression_configuration, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_complete->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_HEADER_COMPRESSION_CONFIGURATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_DS_TT_ETHERNET_PORT_MAC_ADDRESS_TYPE:
                 size = ogs_nas_decode_ds_tt_ethernet_port_mac_address(&pdu_session_authentication_complete->ds_tt_ethernet_port_mac_address, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_complete->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_DS_TT_ETHERNET_PORT_MAC_ADDRESS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_UE_DS_TT_RESIDENCE_TIME_TYPE:
                 size = ogs_nas_decode_ue_ds_tt_residence_time(&pdu_session_authentication_complete->ue_ds_tt_residence_time, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_complete->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_UE_DS_TT_RESIDENCE_TIME_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_PORT_MANAGEMENT_INFORMATION_CONTAINER_TYPE:
                 size = ogs_nas_decode_port_management_information_container(&pdu_session_authentication_complete->port_management_information_container, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_complete->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE_PORT_MANAGEMENT_INFORMATION_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_pdu_session_authentication_result(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_pdu_session_authentication_result_t *pdu_session_authentication_result = &message->esm.pdu_session_authentication_result;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode PDU_SESSION_AUTHENTICATION_RESULT\n");

    size = ogs_nas_decode_pdu_session_type(&pdu_session_authentication_result->selected_pdu_session_type, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    size = ogs_nas_decode_qos_rules(&pdu_session_authentication_result->authorized_qos_rules, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    size = ogs_nas_decode_session_ambr(&pdu_session_authentication_result->session_ambr, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_5GSM_CAUSE_TYPE:
                 size = ogs_nas_decode_5gsm_cause(&pdu_session_authentication_result->5gsm_cause, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_result->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_5GSM_CAUSE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_PDU_ADDRESS_TYPE:
                 size = ogs_nas_decode_pdu_address(&pdu_session_authentication_result->pdu_address, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_result->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_PDU_ADDRESS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_RQ_TIMER_VALUE_TYPE:
                 size = ogs_nas_decode_gprs_timer(&pdu_session_authentication_result->rq_timer_value, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_result->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_RQ_TIMER_VALUE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_S_NSSAI_TYPE:
                 size = ogs_nas_decode_s_nssai(&pdu_session_authentication_result->s_nssai, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_result->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_S_NSSAI_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_ALWAYS_ON_PDU_SESSION_INDICATION_TYPE:
                 size = ogs_nas_decode_always_on_pdu_session_indication(&pdu_session_authentication_result->always_on_pdu_session_indication, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_result->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_ALWAYS_ON_PDU_SESSION_INDICATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_MAPPED_EPS_BEARER_CONTEXTS_TYPE:
                 size = ogs_nas_decode_mapped_eps_bearer_contexts(&pdu_session_authentication_result->mapped_eps_bearer_contexts, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_result->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_MAPPED_EPS_BEARER_CONTEXTS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_EAP_MESSAGE_TYPE:
                 size = ogs_nas_decode_eap_message(&pdu_session_authentication_result->eap_message, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_result->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_EAP_MESSAGE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_AUTHORIZED_QOS_FLOW_DESCRIPTIONS_TYPE:
                 size = ogs_nas_decode_qos_flow_descriptions(&pdu_session_authentication_result->authorized_qos_flow_descriptions, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_result->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_AUTHORIZED_QOS_FLOW_DESCRIPTIONS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_TYPE:
                 size = ogs_nas_decode_extended_protocol_configuration_options(&pdu_session_authentication_result->extended_protocol_configuration_options, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_result->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_DNN_TYPE:
                 size = ogs_nas_decode_dnn(&pdu_session_authentication_result->dnn, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_result->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_DNN_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_5GSM_NETWORK_FEATURE_SUPPORT_TYPE:
                 size = ogs_nas_decode_5gsm_network_feature_support(&pdu_session_authentication_result->5gsm_network_feature_support, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_result->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_5GSM_NETWORK_FEATURE_SUPPORT_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_SERVING_PLMN_RATE_CONTROL_TYPE:
                 size = ogs_nas_decode_serving_plmn_rate_control(&pdu_session_authentication_result->serving_plmn_rate_control, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_result->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_SERVING_PLMN_RATE_CONTROL_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_ATSSS_CONTAINER_TYPE:
                 size = ogs_nas_decode_atsss_container(&pdu_session_authentication_result->atsss_container, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_result->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_ATSSS_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_CONTROL_PLANE_ONLY_INDICATION_TYPE:
                 size = ogs_nas_decode_control_plane_only_indication(&pdu_session_authentication_result->control_plane_only_indication, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_result->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_CONTROL_PLANE_ONLY_INDICATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_HEADER_COMPRESSION_CONFIGURATION_TYPE:
                 size = ogs_nas_decode_header_compression_configuration(&pdu_session_authentication_result->header_compression_configuration, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_authentication_result->presencemask |= OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT_HEADER_COMPRESSION_CONFIGURATION_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_pdu_session_modification_request(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_pdu_session_modification_request_t *pdu_session_modification_request = &message->esm.pdu_session_modification_request;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode PDU_SESSION_MODIFICATION_REQUEST\n");

    size = ogs_nas_decode_5gsm_cause(&pdu_session_modification_request->5gsm_cause, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_PDU_SESSION_MODIFICATION_REQUEST_BACK_OFF_TIMER_VALUE_TYPE:
                 size = ogs_nas_decode_gprs_timer_3(&pdu_session_modification_request->back_off_timer_value, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_request->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_REQUEST_BACK_OFF_TIMER_VALUE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_MODIFICATION_REQUEST_ALLOWED_SSC_MODE_TYPE:
                 size = ogs_nas_decode_allowed_ssc_mode(&pdu_session_modification_request->allowed_ssc_mode, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_request->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_REQUEST_ALLOWED_SSC_MODE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_MODIFICATION_REQUEST_EAP_MESSAGE_TYPE:
                 size = ogs_nas_decode_eap_message(&pdu_session_modification_request->eap_message, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_request->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_REQUEST_EAP_MESSAGE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_MODIFICATION_REQUEST_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_TYPE:
                 size = ogs_nas_decode_extended_protocol_configuration_options(&pdu_session_modification_request->extended_protocol_configuration_options, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_request->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_REQUEST_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_MODIFICATION_REQUEST_RE_ATTEMPT_INDICATOR_TYPE:
                 size = ogs_nas_decode_re_attempt_indicator(&pdu_session_modification_request->re_attempt_indicator, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_request->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_REQUEST_RE_ATTEMPT_INDICATOR_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_MODIFICATION_REQUEST_5GSM_CONGESTION_RE_ATTEMPT_INDICATOR_TYPE:
                 size = ogs_nas_decode_5gsm_congestion_re_attempt_indicator(&pdu_session_modification_request->5gsm_congestion_re_attempt_indicator, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_request->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_REQUEST_5GSM_CONGESTION_RE_ATTEMPT_INDICATOR_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_pdu_session_modification_reject(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_pdu_session_modification_reject_t *pdu_session_modification_reject = &message->esm.pdu_session_modification_reject;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode PDU_SESSION_MODIFICATION_REJECT\n");

    size = ogs_nas_decode_eap_message(&pdu_session_modification_reject->eap_message, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_PDU_SESSION_MODIFICATION_REJECT_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_TYPE:
                 size = ogs_nas_decode_extended_protocol_configuration_options(&pdu_session_modification_reject->extended_protocol_configuration_options, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_reject->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_REJECT_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_pdu_session_modification_command(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_pdu_session_modification_command_t *pdu_session_modification_command = &message->esm.pdu_session_modification_command;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode PDU_SESSION_MODIFICATION_COMMAND\n");

    size = ogs_nas_decode_eap_message(&pdu_session_modification_command->eap_message, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_TYPE:
                 size = ogs_nas_decode_extended_protocol_configuration_options(&pdu_session_modification_command->extended_protocol_configuration_options, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_command->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_pdu_session_modification_complete(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_pdu_session_modification_complete_t *pdu_session_modification_complete = &message->esm.pdu_session_modification_complete;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode PDU_SESSION_MODIFICATION_COMPLETE\n");

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_PDU_SESSION_MODIFICATION_COMPLETE_EAP_MESSAGE_TYPE:
                 size = ogs_nas_decode_eap_message(&pdu_session_modification_complete->eap_message, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_complete->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_COMPLETE_EAP_MESSAGE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_MODIFICATION_COMPLETE_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_TYPE:
                 size = ogs_nas_decode_extended_protocol_configuration_options(&pdu_session_modification_complete->extended_protocol_configuration_options, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_complete->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_COMPLETE_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_pdu_session_modification_command_reject(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_pdu_session_modification_command_reject_t *pdu_session_modification_command_reject = &message->esm.pdu_session_modification_command_reject;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode PDU_SESSION_MODIFICATION_COMMAND_REJECT\n");

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_5GSM_CAPABILITY_TYPE:
                 size = ogs_nas_decode_5gsm_capability(&pdu_session_modification_command_reject->5gsm_capability, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_command_reject->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_5GSM_CAPABILITY_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_5GSM_CAUSE_TYPE:
                 size = ogs_nas_decode_5gsm_cause(&pdu_session_modification_command_reject->5gsm_cause, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_command_reject->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_5GSM_CAUSE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_MAXIMUM_NUMBER_OF_SUPPORTED_PACKET_FILTERS_TYPE:
                 size = ogs_nas_decode_maximum_number_of_supported_packet_filters(&pdu_session_modification_command_reject->maximum_number_of_supported_packet_filters, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_command_reject->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_MAXIMUM_NUMBER_OF_SUPPORTED_PACKET_FILTERS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_ALWAYS_ON_PDU_SESSION_REQUESTED_TYPE:
                 size = ogs_nas_decode_always_on_pdu_session_requested(&pdu_session_modification_command_reject->always_on_pdu_session_requested, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_command_reject->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_ALWAYS_ON_PDU_SESSION_REQUESTED_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_INTEGRITY_PROTECTION_MAXIMUM_DATA_RATE_TYPE:
                 size = ogs_nas_decode_integrity_protection_maximum_data_rate(&pdu_session_modification_command_reject->integrity_protection_maximum_data_rate, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_command_reject->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_INTEGRITY_PROTECTION_MAXIMUM_DATA_RATE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_REQUESTED_QOS_RULES_TYPE:
                 size = ogs_nas_decode_qos_rules(&pdu_session_modification_command_reject->requested_qos_rules, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_command_reject->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_REQUESTED_QOS_RULES_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_REQUESTED_QOS_FLOW_DESCRIPTIONS_TYPE:
                 size = ogs_nas_decode_qos_flow_descriptions(&pdu_session_modification_command_reject->requested_qos_flow_descriptions, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_command_reject->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_REQUESTED_QOS_FLOW_DESCRIPTIONS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_MAPPED_EPS_BEARER_CONTEXTS_TYPE:
                 size = ogs_nas_decode_mapped_eps_bearer_contexts(&pdu_session_modification_command_reject->mapped_eps_bearer_contexts, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_command_reject->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_MAPPED_EPS_BEARER_CONTEXTS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_TYPE:
                 size = ogs_nas_decode_extended_protocol_configuration_options(&pdu_session_modification_command_reject->extended_protocol_configuration_options, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_command_reject->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_PORT_MANAGEMENT_INFORMATION_CONTAINER_TYPE:
                 size = ogs_nas_decode_port_management_information_container(&pdu_session_modification_command_reject->port_management_information_container, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_command_reject->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_PORT_MANAGEMENT_INFORMATION_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_HEADER_COMPRESSION_CONFIGURATION_TYPE:
                 size = ogs_nas_decode_header_compression_configuration(&pdu_session_modification_command_reject->header_compression_configuration, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_modification_command_reject->presencemask |= OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT_HEADER_COMPRESSION_CONFIGURATION_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_pdu_session_release_request(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_pdu_session_release_request_t *pdu_session_release_request = &message->esm.pdu_session_release_request;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode PDU_SESSION_RELEASE_REQUEST\n");

    size = ogs_nas_decode_5gsm_cause(&pdu_session_release_request->5gsm_cause, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_PDU_SESSION_RELEASE_REQUEST_BACK_OFF_TIMER_VALUE_TYPE:
                 size = ogs_nas_decode_gprs_timer_3(&pdu_session_release_request->back_off_timer_value, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_release_request->presencemask |= OGS_NAS_PDU_SESSION_RELEASE_REQUEST_BACK_OFF_TIMER_VALUE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_RELEASE_REQUEST_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_TYPE:
                 size = ogs_nas_decode_extended_protocol_configuration_options(&pdu_session_release_request->extended_protocol_configuration_options, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_release_request->presencemask |= OGS_NAS_PDU_SESSION_RELEASE_REQUEST_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_RELEASE_REQUEST_RE_ATTEMPT_INDICATOR_TYPE:
                 size = ogs_nas_decode_re_attempt_indicator(&pdu_session_release_request->re_attempt_indicator, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_release_request->presencemask |= OGS_NAS_PDU_SESSION_RELEASE_REQUEST_RE_ATTEMPT_INDICATOR_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_RELEASE_REQUEST_5GSM_CONGESTION_RE_ATTEMPT_INDICATOR_TYPE:
                 size = ogs_nas_decode_5gsm_congestion_re_attempt_indicator(&pdu_session_release_request->5gsm_congestion_re_attempt_indicator, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_release_request->presencemask |= OGS_NAS_PDU_SESSION_RELEASE_REQUEST_5GSM_CONGESTION_RE_ATTEMPT_INDICATOR_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_pdu_session_release_reject(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_pdu_session_release_reject_t *pdu_session_release_reject = &message->esm.pdu_session_release_reject;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode PDU_SESSION_RELEASE_REJECT\n");

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_PDU_SESSION_RELEASE_REJECT_5GSM_CAUSE_TYPE:
                 size = ogs_nas_decode_5gsm_cause(&pdu_session_release_reject->5gsm_cause, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_release_reject->presencemask |= OGS_NAS_PDU_SESSION_RELEASE_REJECT_5GSM_CAUSE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_RELEASE_REJECT_SESSION_AMBR_TYPE:
                 size = ogs_nas_decode_session_ambr(&pdu_session_release_reject->session_ambr, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_release_reject->presencemask |= OGS_NAS_PDU_SESSION_RELEASE_REJECT_SESSION_AMBR_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_RELEASE_REJECT_RQ_TIMER_VALUE_TYPE:
                 size = ogs_nas_decode_gprs_timer(&pdu_session_release_reject->rq_timer_value, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_release_reject->presencemask |= OGS_NAS_PDU_SESSION_RELEASE_REJECT_RQ_TIMER_VALUE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_RELEASE_REJECT_ALWAYS_ON_PDU_SESSION_INDICATION_TYPE:
                 size = ogs_nas_decode_always_on_pdu_session_indication(&pdu_session_release_reject->always_on_pdu_session_indication, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_release_reject->presencemask |= OGS_NAS_PDU_SESSION_RELEASE_REJECT_ALWAYS_ON_PDU_SESSION_INDICATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_RELEASE_REJECT_AUTHORIZED_QOS_RULES_TYPE:
                 size = ogs_nas_decode_qos_rules(&pdu_session_release_reject->authorized_qos_rules, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_release_reject->presencemask |= OGS_NAS_PDU_SESSION_RELEASE_REJECT_AUTHORIZED_QOS_RULES_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_RELEASE_REJECT_MAPPED_EPS_BEARER_CONTEXTS_TYPE:
                 size = ogs_nas_decode_mapped_eps_bearer_contexts(&pdu_session_release_reject->mapped_eps_bearer_contexts, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_release_reject->presencemask |= OGS_NAS_PDU_SESSION_RELEASE_REJECT_MAPPED_EPS_BEARER_CONTEXTS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_RELEASE_REJECT_AUTHORIZED_QOS_FLOW_DESCRIPTIONS_TYPE:
                 size = ogs_nas_decode_qos_flow_descriptions(&pdu_session_release_reject->authorized_qos_flow_descriptions, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_release_reject->presencemask |= OGS_NAS_PDU_SESSION_RELEASE_REJECT_AUTHORIZED_QOS_FLOW_DESCRIPTIONS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_RELEASE_REJECT_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_TYPE:
                 size = ogs_nas_decode_extended_protocol_configuration_options(&pdu_session_release_reject->extended_protocol_configuration_options, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_release_reject->presencemask |= OGS_NAS_PDU_SESSION_RELEASE_REJECT_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_RELEASE_REJECT_ATSSS_CONTAINER_TYPE:
                 size = ogs_nas_decode_atsss_container(&pdu_session_release_reject->atsss_container, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_release_reject->presencemask |= OGS_NAS_PDU_SESSION_RELEASE_REJECT_ATSSS_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_RELEASE_REJECT_HEADER_COMPRESSION_CONFIGURATION_TYPE:
                 size = ogs_nas_decode_header_compression_configuration(&pdu_session_release_reject->header_compression_configuration, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_release_reject->presencemask |= OGS_NAS_PDU_SESSION_RELEASE_REJECT_HEADER_COMPRESSION_CONFIGURATION_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_RELEASE_REJECT_PORT_MANAGEMENT_INFORMATION_CONTAINER_TYPE:
                 size = ogs_nas_decode_port_management_information_container(&pdu_session_release_reject->port_management_information_container, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_release_reject->presencemask |= OGS_NAS_PDU_SESSION_RELEASE_REJECT_PORT_MANAGEMENT_INFORMATION_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_RELEASE_REJECT_SERVING_PLMN_RATE_CONTROL_TYPE:
                 size = ogs_nas_decode_serving_plmn_rate_control(&pdu_session_release_reject->serving_plmn_rate_control, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_release_reject->presencemask |= OGS_NAS_PDU_SESSION_RELEASE_REJECT_SERVING_PLMN_RATE_CONTROL_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_pdu_session_release_command(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_pdu_session_release_command_t *pdu_session_release_command = &message->esm.pdu_session_release_command;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode PDU_SESSION_RELEASE_COMMAND\n");

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_PDU_SESSION_RELEASE_COMMAND_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_TYPE:
                 size = ogs_nas_decode_extended_protocol_configuration_options(&pdu_session_release_command->extended_protocol_configuration_options, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_release_command->presencemask |= OGS_NAS_PDU_SESSION_RELEASE_COMMAND_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_PDU_SESSION_RELEASE_COMMAND_PORT_MANAGEMENT_INFORMATION_CONTAINER_TYPE:
                 size = ogs_nas_decode_port_management_information_container(&pdu_session_release_command->port_management_information_container, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_release_command->presencemask |= OGS_NAS_PDU_SESSION_RELEASE_COMMAND_PORT_MANAGEMENT_INFORMATION_CONTAINER_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_pdu_session_release_complete(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_pdu_session_release_complete_t *pdu_session_release_complete = &message->esm.pdu_session_release_complete;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode PDU_SESSION_RELEASE_COMPLETE\n");

    size = ogs_nas_decode_5gsm_cause(&pdu_session_release_complete->5gsm_cause, pkbuf);
    ogs_assert(size >= 0);
    decoded += size;

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_PDU_SESSION_RELEASE_COMPLETE_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_TYPE:
                 size = ogs_nas_decode_extended_protocol_configuration_options(&pdu_session_release_complete->extended_protocol_configuration_options, pkbuf);
                 ogs_assert(size >= 0);
                 pdu_session_release_complete->presencemask |= OGS_NAS_PDU_SESSION_RELEASE_COMPLETE_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_decode_5gsm_status(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    ogs_nas_5gsm_status_t *5gsm_status = &message->esm.5gsm_status;
    int decoded = 0;
    int size = 0;

    ogs_trace("[NAS] Decode 5GSM_STATUS\n");

    while(pkbuf->len > 0) 
    {
        uint8_t *buffer = pkbuf->data;
        uint8_t type = (*buffer) >= 0x80 ? ((*buffer) & 0xf0) : (*buffer);

        size = sizeof(uint8_t);
        ogs_assert(ogs_pkbuf_pull(pkbuf, size));
        decoded += size;

        switch(type)
        {
             case OGS_NAS_5GSM_STATUS_5GSM_CAUSE_TYPE:
                 size = ogs_nas_decode_5gsm_cause(&5gsm_status->5gsm_cause, pkbuf);
                 ogs_assert(size >= 0);
                 5gsm_status->presencemask |= OGS_NAS_5GSM_STATUS_5GSM_CAUSE_PRESENT;
                 decoded += size;
                 break;
             case OGS_NAS_5GSM_STATUS_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_TYPE:
                 size = ogs_nas_decode_extended_protocol_configuration_options(&5gsm_status->extended_protocol_configuration_options, pkbuf);
                 ogs_assert(size >= 0);
                 5gsm_status->presencemask |= OGS_NAS_5GSM_STATUS_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS_PRESENT;
                 decoded += size;
                 break;
             default:
                ogs_warn("Unknown type(0x%x) or not implemented\n", type);
                break;
        }
    }

    return decoded;
}

int ogs_nas_emm_decode(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    int size = 0;
    uint16_t decoded = 0;

    ogs_assert(pkbuf);
    ogs_assert(pkbuf->data);
    ogs_assert(pkbuf->len);

    memset(message, 0, sizeof(ogs_nas_message_t));

    size = sizeof(ogs_nas_emm_header_t);
    ogs_assert(ogs_pkbuf_pull(pkbuf, size));
    memcpy(&message->emm.h, pkbuf->data - size, size);
    decoded += size;

    if (message->emm.h.security_header_type >=
            OGS_NAS_SECURITY_HEADER_FOR_SERVICE_REQUEST_MESSAGE)
    {
        ogs_assert(ogs_pkbuf_push(pkbuf, 1));
        decoded -= 1;
        size = ogs_nas_decode_service_request(message, pkbuf);
        ogs_assert(size >= 0);
        decoded += size;

        goto out;
    }

    switch(message->emm.h.message_type)
    {
        case OGS_NAS_REGISTRATION_REQUEST:
            size = ogs_nas_decode_registration_request(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_REGISTRATION_ACCEPT:
            size = ogs_nas_decode_registration_accept(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_REGISTRATION_COMPLETE:
            size = ogs_nas_decode_registration_complete(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_REGISTRATION_REJECT:
            size = ogs_nas_decode_registration_reject(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_DEREGISTRATION_REQUEST:
            size = ogs_nas_decode_deregistration_request_from_ue(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_DEREGISTRATION_ACCEPT:
            break;
        case OGS_NAS_SERVICE_REJECT:
            size = ogs_nas_decode_service_reject(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_SERVICE_ACCEPT:
            size = ogs_nas_decode_service_accept(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_CONFIGURATION_UPDATE_COMMAND:
            size = ogs_nas_decode_configuration_update_command(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_CONFIGURATION_UPDATE_COMPLETE:
            size = ogs_nas_decode_configuration_update_complete(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_AUTHENTICATION_REQUEST:
            size = ogs_nas_decode_authentication_request(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_AUTHENTICATION_RESPONSE:
            size = ogs_nas_decode_authentication_response(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_AUTHENTICATION_REJECT:
            size = ogs_nas_decode_authentication_reject(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_AUTHENTICATION_FAILURE:
            size = ogs_nas_decode_authentication_failure(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_AUTHENTICATION_RESULT:
            size = ogs_nas_decode_authentication_result(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_IDENTITY_REQUEST:
            size = ogs_nas_decode_identity_request(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_IDENTITY_RESPONSE:
            size = ogs_nas_decode_identity_response(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_SECURITY_MODE_COMMAND:
            size = ogs_nas_decode_security_mode_command(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_SECURITY_MODE_COMPLETE:
            size = ogs_nas_decode_security_mode_complete(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_SECURITY_MODE_REJECT:
            size = ogs_nas_decode_security_mode_reject(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_5GMM_STATUS:
            size = ogs_nas_decode_5gmm_status(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_NOTIFICATION:
            size = ogs_nas_decode_notification(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_NOTIFICATION_RESPONSE:
            size = ogs_nas_decode_notification_response(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_UL_NAS_TRANSPORT:
            size = ogs_nas_decode_ul_nas_transport(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_DL_NAS_TRANSPORT:
            size = ogs_nas_decode_dl_nas_transport(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        default:
            ogs_error("Unknown message type (0x%x) or not implemented", 
                    message->emm.h.message_type);
            break;
    }

out:
    ogs_assert(ogs_pkbuf_push(pkbuf, decoded));

    return OGS_OK;
}
int ogs_nas_esm_decode(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf)
{
    int size = 0;
    uint16_t decoded = 0;

    ogs_assert(pkbuf);
    ogs_assert(pkbuf->data);
    ogs_assert(pkbuf->len);

    memset(message, 0, sizeof(ogs_nas_message_t));

    size = sizeof(ogs_nas_esm_header_t);
    ogs_assert(ogs_pkbuf_pull(pkbuf, size));
    memcpy(&message->esm.h, pkbuf->data - size, size);
    decoded += size;

    switch(message->esm.h.message_type)
    {
        case OGS_NAS_PDU_SESSION_ESTABLISHMENT_REQUEST:
            size = ogs_nas_decode_pdu_session_establishment_request(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_PDU_SESSION_ESTABLISHMENT_ACCEPT:
            size = ogs_nas_decode_pdu_session_establishment_accept(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_PDU_SESSION_ESTABLISHMENT_REJECT:
            size = ogs_nas_decode_pdu_session_establishment_reject(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_PDU_SESSION_AUTHENTICATION_COMMAND:
            size = ogs_nas_decode_pdu_session_authentication_command(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE:
            size = ogs_nas_decode_pdu_session_authentication_complete(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT:
            size = ogs_nas_decode_pdu_session_authentication_result(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_PDU_SESSION_MODIFICATION_REQUEST:
            size = ogs_nas_decode_pdu_session_modification_request(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_PDU_SESSION_MODIFICATION_REJECT:
            size = ogs_nas_decode_pdu_session_modification_reject(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND:
            size = ogs_nas_decode_pdu_session_modification_command(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_PDU_SESSION_MODIFICATION_COMPLETE:
            size = ogs_nas_decode_pdu_session_modification_complete(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT:
            size = ogs_nas_decode_pdu_session_modification_command_reject(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_PDU_SESSION_RELEASE_REQUEST:
            size = ogs_nas_decode_pdu_session_release_request(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_PDU_SESSION_RELEASE_REJECT:
            size = ogs_nas_decode_pdu_session_release_reject(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_PDU_SESSION_RELEASE_COMMAND:
            size = ogs_nas_decode_pdu_session_release_command(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_PDU_SESSION_RELEASE_COMPLETE:
            size = ogs_nas_decode_pdu_session_release_complete(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        case OGS_NAS_5GSM_STATUS:
            size = ogs_nas_decode_5gsm_status(message, pkbuf);
            ogs_assert(size >= 0);
            decoded += size;
            break;
        default:
            ogs_error("Unknown message type (0x%x) or not implemented", 
                    message->esm.h.message_type);
            break;
    }

    ogs_assert(ogs_pkbuf_push(pkbuf, decoded));

    return OGS_OK;
}

