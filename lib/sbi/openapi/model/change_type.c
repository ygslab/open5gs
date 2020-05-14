
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "change_type.h"

char* ogs_sbi_change_type_ToString(ogs_sbi_change_type_e change_type)
{
    const char *change_typeArray[] =  { "NULL", "ADD", "MOVE", "_REMOVE", "REPLACE" };
    return (char *)change_typeArray[change_type];
}

ogs_sbi_change_type_e ogs_sbi_change_type_FromString(char* change_type)
{
    int stringToReturn = 0;
    const char *change_typeArray[] =  { "NULL", "ADD", "MOVE", "_REMOVE", "REPLACE" };
    size_t sizeofArray = sizeof(change_typeArray) / sizeof(change_typeArray[0]);
    while (stringToReturn < sizeofArray) {
        if (strcmp(change_type, change_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

