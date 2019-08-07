#include <stdio.h>
#include "functions.h"

void test_dsk_x2_0() {
    int size = 4;
    struct context *ctx = make_dsk_context(size, f_x2_1);
    double x[] = {5, 4, -1, 3};
    double dx[] = {-1, -1, 1, -1};
    dsk(x, dx, ctx);
    double f = f_x2_1(size, x)/size;
    printf("%f, f_x2_1\n", f - 2.87);
    dispose_dsk_context(ctx);
}

void test_dsk_x2_1() {
    int size = 4;
    struct context *ctx = make_dsk_context(size, f_x2_2);
    double x[] = {5, 4, -1, 3};
    double dx[] = {-1, -1, 1, -1};
    dsk(x, dx, ctx);
    double f = f_x2_2(size, x)/size;
    printf("%f, f_x2_2\n", f + 1);
    dispose_dsk_context(ctx);
}

void test_dsk() {
    test_dsk_x2_0();
    test_dsk_x2_1();
}

void test_ls() {
    test_dsk();
}
