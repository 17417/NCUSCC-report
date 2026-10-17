#include <stdio.h>

/* 读数统计（C11 起步模板）
 * 读入 n 和 n 个整数，按题面格式输出 count/sum/min/max。
 * 使用方法：cp c/main.c . ，完成 TODO 后自测、提交。
 */

int main(void) {
    int n = 0;
    if (scanf("%d", &n) != 1) {
        return 1; /* 没读到 n：保留非零退出码，便于发现输入问题 */
    }
    if(n > 10000){
	    return 1;
    }

    /* TODO: 逐个读入 n 个整数（范围 [-1000, 1000]），统计：
     *   count —— 读到的个数
     *   sum   —— 所有读数之和（int 范围内）
     *   min   —— 最小读数（不要用 0 初始化！）
     *   max   —— 最大读数
     */
    getchar();
    //printf("%s",buffer);
    int max = -1000,min = 1000,count = 0,sum=0;
    int temp = 0;
    while (count < n && scanf("%d", &temp) == 1)
    {
        count++;
        sum += temp;
        if (temp>max)
        {
            max = temp;
        }
        if (temp<min)
        {
            min = temp;
        }
    }

    /* TODO: 按以下格式输出（每行一个，"=" 两边不要有空格）：
     *   count=<n>
     *   sum=<S>
     *   min=<m>
     *   max=<M>
     */

    /* 占位输出：只保证程序能编译运行，统计尚未实现。 */
    printf("count=%d\n", count);
    printf("sum=%d\n", sum);
    printf("min=%d\n", min);
    printf("max=%d\n", max);
    return 0;
}
