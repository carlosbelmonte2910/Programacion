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
        //private int posicion;
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

        #region LISTAR COM EN COMBOBOX
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
                habilitar(true, true, false, false, false, false, false);
            }
        }
        #endregion

        #region HABILITACIONES
        private void habilitar(bool COM, bool conectar, bool desconectar, bool automovil, bool camara, bool brazo, bool Luz)
        {
            comboBoxPuertos.Enabled = COM;
            botonConectar.Enabled = conectar;
            botonDesconectar.Enabled = desconectar;
            groupBoxLuces.Enabled = Luz;
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

        #region Boton DESCONECTAR
        private void botonDesconectar_Click(object sender, EventArgs e)
        {
            cerrarPuerto();
        }
        #endregion

        #region Boton CONECTAR
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
                    habilitar(false, false, true, true, true, true, true);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(this, "NO ES POSIBLE LA CONEXION. \n" + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        #endregion

        #region Cerrar Formulario
        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            cerrarPuerto();
        }
        #endregion

        #region BOTONES AUTO
        private void bt1_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x41; //Letra 8 en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
      
        }

        private void bt2_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x42; //Letra 8 en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
            
        }

        private void bt3_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x43; //Letra 4 en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
            
        }

        private void bt4_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x44; //Letra 6 en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
            
        }
        #endregion

        #region BOTONES CAMARA
        private void bt5_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x45; //Letra J en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
        }

        private void bt6_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x46; //Letra L en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
        }

        private void bt7_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x47; //Letra I en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
        }

        private void bt8_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x48; //Letra K en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
        }
        #endregion

        #region BOTONES BRAZO
        private void bt9_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x49; //Letra A en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
        }

        private void bt10_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x4A; //Letra D en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
        }

        private void bt11_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x4B; //Letra W en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
        }

        private void bt12_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x4C; //Letra S en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
        }

        private void bt13_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x4D; //Letra Z en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
        }

        private void bt14_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x4E; //Letra X en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
        }
        #endregion


        private void bt15_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x4F; //Letra G en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
        }

        private void bt16_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x50; //Letra B en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
        }

        private void bt17_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x51; //Letra B en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
        }

        private void bt18_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x52; //Letra B en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
        }

        private void bt19_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x53; //Letra B en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
        }

        private void bt20_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x54; //Letra B en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
        }

        private void bt00_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Properties.Resources.Gráfico2;
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x55; //Letra B en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
            System.Threading.Thread.Sleep(50);
            byte[] PBuffer = new byte[1];
            PBuffer[0] = 0x55; //Letra B en ascii
            Puerto.Write(PBuffer, 0, PBuffer.Length);
        }

        private void btEnviarMinutos_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x2A; //Letra B en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
            System.Threading.Thread.Sleep(15);
            Puerto.Write(textMinuto.Text.ToString());
        }

        private void btEnviarHora_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x2B; //Letra B en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
            System.Threading.Thread.Sleep(15);
            Puerto.Write(textHora.Text.ToString());
        }

        private void textHora_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (textHora.TextLength == 2)
            {
                textMinuto.Focus();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string fallas = "";
            fallas = listBox2.Text;
            //listBox1.Items.Clear();
            byte[] mBuffer = new byte[1];
            switch (fallas)
            {
                case "01 - Falta de caña":
                    mBuffer[0] = 0x41;
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
                case "02 - Falla en usina (SIEMENS)":
                    mBuffer[0] = 0x42; //Letra L en ascii
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
                case "03 - Falla en usina (MARELLI)":
                    mBuffer[0] = 0x43;
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
                case "04 - Falla en Caldera 1":
                    mBuffer[0] = 0x44; //Letra L en ascii
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
                case "05 - Falla en Caldera 2":
                    mBuffer[0] = 0x45;
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
                case "06 - Falla en Caldera 3":
                    mBuffer[0] = 0x46; //Letra L en ascii
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
                case "07 - Falla en Caldera 4":
                    mBuffer[0] = 0x47;
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
                case "08 - Baja presion de vapor":
                    mBuffer[0] = 0x48; //Letra L en ascii
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
                case "09 - Falta de gas":
                    mBuffer[0] = 0x49; //Letra L en ascii
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
                case "10 - Atascamiento de molino 1":
                    mBuffer[0] = 0x4A; //Letra L en ascii
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
                case "11 - Atascamiento de molino 2":
                    mBuffer[0] = 0x4B; //Letra L en ascii
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
                case "12 - Atascamiento de molino 3":
                    mBuffer[0] = 0x4C; //Letra L en ascii
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
                case "13 - Falla en encaladora":
                    mBuffer[0] = 0x4D; //Letra L en ascii
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
                case "14 - Falla horno de azufre":
                    mBuffer[0] = 0x4E; //Letra L en ascii
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
                case "15 - Rotura cinta de bagacera":
                    mBuffer[0] = 0x4F; //Letra L en ascii
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
                case "16 - Fallas en centrifugas":
                    mBuffer[0] = 0x50; //Letra L en ascii
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
                case "17 - Filtro de cachaza atascado":
                    mBuffer[0] = 0x51; //Letra L en ascii
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
                case "18 - Falla en calentadores":
                    mBuffer[0] = 0x52; //Letra L en ascii
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
                case "19 - Falla en cristalizadores":
                    mBuffer[0] = 0x53; //Letra L en ascii
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
                case "20 - Falla tolva de azucar":
                    mBuffer[0] = 0x54; //Letra L en ascii
                    Puerto.Write(mBuffer, 0, mBuffer.Length);
                    break;
            }

        }

      

        private void listBox2_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Properties.Resources.Gráfico1;
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x2F; //Letra B en ascii
            Puerto.Write(mBuffer, 0, mBuffer.Length);
            System.Threading.Thread.Sleep(10);
        }
    }
}

        

