using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DiceGame
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        List<Player> players = new List<Player>();
        int result = 0;

        private void buttonStart_Click(object sender, EventArgs e)
        {
            Random ran = new Random();
            int[] num = new int[5];
            result = 0;
            for (int i = 0; i < 5; i++) {
                num[i] = ran.Next(6) + 1;
                result = result + num[i];
            }
            drawDices(num);
            labelResult.Text = "Result is " + result;
            buttonSave.Enabled = true;
        }

        private void drawDices(int[] diceValues)
        {
            pictureBox1.Image = Image.FromFile(@"Images\dice" + diceValues[0] + ".png");
            pictureBox2.Image = Image.FromFile(@"Images\dice" + diceValues[1] + ".png");
            pictureBox3.Image = Image.FromFile(@"Images\dice" + diceValues[2] + ".png");
            pictureBox4.Image = Image.FromFile(@"Images\dice" + diceValues[3] + ".png");
            pictureBox5.Image = Image.FromFile(@"Images\dice" + diceValues[4] + ".png");
        }

        private void textBoxName_TextChanged(object sender, EventArgs e)
        {
            buttonStart.Enabled = false;
            if (textBoxName.TextLength > 2)
            {
                buttonStart.Enabled = true;
            }
            else
            {
                buttonStart.Enabled = false;
            }
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            players.Add(new Player(textBoxName.Text, result));
            textBoxName.Text = "";
            buttonSave.Enabled = false;
        }

        private void buttonPrint_Click(object sender, EventArgs e)
        {
            textBoxResults.Text = "";
            foreach(Player aPlayer in players)
            {
                textBoxResults.AppendText(aPlayer.GetName() + " " + aPlayer.GetPoints() + Environment.NewLine);
            }
        }
    }

    class Player
    {
        private string mName;
        private int mPoints;

        public Player(string name, int points)
        {
            mName = name;
            mPoints = points;
        }

        public string GetName()
        {
            return mName;
        }

        public int GetPoints()
        {
            return mPoints;
        }
    }
}
