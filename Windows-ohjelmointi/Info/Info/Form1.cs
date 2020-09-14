using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Info
{
    public partial class FormFavCountry : Form
    {
        public FormFavCountry()
        {
            InitializeComponent();
        }

        private void buttonPrint_Click(object sender, EventArgs e)
        {
            String str = textBoxNickname.Text + ":" ;
            if(checkBoxIceCream.Checked)
            {
                str += " I like ice cream. ";
            } else
            {
                str += " I dont like ice cream. ";
            }
            str += groupBoxAge.Text + " ";
            if(radioButtonYoung.Checked)
            {
                str += radioButtonYoung.Text;
            } else if(radioButtonMiddle.Checked)
            {
                str += radioButtonMiddle.Text;
            } else if(radioButtonOld.Checked)
            {
                str += radioButtonOld.Text;
            } else
            {
                str += "unknown";
            }
            textBoxResults.Text = str + ". " + labelCountry.Text + " " + listBoxCountry.SelectedItem.ToString();
        }

        private void FormFavCountry_Load(object sender, EventArgs e)
        {
            listBoxCountry.SelectedIndex = 0;
        }
    }
}
