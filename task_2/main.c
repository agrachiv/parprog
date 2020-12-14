#include <omp.h>
#include <stdio.h>
int main( int argc, char **argv)
{
    int sum_limit = atoi(argv[1]);
    int global_sum = 0;
    #pragma omp parallel
    {
    	int local_sum = 0;
	    #pragma omp for //Here every thread gets it's own range of integers
		for ( int i = 1; i <= sum_limit; i++)
            local_sum += i;
		#pragma omp atomic //Atomic directive allows to write the value of a variable atomically
		global_sum += local_sum;
   	}
   	printf( "Sum of the first %d integers is %d\n", sum_limit, global_sum);
}
	
