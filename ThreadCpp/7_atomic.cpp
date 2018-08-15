#include "stdafx.h"

struct AtomicCounter {
	std::atomic<int> value;

	void increment()
	{
		++value;
	}

	void decrement()
	{
		--value;
	}

	int get()
	{
		return value;
	}
};