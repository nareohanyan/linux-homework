#ifndef SHARED_ARRAY_H
#define SHARED_ARRAY_H

#include <iostream>
#include <sys/shm.h>
#include <cstring>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>

class shared_array {
private:
  const char* array_name;
  std::size_t size;
  int* data;
  int shmid;

public:
  sem_t* semaphore;

  shared_array(const char* _array_name, std::size_t _size);

  ~shared_array();

  int &operator[](int index);
};

#endif 
