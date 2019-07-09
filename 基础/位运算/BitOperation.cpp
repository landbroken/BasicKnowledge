#include "stdafx.h"
#include "BitOperation.h"

BitOperation::BitOperation()
{
}


BitOperation::~BitOperation()
{
}

bool BitOperation::IsEven(int a)
{
	//==优先级比&高
	return (a & 1) == 0;
}

int BitOperation::Multiply2(int a)
{
	return a << 1;
}

int BitOperation::Divide2(int a)
{
	return a >> 1;
}

int BitOperation::SingleNumber(int A[], int n)
{
	for (int i = 1; i < n; ++i) {
		A[0] ^= A[i];
	}
	return A[0];
}

void BitOperation::Swap(int & x, int & y)
{
	x ^= y;
	y ^= x;
	x ^= y;
}
