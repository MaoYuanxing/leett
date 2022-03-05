#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include "duishuqi.h" //创建随机数组返回值用名为duishuqi的结构
                      //此结构包含数组长度及数组首地址

// 十进制转换为32位二进制
void print(int i)
{
    for (int j = 31; j >= 0; j--)
    {
        printf("%d", (i & (1 << j)) == 0 ? 0 : 1);
    }
    printf("\n");
}

// 1!+2!+3!+...+n!的两种实现
int factor(int i)
{
    int ans = 1;
    for (int j = 1; j <= i; j++)
    {
        ans = j * ans;
    }
    return ans;
}
void f1(int i)
{
    int ans = 0;
    for (int j = 1; j <= i; j++)
    {
        ans += factor(j);
    }
    printf("%d\n", ans);
}

void f2(int i)
{
    int ans = 0;
    int cur = 1;
    for (int j = 1; j <= i; j++)
    {
        cur = cur * j;
        ans += cur;
    }
    printf("%d\n", ans);
}

// ff1()等概率生成1到5的随机数
int ff1()
{
    int p = rand() % 5 + 1;
    return p;
}
//用ff1()构造函数g()使得g()生成0到7的随机数
int ff2()
{
    int ans = 0;
    do
    {
        ans = ff1();
    } while (ans == 3);
    ans = ans < 3 ? 0 : 1;
    return ans;
}
int g()
{
    int ans = 0;
    do
    {
        ans = (ff2() << 2) + (ff2() << 1) + ff2();
    } while (ans == 7);
}

// fff1()函数等于1的概率为p等于0的概率为1-p
//依此构造g1()使得生成0和1的概率相同
int fff1()
{
    int p = rand() % 100;
    int ans = p < 84 ? 0 : 1;
    return ans;
}

int g1()
{
    int ans = 0;
    do
    {
        ans = fff1();
    } while (ans == fff1());
    ans = ans == 0 ? 0 : 1;
    return ans;
}
int main()
{
    // 逻辑左移与右移 符号右移
    // int i = 2;
    // print(i);
    // int ii = INT_MIN;
    // print(ii);
    // print(ii >> 1);
    // print((unsigned int)ii >> 1);

    // sort test;
    //  int a[11] = {1, 3, 543, 34, 54, 33, 4, 5, 34, 5, 786};
    //  int n = sizeof(a) / sizeof(a[0]);
    //  printArray(a, n);
    //  insertSort(a, n);
    //  printArray(a, n);

    // srand((unsigned)time(0));
    // int times = 10000000;
    // int n = 2;
    // int count[2] = {0};
    // for (int i = 0; i < times; i++)
    // {
    //     int p = g1();
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (p == i)
    //         {
    //             count[i]++;
    //         }
    //     }
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%f\n", (double)count[i] / (double)times);
    // }
    srand((unsigned)time(0));
    int maxlen = 10;
    int maxValue = 5;
    duishuqi a = randomArray(maxlen, maxValue);
    int len = a.len;
    int *arr = a.arr;
    printArray(arr, len);
    return 0;
}