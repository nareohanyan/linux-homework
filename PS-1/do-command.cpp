#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <ctime>

void do_command(char** argv) {
    time_t beginning = time(nullptr);

    int pid = fork();
        
    if(pid < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }

    if(pid == 0) {
        execvp(argv[0], argv); 
    } else {
        int status;
        waitpid(pid, &status ,0);

        time_t end = time(nullptr);
        double duration = difftime(end, beginning);

        std::cout << "Command completed with " << WEXITSTATUS(status) << " exit code" << " and took " << duration << " seconds" << std::endl;
    }
}


int main(int argc, char** argv) {
    
    //if argc is less than 2, means there are not given command name and argument
    if(argc < 2) {
        std::cerr << "The program is not provided with the expected number of command line arguments!" << std::endl;
        exit(errno);
    }

    do_command(argv + 1);
    return 0;
}