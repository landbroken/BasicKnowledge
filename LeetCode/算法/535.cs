using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.算法
{
    /// <summary>
    /// TinyURL 的加密与解密
    /// </summary>
    /// <remarks>
    /// 短链接URL系统是怎么设计的？
    /// http://www.codeceo.com/article/short-url-system-design.html
    /// TinyURL的实现原理
    /// https://blog.csdn.net/bdss58/article/details/74784428
    /// leetcode 535. Encode and Decode TinyURL（长短网址互译）
    /// https://blog.csdn.net/a731604348/article/details/70150107
    /// </remarks>
    class _535
    {
        private static string BASE_HOST = "http://tinyurl.com/";
        private static string SEED = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

        private Dictionary<string, string> keyToUrl = new Dictionary<string, string>();
        private Dictionary<string, string> urlToKey = new Dictionary<string, string>();
        // Encodes a URL to a shortened URL
        public string encode(string longUrl)
        {
            if (urlToKey.ContainsKey(longUrl))
            {
                return BASE_HOST + urlToKey[longUrl];
            }

            string key = null;
            do
            {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < 6; i++)
                {
                    int r = (int)(new Random().Next(SEED.Length));
                    sb.Append(SEED.ElementAt(r));
                }
                key = sb.ToString();
            } while (keyToUrl.ContainsKey(key));

            keyToUrl.Add(key, longUrl);
            urlToKey.Add(longUrl, key);
            return BASE_HOST + key;
        }

        // Decodes a shortened URL to its original URL.
        public string decode(string shortUrl)
        {
            return keyToUrl[shortUrl.Replace(BASE_HOST, "")];
        }
    }
}
