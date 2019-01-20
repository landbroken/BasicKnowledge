#include"stdafx.h"

/*
https://leetcode-cn.com/problems/count-primes/
统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/
class Solution {
public:
	int countPrimes(int n) {
		if (n <= 2) return 0;

		int cnt = 0;
		vector<bool> isPrime(n, true);
		//循环最大值一定是小于n的开方
		/*
		i=2
		j=4;p[4]=f;
		j=6;p[6]=f;
		j=9;p[8]=f;
		j=10;
		i=3;
		j=9;p[9]=f;
		*/
		for (int i = 2;i*i<n;i++) {
			/*
			如果一个数是质数，那么它的任意倍数(j+=i)都是合数

			j的初值：因为(i-x)*i，x为任意大于0的正整数，在上一轮中一定已经被判断过了，
			所以从(i-1)*i+i=i*i开始判断
			*/
			if (isPrime[i] == true) {
				for (int j = i*i;j<n;j += i) {
					isPrime[j] = false;
				}
			}
		}

		for (size_t i = 2; i < n; i++)
		{
			if (isPrime[i])
			{
				cnt++;
			}
		}

		return cnt;
	}
};