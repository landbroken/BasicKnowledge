#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	int binaryGap(int N) {
		int maxGap = 0;
		int pre = -1;//前一个1的位置
		int cur = 0;//当前循环次数
		int next = 0;
		while (N != 0)
		{
			//当前位置是1，且忽略第一个1
			if (N & 1)
			{
				if (pre != -1) maxGap = maxGap>cur - pre ? maxGap : cur - pre;
				pre = cur;
			}
			N = N >> 1;
			cur++;
		}
		return maxGap;
	}
};