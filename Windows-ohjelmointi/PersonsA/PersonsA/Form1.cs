using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PersonsA
{
    public partial class Form1 : Form
    {
        string[] persons = new string[10];
        int index = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void saveButton_Click(object sender, EventArgs e)
        {
            persons[index] = textBoxFname.Text + " " + textBoxLname.Text + " " + textBoxAge.Text;
            index++;
            if (index > 9) buttonSave.Enabled = false;
            textBoxFname.Text = "";
            textBoxLname.Text = "";
            textBoxAge.Text = "";

        }

        private void buttonPrint_Click(object sender, EventArgs e)
        {
            textBoxPersons.Text = "";
            for(int i = 0; i < index; i++)
            {
                textBoxPersons.AppendText(persons[i]);
                if (i < index - 1) textBoxPersons.AppendText(Environment.NewLine);
            }

        }
    }
}
