#include "shared_array.h"

int main() {
    const char* array_name = "/my_shared_array";
    const std::size_t array_size = 10;

    shared_array array(array_name, array_size);

    while (true) {
        sem_wait(array.semaphore); 

        // Writing to shared array
        for (int i = 0; i < array_size; ++i) {
            array[i] = i * 2;
        }

        sem_post(array.semaphore); 

        sleep(1); 
    }

    return 0;
}
