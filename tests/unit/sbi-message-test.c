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

#include "ogs-sbi.h"

static void sbi_message_test1(abts_case *tc, void *data)
{
	cJSON *item = NULL;
    listEntry_t *entry;

	nf_profile_t *nf_profile1;
	nf_profile_t *nf_profile2;

    udr_info_t *udr_info1;
    udr_info_t *udr_info2;

    identity_range_t *identity_range1;
    identity_range_t *identity_range2;

    plmn_id_t plmn_id1[3];
    plmn_id_t *plmn_id2;

    char *nsi;

    nf_profile1 = ogs_calloc(1, sizeof(*nf_profile1));
    ABTS_PTR_NOTNULL(tc, nf_profile1);
	nf_profile1->nf_instance_id = "NF_INSTANCE_ID";
	nf_profile1->nf_type = nf_type_SMF;
	nf_profile1->nf_status = nf_status_REGISTERED;

    memset(plmn_id1, 0, sizeof(plmn_id1));

    nf_profile1->plmn_list = list_create();
    ABTS_PTR_NOTNULL(tc, nf_profile1->plmn_list);

    plmn_id1[0].mcc = "111";
    plmn_id1[0].mnc = "222";
    list_addElement(nf_profile1->plmn_list, &plmn_id1[0]);
    plmn_id1[1].mcc = "333";
    plmn_id1[1].mnc = "444";
    list_addElement(nf_profile1->plmn_list, &plmn_id1[1]);
    plmn_id1[2].mcc = "555";
    plmn_id1[2].mnc = "666";
    list_addElement(nf_profile1->plmn_list, &plmn_id1[2]);

    nf_profile1->nsi_list = list_create();
    list_addElement(nf_profile1->nsi_list, "aaa");
    list_addElement(nf_profile1->nsi_list, "bbbbb");

    nf_profile1->priority = 30;

    udr_info1 = nf_profile1->udr_info = ogs_calloc(1, sizeof(*udr_info1));
    ABTS_PTR_NOTNULL(tc, udr_info1);
    udr_info1->group_id = "group";

    udr_info1->supi_ranges = list_create();
    ABTS_PTR_NOTNULL(tc, udr_info1->supi_ranges);

    udr_info1->gpsi_ranges = list_create();
    ABTS_PTR_NOTNULL(tc, udr_info1->gpsi_ranges);

    identity_range1 = ogs_calloc(1, sizeof(*identity_range1));
    ABTS_PTR_NOTNULL(tc, identity_range1);
    identity_range1->start = "1";
    identity_range1->end = "9";
    list_addElement(udr_info1->gpsi_ranges, identity_range1);

	item = nf_profile_convertToJSON(nf_profile1);
    ABTS_PTR_NOTNULL(tc, item);

#if 0
    {
        char *str = cJSON_Print(item);
        printf("%s", str);
        ogs_free(str);
    }
#endif

	nf_profile2 = nf_profile_parseFromJSON(item);
    ABTS_PTR_NOTNULL(tc, nf_profile2);

    ABTS_STR_EQUAL(tc,
            nf_profile1->nf_instance_id, nf_profile2->nf_instance_id);
    ABTS_INT_EQUAL(tc, nf_profile1->nf_type, nf_profile2->nf_type);
    ABTS_INT_EQUAL(tc, nf_profile1->nf_status, nf_profile2->nf_status);

    ABTS_PTR_NOTNULL(tc, nf_profile2->plmn_list);

    entry = nf_profile2->plmn_list->firstEntry;
    ABTS_PTR_NOTNULL(tc, entry);
    plmn_id2 = entry->data;
    ABTS_PTR_NOTNULL(tc, plmn_id2);
    ABTS_STR_EQUAL(tc, "111", plmn_id2->mcc);
    ABTS_STR_EQUAL(tc, "222", plmn_id2->mnc);

    entry = entry->nextListEntry;
    ABTS_PTR_NOTNULL(tc, entry);
    plmn_id2 = entry->data;
    ABTS_PTR_NOTNULL(tc, plmn_id2);
    ABTS_STR_EQUAL(tc, "333", plmn_id2->mcc);
    ABTS_STR_EQUAL(tc, "444", plmn_id2->mnc);

    entry = entry->nextListEntry;
    ABTS_PTR_NOTNULL(tc, entry);
    plmn_id2 = entry->data;
    ABTS_PTR_NOTNULL(tc, plmn_id2);
    ABTS_STR_EQUAL(tc, "555", plmn_id2->mcc);
    ABTS_STR_EQUAL(tc, "666", plmn_id2->mnc);

    entry = entry->nextListEntry;
    ABTS_PTR_EQUAL(tc, NULL, entry);

    entry = nf_profile2->nsi_list->firstEntry;
    ABTS_PTR_NOTNULL(tc, entry);
    nsi = entry->data;
    ABTS_PTR_NOTNULL(tc, nsi);
    ABTS_STR_EQUAL(tc, "aaa", nsi);

    entry = entry->nextListEntry;
    ABTS_PTR_NOTNULL(tc, entry);
    nsi = entry->data;
    ABTS_PTR_NOTNULL(tc, nsi);
    ABTS_STR_EQUAL(tc, "bbbbb", nsi);

    ABTS_INT_EQUAL(tc, 30, nf_profile2->priority);

    udr_info2 = nf_profile2->udr_info;
    ABTS_PTR_NOTNULL(tc, udr_info2);
    ABTS_STR_EQUAL(tc, "group", udr_info2->group_id);

    ABTS_PTR_NOTNULL(tc, udr_info2->supi_ranges);
    ABTS_INT_EQUAL(tc, 0, udr_info2->supi_ranges->count);

    ABTS_PTR_NOTNULL(tc, udr_info2->gpsi_ranges);
    entry = udr_info2->gpsi_ranges->firstEntry;
    ABTS_PTR_NOTNULL(tc, entry);
    identity_range2 = entry->data;
    ABTS_PTR_NOTNULL(tc, identity_range2);
    ABTS_STR_EQUAL(tc, "1", identity_range2->start);
    ABTS_STR_EQUAL(tc, "9", identity_range2->end);

    ogs_free(identity_range1);

    list_free(udr_info1->gpsi_ranges);
    list_free(udr_info1->supi_ranges);
    ogs_free(udr_info1);

    list_free(nf_profile1->plmn_list);
    list_free(nf_profile1->nsi_list);
    ogs_free(nf_profile1);

    cJSON_Delete(item);

	nf_profile_free(nf_profile2);
}

