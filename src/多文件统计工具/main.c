#include "format.h"
#include "stats.h"

#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int count = 0;
    if (scanf("%d", &count) != 1 || count <= 0) return 1;
    int* values = calloc((size_t)count, sizeof(int));
    if (values == NULL) return 1;
    for (int i = 0; i < count; ++i) {
        if (scanf("%d", &values[i]) != 1) {
            free(values);
            return 1;
        }
    }
    print_report(count, sum_values(values, count), min_value(values, count), max_value(values, count));
    free(values);
    return 0;
}
