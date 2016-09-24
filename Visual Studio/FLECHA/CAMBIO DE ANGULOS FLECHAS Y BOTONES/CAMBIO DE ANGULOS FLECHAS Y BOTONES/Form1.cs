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
        private int posicion;
        public Form1()
        {
            InitializeComponent();
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
        }

        #region PULSAR FLECHAS
        protected override bool ProcessCmdKey(ref Message m, Keys keyData)
        {
            bool blnProcess = false;
            if (keyData == Keys.Left)
            {
                if(posicion >=0 && posicion <180)
                {
                    posicion += 10;
                }
                label1.Text = posicion.ToString();
                blnProcess = true;
                byte[] mBuffer = new byte[1];
                mBuffer[0] = 0x49; //Letra I en ascii
                serialPort1.Write(mBuffer, 0, mBuffer.Length);
            }

            if (keyData == Keys.Right)
            {
                if (posicion > 0 && posicion <= 180)
                {
                    posicion -= 10;
                }
                label1.Text = posicion.ToString();
                blnProcess = true;
                byte[] mBuffer = new byte[1];
                mBuffer[0] = 0x44; //Letra D en ascii
                serialPort1.Write(mBuffer, 0, mBuffer.Length);
            }

            if(blnProcess == true)
            {
                return true;
            }
            else
            {
                return base.ProcessCmdKey(ref m, keyData);
            }
        }
        #endregion

        #region PULSAR BOTONES
        private void btIzq_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x49; //Letra I en ascii
            serialPort1.Write(mBuffer, 0, mBuffer.Length);
            if (posicion >= 0 && posicion < 180)
            {
                posicion += 10;
            }
            label1.Text = posicion.ToString();
        }

        private void btDer_Click(object sender, EventArgs e)
        {
            byte[] mBuffer = new byte[1];
            mBuffer[0] = 0x44; //Letra D en ascii
            serialPort1.Write(mBuffer, 0, mBuffer.Length);
            if (posicion > 0 && posicion <= 180)
            {
                posicion -= 10;
            }
            label1.Text = posicion.ToString();
        }
        #endregion
    }
}