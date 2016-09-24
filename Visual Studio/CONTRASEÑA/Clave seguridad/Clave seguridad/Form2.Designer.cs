namespace Clave_seguridad
{
    partial class Form2
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
            this.labelGrados = new System.Windows.Forms.Label();
            this.buttonIzq = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // labelGrados
            // 
            this.labelGrados.AutoSize = true;
            this.labelGrados.Location = new System.Drawing.Point(73, 145);
            this.labelGrados.Name = "labelGrados";
            this.labelGrados.Size = new System.Drawing.Size(19, 13);
            this.labelGrados.TabIndex = 0;
            this.labelGrados.Text = "0  ";
            // 
            // buttonIzq
            // 
            this.buttonIzq.Location = new System.Drawing.Point(47, 209);
            this.buttonIzq.Name = "buttonIzq";
            this.buttonIzq.Size = new System.Drawing.Size(75, 23);
            this.buttonIzq.TabIndex = 1;
            this.buttonIzq.Text = "button1";
            this.buttonIzq.UseVisualStyleBackColor = true;
            this.buttonIzq.Click += new System.EventHandler(this.buttonIzq_Click);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.buttonIzq);
            this.Controls.Add(this.labelGrados);
            this.Name = "Form2";
            this.Text = "Form2";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form2_FormClosing);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelGrados;
        private System.Windows.Forms.Button buttonIzq;

    }
}