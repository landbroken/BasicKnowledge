using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.算法
{
    class _657
    {
        public bool JudgeCircle(string moves)
        {
            char[] dir = { 'L', 'R', 'U', 'D' };
            int len = moves.Length;
            int lr = 0, ud = 0;
            for (int i = 0; i < moves.Length; i++)
            {
                if (moves.ElementAt(i)==dir[0])
                {
                    lr--;
                }
                if (moves.ElementAt(i) == dir[1])
                {
                    lr++;
                }
                if (moves.ElementAt(i) == dir[2])
                {
                    ud++;
                }
                if (moves.ElementAt(i) == dir[3])
                {
                    ud--;
                }
            }
            if (lr==0&&ud==0)
            {
                return true;
            }
            return false;
        }
    }
}
