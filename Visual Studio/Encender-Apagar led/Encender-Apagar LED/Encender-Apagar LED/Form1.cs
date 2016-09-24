using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;

namespace Encender_Apagar_LED
{
    public partial class Form1 : Form
    {
        //Utilizamos un string como Buffer de recepcion
        string Recibidos;
        public Form1()
        {
            InitializeComponent();
            //Abrir el puerto mientras se ejecute aplicacion
            if (!serialPort1.IsOpen)
            {
                try
                {
                    serialPort1.Open();
                }
                catch (System.Exception ex)
                {
                    MessageBox.Show(ex.ToString());
                }
            }
            //Ejecutar la funcion Recepcion por disparo del Evento 'DataReceived'
            serialPort1.DataReceived += new
            System.IO.Ports.SerialDataReceivedEventHandler(Recepcion);
        }
        //Al Recibir datos
        private void Recepcion(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            //Acumular los caracteres recibidos a nuestro Buffer (string)
            Recibidos += serialPort1.ReadExisting();
            //Invocar o llamar la proceso de tramas
            this.Invoke(new EventHandler(Actualizar));
        }
        //Procesar los datos recibidos en el buffer y extraer tramas completas
        private void Actualizar(object s, EventArgs e)
        {
            //Asignar el valor a la trama del texto
            textBox_visualizar_mensaje.Text = Recibidos;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x68; //Letra h en ascii
            serialPort1.Write(mBuffer, 0, mBuffer.Length);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x6C; //Letra l en ascii
            serialPort1.Write(mBuffer, 0, mBuffer.Length);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            statusStrip1.Items[0].Text = DateTime.Now.ToLongTimeString();
        }
    }
}
