#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

/*
LeetCode（78）：子集
https://www.cnblogs.com/ariel-dreamland/p/9154503.html
*/
class Solution {
public:

#pragma region 方法1

	vector<vector<int> > subsets_Method1(vector<int> &S) {
		vector<vector<int> > res(1);
		sort(S.begin(), S.end());
		for (int i = 0; i < S.size(); ++i) 
		{
			int size = res.size();
			for (int j = 0; j < size; ++j) 
			{
				res.push_back(res[j]);
				res.back().push_back(S[i]);
			}
		}
		return res;
	}

#pragma endregion

#pragma region 方法2

	vector<vector<int> > subsets_Method2(vector<int> &S) {
		vector<vector<int> > res;
		vector<int> out;
		sort(S.begin(), S.end());
		getSubsets(S, 0, out, res);
		return res;
	}
	void getSubsets(vector<int> &S, int pos, vector<int> &out, vector<vector<int> > &res) {
		res.push_back(out);
		for (int i = pos; i < S.size(); ++i) {
			out.push_back(S[i]);
			getSubsets(S, i + 1, out, res);
			out.pop_back();
		}
	}

#pragma endregion

#pragma region 方法3

	vector<vector<int> > subsets_Method3(vector<int> &S) {
		vector<vector<int> > res;
		sort(S.begin(), S.end());
		int max = 1 << S.size();
		for (int k = 0; k < max; ++k) {
			vector<int> out = convertIntToSet(S, k);
			res.push_back(out);
		}
		return res;
	}
	vector<int> convertIntToSet(vector<int> &S, int k) {
		vector<int> sub;
		int idx = 0;
		for (int i = k; i > 0; i >>= 1) {
			if ((i & 1) == 1) {
				sub.push_back(S[idx]);
			}
			++idx;
		}
		return sub;
	}

#pragma endregion

};