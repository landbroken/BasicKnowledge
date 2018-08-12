#include "stdafx.h"
#include "HuaWei.h"
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <cctype>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

/*
清一色是麻将番种之一，指由一种花色的序数牌组成的和牌。
数字1-9，每个数字最多有4张牌
我们不考虑具体花色，我们只看数字组合。
刻子：三张一样的牌；如: 111, 222, 333, ..., 999
顺子：三张连续的牌；如: 123, 234, 345, ..., 789
对子：两张相同的牌；如: 11, 22, 33, ..., 99
需要实现一个程序，判断给定牌，是否可以和牌（胡牌）。

和牌要求:
- 麻将牌张数只能是 2, 5, 8, 11, 14
- 给定牌可以组合成，除1个对子以外其他都是刻子或顺子
举例： - "11" -> "11", 1对子，可以和牌
- "11122233" -> "111"+"222"+"33", 2刻子，1对子，可以
- "11223344567" -> "11"+"234"+"234"+"567", 1对子，3顺子，可以
-> "123"+"123"+"44"+"567", 另一种组合，也可以

输入描述:
合法C字符串，只包含'1'-'9'，且已经按从小到大顺序排好；字符串长度不超过15。同一个数字最多出现4次，与实际相符。

输出描述:
C字符串，"yes"或者"no"
*/

int test_清一色()
{
	string str;
	while (cin >> str)
	{
		//张数不符合
		if (str.size()!=2 && str.size() != 5 && str.size() != 8
			&& str.size() != 11 && str.size() != 14)
		{
			cout << "no" << endl;
			continue;
		}
		//正好两张
		if (str.size()==2)
		{
			if (str[0]==str[1])
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
			continue;
		}

		bool flag = false;
		for (size_t i = 0; i < str.size() - 1; i++)
		{
			if (str[i]==str[i+1])
			{
				flag = false;
				//有对子，考虑深度优先遍历其余牌
				//未遍历的字符
				string tmp = str.substr(0, i) + str.substr(i + 2);
				//遍历全排列
				do
				{
					int kezi = 0, shunzi = 0;
					flag = false;
					for (size_t j = 0; j < tmp.size()-2;)
					{
						if (tmp[j]==tmp[j+1]&&tmp[j+1]==tmp[j+2])
						{
							kezi++;
							j += 3;
						}
						else if(tmp[j]+1==tmp[j+1]&&tmp[j+1]+1==tmp[j+2])
						{
							shunzi++;
							j += 3;
						}
						else
						{
							j++;
						}
					}
					//都是kezi和顺子
					if (kezi*3+shunzi*3== tmp.size())
					{
						flag = true;
						break;
					}
				} while (next_permutation(tmp.begin(), tmp.end()));
				if (flag)
				{
					break;
				}
			}
		}
		if (flag)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
	return 0;
}