#pragma once
#ifndef _STL_DEMO_H_
#define _STL_DEMO_H_

#include<set>
#include<map>
#include<string>
#include<list>
#include<vector>

#pragma region vector容器

class VectorDemo
{
public:
	VectorDemo();
	~VectorDemo();

	//初始化vector
	void Initial();
	void Add(int* data, int raw_len, int column_len);
	//遍历二维数组
	void ErgodicOutput();

private:
	std::vector<std::vector<int>> arr;
};

#pragma endregion

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
	void Insert(int key, std::string value);
	void Output();
	void Find(const int & val);
	std::map<int, std::string> GetMap();

private:
	std::map<int, std::string> mapStudent;
	std::map<int, std::string>::iterator iter;
};

#pragma endregion

#pragma region list容器

class ListDemo
{
public:
	ListDemo() {};
	~ListDemo() {};

	void Insert(const int value);
	void Insert(int * value, int len);
	void Output();
	void Clear();
	void Sort();
	std::vector<int> GetOutput() { return m_output; };
	bool IsEqual(int* arr,int size);
private:
	std::list<int> m_list;
	std::vector<int> m_output;
};

#pragma endregion


#endif // !_STL_DEMO_H_
