namespace PersonsA
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
            this.label1 = new System.Windows.Forms.Label();
            this.textBoxFname = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxLname = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textBoxAge = new System.Windows.Forms.TextBox();
            this.buttonSave = new System.Windows.Forms.Button();
            this.textBoxPersons = new System.Windows.Forms.TextBox();
            this.buttonPrint = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(62, 45);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(113, 25);
            this.label1.TabIndex = 0;
            this.label1.Text = "First name";
            // 
            // textBoxFname
            // 
            this.textBoxFname.Location = new System.Drawing.Point(67, 74);
            this.textBoxFname.Name = "textBoxFname";
            this.textBoxFname.Size = new System.Drawing.Size(176, 31);
            this.textBoxFname.TabIndex = 1;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(62, 127);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(112, 25);
            this.label2.TabIndex = 2;
            this.label2.Text = "Last name";
            // 
            // textBoxLname
            // 
            this.textBoxLname.Location = new System.Drawing.Point(67, 156);
            this.textBoxLname.Name = "textBoxLname";
            this.textBoxLname.Size = new System.Drawing.Size(176, 31);
            this.textBoxLname.TabIndex = 3;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(67, 206);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(50, 25);
            this.label3.TabIndex = 4;
            this.label3.Text = "Age";
            // 
            // textBoxAge
            // 
            this.textBoxAge.Location = new System.Drawing.Point(67, 234);
            this.textBoxAge.Name = "textBoxAge";
            this.textBoxAge.Size = new System.Drawing.Size(100, 31);
            this.textBoxAge.TabIndex = 5;
            // 
            // buttonSave
            // 
            this.buttonSave.Location = new System.Drawing.Point(468, 234);
            this.buttonSave.Name = "buttonSave";
            this.buttonSave.Size = new System.Drawing.Size(110, 50);
            this.buttonSave.TabIndex = 6;
            this.buttonSave.Text = "Save";
            this.buttonSave.UseVisualStyleBackColor = true;
            this.buttonSave.Click += new System.EventHandler(this.saveButton_Click);
            // 
            // textBoxPersons
            // 
            this.textBoxPersons.Location = new System.Drawing.Point(67, 303);
            this.textBoxPersons.Multiline = true;
            this.textBoxPersons.Name = "textBoxPersons";
            this.textBoxPersons.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBoxPersons.Size = new System.Drawing.Size(386, 118);
            this.textBoxPersons.TabIndex = 7;
            // 
            // buttonPrint
            // 
            this.buttonPrint.Location = new System.Drawing.Point(468, 372);
            this.buttonPrint.Name = "buttonPrint";
            this.buttonPrint.Size = new System.Drawing.Size(110, 50);
            this.buttonPrint.TabIndex = 8;
            this.buttonPrint.Text = "Print";
            this.buttonPrint.UseVisualStyleBackColor = true;
            this.buttonPrint.Click += new System.EventHandler(this.buttonPrint_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.buttonPrint);
            this.Controls.Add(this.textBoxPersons);
            this.Controls.Add(this.buttonSave);
            this.Controls.Add(this.textBoxAge);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textBoxLname);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBoxFname);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxFname;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxLname;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBoxAge;
        private System.Windows.Forms.Button buttonSave;
        private System.Windows.Forms.TextBox textBoxPersons;
        private System.Windows.Forms.Button buttonPrint;
    }
}

