double f_x2(int size, double *x, double a, double b, double c) {
    double result = 0;
    for(int i = 0; i < size; i++) {
        result += a * x[i]*x[i] + b * x[i] + c;
    }
    return result;
}

double f_x2_1(int size, double *x) {
    return f_x2(size, x, 2, -7, 9);
}

double f_x2_2(int size, double *x) {
    return f_x2(size, x, 3, 0, -1);
}
