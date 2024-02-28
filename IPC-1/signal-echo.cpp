#include <iostream>
#include <sys/types.h>
#include <pwd.h>
#include <signal.h>
#include <ucontext.h>
#include <unistd.h>
#include <csignal>
#include <string.h>
#include <errno.h>

void printUserInfo(uid_t pid) {
    struct passwd* userInfo = getpwuid(pid);

    if(userInfo != NULL) {
        std::cout << "PID: " << pid << std::endl;
    } else {
        std::cout << "User information is NOT available." << std::endl;
    }
}

void sigusr1Handler(int signum, siginfo_t* info, void* context) {

    pid_t PID = info->si_pid;
    uid_t UID = info->si_uid;
    
    printUserInfo(UID);

    ucontext_t* ucontext = (ucontext_t*)context;
    unsigned long EIP = ucontext->uc_mcontext.gregs[REG_RIP];
    unsigned long EAX = ucontext->uc_mcontext.gregs[REG_RAX];
    unsigned long EBX = ucontext->uc_mcontext.gregs[REG_RBX];

    std::cout << "Received a SIGUSR1 signal from process [" << PID << "]" << "executed by [" << UID << "]" << std::endl;
    std::cout << "State of the context: EIP = " << "[" << EIP << "], " << "EAX = [" << EAX << "], " << "EBX = [" << EBX << "]." << std::endl; 
}


int main() {
    std::cout << "PID is: " << getpid() << std::endl;

    struct sigaction sigact;
    sigact.sa_flags = SA_SIGINFO;
    sigact.sa_sigaction = sigusr1Handler;

    int sigusrResult = sigaction(SIGUSR1, &sigact, NULL);

    if(sigusrResult == -1) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }

    while(true) {
        sleep(1);
    }

    return 0;
}