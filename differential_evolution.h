
struct de_context;
struct de_context *make_default_de_context(int size, int population_size, double estimate, double (*f)(int, double *), double mutation_force, double p, int check_index);
double *default_de(int size, int population_size, double estimate, double (*f)(int, double *), double mutation_force, double p, int check_index);
void differential_evolution(struct de_context *context);
double *dispose_de_context(struct de_context *context);
