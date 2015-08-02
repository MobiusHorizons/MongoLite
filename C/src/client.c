#include "client.h"
#include "errors.h"
#include "client-private.h"
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>


int mkpath(char* file_path, mode_t mode) {
    char* p;
    for (p=strchr(file_path+1, '/'); p; p=strchr(p+1, '/')) {
        *p='\0';

        if (mkdir(
            file_path
#ifndef WIN32
            ,mode
#endif
            )==-1) {
            if (errno!=EEXIST) { *p='/'; return -1; }
        }
        *p='/';
    }
    return 0;
}

mongoc_client_t * mongoc_client_new(const char * connectionString){
  DIR * dir = opendir(connectionString);
  if (dir == NULL){
    // create the directory.
    char * temp_path = strdup(connectionString);
    int err = mkpath(temp_path, 0777);
    free(temp_path);
    if (err){ // connection string probably malformed.
      mongolite_set_error("could not create '%s'.", connectionString);
      return NULL;
    }
    dir = opendir(connectionString);
    if (dir == NULL){// something is quite wrong
      return NULL;
    }
  }

  void* mem = malloc(sizeof(mongoc_client_t) + strlen(connectionString)+1);
  mongoc_client_t * client = (mongoc_client_t *) mem;
  char * cs = (char*)mem + sizeof(mongoc_client_t);
  strcpy(cs, connectionString);
  client->path = cs;
  client->dir = dir;
  return client;
}

void mongoc_client_destroy(mongoc_client_t * client){
  if (client){
    closedir(client->dir);
  }
  free(client);
}
