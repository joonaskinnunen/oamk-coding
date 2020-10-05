using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StudentsArrayList
{
    public partial class Form1 : Form
    {
        ArrayList studentsAl = new ArrayList();

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Student newStudent = new Student(textBox1.Text, int.Parse(textBox2.Text));
            studentsAl.Add(newStudent);
            textBox3.AppendText(newStudent.Name + " " + newStudent.Age);
            textBox3.AppendText(Environment.NewLine);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            double sum = 0;
            foreach(Student student in studentsAl)
            {
                sum += student.Age;
            }
            textBox4.Text = (sum / studentsAl.Count).ToString();
        }
    }

    public class Student
    {
        private string name;
        private int age;

        public Student(string name, int age)
        {
            this.name = name;
            this.age = age;
        }

        public string Name { get => name; set => name = value; }
        public int Age { get => age; set => age = value; }
    }
}
