//先中缀转后缀再计算后缀表达式的值，需要注意的是对于‘-’为一元运算符的处理和数字
#include "stdafx.h"

int test_50() {
	string s;
	while (cin >> s) {
		stack<char> opera;
		vector<int> numcnt;//用来保存每个数字的位数，以保证计算后缀表达式时的正确性
		string s1;//后缀表达式
				  //中缀表达式转后缀表达式
		for (int i = 0;i<s.size();i++) {
			if (s[i] >= '0'&&s[i] <= '9') {
				int tmp = 0;
				while (s[i] >= '0'&&s[i] <= '9') {
					tmp++;
					s1 += s[i];
					i++;
				}
				i--;
				numcnt.push_back(tmp);
			}
			else if (s[i] == '-' || s[i] == '+') {
				if (s[i] == '-' && (s[i - 1] == '(' || s[i - 1] == '[' || s[i - 1] == '{'))
					s1 += '0';
				while (!opera.empty() && (opera.top() == '*' || opera.top() == '/' || opera.top() == '+' || opera.top() == '-')) {
					s1 += opera.top();
					opera.pop();
				}
				opera.push(s[i]);
			}
			else if (s[i] == '*' || s[i] == '/') {
				while (!opera.empty() && (opera.top() == '*' || opera.top() == '/')) {
					s1 += opera.top();
					opera.pop();
				}
				opera.push(s[i]);
			}
			else if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				opera.push(s[i]);
			else if (s[i] == ')') {
				while (opera.top() != '(') {
					s1 += opera.top();
					opera.pop();
				}
				opera.pop();
			}
			else if (s[i] == ']') {
				while (opera.top() != '[') {
					s1 += opera.top();
					opera.pop();
				}
				opera.pop();
			}
			else if (s[i] == '}') {
				while (opera.top() != '{') {
					s1 += opera.top();
					opera.pop();
				}
				opera.pop();
			}
			else
				cout << "Invalid input!" << endl;
		}
		while (!opera.empty()) {
			s1 += opera.top();
			opera.pop();
		}
		//计算后缀表达式的值
		stack<int> nums;
		int ind = 0;
		for (int i = 0;i<s1.size();i++) {
			if (s1[i] >= '0'&&s1[i] <= '9') {
				int total = 0;
				while (numcnt[ind]--)
					total = 10 * total + (s1[i++] - '0');
				i--;
				nums.push(total);
				ind++;
			}
			else {
				int tmp1 = nums.top();
				nums.pop();
				int tmp2 = nums.top();
				nums.pop();
				if (s1[i] == '+')
					nums.push(tmp2 + tmp1);
				else if (s1[i] == '-')
					nums.push(tmp2 - tmp1);
				else if (s1[i] == '*')
					nums.push(tmp2*tmp1);
				else
					nums.push(tmp2 / tmp1);
			}
		}
		cout << nums.top() << endl;
	}
	return 0;
}