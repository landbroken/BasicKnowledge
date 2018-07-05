/*
4、斐波那契查找.cpp

@基本思想
也是二分查找的一种提升算法，通过运用黄金比例的概念在数列中选择查找点进行查找，
提高查找效率。同样地，斐波那契查找也属于一种有序查找算法。

相对于折半查找，一般将待比较的key值与第mid=（low+high）/2位置的元素比较，
比较结果分三种情况：

1）相等，mid位置的元素即为所求
2）>，low=mid+1;
3）<，high=mid-1。

斐波那契查找与折半查找很相似，他是根据斐波那契序列的特点对有序表进行分割的。
他要求开始表中记录的个数为某个斐波那契数小1，及n=F(k)-1;

开始将k值与第F(k-1)位置的记录进行比较(及mid=low+F(k-1)-1),比较结果也分为三种

1）相等，mid位置的元素即为所求
2）>，low=mid+1,k-=2;
说明：low=mid+1说明待查找的元素在[mid+1,high]范围内，
k-=2 说明范围[mid+1,high]内的元素个数为
n-(F(k-1))= Fk-1-F(k-1)=Fk-F(k-1)-1=F(k-2)-1
个，所以可以递归的应用斐波那契查找。
3）<，high=mid-1,k-=1。
说明：low=mid+1说明待查找的元素在[low,mid-1]范围内，
k-=1 说明范围[low,mid-1]内的元素个数为F(k-1)-1个，
所以可以递归的应用斐波那契查找。

@复杂度分析
最坏情况下，时间复杂度为O(log2n)，且其期望复杂度也为O(log2n)。
*/

#include "stdafx.h"
#include <memory>
#include  <iostream>
#include<search.h>
using namespace std;

const int max_size = 20;//斐波那契数组的长度

/*构造一个斐波那契数组*/
void Fibonacci(int * F)
{
	F[0] = 0;
	F[1] = 1;
	for (int i = 2;i<max_size;++i)
		F[i] = F[i - 1] + F[i - 2];
}

/*
@brief 斐波那契查找法
@参数
para=a为要查找的数组
para=n为要查找的数组长
para=key为要查找的关键字
*/
int FibonacciSearch(int *a, int n, int key)  
{
	int low = 0;
	int high = n - 1;

	int F[max_size];
	Fibonacci(F);//构造一个斐波那契数组F 

	int k = 0;
	while (n>F[k] - 1)//计算n位于斐波那契数列的位置
		++k;

	int  * temp;//将数组a扩展到F[k]-1的长度
	temp = new int[F[k] - 1];
	memcpy(temp, a, n * sizeof(int));

	for (int i = n;i<F[k] - 1;++i)
		temp[i] = a[n - 1];

	while (low <= high)
	{
		int mid = low + F[k - 1] - 1;
		if (key<temp[mid])
		{
			high = mid - 1;
			k -= 1;
		}
		else if (key>temp[mid])
		{
			low = mid + 1;
			k -= 2;
		}
		else
		{
			if (mid<n)
				return mid; //若相等则说明mid即为查找到的位置
			else
				return n - 1; //若mid>=n则说明是扩展的数值,返回n-1
		}
	}
	delete[] temp;
	return -1;
}