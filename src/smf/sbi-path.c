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

#include "context.h"
#include "sbi-path.h"

static int server_cb(ogs_sbi_session_t *session, ogs_sbi_request_t *request)
{
    smf_event_t *e = NULL;
    int rv;

    ogs_assert(session);
    ogs_assert(request);

    e = smf_event_new(SMF_EVT_SBI_SERVER);
    ogs_assert(e);

    e->sbi.session = session;
    e->sbi.request = request;

    rv = ogs_queue_push(smf_self()->queue, e);
    if (rv != OGS_OK) {
        ogs_error("ogs_queue_push() failed:%d", (int)rv);
        smf_event_free(e);
        return OGS_ERROR;
    }

    return OGS_OK;
}

static int client_cb(ogs_sbi_response_t *response, void *data)
{
    smf_event_t *e = NULL;
    int rv;

    ogs_assert(response);

    e = smf_event_new(SMF_EVT_SBI_CLIENT);
    ogs_assert(e);
    e->sbi.response = response;
    e->sbi.data = data;

    rv = ogs_queue_push(smf_self()->queue, e);
    if (rv != OGS_OK) {
        ogs_error("ogs_queue_push() failed:%d", (int)rv);
        smf_event_free(e);
        return OGS_ERROR;
    }

    return OGS_OK;
}

int smf_sbi_open(void)
{
    ogs_sbi_client_t *client = NULL;

    ogs_sbi_server_start_all(server_cb);

    ogs_list_for_each(&ogs_sbi_self()->client_list, client) {
        smf_event_t e;

        client->cb = client_cb;
        e.sbi.data = client;

        ogs_fsm_create(&client->sm, smf_nf_state_initial, smf_nf_state_final);
        ogs_fsm_init(&client->sm, &e);
    }

    return OGS_OK;
}

void smf_sbi_close(void)
{
    ogs_sbi_client_t *client = NULL;

    ogs_list_for_each(&ogs_sbi_self()->client_list, client) {
        smf_event_t e;

        client->cb = client_cb;
        e.sbi.data = client;

        ogs_fsm_fini(&client->sm, &e);
        ogs_fsm_delete(&client->sm);
    }

    ogs_sbi_server_stop_all();
}

void smf_sbi_send_nf_register(
        ogs_sbi_client_t *client,
        ogs_sbi_nf_type_e nf_type, ogs_sbi_nf_status_e nf_status)
{
    ogs_sbi_request_t *request = NULL;

    ogs_assert(client);

    request = smf_nnrf_build_nf_register(client, nf_type, nf_status);
    ogs_assert(request);
    ogs_sbi_client_send_request(client, request, client);
}

void smf_sbi_send_nf_update(ogs_sbi_client_t *client)
{
    ogs_sbi_request_t *request = NULL;

    ogs_assert(client);

    request = smf_nnrf_build_nf_update(client);
    ogs_assert(request);
    ogs_sbi_client_send_request(client, request, client);
}

void smf_sbi_send_nf_de_register(ogs_sbi_client_t *client)
{
    ogs_sbi_request_t *request = NULL;

    ogs_assert(client);

    request = smf_nnrf_build_nf_de_register(client);
    ogs_assert(request);
    ogs_sbi_client_send_request(client, request, client);
}

void smf_sbi_send_nf_status_subscribe(ogs_sbi_client_t *client)
{
    ogs_sbi_request_t *request = NULL;

    ogs_assert(client);

    request = smf_nnrf_build_nf_status_subscribe(client);
    ogs_assert(request);
    ogs_sbi_client_send_request(client, request, client);
}
