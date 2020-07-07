

double **make_random_populations(int populations_number) {
	double **populations = (double **)malloc(size*sizeof(double*));
	for(int i = 0; i < populations_number; i++) {
        populations[i] = (double *)malloc(size*sizeof(double));
	}
	return populations;
}
