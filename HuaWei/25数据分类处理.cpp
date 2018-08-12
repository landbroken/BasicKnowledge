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

int CountRightNum(const int& val, const vector<long> &vec, vector<long> &ret)
{
	string tmp;
	string strVal = to_string(val);
	for (size_t i = 0;i<vec.size();i++)
	{
		tmp = to_string(vec[i]);
		for (size_t j = 0;j<tmp.size() - strVal.size() + 1;j++)
		{
			if (tmp[j] == strVal[0])
			{
				bool isSame = true;
				for (size_t k = 1;k<strVal.size();k++)
				{
					if (tmp[j + k] != strVal[k])
					{
						isSame = false;
						break;
					}
				}
				if (isSame)
				{
					ret.push_back(i);
					ret.push_back(vec[i]);
					break;
				}
			}
		}
	}
	return ret.size() / 2;
}

int main()
{
	int iNum, rNum;
	//输入
	while (cin >> iNum)
	{
		long tmp;
		vector<long> ivec(iNum, 0);//储存序列i
		vector<long> ret;//最后输出的存储
		vector<long> tmpvec;//临时存储
		for (int i = 0;i<iNum;i++)
		{
			cin >> ivec[i];
		}
		cin >> rNum;
		set<long> rset;//储存序列r
		for (int i = 0;i<rNum;i++)
		{
			cin >> tmp;
			rset.insert(tmp);
		}

		//判断
		//sort(rvec.begin().rvec.end());
		for (auto it = rset.begin();it != rset.end();it++)
		{
			CountRightNum(*it, ivec, tmpvec);
			if (tmpvec.size()>0)
			{
				ret.push_back(*it);
				ret.push_back(tmpvec.size() / 2);
				for (int i = 0;i<tmpvec.size();i++)
				{
					ret.push_back(tmpvec[i]);
				}
			}
			tmpvec.clear();
		}

		//输出
		cout << ret.size() << " ";
		for (size_t i = 0;i<ret.size() - 1;i++)
		{
			cout << ret[i] << " ";
		}
		cout << ret[ret.size() - 1] << endl;
	}
	return 0;
}