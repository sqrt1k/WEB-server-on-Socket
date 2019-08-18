using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
        }
    }
    public class x1110bdd110cdcea4
    {
        public x1110bdd110cdcea4() : base()
        {
        }
        public static string _xaacba899487bce8c(string x5e99b576d2530d13, int x2710752c36f2d14b)
        {
            ushort usht;
            char[] arrch;
            int i;
            ushort usht1;
            string str;
            usht = (ushort)x2710752c36f2d14b;

            goto ILO_007f;

            while (true)
            {
                i++;
            ILO_000c:
                if (i < (x5e99b576d2530d13.Length / 4))
                {
                    break;
                }
                str = new string(arrch);
                if (!0.Equals(0))
                {
                    goto ILO_008d;
                }
                return str;
            ILO_0027:
                arrch[i] = (char)usht1;
                usht += 1789;
            }
            usht1 = (ushort)((((x5e99b576d2530d13[4 * i] - 'a') + ((x5e99b576d2530d13[(4 * i) + 1] - 'a') << '\u0004')) + ((x5e99b576d2530d13[(4 * i) + 2] - 'a') << '\u0008')) + ((x5e99b576d2530d13[(4 * i) + 3] - 'a') << '\u000c'));
            usht1 -= usht;

            goto ILO_0027;

        ILO_007f:
            arrch = new char[x5e99b576d2530d13.Length / 4];
        ILO_008d:
            i = 0;
            if ((((((uint)usht)) + (((uint)usht1))) > -1))
            {
                goto ILO_008d;
            }
            goto ILO_000c;
            return str;
        }
    }

}
