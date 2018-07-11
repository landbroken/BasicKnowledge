// LeetCodeCpp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int W) {
		if (0 != hand.size() % W)
		{
			return false;
		}

		sort(hand.begin(), hand.end());

		vector<int>::iterator it = hand.begin();
		int len = hand.size() / W;
		for (size_t i = 0; i < len; i++)
		{
			int start = hand[0];
			int cnt = 0;
			it = hand.begin();
			while (cnt<W&&it != hand.end())
			{
				if (*it == start + cnt)
				{
					it = hand.erase(it);
					cnt++;
				}
				else
				{
					it++;
				}
			}
			if (cnt != W)
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	vector<int> hand = { 1,2,3,6,2,3,4,7,8 };
	int W = 3;
	Solution s;
	s.isNStraightHand(hand, W);
    return 0;
}

