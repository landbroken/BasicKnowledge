#include "stdafx.h"
#include "HuaWei.h"
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

bool isOutNum(int *push, int *pop, int len)//判断pop是不是push的出栈序列
{
	if (push == NULL || pop == NULL || len <= 0)
		return false;
	stack<int> Stack;
	int i = 0, j = 0;
	for (i = 0;i<len;i++)//依次把push中的数入栈
	{
		Stack.push(push[i]);
		while (j<len && Stack.size() != 0 && pop[j] == Stack.top())//依次判断pop序列每个值是否与栈顶相等
		{
			Stack.pop();
			j++;
		}
	}
	return Stack.empty();
}

int test_火车进站()
{
	int N;
	while (cin >> N)
	{
		int *pushNum = new int[N];
		int *popNum = new int[N];
		for (int i = 0;i<N;i++)
		{
			cin >> pushNum[i];
			popNum[i] = pushNum[i];
		}
		sort(popNum, popNum + N);

		vector<int> vec(N);
		for (size_t i = 0; i < vec.size(); i++)
		{
			vec[i] = popNum[i];
		}

		do
		{
			if (isOutNum(pushNum, popNum, N))//如果该排列正确，则输出
			{
				for (int i = 0;i<N - 1;i++)
					cout << popNum[i] << " ";
				cout << popNum[N - 1] << endl;
			}
		} while (next_permutation(popNum, popNum + N));//获取下一个排列       
	}
	return 0;
}