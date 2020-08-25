using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CalculatorWin
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void CalculateResult(string oper)
        {
            double firstInput, secondInput;
            if (!Double.TryParse(firstInputField.Text, out firstInput))
            {
                label2.Text = "First input invalid. Hint: use comma instead of dot.";
            }
            else if (!Double.TryParse(secondInputField.Text, out secondInput))
            {
                label2.Text = "Second input invalid. Hint: use comma instead of dot.";
            }
            else
            {
                switch (oper) {
                    case "+":
                        label2.Text = "Result is: " + (firstInput + secondInput).ToString();
                    break;
                    case "-":
                        label2.Text = "Result is: " + (firstInput - secondInput).ToString();
                    break;
                    case "*":
                        label2.Text = "Result is: " + (firstInput * secondInput).ToString();
                    break;
                    case "/":
                        label2.Text = "Result is: " + (firstInput / secondInput).ToString();
                    break;
                }

            }
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void plusBtn_Click(object sender, EventArgs e)
        {
            CalculateResult("+");

        }

        private void minusBtn_Click(object sender, EventArgs e)
        {
            CalculateResult("-");
        }

        private void multiplyBtn_Click(object sender, EventArgs e)
        {
            CalculateResult("*");
        }

        private void divideBtn_Click(object sender, EventArgs e)
        {
            CalculateResult("/");
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
