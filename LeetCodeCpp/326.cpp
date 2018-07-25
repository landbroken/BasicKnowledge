#include "stdafx.h"
#include <vector>
using namespace std;

/*
3的幂
给定一个整数，写一个函数来判断它是否是 3 的幂次方。

示例 1:

输入: 27
输出: true
示例 2:

输入: 0
输出: false
示例 3:

输入: 9
输出: true
示例 4:

输入: 45
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？
*/
class Solution {
private:
	bool method1(int n)
	{
		if (n <= 1) {
			return n >= 1;
		}
		while (n % 3 == 0) {
			n /= 3;
		}
		return n == 1;
	}

	/*
	所有的int范围的3的n次幂是int范围最大的3的n次幂数
	(即3^((int)log3(MAXINT)) =  1162261467)的约数
	即3^19=0100 0101 0100 0110 1011 0011 1101 1011
	*/
	bool method2(int n)
	{
		if (n>0) return 1162261467 % n == 0;
		else return false;
	}
public:

	bool isPowerOfThree(int n) {
		return method2(n);
	}
};