// string.cpp : 定义控制台应用程序的入口点。
// 标准C++中string类，必须要#include<string>和using namespace std;
// 然后就可以用string/wstring了，它们两分别对应着char和wchar_t
// 主要参考文献
// 1、标准C++中的string类的用法总结（转） 
// http://www.cnblogs.com/xFreedom/archive/2011/05/16/2048037.html

#include "stdafx.h"
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
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
	char chr[6];
	memset(chr, '\0', sizeof(chr));
	chr[0] = '2';
	string str5(chr);

	cout << endl << "InitialDemo:" << endl;
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
	cout << str5 << endl;
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
	//s[1] = "1";不能用这种形式
	//replace(off,number,new string)
	s.replace(5, s2.length(), s2);
	//char* p;char c = s[0];p = &c;
	//s.replace(5, 1, p);
	//结果为"They say he carved it himself...find your soul-mate, Homer."
	cout << s << endl;

}

string ReverseStringDemo(string s) 
{
	int left = 0, right = s.size() - 1;
	while (left < right) 
	{
		char t = s[left];
		s[left++] = s[right];
		s[right--] = t;
	}
	return s;
}

string ReverseStringDemo2(string s) {
	int left = 0, right = s.size() - 1;
	while (left < right) {
		swap(s[left++], s[right--]);
	}
	return s;
}

void Change2CharDemo()
{
	cout << endl << "Change2CharDemo:" << endl;

	string str1 = "War and Peace";
	const char* chr = str1.c_str();
	cout << chr << endl;
}

void Change2IntDemo()
{
	string str1 = "-20";
	string str2 = "5";
	int ret = stoi(str1) + stoi(str2);
	cout << "string to int: -20+5=" << ret << " " << endl;

	int a = -3, b = 37;
	string a_plus_b = to_string(a + b);
	cout << "int to string: -3+37=" << a_plus_b << " " << endl;

	string str3 = "-0x12";
	string str4 = "0x76E";//1902
	char *offset;
	cout << "string to int: -0x12=" << strtol(str3.c_str(),&offset,0) << " " << endl;
	cout << "string to int: 0x76E=" << strtol(str4.c_str(), &offset, 0) << " " << endl;
	cout << "string to int: 0x76E=" << stol(str4, nullptr,0) << " " << endl;
	string str5 = "A4";
	char *offset5;
	int istr5 = strtol(str5.c_str(), &offset5, 10);
	cout << "string to int: A4=" << istr5 << " " << endl;//0
}

void SubStringDemo()
{
	string str = "20+-22i";
	int size = str.size();
	int plus = str.find("+");
	string real = str.substr(0, plus);//off,count
	string imaginary = str.substr(plus + 1, size - plus - 2);
	cout << "substring: " << real << " " << imaginary << endl;
}

void FindDemo()
{
	string str;
	cout << "FindDemo: please cin words and find spaces "<<endl;
	getline(cin, str);
	//hello world=5
	//helloworld=-1=string
	int begin = str.find(' ');
	int end = str.find_last_of(' ');//hello world =5
	string last(str, end + 1, str.size() - end);
	cout << last<<" "<<last.size() << endl;;
}

void AddDemo()
{
	cout << "AddDemo" << endl;
	string str = "";
	str += "5";
	cout << str << endl;
	str.append("11");
	cout << str << endl;
	str.append(5,'0');
	cout << str << endl;
}

void CompareDemo()
{
	cout << "CompareDemo:" << endl;
	string str1("aaa");
	string str2("aab");
	string str3("aaaa");
	bool ret = str1 < str2;
	cout << ret << endl;
	ret = str1 < str3;
	cout << ret << endl;
	ret = str2 < str3;
	cout << ret << endl;

}

void WStringDemo()
{
	wstring wstr1;
	wstr1 = L"我ABC的string";
	wstring wstr2(L"我A的XX啊");
	int s1 = wstr1.size();
}

int main()
{
	WStringDemo();
	InitialDemo();
	AssignReplaceDemo();
	Change2CharDemo();
	Change2IntDemo();
	SubStringDemo();
	FindDemo();
	AddDemo();
	CompareDemo();
	system("pause");
    return 0;
}

