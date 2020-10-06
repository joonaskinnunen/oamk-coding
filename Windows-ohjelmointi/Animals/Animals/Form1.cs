using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Animals
{
    public partial class Form1 : Form
    {
        System.Media.SoundPlayer player;
        public Form1()
        {
            InitializeComponent();
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox2.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox3.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox4.SizeMode = PictureBoxSizeMode.StretchImage;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            player = new System.Media.SoundPlayer(@"media\wolf.wav");
            player.Play();
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            player = new System.Media.SoundPlayer(@"media\bear.wav");
            player.Play();
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            player = new System.Media.SoundPlayer(@"media\lamb.wav");
            player.Play();
        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {
            player = new System.Media.SoundPlayer(@"media\elephant.wav");
            player.Play();
        }
    }
}
