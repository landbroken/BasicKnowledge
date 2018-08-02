#include "stdafx.h"
#include<iostream>
#include <string>
#include<vector>
#include <algorithm>
using namespace std;

int test_HeChangDui()
{
	int N;
	while (cin >> N)
	{
		vector<int>data(N, 0);
		for (int i = 0; i < N; i++)
			cin >> data[i];
		//cout << endl;
		vector<int>dp_increase(N, 0);
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < i; j++)
				if (data[i] > data[j])
					dp_increase[i] = max(dp_increase[i], dp_increase[j] + 1);
		}
		vector<int>dp_decrease(N, 0);
		for (int i = N - 1; i >= 0; i--) {
			for (int j = i + 1; j < N; j++)
				if (data[j] < data[i])
					dp_decrease[i] = max(dp_decrease[i], dp_decrease[j] + 1);
		}


		for (int i = 0; i < N; i++) {
			dp_decrease[i] += dp_increase[i];
		}
		cout << N - (*max_element(dp_decrease.begin() + 1, dp_decrease.end() - 1) + 1) << endl;
	}
	return 0;
}
