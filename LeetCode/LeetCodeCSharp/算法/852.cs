using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.算法
{
    class _852
    {
        /// <summary>
        /// 
        /// </summary>
        /// <param name="A"></param>
        /// <returns></returns>
        /// <remarks>
        /// a) 3 <= A.length <= 10000
        /// b) 0 <= A[i] <= 10^6
        /// c) 存在 0 < i < A.length - 1 使得
        /// A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
        /// title: 给定一个确定为山脉的数组，返回任何满足 
        /// A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1] 的 i 的值。
        /// </remarks>
        public int PeakIndexInMountainArray(int[] A)
        {
            int pos = 0;
            for (int i = 1; i < A.Length; i++)
            {
                if (A[i]>A[i-1])
                {
                    pos = i;
                }
            }
            return pos;
        }
    }
}
