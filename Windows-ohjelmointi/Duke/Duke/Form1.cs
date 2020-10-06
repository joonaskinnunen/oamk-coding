using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Duke
{
    public partial class Form1 : Form
    {
        private System.Windows.Forms.ImageList imageList;
        int counter = 0;
        public Form1()
        {
            InitializeComponent();
            imageList = new ImageList();

            timer1.Interval = 200;
            timer1.Tick += new EventHandler(timer1_Tick);

            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            pictureBox1.Image = imageList.Images[counter];
            counter++;
            if (counter > 9) counter = 0;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            for(int i = 1; i <= 10; i++)
            {
                imageList.Images.Add(Image.FromFile(@"media\duke\T" + i + ".png"));
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            timer1.Enabled = true;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            timer1.Enabled = false;
        }
    }
}
