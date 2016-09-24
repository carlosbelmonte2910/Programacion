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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.comboBoxPuertos = new System.Windows.Forms.ComboBox();
            this.frase = new System.Windows.Forms.Label();
            this.botonDesconectar = new System.Windows.Forms.Button();
            this.botonConectar = new System.Windows.Forms.Button();
            this.bt00 = new System.Windows.Forms.Button();
            this.statusBar = new System.Windows.Forms.StatusStrip();
            this.StatusLabelEstado = new System.Windows.Forms.ToolStripStatusLabel();
            this.statusLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.groupBoxLuces = new System.Windows.Forms.GroupBox();
            this.btEnviarHora = new System.Windows.Forms.Button();
            this.textMinuto = new System.Windows.Forms.TextBox();
            this.btEnviarMinutos = new System.Windows.Forms.Button();
            this.textHora = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.listBox2 = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.statusBar.SuspendLayout();
            this.groupBoxLuces.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox1.Controls.Add(this.comboBoxPuertos);
            this.groupBox1.Controls.Add(this.frase);
            this.groupBox1.Controls.Add(this.botonDesconectar);
            this.groupBox1.Controls.Add(this.botonConectar);
            this.groupBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox1.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(475, 85);
            this.groupBox1.TabIndex = 19;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "CONEXION";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(327, 130);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(23, 23);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 5;
            this.pictureBox1.TabStop = false;
            // 
            // comboBoxPuertos
            // 
            this.comboBoxPuertos.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.comboBoxPuertos.FormattingEnabled = true;
            this.comboBoxPuertos.Location = new System.Drawing.Point(10, 22);
            this.comboBoxPuertos.Name = "comboBoxPuertos";
            this.comboBoxPuertos.Size = new System.Drawing.Size(116, 21);
            this.comboBoxPuertos.TabIndex = 4;
            // 
            // frase
            // 
            this.frase.AutoSize = true;
            this.frase.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.frase.Location = new System.Drawing.Point(7, 58);
            this.frase.Name = "frase";
            this.frase.Size = new System.Drawing.Size(213, 13);
            this.frase.TabIndex = 3;
            this.frase.Text = " La tasa de baudio esta configurada a 9600";
            // 
            // botonDesconectar
            // 
            this.botonDesconectar.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.botonDesconectar.Location = new System.Drawing.Point(236, 22);
            this.botonDesconectar.Name = "botonDesconectar";
            this.botonDesconectar.Size = new System.Drawing.Size(90, 31);
            this.botonDesconectar.TabIndex = 2;
            this.botonDesconectar.Text = "Desconectar";
            this.botonDesconectar.UseVisualStyleBackColor = true;
            this.botonDesconectar.Click += new System.EventHandler(this.botonDesconectar_Click);
            // 
            // botonConectar
            // 
            this.botonConectar.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.botonConectar.Location = new System.Drawing.Point(140, 22);
            this.botonConectar.Name = "botonConectar";
            this.botonConectar.Size = new System.Drawing.Size(90, 31);
            this.botonConectar.TabIndex = 1;
            this.botonConectar.Text = "Conectar";
            this.botonConectar.UseVisualStyleBackColor = true;
            this.botonConectar.Click += new System.EventHandler(this.botonConectar_Click);
            // 
            // bt00
            // 
            this.bt00.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.bt00.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.bt00.Location = new System.Drawing.Point(339, 19);
            this.bt00.Name = "bt00";
            this.bt00.Size = new System.Drawing.Size(116, 35);
            this.bt00.TabIndex = 18;
            this.bt00.Text = "Molienda Normal";
            this.bt00.UseVisualStyleBackColor = true;
            this.bt00.Click += new System.EventHandler(this.bt00_Click);
            // 
            // statusBar
            // 
            this.statusBar.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.StatusLabelEstado,
            this.statusLabel,
            this.toolStripStatusLabel1});
            this.statusBar.Location = new System.Drawing.Point(0, 275);
            this.statusBar.Name = "statusBar";
            this.statusBar.Size = new System.Drawing.Size(499, 22);
            this.statusBar.TabIndex = 7;
            this.statusBar.Text = "statusStrip1";
            // 
            // StatusLabelEstado
            // 
            this.StatusLabelEstado.Name = "StatusLabelEstado";
            this.StatusLabelEstado.Size = new System.Drawing.Size(45, 17);
            this.StatusLabelEstado.Text = "Estado:";
            // 
            // statusLabel
            // 
            this.statusLabel.Name = "statusLabel";
            this.statusLabel.Size = new System.Drawing.Size(76, 17);
            this.statusLabel.Text = "Desconocido";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Padding = new System.Windows.Forms.Padding(200, 0, 0, 0);
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(341, 17);
            this.toolStripStatusLabel1.Text = "Carlos Mariano Belmonte";
            this.toolStripStatusLabel1.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // groupBoxLuces
            // 
            this.groupBoxLuces.Controls.Add(this.pictureBox1);
            this.groupBoxLuces.Controls.Add(this.label4);
            this.groupBoxLuces.Controls.Add(this.groupBox2);
            this.groupBoxLuces.Controls.Add(this.button1);
            this.groupBoxLuces.Controls.Add(this.listBox2);
            this.groupBoxLuces.Controls.Add(this.bt00);
            this.groupBoxLuces.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBoxLuces.Location = new System.Drawing.Point(13, 103);
            this.groupBoxLuces.Name = "groupBoxLuces";
            this.groupBoxLuces.Size = new System.Drawing.Size(474, 165);
            this.groupBoxLuces.TabIndex = 8;
            this.groupBoxLuces.TabStop = false;
            this.groupBoxLuces.Text = "ESTADOS";
            // 
            // btEnviarHora
            // 
            this.btEnviarHora.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btEnviarHora.Location = new System.Drawing.Point(96, 29);
            this.btEnviarHora.Name = "btEnviarHora";
            this.btEnviarHora.Size = new System.Drawing.Size(77, 31);
            this.btEnviarHora.TabIndex = 22;
            this.btEnviarHora.Text = "Enviar Hora";
            this.btEnviarHora.UseVisualStyleBackColor = true;
            this.btEnviarHora.Click += new System.EventHandler(this.btEnviarHora_Click);
            // 
            // textMinuto
            // 
            this.textMinuto.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textMinuto.Location = new System.Drawing.Point(54, 35);
            this.textMinuto.MaxLength = 2;
            this.textMinuto.Name = "textMinuto";
            this.textMinuto.Size = new System.Drawing.Size(24, 20);
            this.textMinuto.TabIndex = 21;
            this.textMinuto.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // btEnviarMinutos
            // 
            this.btEnviarMinutos.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btEnviarMinutos.Location = new System.Drawing.Point(179, 29);
            this.btEnviarMinutos.Name = "btEnviarMinutos";
            this.btEnviarMinutos.Size = new System.Drawing.Size(65, 31);
            this.btEnviarMinutos.TabIndex = 20;
            this.btEnviarMinutos.Text = "Enviar Min";
            this.btEnviarMinutos.UseVisualStyleBackColor = true;
            this.btEnviarMinutos.Click += new System.EventHandler(this.btEnviarMinutos_Click);
            // 
            // textHora
            // 
            this.textHora.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textHora.Location = new System.Drawing.Point(8, 35);
            this.textHora.MaxLength = 2;
            this.textHora.Name = "textHora";
            this.textHora.Size = new System.Drawing.Size(24, 20);
            this.textHora.TabIndex = 1;
            this.textHora.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.textHora.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textHora_KeyPress);
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.Location = new System.Drawing.Point(235, 19);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(90, 35);
            this.button1.TabIndex = 22;
            this.button1.Text = "Enviar falla";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // listBox2
            // 
            this.listBox2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.listBox2.FormattingEnabled = true;
            this.listBox2.Items.AddRange(new object[] {
            "01 - Falta de caña",
            "02 - Falla en usina (SIEMENS)",
            "03 - Falla en usina (MARELLI)",
            "04 - Falla en Caldera 1",
            "05 - Falla en Caldera 2",
            "06 - Falla en Caldera 3",
            "07 - Falla en Caldera 4",
            "08 - Baja presion de vapor",
            "09 - Falta de gas",
            "10 - Atascamiento de molino 1",
            "11 - Atascamiento de molino 2",
            "12 - Atascamiento de molino 3",
            "13 - Falla en encaladora",
            "14 - Falla horno de azufre",
            "15 - Rotura cinta de bagacera",
            "16 - Fallas en centrifugas",
            "17 - Filtro de cachaza atascado",
            "18 - Falla en calentadores",
            "19 - Falla en cristalizadores",
            "20 - Falla tolva de azucar"});
            this.listBox2.Location = new System.Drawing.Point(9, 19);
            this.listBox2.Name = "listBox2";
            this.listBox2.Size = new System.Drawing.Size(196, 134);
            this.listBox2.TabIndex = 23;
            this.listBox2.Click += new System.EventHandler(this.listBox2_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(9, 19);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(23, 13);
            this.label1.TabIndex = 24;
            this.label1.Text = "HH";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(53, 19);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(25, 13);
            this.label2.TabIndex = 25;
            this.label2.Text = "MM";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(38, 38);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(10, 13);
            this.label3.TabIndex = 26;
            this.label3.Text = ":";
            this.label3.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.btEnviarHora);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.label1);
            this.groupBox2.Controls.Add(this.btEnviarMinutos);
            this.groupBox2.Controls.Add(this.textHora);
            this.groupBox2.Controls.Add(this.textMinuto);
            this.groupBox2.Location = new System.Drawing.Point(211, 60);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(263, 68);
            this.groupBox2.TabIndex = 27;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Horario de la falla";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(215, 133);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(106, 20);
            this.label4.TabIndex = 28;
            this.label4.Text = "MOLIENDA:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(499, 297);
            this.Controls.Add(this.groupBoxLuces);
            this.Controls.Add(this.statusBar);
            this.Controls.Add(this.groupBox1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(515, 335);
            this.MinimizeBox = false;
            this.MinimumSize = new System.Drawing.Size(515, 335);
            this.Name = "Form1";
            this.Text = "Indicacion de Estado";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.statusBar.ResumeLayout(false);
            this.statusBar.PerformLayout();
            this.groupBoxLuces.ResumeLayout(false);
            this.groupBoxLuces.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label frase;
        private System.Windows.Forms.Button botonDesconectar;
        private System.Windows.Forms.Button botonConectar;
        private System.Windows.Forms.StatusStrip statusBar;
        private System.Windows.Forms.ToolStripStatusLabel StatusLabelEstado;
        private System.Windows.Forms.ToolStripStatusLabel statusLabel;
        private System.Windows.Forms.ComboBox comboBoxPuertos;
        private System.Windows.Forms.GroupBox groupBoxLuces;
        private System.Windows.Forms.Button bt00;
        private System.Windows.Forms.Button btEnviarMinutos;
        private System.Windows.Forms.TextBox textHora;
        private System.Windows.Forms.TextBox textMinuto;
        private System.Windows.Forms.Button btEnviarHora;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.ListBox listBox2;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label4;
    }
}

