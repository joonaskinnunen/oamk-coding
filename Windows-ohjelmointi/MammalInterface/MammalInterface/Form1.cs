using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MammalInterface
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
            Dog dog = new Dog("Joonas", "DOG");
            dog.SetName("Nalle");
            textBox1.AppendText(dog.GetName() + ", owner: " + dog.GetOwner());
            Person person = new Person(29, "PERSON");
            person.SetName("Joonas Kinnunen");
            textBox1.AppendText(Environment.NewLine);
            textBox1.AppendText(person.GetMType() + ": " + person.GetName() + ", age: " + person.GetAge());
            person.SetAge(35);
            textBox1.AppendText(Environment.NewLine);
            textBox1.AppendText(person.GetMType() + ": " + person.GetName() + ", age: " + person.GetAge());
        }
    }

    public interface IId
    {
        string MType
        {
            get;
        }

        string GetMType();
    }

    public class Mammal
    {
        public string mName;

        public void SetName(string name)
        {
            mName = name;
        }

        public string GetName()
        {
            return mName;
        }
    }

    public class Person : Mammal, IId
    {
        private int mAge;
        private string mType;
        public string MType
        {
            get
            {
                return mType;
            }

        }

        public Person(int age, string type)
        {
            mAge = age;
            mType = type;
        }

        public void SetAge(int age)
        {
            mAge = age;
        }

        public int GetAge()
        {
            return mAge;
        }

        public string GetMType()
        {
            return "Object type is " + this.mType;
        }
    }

    public class Dog : Mammal, IId
    {
        private string mOwner;
        private string mType;
        public string MType
        {
            get
            {
                return mType;
            }

        }

        public Dog(string owner, string type)
        {
            mOwner = owner;
            mType = type;
        }

        public void SetOwner(string owner)
        {
            mOwner = owner;
        }

        public string GetOwner()
        {
            return mOwner;
        }

        public string GetMType()
        {
            return "Object type is " + this.mType;
        }
    }
}
