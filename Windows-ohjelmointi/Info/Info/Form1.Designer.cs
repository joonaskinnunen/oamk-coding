namespace Info
{
    partial class FormFavCountry
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
            this.labelNickname = new System.Windows.Forms.Label();
            this.textBoxNickname = new System.Windows.Forms.TextBox();
            this.checkBoxIceCream = new System.Windows.Forms.CheckBox();
            this.radioButtonYoung = new System.Windows.Forms.RadioButton();
            this.radioButtonMiddle = new System.Windows.Forms.RadioButton();
            this.radioButtonOld = new System.Windows.Forms.RadioButton();
            this.groupBoxAge = new System.Windows.Forms.GroupBox();
            this.labelCountry = new System.Windows.Forms.Label();
            this.listBoxCountry = new System.Windows.Forms.ListBox();
            this.buttonPrint = new System.Windows.Forms.Button();
            this.textBoxResults = new System.Windows.Forms.TextBox();
            this.groupBoxAge.SuspendLayout();
            this.SuspendLayout();
            // 
            // labelNickname
            // 
            this.labelNickname.AutoSize = true;
            this.labelNickname.Location = new System.Drawing.Point(78, 51);
            this.labelNickname.Name = "labelNickname";
            this.labelNickname.Size = new System.Drawing.Size(107, 25);
            this.labelNickname.TabIndex = 0;
            this.labelNickname.Text = "Nickname";
            // 
            // textBoxNickname
            // 
            this.textBoxNickname.Location = new System.Drawing.Point(191, 45);
            this.textBoxNickname.Name = "textBoxNickname";
            this.textBoxNickname.Size = new System.Drawing.Size(100, 31);
            this.textBoxNickname.TabIndex = 1;
            // 
            // checkBoxIceCream
            // 
            this.checkBoxIceCream.AutoSize = true;
            this.checkBoxIceCream.Location = new System.Drawing.Point(126, 93);
            this.checkBoxIceCream.Name = "checkBoxIceCream";
            this.checkBoxIceCream.Size = new System.Drawing.Size(187, 29);
            this.checkBoxIceCream.TabIndex = 2;
            this.checkBoxIceCream.Text = "I like ice cream";
            this.checkBoxIceCream.UseVisualStyleBackColor = true;
            // 
            // radioButtonYoung
            // 
            this.radioButtonYoung.AutoSize = true;
            this.radioButtonYoung.Location = new System.Drawing.Point(6, 43);
            this.radioButtonYoung.Name = "radioButtonYoung";
            this.radioButtonYoung.Size = new System.Drawing.Size(86, 29);
            this.radioButtonYoung.TabIndex = 3;
            this.radioButtonYoung.TabStop = true;
            this.radioButtonYoung.Text = "0-20";
            this.radioButtonYoung.UseVisualStyleBackColor = true;
            // 
            // radioButtonMiddle
            // 
            this.radioButtonMiddle.AutoSize = true;
            this.radioButtonMiddle.Location = new System.Drawing.Point(6, 80);
            this.radioButtonMiddle.Name = "radioButtonMiddle";
            this.radioButtonMiddle.Size = new System.Drawing.Size(98, 29);
            this.radioButtonMiddle.TabIndex = 4;
            this.radioButtonMiddle.TabStop = true;
            this.radioButtonMiddle.Text = "21-49";
            this.radioButtonMiddle.UseVisualStyleBackColor = true;
            // 
            // radioButtonOld
            // 
            this.radioButtonOld.AutoSize = true;
            this.radioButtonOld.Location = new System.Drawing.Point(6, 115);
            this.radioButtonOld.Name = "radioButtonOld";
            this.radioButtonOld.Size = new System.Drawing.Size(74, 29);
            this.radioButtonOld.TabIndex = 5;
            this.radioButtonOld.TabStop = true;
            this.radioButtonOld.Text = "50-";
            this.radioButtonOld.UseVisualStyleBackColor = true;
            // 
            // groupBoxAge
            // 
            this.groupBoxAge.Controls.Add(this.radioButtonMiddle);
            this.groupBoxAge.Controls.Add(this.radioButtonOld);
            this.groupBoxAge.Controls.Add(this.radioButtonYoung);
            this.groupBoxAge.Location = new System.Drawing.Point(83, 161);
            this.groupBoxAge.Name = "groupBoxAge";
            this.groupBoxAge.Size = new System.Drawing.Size(252, 175);
            this.groupBoxAge.TabIndex = 6;
            this.groupBoxAge.TabStop = false;
            this.groupBoxAge.Text = "My age is";
            // 
            // labelCountry
            // 
            this.labelCountry.AutoSize = true;
            this.labelCountry.Location = new System.Drawing.Point(89, 343);
            this.labelCountry.Name = "labelCountry";
            this.labelCountry.Size = new System.Drawing.Size(142, 25);
            this.labelCountry.TabIndex = 7;
            this.labelCountry.Text = "I like to live in";
            // 
            // listBoxCountry
            // 
            this.listBoxCountry.FormattingEnabled = true;
            this.listBoxCountry.ItemHeight = 25;
            this.listBoxCountry.Items.AddRange(new object[] {
            "Finland",
            "Sweden",
            "Usa",
            "Norway"});
            this.listBoxCountry.Location = new System.Drawing.Point(89, 371);
            this.listBoxCountry.Name = "listBoxCountry";
            this.listBoxCountry.Size = new System.Drawing.Size(202, 154);
            this.listBoxCountry.TabIndex = 8;
            // 
            // buttonPrint
            // 
            this.buttonPrint.Location = new System.Drawing.Point(329, 477);
            this.buttonPrint.Name = "buttonPrint";
            this.buttonPrint.Size = new System.Drawing.Size(178, 48);
            this.buttonPrint.TabIndex = 9;
            this.buttonPrint.Text = "Print";
            this.buttonPrint.UseVisualStyleBackColor = true;
            this.buttonPrint.Click += new System.EventHandler(this.buttonPrint_Click);
            // 
            // textBoxResults
            // 
            this.textBoxResults.Location = new System.Drawing.Point(89, 569);
            this.textBoxResults.Multiline = true;
            this.textBoxResults.Name = "textBoxResults";
            this.textBoxResults.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBoxResults.Size = new System.Drawing.Size(418, 82);
            this.textBoxResults.TabIndex = 10;
            // 
            // FormFavCountry
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(557, 713);
            this.Controls.Add(this.textBoxResults);
            this.Controls.Add(this.buttonPrint);
            this.Controls.Add(this.listBoxCountry);
            this.Controls.Add(this.labelCountry);
            this.Controls.Add(this.groupBoxAge);
            this.Controls.Add(this.checkBoxIceCream);
            this.Controls.Add(this.textBoxNickname);
            this.Controls.Add(this.labelNickname);
            this.Name = "FormFavCountry";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.FormFavCountry_Load);
            this.groupBoxAge.ResumeLayout(false);
            this.groupBoxAge.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelNickname;
        private System.Windows.Forms.TextBox textBoxNickname;
        private System.Windows.Forms.CheckBox checkBoxIceCream;
        private System.Windows.Forms.RadioButton radioButtonYoung;
        private System.Windows.Forms.RadioButton radioButtonMiddle;
        private System.Windows.Forms.RadioButton radioButtonOld;
        private System.Windows.Forms.GroupBox groupBoxAge;
        private System.Windows.Forms.Label labelCountry;
        private System.Windows.Forms.ListBox listBoxCountry;
        private System.Windows.Forms.Button buttonPrint;
        private System.Windows.Forms.TextBox textBoxResults;
    }
}

