
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transport_protocol.h"

char* ogs_sbi_transport_protocol_ToString(ogs_sbi_transport_protocol_e transport_protocol)
{
    const char *transport_protocolArray[] =  { "NULL", "TCP" };
    return (char *)transport_protocolArray[transport_protocol];
}

ogs_sbi_transport_protocol_e ogs_sbi_transport_protocol_FromString(char* transport_protocol)
{
    int stringToReturn = 0;
    const char *transport_protocolArray[] =  { "NULL", "TCP" };
    size_t sizeofArray = sizeof(transport_protocolArray) / sizeof(transport_protocolArray[0]);
    while (stringToReturn < sizeofArray) {
        if (strcmp(transport_protocol, transport_protocolArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

