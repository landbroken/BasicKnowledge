using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DesignPattern.Factory
{
    #region 教程版

    public abstract class Creator
    {
        public abstract Food CreateFoddFactory();
    }

    /// <summary>
    /// 肉末茄子这道菜
    /// </summary>
    public class MincedMeatEggplant : Food
    {
        /// <summary>
        /// 重写抽象类中的方法
        /// </summary>
        public override void Print()
        {
            FoodName = "肉末茄子好了";
            Console.WriteLine("肉末茄子好了");
        }
    }
    /// <summary>
    /// 肉末茄子工厂类，负责创建肉末茄子这道菜
    /// </summary>
    public class MincedMeatEggplantFactory : Creator
    {
        /// <summary>
        /// 负责创建肉末茄子这道菜
        /// </summary>
        /// <returns></returns>
        public override Food CreateFoddFactory()
        {
            return new MincedMeatEggplant();
        }
    }

    #endregion

    #region 根据教程理解自己写的示例

    public interface IEquipCreator
    {
        IEquip CreateFactory();
    }

    /// <summary>
    /// gps的工厂方法
    /// </summary>
    public class GpsFactory : IEquipCreator
    {
        public IEquip CreateFactory()
        {
            return new Gps();
        }
    }

    /// <summary>
    /// 惯性测量单元的工厂方法
    /// </summary>
    public class IMUFactory : IEquipCreator
    {
        public IEquip CreateFactory()
        {
            return new IMU();
        }
    }

    /// <summary>
    /// 摄像头工厂方法
    /// </summary>
    public class CameraFactory : IEquipCreator
    {
        public IEquip CreateFactory()
        {
            return new Camera();
        }
    }

    /// <summary>
    /// 摄像头设备
    /// </summary>
    public class Camera : IEquip
    {
        public string GetName()
        {
            return nameof(Camera);
        }
    }

    #endregion

}
