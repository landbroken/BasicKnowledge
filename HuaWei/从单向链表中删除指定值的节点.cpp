#include"stdafx.h"
#include"HuaWei.h"
#include<list>
#include<iostream>
using namespace std;

int test_shan_chu_zhi_ding_zhi_de_jie_dian()
{
	int n;
	while (cin >> n)
	{
		int val, last;
		list<int> li;
		list<int>::iterator it22;
		cin >> val;
		li.insert(li.begin(), val);
		for (int i = 1;i<n;i++)
		{
			cin >> val >> last;
			for (auto it = li.begin();it != li.end();it++)
			{
				if ((*it) == last)
				{
					auto it2 = it;
					if ((++it2) == li.end())
					{
						li.push_back(val);
					}
					else
					{
						li.insert(it2, val);
					}
					break;
				}
			}
		}
		//É¾³ı
		cin >> last;
		for (auto it = li.begin();it != li.end();it++)
		{
			if ((*it) == last)
			{
				it = li.erase(it);
				break;
			}
		}
		//Êä³ö
		for (auto it = li.begin();it != li.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	return 0;
}