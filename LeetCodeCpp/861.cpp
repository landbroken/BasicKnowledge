#include "stdafx.h"
#include <vector>
using namespace std;

/*
861. 翻转矩阵后的得分
https://blog.csdn.net/wez031113/article/details/80914083

解题思路：

返回尽可能高分这个要求，理解为对同一组数，高位尽可能置1，对不同组的相同位尽可能多的置1。

上述即为本代码的流程：

1，判断最高位是否为1，否，移动当前行。

2，判断每列的的0的个数，如果0较多，移动当前列。

3，输出最高分数。
*/
class Solution {
public:
	int matrixScore(vector<vector<int>>& A) {
		int row = A.size();
		int cloumn = A[0].size();
		for (int i = 0; i < row; i++)
		{
			if (A[i][0] == 0)
			{
				for (int j = 0; j < cloumn; j++)
				{
					A[i][j] = 1 - A[i][j];
				}
			}
		}
		for (int j = 0; j < cloumn; j++)
		{
			int coutZero = 0;
			for (int i = 0; i < row; i++)
			{
				if (A[i][j] == 0)coutZero++;
			}
			int coutOne = row - coutZero;
			if (coutZero > coutOne)
			{
				for (int m = 0; m < row; m++)
				{
					A[m][j] = 1 - A[m][j];
				}
			}
		}

		int sum = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < cloumn; j++)
			{
				sum += A[i][j] * pow(2, (cloumn - j - 1));
			}
		}
		return sum;
	}
};