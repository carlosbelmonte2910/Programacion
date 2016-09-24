namespace WindowsFormsApplication1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.label1 = new System.Windows.Forms.Label();
            this.btIzq = new System.Windows.Forms.Button();
            this.btDer = new System.Windows.Forms.Button();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.label1.Location = new System.Drawing.Point(124, 145);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 0;
            // 
            // btIzq
            // 
            this.btIzq.Location = new System.Drawing.Point(35, 172);
            this.btIzq.Name = "btIzq";
            this.btIzq.Size = new System.Drawing.Size(84, 32);
            this.btIzq.TabIndex = 1;
            this.btIzq.Text = "Izquierda";
            this.btIzq.UseVisualStyleBackColor = true;
            this.btIzq.Click += new System.EventHandler(this.btIzq_Click);
            // 
            // btDer
            // 
            this.btDer.Location = new System.Drawing.Point(165, 173);
            this.btDer.Name = "btDer";
            this.btDer.Size = new System.Drawing.Size(84, 31);
            this.btDer.TabIndex = 2;
            this.btDer.Text = "Derecha";
            this.btDer.UseVisualStyleBackColor = true;
            this.btDer.Click += new System.EventHandler(this.btDer_Click);
            // 
            // serialPort1
            // 
            this.serialPort1.PortName = "COM12";
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(13, 27);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(121, 21);
            this.comboBox1.TabIndex = 3;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.btDer);
            this.Controls.Add(this.btIzq);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btIzq;
        private System.Windows.Forms.Button btDer;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.ComboBox comboBox1;
    }
}

