#include "shared_array.h"

shared_array::shared_array(const char* _array_name, std::size_t _size) :
    array_name(_array_name), size(_size) {

  shmid = shm_open(array_name, O_CREAT | O_RDWR, 0666);

  if(shmid == -1) {
    std::cerr << "Error creating shared memory" << std::endl;
    exit(1);
  }

  int ftrunc = ftruncate(shmid, size * sizeof(int));
  if(ftrunc == -1){
    std::cerr << strerror(errno) << std::endl;
    exit(errno);
  }

  
  void* mapResult = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);

  if(data == MAP_FAILED) {
    std::cerr << "Error mapping shared memory" << std::endl;
    exit(1);
  }

  data = static_cast<int*>(mapResult);

  semaphore = sem_open(array_name, O_CREAT, 0666, 1);

  if (semaphore == SEM_FAILED) {
      std::cerr << "Error creating semaphore" << std::endl;
      exit(1);
  }
}

shared_array::~shared_array() {
  close(shmid);
  shm_unlink(array_name);
  sem_close(semaphore);
  sem_unlink(array_name);
}

int &shared_array::operator[](int index) {
  return data[index];
}
