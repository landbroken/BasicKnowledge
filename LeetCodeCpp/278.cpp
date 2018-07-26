#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version)
{
	return version >= 1792997410;
}

class Solution {
public:
	int BinarySearch(int n)
	{
		int low, high, mid;
		low = 1;
		high = n;
		while (low <= high)
		{
			//二分（折半），即mid=low+1/2*(high-low);
			mid = low + (high - low) / 2;
			if (isBadVersion(mid) == true)
			{
				//说明后一半没有，定义新搜索终点
				high = mid - 1;
			}
			else
			{
				//说明前一半没有，定义新搜索起点
				low = mid + 1;
			}
		}
		//说明没有
		return low;
	}

	int firstBadVersion(int n) {
		return BinarySearch(n);
	}
};

/*
//最接近int加法溢出的
//0x7FFF FFFF + 0x7FFF FFFF = 0xFFFF FFFE
*/
int test_278(int n)
{
	Solution s;
	int bad = s.firstBadVersion(n);
	cout << " " << bad << " " << endl;
	return bad;
}