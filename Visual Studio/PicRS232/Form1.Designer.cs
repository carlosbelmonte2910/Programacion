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
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.textBox_visualizar_mensaje = new System.Windows.Forms.TextBox();
            this.label_mensaje_pic = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.opcionesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.salirToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ayudaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.contenidoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.acercaDeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripSeparator();
            this.acercaDe2ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.statusStrip1.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // button_t
            // 
            this.button_t.Location = new System.Drawing.Point(109, 38);
            this.button_t.Name = "button_t";
            this.button_t.Size = new System.Drawing.Size(75, 23);
            this.button_t.TabIndex = 1;
            this.button_t.Text = "t";
            this.button_t.UseVisualStyleBackColor = true;
            this.button_t.Click += new System.EventHandler(this.button_t_Click);
            // 
            // button_b
            // 
            this.button_b.Location = new System.Drawing.Point(109, 67);
            this.button_b.Name = "button_b";
            this.button_b.Size = new System.Drawing.Size(75, 23);
            this.button_b.TabIndex = 3;
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
            this.button_l.TabIndex = 4;
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
            this.button_Espacio.TabIndex = 0;
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
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(53, 17);
            this.toolStripStatusLabel1.Text = "hh:mm:ss";
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
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.opcionesToolStripMenuItem,
            this.ayudaToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(292, 24);
            this.menuStrip1.TabIndex = 8;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // opcionesToolStripMenuItem
            // 
            this.opcionesToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.salirToolStripMenuItem});
            this.opcionesToolStripMenuItem.Name = "opcionesToolStripMenuItem";
            this.opcionesToolStripMenuItem.Size = new System.Drawing.Size(63, 20);
            this.opcionesToolStripMenuItem.Text = "&Opciones";
            // 
            // salirToolStripMenuItem
            // 
            this.salirToolStripMenuItem.Name = "salirToolStripMenuItem";
            this.salirToolStripMenuItem.Size = new System.Drawing.Size(105, 22);
            this.salirToolStripMenuItem.Text = "&Salir";
            this.salirToolStripMenuItem.Click += new System.EventHandler(this.salirToolStripMenuItem_Click);
            // 
            // ayudaToolStripMenuItem
            // 
            this.ayudaToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.contenidoToolStripMenuItem,
            this.acercaDeToolStripMenuItem,
            this.toolStripMenuItem1,
            this.acercaDe2ToolStripMenuItem});
            this.ayudaToolStripMenuItem.Name = "ayudaToolStripMenuItem";
            this.ayudaToolStripMenuItem.Size = new System.Drawing.Size(50, 20);
            this.ayudaToolStripMenuItem.Text = "A&yuda";
            // 
            // contenidoToolStripMenuItem
            // 
            this.contenidoToolStripMenuItem.Name = "contenidoToolStripMenuItem";
            this.contenidoToolStripMenuItem.Size = new System.Drawing.Size(157, 22);
            this.contenidoToolStripMenuItem.Text = "&Contenido";
            this.contenidoToolStripMenuItem.Click += new System.EventHandler(this.contenidoToolStripMenuItem_Click);
            // 
            // acercaDeToolStripMenuItem
            // 
            this.acercaDeToolStripMenuItem.Name = "acercaDeToolStripMenuItem";
            this.acercaDeToolStripMenuItem.Size = new System.Drawing.Size(157, 22);
            this.acercaDeToolStripMenuItem.Text = "Ac&erca de...";
            this.acercaDeToolStripMenuItem.Click += new System.EventHandler(this.acercaDeToolStripMenuItem_Click);
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(154, 6);
            // 
            // acercaDe2ToolStripMenuItem
            // 
            this.acercaDe2ToolStripMenuItem.Name = "acercaDe2ToolStripMenuItem";
            this.acercaDe2ToolStripMenuItem.Size = new System.Drawing.Size(157, 22);
            this.acercaDe2ToolStripMenuItem.Text = "Ace&rca de 2 ...";
            this.acercaDe2ToolStripMenuItem.Click += new System.EventHandler(this.acercaDe2ToolStripMenuItem_Click);
            // 
            // Form1_Principal
            // 
            this.AcceptButton = this.button_Espacio;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(292, 266);
            this.Controls.Add(this.label_mensaje_pic);
            this.Controls.Add(this.textBox_visualizar_mensaje);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.button_Espacio);
            this.Controls.Add(this.button_l);
            this.Controls.Add(this.button_a);
            this.Controls.Add(this.button_b);
            this.Controls.Add(this.button_t);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.Name = "Form1_Principal";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "PicRS232";
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
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
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem opcionesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem ayudaToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem acercaDeToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem acercaDe2ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem contenidoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem salirToolStripMenuItem;


    }
}

