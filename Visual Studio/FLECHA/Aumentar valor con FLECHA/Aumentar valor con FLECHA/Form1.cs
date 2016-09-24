using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        private int posicion;
        public Form1()
        {
            InitializeComponent();
        }

        protected override void OnKeyDown(KeyEventArgs keyg)
        {
            if (keyg.KeyData == Keys.Up)
            {
                if (posicion >= 0 && posicion < 180)
                {
                    // Incrementa 10
                    posicion += 10;
                }
                label1.Text = posicion.ToString();
            }

            if (keyg.KeyData == Keys.Down)
            {
                if (posicion > 0 && posicion <= 180)
                {
                    // Incrementa 10
                    posicion -= 10;
                }
                label1.Text = posicion.ToString();
            }
            
            }
        }

    }

