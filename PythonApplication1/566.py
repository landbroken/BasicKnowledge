# -*- coding: utf-8 -*-


class Solution:
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        origin_r = len(nums)  # 行
        origin_c = len(nums[0])  # 列
        if origin_c * origin_r == r * c:  # 可以reshape
            temp = [num for row in nums for num in row]  # 展开成一维数组
            new_matrix = [[0 for j in range(c)] for i in range(r)]
            for i in range(r):
                for j in range(c):
                    new_matrix[i][j] = temp[i * c + j]
            return new_matrix
        else:  # 无法reshape
            return nums


