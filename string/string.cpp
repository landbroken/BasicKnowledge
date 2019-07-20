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
	if(str1[5]== '\0')
	{
		cout << "越界输出：str1[5]=\0" << endl;//空
	}
	else
	{
		cout << "越界输出：str1[5]=" << str1[5] << endl;//空
	}
	//cout << "越界输出：str1[6]=" << str1[6] << endl;//异常
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
	//结果为and
	cout << str1 << endl;

	string s = "They say he carved it himself...from a BIGGER spoon";
	string s2 = "find your soul-mate, Homer.";
	//s[1] = "1";不能用这种形式
	//replace(off,number,new string)
	//结果为They find your soul-mate, Homer.from a BIGGER spoon
	s.replace(5, s2.length(), s2);
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

/*
string转为char*类型
char*转为string类型
*/
void Change2CharDemo()
{
	cout << endl << "Change2CharDemo:" << endl;

	string str1 = "War and Peace";
	const char* chr = str1.c_str();
	cout << chr << endl;

	//定义成char chr2[10]是一样的
	char* chr2 = "to_string";
	string str2 = chr2;
	cout << str2 << endl;
}

/*
string转为Int类型
int转为string类型
*/
void Change2IntDemo()
{
	cout << endl << "Change2IntDemo" << endl;

	//stoi：string转int
	string str1 = "-20";
	string str2 = "5";
	int ret = stoi(str1) + stoi(str2);
	cout << "string to int: -20+5=" << ret << " " << endl;

	//to_string：数值转string
	int a = -3, b = 37;
	string a_plus_b = to_string(a + b);
	cout << "int to string: -3+37=" << a_plus_b << " " << endl;

	//strtol：string转long。_Radix表示进制。
	//stol：string转long，并做进制转换。Base=0时使用默认的十进制
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
	cout << endl << "AddDemo" << endl;
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
	cout << endl << "CompareDemo:" << endl;
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

/*
用空格分隔字符串示例
STL没有原生的split函数
*/
void SplitDemo() {
	cout << endl << "begin SplitDemo" << endl;
	string str = "hello world! this is a string.";
	vector<string> str_arr;
	string temp;
	int offset = 0;
	int newOffset = 0;
	//获取空格位置，没有空格时返回-1
	while (offset<str.size()&& newOffset>=0)
	{
		newOffset = str.find(' ', offset);
		temp = str.substr(offset, newOffset - offset);
		str_arr.push_back(temp);
		offset = newOffset + 1;
	}
	cout << "origin string = " << str << endl;
	cout << "split arr size = " << str_arr.size() << endl;
	for (int i = 0;i < str_arr.size();i++) {
		cout << "str_arr[" << i << "] = " << str_arr[i] << endl;
	}
	cout << "end SplitDemo" << endl;
}

int main()
{
	SplitDemo();
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

