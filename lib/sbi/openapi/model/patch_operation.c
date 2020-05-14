
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_operation.h"

char* ogs_sbi_patch_operation_ToString(ogs_sbi_patch_operation_e patch_operation)
{
    const char *patch_operationArray[] =  { "NULL", "add", "copy", "move", "_remove", "replace", "test" };
    return (char *)patch_operationArray[patch_operation];
}

ogs_sbi_patch_operation_e ogs_sbi_patch_operation_FromString(char* patch_operation)
{
    int stringToReturn = 0;
    const char *patch_operationArray[] =  { "NULL", "add", "copy", "move", "_remove", "replace", "test" };
    size_t sizeofArray = sizeof(patch_operationArray) / sizeof(patch_operationArray[0]);
    while (stringToReturn < sizeofArray) {
        if (strcmp(patch_operation, patch_operationArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

