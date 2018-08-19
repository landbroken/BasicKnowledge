#include"stdafx.h"

class Solution {
public:
	bool isValidRawColumn(unordered_set<char>& s, char tmp)
	{
		if (s.find(tmp) == s.end())
			s.insert(tmp);
		else
			return false;

		return true;
	}

	bool isValidSudoku(vector<vector<char>>& board) {
		unordered_set<char> raw, column;

		char tmp;
		for (int i = 0;i<board.size();i++)
		{
			raw.clear();
			column.clear();

			for (int j = 0;j<board[0].size();j++)
			{
				if (board[i][j] == '.')
					continue;

				//i行j列，对比i行
				tmp = board[i][j];
				if (!isValidRawColumn(raw, tmp))
				{
					return false;
				}

				for (int p = 0;p<3;p++)
				{
					for (int q = 0;q<3;q++)
					{
						if (i == i / 3 * 3 + p&&j == j / 3 * 3 + q)
							continue;
						if (tmp == board[i / 3 * 3 + p][j / 3 * 3 + q])
						{
							return false;
						}
					}
				}
			}
			for (int j = 0;j<board[0].size();j++)
			{
				if (board[j][i] == '.')
					continue;

				tmp = board[j][i];
				if (!isValidRawColumn(column, tmp))
				{
					return false;
				}
			}
		}
		return true;
	}
};
