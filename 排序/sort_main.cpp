/*
排序.cpp : 定义控制台应用程序的入口点。
参考文献为：
1、十大经典排序算法（动图演示） 
https://www.cnblogs.com/onepixel/articles/7674659.html
2、七大经典排序算法总结(C语言描述)  
https://www.cnblogs.com/maluning/p/7944809.html#_label1_1
3、常用排序算法总结(一) 
http://www.cnblogs.com/eniac12/p/5329396.html
4、常用排序算法总结(二) 
http://www.cnblogs.com/eniac12/p/5332117.html
*/

#include "stdafx.h"
#include "sort.h"
#include<stdlib.h>
#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

bool IsEqual(int* test, const int* right, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (*(test+i)!=*(right+i))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	const static int bufferSize = 10;
	const int right[bufferSize] = { 0,1,2,3,4,5,6,7,8,9 };
	int test1[bufferSize] = { 1,5,8,3,9,2,0,4,7,6 };
	int test2[bufferSize] = { 1,2,3,4,5,6,7,8,9,0 };
	int test3[bufferSize] = { 2,3,1,4,5,6,7,8,9,0 };
	int test4[bufferSize] = { 6,1,5,4,2,9,3,0,7,8 };
	int test5[bufferSize] = { 8,2,1,7,6,5,0,4,3,9 };

	int *p[5];
	p[0] = test1;
	p[1] = test1;
	p[2] = test1;
	p[3] = test1;
	p[4] = test1;

	//QuickSort(test1, 0, bufferSize - 1);
	//QuickSort(test2, 0, bufferSize - 1);
	//QuickSort(test3, 0, bufferSize - 1);
	//QuickSort(test4, 0, bufferSize - 1);
	//QuickSort(test5, 0, bufferSize - 1);
	HeapSort(test1, bufferSize);
	HeapSort(test2, bufferSize);
	HeapSort(test3, bufferSize);
	HeapSort(test4, bufferSize);
	HeapSort(test5, bufferSize);

	for (size_t i = 0; i < 5; i++)
	{
		cout << i << ": ";
		for (size_t j = 0; j < bufferSize; j++)
		{
			cout << " " <<p[i][j];
		}
		cout << endl;
	}

	system("pause");

    return 0;
}

