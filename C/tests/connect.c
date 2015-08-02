#include <mongolite.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void setup(){
  mongoc_init();
  system("rm -rf ./db/");
}

int main(){
  setup();
  // should be able to connect to a new database.
  mongoc_client_t * c1 = mongoc_client_new("./db/");
  assert(c1 != NULL);

  // should be able to connect to an existing database
  mongoc_client_t * c2 = mongoc_client_new("./db/");
  assert (c2 != NULL);


  // should be able to connect to a collection
  mongoc_collection_t * col1 = mongoc_client_get_collection(c1, "doesn't matter", "collection");

  mongoc_collection_destroy(col1);

  mongoc_client_destroy(c1);
  mongoc_client_destroy(c2);
}
