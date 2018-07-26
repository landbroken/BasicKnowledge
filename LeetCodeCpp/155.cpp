#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

/*
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
*/
class MinStack {
public:
	std::stack<int> data;
	std::stack<int> minValue;

	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		data.push(x);
		/*
		1、空的，则新值为最小
		2、非空，x <= minValue.top()，注意有=号，因为data栈这个值出栈后，
		data栈里可能还有这个值
		*/
		if (minValue.size() <= 0 || x <= minValue.top())
		{
			minValue.push(x);
		}
	}

	void pop() {
		if (minValue.size()>0 && minValue.top() == data.top())
		{
			minValue.pop();
		}
		data.pop();

	}

	int top() {
		return data.top();
	}

	int getMin() {
		return minValue.top();
	}
};
