#ifndef _MONGOLITE_COLLECTION_H_
#define _MONGOLITE_COLLECTION_H_

#include "client.h"
typedef struct mongoc_collection_t mongoc_collection_t;

mongoc_collection_t * mongoc_client_get_collection(mongoc_client_t *client, const char * db, const char * collection);
void mongoc_collection_destroy(mongoc_collection_t * col);

#endif
