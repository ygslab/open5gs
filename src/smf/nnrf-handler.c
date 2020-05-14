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

void smf_nnrf_handle_nf_register(
        ogs_sbi_client_t *client, ogs_sbi_message_t *message)
{
    ogs_sbi_nf_profile_t *nf_profile = NULL;

    ogs_assert(client);
    ogs_assert(message);

    nf_profile = message->nf_profile;
    if (!nf_profile) {
        ogs_error("No NFProfile");
        return;
    }

    /* Update from NRF */
    client->heart_beat_timer = nf_profile->heart_beat_timer;
}
