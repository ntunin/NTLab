#include <stdbool.h>

struct dsk_context {
    int size;
    double (*f)(double *);
    double *x_i;
    double *x_a;
    double *x_b;
    double *x_c;
};

struct dsk_context *make_dsk_context(int size, double (*f)(int, double *)) {
    struct dsk_context *context = (struct context *)malloc(sizeof(struct dsk_context));
    context->size = size;
    context->f = f;
    context->x_i = (double *)malloc(size * sizeof(double));
    context->x_a = (double *)malloc(size * sizeof(double));
    context->x_b = (double *)malloc(size * sizeof(double));
    context->x_c = (double *)malloc(size * sizeof(double));
    return context;
};

void dispose_dsk_context(struct dsk_context *context) {
    free(context->x_i);
    free(context->x_a);
    free(context->x_b);
    free(context->x_c);
    free(context);
}

void dsk(double *x, double *dx, struct dsk_context *context) {
    int size = context->size;
    double *x_i = context->x_i;
    double (*f)(int, double *) = context->f;
    double f0 = f(size, x);

    double delta_x = 1;
    double delta_x0 = 1;
    int steps = 0;

    double path = 0;
    double fi = f(size, x);
    double fi_1 = fi;
    double fi_2 = fi;

    while (true) {
        path += delta_x;
        for (int i = 0; i < size; i++) {
            x_i[i] = x[i] + path * dx[i];
        }
        fi = f(size, x_i);
        if (fi > fi_1) {
            if (steps > 2 || delta_x0 < 1e-5) {
                break;
            }
            delta_x0 /= 2;
            delta_x = delta_x0;
            path = 0;
            fi = f(size, x);
            fi_1 = fi;
            fi_2 = fi;
            continue;
        }
        fi_2 = fi_1;
        fi_1 = fi;
        delta_x *= 2;
        steps++;
    }

    double *x_a = context->x_a;
    double *x_b = context->x_b;
    double *x_c = context->x_c;

    delta_x /= 2;

    path -= delta_x * 3;
    double path_b = path + delta_x;
    double path_c = path + 2*delta_x;

    for (int i = 0; i < size; i++) {
        x_a[i] = x[i] + path * dx[i];
        x_b[i] = x[i] + path_b * dx[i];
        x_c[i] = x[i] + path_c * dx[i];
    }

    double f_a = f(size, x_a);
    double f_b = f(size, x_b);
    double f_c = f(size, x_c);

    double divider = (f_a - 2 * f_b + f_c);

    if (divider > 1e-9) {
        path += (f_c > f_b) ? (delta_x * (1 + (f_a - f_c) / (2 * divider))) : 2 * delta_x;
    }
    else {
        path += 2*delta_x;
    }

    for (int i = 0; i < size; i++) {
        x[i] = x[i] + path * dx[i];
    }
}
