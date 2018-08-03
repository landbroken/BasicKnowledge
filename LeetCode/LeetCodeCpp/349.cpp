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
		// 对数组1进行排序 
		sort(nums1.begin(), nums1.end());
		// 对数组2进行排序
		sort(nums2.begin(), nums2.end());
		set<int> s1(nums1.begin(), nums1.end());
		set<int> s2(nums2.begin(), nums2.end());
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