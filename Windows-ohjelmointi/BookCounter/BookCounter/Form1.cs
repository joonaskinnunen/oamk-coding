using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BookCounter
{
    public partial class Form1 : Form
    {
        private const int MAX_BOOK = 100;
        private Book[] bookArray = new Book[MAX_BOOK];

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void saveButton_Click(object sender, EventArgs e)
        {
            Book book = new Book(nameTextBox.Text, authorTextBox.Text);
            if(Book.counter < MAX_BOOK - 1)
            {
                bookArray[book.OrderNum - 1] = book;
                nameTextBox.Text = "";
                authorTextBox.Text = "";
            }
        }

        private void printButton_Click(object sender, EventArgs e)
        {
            resultsTextBox.Text = "";
            foreach(Book book in bookArray)
            {
                if(book != null)
                {
                    resultsTextBox.Text = resultsTextBox.Text + book.Name + " " + book.Author + " " + book.OrderNum + Environment.NewLine;
                }
            }
        }
    }

    public class Book
    {
        private string mName;
        private string mAuthor;
        private int mOrderNum;
        static public int counter = 1;

        public Book(string name, string author)
        {
            mName = name;
            mAuthor = author;
            mOrderNum = counter;
            counter++;
        }
        public string Name
        {
            get
            {
                return mName;
            }
            set
            {
                mName = value;
            }
        }

        public string Author
        {
            get
            {
                return mAuthor;
            }
            set
            {
                mAuthor = value;
            }
        }

        public int OrderNum
        {
            get
            {
                return mOrderNum;
            }
        }
    }

}
