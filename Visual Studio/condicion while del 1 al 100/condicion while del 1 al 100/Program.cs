using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace condicion_while_del_1_al_100
{
    class Program
    {
        static void Main(string[] args)
        {
            int x;
            x = 1;
            while (x <= 100)
            {
                Console.Write(x);
                Console.Write(" - ");
                x = x + 1;
            }
            Console.ReadKey();
        }
    }
}
