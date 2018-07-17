// string.cpp : 定义控制台应用程序的入口点。
// 标准C++中string类，必须要#include<string>和using namespace std;
// 然后就可以用string/wstring了，它们两分别对应着char和wchar_t
// 主要参考文献
// 1、标准C++中的string类的用法总结（转） 
// http://www.cnblogs.com/xFreedom/archive/2011/05/16/2048037.html

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

	cout << endl << "InitialDemo:" << endl;
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
}

/*
赋值和替换demo
*/
void AssignReplaceDemo()
{
	cout << endl << "AssignReplaceDemo:" << endl;

	string str1, str2 = "War and Peace";
	str1.assign(str2, 4, 3);
	cout << str1 << endl;

	string s = "They say he carved it himself...from a BIGGER spoon";
	string s2 = "find your soul-mate, Homer.";

	s.replace(5, s2.length(), s2);
	//结果为"They say he carved it himself...find your soul-mate, Homer."
	cout << s << endl;

}

void Change2CharDemo()
{
	cout << endl << "Change2CharDemo:" << endl;

	string str1 = "War and Peace";
	const char* chr = str1.c_str();
	cout << chr << endl;
}

int main()
{
	InitialDemo();
	AssignReplaceDemo();
	Change2CharDemo();
	system("pause");
    return 0;
}

