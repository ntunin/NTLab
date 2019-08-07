
struct dsk_context;
struct dsk_context *make_dsk_context(int size, double (*f)(int, double *));
void dispose_dsk_context(struct dsk_context *context);
void dsk(double *x, double *dx, struct dsk_context *context);
