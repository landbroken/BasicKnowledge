#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int W) {
		if (0!=hand.size()%W)
		{
			return false;
		}

		sort(hand.begin(), hand.end());

		vector<int>::iterator it = hand.begin();
		int len = hand.size() / W;
		it = hand.begin();
		for (size_t i = 0; i < len; i++)
		{
			int start = hand[0];
			int cnt = 0;
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
			if (cnt!=W)
			{
				return false;
			}
		}
		return true;
	}
};