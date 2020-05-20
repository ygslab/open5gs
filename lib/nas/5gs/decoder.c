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
 * Created on: 2020-05-20 15:05:34.958466 by acetcom
 * from 24501-g41.docx
 ******************************************************************************/

#include "ogs-nas.h"

int ogs_nas_decode_authentication_request(ogs_nas_message_t *message, ogs_pkbuf_t *pkbuf);
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
        case OGS_NAS_AUTHENTICATION_REQUEST:
            size = ogs_nas_decode_authentication_request(message, pkbuf);
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
        default:
            ogs_error("Unknown message type (0x%x) or not implemented", 
                    message->esm.h.message_type);
            break;
    }

    ogs_assert(ogs_pkbuf_push(pkbuf, decoded));

    return OGS_OK;
}

