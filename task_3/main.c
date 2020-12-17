#include <omp.h>
#include <stdio.h>

const int array_size = 100000;

long long calculate_average( long long num_1, long long num_2, long long num_3) { return num_1 * num_2 * num_3 / 3; }

int main()
{
	long long a[array_size];
	long long b[array_size];
	for (int i = 0; i < array_size; i++)
        a[i] = i;
	b[0] = 0; //No boundary conditions were specified in the task
	b[array_size - 1] = 0;
	#pragma omp parallel
	{
		#pragma omp for //Here things go parallel!
		for ( int i = 1; i < array_size - 1; i++)
            b[i] = calculate_average( a[i-1], a[i], a[i+1]);
	}
	for (int i = 100; i < array_size - 1; i+=5000)
        printf("b[%d] = %lld \n", i, b[i]);
}

