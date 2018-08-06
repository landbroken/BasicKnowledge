#ifndef _HUAWEI_H_
#define _HUAWEI_H_

#pragma region 动态规划

/*
最长递增子序列详解
https://blog.csdn.net/joylnwang/article/details/6766317
*/

/*
C++ 华为 合唱队
https://blog.csdn.net/bingo_12345/article/details/48324535

@思路
1.以每一个成员为中值，计算每个成员的最长正序和逆序合唱队队列人数，
最终得到最大序列和元素。计算复杂度O(N^3)；

2.对成员排序，正序和逆序各一次，采用动态规划思想，求各元素对于两个
序列的最长公共子序列的和。计算复杂度O(NlogN)+O(N^2) = O(N^2)；

3.采用动态规划的思想，对序列求解最长递增子序列和最长递减子序列；

4.计算每一个元素为中值，计算前向递增最优解和后向递减最优解，得到
最终最长最优解；
*/
void test_HeChangDui();

#pragma endregion

#pragma region 查找

/*
查找兄弟单词
https://www.nowcoder.com/practice/03ba8aeeef73400ca7a37a5f3370fe68?tpId=37&tqId=21250&tPage=2&rp=&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking
*/
int test_cha_zhao_xiong_di_dan_ci();
int test_su_shu_ban_lv();

/*
数独
https://www.nowcoder.com/practice/78a1a4ebe8a34c93aac006c44f6bf8a1?tpId=37&tqId=21267&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking
*/
int test_sudoku();

#pragma endregion

#pragma region 图

//路径规划问题
int test_mi_gong_wen_ti();

#pragma endregion


#endif // !_HUAWEI_H_
