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

#include "ogs-dbi.h"
#include "context.h"

static nrf_context_t self;

int __nrf_log_domain;

static OGS_POOL(nrf_nf_instance_pool, nrf_nf_instance_t);
static OGS_POOL(nrf_subscription_pool, nrf_subscription_t);

static int context_initialized = 0;

void nrf_context_init(void)
{
    ogs_assert(context_initialized == 0);

    /* Initialize NRF context */
    memset(&self, 0, sizeof(nrf_context_t));

    ogs_log_install_domain(&__ogs_dbi_domain, "dbi", ogs_core()->log.level);
    ogs_log_install_domain(&__nrf_log_domain, "nrf", ogs_core()->log.level);

    ogs_list_init(&nrf_self()->nf_instance_list);
    ogs_pool_init(&nrf_nf_instance_pool, ogs_config()->pool.sbi);

#define MAX_NUM_OF_SUBSCRIPTION 32
    ogs_list_init(&nrf_self()->subscription_list);
    ogs_pool_init(&nrf_subscription_pool, MAX_NUM_OF_SUBSCRIPTION);

    context_initialized = 1;
}

void nrf_context_final(void)
{
    ogs_assert(context_initialized == 1);

    nrf_subscription_remove_all();
    ogs_pool_final(&nrf_subscription_pool);

    nrf_nf_instance_remove_all();
    ogs_pool_final(&nrf_nf_instance_pool);

    context_initialized = 0;
}

nrf_context_t *nrf_self(void)
{
    return &self;
}

static int nrf_context_prepare(void)
{
    return OGS_OK;
}

static int nrf_context_validation(void)
{
    return OGS_OK;
}

int nrf_context_parse_config(void)
{
    int rv;

    rv = nrf_context_prepare();
    if (rv != OGS_OK) return rv;

    rv = nrf_context_validation();
    if (rv != OGS_OK) return rv;

    return OGS_OK;
}

nrf_nf_instance_t *nrf_nf_instance_add(char *id)
{
    nrf_nf_instance_t *nf_instance = NULL;
    nrf_event_t e;

    ogs_assert(id);

    ogs_pool_alloc(&nrf_nf_instance_pool, &nf_instance);
    ogs_assert(nf_instance);
    memset(nf_instance, 0, sizeof(nrf_nf_instance_t));

    nf_instance->id = ogs_strdup(id);
    ogs_assert(nf_instance->id);

    e.nf_instance = nf_instance;
    ogs_fsm_create(&nf_instance->sm, nrf_nf_state_initial, nrf_nf_state_final);
    ogs_fsm_init(&nf_instance->sm, &e);

    ogs_list_add(&nrf_self()->nf_instance_list, nf_instance);

    return nf_instance;
}

nrf_nf_instance_t *nrf_nf_instance_find(char *id)
{
    nrf_nf_instance_t *nf_instance = NULL;

    ogs_assert(id);

    ogs_list_for_each(&nrf_self()->nf_instance_list, nf_instance) {
        if (strcmp(nf_instance->id, id) == 0)
            break;
    }

    return nf_instance;
}

void nrf_nf_instance_clear(nrf_nf_instance_t *nf_instance)
{
    ogs_sbi_lnode_t *node;

    ogs_assert(nf_instance);

    if (nf_instance->ipv4_addresses) {
        ogs_sbi_list_for_each(nf_instance->ipv4_addresses, node)
            ogs_free(node->data);
        ogs_sbi_list_free(nf_instance->ipv4_addresses);
    }
    if (nf_instance->ipv6_addresses) {
        ogs_sbi_list_for_each(nf_instance->ipv6_addresses, node)
            ogs_free(node->data);
        ogs_sbi_list_free(nf_instance->ipv6_addresses);
    }
}

void nrf_nf_instance_remove(nrf_nf_instance_t *nf_instance)
{
    nrf_event_t e;

    ogs_assert(nf_instance);

    ogs_list_remove(&nrf_self()->nf_instance_list, nf_instance);

    e.nf_instance = nf_instance;
    ogs_fsm_fini(&nf_instance->sm, &e);
    ogs_fsm_delete(&nf_instance->sm);

    ogs_assert(nf_instance->id);
    ogs_free(nf_instance->id);

    nrf_nf_instance_clear(nf_instance);

    ogs_pool_free(&nrf_nf_instance_pool, nf_instance);
}

void nrf_nf_instance_remove_all(void)
{
    nrf_nf_instance_t *nf_instance = NULL, *next_nf_instance = NULL;

    ogs_list_for_each_safe(
            &nrf_self()->nf_instance_list, next_nf_instance, nf_instance)
        nrf_nf_instance_remove(nf_instance);
}

nrf_subscription_t *nrf_subscription_add(char *id)
{
    nrf_subscription_t *subscription = NULL;

    ogs_assert(id);

    ogs_pool_alloc(&nrf_subscription_pool, &subscription);
    ogs_assert(subscription);
    memset(subscription, 0, sizeof(nrf_subscription_t));

    subscription->id = ogs_strdup(id);
    ogs_assert(subscription->id);

    ogs_list_add(&nrf_self()->subscription_list, subscription);

    return subscription;
}

nrf_subscription_t *nrf_subscription_find(char *id)
{
    nrf_subscription_t *subscription = NULL;

    ogs_assert(id);

    ogs_list_for_each(&nrf_self()->subscription_list, subscription) {
        if (strcmp(subscription->id, id) == 0)
            break;
    }

    return subscription;
}

void nrf_subscription_clear(nrf_subscription_t *subscription)
{
    ogs_assert(subscription);
}

void nrf_subscription_remove(nrf_subscription_t *subscription)
{
    ogs_assert(subscription);

    ogs_list_remove(&nrf_self()->subscription_list, subscription);

    ogs_assert(subscription->id);
    ogs_free(subscription->id);

    nrf_subscription_clear(subscription);

    ogs_pool_free(&nrf_subscription_pool, subscription);
}

void nrf_subscription_remove_all(void)
{
    nrf_subscription_t *subscription = NULL, *next_subscription = NULL;

    ogs_list_for_each_safe(
            &nrf_self()->subscription_list, next_subscription, subscription)
        nrf_subscription_remove(subscription);
}
