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
    // Example vectors
    const int n = 5;
    double a[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    double b[5] = { 5.0, 4.0, 3.0, 2.0, 1.0 };

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

    return 0;
}
