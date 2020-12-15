#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int main()
{
    int num;
    #pragma omp parallel shared(num)
    {
        num = omp_get_num_threads();
        for( int i = 0; i < num; i++)
        {
            #pragma omp barrier //Synchronization
            {
                if( i == omp_get_thread_num())
                {
                    #pragma omp critical //Indicates that code should only be executed on one thread at a time
                    printf("Hello world %d\n", i);
                }
            }
        }
    }
    return 0;
}
