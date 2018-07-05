#include "stdafx.h"
#include "sort.h"

/*
@brief 简单选择排序
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- O(n^2)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定

选择排序是不稳定的排序算法，不稳定发生在最小元素与A[i]交换的时刻。
*/
void SelectSort(int* data, int length)
{
	int minIndex = 0;
	for (int i = 0; i < length - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < length; j++)
		{
			if (*(data + j)<*(data + minIndex))
			{
				minIndex = j;
			}
		}
		// 放到已排序序列的末尾，该操作很有可能把稳定性打乱，
		// 所以选择排序是不稳定的排序算法
		swap((data + i), (data + minIndex));

	}
}

#pragma region 堆排序

void Swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void Heapify(int A[], int i, int size)  // 从A[i]向下进行堆调整
{
	int left_child = 2 * i + 1;         // 左孩子索引
	int right_child = 2 * i + 2;        // 右孩子索引
	int max = i;                        // 选出当前结点与其左右孩子三者之中的最大值
	if (left_child < size && A[left_child] > A[max])
		max = left_child;
	if (right_child < size && A[right_child] > A[max])
		max = right_child;
	if (max != i)
	{
		Swap(A, i, max);                // 把当前结点和它的最大(直接)子节点进行交换
		Heapify(A, max, size);          // 递归调用，继续从当前结点向下进行堆调整
	}
}

int BuildHeap(int A[], int n)           // 建堆，时间复杂度O(n)
{
	int heap_size = n;
	for (int i = heap_size / 2 - 1; i >= 0; i--) // 从每一个非叶结点开始向下进行堆调整
		Heapify(A, i, heap_size);
	return heap_size;
}

void HeapSort(int* A, int len)
{
	int heap_size = BuildHeap(A, len);    // 建立一个最大堆
	while (heap_size > 1)
	{
		// 堆（无序区）元素个数大于1，未完成排序
		// 将堆顶元素与堆的最后一个元素互换，并从堆中去掉最后一个元素
		// 此处交换操作很有可能把后面元素的稳定性打乱，所以堆排序是不稳定的排序算法
		Swap(A, 0, --heap_size);
		Heapify(A, 0, heap_size);     // 从新的堆顶元素开始向下进行堆调整，时间复杂度O(logn)
	}
}

#pragma endregion