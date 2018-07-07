#pragma once
#ifndef _SEARCH_H_
#define _SEARCH_H_

//1. 顺序查找
int SequenceSearch(int a[], int value, int n);

//2. 二分查找
int BinarySearch(int a[], int value, int n);
int BinarySearch_Recursion(int a[], int value, int low, int high);

//3. 插值查找
int InsertionSearch(int a[], int value, int low, int high);
int InsertionSearch_Recursion(int a[], int value, int low, int high);

//4. 斐波那契查找
int FibonacciSearch(int *a, int n, int key);

//5. 树表查找

//6. 分块查找

//7. 哈希查找

#endif // !_SEARCH_H_
