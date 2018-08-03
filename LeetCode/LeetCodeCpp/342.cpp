#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	bool isPowerOfFour(int num) {
		if (num <= 0) return false;
		if (num & (num - 1)) return false; // 先判断是否是 2 的 N 次方
		if (num & 0x55555555) return true; // 再将不是 4 的 N 次方的数字去掉
		return false;
	}
};