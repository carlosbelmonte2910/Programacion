using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        private SerialPort Puerto;
        private string[] Puertos;
        public Form1()
        {
            InitializeComponent();
            listarPuertos();
        }

        #region STATUS
        private void defineStatus(bool status)
        {
            if (status == true)
            {
                statusLabel.Text = "Conectado";
                statusLabel.ForeColor = Color.Green;
            }
            else
            {
                statusLabel.Text = "Desconectado";
                statusLabel.ForeColor = Color.Red;
            }
        }
        #endregion

        #region LISTAR LOS COM EN COMBOBOX
        private void listarPuertos()
        {
            Puertos = SerialPort.GetPortNames();
            if (Puertos.Length > 0)
            {
                comboBoxPuertos.Items.Clear();
                //comboBoxPuertos.SelectedIndex = -1;

                foreach (string s in SerialPort.GetPortNames())
                {
                    comboBoxPuertos.Items.Add(s);
                }
                defineStatus(false);
                habilitar(true, true, false);
            }

        }
        #endregion

        #region HABILITACIONES
        private void habilitar(bool COM, bool conectar, bool desconectar)
        {
            comboBoxPuertos.Enabled = COM;
            botonConectar.Enabled = conectar;
            botonDesconectar.Enabled = desconectar;
        }
        #endregion

        #region CERRAR PUERTO
        private void cerrarPuerto()
        {
            if (Puerto != null && Puerto.IsOpen)
            {
                Puerto.Close();
                Puerto = null;
                defineStatus(false);
                listarPuertos();
            }
        }
        #endregion

        #region BOTON DESCONECTAR
        private void botonDesconectar_Click(object sender, EventArgs e)
        {
            cerrarPuerto();
        }
        #endregion

        #region BOTON CONECTAR
        private void botonConectar_Click(object sender, EventArgs e)
        {
            try
            {
                if (comboBoxPuertos.SelectedIndex != -1)
                {
                    Puerto = new SerialPort();
                    Puerto.PortName = comboBoxPuertos.SelectedItem.ToString();
                    Puerto.BaudRate = 9600;
                }
                else
                {
                    throw new Exception("Seleccione un puerto para conectar");
                }
                if (!Puerto.IsOpen)
                {
                    Puerto.Open();
                    defineStatus(true);
                    habilitar(false, false, true);
                }

            }
            catch (Exception ex)
            {
                MessageBox.Show(this, "NO ES POSIBLE LA CONEXION.\n" + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        #endregion 

        #region EXIT VENTANA
        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            cerrarPuerto();
        }
        #endregion


    }
}
