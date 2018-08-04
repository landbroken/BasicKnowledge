#include"stdafx.h"
#include<map>
#include<iostream>
#include<string>
#include"stl_demo.h"
using namespace std;

MapDemo::MapDemo()
{
}

MapDemo::~MapDemo()
{
}

void MapDemo::Insert(int key,string value)
{
	mapStudent.insert(pair<int, string>(key, value));
}

void MapDemo::Output()
{
	for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
	{
		cout << iter->first;
		cout << " ";
		cout << iter->second;
		cout << endl;
	}
}

void MapDemo::Find(const int& key)
{
	auto ret = mapStudent.find(key);
	if (ret!=mapStudent.end())
	{
		cout << "key=" << ret->first << "value=" << ret->second << endl;
	}
	else
	{
		cout << "can't find this key" << endl;
	}
}

std::map<int, std::string> MapDemo::GetMap()
{
	return mapStudent;
}