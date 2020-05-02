
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nf_type.h"

char* nf_type_ToString(nf_type_e nf_type) {
    char *nf_typeArray[] =  { "NULL", "NRF", "UDM", "AMF", "SMF", "AUSF", "NEF", "PCF", "SMSF", "NSSF", "UDR", "LMF", "GMLC", "5G_EIR", "SEPP", "UPF", "N3IWF", "AF", "UDSF", "BSF", "CHF", "NWDAF" };
    return nf_typeArray[nf_type];
}

nf_type_e nf_type_FromString(char* nf_type) {
    int stringToReturn = 0;
    char *nf_typeArray[] =  { "NULL", "NRF", "UDM", "AMF", "SMF", "AUSF", "NEF", "PCF", "SMSF", "NSSF", "UDR", "LMF", "GMLC", "5G_EIR", "SEPP", "UPF", "N3IWF", "AF", "UDSF", "BSF", "CHF", "NWDAF" };
    size_t sizeofArray = sizeof(nf_typeArray) / sizeof(nf_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(nf_type, nf_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

