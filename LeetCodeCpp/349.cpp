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
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ret;
		set<int> s1(nums1.begin(),nums1.end());
		set<int> s2(nums2.begin(), nums2.end());
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		set<int>::iterator it1 = s1.begin();
		set<int>::iterator it2 = s2.begin();
		while (it1 != s1.end() && it2 != s2.end())
		{
			if (*it1==*it2)
			{
				ret.push_back(*it1);
				it1++;
				it2++;
			}
			else if (*it1<*it2)
			{
				it1++;
			}
			else
			{
				it2++;
			}
		}
		return ret;
	}
};