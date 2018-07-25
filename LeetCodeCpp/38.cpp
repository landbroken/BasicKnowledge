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
	string getNext(string s)
	{
		string result;
		int i = 0;
		int count;
		while (i < s.size())
		{
			count = 1;
			char temp;
			if (s[i] == s[i + 1])
			{
				while (s[i] == s[i + 1])
				{
					count++;
					i++;
				}
				temp = count + '0';
				result = result + temp + s[i];
				i++;
			}
			else
			{
				temp = '1';
				result = result + temp + s[i];
				i++;
			}
		}
		return result;
	}

	string countAndSay(int n) {
		if (n == 1)
			return "1";
		string s = "1";
		while (--n)
		{
			s = getNext(s);
		}
		return s;

	}
};