#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int length = nums.size();
		if (length == 0)
			return;
		int i = -1;
		int j = 0;
		while (nums[++i]);//i是第一个0所在的位置。
		for (j = i + 1;j<length;j++) {
			if (nums[j]) {
				nums[i++] = nums[j];
			}
		}
		while (i<length)
			nums[i++] = 0;
		return;
	}
};