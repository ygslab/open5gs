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

#ifndef NRF_CONTEXT_H
#define NRF_CONTEXT_H

#include "ogs-app.h"
#include "ogs-sbi.h"

#include "nrf-sm.h"
#include "timer.h"

#ifdef __cplusplus
extern "C" {
#endif

extern int __nrf_log_domain;

#undef OGS_LOG_DOMAIN
#define OGS_LOG_DOMAIN __nrf_log_domain

typedef struct nrf_context_s {
    ogs_queue_t     *queue;         /* Queue for processing UPF control */
    ogs_timer_mgr_t *timer_mgr;     /* Timer Manager */
    ogs_pollset_t   *pollset;       /* Poll Set for I/O Multiplexing */

    ogs_list_t      nf_instance_list;
    ogs_list_t      subscription_list;
} nrf_context_t;

typedef struct nrf_nf_instance_s {
    ogs_lnode_t     lnode;

    ogs_fsm_t       sm;                 /* A state machine */
    ogs_timer_t     *t_no_heartbeat;    /* check NF aliveness */

    char *id;                           /* NFInstanceId */

    ogs_sbi_nf_type_e nf_type;
    ogs_sbi_nf_status_e nf_status;
    int heart_beat_timer;

    char fqdn[OGS_MAX_FQDN_LEN];
    ogs_sbi_list_t *ipv4_addresses;
    ogs_sbi_list_t *ipv6_addresses;
} nrf_nf_instance_t;

typedef struct nrf_subscription_s {
    ogs_lnode_t     lnode;

    char *id;                           /* NFInstanceId */

    ogs_sbi_nf_type_e nf_type;
    ogs_sbi_nf_status_e nf_status;
} nrf_subscription_t;

void nrf_context_init(void);
void nrf_context_final(void);
nrf_context_t *nrf_self(void);

int nrf_context_parse_config(void);

nrf_nf_instance_t *nrf_nf_instance_add(char *id);
nrf_nf_instance_t *nrf_nf_instance_find(char *id);
void nrf_nf_instance_clear(nrf_nf_instance_t *nf_instance);
void nrf_nf_instance_remove(nrf_nf_instance_t *nf_instance);
void nrf_nf_instance_remove_all(void);

nrf_subscription_t *nrf_subscription_add(char *id);
nrf_subscription_t *nrf_subscription_find(char *id);
void nrf_subscription_clear(nrf_subscription_t *subscription);
void nrf_subscription_remove(nrf_subscription_t *subscription);
void nrf_subscription_remove_all(void);

#ifdef __cplusplus
}
#endif

#endif /* NRF_CONTEXT_H */
