using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Mammal2
{
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
}
