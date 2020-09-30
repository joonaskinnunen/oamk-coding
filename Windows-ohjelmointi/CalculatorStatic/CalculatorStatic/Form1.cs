using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CalculatorStatic
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

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            double firstInput, secondInput;
            if (!Double.TryParse(textBox1.Text, out firstInput))
            {
                labelResult.Text = "First input invalid. Hint: use comma instead of dot.";
            }
            else if (!Double.TryParse(textBox2.Text, out secondInput))
            {
                labelResult.Text = "Second input invalid. Hint: use comma instead of dot.";
            }
            else
            {
                labelResult.Text = "Result is: " + Calculate.Add(firstInput, secondInput);
            }
        }

        private void buttonMinus_Click(object sender, EventArgs e)
        {
            double firstInput, secondInput;
            if (!Double.TryParse(textBox1.Text, out firstInput))
            {
                labelResult.Text = "First input invalid. Hint: use comma instead of dot.";
            }
            else if (!Double.TryParse(textBox2.Text, out secondInput))
            {
                labelResult.Text = "Second input invalid. Hint: use comma instead of dot.";
            }
            else
            {
                labelResult.Text = "Result is: " + Calculate.Minus(firstInput, secondInput);
            }
        }

        private void buttonMul_Click(object sender, EventArgs e)
        {
            double firstInput, secondInput;
            if (!Double.TryParse(textBox1.Text, out firstInput))
            {
                labelResult.Text = "First input invalid. Hint: use comma instead of dot.";
            }
            else if (!Double.TryParse(textBox2.Text, out secondInput))
            {
                labelResult.Text = "Second input invalid. Hint: use comma instead of dot.";
            }
            else
            {
                labelResult.Text = "Result is: " + Calculate.Mul(firstInput, secondInput);
            }
        }

        private void buttonDiv_Click(object sender, EventArgs e)
        {
            double firstInput, secondInput;
            if (!Double.TryParse(textBox1.Text, out firstInput))
            {
                labelResult.Text = "First input invalid. Hint: use comma instead of dot.";
            }
            else if (!Double.TryParse(textBox2.Text, out secondInput))
            {
                labelResult.Text = "Second input invalid. Hint: use comma instead of dot.";
            }
            else
            {
                labelResult.Text = "Result is: " + Calculate.Div(firstInput, secondInput);
            }
        }
    }

    public class Calculate
    {
        public static double Add(double firstNum, double secondNum)
        {
            return firstNum + secondNum;
        }

        public static double Minus(double firstNum, double secondNum)
        {
            return firstNum - secondNum;
        }

        public static double Mul(double firstNum, double secondNum)
        {
            return firstNum * secondNum;
        }

        public static double Div(double firstNum, double secondNum)
        {
            return firstNum / secondNum;
        }
    }
}
