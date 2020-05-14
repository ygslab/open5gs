
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "notification_type.h"

char* ogs_sbi_notification_type_ToString(ogs_sbi_notification_type_e notification_type)
{
    const char *notification_typeArray[] =  { "NULL", "N1_MESSAGES", "N2_INFORMATION", "LOCATION_NOTIFICATION", "DATA_REMOVAL_NOTIFICATION", "DATA_CHANGE_NOTIFICATION" };
    return (char *)notification_typeArray[notification_type];
}

ogs_sbi_notification_type_e ogs_sbi_notification_type_FromString(char* notification_type)
{
    int stringToReturn = 0;
    const char *notification_typeArray[] =  { "NULL", "N1_MESSAGES", "N2_INFORMATION", "LOCATION_NOTIFICATION", "DATA_REMOVAL_NOTIFICATION", "DATA_CHANGE_NOTIFICATION" };
    size_t sizeofArray = sizeof(notification_typeArray) / sizeof(notification_typeArray[0]);
    while (stringToReturn < sizeofArray) {
        if (strcmp(notification_type, notification_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

