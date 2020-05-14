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

#include "nnrf-build.h"

ogs_sbi_request_t *smf_nnrf_build_nf_register(ogs_sbi_client_t *client,
        ogs_sbi_nf_type_e nf_type, ogs_sbi_nf_status_e nf_status)
{
    ogs_sbi_request_t *request = NULL;
    ogs_sbi_nf_profile_t *nf_profile = NULL;
    ogs_sbi_server_t *server = NULL;

    ogs_sbi_list_t *ipv4_addresses;
    ogs_sbi_list_t *ipv6_addresses;
    ogs_sbi_lnode_t *node;

    char fqdn[OGS_MAX_FQDN_LEN+1];
    char *hostname = NULL;

    ogs_sbi_message_t message;

    ogs_assert(client);

    memset(&message, 0, sizeof(message));
    message.h.method = (char *)OGS_SBI_HTTP_METHOD_PUT;
    message.h.api.name = (char *)OGS_SBI_API_NAME_NRF_NFM;
    message.h.api.version = (char *)OGS_SBI_API_VERSION;
    message.h.resource.name = (char *)OGS_SBI_RESOURCE_NAME_NF_INSTANCES;
    message.h.resource.id = ogs_sbi_self()->nf_instance_id;

    message.http.content_encoding = (char*)ogs_sbi_self()->content_encoding;

    nf_profile = ogs_calloc(1, sizeof(*nf_profile));
    ogs_assert(nf_profile);

	nf_profile->nf_instance_id = ogs_sbi_self()->nf_instance_id;
	nf_profile->nf_type = nf_type;
	nf_profile->nf_status = nf_status;
    nf_profile->heart_beat_timer = client->heart_beat_timer;

    ipv4_addresses = ogs_sbi_list_create();
    ogs_assert(ipv4_addresses);
    ipv6_addresses = ogs_sbi_list_create();
    ogs_assert(ipv6_addresses);

    ogs_list_for_each(&ogs_sbi_self()->server_list, server) {
        ogs_sockaddr_t *addr = NULL;
        char *ipstr = NULL;

        addr = server->addr;
        ogs_assert(addr);

        /* First FQDN is selected */
        if (!hostname) {
            hostname = ogs_gethostname(addr);
            if (hostname)
                continue;
        }

        ipstr = ogs_ipstrdup(addr);

        if (addr->ogs_sa_family == AF_INET) {
            ogs_sbi_list_add(ipv4_addresses, ipstr);
        } else if (addr->ogs_sa_family == AF_INET6) {
            ogs_sbi_list_add(ipv6_addresses, ipstr);
        } else
            ogs_assert_if_reached();
    }

    if (hostname) {
        memset(fqdn, 0, sizeof(fqdn));
        ogs_fqdn_build(fqdn, hostname, strlen(hostname));
        nf_profile->fqdn = fqdn;
    }

    if (ipv4_addresses->count)
        nf_profile->ipv4_addresses = ipv4_addresses;
    if (ipv6_addresses->count)
        nf_profile->ipv6_addresses = ipv6_addresses;

    ogs_assert(nf_profile->fqdn ||
        (nf_profile->ipv4_addresses && nf_profile->ipv4_addresses->count) ||
        (nf_profile->ipv6_addresses && nf_profile->ipv6_addresses->count));

    message.nf_profile = nf_profile;

    request = ogs_sbi_build_request(&message);
    ogs_assert(request);

    ogs_sbi_list_for_each(ipv4_addresses, node)
        ogs_free(node->data);
    ogs_sbi_list_free(ipv4_addresses);
    ogs_sbi_list_for_each(ipv6_addresses, node)
        ogs_free(node->data);
    ogs_sbi_list_free(ipv6_addresses);
    ogs_free(nf_profile);

    return request;
}

ogs_sbi_request_t *smf_nnrf_build_nf_update(ogs_sbi_client_t *client)
{
    ogs_sbi_request_t *request = NULL;
    ogs_sbi_list_t *patch_list;
    ogs_sbi_patch_item_t item;

    ogs_sbi_message_t message;

    ogs_assert(client);

    memset(&message, 0, sizeof(message));
    message.h.method = (char *)OGS_SBI_HTTP_METHOD_PATCH;
    message.h.api.name = (char *)OGS_SBI_API_NAME_NRF_NFM;
    message.h.api.version = (char *)OGS_SBI_API_VERSION;
    message.h.resource.name = (char *)OGS_SBI_RESOURCE_NAME_NF_INSTANCES;
    message.h.resource.id = ogs_sbi_self()->nf_instance_id;
    message.http.content_type = (char *)OGS_SBI_CONTENT_PATCH_TYPE;

    patch_list = ogs_sbi_list_create();
    ogs_assert(patch_list);

    memset(&item, 0, sizeof(item));
    item.op = ogs_sbi_patch_operation_replace;
    item.path = (char *)"/nfStatus";
    item.value = ogs_sbi_nf_status_ToString(ogs_sbi_nf_status_REGISTERED);

    ogs_sbi_list_add(patch_list, &item);

    message.patch_list = patch_list;

    request = ogs_sbi_build_request(&message);
    ogs_assert(request);

    ogs_sbi_list_free(patch_list);

    return request;
}

ogs_sbi_request_t *smf_nnrf_build_nf_de_register(ogs_sbi_client_t *client)
{
    ogs_sbi_request_t *request = NULL;
    ogs_sbi_message_t message;

    ogs_assert(client);

    memset(&message, 0, sizeof(message));
    message.h.method = (char *)OGS_SBI_HTTP_METHOD_DELETE;
    message.h.api.name = (char *)OGS_SBI_API_NAME_NRF_NFM;
    message.h.api.version = (char *)OGS_SBI_API_VERSION;
    message.h.resource.name = (char *)OGS_SBI_RESOURCE_NAME_NF_INSTANCES;
    message.h.resource.id = ogs_sbi_self()->nf_instance_id;

    request = ogs_sbi_build_request(&message);
    ogs_assert(request);

    return request;
}

ogs_sbi_request_t *smf_nnrf_build_nf_status_subscribe(ogs_sbi_client_t *client)
{
    ogs_sbi_request_t *request = NULL;
    ogs_sbi_subscription_data_t *subscription_data = NULL;
    ogs_sbi_message_t message;

    ogs_assert(client);

    memset(&message, 0, sizeof(message));
    message.h.method = (char *)OGS_SBI_HTTP_METHOD_POST;
    message.h.api.name = (char *)OGS_SBI_API_NAME_NRF_NFM;
    message.h.api.version = (char *)OGS_SBI_API_VERSION;
    message.h.resource.name = (char *)OGS_SBI_RESOURCE_NAME_SUBSCRIPTIONS;

    subscription_data = ogs_calloc(1, sizeof(*subscription_data));
    ogs_assert(subscription_data);

	subscription_data->nf_status_notification_uri = ogs_sbi_uridup(client,
                OGS_SBI_API_NAME_NRF_NFM, OGS_SBI_API_VERSION,
                OGS_SBI_RESOURCE_NAME_NF_STATUS_NOTIFY, NULL);
    ogs_assert(subscription_data->nf_status_notification_uri);
	subscription_data->req_nf_instance_id = ogs_sbi_self()->nf_instance_id;

    message.subscription_data = subscription_data;

    request = ogs_sbi_build_request(&message);
    ogs_assert(request);

    ogs_free(subscription_data->nf_status_notification_uri);
    ogs_free(subscription_data);

    return request;
}
