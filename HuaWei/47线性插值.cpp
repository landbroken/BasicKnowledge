#include "stdafx.h"

void Output(int key, int val)
{
	cout << key << " " << val << endl;
}

int test_47()
{
	int m, n;
	while (cin >> m >> n)
	{
		vector<vector<int>> imap;
		vector<int> tmpvec(2, 0);
		int key, val, last_key = -1, last_val = -1;
		for (int i = 0;i<m;i++)
		{
			cin >> key >> val;
			//第一次
			if (last_key == -1)
			{
				Output(key, val);
			}
			//不记录重复的
			else if (last_key == key)
			{
				continue;
			}
			//递增，可能需要插值
			else if (key - last_key>1)
			{
				for (int j = 0;j<key - last_key - 1;j++)
				{
					int new_key = last_key + j + 1;
					int new_val = last_val + (val - last_val) / (key - last_key)*(j + 1);
					Output(new_key, new_val);
				}
				Output(key, val);
			}
			//不需要插值
			else
			{
				Output(key, val);
			}
			last_key = key;
			last_val = val;
		}
	}
	return 0;
}