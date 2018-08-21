using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DesignPattern.Adapter
{
    #region 教程

    /// <summary>
    /// 客户端，客户想要把2个孔的插头 转变成三个孔的插头，这个转变交给适配器就好
    /// 既然适配器需要完成这个功能，所以它必须同时具体2个孔插头和三个孔插头的特征
    /// </summary>
    public class Client
    {
        public static void test()
        {
            // 现在客户端可以通过电适配要使用2个孔的插头了
            IThreeHole threehole = new PowerAdapter();
            threehole.Request();
            Console.ReadLine();
        }
    }

    /// <summary>
    /// 三个孔的插头，也就是适配器模式中的目标角色
    /// </summary>
    public interface IThreeHole
    {
        void Request();
    }

    /// <summary>
    /// 两个孔的插头，源角色——需要适配的类
    /// </summary>
    public abstract class TwoHole
    {
        public void SpecificRequest()
        {
            Console.WriteLine("我是两个孔的插头");
        }
    }

    /// <summary>
    /// 适配器类，接口要放在类的后面
    /// 适配器类提供了三个孔插头的行为，但其本质是调用两个孔插头的方法
    /// </summary>
    public class PowerAdapter : TwoHole, IThreeHole
    {
        /// <summary>
        /// 实现三个孔插头接口方法
        /// </summary>
        public void Request()
        {
            // 调用两个孔插头方法
            this.SpecificRequest();
        }
    }


    #endregion

    #region 自己写一遍

    /// <summary>
    /// 客户端
    /// </summary>
    public class MyClient
    {
        public static void test()
        {
            //新的usb接口行为和旧的一样，都是插进去
            //但是usb形状不一样（函数接口不一样）
            //适配器模型转换一下就能调用旧接口了
            ITypeC typeC = new TypeC();
            typeC.NewUsb();
            Console.ReadLine();
        }
    }

    /// <summary>
    /// 新插头，也就是适配器模式中的目标角色
    /// </summary>
    public interface ITypeC
    {
        void NewUsb();
    }

    /// <summary>
    /// 早期的手机usb接口，源角色——需要适配的类
    /// </summary>
    public abstract class MicroUSB
    {
        public void OldUsb()
        {
            Console.WriteLine(nameof(MicroUSB)+"插入");
        }
    }

    /// <summary>
    /// 适配器类，接口要放在类的后面
    /// 适配器类提供了新的插头，但其本质是调用旧插头的方法
    /// </summary>
    public class TypeC : MicroUSB, ITypeC
    {
        /// <summary>
        /// 实现新的插头方法
        /// </summary>
        public void NewUsb()
        {
            // 调用旧插头方法
            this.OldUsb();
        }
    }


    #endregion
}
