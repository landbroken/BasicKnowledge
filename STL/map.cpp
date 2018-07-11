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

void MapDemo::Insert()
{
	mapStudent.insert(pair<int, string>(1, "student_one"));
	mapStudent.insert(pair<int, string>(2, "student_two"));
	mapStudent.insert(pair<int, string>(3, "student_three"));
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
