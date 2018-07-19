#pragma once

#ifndef _STACK_DEMO_H_
#define _STACK_DEMO_H_

class ArrStack
{
public:
	ArrStack(int maxSize);
	~ArrStack();

	void Push(const int& element);
	int GetTop() const;
	void Pop();
	bool IsEmpty()const;
	bool IsFull()const;
	void MakeEmpty();
private:
	int size;
	int tos;//Õ»¶¥Ë÷Òý
	int* contain;
};

#endif // !_STACK_DEMO_H_
