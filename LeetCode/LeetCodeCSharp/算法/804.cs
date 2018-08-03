﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.算法
{
    class _804
    {
        string[] Morse = {
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
            "....", "..", ".---", "-.-", ".-..", "--", "-.",
            "---", ".--.", "--.-", ".-.", "...", "-",
            "..-", "...-", ".--", "-..-", "-.--", "--.."
        };

        /// <summary>
        /// 
        /// </summary>
        /// <param name="words"></param>
        /// <returns></returns>
        /// <example>
        /// 例如:
        /// 输入: words = ["gin", "zen", "gig", "msg"]
        /// 输出: 2
        /// 解释: 
        /// 各单词翻译如下:
        /// "gin" -> "--...-."
        /// "zen" -> "--...-."
        /// "gig" -> "--...--."
        /// "msg" -> "--...--."
        /// 
        /// 共有 2 种不同翻译, "--...-." 和 "--...--.".
        /// </example>
        public int UniqueMorseRepresentations(string[] words)
        {
            List<string> m = new List<string>();
            for (int i = 0; i < words.Length; i++)
            {
                string tmp = Transfer2Morse(words[i]);
                if (!m.Contains(tmp))
                {
                    m.Add(tmp);
                }
            }
            return m.Count;
        }

        public string Transfer2Morse(string word)
        {
            string ret = "";
            for (int i = 0; i < word.Length; i++)
            {
                int num = Convert.ToInt32(word.ElementAt(i)) - 97;
                ret += Morse[num];
            }
            return ret;
        }
    }
}