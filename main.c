#include <stdio.h>
#include <stdlib.h>
#include <sys\timeb.h>
#include "linear_search.h"
#include "descend.h"
#include "envirounment.h"

int TIME_LIMIT = 1e6;
double ACCURACY = 1e-4;

struct timeb time;

int main()
{
    test_ls();
    test_descend();
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
