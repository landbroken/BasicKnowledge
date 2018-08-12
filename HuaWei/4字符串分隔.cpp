#include "stdafx.h"
#include "HuaWei.h"
#include<iostream>
#include<set>
#include<string>
using namespace std;

void str_handler(string& s) {
	if (s.size() <= 8)
	{
		s.append(8 - s.size(), '0');
		cout << s << endl;
	}
	else
	{
		cout << s.substr(0, 8) << endl;
		string s1 = s.substr(8, s.size() - 8);
		str_handler(s1);
	}
}

int test_4()
{
	string s1, s2;
	while (cin >> s1 >> s2) {
		str_handler(s1);
		str_handler(s2);
	}
	return 0;
}