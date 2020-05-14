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

#include "nnrf-handler.h"

bool nrf_nnrf_handle_nf_register(nrf_nf_instance_t *nf_instance,
        ogs_sbi_session_t *session, ogs_sbi_message_t *message)
{
    ogs_sbi_response_t *response = NULL;
    ogs_sbi_nf_profile_t *nf_profile = NULL;
    int status;
    ogs_sbi_lnode_t *node;

    ogs_assert(nf_instance);
    ogs_assert(session);
    ogs_assert(message);

    nrf_nf_instance_clear(nf_instance);

    nf_profile = message->nf_profile;
    if (!nf_profile) {
        ogs_sbi_server_send_error(session,
                OGS_SBI_HTTP_STATUS_BAD_REQUEST,
                message, "No NFProfile", NULL);
        return false;
    }

    nf_instance->nf_type = nf_profile->nf_type;
    nf_instance->nf_status = nf_profile->nf_status;
    nf_instance->heart_beat_timer = nf_profile->heart_beat_timer;

    if (nf_profile->fqdn)
        ogs_fqdn_parse(nf_instance->fqdn,
                nf_profile->fqdn, strlen(nf_profile->fqdn));

    /* Only one time handles RegisterNFInstance operation */
    nf_instance->ipv4_addresses = ogs_sbi_list_create();
    nf_instance->ipv6_addresses = ogs_sbi_list_create();

    ogs_sbi_list_for_each(nf_profile->ipv4_addresses, node) {
        if (node->data)
            ogs_sbi_list_add(nf_instance->ipv4_addresses,
                    ogs_strdup(node->data));
    }
    ogs_sbi_list_for_each(nf_profile->ipv6_addresses, node) {
        if (node->data)
            ogs_sbi_list_add(nf_instance->ipv6_addresses,
                    ogs_strdup(node->data));
    }

    if (OGS_FSM_CHECK(&nf_instance->sm, nrf_nf_state_will_register)) {
        message->http.location = true;
        status = OGS_SBI_HTTP_STATUS_CREATED;
    } else if (OGS_FSM_CHECK(&nf_instance->sm, nrf_nf_state_registered)) {
        status = OGS_SBI_HTTP_STATUS_OK;
    } else
        ogs_assert_if_reached();

    response = ogs_sbi_build_response(message);
    ogs_assert(response);
    ogs_sbi_server_send_response(session, response, status);

    return true;
}

bool nrf_nnrf_handle_nf_update(nrf_nf_instance_t *nf_instance,
        ogs_sbi_session_t *session, ogs_sbi_message_t *message)
{
    ogs_sbi_response_t *response = NULL;
    ogs_sbi_list_t *patch_list = NULL;
    ogs_sbi_lnode_t *node;

    ogs_assert(nf_instance);
    ogs_assert(session);
    ogs_assert(message);

    SWITCH(message->h.method)
    CASE(OGS_SBI_HTTP_METHOD_PUT)
        return nrf_nnrf_handle_nf_register(
                nf_instance, session, message);

    CASE(OGS_SBI_HTTP_METHOD_PATCH)
        patch_list = message->patch_list;
        if (!patch_list) {
            ogs_sbi_server_send_error(session,
                    OGS_SBI_HTTP_STATUS_BAD_REQUEST,
                    message, "No PatchItem Array", NULL);
            return false;
        }

        ogs_sbi_list_for_each(patch_list, node) {
            ogs_sbi_patch_item_t *patch_item = node->data;
            if (!patch_item) {
                ogs_sbi_server_send_error(session,
                        OGS_SBI_HTTP_STATUS_BAD_REQUEST,
                        message, "No PatchItem", NULL);
                return false;
            }
        }

        response = ogs_sbi_build_response(message);
        ogs_assert(response);
        ogs_sbi_server_send_response(session, response,
                OGS_SBI_HTTP_STATUS_NO_CONTENT);
        break;

    DEFAULT
        ogs_error("Invalid HTTP method [%s]",
                message->h.method);
        ogs_assert_if_reached();
    END

    return true;
}

bool nrf_nnrf_handle_nf_status_subscribe(nrf_nf_instance_t *nf_instance,
        ogs_sbi_session_t *session, ogs_sbi_message_t *message)
{
    ogs_sbi_response_t *response = NULL;
    ogs_sbi_subscription_data_t *subscription_data = NULL;
    int status;

    ogs_assert(nf_instance);
    ogs_assert(session);
    ogs_assert(message);

    subscription_data = message->subscription_data;
    if (!subscription_data) {
        ogs_sbi_server_send_error(session,
                OGS_SBI_HTTP_STATUS_BAD_REQUEST,
                message, "No SubscriptionData", NULL);
        return false;
    }

    message->http.location = true;
    status = OGS_SBI_HTTP_STATUS_CREATED;

    response = ogs_sbi_build_response(message);
    ogs_assert(response);
    ogs_sbi_server_send_response(session, response, status);

    return true;
}
