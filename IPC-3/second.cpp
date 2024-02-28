#include "shared_array.h"

int main() {
    const char* array_name = "/my_shared_array";
    const std::size_t array_size = 10;

    shared_array array(array_name, array_size);

    while (true) {
        sem_wait(array.semaphore); 

        // Reading from shared array
        for (int i = 0; i < array_size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;

        sem_post(array.semaphore); 

        sleep(1); 
    }

    return 0;
}
