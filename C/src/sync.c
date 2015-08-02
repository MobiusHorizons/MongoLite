/* sync.c: This file contains all synchronization code for cross process locking */
#include "errors.h"
#include <sys/file.h>

void mongolite_lock_shared(int fd){
  //posix
  int err;
  if ((err = flock(fd, LOCK_SH)) != 0){
    mongolite_set_error("failed to get shared lock on fd: %d\nGot %d", fd, err);
  }
}

void mongolite_lock_exclusive(int fd){
  //posix
  int err;
  if ((err = flock(fd, LOCK_EX)) != 0 ){
    mongolite_set_error("failed to get exclusive lock on fd: %d\n Got %d", fd, err);
  }
}

void mongolite_lock_remove(int fd){
  // posix
  int err;
  if ((err = flock(fd, LOCK_UN)) != 0){
    mongolite_set_error("failed to release lock on fd: %d\n Got %d", fd, err);
  }
}
