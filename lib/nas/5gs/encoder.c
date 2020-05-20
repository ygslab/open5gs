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
 * Created on: 2020-05-20 15:05:34.958707 by acetcom
 * from 24501-g41.docx
 ******************************************************************************/

#include "ogs-nas.h"

int ogs_nas_encode_authentication_request(ogs_pkbuf_t *pkbuf, ogs_nas_message_t *message);
int ogs_nas_encode_authentication_request(ogs_pkbuf_t *pkbuf, ogs_nas_message_t *message)
{
    ogs_nas_authentication_request_t *authentication_request = &message->emm.authentication_request;
    int encoded = 0;
    int size = 0;

    ogs_trace("[NAS] Encode AUTHENTICATION_REQUEST");

    size = ogs_nas_encode_key_set_identifier(pkbuf, &authentication_request->ngksi);
    ogs_assert(size >= 0);
    encoded += size;

    size = ogs_nas_encode_abba(pkbuf, &authentication_request->abba);
    ogs_assert(size >= 0);
    encoded += size;

    if (authentication_request->presencemask & OGS_NAS_AUTHENTICATION_REQUEST_AUTHENTICATION_PARAMETER_RAND_PRESENT)
    {
        size = ogs_nas_encode_optional_type(pkbuf, OGS_NAS_AUTHENTICATION_REQUEST_AUTHENTICATION_PARAMETER_RAND_TYPE);
        ogs_assert(size >= 0);
        encoded += size;

        size = ogs_nas_encode_authentication_parameter_rand(pkbuf, &authentication_request->authentication_parameter_rand);
        ogs_assert(size >= 0);
        encoded += size;
    }

    if (authentication_request->presencemask & OGS_NAS_AUTHENTICATION_REQUEST_AUTHENTICATION_PARAMETER_AUTN_PRESENT)
    {
        size = ogs_nas_encode_optional_type(pkbuf, OGS_NAS_AUTHENTICATION_REQUEST_AUTHENTICATION_PARAMETER_AUTN_TYPE);
        ogs_assert(size >= 0);
        encoded += size;

        size = ogs_nas_encode_authentication_parameter_autn(pkbuf, &authentication_request->authentication_parameter_autn);
        ogs_assert(size >= 0);
        encoded += size;
    }

    if (authentication_request->presencemask & OGS_NAS_AUTHENTICATION_REQUEST_EAP_MESSAGE_PRESENT)
    {
        size = ogs_nas_encode_optional_type(pkbuf, OGS_NAS_AUTHENTICATION_REQUEST_EAP_MESSAGE_TYPE);
        ogs_assert(size >= 0);
        encoded += size;

        size = ogs_nas_encode_eap_message(pkbuf, &authentication_request->eap_message);
        ogs_assert(size >= 0);
        encoded += size;
    }

    return encoded;
}

ogs_pkbuf_t *ogs_nas_emm_encode(ogs_nas_message_t *message)
{
    ogs_pkbuf_t *pkbuf = NULL;
    int size = 0;
    int encoded = 0;

    ogs_assert(message);

    /* The Packet Buffer(ogs_pkbuf_t) for NAS message MUST make a HEADROOM. 
     * When calculating AES_CMAC, we need to use the headroom of the packet. */
    pkbuf = ogs_pkbuf_alloc(NULL, OGS_MAX_SDU_LEN);
    ogs_assert(pkbuf);
    ogs_pkbuf_reserve(pkbuf, OGS_NAS_HEADROOM);
    ogs_pkbuf_put(pkbuf, OGS_MAX_SDU_LEN-OGS_NAS_HEADROOM);

    size = sizeof(ogs_nas_emm_header_t);
    ogs_assert(ogs_pkbuf_pull(pkbuf, size));

    memcpy(pkbuf->data - size, &message->emm.h, size);
    encoded += size;

    if (message->emm.h.security_header_type >=
            OGS_NAS_SECURITY_HEADER_FOR_SERVICE_REQUEST_MESSAGE)
    {
        ogs_assert(ogs_pkbuf_push(pkbuf, 1));
        encoded -= 1;
        size = ogs_nas_encode_service_request(pkbuf, message);
        ogs_assert(size >= 0);
        encoded += size;

        goto out;
    }

    switch(message->emm.h.message_type)
    {
        case OGS_NAS_AUTHENTICATION_REQUEST:
            size = ogs_nas_encode_authentication_request(pkbuf, message);
            ogs_assert(size >= 0);
            encoded += size;
            break;
        default:
            ogs_error("Unknown message type (0x%x) or not implemented", 
                    message->emm.h.message_type);
            ogs_pkbuf_free(pkbuf);
            return NULL;
    }

out:
    ogs_assert(ogs_pkbuf_push(pkbuf, encoded));

    pkbuf->len = encoded;

    return pkbuf;
}

ogs_pkbuf_t *ogs_nas_esm_encode(ogs_nas_message_t *message)
{
    ogs_pkbuf_t *pkbuf = NULL;
    int size = 0;
    int encoded = 0;

    ogs_assert(message);

    /* The Packet Buffer(ogs_pkbuf_t) for NAS message MUST make a HEADROOM. 
     * When calculating AES_CMAC, we need to use the headroom of the packet. */
    pkbuf = ogs_pkbuf_alloc(NULL, OGS_MAX_SDU_LEN);
    ogs_assert(pkbuf);
    ogs_pkbuf_reserve(pkbuf, OGS_NAS_HEADROOM);
    ogs_pkbuf_put(pkbuf, OGS_MAX_SDU_LEN-OGS_NAS_HEADROOM);

    size = sizeof(ogs_nas_esm_header_t);
    ogs_assert(ogs_pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &message->esm.h, size);
    encoded += size;

    switch(message->esm.h.message_type)
    {
        default:
            ogs_error("Unknown message type (0x%x) or not implemented", 
                    message->esm.h.message_type);
            ogs_pkbuf_free(pkbuf);
            return NULL;
    }

    ogs_assert(ogs_pkbuf_push(pkbuf, encoded));
    pkbuf->len = encoded;

    return pkbuf;
}

ogs_pkbuf_t *ogs_nas_plain_encode(ogs_nas_message_t *message)
{
    ogs_assert(message);

    ogs_assert(message->emm.h.protocol_discriminator ==
            message->esm.h.protocol_discriminator);

    if (message->emm.h.protocol_discriminator == 
            OGS_NAS_PROTOCOL_DISCRIMINATOR_EMM)
        return ogs_nas_emm_encode(message);
    else if (message->emm.h.protocol_discriminator == 
            OGS_NAS_PROTOCOL_DISCRIMINATOR_ESM)
        return ogs_nas_esm_encode(message);

    return NULL;
}
