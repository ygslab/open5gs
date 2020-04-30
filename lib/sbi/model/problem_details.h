/*
 * problem_details.h
 *
 * 
 */

#ifndef _problem_details_H_
#define _problem_details_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct problem_details_t problem_details_t;

#include "invalid_param.h"



typedef struct problem_details_t {
    char *type; // string
    char *title; // string
    int status; //numeric
    char *detail; // string
    char *instance; // string
    char *cause; // string
    list_t *invalid_params; //nonprimitive container
    char *supported_features; // string

} problem_details_t;

problem_details_t *problem_details_create(
    char *type,
    char *title,
    int status,
    char *detail,
    char *instance,
    char *cause,
    list_t *invalid_params,
    char *supported_features
);

void problem_details_free(problem_details_t *problem_details);

problem_details_t *problem_details_parseFromJSON(cJSON *problem_detailsJSON);

cJSON *problem_details_convertToJSON(problem_details_t *problem_details);

#endif /* _problem_details_H_ */

