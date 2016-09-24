using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int lado;
            int superficie;
            String linea;
            Console.Write("Ingrese el valor del lado:");
            linea = Console.ReadLine();
            lado = int.Parse(linea);
            superficie = lado * lado;
            Console.Write("El valor de la superficie es:");
            Console.Write(superficie);
            Console.ReadKey();
        }
    }
}
