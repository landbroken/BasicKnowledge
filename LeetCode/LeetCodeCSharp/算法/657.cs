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
            int lr = moves.Count<char>(c => c == 'L') - moves.Count<char>(c => c == 'R');
            int ud = moves.Count<char>(c => c == 'U') - moves.Count<char>(c => c == 'D');
            if (lr==0&&ud==0)
            {
                return true;
            }
            return false;
        }
    }
}
