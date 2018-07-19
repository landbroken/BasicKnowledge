#include "stdafx.h"
#include<iostream>
#include"StackDemo.h"
using namespace std;

ArrStack::ArrStack(int maxSize)
{
	size = maxSize;
	tos = -1;
	contain = new int[size];
}

ArrStack::~ArrStack()
{
	if (contain!=nullptr)
	{
		delete contain;
		contain = nullptr;
	}
}

void ArrStack::Push(const int & element)
{
	if (!IsFull())
	{
		++tos;
		contain[tos] = element;
	}
}

int ArrStack::GetTop() const
{
	if (!IsEmpty())
	{
		return contain[tos];
	}
	else
	{
		throw std::exception("NULL");
	}
}

void ArrStack::Pop()
{
	if (!IsEmpty())
	{
		tos--;
	}
}

bool ArrStack::IsEmpty() const
{
	return tos == -1;
}

bool ArrStack::IsFull() const
{
	return tos >= size - 1;
}

void ArrStack::MakeEmpty()
{
	tos = -1;
}
