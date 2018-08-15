using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using DesignPattern.Factory;

namespace DesignPattern.Builder
{
    #region 教程

    /// <summary>
    /// 以组装电脑为例子
    /// 每台电脑的组成过程都是一致的，但是使用同样的构建过程可以
    /// 创建不同的表示(即可以组装成不一样的电脑，配置不一样)
    /// 组装电脑的这个场景就可以应用建造者模式来设计
    /// </summary>

    /// <summary>
    /// 客户类
    /// </summary>
    class Customer
    {
        static void test()
        {
            // 客户找到电脑城老板说要买电脑，这里要装两台电脑
            // 创建指挥者和构造者
            Director director = new Director();
            Builder b1 = new ConcreteBuilder1();
            Builder b2 = new ConcreteBuilder2();

            // 老板叫员工去组装第一台电脑
            director.Construct(b1);

            // 组装完，组装人员搬来组装好的电脑
            Computer computer1 = b1.GetComputer();
            computer1.Show();

            // 老板叫员工去组装第二台电脑
            director.Construct(b2);
            Computer computer2 = b2.GetComputer();
            computer2.Show();

            Console.Read();
        }
    }

    /// <summary>
    /// 小王和小李难道会自愿地去组装嘛，谁不想休息的，这必须有一个人叫他们去组装才会去的
    /// 这个人当然就是老板了，也就是建造者模式中的指挥者
    /// 指挥创建过程类
    /// </summary>
    public class Director
    {
        // 组装电脑
        public void Construct(Builder builder)
        {
            builder.BuildPartCPU();
            builder.BuildPartMainBoard();
        }
    }

    /// <summary>
    /// 电脑类
    /// </summary>
    public class Computer
    {
        // 电脑组件集合
        private IList<string> parts = new List<string>();

        // 把单个组件添加到电脑组件集合中
        public void Add(string part)
        {
            parts.Add(part);
        }

        public void Show()
        {
            Console.WriteLine("电脑开始在组装.......");
            foreach (string part in parts)
            {
                Console.WriteLine("组件" + part + "已装好");
            }

            Console.WriteLine("电脑组装好了");
        }
    }

    /// <summary>
    /// 抽象建造者，这个场景下为 "组装人" ，这里也可以定义为接口
    /// </summary>
    public abstract class Builder
    {
        // 装CPU
        public abstract void BuildPartCPU();
        // 装主板
        public abstract void BuildPartMainBoard();

        // 当然还有装硬盘，电源等组件，这里省略

        // 获得组装好的电脑
        public abstract Computer GetComputer();
    }

    /// <summary>
    /// 具体创建者，具体的某个人为具体创建者，例如：装机小王啊
    /// </summary>
    public class ConcreteBuilder1 : Builder
    {
        Computer computer = new Computer();
        public override void BuildPartCPU()
        {
            computer.Add("CPU1");
        }

        public override void BuildPartMainBoard()
        {
            computer.Add("Main board1");
        }

        public override Computer GetComputer()
        {
            return computer;
        }
    }

    /// <summary>
    /// 具体创建者，具体的某个人为具体创建者，例如：装机小李啊
    /// 又装另一台电脑了
    /// </summary>
    public class ConcreteBuilder2 : Builder
    {
        Computer computer = new Computer();
        public override void BuildPartCPU()
        {
            computer.Add("CPU2");
        }

        public override void BuildPartMainBoard()
        {
            computer.Add("Main board2");
        }

        public override Computer GetComputer()
        {
            return computer;
        }
    }

    #endregion

    #region 自己写的版本

    /// <summary>
    /// 调用类
    /// </summary>
    class BuilderUser
    {
        public static void test()
        {
            // 创建指挥者和构造者
            UsvDirector director = new UsvDirector();
            IUsvBuilder b1 = new UsvConcreteBuilder();
            IUsvBuilder b2 = new UsvConcreteBuilder2();

            Console.WriteLine("第一个");
            // 老板叫员工去组装第一个
            director.Construct(b1);
            // 组装完
            Usv usv1 = b1.GetUsv();
            usv1.Show();

            Console.WriteLine("第二个");
            // 老板叫员工去组装第二个
            director.Construct(b2);
            Usv usv2 = b2.GetUsv();
            usv2.Show();
        }
    }

    /// <summary>
    /// 建造者模式中的指挥者
    /// 指挥创建过程类
    /// </summary>
    public class UsvDirector
    {
        // 组装
        public void Construct(IUsvBuilder builder)
        {
            builder.BuildTailThruster();
            builder.BuildPwm();
            builder.BuildCamera();
            builder.BuildGps();
            builder.BuildImu();
            builder.BuildCompass();
            builder.BuildRader();
        }
    }

    /// <summary>
    /// 船类
    /// </summary>
    public class Usv
    {
        // 组件集合
        private IList<IEquip> parts = new List<IEquip>();

        // 把单个组件添加到组件集合中
        public void Add(IEquip part)
        {
            parts.Add(part);
        }

        public void Show()
        {
            Console.WriteLine("开始在组装.......");
            foreach (var part in parts)
            {
                Console.WriteLine("组件" + part.GetName() + "已装好");
            }

            Console.WriteLine("组装好了");
        }
    }

    /// <summary>
    /// 抽象建造者，这个场景下为 "组装人" ，这里也可以定义为接口
    /// </summary>
    public interface IUsvBuilder
    {
        void BuildTailThruster();
        void BuildPwm();
        void BuildCamera();
        void BuildGps();
        void BuildImu();
        void BuildCompass();
        void BuildRader();

        // 获得组装好的
        Usv GetUsv();
    }

    /// <summary>
    /// 具体创建者，具体的某个人为具体创建者
    /// </summary>
    public class UsvConcreteBuilder : IUsvBuilder
    {
        Usv _usv = new Usv();

        public void BuildCamera()
        {
            ICamera e = new HikVision();
            _usv.Add(e);
        }

        public void BuildCompass()
        {
            
        }

        public void BuildGps()
        {
            IEquip e = new Gps();
            _usv.Add(e);
        }

        public void BuildImu()
        {
            IEquip e = new IMU();
            _usv.Add(e);
        }

        public void BuildPwm()
        {
            
        }

        public void BuildRader()
        {
            IRadar r = new LaserRadar();
            _usv.Add(r);
        }

        public void BuildTailThruster()
        {
            
        }

        public Usv GetUsv()
        {
            return _usv;
        }
    }

    /// <summary>
    /// 具体创建者，具体的某个人为具体创建者
    /// </summary>
    public class UsvConcreteBuilder2 : IUsvBuilder
    {
        Usv _usv = new Usv();

        public void BuildCamera()
        {
            IEquip e = new Uniview();
            _usv.Add(e);
        }

        public void BuildCompass()
        {

        }

        public void BuildGps()
        {
            IEquip e = new Gps();
            _usv.Add(e);
        }

        public void BuildImu()
        {
            IEquip e = new IMU();
            _usv.Add(e);
        }

        public void BuildPwm()
        {

        }

        public void BuildRader()
        {
            IRadar r = new MillimeterWaveRadar();
            _usv.Add(r);
        }

        public void BuildTailThruster()
        {

        }

        public Usv GetUsv()
        {
            return _usv;
        }
    }

    #endregion
}
