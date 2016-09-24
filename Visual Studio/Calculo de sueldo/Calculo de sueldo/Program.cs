using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Calculo_de_sueldo
{
    class Program
    {
        static void Main(string[] args)
        {
            int horasTrabajadas;
            float costoHora;
            float sueldo;
            string linea;
            Console.Write("Ingrese las horas trabajadas por el operario:");//Muestra mensajes en pantalla.
            linea = Console.ReadLine();//Ingresa por teclado un conjunto de caracteres
            horasTrabajadas = int.Parse(linea); //Convierte el string LINEA en entero y lo almacena en horasTrabajadas
            Console.Write("Ingrese el pago por la hora:");
            linea = Console.ReadLine();
            costoHora = float.Parse(linea);
            sueldo = horasTrabajadas * costoHora;
            Console.Write("El sueldo total del operario es:");
            Console.Write(sueldo);//Cuando esta sin comillas " " muestra el valor almacenado en la variable
            Console.ReadKey();
        }
    }
}
