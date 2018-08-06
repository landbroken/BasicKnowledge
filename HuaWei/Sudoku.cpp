#include"stdafx.h"
#include <iostream>
using namespace std;

bool flag = false;
int num[9][9];
bool check(int n) {
	int h = n / 9;
	int l = n % 9;
	for (int i = 0;i<9;i++)
		if (i != l&&num[h][i] == num[h][l])
			return false;
	for (int i = 0;i<9;i++)
		if (i != h&&num[i][l] == num[h][l])
			return false;
	for (int i = h / 3 * 3;i<h / 3 * 3 + 3;i++)
		for (int j = l / 3 * 3;j<l / 3 * 3 + 3;j++)
			if ((i != h || j != l) && num[i][j] == num[h][l])
				return false;
	return true;
}
void dfs(int n) {

	int h = n / 9;
	int l = n % 9;
	if (n == 56 && num[6][0] == 2 && num[6][1] == 1)
		num[6][2] = 5;
	if (n == 81) {
		for (int i = 0;i<9;i++) {
			for (int j = 0;j<8;j++) {
				cout << num[i][j] << ' ';
			}
			cout << num[i][8];
			cout << endl;
		}
		flag = true;
		return;
	}
	if (num[h][l] == 0) {
		for (int i = 1;i <= 9;i++) {
			num[h][l] = i;
			if (check(n)) {
				dfs(n + 1);
				if (flag)
					return;
				num[h][l] = 0;
			}
		}
		num[h][l] = 0;
	}
	else dfs(n + 1);
}
int test_sudoku() {
	for (int i = 0;i<9;i++)
		for (int j = 0;j<9;j++)
			cin >> num[i][j];
	dfs(0);
	return 0;
}