#include "stdafx.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	string toLowerCase(string str) {
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] >= 'A'&&str[i] <= 'Z')
			{
				char tmp = str[i] - 'A' + 'a';
				//•用str中的num2个字符（从index2开始）替换本字符串中的字符，从index1开始，num1个字符
				//_Myt& replace(size_type _Off,size_type _N0, size_type _Count, _Elem _Ch)
			    //replace [_Off, _Off + _N0) with _Count * _Ch
				str.replace(i, 1, 1, tmp);
			}
		}
		return str;
	}
};

int test_709()
{
	Solution s;
	string str("ZzPiTAs");
	cout << str.c_str() << endl;
	str = s.toLowerCase(str);
	cout << str.c_str() << endl;
	return 0;
}
