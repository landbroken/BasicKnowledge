#include "stdafx.h"
#include "HuaWei.h"
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <cctype>
#include <cmath>
#include <algorithm>
using namespace std;

const string helper1 = "0123456789abcdefABCDEF";
const string helper2 = "084C2A6E195D3B7F5D3B7F";

int test_30() {
	string str1, str2;
	while (cin >> str1 >> str2) {
		string s, s1, s2;
		s = str1 + str2;
		int len = s.size();
		for (int i = 0; i < len; ++i) {
			if (i % 2 == 0)
				s1 += s[i];
			else
				s2 += s[i];
		}
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		s.clear();
		for (int i = 0, j = 0, k = 0; i < len; ++i) {
			if (i % 2 == 0)
				s += s1[j++];
			else
				s += s2[k++];
		}
		for (int i = 0; i < len; ++i) {
			int n = helper1.find(s[i]);
			if (n != -1)
				s[i] = helper2[n];
		}
		cout << s << endl;
	}
	return 0;
}