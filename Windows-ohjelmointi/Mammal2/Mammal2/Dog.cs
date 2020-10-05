using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Mammal2
{
    public class Dog : Mammal
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
