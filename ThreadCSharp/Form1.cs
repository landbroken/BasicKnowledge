using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ThreadCSharp
{
    public partial class Form1 : Form
    {
        const int cycleNum = 15;
        static AutoResetEvent myEvent = new AutoResetEvent(false);

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        public void testFun(object obj)
        {
            string output = $"{"Begin:" + DateTime.Now.ToString()}:第{obj.ToString()}个线程";
            SetMessage(textBox1, output);
            Thread.Sleep(3000);
            string end = $"{"End:" + DateTime.Now.ToString()}:第{obj.ToString()}个线程";
            SetMessage(textBox1, end);
            if (obj.ToString() == "10")
            {
                myEvent.Set();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SetMessage(textBox1, $"主线程执行！{DateTime.Now.ToString()}");
            ThreadPool.SetMinThreads(1, 1);
            ThreadPool.SetMaxThreads(5, 5);
            for (int i = 1; i <= cycleNum; i++)
            {
                ThreadPool.QueueUserWorkItem(new WaitCallback(testFun), i.ToString());
            }
            SetMessage(textBox1, $"主线程结束！{DateTime.Now.ToString()}");
            myEvent.WaitOne();
            SetMessage(textBox1, $"线程池终止！{DateTime.Now.ToString()}");
        }

        delegate void SetMessageCallBack(TextBox txtIn, string MyMessage);
        private void SetMessage(TextBox txtIn, string MyMessageIn)
        {
            try
            {
                if (!MyMessageIn.EndsWith(Environment.NewLine))
                {
                    MyMessageIn += Environment.NewLine;//加上换行符
                }
                if (this.InvokeRequired)
                {
                    SetMessageCallBack tmpMessage = new SetMessageCallBack(SetMessage);
                    this.BeginInvoke(tmpMessage, new object[] { txtIn, MyMessageIn });
                }
                else
                {
                    txtIn.Text += MyMessageIn;
                }
            }
            catch (Exception ex)
            {
                //线程时间太短，容易在关闭窗口时引起异常：
                //无法访问已释放的对象。对象名:“Form1”。
                string tmp = ex.Message;
            }
        }
    }
}
