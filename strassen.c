#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Strassen's Algorithm simplified for 2x2 to show the concept
// General Strassen for NxN is very large; using 2x2 for simplicity.

void strassen2x2(int A[2][2], int B[2][2], int C[2][2]) {
    int m1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    int m2 = (A[1][0] + A[1][1]) * B[0][0];
    int m3 = A[0][0] * (B[0][1] - B[1][1]);
    int m4 = A[1][1] * (B[1][0] - B[0][0]);
    int m5 = (A[0][0] + A[0][1]) * B[1][1];
    int m6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    int m7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    C[0][0] = m1 + m4 - m5 + m7;
    C[0][1] = m3 + m5;
    C[1][0] = m2 + m4;
    C[1][1] = m1 - m2 + m3 + m6;
}

int main() {
    int A[2][2], B[2][2], C[2][2];
    printf("Enter elements of 2x2 Matrix A:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) scanf("%d", &A[i][j]);

    printf("Enter elements of 2x2 Matrix B:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) scanf("%d", &B[i][j]);

    clock_t start = clock();
    strassen2x2(A, B, C);
    clock_t end = clock();

    printf("Result Matrix C:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) printf("%d ", C[i][j]);
        printf("\n");
    }
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
Strassen's Algorithm is a Divide and Conquer approach for matrix multiplication 
that reduces the number of recursive multiplications from 8 to 7.
Complexity: O(n^2.81)
Note: This implementation is for 2x2 matrices to demonstrate the formulas.
*/
