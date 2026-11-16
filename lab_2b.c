#include <stdio.h>
#include <omp.h>

int main() {
    int data = 0, ready = 0;
    #pragma omp parallel num_threads(3) shared(data, ready)
    {
        int id = omp_get_thread_num();
        if (id == 0) {
            data = 10;                  // Producer adds 10
            #pragma omp atomic write
            ready = 1;
            printf("Producer added 10\n");
        } else {
            int flag = 0;
            while (!flag) {
                #pragma omp atomic read
                flag = ready;
            }
            #pragma omp critical
            {
                if (data >= 5) {
                    data -= 5;
                    printf("Consumer %d took 5, left %d\n", id, data);
                }
            }
        }
    }
    return 0;
}
