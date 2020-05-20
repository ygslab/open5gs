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
 * Created on: 2020-05-20 15:05:34.958018 by acetcom
 * from 24501-g41.docx
 ******************************************************************************/

#if !defined(OGS_NAS_INSIDE) && !defined(OGS_NAS_COMPILATION)
#error "This header cannot be included directly."
#endif

#ifndef OGS_NAS_MESSAGE_H
#define OGS_NAS_MESSAGE_H

#ifdef __cplusplus
extern "C" {
#endif

/* The Packet Buffer(ogs_pkbuf_t) for NAS message MUST make a HEADROOM. 
 * When calculating AES_CMAC, we need to use the headroom of the packet. */
#define OGS_NAS_HEADROOM 16

#define OGS_NAS_SECURITY_HEADER_PLAIN_NAS_MESSAGE 0
#define OGS_NAS_SECURITY_HEADER_INTEGRITY_PROTECTED 1
#define OGS_NAS_SECURITY_HEADER_INTEGRITY_PROTECTED_AND_CIPHERED 2
#define OGS_NAS_SECURITY_HEADER_INTEGRITY_PROTECTED_AND_NEW_SECURITY_CONTEXT 3
#define OGS_NAS_SECURITY_HEADER_INTEGRITY_PROTECTED_AND_CIPHTERD_WITH_NEW_INTEGRITY_CONTEXT 4
#define OGS_NAS_SECURITY_HEADER_INTEGRITY_PROTECTED_AND_PARTICALLY_CIPHTERD 5
#define OGS_NAS_SECURITY_HEADER_FOR_SERVICE_REQUEST_MESSAGE 12

#define OGS_NAS_PROTOCOL_DISCRIMINATOR_ESM 0x2
#define OGS_NAS_PROTOCOL_DISCRIMINATOR_EMM 0x7

#define OGS_NAS_EPS_BEARER_IDENTITY_UNASSIGNED 0

typedef struct ogs_nas_emm_header_s {
ED2(uint8_t security_header_type:4;,
    uint8_t protocol_discriminator:4;)
    uint8_t message_type;
} __attribute__ ((packed)) ogs_nas_emm_header_t;

typedef struct ogs_nas_esm_header_s {
ED2(uint8_t eps_bearer_identity:4;,
    uint8_t protocol_discriminator:4;)
    uint8_t procedure_transaction_identity;
    uint8_t message_type;
} __attribute__ ((packed)) ogs_nas_esm_header_t;

typedef struct ogs_nas_security_header_s {
ED2(uint8_t security_header_type:4;,
    uint8_t protocol_discriminator:4;)
    uint32_t message_authentication_code;
    uint8_t sequence_number;
} __attribute__ ((packed)) ogs_nas_security_header_t;

#define OGS_NAS_REGISTRATION_REQUEST 65
#define OGS_NAS_REGISTRATION_ACCEPT 66
#define OGS_NAS_REGISTRATION_COMPLETE 67
#define OGS_NAS_REGISTRATION_REJECT 68
#define OGS_NAS_DEREGISTRATION_REQUEST 69
#define OGS_NAS_DEREGISTRATION_ACCEPT 70
#define OGS_NAS_SERVICE_REJECT 77
#define OGS_NAS_SERVICE_ACCEPT 78
#define OGS_NAS_CONFIGURATION_UPDATE_COMMAND 84
#define OGS_NAS_CONFIGURATION_UPDATE_COMPLETE 85
#define OGS_NAS_AUTHENTICATION_REQUEST 86
#define OGS_NAS_AUTHENTICATION_RESPONSE 87
#define OGS_NAS_AUTHENTICATION_REJECT 88
#define OGS_NAS_AUTHENTICATION_FAILURE 89
#define OGS_NAS_AUTHENTICATION_RESULT 90
#define OGS_NAS_IDENTITY_REQUEST 91
#define OGS_NAS_IDENTITY_RESPONSE 92
#define OGS_NAS_SECURITY_MODE_COMMAND 93
#define OGS_NAS_SECURITY_MODE_COMPLETE 94
#define OGS_NAS_SECURITY_MODE_REJECT 95
#define OGS_NAS_5GMM_STATUS 100
#define OGS_NAS_NOTIFICATION 101
#define OGS_NAS_NOTIFICATION_RESPONSE 102
#define OGS_NAS_UL_NAS_TRANSPORT 103
#define OGS_NAS_DL_NAS_TRANSPORT 104
#define OGS_NAS_PDU_SESSION_ESTABLISHMENT_REQUEST 193
#define OGS_NAS_PDU_SESSION_ESTABLISHMENT_ACCEPT 194
#define OGS_NAS_PDU_SESSION_ESTABLISHMENT_REJECT 195
#define OGS_NAS_PDU_SESSION_AUTHENTICATION_COMMAND 197
#define OGS_NAS_PDU_SESSION_AUTHENTICATION_COMPLETE 198
#define OGS_NAS_PDU_SESSION_AUTHENTICATION_RESULT 199
#define OGS_NAS_PDU_SESSION_MODIFICATION_REQUEST 201
#define OGS_NAS_PDU_SESSION_MODIFICATION_REJECT 202
#define OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND 203
#define OGS_NAS_PDU_SESSION_MODIFICATION_COMPLETE 204
#define OGS_NAS_PDU_SESSION_MODIFICATION_COMMAND_REJECT 205
#define OGS_NAS_PDU_SESSION_RELEASE_REQUEST 209
#define OGS_NAS_PDU_SESSION_RELEASE_REJECT 210
#define OGS_NAS_PDU_SESSION_RELEASE_COMMAND 211
#define OGS_NAS_PDU_SESSION_RELEASE_COMPLETE 212
#define OGS_NAS_5GSM_STATUS 214


/*******************************************************
 * AUTHENTICATION REQUEST
 ******************************************************/
#define OGS_NAS_AUTHENTICATION_REQUEST_AUTHENTICATION_PARAMETER_RAND_PRESENT (1<<0)
#define OGS_NAS_AUTHENTICATION_REQUEST_AUTHENTICATION_PARAMETER_AUTN_PRESENT (1<<1)
#define OGS_NAS_AUTHENTICATION_REQUEST_EAP_MESSAGE_PRESENT (1<<2)
#define OGS_NAS_AUTHENTICATION_REQUEST_AUTHENTICATION_PARAMETER_RAND_TYPE 0x21
#define OGS_NAS_AUTHENTICATION_REQUEST_AUTHENTICATION_PARAMETER_AUTN_TYPE 0x20
#define OGS_NAS_AUTHENTICATION_REQUEST_EAP_MESSAGE_TYPE 0x78

typedef struct ogs_nas_authentication_request_s {
    /* Mandatory fields */
    ogs_nas_key_set_identifier_t ngksi;
    ogs_nas_abba_t abba;

    /* Optional fields */
    uint32_t presencemask;
    ogs_nas_authentication_parameter_rand_t authentication_parameter_rand;
    ogs_nas_authentication_parameter_autn_t authentication_parameter_autn;
    ogs_nas_eap_message_t eap_message;
} ogs_nas_authentication_request_t;


typedef struct ogs_nas_emm_message_s {
    ogs_nas_emm_header_t h;
    union {
        ogs_nas_authentication_request_t authentication_request;
    };
} ogs_nas_emm_message_t;

typedef struct ogs_nas_esm_message_s {
    ogs_nas_esm_header_t h;
    union {
    };
} ogs_nas_esm_message_t;

typedef struct ogs_nas_message_s {
    ogs_nas_security_header_t h;
    union {
        ogs_nas_emm_message_t emm;
        ogs_nas_esm_message_t esm;
    };
} ogs_nas_message_t;

ogs_pkbuf_t *ogs_nas_emm_encode(ogs_nas_message_t *message);
ogs_pkbuf_t *ogs_nas_esm_encode(ogs_nas_message_t *message);
int ogs_nas_emm_decode(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
int ogs_nas_esm_decode(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
ogs_pkbuf_t *ogs_nas_plain_encode(ogs_nas_message_t *message);

#ifdef __cplusplus
}
#endif

#endif /* OGS_NAS_MESSAGE_H */
