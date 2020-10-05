using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Mammal2
{
    public class Person : Mammal
    {
        private int mAge;
        public Person(int age) : base("PERSON")
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
}
