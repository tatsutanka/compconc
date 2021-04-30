#include <stdio.h>
#include <stdlib.h>


#define SQR(x) ((x)*(x))

int laplace_det(int matrix_size, const int (*mat)[][matrix_size], int *is_valid) {
    // base cases
    if(matrix_size == 1) 
        return (*mat)[0][0];

    if(matrix_size == 2)
        return (*mat)[0][0] * (*mat)[1][1] - (*mat)[1][0] * (*mat)[0][1];

    // recusive case, matrix_size > 2
    // expansion indiscriminately along the first row
    //
    //   minor  matrix with i-th row and j-th column
    //          removed for the purpose of calculating
    //          the minor.
    //   r, c   row and column index variables
    //   col    current column in expansion
    //   d      determinant accumulator
    //
    int r, c, col, d = 0;
    int (*minor)[matrix_size-1][matrix_size-1] = calloc(SQR(matrix_size-1), sizeof(int));

    if(!minor) {
        *is_valid = 0;
        return 0;
    }

    // expand along first row
    for(col = 0; col < matrix_size; col++) {
        // copy into minor matrix, left side then right side
        for(r = 1; r < matrix_size; r++) {
            for(c = 0; c < col; c++) {
                (*minor)[r-1][c] = (*mat)[r][c];
            }
            for(c = col+1; c < matrix_size; c++) {
                (*minor)[r-1][c-1] = (*mat)[r][c];
            }
        }

        // calculate minor
        int temp_d = laplace_det(matrix_size-1, minor, is_valid);
        if(!is_valid) {
            free(minor);
            return 0;
        }

        d += (col & 1 ? -1 : 1) * (*mat)[0][col] * temp_d;
    }

    // free resources
    free(minor);
    return d;
}

int main(void) {
    int is_valid = 1;
   // int matrix[3][3] = {
   //     {1, 2, 3},
   //     {4, 5, 6},
   //     {7, 8, 9}
   // };
    int size = 3;
    int *matrix;
    matrix = (int*)malloc(sizeof(int)*SQR(size));
    int det_m = laplace_det(size, &matrix, &is_valid);

    if(is_valid) {
        printf("determinant %d\n", det_m);
    }
}
