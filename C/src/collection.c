#include "collection.h"
#include "collection-private.h"
#include "client-private.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>


mongoc_collection_t * mongoc_client_get_collection(mongoc_client_t *client, const char * db, const char * collection){
  void * mem = malloc(sizeof(mongoc_collection_t) + strlen(client->path) + strlen(collection) + strlen(".bson") + 2);
  mongoc_collection_t * col = (mongoc_collection_t *) mem;
  col->path = (char * ) mem + sizeof(mongoc_collection_t);
  strcpy(col->path, client->path);
  strcat(col->path, "/");
  col->name = col->path + strlen(col->path);
  strcat(col->path, collection);
  strcat(col->path, ".bson");

  col->fd = open(col->path, O_RDWR | O_CREAT);

  if (col->fd == -1){
    // something with errno
    free(col);
    return NULL;
  }
  return col;
}

void mongoc_collection_destroy(mongoc_collection_t * col){
  close(col->fd);
  free(col);
}
