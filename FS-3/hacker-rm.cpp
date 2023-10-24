#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>

int main(int arg, char** argc) {
    if(arg < 2) {
        std::cerr << "File path is not provided" << std::endl;
        exit(1);
    }
    
    const char* path = argc[1];

    int fd = open(path, O_WRONLY);
    
    if(fd < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(1);
    }

    int buffer_size = 25;
    char* buffer = new char[buffer_size];
    for(int i = 0; i < buffer_size; ++i) {
        buffer[i] = '\0';
    }
    
    int return_value = unlink(path);

    if(return_value < 0) {
        std::cerr << strerror(errno) << std::endl;
    }

    delete[] buffer;
    return 0;
}