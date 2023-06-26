//************************************************************
// Navya Mishra
// nmishra3
// PA 4
//************************************************************


#include <stdio.h>
#include "Matrix.h"

int main (int argc, char* argv[]) {
    int n, i, nnza, nnzb, row, col;
    double val;
    FILE* in; 
    FILE* out; 
    Matrix A, B, C, D, E, F, G, H, I, J;

    // check command line for correct number of arguments
    if( argc != 3 ) {
	printf("Usage: %s <input file> <output file>\n", argv[0]);
	exit(1);
    }

    // open input file for reading
    in = fopen(argv[1], "r");
    if(!in) {
	printf("Unable to read from file %s\n", argv[1]);
	exit(1);
    }

    // open output file for writing
    out = fopen(argv[2], "w");
    if(!out) {
	printf("Unable to write to file %s\n", argv[2]);
	exit(1);
    }

    // scan and initialize Matrix 
    fscanf(in, " %d %d %d", &n, &nnza, &nnzb);

    // create two matrices A and B of size n
    A = newMatrix(n);
    B = newMatrix(n);

    // from 0 to nnza: 
    //      scan in the rows, columns and values
    //      assign them to matrix A
    for (i = 0; i<nnza; i++){
        fscanf(in, " %d %d %le", &row, &col, &val);
        changeEntry(A, row,col,val);
    }
    
    // from 0 to nnzb: 
    //      scan in the rows, columns and values
    //      assign them to matrix B
    for (i = 0; i<nnzb; i++){
        fscanf(in, " %d %d %le", &row, &col, &val);
        changeEntry(B, row,col,val);
    }

    fprintf(out, "A has %d non-zero entries:\n", NNZ(A));
    fprintf(stdout, "A has %d non-zero entries:\n", NNZ(A));//delete
    // print out the matrix
    printMatrix(out, A);
    printMatrix(stdout, A);

    fprintf(out, "\nB has %d non-zero entries:\n", NNZ(B));
    fprintf(stdout, "\nB has %d non-zero entries:\n", NNZ(B));
    // print out the matrix
    printMatrix(out, B);
    printMatrix(stdout, B);
    
    fprintf(out, "\n(1.5)*A =\n");
    fprintf(stdout, "\n(1.5)*A =\n");
    // C = multiply everything in A by 1.5
    C = scalarMult(1.5, A);
    // print out the matrix
    printMatrix(out, C);
    printMatrix(stdout, C);

    fprintf(out, "\nA+B =\n");
    fprintf(stdout, "\nA+B =\n");
    //D = sum of a and b
    D = sum(A,B);
    // print out the matrix
    printMatrix(out, D);
    printMatrix(stdout, D);

    fprintf(out, "\nA+A =\n");
    fprintf(stdout, "\nA+A =\n");
    // E = addition of A twice
    E = sum(A,A);
    // print out the matrix
    printMatrix(out, E);
    printMatrix(stdout, E);

    fprintf(out, "\nB-A =\n");
    fprintf(stdout, "\nB-A =\n");
    // F = subtraction of A from B;
    F = diff(B,A);
    // print out the matrix
    printMatrix(out, F);
    printMatrix(stdout, F);


    fprintf(out, "\nA-A = \n");
    fprintf(stdout, "\nA-A = \n");
    // G = subtraction of A from A (should be 0)
    G = diff(A,A);
    // print out the matrix
    //printMatrix(out, G);
    //printMatrix(stdout, G);


    fprintf(out, "\nTranspose(A) =\n");
    fprintf(stdout, "\nTranspose(A) =\n");
    // H = transpose of A
    H = transpose(A);
    // print out the matrix
    printMatrix(out, H);
    printMatrix(stdout, H);

    fprintf(out, "\nA*B =\n");
    fprintf(stdout, "\nA*B =\n");
    // I = product of the two matrices
    I = product(A,B);
    // print out the matrix
    printMatrix(out, I);
    printMatrix(stdout, I);

    fprintf(out, "\nB*B =\n");
    fprintf(stdout, "\nB*B =\n");
    // J = product of B twice
    J = product(B,B);
    // print out the matrix
    printMatrix(out, J);
    printMatrix(stdout, J);

    // free all metrices
    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&C);
    freeMatrix(&D);
    freeMatrix(&E);
    freeMatrix(&F);
    freeMatrix(&G);
    freeMatrix(&H);
    freeMatrix(&I);
    freeMatrix(&J);
    // close files
    fclose(in);
    fclose(out);

    return 0;
}