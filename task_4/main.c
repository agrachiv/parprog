#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int matrix_size = 4;

int** alocate_memory()
{
    int** alocated_memory = ( int**) calloc( matrix_size, sizeof(int*));
    for(int i = 0; i < matrix_size; i++)
        alocated_memory[i] = ( int*) calloc( matrix_size, sizeof(int));
    return alocated_memory;
}

void fill_with_random_integers( int** matrix)
{
    srand( time(NULL)); //That macro is required to make numbers random between launches
    for( int i = 0; i < matrix_size; i++)
        for( int j = 0; j < matrix_size; j++)
            matrix[i][j] = rand() % 10;
}

void print( int** matrix)
{
    printf( "-------------\n");
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    printf( "-------------\n");
}


int main()
{
    //Memory allocation
    int** matrix_a = alocate_memory();
    int** matrix_b = alocate_memory();
    int** matrix_c = alocate_memory();

    //Filling matrices with random values
    fill_with_random_integers( matrix_a);
    fill_with_random_integers( matrix_b);

    //Calculation product of the multiplication
    int i, j, k;
    #pragma omp parallel for private(i, j, k) //Here things go parallel!
    for (i = 0; i < matrix_size; i++)
        for (j = 0; j < matrix_size; j++)
            for (k = 0; k < matrix_size; k++)
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j]; //Cij = Ai1*B1j+Ai2*B2j...Aik*Bkj

    //Printing results
    printf( "Matrix A:\n");
    print( matrix_a);
    printf( "Matrix B:\n");
    print( matrix_b);
    printf( "Matrix C = A * B:\n");
    print( matrix_c);
}

