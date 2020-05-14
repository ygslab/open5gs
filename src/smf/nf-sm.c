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
#include "nnrf-handler.h"

void smf_nf_state_initial(ogs_fsm_t *s, smf_event_t *e)
{
    ogs_sbi_client_t *client = NULL;

    ogs_assert(s);
    ogs_assert(e);

    smf_sm_debug(e);

    client = e->sbi.data;
    ogs_assert(client);

    client->t_registration = ogs_timer_add(smf_self()->timer_mgr,
            smf_timer_sbi_registration, client);
    ogs_assert(client->t_registration);
    client->t_heartbeat = ogs_timer_add(smf_self()->timer_mgr,
            smf_timer_sbi_heartbeat, client);
    ogs_assert(client->t_heartbeat);
    client->t_no_heartbeat = ogs_timer_add(smf_self()->timer_mgr,
            smf_timer_sbi_no_heartbeat, client);
    ogs_assert(client->t_no_heartbeat);

    OGS_FSM_TRAN(s, &smf_nf_state_will_register);
}

void smf_nf_state_final(ogs_fsm_t *s, smf_event_t *e)
{
    ogs_sbi_client_t *client = NULL;

    ogs_assert(s);
    ogs_assert(e);

    smf_sm_debug(e);

    client = e->sbi.data;
    ogs_assert(client);

    ogs_timer_delete(client->t_registration);
    ogs_timer_delete(client->t_heartbeat);
    ogs_timer_delete(client->t_no_heartbeat);
}

void smf_nf_state_will_register(ogs_fsm_t *s, smf_event_t *e)
{
    char buf[OGS_ADDRSTRLEN];

    ogs_sbi_client_t *client = NULL;
    ogs_sbi_message_t *message = NULL;
    ogs_sockaddr_t *addr = NULL;

    ogs_assert(s);
    ogs_assert(e);

    smf_sm_debug(e);

    client = e->sbi.data;
    ogs_assert(client);

    switch (e->id) {
    case OGS_FSM_ENTRY_SIG:
        ogs_timer_start(client->t_registration,
                smf_timer_cfg(SMF_TIMER_SBI_REGISTRATION)->duration);

        smf_sbi_send_nf_register(client,
                smf_self()->nf_type, ogs_sbi_nf_status_REGISTERED);
        break;

    case OGS_FSM_EXIT_SIG:
        ogs_timer_stop(client->t_registration);
        break;

    case SMF_EVT_SBI_CLIENT:
        message = e->sbi.message;
        ogs_assert(message);

        SWITCH(message->h.api.name)
        CASE(OGS_SBI_API_NAME_NRF_NFM)

            SWITCH(message->h.resource.name)
            CASE(OGS_SBI_RESOURCE_NAME_NF_INSTANCES)

                if (message->res_status == OGS_SBI_HTTP_STATUS_OK ||
                    message->res_status == OGS_SBI_HTTP_STATUS_CREATED) {
                    smf_nnrf_handle_nf_register(client, message);
                    OGS_FSM_TRAN(s, &smf_nf_state_registered);
                } else {
                    ogs_error("HTTP Response Status Code [%d]",
                            message->res_status);
                    OGS_FSM_TRAN(s, &smf_nf_state_exception);
                }
                break;

            DEFAULT
                ogs_error("Invalid resource name [%s]",
                        message->h.resource.name);
            END
            break;

        DEFAULT
            ogs_error("Invalid API name [%s]", message->h.api.name);
        END
        break;

    case SMF_EVT_SBI_TIMER:
        switch(e->timer_id) {
        case SMF_TIMER_SBI_REGISTRATION:
            addr = client->addr;
            ogs_assert(addr);

            ogs_warn("Retry to registration with NRF [%s]:%d",
                        OGS_ADDR(addr, buf), OGS_PORT(addr));

            ogs_timer_start(client->t_registration,
                smf_timer_cfg(SMF_TIMER_SBI_REGISTRATION)->duration);

            smf_sbi_send_nf_register(client,
                    smf_self()->nf_type, ogs_sbi_nf_status_REGISTERED);
            break;

        default:
            ogs_error("Unknown timer[%s:%d]",
                    smf_timer_get_name(e->timer_id), e->timer_id);
            break;
        }
        break;

    default:
        ogs_error("Unknown event %s", smf_event_get_name(e));
        break;
    }
}

