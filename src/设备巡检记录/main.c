#include <stdio.h>
#include <string.h>
/* 设备巡检记录（C11 起步模板）
 * 建议定义记录结构体，并用函数拆分读取、聚合和输出。
 * 名称不强制，评分只检查程序行为。
 */

struct Record {
    char type[16];
    char status[16];
    int hours;
};
int main(void) {
    int count = 0;
    if (scanf("%d", &count) != 1) return 1;

    /* TODO: 读取 count 条记录并按固定顺序输出四类统计。 */

    int total = 0;
    int TotalPrinterCount = 0, TotalScannerCount = 0, TotalRouterCount = 0,TotalServerCount = 0;
    int TotalPrinterHours = 0, TotalScannerHours = 0, TotalRouterHours = 0,TotalServerHours = 0;
    int TempTime = 0;           //Temptime用于对比出时间最多的那个
    int busiest = 1;            //1为printer，2为scanner，3为router，4为server
    //需要把busiest初始化为1，否则如果所有都为0时，busiest不会有任何输出
    struct Record NewRecord;
    getchar();
    //消除回车后我们需要读取一个Record，以字符串 字符串 整型读取
    //无法重复读取，读取一次后就会直接跳出while循环
    //原因：scanf读取成功n个数据后返回n而不是1,直接用3
    while(total < count && scanf("%s%s%d",NewRecord.type,NewRecord.status,&NewRecord.hours) == 3){
        //此处有过一个隐藏bug：c语言里不允许字符串之间和另一个字符串相比，要用strcmp
        //一些未知bug导致if无法进行
        if ((strcmp(NewRecord.status,"ok") == 0 || strcmp(NewRecord.status,"repair") == 0) && (NewRecord.hours >= 0 && NewRecord.hours <= 100000))
        {
            //这一长串if里东西的意思就是，分析status是不是ok或repair，以及限定hours必须在[0,100000]而不是(0,100000)
            if (strcmp(NewRecord.type,"printer") == 0)
            {
                TotalPrinterHours += NewRecord.hours;
                TotalPrinterCount++;
                total++;
            }
            else if (strcmp(NewRecord.type,"scanner") == 0)
            {
                TotalScannerHours += NewRecord.hours;
                TotalScannerCount++;
                total++;
            }
            else if (strcmp(NewRecord.type,"router") == 0)
            {
                TotalRouterHours += NewRecord.hours;
                TotalRouterCount++;
                total++;
            }
            else if (strcmp(NewRecord.type,"server") == 0)
            {
               TotalServerHours += NewRecord.hours;
               TotalServerCount++;
               total++;
            }
        }
        getchar();
    }
    //统计完所有数据后就可以判定一下busiest了
    if (TempTime < TotalPrinterHours)
    {
        TempTime = TotalPrinterHours;
        busiest = 1;
    }
    if (TempTime < TotalScannerHours)
    {
        TempTime = TotalScannerHours;
        busiest = 2;
    }
    if (TempTime < TotalRouterHours)
    {
        TempTime = TotalRouterHours;
        busiest = 3;
    }
    if (TempTime < TotalServerHours)
    {
        TempTime = TotalServerHours;
        busiest = 4;
    }
    
    

    printf("printer %d %d\n",TotalPrinterCount,TotalPrinterHours);
    printf("scanner %d %d\n",TotalScannerCount,TotalScannerHours);
    printf("router %d %d\n",TotalRouterCount,TotalRouterHours);
    printf("server %d %d\n",TotalServerCount,TotalServerHours);
    switch (busiest){
        case 1:
            printf("busiest %s\n","printer");
            break;
        case 2:
            printf("busiest %s\n","scanner");
            break;
        case 3:
            printf("busiest %s\n","router");
            break;
        case 4:
            printf("busiest %s\n","server");
            break;
        default:
            break;
    }

    
    return 0;
}
