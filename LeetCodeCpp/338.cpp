#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		// GCC内建函数__builtin_popcount (unsigned u) 
		//std::vector<int> ret;
		//for (int i = 0;i <= num;i++)
		//{
		//	ret.push_back(__builtin_popcount(i));
		//}
		//return ret;

		// 时间复杂度为O(n * sizeof(integer)) 
		// int count=0;
		// vector<int> dp(num+1,0);
		// for(int i=0;i<num+1;i++){
		//     int j=i;
		//     int count=0;
		//     while(j){
		//         if(j&1)
		//             count++;
		//         j=j>>1;
		//     }
		//     dp[i]=count;
		// }
		// return dp;

		// 线性时间O(n)
		vector<int> dp(num + 1, 0);

		for (int i = 1;i <= num;i++) {
			dp[i] = dp[i&i - 1] + 1;
		}
		return dp;
	}
};