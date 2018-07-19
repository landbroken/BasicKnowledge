// Stack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"StackDemo.h"
using namespace std;



int main()
{
	ArrStack arrS(5);
	//插入
	cout << "arrS.Push(a):" << endl;
	arrS.Push(1);
	cout << " " << arrS.GetTop() << " ";
	arrS.Push(2);
	cout << " " << arrS.GetTop() << " ";
	arrS.Push(3);
	cout << " " << arrS.GetTop() << " " << endl;
	//删除
	cout << "arrS.Pop():" << endl;
	arrS.Pop();
	cout << " " << arrS.GetTop() << " ";
	arrS.Pop();
	cout << " " << arrS.GetTop() << " ";
	try
	{
		arrS.Pop();
		cout << " " << arrS.GetTop() << " " << endl;
	}
	catch (const std::exception& e)
	{
		cout << "Error: " << e.what() << endl;
	}
	//空栈
	cout << "arrS.IsEmpty(): " << arrS.IsEmpty() << " ";

	system("pause");
    return 0;
}