static void sbi_message_test2(abts_case *tc, void *data)
{
	cJSON *item = NULL;
    listEntry_t *entry;

    nf_group_cond_t *nf_group_cond1;
    nf_group_cond_t *nf_group_cond2;

	smf_info_t *smf_info1;
	smf_info_t *smf_info2;
    access_type_e access_type;

    nf_group_cond1 = ogs_calloc(1, sizeof(*nf_group_cond1));
    ABTS_PTR_NOTNULL(tc, nf_group_cond1);
	nf_group_cond1->nf_type = nf_group_cond_NFTYPE_UDR;
	nf_group_cond1->nf_group_id = "group";

	item = nf_group_cond_convertToJSON(nf_group_cond1);
    ABTS_PTR_NOTNULL(tc, item);

    ogs_free(nf_group_cond1);

#if 0
    {
        char *str = cJSON_Print(item);
        printf("%s", str);
        ogs_free(str);
    }
#endif

	nf_group_cond2 = nf_group_cond_parseFromJSON(item);
    ABTS_PTR_NOTNULL(tc, nf_group_cond2);

    ABTS_STR_EQUAL(tc,
            nf_group_cond1->nf_group_id, nf_group_cond2->nf_group_id);
    ABTS_INT_EQUAL(tc, nf_group_cond_NFTYPE_UDR, nf_group_cond2->nf_type);

    cJSON_Delete(item);

    nf_group_cond_free(nf_group_cond2);

    smf_info1 = ogs_calloc(1, sizeof(*smf_info1));
    ABTS_PTR_NOTNULL(tc, smf_info1);
    smf_info1->s_nssai_smf_info_list = list_create();
	smf_info1->pgw_fqdn = "PGW_FQDN";
    smf_info1->access_type = list_create();
    ABTS_PTR_NOTNULL(tc, smf_info1->access_type);

    list_addElement(smf_info1->access_type,
            (void*)access_type_3GPP_ACCESS);
    list_addElement(smf_info1->access_type,
            (void*)access_type_NON_3GPP_ACCESS);
	item = smf_info_convertToJSON(smf_info1);
    ABTS_PTR_NOTNULL(tc, item);

#if 0
    {
        char *str = cJSON_Print(item);
        printf("%s", str);
        ogs_free(str);
    }
#endif

	smf_info2 = smf_info_parseFromJSON(item);
    ABTS_PTR_NOTNULL(tc, smf_info2);

    ABTS_STR_EQUAL(tc,
            smf_info1->pgw_fqdn, smf_info2->pgw_fqdn);
    ABTS_PTR_NOTNULL(tc, smf_info2->s_nssai_smf_info_list);
    ABTS_INT_EQUAL(tc, smf_info1->s_nssai_smf_info_list->count,
                        smf_info2->s_nssai_smf_info_list->count);
    ABTS_PTR_NOTNULL(tc, smf_info2->access_type);
    ABTS_INT_EQUAL(tc, smf_info1->access_type->count,
                        smf_info2->access_type->count);

    entry = smf_info2->access_type->firstEntry;
    ABTS_PTR_NOTNULL(tc, entry);
    access_type = (access_type_e)entry->data;
    ABTS_INT_EQUAL(tc, access_type_3GPP_ACCESS, access_type);

    entry = entry->nextListEntry;
    ABTS_PTR_NOTNULL(tc, entry);
    access_type = (access_type_e)entry->data;
    ABTS_INT_EQUAL(tc, access_type_NON_3GPP_ACCESS, access_type);

    list_free(smf_info1->s_nssai_smf_info_list);
    list_free(smf_info1->access_type);
    ogs_free(smf_info1);

    cJSON_Delete(item);

    smf_info_free(smf_info2);
}

