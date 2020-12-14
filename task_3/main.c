#include <omp.h>
#include <stdio.h>

const int array_size = 100000;

double calculate_average( double num_1, double num_2, double num_3) { return num_1 / 3 + num_2 / 3 + num_3 / 3; }

int main()
{
	double a[array_size];
	double b[array_size];
	for (int i = 0; i < array_size; a[i] = i++);
	b[0] = 0; //No boundary conditions were specified in the task
	b[array_size - 1] = 0;
	#pragma omp parallel
	{
		#pragma omp for
		for ( int i = 1; i < array_size - 1; i++)
            b[i] = calculate_average( a[i-1], a[i], a[i+1]);
	}
	for (int i = 1; i < array_size - 1; i+=5000)
        printf("b[%d] = %d\n", i, b[i]);
}
	
