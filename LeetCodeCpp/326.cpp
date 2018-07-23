#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	/*
	所有的int范围的3的n次幂是int范围最大的3的n次幂数
	(即3^((int)log3(MAXINT)) =  1162261467)的约数
	即3^19=0100 0101 0100 0110 1011 0011 1101 1011
	*/
	bool isPowerOfThree(int n) {
		if (n>0) return 1162261467 % n == 0;
		else return false;
	}
};