using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Mammal
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

        private void button1_Click(object sender, EventArgs e)
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
            textBox1.AppendText(dog.getMType() + " " + dog.getName() +" " + dog.getOwner());
            person.setName("Joonas Kinnunen");
            person.setAge(33);
            textBox1.AppendText(Environment.NewLine);
            textBox1.AppendText(person.getMType() + " " + person.getName() + " " + person.getAge());
        }
    }

    public class Mammal
    {
        private string mType, mName;

        public Mammal(string type)
        {
            mType = type;
        }

        public string getMType()
        {
            return mType;
        }

        public void setName(string name)
        {
            mName = name;
        }

        public string getName()
        {
            return mName;
        }
    }

    public class Person:Mammal
    {
        private int mAge;
        public Person(int age):base("PERSON")
        {
            mAge = age;
        }

        public void setAge(int age)
        {
            mAge = age;
        }

        public int getAge()
        {
            return mAge;
        }

    }

    public class Dog:Mammal
    {
        private string mOwner;
        public Dog(string owner) : base("DOG")
        {
            mOwner = owner;
        }

        public void setOwner(string owner)
        {
            mOwner = owner;
        }

        public string getOwner()
        {
            return mOwner;
        }
    }
}
