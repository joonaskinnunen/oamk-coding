using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Mammal2
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

        private void button1_Click_1(object sender, EventArgs e)
        {
            Person person = new Person(29);
            Dog dog = new Dog("Joonas Kinnunen");
            textBox1.AppendText(person.getMType() + " " + person.getName() + " " + person.getAge());
            textBox1.AppendText(Environment.NewLine);
            textBox1.AppendText(dog.getMType() + " " + dog.getName() + " " + dog.getOwner());
            dog.setName("Nalle");
            textBox1.AppendText(Environment.NewLine);
            textBox1.AppendText(dog.getMType() + " " + dog.getName() + " " + dog.getOwner());
            dog.setOwner("Aku Ankka");
            textBox1.AppendText(Environment.NewLine);
            textBox1.AppendText(dog.getMType() + " " + dog.getName() + " " + dog.getOwner());
            person.setName("Joonas Kinnunen");
            person.setAge(33);
            textBox1.AppendText(Environment.NewLine);
            textBox1.AppendText(person.getMType() + " " + person.getName() + " " + person.getAge());
        }
    }
}
