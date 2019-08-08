#include <stdbool.h>
#include "direction.h"

void find_direction(int size, double *x, double *dx, double(*f)(int size, double *)) {
    double step = 1;
    double value;
    double zero;
    double plus;
    double minus;
    double value_plus;
    double value_minus;
    for (int i = 0; i < size; i++) {
        while(true) {
            dx[i] = 0;
            value = f(size, x);
            zero = x[i];
            plus = x[i] + step;
            minus = x[i] - step;
            x[i] = plus;
            value_plus = f(size, x);
            x[i] = minus;
            value_minus = f(size, x);
            x[i] = zero;

            if (value_plus < value || value_minus < value) {
                if (value_plus < value_minus) {
                    dx[i] = +step;
                    break;
                }
                else {
                    dx[i] = -step;
                    break;
                }
            }
            step /= 2;
            if (step < FIND_DIRECTION_ACCURACY) {
                break;
            }
        }
    }
}
