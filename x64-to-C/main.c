#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Function prototypes
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
    scanf("%d", &n);

    // Allocate memory for vectors dynamically
    double* a = (double*)malloc(n * sizeof(double));
    double* b = (double*)malloc(n * sizeof(double));

    if (a == NULL || b == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Prompt user for vector values
    printf("Enter values for the first vector:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    printf("Enter values for the second vector:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    LARGE_INTEGER frequency, start, end;
    double time_c, result_c;

    // Get the frequency for the high-resolution performance counter
    QueryPerformanceFrequency(&frequency);

    // Measure C version
    QueryPerformanceCounter(&start);
    result_c = dot_product_c(a, b, n);
    QueryPerformanceCounter(&end);
    time_c = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("Dot product C: %lf, Time: %f seconds\n", result_c, time_c);

    // Free allocated memory
    free(a);
    free(b);

    return 0;
}
