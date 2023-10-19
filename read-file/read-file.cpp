#include <iostream>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>

#define buffer_size 32

int main(int arg, char* argc[]) {
  if(arg < 2) {
    std::cerr << "Error:File name not provided\n";
    exit(1);
  }

  int fd = open(argc[1], O_RDONLY);
  
  if(fd == -1) {
    std::cerr << "Error:Something went wrong\n" << errno << strerror(errno) << std::endl;
    exit(errno);
  }

  char* buffer = new char[buffer_size + 1];
  while(true) {
    int r_bytes = read(fd, buffer, buffer_size);

    if(r_bytes == -1) {
      std::cerr << "Error:Something went wrong\n" << strerror(errno) << std::endl;
      exit(errno);
    }

    if(r_bytes == 0) {
      break;
    }

    buffer[r_bytes] = '\0';
    std::cout << buffer << std::endl;
  }

  close(fd);
  delete[] buffer;
  return 0;
}

