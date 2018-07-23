using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DesignPattern.Factory
{
    #region 教程

    /// <summary>
    /// 如果绝味又想开一家湖南的分店时，因为湖南喜欢吃麻的
    /// 所以这是有需要有一家湖南的工厂专门制作
    /// </summary>
    public class HuNanFactory : AbstractFactory
    {
        // 制作湖南鸭脖
        public override YaBo CreateYaBo()
        {
            return new HuNanYaBo();
        }

        // 制作湖南鸭架
        public override YaJia CreateYaJia()
        {
            return new HuNanYajia();
        }
    }

    /// <summary>
    /// 湖南的鸭脖
    /// </summary>
    public class HuNanYaBo : YaBo
    {
        public override void Print()
        {
            Console.WriteLine("湖南的鸭脖");
        }
    }

    /// <summary>
    /// 湖南的鸭架
    /// </summary>
    public class HuNanYajia : YaJia
    {
        public override void Print()
        {
            Console.WriteLine("湖南的鸭架子");
        }
    }

    #endregion

    #region 自己写的

    #endregion
}
