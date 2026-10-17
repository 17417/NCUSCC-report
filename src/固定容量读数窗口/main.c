#include <stdio.h>

/* 固定容量读数窗口（含已知缺陷的 C11 起步代码） */

int main(void) {
    enum { CAPACITY = 8 };
    int window[8] = {0};
    int kept = 0;
    int count = 0;
    int OldPoint = 0,NewPoint = 0;              //利用OldPoint来指向最早的那个，NewPoint指向最新的那个
    if (scanf("%d", &count) != 1) return 1;
    for (int i = 0; i < count; ++i) {
        int value = 0;
        if (scanf("%d", &value) != 1) return 1;

        window[i % CAPACITY] = value; /* 缺陷：下标没有按 CAPACITY 回绕。 */ //方案：对i进行取余，实现回绕
        NewPoint = i % CAPACITY;       //每次有新数就把NewPoint指向它
        if(kept < CAPACITY){           //方案：限制kept必须小于8
            ++kept;            /* 缺陷：保留数量没有上限。 */
        }
        else{
            OldPoint = (i+1) % CAPACITY;
        }
        
    }
    long long sum = 0;
    for (int i = 0; i < kept; ++i) sum += window[i];
    printf("kept=%d\n", kept);
    printf("oldest=%d\n", window[OldPoint]);
    printf("last=%d\n", window[NewPoint]);
    printf("sum=%lld\n", sum);
    (void)CAPACITY;
    return 0;
}
