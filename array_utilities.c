#include "array_utilities.h"
#include <stdlib.h>

double *make_and_fill_1_dim_array(int N, double filling_value) {
	double *array = (double **)malloc(N*sizeof(double));
	for(int i = 0; i < N; i++) {
        array[i] = filling_value;
	}
	return array;
}

double *make_1_dim_random_array_in_interval(int N, double lower_bound, double upper_bound, int precision) {
	double *array = (double **)malloc(N*sizeof(double));
	double radius = (upper_bound - lower_bound) / 2;
	double center = (lower_bound + radius);
	int r = 2 * radius * precision;
	for(int i = 0; i < N; i++) {
        array[i] = rand()%r/(double)precision - radius + center;
	}
	return array;
}

double *make_1_dim_random_array_in_radius(int N, double radius, int precision) {
	return make_1_dim_random_array_in_interval(N, -radius, radius, precision);
}

double *make_1_dim_random_array(int N, double radius) {
	return make_1_dim_random_array_in_interval(N, -radius, radius, 1);
}

double *copy_1_dim_array(int N, double *array) {
	double *result = (double **)malloc(N*sizeof(double));
	for(int i = 0; i < N; i++) {
        result[i] = array[i];
	}
	return result;
}

double **make_and_fill_2_dim_array(int N, int M, double filling_value) {
	double **array = (double **)malloc(N*sizeof(double*));
	for(int i = 0; i < N; i++) {
        array[i] = (double *)malloc(M*sizeof(double));
        for(int j = 0; j < M; j++) {
            array[i][j] = filling_value;
        }
	}
	return array;
}

double **make_2_dim_random_array_in_interval(int N, int M, double lower_bound, double upper_bound, int precision) {
	double **populations = (double **)malloc(N*sizeof(double*));
	for(int i = 0; i < N; i++) {
        populations[i] = make_1_dim_random_array_in_interval(M, lower_bound, upper_bound, precision);
	}
	return populations;
}

double **make_2_dim_random_array_in_radius(int N, int M, double radius, int precision) {
	double **populations = (double **)malloc(N*sizeof(double*));
	for(int i = 0; i < N; i++) {
        populations[i] = make_1_dim_random_array_in_radius(M, radius, precision);
	}
	return populations;
}

double **make_2_dim_random_array(int N, int M, double radius) {
	double **populations = (double **)malloc(N*sizeof(double*));
	for(int i = 0; i < N; i++) {
        populations[i] = make_1_dim_random_array(M, radius);
	}
	return populations;
}

void dispose_array(int N, double **array) {
    for(int i = 0; i < N; i++) {
        free(array[i]);
    }
    free(array);
}

void iterate_1_dim_array(int N, double *array, void(*action)(double)) {
    for(int i = 0; i < N; i++) {
        action(array[i]);
    }
}

void iterate_2_dim_array(int N, int M, double *array, void(*action)(double)) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            action(array[i]);
        }
    }
}
