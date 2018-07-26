#include "stdafx.h"
#include <vector>
using namespace std;

/*
位1的个数
编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。

示例 :

输入: 11
输出: 3
解释: 整数 11 的二进制表示为 00000000000000000000000000001011


示例 2:

输入: 128
输出: 1
解释: 整数 128 的二进制表示为 00000000000000000000000010000000
*/
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int sum = 0;
		while (n != 0)
		{
			if (n & 1)sum++;
			n = n >> 1;
		}
		return sum;
	}
};