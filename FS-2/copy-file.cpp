#include <iostream>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main(int arg, char** argv) {
    
    if(arg < 3) {
        std::cerr << "Source and destination files are not provided" << std::endl;
        exit(1);
    }

    char* source_path = argv[1];

    int source_file = open(source_path, O_RDONLY);

    if(source_file < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }

    char* dest_path = argv[2];

    int dest_file = open(dest_path, O_CREAT | O_RDONLY | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if(dest_file == -1) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }

    long copied_bytes = 0;
    long read_bytes = 0;

    if(read_bytes == -1) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }    

    if(read_bytes == 0) {
        std::cout << "You've reached the end, there are no more bytes to read" << std::endl;
    }

    copied_bytes = read_bytes + copied_bytes;

    close(source_file);
    close(dest_file);
    
    return 0;
}