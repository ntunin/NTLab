#include "linear_search.h"
#include "envirounment.h"
#include <stdbool.h>

void descend(int size, double *x, double(*f)(int, double *), void(*df)(int, double *, double *), void (*linear_search)(double *, double *)) {
    double last_value = 0;
	double value = 1e7;
	double step = 1;
	double *direction = (double *)malloc(size*sizeof(double));
	double *tmp_x = (double *)malloc(size*sizeof(double));
	int start_time = system_time();
	int end_time = start_time;
	int full_time = 0;
	int count = 0;
	int iteration_time;
	while (fabs(last_value - value) > ACCURACY) {
		end_time = system_time();
		iteration_time = end_time - start_time;
		start_time = end_time;
		full_time += iteration_time;

		count++;

		if (full_time > TIME_LIMIT) {
			break;
		}

		bool has_valid_direction = false;
        last_value = value;
        value = f(size, x);
        df(size, x, direction);

        for (int i = 0; i < size; i++) {
            tmp_x[i] = x[i] + step * direction[i];
        }
        double value_plus = f(size, tmp_x);

        if (value_plus < value) {
            has_valid_direction = true;
        }

        if (has_valid_direction) {
            linear_search(x, direction);
        }
        else {
            step /= 2;
            last_value = -1e7;
        }

	}
	free(direction);
	free(tmp_x);
}
