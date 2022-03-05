#include <stdio.h>
#include <stdbool.h>
#include "duishuqi.h"

bool binarySearch(int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int midVal = a[mid];
        if (midVal < key)
            low = mid + 1;
        else if (midVal > key)
            high = mid - 1;
        else
            return true;
    }
    return false;
}

int leftbinarySearch(int a[], int n, int key)
{
    if (!a || !n)
        return -1;
    int low = 0;
    int high = n - 1;
    int t = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int midVal = a[mid];
        if (midVal < key)
            low = mid + 1;
        else
        {
            high = mid - 1;
            t = mid;
        }
    }
    return t;
}

int localmin(int a[], int len)
{
    if (!a || !len)
        return -1;
    if (len == 1)
        return 0;
    if (a[0] < a[1])
        return 0;
    if (a[len - 1] < a[len - 2])
        return len - 1;
    int left = 0;
    int right = len - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] < a[mid + 1] && a[mid] < a[mid - 1])
            return mid;
        else
        {
            if (a[mid] > a[mid + 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
}
duishuqi MyrandomArray(int maxLen, int maxValue)
{

    int len = rand() % maxLen;
    int *arr = malloc(len * sizeof(int));
    duishuqi a;
    a.len = len;
    a.arr = arr;
    arr[0] = rand() % maxValue;
    for (int i = 0; i < len; i++)
    {
        do
        {
            arr[i] = rand() % maxValue;
        } while (arr[i] == arr[i - 1]);
    }
    return a;
}
bool test1(int a[], int len, int minIndex)
{
    if (len == 0)
        return minIndex == -1;
    int left = minIndex - 1;
    int right = minIndex + 1;
    bool leftBigger = left >= 0 ? a[left] > a[minIndex] : true;
    bool rightBigger = right < len ? a[right] > a[minIndex] : true;
    return leftBigger && rightBigger;
}
bool test(int a[], int len, int key)
{
    for (int i = 0; i < len; i++)
    {
        if (a[i] == key)
            return true;
    }
    return false;
}

int main()
{
    // srand((unsigned)time(0));
    // int maxlen = 100;
    // int maxvalue = 200;
    // int times = 1000000;
    // for (int i = 0; i < times; i++)
    // {
    //     duishuqi a = MyrandomArray(maxlen, maxvalue);
    //     int len = a.len;
    //     int *arr = a.arr;
    //     // insertSort(arr, len);
    //     int minIndex = localmin(arr, len);
    //     if (!test1(arr, len, minIndex))
    //     {
    //         printf("error!\n");
    //         printf("minIndex: %d, len: %d\n", minIndex, len);
    //         printArray(arr, len);
    //         break;
    //     }
    // }
    // printf("the method is correct!\n");

    int a[5] = {3, 2, 3, 2, 3};
    printf("%d\n", localmin(a, 5));
    return 0;
}
