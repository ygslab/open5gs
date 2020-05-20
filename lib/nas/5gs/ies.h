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
 * Created on: 2020-05-20 15:05:34.957213 by acetcom
 * from 24501-g41.docx
 ******************************************************************************/

#if !defined(OGS_NAS_INSIDE) && !defined(OGS_NAS_COMPILATION)
#error "This header cannot be included directly."
#endif

#ifndef OGS_NAS_IES_H
#define OGS_NAS_IES_H

#ifdef __cplusplus
extern "C" {
#endif

int ogs_nas_encode_optional_type(ogs_pkbuf_t *pkbuf, uint8_t type);

int ogs_nas_decode_eap_message(ogs_nas_eap_message_t *eap_message, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_abba(ogs_nas_abba_t *abba, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_authentication_parameter_autn(ogs_nas_authentication_parameter_autn_t *authentication_parameter_autn, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_authentication_parameter_rand(ogs_nas_authentication_parameter_rand_t *authentication_parameter_rand, ogs_pkbuf_t *pkbuf);
int ogs_nas_decode_key_set_identifier(ogs_nas_key_set_identifier_t *key_set_identifier, ogs_pkbuf_t *pkbuf);

int ogs_nas_encode_eap_message(ogs_pkbuf_t *pkbuf, ogs_nas_eap_message_t *eap_message);
int ogs_nas_encode_abba(ogs_pkbuf_t *pkbuf, ogs_nas_abba_t *abba);
int ogs_nas_encode_authentication_parameter_autn(ogs_pkbuf_t *pkbuf, ogs_nas_authentication_parameter_autn_t *authentication_parameter_autn);
int ogs_nas_encode_authentication_parameter_rand(ogs_pkbuf_t *pkbuf, ogs_nas_authentication_parameter_rand_t *authentication_parameter_rand);
int ogs_nas_encode_key_set_identifier(ogs_pkbuf_t *pkbuf, ogs_nas_key_set_identifier_t *key_set_identifier);

#ifdef __cplusplus
}
#endif

#endif /* OGS_NAS_IES_H */

