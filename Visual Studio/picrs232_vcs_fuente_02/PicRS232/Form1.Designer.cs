namespace PicRS232
{
    partial class Form1_Principal
    {
        /// <summary>
        /// Variable del diseñador requerida.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén utilizando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben eliminar; false en caso contrario, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido del método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.button_t = new System.Windows.Forms.Button();
            this.button_b = new System.Windows.Forms.Button();
            this.button_a = new System.Windows.Forms.Button();
            this.button_l = new System.Windows.Forms.Button();
            this.button_Espacio = new System.Windows.Forms.Button();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.textBox_visualizar_mensaje = new System.Windows.Forms.TextBox();
            this.label_mensaje_pic = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // button_t
            // 
            this.button_t.Location = new System.Drawing.Point(109, 38);
            this.button_t.Name = "button_t";
            this.button_t.Size = new System.Drawing.Size(75, 23);
            this.button_t.TabIndex = 0;
            this.button_t.Text = "t";
            this.button_t.UseVisualStyleBackColor = true;
            this.button_t.Click += new System.EventHandler(this.button_t_Click);
            // 
            // button_b
            // 
            this.button_b.Location = new System.Drawing.Point(109, 67);
            this.button_b.Name = "button_b";
            this.button_b.Size = new System.Drawing.Size(75, 23);
            this.button_b.TabIndex = 1;
            this.button_b.Text = "b";
            this.button_b.UseVisualStyleBackColor = true;
            this.button_b.Click += new System.EventHandler(this.button_b_Click);
            // 
            // button_a
            // 
            this.button_a.Location = new System.Drawing.Point(28, 67);
            this.button_a.Name = "button_a";
            this.button_a.Size = new System.Drawing.Size(75, 23);
            this.button_a.TabIndex = 2;
            this.button_a.Text = "a";
            this.button_a.UseVisualStyleBackColor = true;
            this.button_a.Click += new System.EventHandler(this.button_a_Click);
            // 
            // button_l
            // 
            this.button_l.Location = new System.Drawing.Point(190, 67);
            this.button_l.Name = "button_l";
            this.button_l.Size = new System.Drawing.Size(75, 23);
            this.button_l.TabIndex = 3;
            this.button_l.Text = "l";
            this.button_l.UseVisualStyleBackColor = true;
            this.button_l.Click += new System.EventHandler(this.button_l_Click);
            // 
            // button_Espacio
            // 
            this.button_Espacio.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
            this.button_Espacio.Location = new System.Drawing.Point(190, 96);
            this.button_Espacio.Name = "button_Espacio";
            this.button_Espacio.Size = new System.Drawing.Size(75, 23);
            this.button_Espacio.TabIndex = 4;
            this.button_Espacio.Text = "Espacio";
            this.button_Espacio.UseVisualStyleBackColor = false;
            this.button_Espacio.Click += new System.EventHandler(this.button_Espacio_Click);
            // 
            // serialPort1
            // 
            this.serialPort1.StopBits = System.IO.Ports.StopBits.Two;
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1});
            this.statusStrip1.Location = new System.Drawing.Point(0, 244);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(292, 22);
            this.statusStrip1.TabIndex = 7;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // textBox_visualizar_mensaje
            // 
            this.textBox_visualizar_mensaje.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.textBox_visualizar_mensaje.Location = new System.Drawing.Point(0, 162);
            this.textBox_visualizar_mensaje.Multiline = true;
            this.textBox_visualizar_mensaje.Name = "textBox_visualizar_mensaje";
            this.textBox_visualizar_mensaje.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBox_visualizar_mensaje.Size = new System.Drawing.Size(292, 82);
            this.textBox_visualizar_mensaje.TabIndex = 6;
            // 
            // label_mensaje_pic
            // 
            this.label_mensaje_pic.AutoSize = true;
            this.label_mensaje_pic.Location = new System.Drawing.Point(25, 146);
            this.label_mensaje_pic.Name = "label_mensaje_pic";
            this.label_mensaje_pic.Size = new System.Drawing.Size(110, 13);
            this.label_mensaje_pic.TabIndex = 5;
            this.label_mensaje_pic.Text = "Mensaje desde el PIC";
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(53, 17);
            this.toolStripStatusLabel1.Text = "hh:mm:ss";
            // 
            // Form1_Principal
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(292, 266);
            this.Controls.Add(this.label_mensaje_pic);
            this.Controls.Add(this.textBox_visualizar_mensaje);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.button_Espacio);
            this.Controls.Add(this.button_l);
            this.Controls.Add(this.button_a);
            this.Controls.Add(this.button_b);
            this.Controls.Add(this.button_t);
            this.Name = "Form1_Principal";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "PicRS232";
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button_t;
        private System.Windows.Forms.Button button_b;
        private System.Windows.Forms.Button button_a;
        private System.Windows.Forms.Button button_l;
        private System.Windows.Forms.Button button_Espacio;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.TextBox textBox_visualizar_mensaje;
        private System.Windows.Forms.Label label_mensaje_pic;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;


    }
}

