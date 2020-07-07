#include "differential_evolution.h"
#include <stdlib.h>

double rosenbroke_function(int size, double *x) {
    return 100 * (x[1] - x[0]*x[0]) * (x[1] - x[0]*x[0]) + (1 - x[0]) * (1 - x[0]);
}

void test_rosenbroke_function() {
    double *result = default_de(2, 200, 2, rosenbroke_function, 0.5, 0.5, 1000);
    printf("f_de(%f, %f) = %f\n", result[0], result[1], rosenbroke_function(2, result));
    free(result);
}
