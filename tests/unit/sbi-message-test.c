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

#include "test-app.h"

#include "sbi/model/nf_profile.h"

static void sbi_message_test1(abts_case *tc, void *data)
{
	nf_profile_t nf_profile1;
	nf_profile_t *nf_profile2 = NULL;
	cJSON *item = NULL;

	memset(&nf_profile1, 0, sizeof(nf_profile1));
	nf_profile1.nf_instance_id = "NF_INSTANCE_ID";
	nf_profile1.nf_type = "SMF";
	nf_profile1.nf_status = "REGISTERD";

	item = nf_profile_convertToJSON(&nf_profile1);
    ABTS_PTR_NOTNULL(tc, item);

    ABTS_PTR_EQUAL(tc, NULL, nf_profile2);
	nf_profile2 = nf_profile_parseFromJSON(item);
    ABTS_PTR_NOTNULL(tc, nf_profile2);

    cJSON_Delete(item);

    ABTS_STR_EQUAL(tc, nf_profile1.nf_instance_id, nf_profile2->nf_instance_id);
    ABTS_STR_EQUAL(tc, nf_profile1.nf_type, nf_profile2->nf_type);
    ABTS_STR_EQUAL(tc, nf_profile1.nf_status, nf_profile2->nf_status);

	nf_profile_free(nf_profile2);
}

abts_suite *test_sbi_message(abts_suite *suite)
{
    suite = ADD_SUITE(suite)

    abts_run_test(suite, sbi_message_test1, NULL);

    return suite;
}
