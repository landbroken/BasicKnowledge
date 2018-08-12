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

struct error_codes {
	string filename;
	int codeline;
	int counter = 1;
	bool operator==(const error_codes &a) {
		if (a.filename == filename&&a.codeline == codeline)
			return true;
		else
			return false;
	}
};

string getfilename(string f) {  //从地址字符串中，获取最后的文件名
	int begin = f.find_last_of('\\');
	string result = f.substr(begin + 1, f.size() - begin - 1);

	if (result.size()>16)
		result = result.substr(result.size() - 16, 16);
	return result;
}

int test_19()
{
	vector<error_codes> inputnumber;
	string filename;
	int codeline = 0;
	int i = 0;

	while (cin >> filename >> codeline)
	{
		error_codes temp;
		vector<error_codes>::iterator res;
		temp.filename = getfilename(filename);
		temp.codeline = codeline;

		res = find(inputnumber.begin(), inputnumber.end(), temp);
		if (res == inputnumber.end())
		{
			//temp不在inpunumber数组中
			inputnumber.push_back(temp);
		}
		else
		{
			res->counter++;
		}
		++i;
	}
	int j = 0;
	if (inputnumber.size()>8)
		j = inputnumber.size() - 8;
	for (j;j<inputnumber.size();++j) {
		cout << inputnumber[j].filename << " " << inputnumber[j].codeline << " " << inputnumber[j].counter << endl;
	}
	return 0;
}