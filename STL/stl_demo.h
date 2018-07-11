#pragma once
#ifndef _STL_DEMO_H_
#define _STL_DEMO_H_

#include<set>
#include<map>
#include<string>

#pragma region set容器

/*
@brief 一个std::set<int>容器使用的Demo
*/
class SetDemo
{
public:
	SetDemo();
	~SetDemo();

	void Insert(int * value, int len);
	void IteratorOutput();
	void ReverseIteratorOutput();
	int ElementDelete(int i);
	int IteratorElementDelete();
	int Clear();
	bool Find(int value);
	int Count(int value);
	bool IsEqual(std::set<int> out);
	std::set<int> GetInnerSet();
private:
	std::set<int> s;
	std::set<int>::iterator it;
	std::set<int>::reverse_iterator rit;
};

#pragma endregion

#pragma region map容器

class MapDemo
{
public:
	MapDemo();
	~MapDemo();
	void Insert();
	void Output();

private:
	std::map<int, std::string> mapStudent;
	std::map<int, std::string>::iterator iter;
};

#pragma endregion


#endif // !_STL_DEMO_H_
