#include <stdio.h>

double dot_product_c(const double* a, const double* b, int n) {
    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        result += a[i] * b[i];
    }
    return result;
}
