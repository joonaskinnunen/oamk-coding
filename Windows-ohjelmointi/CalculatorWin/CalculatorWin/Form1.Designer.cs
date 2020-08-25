namespace CalculatorWin
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
            this.firstInputField = new System.Windows.Forms.TextBox();
            this.plusBtn = new System.Windows.Forms.Button();
            this.secondInputField = new System.Windows.Forms.TextBox();
            this.minusBtn = new System.Windows.Forms.Button();
            this.multiplyBtn = new System.Windows.Forms.Button();
            this.divideBtn = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(121, 64);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(344, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Enter a decimal numbers and select an aritmetic operation into the fields";
            // 
            // firstInputField
            // 
            this.firstInputField.Location = new System.Drawing.Point(124, 121);
            this.firstInputField.Name = "firstInputField";
            this.firstInputField.Size = new System.Drawing.Size(100, 20);
            this.firstInputField.TabIndex = 1;
            // 
            // plusBtn
            // 
            this.plusBtn.Location = new System.Drawing.Point(124, 147);
            this.plusBtn.Name = "plusBtn";
            this.plusBtn.Size = new System.Drawing.Size(30, 23);
            this.plusBtn.TabIndex = 2;
            this.plusBtn.Text = "+";
            this.plusBtn.UseVisualStyleBackColor = true;
            this.plusBtn.Click += new System.EventHandler(this.plusBtn_Click);
            // 
            // secondInputField
            // 
            this.secondInputField.Location = new System.Drawing.Point(231, 120);
            this.secondInputField.Name = "secondInputField";
            this.secondInputField.Size = new System.Drawing.Size(100, 20);
            this.secondInputField.TabIndex = 3;
            // 
            // minusBtn
            // 
            this.minusBtn.Location = new System.Drawing.Point(160, 147);
            this.minusBtn.Name = "minusBtn";
            this.minusBtn.Size = new System.Drawing.Size(30, 23);
            this.minusBtn.TabIndex = 4;
            this.minusBtn.Text = "-";
            this.minusBtn.UseVisualStyleBackColor = true;
            this.minusBtn.Click += new System.EventHandler(this.minusBtn_Click);
            // 
            // multiplyBtn
            // 
            this.multiplyBtn.Location = new System.Drawing.Point(196, 147);
            this.multiplyBtn.Name = "multiplyBtn";
            this.multiplyBtn.Size = new System.Drawing.Size(30, 23);
            this.multiplyBtn.TabIndex = 5;
            this.multiplyBtn.Text = "*";
            this.multiplyBtn.UseVisualStyleBackColor = true;
            this.multiplyBtn.Click += new System.EventHandler(this.multiplyBtn_Click);
            // 
            // divideBtn
            // 
            this.divideBtn.Location = new System.Drawing.Point(232, 147);
            this.divideBtn.Name = "divideBtn";
            this.divideBtn.Size = new System.Drawing.Size(30, 23);
            this.divideBtn.TabIndex = 6;
            this.divideBtn.Text = "/";
            this.divideBtn.UseVisualStyleBackColor = true;
            this.divideBtn.Click += new System.EventHandler(this.divideBtn_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(124, 188);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(0, 13);
            this.label2.TabIndex = 7;
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.divideBtn);
            this.Controls.Add(this.multiplyBtn);
            this.Controls.Add(this.minusBtn);
            this.Controls.Add(this.secondInputField);
            this.Controls.Add(this.plusBtn);
            this.Controls.Add(this.firstInputField);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox firstInputField;
        private System.Windows.Forms.Button plusBtn;
        private System.Windows.Forms.TextBox secondInputField;
        private System.Windows.Forms.Button minusBtn;
        private System.Windows.Forms.Button multiplyBtn;
        private System.Windows.Forms.Button divideBtn;
        private System.Windows.Forms.Label label2;
    }
}

