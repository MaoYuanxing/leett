#include "duishuqi.h"
void swap(int a[], int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
// 选择排序
void selectSort(int a[], int length)
{
    if (length < 2)
    {
        return;
    }
    for (int i = 0; i < length; i++)
    {
        int min = i;
        for (int j = i; j < length; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        int tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
}

// 冒泡排序
void bubblingSort(int a[], int length)
{
    if (length < 2)
    {
        return;
    }
    for (int i = length; i > 0; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a, j, j + 1);
            }
        }
    }
}

//插入排序
void insertSort(int a[], int len)
{
    if (len < 2)
    {
        return;
    }
    for (int i = 1; i < len; i++)
    {
        for (int j = i; j > 0 && a[j] < a[j - 1]; j--)
        {
            swap(a, j, j - 1);
        }
    }
}

void printArray(int a[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}

duishuqi randomArray(int maxLen, int maxValue)
{

    int len = rand() % maxLen;
    int *arr = malloc(len * sizeof(int));
    duishuqi a;
    a.len = len;
    a.arr = arr;
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % maxValue;
    }
    return a;
}

//检查数组是否排列好顺序
bool isSorted(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}