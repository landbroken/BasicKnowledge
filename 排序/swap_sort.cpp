#include "stdafx.h"
#include "sort.h"

/*
@brief 冒泡排序
*/
void BubbleSort(int* data,int length)
{
	for (int i = 0; i < length-1; i++)
	{
		for (int j = 0; j < length-i-1; j++)
		{
			if (data[j]>data[j+1])
			{
				swap(&data[j], &data[j+1]);
			}
		}
	}
}

/*
@brief 鸡尾酒排序，也叫定向冒泡排序
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- 如果序列在一开始已经大部分排序过的话,会接近O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定

此算法与冒泡排序的不同处在于从低到高然后从高到低，
而冒泡排序则仅从低到高去比较序列里的每个元素。他
可以得到比冒泡排序稍微好一点的效能。

在乱数序列的状态下，鸡尾酒排序与冒泡排序的效率都很差劲。
*/
void CocktailSort(int* A, int length)
{
	int left = 0;                            // 初始化边界
	int right = length - 1;
	while (left < right)
	{
		for (int i = left; i < right; i++)   // 前半轮,将最大元素放到后面
		{
			if (A[i] > A[i + 1])
			{
				swap(&A[i], &A[i + 1]);
			}
		}
		right--;
		for (int i = right; i > left; i--)   // 后半轮,将最小元素放到前面
		{
			if (A[i - 1] > A[i])
			{
				swap(&A[i - 1], &A[i]);
			}
		}
		left++;
	}
}


/*
@brief 快速排序的排序部分
*/
int Partition(int* A, int left, int right)  // 划分函数
{
	int pivot = A[right];               // 这里每次都选择最后一个元素作为基准
	int tail = left - 1;                // tail为小于基准的子数组最后一个元素的索引
	for (int i = left; i < right; i++)  // 遍历基准以外的其他元素
	{
		if (A[i] <= pivot)              // 把小于等于基准的元素放到前一个子数组末尾
		{
			tail++;
			swap(&A[tail], &A[i]);
		}
	}
	swap(&A[tail + 1], &A[right]);           // 最后把基准放到前一个子数组的后边，剩下的子数组既是大于基准的子数组
											 // 该操作很有可能把后面元素的稳定性打乱，所以快速排序是不稳定的排序算法

	return tail + 1;                    // 返回基准的索引
}

/*
@brief 快速排序
@基本思想
通过一趟排序将待排记录分隔成独立的两部分，其中一部分记录的关键字
均比另一部分的关键字小，则可分别对这两部分记录继续进行排序，以达
到整个序列有序。

@算法描述
•从数列中挑出一个元素，称为 “基准”（pivot）；
•重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准
值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，
该基准就处于数列的中间位置。这个称为分区（partition）操作；
•递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数
列排序。


@分析
在平均状况下，排序n个元素要O(nlogn)次比较。在最坏状况下则需要O(n^2)次
比较，但这种状况并不常见。事实上，快速排序通常明显比其他O(nlogn)算法
更快，因为它的内部循环可以在大部分的架构上很有效率地被实现出来。
*/
void QuickSort(int* A, int left, int right)
{
	if (left >= right)
		return;
	int pivot_index = Partition(A, left, right); // 基准的索引
	QuickSort(A, left, pivot_index - 1);
	QuickSort(A, pivot_index + 1, right);
}



