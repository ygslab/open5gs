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

#include "ogs-sbi.h"

#include "sbi-private.h"

char *ogs_sbi_uridup(ogs_sbi_client_t *client,
    const char *api_name, const char *api_version,
    const char *resource_name, const char *resource_id)
{
    char buf[OGS_ADDRSTRLEN];
    char url[OGS_HUGE_LEN];
    char *p, *last;

    ogs_assert(client);
    ogs_assert(api_name);
    ogs_assert(api_version);
    ogs_assert(resource_name);

    p = url;
    last = url + OGS_HUGE_LEN;

    /* HTTP scheme is selected based on TLS information */
    if (client->tls.key && client->tls.pem)
        p = ogs_slprintf(p, last, "https://");
    else
        p = ogs_slprintf(p, last, "http://");

    /* IP address */
    if (client->addr->ogs_sa_family == AF_INET6)
        p = ogs_slprintf(p, last, "[%s]", OGS_ADDR(client->addr, buf));
    else
        p = ogs_slprintf(p, last, "%s", OGS_ADDR(client->addr, buf));

    /* Port number */
    if (OGS_PORT(client->addr) != OGS_SBI_HTTP_PORT) {
        p = ogs_slprintf(p, last, ":%d", OGS_PORT(client->addr));
    }

    /* API */
    ogs_assert(api_name);
    p = ogs_slprintf(p, last, "/%s", api_name);
    ogs_assert(api_version);
    p = ogs_slprintf(p, last, "/%s", api_version);

    /* Resource */
    ogs_assert(resource_name);
    p = ogs_slprintf(p, last, "/%s", resource_name);
    if (resource_id)
        p = ogs_slprintf(p, last, "/%s", resource_id);

    return ogs_strdup(url);
}
