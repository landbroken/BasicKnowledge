#include "stdafx.h"

/*
给定一个 32 位有符号整数，将整数中的数字进行反转。

示例 1:

输入: 123
输出: 321
示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。
*/
class Solution {
public:
	int reverse(int x) {
		int ret = 0;
		int flag = 1;
		if (x<0) flag = -1;

		while (x != 0)
		{
			if (ret>INT_MAX / 10) return 0;
			if (ret<INT_MIN / 10) return 0;
			ret = ret * 10 + x % 10;
			x /= 10;
		}
		return ret;
	}
};
