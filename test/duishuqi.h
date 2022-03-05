#ifndef _DUISHUQI_H_
#define _DUISHUQI_H_

#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
extern void swap(int a[], int i, int j);
extern void selectSort(int a[], int length);
extern void bubblingSort(int a[], int length);
extern void insertSort(int a[], int len);
extern void printArray(int a[], int length);

//生成一个随机数组长度为[0,maxlen - 1]，里面每一个值大小
//为[0, maxValue - 1]
typedef struct duishuqi
{
    int *arr;
    int len;
} duishuqi;
extern duishuqi randomArray(int maxLen, int maxValue);
//检查数组是否排列好顺序
extern bool isSorted(int arr[], int len);
#endif