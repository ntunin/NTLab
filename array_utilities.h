double *make_and_fill_1_dim_array(int N, double filling_value);
double *make_1_dim_random_array_in_interval(int N, double lower_bound, double upper_bound, int precision);
double *make_1_dim_random_array_in_radius(int N, double radius, int precision);
double *make_1_dim_random_array(int N, double radius);
double *copy_1_dim_array(int N, double *array);

double **make_and_fill_2_dim_array(int N, int M, double filling_value);
double **make_2_dim_random_array_in_interval(int N, int M, double lower_bound, double upper_bound, int precision);
double **make_2_dim_random_array_in_radius(int N, int M, double radius, int precision);
double **make_2_dim_random_array(int N, int M, double radius);

void dispose_array(int N, double **array);
void iterate_1_dim_array(int N, double *array, void(*action)(double));
void iterate_2_dim_array(int N, int M, double *array, void(*action)(double));

