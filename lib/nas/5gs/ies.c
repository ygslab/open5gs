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
 * Created on: 2020-05-20 15:05:34.957508 by acetcom
 * from 24501-g41.docx
 ******************************************************************************/

#include "ogs-nas.h"

int ogs_nas_encode_optional_type(ogs_pkbuf_t *pkbuf, uint8_t type)
{
    uint16_t size = sizeof(uint8_t);

    ogs_assert(ogs_pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &type, size);

    return size;
}
/* 9.11.2.2 EAP message
 * O TLV-E 7-1503 */
int ogs_nas_decode_eap_message(ogs_nas_eap_message_t *eap_message, ogs_pkbuf_t *pkbuf)
{
    uint16_t size = 0;
    ogs_nas_eap_message_t *source = (ogs_nas_eap_message_t *)pkbuf->data;

    eap_message->length = be16toh(source->length);
    size = eap_message->length + sizeof(eap_message->length);

    ogs_assert(ogs_pkbuf_pull(pkbuf, size));
    eap_message->buffer = pkbuf->data - size + sizeof(eap_message->length);

    ogs_trace("  EAP_MESSAGE - ");
    ogs_log_hexdump(OGS_LOG_TRACE, (void*)eap_message->buffer, eap_message->length);

    return size;
}

int ogs_nas_encode_eap_message(ogs_pkbuf_t *pkbuf, ogs_nas_eap_message_t *eap_message)
{
    uint16_t size = 0;
    uint16_t target;

    ogs_assert(eap_message);
    ogs_assert(eap_message->buffer);

    size = sizeof(eap_message->length);
    ogs_assert(ogs_pkbuf_pull(pkbuf, size));
    target = htobe16(eap_message->length);
    memcpy(pkbuf->data - size, &target, size);

    size = eap_message->length;
    ogs_assert(ogs_pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, eap_message->buffer, size);

    ogs_trace("  EAP_MESSAGE - ");
    ogs_log_hexdump(OGS_LOG_TRACE, pkbuf->data - size, size);

    return eap_message->length + sizeof(eap_message->length);
}

/* 9.11.3.10 ABBA
 * M LV 3-n */
int ogs_nas_decode_abba(ogs_nas_abba_t *abba, ogs_pkbuf_t *pkbuf)
{
    uint16_t size = 0;
    ogs_nas_abba_t *source = (ogs_nas_abba_t *)pkbuf->data;

    abba->length = source->length;
    size = abba->length + sizeof(abba->length);

    ogs_assert(ogs_pkbuf_pull(pkbuf, size));
    memcpy(abba, pkbuf->data - size, size);

    ogs_trace("  ABBA - ");
    ogs_log_hexdump(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_encode_abba(ogs_pkbuf_t *pkbuf, ogs_nas_abba_t *abba)
{
    uint16_t size = abba->length + sizeof(abba->length);
    ogs_nas_abba_t target;

    memcpy(&target, abba, sizeof(ogs_nas_abba_t));
    ogs_assert(ogs_pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    ogs_trace("  ABBA - ");
    ogs_log_hexdump(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.11.3.15 Authentication parameter AUTN
 * O TLV 18 */
int ogs_nas_decode_authentication_parameter_autn(ogs_nas_authentication_parameter_autn_t *authentication_parameter_autn, ogs_pkbuf_t *pkbuf)
{
    uint16_t size = 0;
    ogs_nas_authentication_parameter_autn_t *source = (ogs_nas_authentication_parameter_autn_t *)pkbuf->data;

    authentication_parameter_autn->length = source->length;
    size = authentication_parameter_autn->length + sizeof(authentication_parameter_autn->length);

    ogs_assert(ogs_pkbuf_pull(pkbuf, size));
    memcpy(authentication_parameter_autn, pkbuf->data - size, size);

    ogs_trace("  AUTHENTICATION_PARAMETER_AUTN - ");
    ogs_log_hexdump(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_encode_authentication_parameter_autn(ogs_pkbuf_t *pkbuf, ogs_nas_authentication_parameter_autn_t *authentication_parameter_autn)
{
    uint16_t size = authentication_parameter_autn->length + sizeof(authentication_parameter_autn->length);
    ogs_nas_authentication_parameter_autn_t target;

    memcpy(&target, authentication_parameter_autn, sizeof(ogs_nas_authentication_parameter_autn_t));
    ogs_assert(ogs_pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    ogs_trace("  AUTHENTICATION_PARAMETER_AUTN - ");
    ogs_log_hexdump(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.11.3.16 Authentication parameter RAND
 * O TV 17 */
int ogs_nas_decode_authentication_parameter_rand(ogs_nas_authentication_parameter_rand_t *authentication_parameter_rand, ogs_pkbuf_t *pkbuf)
{
    uint16_t size = sizeof(ogs_nas_authentication_parameter_rand_t);

    ogs_assert(ogs_pkbuf_pull(pkbuf, size));
    memcpy(authentication_parameter_rand, pkbuf->data - size, size);

    ogs_trace("  AUTHENTICATION_PARAMETER_RAND - ");
    ogs_log_hexdump(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_encode_authentication_parameter_rand(ogs_pkbuf_t *pkbuf, ogs_nas_authentication_parameter_rand_t *authentication_parameter_rand)
{
    uint16_t size = sizeof(ogs_nas_authentication_parameter_rand_t);
    ogs_nas_authentication_parameter_rand_t target;

    memcpy(&target, authentication_parameter_rand, size);
    ogs_assert(ogs_pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    ogs_trace("  AUTHENTICATION_PARAMETER_RAND - ");
    ogs_log_hexdump(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.11.3.32 key set identifier
 * M V 1/2 */
int ogs_nas_decode_key_set_identifier(ogs_nas_key_set_identifier_t *key_set_identifier, ogs_pkbuf_t *pkbuf)
{
    uint16_t size = sizeof(ogs_nas_key_set_identifier_t);

    ogs_assert(ogs_pkbuf_pull(pkbuf, size));
    memcpy(key_set_identifier, pkbuf->data - size, size);

    ogs_trace("  KEY_SET_IDENTIFIER - ");
    ogs_log_hexdump(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_encode_key_set_identifier(ogs_pkbuf_t *pkbuf, ogs_nas_key_set_identifier_t *key_set_identifier)
{
    uint16_t size = sizeof(ogs_nas_key_set_identifier_t);
    ogs_nas_key_set_identifier_t target;

    memcpy(&target, key_set_identifier, size);
    ogs_assert(ogs_pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    ogs_trace("  KEY_SET_IDENTIFIER - ");
    ogs_log_hexdump(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

