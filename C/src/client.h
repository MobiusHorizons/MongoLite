#ifndef _MONGOLITE_CLIENT_H_
#define _MONGOLITE_CLIENT_H_

typedef struct mongoc_client_t mongoc_client_t;


mongoc_client_t * mongoc_client_new(const char * connectionString);


void mongoc_client_destroy(mongoc_client_t * client);

#endif
