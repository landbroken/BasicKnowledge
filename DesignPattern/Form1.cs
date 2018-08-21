using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using DesignPattern.Factory;
using DesignPattern.Builder;
using DesignPattern.Prototype;
using DesignPattern.Adapter;
using DesignPattern.Bridge;
using DesignPattern.Decorator;

namespace DesignPattern
{
    public partial class Form1 : Form
    {
        #region 委托

        delegate void show(string data);
        public void showTextbox(string data)
        {
            textBox1.Text += data + Environment.NewLine;
        }

        #endregion

        #region Form相关

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        #endregion

        private class TestModel
        {
            public Singleton_t m_test = null;

            public void Initializer()
            {
                m_test = Singleton_t.GetInstance();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var test1 = Singleton_t.GetInstance();
            Invoke(new show(showTextbox), new object[] { "初始值:"+test1.strData });
            test1.data = 1;
            test1.strData = "1";
            Invoke(new show(showTextbox), new object[] { "赋值后:"+test1.strData });
            var test2 = Singleton_t.GetInstance();
            Invoke(new show(showTextbox), new object[] { "获取的第二个实例值:"+test2.strData });
            TestModel test3 = new TestModel();
            test3.Initializer();
            Invoke(new show(showTextbox), new object[] { "在另一个类中的作为成员变量时:" + test3.m_test.strData });
            test1.strData = "3";
            Invoke(new show(showTextbox), new object[] { "所有实例同步变化:" + test3.m_test.strData });
        }

        private void button2_Click(object sender, EventArgs e)
        {
            // 客户想点一个西红柿炒蛋        
            Food food1 = FoodSimpleFactory.CreateFood("西红柿炒蛋");
            food1.Print();

            // 客户想点一个土豆肉丝
            Food food2 = FoodSimpleFactory.CreateFood("土豆肉丝");
            food2.Print();

            string className = "gps";
            button2_NoEncapsulation(className);
            button2_Encapsulation(className);
            className = "imu";
            button2_NoEncapsulation(className);
            button2_Encapsulation(className);
        }

        /// <summary>
        /// 如果不用简单工厂
        /// </summary>
        /// <param name="str1"></param>
        private void button2_NoEncapsulation(string className)
        {
            string str1 = "";
            if (className == "gps")
            {
                Gps e1 = new Gps();
                str1 = e1.GetName();
                Invoke(new show(showTextbox), new object[] { str1 });
            }
            else
            {
                IMU e2 = new IMU();
                str1 = e2.GetName();
                Invoke(new show(showTextbox), new object[] { str1 });
            }
        }

        /// <summary>
        /// 如果用简单工厂
        /// </summary>
        /// <param name="className"></param>
        private void button2_Encapsulation(string className)
        {
            IEquip e3 = EquipSimpleFactory.CreateFactory(className);
            string str1 = e3.GetName();
            Invoke(new show(showTextbox), new object[] { str1 });
        }

        private void button3_Click(object sender, EventArgs e)
        {
            #region 教程的版本

            // 如果客户又想点肉末茄子了
            // 再另外初始化一个肉末茄子工厂
            Creator minceMeatEggplantFactor = new MincedMeatEggplantFactory();

            // 利用肉末茄子工厂来创建肉末茄子这道菜
            Food minceMeatEggplant = minceMeatEggplantFactor.CreateFoddFactory();
            minceMeatEggplant.Print();

            Invoke(new show(showTextbox), new object[] { minceMeatEggplant.FoodName });

            #endregion

            #region 自己的版本

            IEquipCreator IEC;
            string str1;
            //已经有了gps和imu类
            IEC = new GpsFactory();
            IEquip _gps = IEC.CreateFactory();
            str1 = _gps.GetName();
            Invoke(new show(showTextbox), new object[] { str1 });

            IEC = new IMUFactory();
            IEquip _imu = IEC.CreateFactory();
            str1 = _imu.GetName();
            Invoke(new show(showTextbox), new object[] { str1 });
            //现在新增camera类，新增和调用时都不需要对原有类进行修改
            IEC = new CameraFactory();
            IEquip _camera = IEC.CreateFactory();
            str1 = _camera.GetName();
            Invoke(new show(showTextbox), new object[] { str1 });

            #endregion
        }

        private void button4_Click(object sender, EventArgs e)
        {
            // 南昌工厂制作南昌的鸭脖和鸭架
            AbstractFactory nanChangFactory = new NanChangFactory();
            YaBo nanChangYabo = nanChangFactory.CreateYaBo();
            nanChangYabo.Print();
            YaJia nanChangYajia = nanChangFactory.CreateYaJia();
            nanChangYajia.Print();

            // 上海工厂制作上海的鸭脖和鸭架
            AbstractFactory shangHaiFactory = new ShangHaiFactory();
            shangHaiFactory.CreateYaBo().Print();
            shangHaiFactory.CreateYaJia().Print();

            // 自己写的
            AbstractFactoryClient.Test();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            BuilderUser.test();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Prototype.Client.test();
            Prototype.MyClient.test();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            Adapter.Client.test();
            Adapter.MyClient.test();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            Bridge.Client.test();
            Bridge.MyClient.test();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            Decorator.Customer.test();
            Decorator.MyClient.test();
        }

        private void button10_Click(object sender, EventArgs e)
        {
            Composite.MyClient.test();
        }
    }
}
