# -*- coding: utf-8 -*-


class Solution:
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        tmp = set(nums1).intersection(nums2)
        return list(tmp)


if __name__ == '__main__':
    s = Solution()
    ret = s.intersection([1, 2, 2, 1], [2, 2])
    print(ret)
