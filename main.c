#include <stdio.h>
#include <stdlib.h>
#include <sys\timeb.h>
#include "linear_search.h"
#include "descend.h"
#include "differential_evolution.h"
#include "envirounment.h"

int TIME_LIMIT = 1e6;
int ITERATIONS_COUNT = 100000;
double ACCURACY = 1e-8;

struct timeb time;

int main()
{
    test_ls();
    test_descend();
    test_rosenbroke_function();
    system("pause");
    return 0;
}

void log(const char *message) {
    printf("%s", message);
}

int system_time() {
    ftime(&time);
    return time.millitm;
}
