using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace NumberGame
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            int numberOne, numberTwo, numberThree;

            bool successOne = Int32.TryParse(textBox1.Text, out numberOne);
            bool successTwo = Int32.TryParse(textBox2.Text, out numberTwo);
            bool successThree = Int32.TryParse(textBox3.Text, out numberThree);
            if (successOne && successTwo && successThree)
            {
                if (numberOne >= 0 && numberOne < 100 && numberTwo >= 0 && numberTwo < 100 && numberThree >= 0 && numberThree < 100)
                {
                    if (numberOne == 3 && numberTwo == 10 && numberThree == 44)
                    {
                        textBox4.Text = "Your answer was correct!";
                    }
                    else
                    {
                        textBox4.Text = "Your answer was wrong!";
                    }
                }
                else
                {
                    MessageBox.Show("Value(s) not between 0-99! Please re-enter new values", "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);

                }
            }
            else
            {
                MessageBox.Show("Not integer value(s)! Please re-enter new values", "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }
    }
}
