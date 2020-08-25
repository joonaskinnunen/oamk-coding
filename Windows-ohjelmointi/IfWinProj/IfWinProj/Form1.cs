using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IfWinProj
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            int inputInt;
            Int32.TryParse(textBox1.Text, out inputInt);
            if(inputInt == 1)
            {
                label2.Text = "You won a new boat!!!";
            } else if(inputInt == 2)
            {
                label2.Text = "You won 1000€!!!";
            }
            else if (inputInt == 3)
            {
                label2.Text = "You won a new house!!!";
            } else
            {
                label2.Text = "Unknown selection!";
            }
        }
    }
}
