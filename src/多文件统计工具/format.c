#include "format.h"

#include <stdio.h>

/* 缺陷：定义的参数顺序与 format.h 和 main 的调用语义不一致。 */
void print_report(int count, long long total, int smallest, int largest) {
    //调整参数的顺序与类型
    printf("count=%d\n", count);
    printf("sum=%lld\n", total);
    printf("min=%d\n", smallest);
    printf("max=%d\n", largest);
}
