using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.算法
{
    public class Solution
    {
        public int[][] Transpose(int[][] A)
        {
            int raw = A.Length;
            int column = A[0].Length;
            int[][] ret = new int[column][];
            for (int j = 0; j < column; j++)
            {
                ret[j] = new int[raw];
            }
            for (int i = 0; i < raw; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    ret[j][i] = A[i][j];
                }
            }
            return ret;
        }
    }
}
