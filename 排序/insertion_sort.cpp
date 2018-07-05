#include "stdafx.h"
#include "sort.h"
#include<math.h>
using namespace std;

/*
@brief 直接插入排序
@基本思想
和交换排序不同的是它不用进行交换操作，而是用一个临时变量存储当前值。
当前面的元素比后面大时，先把后面的元素存入临时变量，前面元素的值放到后面元素
位置，再到最后把其值插入到合适的数组位置。

@分析
最坏时间复杂度为数组为逆序时，为O(n^2)。最优时间复杂度为数组正序时，为O(n)。
平均时间复杂度为O(n^2)。辅助空间O(1)。稳定性：稳定。
*/
void InsertionSort(int* data, int length)
{
	int preIndex;
	for (int i = 1; i < length; i++)
	{
		preIndex = i - 1;
		int current = data[i];
		while (preIndex >= 0 && (data[preIndex] > current))
		{
			data[preIndex + 1] = data[preIndex];//大数后移一位，空出空间
			preIndex--;
		}
		data[preIndex + 1] = current;//把取出来的数放在小数后面
	}
}

//    希尔排序调用的直接插入排序，当dk=1时即为直接插入排序
//    进行插入排序
//    初始时从dk开始增长，每次比较步长为dk
void InsertionSort(int* data, int length,int dk)
{
	int preIndex;
	for (int i = dk; i < length; i++)
	{
		preIndex = i - dk;
		int current = data[i];
		while (preIndex >= 0 && (data[preIndex] > current))
		{
			swap(&data[preIndex+dk], &data[preIndex]);//大数后移dk位，空出空间
			preIndex -= dk;
		}
		data[preIndex + dk] = current;//把取出来的数放在小数后面
	}
}

/*
@brief 二分插入排序
如果比较操作的代价比交换操作大的话，可以采用二分查找法来减少比较操作的次数

// 分类 -------------- 内部排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
*/
void InsertionSortDichotomy(int* A, int len)
{
	for (int i = 1; i < len; i++)
	{
		int get = A[i];                  // 右手抓到一张扑克牌
		int left = 0;                    // 拿在左手上的牌总是排序好的，所以可以用二分法
		int right = i - 1;               // 手牌左右边界进行初始化
		while (left <= right)            // 采用二分法定位新牌的位置
		{
			int mid = (left + right) / 2;
			if (A[mid] > get)
				right = mid - 1;
			else
				left = mid + 1;
		}
		for (int j = i - 1; j >= left; j--)    // 将欲插入新牌位置右边的牌整体向右移动一个单位
		{
			A[j + 1] = A[j];
		}
		A[left] = get;                    // 将抓到的牌插入手牌
	}
}


/*
@brief 希尔排序
@describe
是简单插入排序的改进版。希尔排序又叫缩小增量排序。

基本思想为在直接插入排序的思想下设置一个最小增量dk,刚开始dk设置为n/2。
进行插入排序，随后再让dk=dk/2,再进行插入排序，直到dk为1时完成最后一次插入排序，此时数组完成排序。

最坏时间复杂度为O(n^2)；最优时间复杂度为O(n)；平均时间复杂度为O(n^1.3)。辅助空间O(1)。稳定性：不稳定。
希尔排序的时间复杂度与选取的增量有关，选取合适的增量可减少时间复杂度。

*/
void ShellSort(int* data, int n) 
{
	int dk = n / 2;        //    设置初始dk
	while (dk >= 1) 
	{
		InsertionSort(data, n, dk);
		dk /= 2;
	} 
}
