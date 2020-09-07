using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MouseEvent
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.panel1.MouseEnter += new EventHandler(this.panel1_MouseEnter);
            this.panel1.MouseLeave += new EventHandler(this.panel1_MouseLeave);
            this.panel1.MouseMove += new MouseEventHandler(this.panel1_MouseMove);
            this.button1.MouseEnter += new EventHandler(this.button1_MouseEnter);
            this.button1.MouseLeave += new EventHandler(this.button1_MouseLeave);
            this.button1.MouseMove += new MouseEventHandler(this.button1_MouseMove);
        }

        private void panel1_MouseEnter(object sender, EventArgs e)
        {
            textBox1.Text = panel1.Name + ": MouseEnter";
            Cursor = Cursors.Cross;
        }

        private void panel1_MouseLeave(object sender, EventArgs e)
        {
            textBox1.Text = panel1.Name + ": MouseLeave";
            Cursor = Cursors.Default;
        }

        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {
            textBox1.Text = panel1.Name + ": MouseMove";
        }

        private void button1_MouseEnter(object sender, EventArgs e)
        {
            textBox1.Text = button1.Name + ": MouseEnter";
            Cursor = Cursors.Hand;

        }

        private void button1_MouseLeave(object sender, EventArgs e)
        {
            textBox1.Text = button1.Name + ": MouseLeave";
            Cursor = Cursors.Default;
        }

        private void button1_MouseMove(object sender, MouseEventArgs e)
        {
            textBox1.Text = button1.Name + ": MouseMove";
        }
    }
}
