/*
抽象工厂模式将具体产品的创建延迟到具体工厂的子类中，这样将对象的创建封装起来，
可以减少客户端与具体产品类之间的依赖，从而使系统耦合度低，这样更有利于后期的
维护和扩展，这真是抽象工厂模式的优点所在，然后抽象模式同时也存在不足的地方。
下面就具体看下抽象工厂的缺点（缺点其实在前面的介绍中以已经涉及了）：

抽象工厂模式很难支持新种类产品的变化。这是因为抽象工厂接口中已经确定了可以被创建
的产品集合，如果需要添加新产品，此时就必须去修改抽象工厂的接口，这样就涉及到抽象
工厂类的以及所有子类的改变，这样也就违背了“开发——封闭”原则。

知道了抽象工厂的优缺点之后，也就能很好地把握什么情况下考虑使用抽象工厂模式了，
下面就具体看看使用抽象工厂模式的系统应该符合那几个前提：
•一个系统不要求依赖产品类实例如何被创建、组合和表达的表达，这点也是所有工厂模式应用的前提。
•这个系统有多个系列产品，而系统中只消费其中某一系列产品
•系统要求提供一个产品类的库，所有产品以同样的接口出现，客户端不需要依赖具体实现。
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DesignPattern.Factory
{
    #region 教程

    /// <summary>
    /// 抽象工厂类，提供创建两个不同地方的鸭架和鸭脖的接口
    /// </summary>
    public abstract class AbstractFactory
    {
        // 抽象工厂提供创建一系列产品的接口，这里作为例子，只给出了绝味中鸭脖和鸭架的创建接口
        public abstract YaBo CreateYaBo();
        public abstract YaJia CreateYaJia();
    }

    /// <summary>
    /// 南昌绝味工厂负责制作南昌的鸭脖和鸭架
    /// </summary>
    public class NanChangFactory : AbstractFactory
    {
        // 制作南昌鸭脖
        public override YaBo CreateYaBo()
        {
            return new NanChangYaBo();
        }
        // 制作南昌鸭架
        public override YaJia CreateYaJia()
        {
            return new NanChangYaJia();
        }
    }

    /// <summary>
    /// 上海绝味工厂负责制作上海的鸭脖和鸭架
    /// </summary>
    public class ShangHaiFactory : AbstractFactory
    {
        // 制作上海鸭脖
        public override YaBo CreateYaBo()
        {
            return new ShangHaiYaBo();
        }
        // 制作上海鸭架
        public override YaJia CreateYaJia()
        {
            return new ShangHaiYaJia();
        }
    }

    /// <summary>
    /// 鸭脖抽象类，供每个地方的鸭脖类继承
    /// </summary>
    public abstract class YaBo
    {
        /// <summary>
        /// 打印方法，用于输出信息
        /// </summary>
        public abstract void Print();
    }

    /// <summary>
    /// 鸭架抽象类，供每个地方的鸭架类继承
    /// </summary>
    public abstract class YaJia
    {
        /// <summary>
        /// 打印方法，用于输出信息
        /// </summary>
        public abstract void Print();
    }

    /// <summary>
    /// 南昌的鸭脖类，因为江西人喜欢吃辣的，所以南昌的鸭脖稍微会比上海做的辣
    /// </summary>
    public class NanChangYaBo : YaBo
    {
        public override void Print()
        {
            Console.WriteLine("南昌的鸭脖");
        }
    }

    /// <summary>
    /// 上海的鸭脖没有南昌的鸭脖做的辣
    /// </summary>
    public class ShangHaiYaBo : YaBo
    {
        public override void Print()
        {
            Console.WriteLine("上海的鸭脖");
        }
    }

    /// <summary>
    /// 南昌的鸭架
    /// </summary>
    public class NanChangYaJia : YaJia
    {
        public override void Print()
        {
            Console.WriteLine("南昌的鸭架子");
        }
    }

    /// <summary>
    /// 上海的鸭架
    /// </summary>
    public class ShangHaiYaJia : YaJia
    {
        public override void Print()
        {
            Console.WriteLine("上海的鸭架子");
        }
    }

    #endregion

    #region 自己写的抽象工厂

    public class AbstractFactoryClient
    {
        public static void Test()
        {
            IEquipAbstractFactory e1 = new FirstVehicleFactory();
            var c1 = e1.CreateCamera();
            var r1 = e1.CreateRadar();
            
            string tmp = "";
            tmp = c1.GetName();
            Console.WriteLine(tmp);
            tmp = r1.GetName();
            Console.WriteLine(tmp);

            IEquipAbstractFactory e2 = new SecondVehicleFactory();
            var c2 = e2.CreateCamera();
            var r2 = e2.CreateRadar();

            tmp = c2.GetName();
            Console.WriteLine(tmp);
            tmp = r2.GetName();
            Console.WriteLine(tmp);
        }
    }

    /// <summary>
    /// 抽象工厂，将所有设备抽象出来
    /// </summary>
    public interface IEquipAbstractFactory
    {
        ICamera CreateCamera();
        IRadar CreateRadar();
    }

    /// <summary>
    /// 摄像头接口
    /// </summary>
    public interface ICamera : IEquip
    {
        new string GetName();
    }

    /// <summary>
    /// 卫星定位设备接口
    /// </summary>
    public interface IRadar : IEquip
    {
        new string GetName();
    }

    /// <summary>
    /// 第一个航行器
    /// </summary>
    public class FirstVehicleFactory: IEquipAbstractFactory
    {
        public ICamera CreateCamera()
        {
            return new HikVision();
        }

        public IRadar CreateRadar()
        {
            return new LaserRadar();
        }
    }

    public class HikVision: ICamera
    {
        public string GetName()
        {
            return nameof(HikVision);
        }
    }

    public class LaserRadar : IRadar
    {
        public string GetName()
        {
            return nameof(LaserRadar);
        }
    }

    /// <summary>
    /// 现在增加第二个航行器
    /// </summary>
    public class SecondVehicleFactory : IEquipAbstractFactory
    {
        public ICamera CreateCamera()
        {
            return new Uniview();
        }

        public IRadar CreateRadar()
        {
            return new MillimeterWaveRadar();
        }
    }

    public class Uniview : ICamera
    {
        public string GetName()
        {
            return nameof(Uniview);
        }
    }

    public class MillimeterWaveRadar : IRadar
    {
        public string GetName()
        {
            return nameof(MillimeterWaveRadar);
        }
    }

    #endregion
}
