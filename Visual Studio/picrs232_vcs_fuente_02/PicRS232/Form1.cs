using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;

namespace PicRS232
{
    public partial class Form1_Principal : Form
    {
        // Utilizaremos un string como buffer de recepcion
        string Recibidos;
        public Form1_Principal()
        {
            InitializeComponent();
            // Abrir puerto mientra se ejecute la aplicación
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
            // Ejecutar la funcion Recepcion por disparo del Evento 'DataReived'
            serialPort1.DataReceived += new
            System.IO.Ports.SerialDataReceivedEventHandler(Recepcion);
        }
        // Al recibir los datos
        private void Recepcion(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            // Acumular los carácteres recibidos a nuestro 'buffer' (string)
            Recibidos += serialPort1.ReadExisting();
            // Invocar o llamar al proceso de tramas
            this.Invoke(new EventHandler(Actualizar));
        }
        // Procesar los datos recibidos en el buffer y extraer tramas completas
        private void Actualizar(object s, EventArgs e)
        {
            // Asignar el valor de la trama al textBox
            textBox_visualizar_mensaje.Text = Recibidos;
        }
        private void button_t_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x74; //ASCII letra "t".
            serialPort1.Write(mBuffer, 0, mBuffer.Length);
        }

        private void button_b_Click(object sender, EventArgs e)
        {
            byte[] miBuffer = new byte[1];
            miBuffer[0] = 0x62; //ASCII letra "b".
            serialPort1.Write(miBuffer, 0, miBuffer.Length);
        }

        private void button_a_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x61; //ASCII letra "a".
            serialPort1.Write(mBuffer, 0, mBuffer.Length);
        }

        private void button_l_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x6C; //ASCII letra "l".
            serialPort1.Write(mBuffer, 0, mBuffer.Length);
        }

        private void button_Espacio_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x20; //ASCII letra "Espacio".
            serialPort1.Write(mBuffer, 0, mBuffer.Length);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            statusStrip1.Items[0].Text = DateTime.Now.ToLongTimeString();
        }
    }
}
