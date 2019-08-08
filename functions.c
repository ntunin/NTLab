#include "direction.h"
#include "math.h"

double FIND_DIRECTION_ACCURACY = 1e-9;

double f_x2(int size, double *x, double a, double b, double c) {
    double result = 0;
    for(int i = 0; i < size; i++) {
        result += a * x[i]*x[i] + b * x[i] + c;
    }
    return result;
}

void df_x2(int size, double *x, double *df, double a, double b) {
    for(int i = 0; i < size; i++) {
        df[i] = -(a * 2 * x[i] + b);
    }
}

double f_x2_1(int size, double *x) {
    return f_x2(size, x, 2, -7, 9);
}

void df_x2_1(int size, double *x, double *df) {
    df_x2(size, x, df, 2, -7);
}

double f_x2_2(int size, double *x) {
    return f_x2(size, x, 3, 0, -1);
}

void df_x2_2(int size, double *x, double *df) {
    df_x2(size, x, df, 3, 0);
}

double f_x2_3(int size, double *x) {
    double result = 0;
    for(int i = 0; i < size; i++) {
        result += -x[i]*x[i] + 1 + 10*pow(fmin(x[i], 0) + fmax(x[i] - 1, 0), 2);
    }
    return result;
}

void df_x2_3(int size, double *x, double *df) {
    find_direction(size, x, df, f_x2_3);
}

