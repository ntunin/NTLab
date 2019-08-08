#include "descend.h"
#include "linear_search.h"
#include "functions.h"

struct dsk_context *context;

void dsk_linear_search(double *x, double *dx) {
    return dsk(x, dx, context);
}

void test_descend_x2_0() {
    int size = 4;
    context = make_dsk_context(size, f_x2_1);
    double x[] = {5, 4, -1, 3};
    descend(size, x, f_x2_1, df_x2_1, dsk_linear_search);
    double f = f_x2_1(size, x)/size;
    printf("%f, f_x2_1\n", f - 2.87);
    dispose_dsk_context(context);
}

void test_descend_x2_1() {
    int size = 1;
    context = make_dsk_context(size, f_x2_1);
    double x[] = {10};
    descend(size, x, f_x2_3, df_x2_3, dsk_linear_search);
    double f = f_x2_3(size, x)/size;
    printf("%f, f_x2_3\n", f);
    dispose_dsk_context(context);
}

void test_descend() {
    //test_descend_x2_0();
    test_descend_x2_1();
}
