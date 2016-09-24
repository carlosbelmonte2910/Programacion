using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Clave_seguridad
{
    public partial class Form2 : Form
    {

        private int posicion;
        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_FormClosing(object sender, FormClosingEventArgs e)
        {
            Application.Exit();
        }

        private void buttonIzq_Click(object sender, EventArgs e)
        {
            if (posicion >= 0 && posicion < 180)
            {
                posicion += 10;
            }

            labelGrados.Text = posicion.ToString();
        }

        private void buttonIzq_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)(Keys.Enter))
            {
                if (posicion >= 0 && posicion < 180)
                {
                    posicion += 10;
                }

                labelGrados.Text = posicion.ToString();
            }
        }


    }
}

