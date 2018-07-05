#include "stdafx.h"
#include "sort.h"
#include<math.h>
using namespace std;

/*
@brief 合并操作
将两个有序表合并成一个有序表
*/
void Merge(int* a, int left, int mid, int right)
{
	int len = right - left + 1;        //    数组的长度
	int *temp= new int[len];       // 分配个临时数组
	//int temp[100];       // 分配个临时数组
	int k = 0;
	int i = left;                   // 前一数组的起始元素
	int j = mid + 1;                // 后一数组的起始元素
	while (i <= mid && j <= right)
	{
		//选择较小的存入临时数组
		if (a[i]<a[j])
		{
			temp[k] = a[i];
			i++;
		}
		else
		{
			temp[k] = a[j];
			j++;
		}
		k++;
	}
	//将剩余的部分存入临时数组
	while (i <= mid)
	{
		temp[k] = a[i];
		i++;
		k++;
	}
	while (j <= right)
	{
		temp[k] = a[j];
		j++;
		k++;
	}
	//将排序后的数组放到原数组中的对应位置
	for (int q = 0; q < len; q++)
	{
		a[left] = temp[q];
		left++;
	}
	if (temp!=nullptr)
	{
		delete temp;
	}
}

/*
@brief 归并排序
递归实现
@基本思想
归并排序是建立在归并操作上的一种有效的排序算法。该算法是采用
分治法（Divide and Conquer）的一个非常典型的应用。将已有序的
子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子
序列段间有序。若将两个有序表合并成一个有序表，称为2-路归并。

@算法描述
•把长度为n的输入序列分成两个长度为n/2的子序列；
•对这两个子序列分别采用归并排序；
•将两个排序好的子序列合并成一个最终的排序序列。

@分析
归并排序是一种稳定的排序方法。和选择排序一样，归并排序的性能不受
输入数据的影响，但表现比选择排序好的多，因为始终都是O(nlogn）的
时间复杂度。代价是需要额外的内存空间。
*/
void MergeSort(int* a, int left, int right)
{
	if (left == right)
		return;
	int mid = (left + right) / 2;
	MergeSort(a, left, mid);
	MergeSort(a, mid + 1, right);
	Merge(a, left, mid, right);
}
