
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "notification_event_type.h"

char* ogs_sbi_notification_event_type_ToString(ogs_sbi_notification_event_type_e notification_event_type)
{
    const char *notification_event_typeArray[] =  { "NULL", "NF_REGISTERED", "NF_DEREGISTERED", "NF_PROFILE_CHANGED" };
    return (char *)notification_event_typeArray[notification_event_type];
}

ogs_sbi_notification_event_type_e ogs_sbi_notification_event_type_FromString(char* notification_event_type)
{
    int stringToReturn = 0;
    const char *notification_event_typeArray[] =  { "NULL", "NF_REGISTERED", "NF_DEREGISTERED", "NF_PROFILE_CHANGED" };
    size_t sizeofArray = sizeof(notification_event_typeArray) / sizeof(notification_event_typeArray[0]);
    while (stringToReturn < sizeofArray) {
        if (strcmp(notification_event_type, notification_event_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

