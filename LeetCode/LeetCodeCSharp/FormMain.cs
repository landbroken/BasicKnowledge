using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using LeetCode.算法;

namespace LeetCode
{
    public partial class FormMain : Form
    {
        public FormMain()
        {
            InitializeComponent();
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            int num = Convert.ToInt32(txtNum.Text);
            _709 t_709 = new _709();
            var ret_709 = t_709.ToLowerCase("PiTAs");
            string output = ret_709.ToString();
            txtOut.Text = output;
        }


    }
}
