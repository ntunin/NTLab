
void gradient(int N, double **m, double *x, double *r) {
    for(int i = 0; i < size; i++) {
        r[i] = 0;
        for(int j = 0; j < size; j++) {
            r[i] += (m[i][j] + m[j][i]) * x[j];
        }
    }
}