static void sbi_message_test3(abts_case *tc, void *data)
{
	cJSON *item = NULL;
    listEntry_t *entry;

	nrf_info_t *nrf_info1;
	nrf_info_t *nrf_info2;

    keyValuePair_t *served_pcf_info1 = NULL;
    keyValuePair_t *served_pcf_info2 = NULL;
    pcf_info_t *pcf_info1;
    pcf_info_t *pcf_info2;

    pcf_info1 = ogs_calloc(1, sizeof(*pcf_info1));
    ABTS_PTR_NOTNULL(tc, pcf_info1);
    pcf_info1->group_id = "pcf_group_id";
    pcf_info2 = ogs_calloc(1, sizeof(*pcf_info2));
    ABTS_PTR_NOTNULL(tc, pcf_info2);
    pcf_info2->group_id = "pcf_group_id2";

    served_pcf_info1 = keyValuePair_create("nfInstanceId", pcf_info1);
    ABTS_PTR_NOTNULL(tc, served_pcf_info1);
    served_pcf_info2 = keyValuePair_create("nfInstanceId2", pcf_info2);
    ABTS_PTR_NOTNULL(tc, served_pcf_info2);

    nrf_info1 = ogs_calloc(1, sizeof(*nrf_info1));
    ABTS_PTR_NOTNULL(tc, nrf_info1);

    nrf_info1->served_pcf_info = list_create();
    ABTS_PTR_NOTNULL(tc, nrf_info1->served_pcf_info);
    list_addElement(nrf_info1->served_pcf_info, served_pcf_info1);
    list_addElement(nrf_info1->served_pcf_info, served_pcf_info2);

	item = nrf_info_convertToJSON(nrf_info1);
    ABTS_PTR_NOTNULL(tc, item);

#if 0
    {
        char *str = cJSON_Print(item);
        printf("%s", str);
        ogs_free(str);
    }
#endif

    keyValuePair_free(served_pcf_info1);
    keyValuePair_free(served_pcf_info2);
    ogs_free(pcf_info1);
    ogs_free(pcf_info2);
    list_free(nrf_info1->served_pcf_info);
    ogs_free(nrf_info1);

	nrf_info2 = nrf_info_parseFromJSON(item);
    ABTS_PTR_NOTNULL(tc, nrf_info2);

    ABTS_INT_EQUAL(tc, nrf_info1->served_pcf_info->count,
                        nrf_info2->served_pcf_info->count);

    entry = nrf_info2->served_pcf_info->firstEntry;
    ABTS_PTR_NOTNULL(tc, entry);
    served_pcf_info1 = entry->data;
    ABTS_PTR_NOTNULL(tc, served_pcf_info1);
    ABTS_STR_EQUAL(tc, served_pcf_info1->key, "nfInstanceId");
    pcf_info1 = served_pcf_info1->value;
    ABTS_PTR_NOTNULL(tc, pcf_info1);
    ABTS_STR_EQUAL(tc, pcf_info1->group_id, "pcf_group_id");

    entry = entry->nextListEntry;
    ABTS_PTR_NOTNULL(tc, entry);
    served_pcf_info1 = entry->data;
    ABTS_STR_EQUAL(tc, served_pcf_info1->key, "nfInstanceId2");
    pcf_info1 = served_pcf_info1->value;
    ABTS_PTR_NOTNULL(tc, pcf_info1);
    ABTS_STR_EQUAL(tc, pcf_info1->group_id, "pcf_group_id2");

    cJSON_Delete(item);
    nrf_info_free(nrf_info2);
}

abts_suite *test_sbi_message(abts_suite *suite)
{
    suite = ADD_SUITE(suite)

    abts_run_test(suite, sbi_message_test1, NULL);
    abts_run_test(suite, sbi_message_test2, NULL);
    abts_run_test(suite, sbi_message_test3, NULL);

    return suite;
}
