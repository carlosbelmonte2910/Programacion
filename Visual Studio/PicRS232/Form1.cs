using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;
using System.Diagnostics;

namespace PicRS232
{
    public partial class Form1_Principal : Form
    {
        #region Envío de datos RS232.
        // Utilizaremos un string como buffer de recepción
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
        #endregion

        #region Reloj y salir.
        private void timer1_Tick(object sender, EventArgs e)
        {
            statusStrip1.Items[0].Text = DateTime.Now.ToLongTimeString();
        }

        private void salirToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }
        #endregion

        private void contenidoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Si deseamos añador un nombre y extensión añadir aquí.
            // Buscará cualquier extensión nombrada aquí.
            String[] oFile = {
                                 Application.StartupPath + @"\manual.pdf",
                                 Application.StartupPath + @"\manual.xps",
                                 Application.StartupPath + @"\manual.htm",
                                 Application.StartupPath + @"\manual.html",
                                 Application.StartupPath + @"\manual.doc",
                                 Application.StartupPath + @"\manual.docx",
                                 Application.StartupPath + @"\manual.hlp",
                                 Application.StartupPath + @"\manual.chm"                 
                               };

            String manual = null;
            for (int nFile = 0; nFile < oFile.Length; nFile++)
            {
                if (System.IO.File.Exists(oFile[nFile]))
                {
                    manual = oFile[nFile];
                    break;
                }
            }

            if (manual != null)
            {
                System.Diagnostics.Process.Start(manual);
            }
            else
            {       // Mensaje de aviso.
                MessageBox.Show("No se ha encontrado ningún archivo de ayuda \n" +
                                "con su nombre correspondiente o no está en la \n" +
                                "misma ubicación de esta aplicación. \n" +
                                "\n" +
                                "Archivos a localizar:\n" +
                                "\n" +
                                "manual.pdf \n" +
                                "manual.xps \n" +
                                "manual.htm \n" +
                                "manual.html \n" +
                                "manual.doc \n" +
                                "manual.docx \n" +
                                "manual.hlp \n" +
                                "manual.chm \n", "Aviso:",
                MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        private void acercaDeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("ControlPIC v1.00.00 \n\n" +
                            "Autor: Ángel Acaymo M. G. \n" +
                            "Contacto: mi@e-mail.com \n\n" +
                            "http://www.pic16f84a.org \n" +
                            "http://usuarios.lycos.es/electronicapic \n\n" +
                            "LICENCIA: \n" +
                            " \n" +
                            "Si no sabes qué quiere decir que un programa sea freeware, te lo explico: \n" +
                            "significa que es gratis, es decir, que no deberás desembolsar ninguna\n" +
                            "cantidad de dinero por su uso. Eso sí, que sea gratis no quiere decir que\n" +
                            "puedas hacer con el programa lo que se te antoje. Por ejemplo, no puedes \n" +
                            "modificar su código sin mi consentimiento expreso; en caso contrario, \n" +
                            "estarás violando el copyright de este programa.", "Acerca de ControlPIC",
                               MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void acercaDe2ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form f = new AcercaDe();
            f.ShowDialog();
        }
    }
}
