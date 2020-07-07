#include "envirounment.h"
#include "helpers.h"
#include "array_utilities.h"
#include <stdbool.h>
#include <stdlib.h>

struct de_context {
    int size;
    int population_size;
    double(*f)(int,double *);
    double **population;
    double mutation_force;
    double*(*cross_over)(struct de_context*, double*, double*);
    double*(*fetch)(struct de_context*, int, double*);
    int(*random)(int);
    double p;
    int chek_index;
};

void dispose_de_context(struct de_context *context) {
    dispose_array(context->population_size, context->population);
    free(context);
}

double *default_crossover(struct de_context *context, double *x, double *c) {
    double *t = (double *)malloc(context->size * sizeof(double));
    for(int i = 0; i < context->size; i++) {
        double p_value = context->random(100) / 100.0;
        if (p_value > context->p) {
            t[i] = c[i];
        }
        else {
            t[i] = x[i];
        }
    }
    return t;
}

void defult_fetch(struct de_context *context, int index, double *descendant) {
    double f = context->f(context->size, context->population[index]);
    double next_f = context->f(context->size, descendant);
    if (next_f < f) {
        free(context->population[index]);
        context->population[index] = descendant;
    }
}


struct de_context *make_default_de_context(int size, int population_size, double estimate, double (*f)(int, double *), double mutation_force, double p, int check_index) {
    struct de_context *context = (struct default_de_context *)malloc(sizeof(struct de_context));
    context->size = size;
    context->population_size = population_size;
    context->f = f;
    context->random = default_random;
    context->population = make_2_dim_random_array(population_size, size, estimate);
    context->mutation_force = mutation_force;
    context->p = p;
    context->chek_index = check_index;
    context->cross_over = default_crossover;
    context->fetch = defult_fetch;
    return context;
};

bool should_stop(struct de_context *context) {
    double max_norm = 0;
    for (int i = 1; i < context->population_size; i++) {
        double norm = 0;
        for (int j = 0; j < context->size; j++) {
            double diff = context->population[0][j] - context->population[i][j];
            norm += diff * diff;
        }
        if (norm > max_norm) {
            max_norm = norm;
        }
    }
    max_norm = sqrt(max_norm);
    return max_norm <= ACCURACY;
}

void differential_evolution(struct de_context *context) {
    double *mutator = (double *)malloc(context->size * sizeof(double));
    for(int iteration = 0; iteration < ITERATIONS_COUNT; iteration++) {
        int individ_number = context->random(context->population_size);
        int mutator_individ_number;
        int second_mutator_individ_number;
        int third_mutator_individ_number;
        do {
            mutator_individ_number = context->random(context->population_size);
        } while(mutator_individ_number == individ_number);

        do {
            second_mutator_individ_number = context->random(context->population_size);
        } while(second_mutator_individ_number == individ_number || second_mutator_individ_number == mutator_individ_number);

        do {
            third_mutator_individ_number = context->random(context->population_size);
        } while(third_mutator_individ_number == individ_number || third_mutator_individ_number == mutator_individ_number);

        double *individ = context->population[individ_number];
        double *mutator_individ = context->population[mutator_individ_number];
        double *second_mutator_individ = context->population[second_mutator_individ_number];
        double *third_mutator_individ = context->population[third_mutator_individ_number];

        for(int i = 0; i < context->size; i++) {
            //Ci' = Ci + F * (Ai - Bi)
            mutator[i] = mutator_individ[i] + context->mutation_force * (second_mutator_individ[i] - third_mutator_individ[i]);
        }
        double *descendant = context->cross_over(context, individ, mutator);
        context->fetch(context, individ_number, descendant);
        if (iteration % context->chek_index == 0 && should_stop(context)) {
            free(mutator);
            return;
        }
    }
    free(mutator);
}

double* default_de(int size, int population_size, double estimate, double (*f)(int, double *), double mutation_force, double p, int check_index) {
    struct de_context *context = make_default_de_context(size, population_size, estimate, f, mutation_force, p, check_index);
    differential_evolution(context);
    double *result = copy_1_dim_array(size, context->population[0]);
    dispose_de_context(context);
    return result;
}
