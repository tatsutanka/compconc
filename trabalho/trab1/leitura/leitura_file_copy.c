#include <stdio.h>

int readmatrix(size_t rows, size_t cols, int (*a)[cols], const char* filename)
{

    FILE *pf;
    pf = fopen (filename, "r");
    if (pf == NULL)
        return 0;

    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < cols; j++)
            fscanf(pf, "%d", a[i] + j);
    }


    fclose (pf); 
    return 1; 
}

int main(void)
{
    int matrix[5][5];

    readmatrix(5, 5, matrix, "bar.dat");

    for(size_t i = 0; i < 5; i++)
    {
        for(size_t j = 0; j < 5; j++)
            printf("%d ", matrix[i][j]);
        puts("");
    }

    return 0;
}
