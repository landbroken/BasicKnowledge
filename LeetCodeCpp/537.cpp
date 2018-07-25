#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include "LeetCodeCppTest.h"
using namespace std;

class Solution {
public:
	int GetReal(string& str,int plus)
	{
		string ret = str.substr(0, plus);
		return stoi(ret);
	}

	int GetImaginary(string& str, int plus)
	{
		string ret = str.substr(plus+1, str.size() - plus - 2);
		return stoi(ret);
	}

	string complexNumberMultiply(string a, string b) {
		int tmp = a.find("+");
		int realA = GetReal(a, tmp);
		int imaginaryA = GetImaginary(a, tmp);
		tmp = b.find("+");
		int realB = GetReal(b, tmp);
		int imaginaryB = GetImaginary(b, tmp);

		int real = realA*realB+ imaginaryA*imaginaryB*(-1);
		int imaginary = realA*imaginaryB + realB*imaginaryA;
		return to_string(real) + "+" + to_string(imaginary) + "i";
	}

};

int test_537()
{
	Solution s;
	s.complexNumberMultiply("20+22i", "-18+-10i");
	return 0;
}