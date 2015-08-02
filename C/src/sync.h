#ifndef __MONGOLITE_SYNC_H__
#define __MONGOLITE_SYNC_H__

void mongolite_lock_shared(int fd);
void mongolite_lock_exclusive(int fd);
void mongolite_lock_remove(int fd);

#endif
