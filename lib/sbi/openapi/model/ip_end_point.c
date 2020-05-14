
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ip_end_point.h"

ogs_sbi_ip_end_point_t *ogs_sbi_ip_end_point_create(
    char *ipv4_address,
    char *ipv6_address,
    ogs_sbi_transport_protocol_e transport,
    int port
    )
{
    ogs_sbi_ip_end_point_t *ip_end_point_local_var = ogs_sbi_malloc(sizeof(ogs_sbi_ip_end_point_t));
    if (!ip_end_point_local_var) {
        return NULL;
    }
    ip_end_point_local_var->ipv4_address = ipv4_address;
    ip_end_point_local_var->ipv6_address = ipv6_address;
    ip_end_point_local_var->transport = transport;
    ip_end_point_local_var->port = port;

    return ip_end_point_local_var;
}

void ogs_sbi_ip_end_point_free(ogs_sbi_ip_end_point_t *ip_end_point)
{
    if (NULL == ip_end_point) {
        return;
    }
    ogs_sbi_lnode_t *node;
    ogs_free(ip_end_point->ipv4_address);
    ogs_free(ip_end_point->ipv6_address);
    ogs_free(ip_end_point);
}

cJSON *ogs_sbi_ip_end_point_convertToJSON(ogs_sbi_ip_end_point_t *ip_end_point)
{
    cJSON *item = cJSON_CreateObject();
    if (ip_end_point->ipv4_address) {
        if (cJSON_AddStringToObject(item, "ipv4Address", ip_end_point->ipv4_address) == NULL) {
            ogs_error("ogs_sbi_ip_end_point_convertToJSON() failed [ipv4_address]");
            goto end;
        }
    }

    if (ip_end_point->ipv6_address) {
        if (cJSON_AddStringToObject(item, "ipv6Address", ip_end_point->ipv6_address) == NULL) {
            ogs_error("ogs_sbi_ip_end_point_convertToJSON() failed [ipv6_address]");
            goto end;
        }
    }

    if (ip_end_point->transport) {
        if (cJSON_AddStringToObject(item, "transport", ogs_sbi_transport_protocol_ToString(ip_end_point->transport)) == NULL) {
            ogs_error("ogs_sbi_ip_end_point_convertToJSON() failed [transport]");
            goto end;
        }
    }

    if (ip_end_point->port) {
        if (cJSON_AddNumberToObject(item, "port", ip_end_point->port) == NULL) {
            ogs_error("ogs_sbi_ip_end_point_convertToJSON() failed [port]");
            goto end;
        }
    }

end:
    return item;
}

ogs_sbi_ip_end_point_t *ogs_sbi_ip_end_point_parseFromJSON(cJSON *ip_end_pointJSON)
{
    ogs_sbi_ip_end_point_t *ip_end_point_local_var = NULL;
    cJSON *ipv4_address = cJSON_GetObjectItemCaseSensitive(ip_end_pointJSON, "ipv4Address");

    if (ipv4_address) {
        if (!cJSON_IsString(ipv4_address)) {
            ogs_error("ogs_sbi_ip_end_point_parseFromJSON() failed [ipv4_address]");
            goto end;
        }
    }

    cJSON *ipv6_address = cJSON_GetObjectItemCaseSensitive(ip_end_pointJSON, "ipv6Address");

    if (ipv6_address) {
        if (!cJSON_IsString(ipv6_address)) {
            ogs_error("ogs_sbi_ip_end_point_parseFromJSON() failed [ipv6_address]");
            goto end;
        }
    }

    cJSON *transport = cJSON_GetObjectItemCaseSensitive(ip_end_pointJSON, "transport");

    ogs_sbi_transport_protocol_e transportVariable;
    if (transport) {
        if (!cJSON_IsString(transport)) {
            ogs_error("ogs_sbi_ip_end_point_parseFromJSON() failed [transport]");
            goto end;
        }
        transportVariable = ogs_sbi_transport_protocol_FromString(transport->valuestring);
    }

    cJSON *port = cJSON_GetObjectItemCaseSensitive(ip_end_pointJSON, "port");

    if (port) {
        if (!cJSON_IsNumber(port)) {
            ogs_error("ogs_sbi_ip_end_point_parseFromJSON() failed [port]");
            goto end;
        }
    }

    ip_end_point_local_var = ogs_sbi_ip_end_point_create (
        ipv4_address ? ogs_strdup(ipv4_address->valuestring) : NULL,
        ipv6_address ? ogs_strdup(ipv6_address->valuestring) : NULL,
        transport ? transportVariable : 0,
        port ? port->valuedouble : 0
        );

    return ip_end_point_local_var;
end:
    return NULL;
}

