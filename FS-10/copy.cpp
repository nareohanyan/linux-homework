#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#define BUFFER_SIZE 13653

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "File paths are not provided" << std::endl;
    }

    const char* sourceFile = argv[1];
    const char* destFile = argv[2];

    int sourceDescr = open(sourceFile, O_RDONLY);

    if (sourceDescr < 0) {
        std::cerr << "Error opening source file: " << strerror(errno) << std::endl;
        exit(errno);
    }

    int destDescr = open(destFile, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IRGRP | S_IROTH      | S_IWUSR);

    if (destDescr < 0) {
        std::cerr << "Error opening destination file: " << strerror(errno) << std::endl;
        exit(errno);
    }

    char buffer[BUFFER_SIZE];

    std::size_t readBytes = 0;
    std::size_t totalBytes = 0;
    std::size_t holeBytes = 0;
    std::size_t dataBytes = 0;
    std::size_t writtenBytes;

    do {
        readBytes = read(sourceDescr, buffer, BUFFER_SIZE);
        if (readBytes < 0) {
            std::cerr << "Error reading source file: " << strerror(errno) << std::endl;
            exit(errno);
        }

        if(readBytes > 0) {
            writtenBytes = write(destDescr, buffer, readBytes);
            if(writtenBytes < 0) {
                std::cerr << "Error writing to destination file: " << strerror(errno) <<                      std::endl;
                exit(errno);
            }
            totalBytes += readBytes;
            dataBytes += writtenBytes;
        } else {
            
            // Check if a hole is encountered (readBytes == 0)
            lseek(destDescr, readBytes, SEEK_CUR);
            holeBytes += readBytes;
        }

    } while(readBytes > 0);

    if(readBytes < 0) {
        std::cerr << "Error reading source file: " << strerror(errno) << std::endl;
        exit(errno);
    }

    int closeSource = close(sourceDescr);
    if(closeSource < 0) {
        std::cerr << "Error closing source file: " << strerror(errno) << std::endl;
    }

    int closeDest = close(destDescr);
    if(closeDest < 0) {
        std::cerr << "Error closing destination file: " << strerror(errno) << std::endl;
    }

    std::cout << "File copy completed." << std::endl;
    std::cout << "Total bytes copied: " << totalBytes << std::endl;
    std::cout << "Data bytes copied: " << dataBytes << std::endl;
    std::cout << "Hole bytes copied: " << holeBytes << std::endl;

    return 0;
}
