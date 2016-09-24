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
        public Form1()
        {
            InitializeComponent();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            serialPort1.Close();
            int selectedIndex = comboBox1.SelectedIndex;
            Object selectedItem = comboBox1.SelectedItem;
            serialPort1.PortName = selectedItem.ToString();
            serialPort1.Open();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            String[] Ports = System.IO.Ports.SerialPort.GetPortNames();
            this.comboBox1.Items.AddRange(Ports);
        }
    }
}
