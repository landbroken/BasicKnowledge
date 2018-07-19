#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int findComplement(int num) {
		int result = num, mask = 1;
		while (result != 1)
		{
			result = result >> 1;
			mask = (mask << 1) + 1; //将有数的位置上全部置为一
		}
		return  num^mask; //抑或，不同的为1相同的为0，相当于取反
	}
};