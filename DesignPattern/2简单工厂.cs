using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DesignPattern.Factory
{
    #region 参考教程的示例

    /// <summary>
    /// 菜抽象类
    /// </summary>
    public abstract class Food
    {
        public string FoodName { get; set; }

        // 输出点了什么菜
        public abstract void Print();
    }

    /// <summary>
    /// 西红柿炒鸡蛋这道菜
    /// </summary>
    public class TomatoScrambledEggs : Food
    {
        public override void Print()
        {
            FoodName = "一份西红柿炒蛋！";
            Console.WriteLine(FoodName);
        }
    }

    /// <summary>
    /// 土豆肉丝这道菜
    /// </summary>
    public class ShreddedPorkWithPotatoes : Food
    {
        public override void Print()
        {
            FoodName = "一份土豆肉丝";
            Console.WriteLine("一份土豆肉丝");
        }
    }

    /// <summary>
    /// 简单工厂类, 负责 炒菜
    /// </summary>
    public class FoodSimpleFactory
    {
        public static Food CreateFood(string type)
        {
            Food food = null;
            //equals比较两个string对象的值
            //==比较两个string对象是否是同一个引用，建议用equals
            if (type.Equals("土豆肉丝"))
            {
                food = new ShreddedPorkWithPotatoes();
            }
            else if (type.Equals("西红柿炒蛋"))
            {
                food = new TomatoScrambledEggs();
            }

            return food;
        }
    }

    #endregion

    #region 根据教程理解自己写的示例

    /// <summary>
    /// 设备抽象接口
    /// </summary>
    public interface IEquip
    {
        string GetName();
    }

    /// <summary>
    /// 简单工厂模式的工厂
    /// </summary>
    public class EquipSimpleFactory
    {
        private static IEquip factory = null;

        public static IEquip CreateFactory(string name)
        {
            switch (name)
            {
                case "gps":
                    factory = new Gps();
                    break;
                case "imu":
                    factory = new IMU();
                    break;
                default:
                    throw new NotImplementedException();
            }
            return factory;
        }
    }

    /// <summary>
    /// GPS设备
    /// </summary>
    public class Gps : IEquip
    {
        public string GetName()
        {
            return nameof(Gps);
        }
    }

    /// <summary>
    /// 惯性测量单元设备
    /// </summary>
    public class IMU : IEquip
    {
        public string GetName()
        {
            return nameof(IMU);
        }
    }

    #endregion
}
