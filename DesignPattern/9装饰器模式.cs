using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DesignPattern.Decorator
{
    #region 教程

    #region 调用

    public class Customer
    {
        public static void test()
        {
            // 我买了个苹果手机
            Phone phone = new ApplePhone();

            // 现在想贴膜了
            Decorator applePhoneWithSticker = new Sticker(phone);
            // 扩展贴膜行为
            applePhoneWithSticker.Print();
            Console.WriteLine("----------------------\n");

            // 现在我想有挂件了
            Decorator applePhoneWithAccessories = new Accessories(phone);
            // 扩展手机挂件行为
            applePhoneWithAccessories.Print();
            Console.WriteLine("----------------------\n");

            // 现在我同时有贴膜和手机挂件了
            Sticker sticker = new Sticker(phone);
            Accessories applePhoneWithAccessoriesAndSticker = new Accessories(sticker);
            applePhoneWithAccessoriesAndSticker.Print();
            Console.ReadLine();
        }
    }

    #endregion

    #region 实现

    /// <summary>
    /// 手机抽象类，即装饰者模式中的抽象组件类
    /// </summary>
    public abstract class Phone
    {
        public abstract void Print();
    }

    /// <summary>
    /// 苹果手机，即装饰着模式中的具体组件类
    /// </summary>
    public class ApplePhone : Phone
    {
        /// <summary>
        /// 重写基类方法
        /// </summary>
        public override void Print()
        {
            Console.WriteLine("开始执行具体的对象——苹果手机");
        }
    }

    /// <summary>
    /// 装饰抽象类,要让装饰完全取代抽象组件，所以必须继承自Phone
    /// </summary>
    public abstract class Decorator : Phone
    {
        private Phone phone;

        public Decorator(Phone p)
        {
            this.phone = p;
        }

        public override void Print()
        {
            if (phone != null)
            {
                phone.Print();
            }
        }
    }

    /// <summary>
    /// 贴膜，即具体装饰者
    /// </summary>
    public class Sticker : Decorator
    {
        public Sticker(Phone p)
            : base(p)
        {
        }

        public override void Print()
        {
            base.Print();

            // 添加新的行为
            AddSticker();
        }

        /// <summary>
        /// 新的行为方法
        /// </summary>
        public void AddSticker()
        {
            Console.WriteLine("现在苹果手机有贴膜了");
        }
    }

    /// <summary>
    /// 手机挂件
    /// </summary>
    public class Accessories : Decorator
    {
        public Accessories(Phone p)
            : base(p)
        {
        }

        public override void Print()
        {
            base.Print();

            // 添加新的行为
            AddAccessories();
        }

        /// <summary>
        /// 新的行为方法
        /// </summary>
        public void AddAccessories()
        {
            Console.WriteLine("现在苹果手机有漂亮的挂件了");
        }
    }

    #endregion

    #endregion

    #region 自己写的

    #region 调用

    /// <summary>
    /// 调用，感觉效果和python的装饰器差不多
    /// </summary>
    public class MyClient
    {
        public static void test()
        {
            Console.WriteLine("----------------------\n");
            // 买了个B52
            IPlane _b52 = new B52();

            // 加装燃烧弹
            ADecoratorPlane WithIncendiaryBomb = new IncendiaryBomb(_b52);
            // 攻击，同时包括默认装载，燃烧弹
            WithIncendiaryBomb.Attack();
            Console.WriteLine("----------------------\n");

            // 加装近程攻击导弹
            ADecoratorPlane WithAGM_69 = new AGM_69(_b52);
            // 攻击，同时包括默认装载，近程攻击导弹
            WithAGM_69.Attack();
            Console.WriteLine("----------------------\n");

            // 同时装载多个
            ADecoratorPlane IncendiaryBomb = new IncendiaryBomb(_b52);
            ADecoratorPlane AGM_69 = new AGM_69(IncendiaryBomb);
            // 攻击，同时包括默认装载，近程攻击导弹
            // 按照装载顺序发射（即按继承层次执行，先执行父类的）
            // 这里实际有三个类对象，_b52《-IncendiaryBomb《-AGM_69
            AGM_69.Attack();
            Console.ReadLine();
        }
    }

    #endregion

    #region 实现

    /// <summary>
    /// 抽象类，即装饰者模式中的抽象组件类
    /// </summary>
    /// <remarks>
    /// 一般船，默认只有一个尾推进器
    /// </remarks>
    public interface IPlane
    {
        void Attack();
    }

    /// <summary>
    /// 轰炸机，即装饰着模式中的具体组件类
    /// </summary>
    public class B52 : IPlane
    {
        /// <summary>
        /// 实现方法
        /// </summary>
        public void Attack()
        {
            Console.WriteLine("便便炸弹攻击");
        }
    }

    /// <summary>
    /// 装饰抽象类,要让装饰完全取代抽象组件，所以必须继承自Phone
    /// </summary>
    public abstract class ADecoratorPlane : IPlane
    {
        private IPlane _plane;

        public ADecoratorPlane(IPlane p)
        {
            this._plane = p;
        }

        public virtual void Attack()
        {
            if (_plane != null)
            {
                _plane.Attack();
            }
        }
    }

    /// <summary>
    /// 燃烧弹，即具体装饰者
    /// </summary>
    public class IncendiaryBomb : ADecoratorPlane
    {
        public IncendiaryBomb(IPlane p)
            : base(p)
        {
        }

        public override void Attack()
        {
            base.Attack();

            // 添加新的行为
            AddWeapon();
        }

        /// <summary>
        /// 新的行为方法
        /// </summary>
        public void AddWeapon()
        {
            Console.WriteLine("加装燃烧弹");
        }
    }

    /// <summary>
    /// AGM-69近程攻击导弹
    /// </summary>
    public class AGM_69 : ADecoratorPlane
    {
        public AGM_69(IPlane p)
            : base(p)
        {
        }

        public override void Attack()
        {
            base.Attack();

            // 添加新的行为
            AddWeapon();
        }

        /// <summary>
        /// 新的行为方法
        /// </summary>
        public void AddWeapon()
        {
            Console.WriteLine("加挂近程攻击导弹");
        }
    }

    #endregion

    #endregion
}
