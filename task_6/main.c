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
        if ( a[current_prime] != CROSSED_NUMBER) //Since we crossed everything not prime we will get inside the loop at next prime number
        {
            #pragma omp parallel
            {
                int i;
                #pragma omp for //Here things go parallel!
                for ( i = 2 * current_prime; i < calculation_limit; i += current_prime ) //We just cross all numbers that are multiple of current_prime
                    a[i] = CROSSED_NUMBER;
            }
        }
    }

    int number_of_primes = 0;
    for ( int i = 2; i < calculation_limit; i++)
        if ( a[i] != CROSSED_NUMBER)
            number_of_primes++;
    printf( "There are %d prime numbers less or equal than %d:\n", number_of_primes, calculation_limit);
    return 0;
}

