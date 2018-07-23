using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DesignPattern
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        delegate void show(string data);
        public void showTextbox(string data)
        {
            textBox1.Text += data + Environment.NewLine;
        }

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
        }

        private void button3_Click(object sender, EventArgs e)
        {
            // 如果客户又想点肉末茄子了
            // 再另外初始化一个肉末茄子工厂
            Creator minceMeatEggplantFactor = new MincedMeatEggplantFactory();

            // 利用肉末茄子工厂来创建肉末茄子这道菜
            Food minceMeatEggplant = minceMeatEggplantFactor.CreateFoddFactory();
            minceMeatEggplant.Print();

            Invoke(new show(showTextbox), new object[] { minceMeatEggplant.FoodName });
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

            Console.Read();
        }
    }
}
