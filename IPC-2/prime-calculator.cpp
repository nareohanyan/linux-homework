#include <iostream>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <cstring>


bool isPrime(int primeNum) {
    for(int i = 2; i <= primeNum / 2; ++i) {
        if(primeNum % i == 0) {
            return false;
        } 
    }
    return true;
}

int primeCalculator(int m) {
    int i = 2;
    while(m != 0) {
        if(isPrime(i)){
            --m;
        }
        ++i;
    }
    return i - 1;
}

int main(){


    int pipeFdParent[2];
    
    int pipeResultParent = pipe(pipeFdParent);
    if(pipeResultParent < 0) { 
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }
    
    int pipeFdChild[2];

    int pipeResultChild = pipe(pipeFdChild);
    if(pipeResultChild < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }

    int pid = fork();
    
    if(pid < 0){
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }

    if(pid > 0){
        close(pipeFdParent[0]);
        close(pipeFdChild[1]);

        while(true) {

            std::string M;
            std::cout << "Enter the number " << std::endl;
            std::cin >> M;
            
            if(M == "exit") {
                return 0;
            }

            int m = std::stoi(M);

            int writeResult = write(pipeFdParent[1], &m , sizeof(int));
            if(writeResult < 0){
                std::cerr << strerror(errno) << std::endl;
                exit(errno);
            }

            int outcome;

            int readResult = read(pipeFdChild[0], &outcome, sizeof(int));
            if(readResult < 0) {
                std::cerr << strerror(errno) << std::endl;
                exit(errno);
            }

            std::cout << m << "-th prime number is " << outcome << std::endl;
        }
    }

    if(pid == 0){
        while(true) {
            close(pipeFdParent[1]);
            close(pipeFdChild[0]);

            int m;

            int readResult = read(pipeFdParent[0], &m, sizeof(int));
            if(readResult < 0) {
                std::cerr << strerror(errno) << std::endl;
                exit(errno);
            }

            int outcome = primeCalculator(m);

            int writeResult = write(pipeFdChild[1], &outcome , sizeof(int));
            if(writeResult < 0){
                std::cerr << strerror(errno) << std::endl;
                exit(errno);
            }
            
        }
    }

    return 0;
}
