#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool judgeCircle(string moves) {
		int lr = 0, ud = 0;
		for (size_t i = 0; i < moves.size(); i++)
		{
			switch (moves[i])
			{
				case 'L':
					lr--;
					break;
				case 'R':
					lr++;
					break;
				case 'U':
					ud++;
					break;
				case 'D':
					ud--;
					break;
				default:
					break;
			}
		}
		if (lr==0&&ud==0)
		{
			return true;
		}
		return false;
	}
};