void smf_nf_state_registered(ogs_fsm_t *s, smf_event_t *e)
{
    ogs_sbi_client_t *client = NULL;
    ogs_sbi_message_t *message = NULL;
    ogs_assert(s);
    ogs_assert(e);

    smf_sm_debug(e);

    client = e->sbi.data;
    ogs_assert(client);

    switch (e->id) {
    case OGS_FSM_ENTRY_SIG:
        ogs_info("NF registered [%s]", ogs_sbi_self()->nf_instance_id);

        smf_timer_cfg(SMF_TIMER_SBI_HEARTBEAT)->duration =
                ogs_time_from_sec(client->heart_beat_timer);
        smf_timer_cfg(SMF_TIMER_SBI_NO_HEARTBEAT)->duration =
            smf_timer_cfg(SMF_TIMER_SBI_HEARTBEAT)->duration *
                OGS_SBI_HEARTBEAT_RETRYCOUNT;

        /* check whether Heartbeat is enabled or not */
        if (smf_timer_cfg(SMF_TIMER_SBI_HEARTBEAT)->duration)
            ogs_timer_start(client->t_heartbeat,
                    smf_timer_cfg(SMF_TIMER_SBI_HEARTBEAT)->duration);
        if (smf_timer_cfg(SMF_TIMER_SBI_NO_HEARTBEAT)->duration)
            ogs_timer_start(client->t_no_heartbeat,
                smf_timer_cfg(SMF_TIMER_SBI_NO_HEARTBEAT)->duration);

        smf_sbi_send_nf_status_subscribe(client);
        break;

    case OGS_FSM_EXIT_SIG:
        ogs_info("NF de-registered [%s]", ogs_sbi_self()->nf_instance_id);

        ogs_timer_stop(client->t_heartbeat);
        ogs_timer_stop(client->t_no_heartbeat);
        break;

    case SMF_EVT_SBI_CLIENT:
        message = e->sbi.message;
        ogs_assert(message);

        SWITCH(message->h.api.name)
        CASE(OGS_SBI_API_NAME_NRF_NFM)

            SWITCH(message->h.resource.name)
            CASE(OGS_SBI_RESOURCE_NAME_NF_INSTANCES)

                if (message->res_status == OGS_SBI_HTTP_STATUS_NO_CONTENT ||
                    message->res_status == OGS_SBI_HTTP_STATUS_OK) {
                    if (smf_timer_cfg(SMF_TIMER_SBI_NO_HEARTBEAT)->duration)
                        ogs_timer_start(client->t_no_heartbeat,
                            smf_timer_cfg(
                                SMF_TIMER_SBI_NO_HEARTBEAT)->duration);
                } else {
                    ogs_error("HTTP response error : %d", message->res_status);
                }

                break;

            CASE(OGS_SBI_RESOURCE_NAME_SUBSCRIPTIONS)
                if (message->res_status == OGS_SBI_HTTP_STATUS_CREATED ||
                    message->res_status == OGS_SBI_HTTP_STATUS_OK) {
                    /* Nothing */
                } else {
                    ogs_error("HTTP response error : %d", message->res_status);
                }
                break;

            DEFAULT
                ogs_error("Invalid resource name [%s]",
                        message->h.resource.name);
            END
            break;

        DEFAULT
            ogs_error("Invalid API name [%s]", message->h.api.name);
        END
        break;

    case SMF_EVT_SBI_TIMER:
        switch(e->timer_id) {
        case SMF_TIMER_SBI_HEARTBEAT:
            if (smf_timer_cfg(SMF_TIMER_SBI_HEARTBEAT)->duration)
                ogs_timer_start(client->t_heartbeat,
                        smf_timer_cfg(SMF_TIMER_SBI_HEARTBEAT)->duration);

            smf_sbi_send_nf_update(client);
            break;

        case SMF_TIMER_SBI_NO_HEARTBEAT:
            OGS_FSM_TRAN(s, &smf_nf_state_will_register);
            break;
        default:
            ogs_error("Unknown timer[%s:%d]",
                    smf_timer_get_name(e->timer_id), e->timer_id);
            break;
        }
        break;

    default:
        ogs_error("Unknown event %s", smf_event_get_name(e));
        break;
    }
}

void smf_nf_state_exception(ogs_fsm_t *s, smf_event_t *e)
{
    char buf[OGS_ADDRSTRLEN];

    ogs_sbi_client_t *client = NULL;
    ogs_sockaddr_t *addr = NULL;
    ogs_assert(s);
    ogs_assert(e);

    smf_sm_debug(e);

    client = e->sbi.data;
    ogs_assert(client);

    switch (e->id) {
    case OGS_FSM_ENTRY_SIG:
        ogs_timer_start(client->t_registration,
                smf_timer_cfg(SMF_TIMER_SBI_REGISTRATION)->duration);
        break;

    case OGS_FSM_EXIT_SIG:
        ogs_timer_stop(client->t_registration);
        break;

    case SMF_EVT_SBI_TIMER:
        switch(e->timer_id) {
        case SMF_TIMER_SBI_REGISTRATION:
            addr = client->addr;
            ogs_assert(addr);

            ogs_warn("Retry to registration with NRF [%s]:%d",
                        OGS_ADDR(addr, buf), OGS_PORT(addr));

            OGS_FSM_TRAN(s, &smf_nf_state_will_register);
            break;

        default:
            ogs_error("Unknown timer[%s:%d]",
                    smf_timer_get_name(e->timer_id), e->timer_id);
            break;
        }
        break;

    default:
        ogs_error("Unknown event %s", smf_event_get_name(e));
        break;
    }
}
