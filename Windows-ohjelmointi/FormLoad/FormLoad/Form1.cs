using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FormLoad
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            textBox1.AppendText("Tom Jones");
            textBox1.AppendText(Environment.NewLine);
            textBox1.AppendText("John Smith");
            textBox1.AppendText(Environment.NewLine);
            textBox1.AppendText("David Osborne");
        }
    }
}
