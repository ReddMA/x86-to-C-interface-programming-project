#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern double dot_product_asm(const double* a, const double* b, int n);

double dot_product_c(const double* a, const double* b, int n) {
    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        result += a[i] * b[i];
    }
    return result;
}

int main() {
    int n;
    printf("Enter the size of the vectors: ");
    scanf_s("%d", &n);

    // Allocate memory for vectors dynamically
    double* a = (double*)malloc(n * sizeof(double));
    double* b = (double*)malloc(n * sizeof(double));

    if (a == NULL || b == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Fill vector a with increasing order and vector b with decreasing order
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;         // Elements in increasing order from 1 to n
        b[i] = n - i;         // Elements in decreasing order from n to 1
    }

    LARGE_INTEGER frequency, start, end;
    double time_c, result_c, time_asm, result_asm;

    // Get the frequency for the high-resolution performance counter
    QueryPerformanceFrequency(&frequency);

    // Measure C version
    QueryPerformanceCounter(&start);
    result_c = dot_product_c(a, b, n);
    QueryPerformanceCounter(&end);
    time_c = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("Dot product C: %lf, Time: %f seconds\n", result_c, time_c);
    printf("\n");
    QueryPerformanceCounter(&start);
    result_asm = dot_product_asm(a, b, n);
    QueryPerformanceCounter(&end);
    time_asm = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("Dot product ASM: %lf, Time: %f seconds\n", result_asm, time_asm);

    // Free allocated memory
    free(a);
    free(b);

    return 0;
}
