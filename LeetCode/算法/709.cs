using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.算法
{
    public class _709
    {
        public string ToLowerCase(string str)
        {
            string strtmp = "";
            for (int i = 0; i < str.Length; i++)
            {
                if (str[i] >= 'A' && str[i] <= 'Z')
                {
                    var itmp = str[i] - 'A' + 'a';
                    strtmp += Convert.ToChar(itmp);
                }
                else
                {
                    strtmp += str[i];
                }
            }
            return strtmp;
        }
    }
}
