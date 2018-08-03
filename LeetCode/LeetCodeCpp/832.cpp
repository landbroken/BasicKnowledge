#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	void swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	vector<vector<int>> flipImage(vector<vector<int>>& A) {
		size_t raw = A.size();
		size_t column = A[0].size();

		for (size_t i = 0; i < raw; i++)
		{
			for (size_t j = 0; j < column/2; j++)
			{
				swap(A[i][j], A[i][column-j-1]);
			}
		}

		return A;
	}

	vector<vector<int>> InvertImage(vector<vector<int>>& A) {
		size_t raw = A.size();
		size_t column = A[0].size();

		for (size_t i = 0; i < raw; i++)
		{
			for (size_t j = 0; j < column; j++)
			{
				A[i][j] = 1 - A[i][j];
			}
		}

		return A;
	}

	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		size_t raw = A.size();
		size_t column = A[0].size();

		flipImage(A);
		InvertImage(A);
		return A;
	}
};