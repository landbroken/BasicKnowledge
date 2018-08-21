using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DesignPattern.Composite
{
    #region 教程——基本实现

    // 通过一些简单图形以及一些复杂图形构建图形树来演示组合模式
    // 客户端调用
    class Client
    {
        public static void test()
        {
            ComplexGraphics complexGraphics = new ComplexGraphics("一个复杂图形和两条线段组成的复杂图形");
            complexGraphics.Add(new Line("线段A"));
            ComplexGraphics CompositeCG = new ComplexGraphics("一个圆和一条线组成的复杂图形");
            CompositeCG.Add(new Circle("圆"));
            CompositeCG.Add(new Circle("线段B"));
            complexGraphics.Add(CompositeCG);
            Line l = new Line("线段C");
            complexGraphics.Add(l);

            // 显示复杂图形的画法
            Console.WriteLine("复杂图形的绘制如下：");
            Console.WriteLine("---------------------");
            complexGraphics.Draw();
            Console.WriteLine("复杂图形绘制完成");
            Console.WriteLine("---------------------");
            Console.WriteLine();

            // 移除一个组件再显示复杂图形的画法
            complexGraphics.Remove(l);
            Console.WriteLine("移除线段C后，复杂图形的绘制如下：");
            Console.WriteLine("---------------------");
            complexGraphics.Draw();
            Console.WriteLine("复杂图形绘制完成");
            Console.WriteLine("---------------------");
            Console.Read();
        }
    }

    /// <summary>
    /// 图形抽象类，
    /// </summary>
    public abstract class Graphics
    {
        public string Name { get; set; }
        public Graphics(string name)
        {
            this.Name = name;
        }

        public abstract void Draw();
        public abstract void Add(Graphics g);
        public abstract void Remove(Graphics g);
    }

    /// <summary>
    /// 简单图形类——线
    /// </summary>
    public class Line : Graphics
    {
        public Line(string name)
            : base(name)
        { }

        // 重写父类抽象方法
        public override void Draw()
        {
            Console.WriteLine("画  " + Name);
        }
        // 因为简单图形在添加或移除其他图形，所以简单图形Add或Remove方法没有任何意义
        // 如果客户端调用了简单图形的Add或Remove方法将会在运行时抛出异常
        // 我们可以在客户端捕获该类移除并处理
        public override void Add(Graphics g)
        {
            throw new Exception("不能向简单图形Line添加其他图形");
        }
        public override void Remove(Graphics g)
        {
            throw new Exception("不能向简单图形Line移除其他图形");
        }
    }

    /// <summary>
    /// 简单图形类——圆
    /// </summary>
    public class Circle : Graphics
    {
        public Circle(string name)
            : base(name)
        { }

        // 重写父类抽象方法
        public override void Draw()
        {
            Console.WriteLine("画  " + Name);
        }

        public override void Add(Graphics g)
        {
            throw new Exception("不能向简单图形Circle添加其他图形");
        }
        public override void Remove(Graphics g)
        {
            throw new Exception("不能向简单图形Circle移除其他图形");
        }
    }

    /// <summary>
    /// 复杂图形，由一些简单图形组成,这里假设该复杂图形由一个圆两条线组成的复杂图形
    /// </summary>
    public class ComplexGraphics : Graphics
    {
        private List<Graphics> complexGraphicsList = new List<Graphics>();

        public ComplexGraphics(string name)
            : base(name)
        { }

        /// <summary>
        /// 复杂图形的画法
        /// </summary>
        public override void Draw()
        {
            foreach (Graphics g in complexGraphicsList)
            {
                g.Draw();
            }
        }

        public override void Add(Graphics g)
        {
            complexGraphicsList.Add(g);
        }
        public override void Remove(Graphics g)
        {
            complexGraphicsList.Remove(g);
        }
    }

    #endregion

    #region 教程——安全式组合模式

    /// 安全式的组合模式
    /// 此方式实现的组合模式把管理子对象的方法声明在树枝构件ComplexGraphics类中
    /// 这样如果叶子节点Line、Circle使用了Add或Remove方法时，就能在编译期间出现错误
    /// 但这种方式虽然解决了透明式组合模式的问题，但是它使得叶子节点和树枝构件具有不一样的接口。
    /// 所以这两种方式实现的组合模式各有优缺点，具体使用哪个，可以根据问题的实际情况而定
    class Client2
    {
        static void test2()
        {
            ComplexGraphics2 complexGraphics = new ComplexGraphics2("一个复杂图形和两条线段组成的复杂图形");
            complexGraphics.Add(new Line2("线段A"));
            ComplexGraphics2 CompositeCG = new ComplexGraphics2("一个圆和一条线组成的复杂图形");
            CompositeCG.Add(new Circle2("圆"));
            CompositeCG.Add(new Circle2("线段B"));
            complexGraphics.Add(CompositeCG);
            Line2 l = new Line2("线段C");
            complexGraphics.Add(l);

            // 显示复杂图形的画法
            Console.WriteLine("复杂图形的绘制如下：");
            Console.WriteLine("---------------------");
            complexGraphics.Draw();
            Console.WriteLine("复杂图形绘制完成");
            Console.WriteLine("---------------------");
            Console.WriteLine();

            // 移除一个组件再显示复杂图形的画法
            complexGraphics.Remove(l);
            Console.WriteLine("移除线段C后，复杂图形的绘制如下：");
            Console.WriteLine("---------------------");
            complexGraphics.Draw();
            Console.WriteLine("复杂图形绘制完成");
            Console.WriteLine("---------------------");
            Console.Read();
        }
    }

    /// <summary>
    /// 图形抽象类，
    /// </summary>
    public abstract class Graphics2
    {
        public string Name { get; set; }
        public Graphics2(string name)
        {
            this.Name = name;
        }

        public abstract void Draw();
        // 移除了Add和Remove方法
        // 把管理子对象的方法放到了ComplexGraphics类中进行管理
        // 因为这些方法只在复杂图形中才有意义
    }

    /// <summary>
    /// 简单图形类——线
    /// </summary>
    public class Line2 : Graphics2
    {
        public Line2(string name)
            : base(name)
        { }

        // 重写父类抽象方法
        public override void Draw()
        {
            Console.WriteLine("画  " + Name);
        }
    }

    /// <summary>
    /// 简单图形类——圆
    /// </summary>
    public class Circle2 : Graphics2
    {
        public Circle2(string name)
            : base(name)
        { }

        // 重写父类抽象方法
        public override void Draw()
        {
            Console.WriteLine("画  " + Name);
        }
    }

    /// <summary>
    /// 复杂图形，由一些简单图形组成,这里假设该复杂图形由一个圆两条线组成的复杂图形
    /// </summary>
    public class ComplexGraphics2 : Graphics2
    {
        private List<Graphics2> complexGraphicsList = new List<Graphics2>();
        public ComplexGraphics2(string name)
            : base(name)
        { }

        /// <summary>
        /// 复杂图形的画法
        /// </summary>
        public override void Draw()
        {
            foreach (Graphics2 g in complexGraphicsList)
            {
                g.Draw();
            }
        }

        public void Add(Graphics2 g)
        {
            complexGraphicsList.Add(g);
        }
        public void Remove(Graphics2 g)
        {
            complexGraphicsList.Remove(g);
        }
    }

    #endregion

    #region 自己写的版本——安全式组合模式

    /// 安全式的组合模式
    /// 此方式实现的组合模式把管理子对象的方法声明在树枝构件ComplexGraphics类中
    /// 这样如果叶子节点Line、Circle使用了Add或Remove方法时，就能在编译期间出现错误
    /// 但这种方式虽然解决了透明式组合模式的问题，但是它使得叶子节点和树枝构件具有不一样的接口。
    /// 所以这两种方式实现的组合模式各有优缺点，具体使用哪个，可以根据问题的实际情况而定
    class MyClient
    {
        public static void test()
        {
            Console.WriteLine("---------------------");
            PerceptionSystem AIPerception = new PerceptionSystem("智能感知系统");
            PerceptionSystem LocationSystem = new PerceptionSystem("定位系统");
            PerceptionSystem RadarSystem = new PerceptionSystem("雷达系统");

            LocationSystem.Add(new Gps("卫星定位系统"));
            LocationSystem.Add(new Imu("IMU"));
            Laser laser32 = new Laser("32线激光雷达");
            RadarSystem.Add(laser32);
            RadarSystem.Add(new Laser("mems-正前"));
            RadarSystem.Add(new Laser("mems-左后"));
            RadarSystem.Add(new Laser("mems-右后"));

            AIPerception.Add(LocationSystem);
            AIPerception.Add(RadarSystem);

            // 启动
            Console.WriteLine("----雷达系统启动----");
            RadarSystem.Run();
            Console.WriteLine("--------------------");
            RadarSystem.End();
            Console.WriteLine("----雷达系统关闭----");

            // 移除一个组件再启动
            RadarSystem.Remove(laser32);
            Console.WriteLine("移除32线激光雷达后启动效果：");
            Console.WriteLine("---------------------");
            RadarSystem.Run();
            Console.WriteLine("---------------------");

            // 启动和关闭全部
            Console.WriteLine("启动整个感知系统：");
            AIPerception.Run();
            Console.WriteLine("现在关闭全部");
            AIPerception.End();
            Console.WriteLine("---------------------");
        }
    }

    /// <summary>
    /// 抽象类，传感器
    /// </summary>
    public abstract class Sensor
    {
        public string Name { get; set; }
        public Sensor(string name)
        {
            this.Name = name;
        }

        public abstract void Run();
        public abstract void End();
        // 移除了Add和Remove方法
        // 把管理子对象的方法放到了ComplexGraphics类中进行管理
        // 因为这些方法只在复杂图形中才有意义
    }

    /// <summary>
    /// 基本设备类——Gps
    /// </summary>
    public class Gps : Sensor
    {
        public Gps(string name)
            : base(name)
        { }

        // 重写父类抽象方法
        public override void Run()
        {
            Console.WriteLine("启动" + Name);
        }

        public override void End()
        {
            Console.WriteLine("关闭" + Name);
        }
    }

    /// <summary>
    /// 基本设备类——Imu
    /// </summary>
    public class Imu : Sensor
    {
        public Imu(string name)
            : base(name)
        { }

        // 重写父类抽象方法
        public override void Run()
        {
            Console.WriteLine("启动" + Name);
        }

        public override void End()
        {
            Console.WriteLine("关闭" + Name);
        }
    }

    /// <summary>
    /// 基本设备类——Imu
    /// </summary>
    public class Laser : Sensor
    {
        public Laser(string name)
            : base(name)
        { }

        // 重写父类抽象方法
        public override void Run()
        {
            Console.WriteLine("启动" + Name);
        }

        public override void End()
        {
            Console.WriteLine("关闭" + Name);
        }
    }

    /// <summary>
    /// 感知系统，由一些基本传感器设备组成,这里假设由一个gps，一个imu，4个激光雷达组成
    /// </summary>
    public class PerceptionSystem : Sensor
    {
        private List<Sensor> complexList = new List<Sensor>();
        public PerceptionSystem(string name)
            : base(name)
        { }

        /// <summary>
        /// 启动全部传感器设备
        /// </summary>
        public override void Run()
        {
            foreach (Sensor g in complexList)
            {
                g.Run();
            }
        }

        public override void End()
        {
            foreach (Sensor g in complexList)
            {
                g.End();
            }
        }

        public void Add(Sensor g)
        {
            complexList.Add(g);
        }
        public void Remove(Sensor g)
        {
            complexList.Remove(g);
        }
    }

    #endregion
}
