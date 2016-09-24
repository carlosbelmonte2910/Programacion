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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void buttonVerificar_Click(object sender, EventArgs e)
        {
            if (textContraseña.Text == "1234")
            {
                labelEstado.Text = "Clave correcta";
                Form2 abrir = new Form2();
                abrir.Show();
                this.Hide();
            }
            else
            {
                labelEstado.Text = "Clave incorrecta";
            }
        }

        private void textContraseña_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)(Keys.Enter))
            {
                if (textContraseña.Text == "1234")
                {
                    labelEstado.Text = "Clave correcta";
                    Form2 abrir = new Form2();
                    abrir.Show();
                    this.Hide();
                }
                else
                {
                    labelEstado.Text = "Clave incorrecta";
                }
            }

        }

    }
}
