namespace Clave_seguridad
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
            this.label1 = new System.Windows.Forms.Label();
            this.textContraseña = new System.Windows.Forms.TextBox();
            this.buttonVerificar = new System.Windows.Forms.Button();
            this.labelEstado = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 39);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(85, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Ingrese la clave:";
            // 
            // textContraseña
            // 
            this.textContraseña.Location = new System.Drawing.Point(103, 36);
            this.textContraseña.Name = "textContraseña";
            this.textContraseña.PasswordChar = '*';
            this.textContraseña.Size = new System.Drawing.Size(188, 20);
            this.textContraseña.TabIndex = 1;
            this.textContraseña.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textContraseña_KeyPress);
            // 
            // buttonVerificar
            // 
            this.buttonVerificar.Location = new System.Drawing.Point(103, 73);
            this.buttonVerificar.Name = "buttonVerificar";
            this.buttonVerificar.Size = new System.Drawing.Size(109, 24);
            this.buttonVerificar.TabIndex = 2;
            this.buttonVerificar.Text = "Verificar";
            this.buttonVerificar.UseVisualStyleBackColor = true;
            this.buttonVerificar.Click += new System.EventHandler(this.buttonVerificar_Click);
            // 
            // labelEstado
            // 
            this.labelEstado.AutoSize = true;
            this.labelEstado.Location = new System.Drawing.Point(103, 110);
            this.labelEstado.Name = "labelEstado";
            this.labelEstado.Size = new System.Drawing.Size(22, 13);
            this.labelEstado.TabIndex = 3;
            this.labelEstado.Text = "     ";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(305, 131);
            this.Controls.Add(this.labelEstado);
            this.Controls.Add(this.buttonVerificar);
            this.Controls.Add(this.textContraseña);
            this.Controls.Add(this.label1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textContraseña;
        private System.Windows.Forms.Button buttonVerificar;
        private System.Windows.Forms.Label labelEstado;
    }
}

