#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int hammingDistance(int x, int y) {
		int tmp = x^y;
		int sum = 0;
		while (tmp != 0)
		{
			if (tmp & 1 != 0)
			{
				sum++;
			}
			tmp = tmp >> 1;
		}
		return sum;
	}
};