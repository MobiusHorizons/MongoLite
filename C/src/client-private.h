#include <dirent.h>

struct mongoc_client_t{
  char * path;
  DIR * dir;
};
