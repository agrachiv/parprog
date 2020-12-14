#include <omp.h>
#include <stdio.h>
#include <math.h>

const int CROSSED_NUMBER = -1; //Required for the Sieve of Eratosthenes algorithm

int main(int argc, char** argv)
{
    int calculation_limit = atoi(argv[1]);
    int a[10000];
    for ( int i = 1; i < calculation_limit; i++)
        a[i] = i;

    for ( int current_prime = 2; current_prime < calculation_limit; current_prime++)
    {
        if ( a[current_prime] != CROSSED_NUMBER)
        {
            #pragma omp parallel  //parallelize our algorithm
            {
                int i;
                #pragma omp for
                for ( i = 2 * current_prime; i < calculation_limit; i += current_prime )
                    a[i] = CROSSED_NUMBER;
            }
        }
    }

    printf( "Prime numbers less than %d:\n", calculation_limit);
    for ( int i = 1; i < calculation_limit; i++)
        if ( a[i] != CROSSED_NUMBER)
            printf( "%d ", i);
    printf( "\n");
    return 0;
}

