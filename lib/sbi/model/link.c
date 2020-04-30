#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "link.h"



link_t *link_create(
    char *href
    ) {
    link_t *link_local_var = malloc(sizeof(link_t));
    if (!link_local_var) {
        return NULL;
    }
    link_local_var->href = href;

    return link_local_var;
}


void link_free(link_t *link) {
    if(NULL == link){
        return ;
    }
    listEntry_t *listEntry;
    free(link->href);
    free(link);
}

cJSON *link_convertToJSON(link_t *link) {
    cJSON *item = cJSON_CreateObject();

    // link->href
    if(link->href) { 
    if(cJSON_AddStringToObject(item, "href", link->href) == NULL) {
    goto fail; //String
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

link_t *link_parseFromJSON(cJSON *linkJSON){

    link_t *link_local_var = NULL;

    // link->href
    cJSON *href = cJSON_GetObjectItemCaseSensitive(linkJSON, "href");
    if (href) { 
    if(!cJSON_IsString(href))
    {
    goto end; //String
    }
    }


    link_local_var = link_create (
        href ? strdup(href->valuestring) : NULL
        );

    return link_local_var;
end:
    return NULL;

}
