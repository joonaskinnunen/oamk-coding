using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LinkLabel
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            this.linkLabel1.AutoSize = true;
            this.linkLabel1.Text = "Ilta-sanomat";
            this.linkLabel2.AutoSize = true;
            this.linkLabel2.Text = "Excel";
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            this.linkLabel1.LinkVisited = true;
            System.Diagnostics.Process.Start("https://is.fi");

        }

        private void linkLabel2_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start(@"C:\Users\Joonas Kinnunen\Downloads\excelfile.xlsx");
        }
    }
}
