// string.cpp : 定义控制台应用程序的入口点。
// 标准C++中string类，必须要#include<string>和using namespace std;
// 然后就可以用string/wstring了，它们两分别对应着char和wchar_t

#include "stdafx.h"
#include<string>
#include<iostream>
using namespace std;

/*
初始化变量demo
*/
void InitialDemo()
{
	string str1(5, 'c');//初始化为5个'c'
	string str2("Now is the time...");
	string str3(str2, 11, 4);//从str2的第11个字符开始，读取4个字符
	string str4;
	str4.append(3, 'h');//增加3个'h'
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
}



int main()
{
	InitialDemo();
	system("pause");
    return 0;
}

