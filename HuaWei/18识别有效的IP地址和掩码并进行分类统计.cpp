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

bool getInt(const string& str, int* arr)
{
	string tmp;
	int itmp = 0;
	size_t i = 0, j = 0;
	for (i = 0;i<str.size() && j <= 2;i++)
	{
		if (str.at(i) == '.') {
			char* offset;
			itmp = strtol(tmp.c_str(), &offset, 10);
			if (itmp == 0)
			{
				if (tmp != "0") return false;
				else arr[j++] = itmp;
			}
			else
				arr[j++] = itmp;

			tmp.clear();
		}
		else
			tmp += str.at(i);
	}
	tmp = str.substr(i, str.size() - 1);
	char* offset;
	itmp = strtol(tmp.c_str(), &offset, 10);
	if (itmp == 0)
	{
		if (tmp != "0")
			return false;
		else
			arr[j++] = itmp;
	}
	else
		arr[j++] = itmp;
	//arr[j++]=stol(tmp,nullptr,10);
	return true;
}

bool MaskIsValid2(vector<string> svec) {
	bool zero = false;
	if (svec.size() != 4)
	{
		return false;
	}
	for (int i = 0; i < 4; i++)
	{
		if (zero == false)
		{
			if (atoi(svec[i].c_str()) != 255)
			{
				if (atoi(svec[i].c_str()) != 0 &&   // 0000 0000
					atoi(svec[i].c_str()) != 128 && // 1000 0000
					atoi(svec[i].c_str()) != 192 && // 1100 0000
					atoi(svec[i].c_str()) != 224 && // 1110 0000
					atoi(svec[i].c_str()) != 240 && // 1111 0000
					atoi(svec[i].c_str()) != 248 && // 1111 1000
					atoi(svec[i].c_str()) != 252 && // 1111 1100
					atoi(svec[i].c_str()) != 254)   // 1111 1110
				{
					return false;
				}
				else
				{
					zero = true;
				}
			}
		}
		else
		{
			if (atoi(svec[i].c_str()) != 0)
			{
				return false;
			}
		}
	}
	if (atoi(svec[3].c_str()) == 255)
	{
		return false;
	}
	return true;
}

bool IpIsValid(int* arr)
{
	for (int i = 0;i<4;i++)
	{
		if (arr[i]>255 || arr[i]<0) return false;
	}
	return true;
}

bool IpIsPrivate(int* arr)
{
	if (arr[0] == 10)return true;
	else if (arr[0] == 172)
	{
		if (arr[1] <= 31 && arr[1] >= 16) return true;
	}
	else if (arr[0] == 192 && arr[1] == 168)
	{
		return true;
	}
	return false;
}

bool IpIsA(int* arr)
{
	if (arr[0] >= 1 && arr[0] <= 126)return true;
	return false;
}
bool IpIsB(int* arr)
{
	if (arr[0] >= 128 && arr[0] <= 191)return true;
	return false;
}
bool IpIsC(int* arr)
{
	if (arr[0] >= 192 && arr[0] <= 223)return true;
	return false;
}
bool IpIsD(int* arr)
{
	if (arr[0] >= 224 && arr[0] <= 239)return true;
	return false;
}
bool IpIsE(int* arr)
{
	if (arr[0] >= 240 && arr[0] <= 255)return true;
	return false;
}

int test_18()
{
	string str, ip, mask;
	int a = 0, b = 0, c = 0, d = 0, e = 0, err = 0, pri = 0;
	while (getline(cin, str))
	{
		int ip_arr[4] = { -1,-1,-1,-1 }, mask_arr[4] = { -1,-1,-1,-1 };//地址和子网掩码第i位
		int mid = str.find('~');
		ip = str.substr(0, mid);
		mask = str.substr(mid + 1, str.size() - 1 - mid);

		if (!getInt(ip, ip_arr))
		{
			err++;
			continue;
		}
		if (!getInt(mask, mask_arr))
		{
			err++;
			continue;
		}
		vector<string> mask_vec(4);
		mask_vec[0] = to_string(mask_arr[0]);
		mask_vec[1] = to_string(mask_arr[1]);
		mask_vec[2] = to_string(mask_arr[2]);
		mask_vec[3] = to_string(mask_arr[3]);
		if (!MaskIsValid2(mask_vec) || !IpIsValid(ip_arr))
		{
			err++;
			continue;
		}

		if (IpIsA(ip_arr))
		{
			if (IpIsPrivate(ip_arr)) pri++;
			a++;
		}
		else if (IpIsB(ip_arr))
		{
			if (IpIsPrivate(ip_arr)) pri++;
			b++;
		}
		else if (IpIsC(ip_arr))
		{
			if (IpIsPrivate(ip_arr)) pri++;
			c++;
		}
		else if (IpIsD(ip_arr))
		{
			d++;
		}
		else if (IpIsE(ip_arr))
		{
			e++;
		}
	}
	cout << a << " " << b << " " << c << " " << d << " " << e << " " << err << " " << pri << endl;
	return 0;
}