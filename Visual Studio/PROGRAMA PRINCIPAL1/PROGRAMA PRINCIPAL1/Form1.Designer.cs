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
            this.comboBoxPuertos = new System.Windows.Forms.ComboBox();
            this.frase = new System.Windows.Forms.Label();
            this.botonDesconectar = new System.Windows.Forms.Button();
            this.botonConectar = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.label2 = new System.Windows.Forms.Label();
            this.groupBoxAuto = new System.Windows.Forms.GroupBox();
            this.labelMovAuto = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.btUpAuto = new System.Windows.Forms.Button();
            this.btDerAuto = new System.Windows.Forms.Button();
            this.btDownAuto = new System.Windows.Forms.Button();
            this.btIzqAuto = new System.Windows.Forms.Button();
            this.groupBoxCamara = new System.Windows.Forms.GroupBox();
            this.labelMovCam = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.btUpCamara = new System.Windows.Forms.Button();
            this.btDerCamara = new System.Windows.Forms.Button();
            this.btIzqCamara = new System.Windows.Forms.Button();
            this.btDownCamara = new System.Windows.Forms.Button();
            this.groupBoxBrazo = new System.Windows.Forms.GroupBox();
            this.labelMovBrazo = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.btCerrarPinza = new System.Windows.Forms.Button();
            this.btAbrirPinza = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.btBajarBrazo = new System.Windows.Forms.Button();
            this.btSubirBrazo = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.btHoraBrazo = new System.Windows.Forms.Button();
            this.btAntiBrazo = new System.Windows.Forms.Button();
            this.statusBar = new System.Windows.Forms.StatusStrip();
            this.StatusLabelEstado = new System.Windows.Forms.ToolStripStatusLabel();
            this.statusLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusLabel3 = new System.Windows.Forms.ToolStripStatusLabel();
            this.groupBoxLuces = new System.Windows.Forms.GroupBox();
            this.btOFF = new System.Windows.Forms.Button();
            this.btON = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.groupBoxAuto.SuspendLayout();
            this.groupBoxCamara.SuspendLayout();
            this.groupBoxBrazo.SuspendLayout();
            this.statusBar.SuspendLayout();
            this.groupBoxLuces.SuspendLayout();
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
            this.groupBox1.Location = new System.Drawing.Point(13, 65);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(338, 85);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "CONEXION";
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
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(14, 12);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(50, 47);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 1;
            this.pictureBox1.TabStop = false;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(124, 31);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(116, 20);
            this.label2.TabIndex = 2;
            this.label2.Text = "CONTROLES";
            // 
            // groupBoxAuto
            // 
            this.groupBoxAuto.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBoxAuto.Controls.Add(this.labelMovAuto);
            this.groupBoxAuto.Controls.Add(this.label7);
            this.groupBoxAuto.Controls.Add(this.btUpAuto);
            this.groupBoxAuto.Controls.Add(this.btDerAuto);
            this.groupBoxAuto.Controls.Add(this.btDownAuto);
            this.groupBoxAuto.Controls.Add(this.btIzqAuto);
            this.groupBoxAuto.Font = new System.Drawing.Font("Microsoft Sans Serif", 8F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBoxAuto.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.groupBoxAuto.Location = new System.Drawing.Point(13, 223);
            this.groupBoxAuto.Name = "groupBoxAuto";
            this.groupBoxAuto.Size = new System.Drawing.Size(338, 116);
            this.groupBoxAuto.TabIndex = 4;
            this.groupBoxAuto.TabStop = false;
            this.groupBoxAuto.Text = "CONTROL: AUTO";
            // 
            // labelMovAuto
            // 
            this.labelMovAuto.BackColor = System.Drawing.Color.White;
            this.labelMovAuto.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.labelMovAuto.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelMovAuto.Location = new System.Drawing.Point(245, 60);
            this.labelMovAuto.Name = "labelMovAuto";
            this.labelMovAuto.Size = new System.Drawing.Size(81, 20);
            this.labelMovAuto.TabIndex = 11;
            this.labelMovAuto.Text = "Desconocido";
            this.labelMovAuto.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(242, 47);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(64, 13);
            this.label7.TabIndex = 10;
            this.label7.Text = "Movimiento:";
            // 
            // btUpAuto
            // 
            this.btUpAuto.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btUpAuto.BackgroundImage")));
            this.btUpAuto.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btUpAuto.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btUpAuto.ImageKey = "(none)";
            this.btUpAuto.Location = new System.Drawing.Point(149, 19);
            this.btUpAuto.Name = "btUpAuto";
            this.btUpAuto.Size = new System.Drawing.Size(40, 40);
            this.btUpAuto.TabIndex = 4;
            this.btUpAuto.UseVisualStyleBackColor = true;
            this.btUpAuto.Click += new System.EventHandler(this.btUpAuto_Click);
            // 
            // btDerAuto
            // 
            this.btDerAuto.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btDerAuto.BackgroundImage")));
            this.btDerAuto.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btDerAuto.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btDerAuto.Location = new System.Drawing.Point(195, 65);
            this.btDerAuto.Name = "btDerAuto";
            this.btDerAuto.Size = new System.Drawing.Size(40, 40);
            this.btDerAuto.TabIndex = 3;
            this.btDerAuto.UseVisualStyleBackColor = true;
            this.btDerAuto.Click += new System.EventHandler(this.btDerAuto_Click);
            // 
            // btDownAuto
            // 
            this.btDownAuto.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btDownAuto.BackgroundImage")));
            this.btDownAuto.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btDownAuto.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btDownAuto.Location = new System.Drawing.Point(149, 65);
            this.btDownAuto.Name = "btDownAuto";
            this.btDownAuto.Size = new System.Drawing.Size(40, 40);
            this.btDownAuto.TabIndex = 2;
            this.btDownAuto.UseVisualStyleBackColor = true;
            this.btDownAuto.Click += new System.EventHandler(this.btDownAuto_Click);
            // 
            // btIzqAuto
            // 
            this.btIzqAuto.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btIzqAuto.BackgroundImage")));
            this.btIzqAuto.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btIzqAuto.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btIzqAuto.Location = new System.Drawing.Point(103, 65);
            this.btIzqAuto.Name = "btIzqAuto";
            this.btIzqAuto.Size = new System.Drawing.Size(40, 40);
            this.btIzqAuto.TabIndex = 1;
            this.btIzqAuto.UseVisualStyleBackColor = true;
            this.btIzqAuto.Click += new System.EventHandler(this.btIzqAuto_Click);
            // 
            // groupBoxCamara
            // 
            this.groupBoxCamara.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBoxCamara.Controls.Add(this.labelMovCam);
            this.groupBoxCamara.Controls.Add(this.label1);
            this.groupBoxCamara.Controls.Add(this.btUpCamara);
            this.groupBoxCamara.Controls.Add(this.btDerCamara);
            this.groupBoxCamara.Controls.Add(this.btIzqCamara);
            this.groupBoxCamara.Controls.Add(this.btDownCamara);
            this.groupBoxCamara.Font = new System.Drawing.Font("Microsoft Sans Serif", 8F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBoxCamara.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.groupBoxCamara.Location = new System.Drawing.Point(13, 345);
            this.groupBoxCamara.Name = "groupBoxCamara";
            this.groupBoxCamara.Size = new System.Drawing.Size(338, 113);
            this.groupBoxCamara.TabIndex = 5;
            this.groupBoxCamara.TabStop = false;
            this.groupBoxCamara.Text = "CONTROL: CAMARA";
            // 
            // labelMovCam
            // 
            this.labelMovCam.BackColor = System.Drawing.Color.White;
            this.labelMovCam.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.labelMovCam.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelMovCam.Location = new System.Drawing.Point(245, 58);
            this.labelMovCam.Name = "labelMovCam";
            this.labelMovCam.Size = new System.Drawing.Size(81, 20);
            this.labelMovCam.TabIndex = 9;
            this.labelMovCam.Text = "Desconocido";
            this.labelMovCam.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(242, 45);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(64, 13);
            this.label1.TabIndex = 5;
            this.label1.Text = "Movimiento:";
            // 
            // btUpCamara
            // 
            this.btUpCamara.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btUpCamara.BackgroundImage")));
            this.btUpCamara.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btUpCamara.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btUpCamara.ImageKey = "(none)";
            this.btUpCamara.Location = new System.Drawing.Point(149, 19);
            this.btUpCamara.Name = "btUpCamara";
            this.btUpCamara.Size = new System.Drawing.Size(40, 40);
            this.btUpCamara.TabIndex = 8;
            this.btUpCamara.UseVisualStyleBackColor = true;
            this.btUpCamara.Click += new System.EventHandler(this.btUpCamara_Click);
            // 
            // btDerCamara
            // 
            this.btDerCamara.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btDerCamara.BackgroundImage")));
            this.btDerCamara.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btDerCamara.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btDerCamara.Location = new System.Drawing.Point(195, 65);
            this.btDerCamara.Name = "btDerCamara";
            this.btDerCamara.Size = new System.Drawing.Size(40, 40);
            this.btDerCamara.TabIndex = 7;
            this.btDerCamara.UseVisualStyleBackColor = true;
            this.btDerCamara.Click += new System.EventHandler(this.btDerCamara_Click);
            // 
            // btIzqCamara
            // 
            this.btIzqCamara.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btIzqCamara.BackgroundImage")));
            this.btIzqCamara.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btIzqCamara.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btIzqCamara.Location = new System.Drawing.Point(103, 65);
            this.btIzqCamara.Name = "btIzqCamara";
            this.btIzqCamara.Size = new System.Drawing.Size(40, 40);
            this.btIzqCamara.TabIndex = 5;
            this.btIzqCamara.UseVisualStyleBackColor = true;
            this.btIzqCamara.Click += new System.EventHandler(this.btIzqCamara_Click);
            // 
            // btDownCamara
            // 
            this.btDownCamara.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btDownCamara.BackgroundImage")));
            this.btDownCamara.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btDownCamara.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btDownCamara.Location = new System.Drawing.Point(149, 65);
            this.btDownCamara.Name = "btDownCamara";
            this.btDownCamara.Size = new System.Drawing.Size(40, 40);
            this.btDownCamara.TabIndex = 6;
            this.btDownCamara.UseVisualStyleBackColor = true;
            this.btDownCamara.Click += new System.EventHandler(this.btDownCamara_Click);
            // 
            // groupBoxBrazo
            // 
            this.groupBoxBrazo.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBoxBrazo.Controls.Add(this.labelMovBrazo);
            this.groupBoxBrazo.Controls.Add(this.label5);
            this.groupBoxBrazo.Controls.Add(this.label8);
            this.groupBoxBrazo.Controls.Add(this.btCerrarPinza);
            this.groupBoxBrazo.Controls.Add(this.btAbrirPinza);
            this.groupBoxBrazo.Controls.Add(this.label4);
            this.groupBoxBrazo.Controls.Add(this.btBajarBrazo);
            this.groupBoxBrazo.Controls.Add(this.btSubirBrazo);
            this.groupBoxBrazo.Controls.Add(this.label3);
            this.groupBoxBrazo.Controls.Add(this.btHoraBrazo);
            this.groupBoxBrazo.Controls.Add(this.btAntiBrazo);
            this.groupBoxBrazo.Font = new System.Drawing.Font("Microsoft Sans Serif", 8F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBoxBrazo.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.groupBoxBrazo.Location = new System.Drawing.Point(13, 464);
            this.groupBoxBrazo.Name = "groupBoxBrazo";
            this.groupBoxBrazo.Size = new System.Drawing.Size(338, 209);
            this.groupBoxBrazo.TabIndex = 6;
            this.groupBoxBrazo.TabStop = false;
            this.groupBoxBrazo.Text = "CONTROL: BRAZO";
            // 
            // labelMovBrazo
            // 
            this.labelMovBrazo.BackColor = System.Drawing.Color.White;
            this.labelMovBrazo.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.labelMovBrazo.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelMovBrazo.Location = new System.Drawing.Point(244, 104);
            this.labelMovBrazo.Name = "labelMovBrazo";
            this.labelMovBrazo.Size = new System.Drawing.Size(81, 20);
            this.labelMovBrazo.TabIndex = 11;
            this.labelMovBrazo.Text = "Desconocido";
            this.labelMovBrazo.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(124, 142);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(90, 13);
            this.label5.TabIndex = 11;
            this.label5.Text = "Movimiento Pinza";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.Location = new System.Drawing.Point(241, 91);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(64, 13);
            this.label8.TabIndex = 10;
            this.label8.Text = "Movimiento:";
            // 
            // btCerrarPinza
            // 
            this.btCerrarPinza.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btCerrarPinza.BackgroundImage")));
            this.btCerrarPinza.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btCerrarPinza.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btCerrarPinza.ImageKey = "(none)";
            this.btCerrarPinza.Location = new System.Drawing.Point(172, 158);
            this.btCerrarPinza.Name = "btCerrarPinza";
            this.btCerrarPinza.Size = new System.Drawing.Size(40, 40);
            this.btCerrarPinza.TabIndex = 10;
            this.btCerrarPinza.UseVisualStyleBackColor = true;
            this.btCerrarPinza.Click += new System.EventHandler(this.btCerrarPinza_Click);
            // 
            // btAbrirPinza
            // 
            this.btAbrirPinza.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btAbrirPinza.BackgroundImage")));
            this.btAbrirPinza.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btAbrirPinza.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btAbrirPinza.Location = new System.Drawing.Point(126, 158);
            this.btAbrirPinza.Name = "btAbrirPinza";
            this.btAbrirPinza.Size = new System.Drawing.Size(40, 40);
            this.btAbrirPinza.TabIndex = 9;
            this.btAbrirPinza.UseVisualStyleBackColor = true;
            this.btAbrirPinza.Click += new System.EventHandler(this.btAbrirPinza_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(120, 79);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(99, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "Movimiento Vertical";
            // 
            // btBajarBrazo
            // 
            this.btBajarBrazo.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btBajarBrazo.BackgroundImage")));
            this.btBajarBrazo.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btBajarBrazo.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btBajarBrazo.ImageKey = "(none)";
            this.btBajarBrazo.Location = new System.Drawing.Point(172, 95);
            this.btBajarBrazo.Name = "btBajarBrazo";
            this.btBajarBrazo.Size = new System.Drawing.Size(40, 40);
            this.btBajarBrazo.TabIndex = 7;
            this.btBajarBrazo.UseVisualStyleBackColor = true;
            this.btBajarBrazo.Click += new System.EventHandler(this.btBajarBrazo_Click);
            // 
            // btSubirBrazo
            // 
            this.btSubirBrazo.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btSubirBrazo.BackgroundImage")));
            this.btSubirBrazo.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btSubirBrazo.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btSubirBrazo.Location = new System.Drawing.Point(126, 95);
            this.btSubirBrazo.Name = "btSubirBrazo";
            this.btSubirBrazo.Size = new System.Drawing.Size(40, 40);
            this.btSubirBrazo.TabIndex = 6;
            this.btSubirBrazo.UseVisualStyleBackColor = true;
            this.btSubirBrazo.Click += new System.EventHandler(this.btSubirBrazo_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(100, 16);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(138, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Movimiento Rotatorio (180º)";
            // 
            // btHoraBrazo
            // 
            this.btHoraBrazo.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btHoraBrazo.BackgroundImage")));
            this.btHoraBrazo.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btHoraBrazo.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btHoraBrazo.ImageKey = "(none)";
            this.btHoraBrazo.Location = new System.Drawing.Point(172, 32);
            this.btHoraBrazo.Name = "btHoraBrazo";
            this.btHoraBrazo.Size = new System.Drawing.Size(40, 40);
            this.btHoraBrazo.TabIndex = 4;
            this.btHoraBrazo.UseVisualStyleBackColor = true;
            this.btHoraBrazo.Click += new System.EventHandler(this.btHoraBrazo_Click);
            // 
            // btAntiBrazo
            // 
            this.btAntiBrazo.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btAntiBrazo.BackgroundImage")));
            this.btAntiBrazo.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btAntiBrazo.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btAntiBrazo.Location = new System.Drawing.Point(126, 32);
            this.btAntiBrazo.Name = "btAntiBrazo";
            this.btAntiBrazo.Size = new System.Drawing.Size(40, 40);
            this.btAntiBrazo.TabIndex = 1;
            this.btAntiBrazo.UseVisualStyleBackColor = true;
            this.btAntiBrazo.Click += new System.EventHandler(this.btAntiBrazo_Click);
            // 
            // statusBar
            // 
            this.statusBar.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.StatusLabelEstado,
            this.statusLabel,
            this.toolStripStatusLabel3});
            this.statusBar.Location = new System.Drawing.Point(0, 676);
            this.statusBar.Name = "statusBar";
            this.statusBar.Size = new System.Drawing.Size(364, 22);
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
            // toolStripStatusLabel3
            // 
            this.toolStripStatusLabel3.Margin = new System.Windows.Forms.Padding(40, 3, 0, 2);
            this.toolStripStatusLabel3.Name = "toolStripStatusLabel3";
            this.toolStripStatusLabel3.Size = new System.Drawing.Size(188, 17);
            this.toolStripStatusLabel3.Text = "    Carlos Mariano Belmonte - 2015";
            // 
            // groupBoxLuces
            // 
            this.groupBoxLuces.Controls.Add(this.btOFF);
            this.groupBoxLuces.Controls.Add(this.btON);
            this.groupBoxLuces.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBoxLuces.Location = new System.Drawing.Point(14, 156);
            this.groupBoxLuces.Name = "groupBoxLuces";
            this.groupBoxLuces.Size = new System.Drawing.Size(337, 61);
            this.groupBoxLuces.TabIndex = 8;
            this.groupBoxLuces.TabStop = false;
            this.groupBoxLuces.Text = "LUCES";
            // 
            // btOFF
            // 
            this.btOFF.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btOFF.BackgroundImage")));
            this.btOFF.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btOFF.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btOFF.ImageKey = "(none)";
            this.btOFF.Location = new System.Drawing.Point(171, 11);
            this.btOFF.Name = "btOFF";
            this.btOFF.Size = new System.Drawing.Size(40, 40);
            this.btOFF.TabIndex = 13;
            this.btOFF.UseVisualStyleBackColor = true;
            this.btOFF.Click += new System.EventHandler(this.btOFF_Click);
            // 
            // btON
            // 
            this.btON.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btON.BackgroundImage")));
            this.btON.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btON.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btON.ImageKey = "(none)";
            this.btON.Location = new System.Drawing.Point(125, 11);
            this.btON.Name = "btON";
            this.btON.Size = new System.Drawing.Size(40, 40);
            this.btON.TabIndex = 12;
            this.btON.UseVisualStyleBackColor = true;
            this.btON.Click += new System.EventHandler(this.btON_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(364, 698);
            this.Controls.Add(this.groupBoxLuces);
            this.Controls.Add(this.statusBar);
            this.Controls.Add(this.groupBoxBrazo);
            this.Controls.Add(this.groupBoxCamara);
            this.Controls.Add(this.groupBoxAuto);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.groupBox1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(380, 800);
            this.MinimizeBox = false;
            this.MinimumSize = new System.Drawing.Size(380, 736);
            this.Name = "Form1";
            this.Text = "CONTROL ROBOT";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.groupBoxAuto.ResumeLayout(false);
            this.groupBoxAuto.PerformLayout();
            this.groupBoxCamara.ResumeLayout(false);
            this.groupBoxCamara.PerformLayout();
            this.groupBoxBrazo.ResumeLayout(false);
            this.groupBoxBrazo.PerformLayout();
            this.statusBar.ResumeLayout(false);
            this.statusBar.PerformLayout();
            this.groupBoxLuces.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label frase;
        private System.Windows.Forms.Button botonDesconectar;
        private System.Windows.Forms.Button botonConectar;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.GroupBox groupBoxAuto;
        private System.Windows.Forms.Button btUpAuto;
        private System.Windows.Forms.Button btDerAuto;
        private System.Windows.Forms.Button btDownAuto;
        private System.Windows.Forms.Button btIzqAuto;
        private System.Windows.Forms.GroupBox groupBoxCamara;
        private System.Windows.Forms.GroupBox groupBoxBrazo;
        private System.Windows.Forms.Button btHoraBrazo;
        private System.Windows.Forms.Button btAntiBrazo;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button btCerrarPinza;
        private System.Windows.Forms.Button btAbrirPinza;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button btBajarBrazo;
        private System.Windows.Forms.Button btSubirBrazo;
        private System.Windows.Forms.Button btUpCamara;
        private System.Windows.Forms.Button btDerCamara;
        private System.Windows.Forms.Button btIzqCamara;
        private System.Windows.Forms.Button btDownCamara;
        private System.Windows.Forms.StatusStrip statusBar;
        private System.Windows.Forms.ToolStripStatusLabel StatusLabelEstado;
        private System.Windows.Forms.ToolStripStatusLabel statusLabel;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel3;
        private System.Windows.Forms.ComboBox comboBoxPuertos;
        private System.Windows.Forms.Label labelMovCam;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label labelMovAuto;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label labelMovBrazo;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.GroupBox groupBoxLuces;
        private System.Windows.Forms.Button btOFF;
        private System.Windows.Forms.Button btON;
    }
}

