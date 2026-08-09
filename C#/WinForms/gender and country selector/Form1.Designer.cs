namespace Lab19_AdvancedControls
{
    partial class Form1
    {
        private System.ComponentModel.IContainer components = null;
        private System.Windows.Forms.Label labelTitle;
        private System.Windows.Forms.GroupBox groupBoxGender;
        private System.Windows.Forms.RadioButton radioButtonMale;
        private System.Windows.Forms.RadioButton radioButtonFemale;
        private System.Windows.Forms.Label labelCountry;
        private System.Windows.Forms.ComboBox comboBoxCountry;
        private System.Windows.Forms.Button buttonSubmit;
        private System.Windows.Forms.Button buttonClear;
        private System.Windows.Forms.Label labelResult;
        private System.Windows.Forms.Panel panelResult;
        private System.Windows.Forms.Panel panelHeader;
        private System.Windows.Forms.Panel panelInput;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        private void InitializeComponent()
        {
            this.panelHeader = new System.Windows.Forms.Panel();
            this.labelTitle = new System.Windows.Forms.Label();
            this.panelInput = new System.Windows.Forms.Panel();
            this.buttonClear = new System.Windows.Forms.Button();
            this.buttonSubmit = new System.Windows.Forms.Button();
            this.comboBoxCountry = new System.Windows.Forms.ComboBox();
            this.labelCountry = new System.Windows.Forms.Label();
            this.groupBoxGender = new System.Windows.Forms.GroupBox();
            this.radioButtonFemale = new System.Windows.Forms.RadioButton();
            this.radioButtonMale = new System.Windows.Forms.RadioButton();
            this.panelResult = new System.Windows.Forms.Panel();
            this.labelResult = new System.Windows.Forms.Label();
            this.panelHeader.SuspendLayout();
            this.panelInput.SuspendLayout();
            this.groupBoxGender.SuspendLayout();
            this.panelResult.SuspendLayout();
            this.SuspendLayout();

            // panelHeader
            this.panelHeader.BackColor = System.Drawing.Color.FromArgb(240, 248, 255);
            this.panelHeader.Controls.Add(this.labelTitle);
            this.panelHeader.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelHeader.Location = new System.Drawing.Point(0, 0);
            this.panelHeader.Name = "panelHeader";
            this.panelHeader.Size = new System.Drawing.Size(450, 70);
            this.panelHeader.TabIndex = 0;

            // labelTitle
            this.labelTitle.AutoSize = true;
            this.labelTitle.Font = new System.Drawing.Font("Arial", 18F, System.Drawing.FontStyle.Bold);
            this.labelTitle.ForeColor = System.Drawing.Color.FromArgb(25, 25, 112);
            this.labelTitle.Location = new System.Drawing.Point(80, 20);
            this.labelTitle.Name = "labelTitle";
            this.labelTitle.Size = new System.Drawing.Size(290, 29);
            this.labelTitle.TabIndex = 0;
            this.labelTitle.Text = "Personal Information";

            // panelInput
            this.panelInput.BackColor = System.Drawing.Color.White;
            this.panelInput.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panelInput.Controls.Add(this.buttonClear);
            this.panelInput.Controls.Add(this.buttonSubmit);
            this.panelInput.Controls.Add(this.comboBoxCountry);
            this.panelInput.Controls.Add(this.labelCountry);
            this.panelInput.Controls.Add(this.groupBoxGender);
            this.panelInput.Location = new System.Drawing.Point(25, 90);
            this.panelInput.Name = "panelInput";
            this.panelInput.Size = new System.Drawing.Size(400, 280);
            this.panelInput.TabIndex = 1;

            // groupBoxGender
            this.groupBoxGender.BackColor = System.Drawing.Color.White;
            this.groupBoxGender.Controls.Add(this.radioButtonFemale);
            this.groupBoxGender.Controls.Add(this.radioButtonMale);
            this.groupBoxGender.Font = new System.Drawing.Font("Arial", 10F, System.Drawing.FontStyle.Bold);
            this.groupBoxGender.ForeColor = System.Drawing.Color.FromArgb(25, 25, 112);
            this.groupBoxGender.Location = new System.Drawing.Point(20, 20);
            this.groupBoxGender.Name = "groupBoxGender";
            this.groupBoxGender.Size = new System.Drawing.Size(360, 90);
            this.groupBoxGender.TabIndex = 0;
            this.groupBoxGender.TabStop = false;
            this.groupBoxGender.Text = "Select Gender";

            // radioButtonMale
            this.radioButtonMale.AutoSize = true;
            this.radioButtonMale.Font = new System.Drawing.Font("Arial", 10F);
            this.radioButtonMale.ForeColor = System.Drawing.Color.FromArgb(25, 25, 112);
            this.radioButtonMale.Location = new System.Drawing.Point(30, 40);
            this.radioButtonMale.Name = "radioButtonMale";
            this.radioButtonMale.Size = new System.Drawing.Size(60, 20);
            this.radioButtonMale.TabIndex = 0;
            this.radioButtonMale.TabStop = true;
            this.radioButtonMale.Text = "Male";
            this.radioButtonMale.UseVisualStyleBackColor = false;

            // radioButtonFemale
            this.radioButtonFemale.AutoSize = true;
            this.radioButtonFemale.Font = new System.Drawing.Font("Arial", 10F);
            this.radioButtonFemale.ForeColor = System.Drawing.Color.FromArgb(25, 25, 112);
            this.radioButtonFemale.Location = new System.Drawing.Point(160, 40);
            this.radioButtonFemale.Name = "radioButtonFemale";
            this.radioButtonFemale.Size = new System.Drawing.Size(75, 20);
            this.radioButtonFemale.TabIndex = 1;
            this.radioButtonFemale.TabStop = true;
            this.radioButtonFemale.Text = "Female";
            this.radioButtonFemale.UseVisualStyleBackColor = false;

            // labelCountry
            this.labelCountry.AutoSize = true;
            this.labelCountry.Font = new System.Drawing.Font("Arial", 10F, System.Drawing.FontStyle.Bold);
            this.labelCountry.ForeColor = System.Drawing.Color.FromArgb(25, 25, 112);
            this.labelCountry.Location = new System.Drawing.Point(20, 120);
            this.labelCountry.Name = "labelCountry";
            this.labelCountry.Size = new System.Drawing.Size(140, 16);
            this.labelCountry.TabIndex = 2;
            this.labelCountry.Text = "Select Your Country:";

            // comboBoxCountry
            this.comboBoxCountry.BackColor = System.Drawing.Color.FromArgb(245, 245, 245);
            this.comboBoxCountry.ForeColor = System.Drawing.Color.FromArgb(25, 25, 112);
            this.comboBoxCountry.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxCountry.Font = new System.Drawing.Font("Arial", 10F);
            this.comboBoxCountry.FormattingEnabled = true;
            this.comboBoxCountry.Location = new System.Drawing.Point(20, 145);
            this.comboBoxCountry.Name = "comboBoxCountry";
            this.comboBoxCountry.Size = new System.Drawing.Size(360, 24);
            this.comboBoxCountry.TabIndex = 3;

            // buttonSubmit
            this.buttonSubmit.BackColor = System.Drawing.Color.FromArgb(144, 238, 144);
            this.buttonSubmit.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonSubmit.FlatAppearance.BorderSize = 0;
            this.buttonSubmit.Font = new System.Drawing.Font("Arial", 10F, System.Drawing.FontStyle.Bold);
            this.buttonSubmit.ForeColor = System.Drawing.Color.FromArgb(25, 25, 112);
            this.buttonSubmit.Location = new System.Drawing.Point(20, 200);
            this.buttonSubmit.Name = "buttonSubmit";
            this.buttonSubmit.Size = new System.Drawing.Size(100, 40);
            this.buttonSubmit.TabIndex = 4;
            this.buttonSubmit.Text = "Submit";
            this.buttonSubmit.UseVisualStyleBackColor = false;
            this.buttonSubmit.Click += new System.EventHandler(this.buttonSubmit_Click);

            // buttonClear
            this.buttonClear.BackColor = System.Drawing.Color.FromArgb(255, 182, 193);
            this.buttonClear.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonClear.FlatAppearance.BorderSize = 0;
            this.buttonClear.Font = new System.Drawing.Font("Arial", 10F, System.Drawing.FontStyle.Bold);
            this.buttonClear.ForeColor = System.Drawing.Color.FromArgb(25, 25, 112);
            this.buttonClear.Location = new System.Drawing.Point(280, 200);
            this.buttonClear.Name = "buttonClear";
            this.buttonClear.Size = new System.Drawing.Size(100, 40);
            this.buttonClear.TabIndex = 5;
            this.buttonClear.Text = "Clear";
            this.buttonClear.UseVisualStyleBackColor = false;
            this.buttonClear.Click += new System.EventHandler(this.buttonClear_Click);

            // panelResult
            this.panelResult.BackColor = System.Drawing.Color.White;
            this.panelResult.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panelResult.Controls.Add(this.labelResult);
            this.panelResult.Location = new System.Drawing.Point(25, 380);
            this.panelResult.Name = "panelResult";
            this.panelResult.Size = new System.Drawing.Size(400, 100);
            this.panelResult.TabIndex = 6;

            // labelResult
            this.labelResult.Font = new System.Drawing.Font("Arial", 10F, System.Drawing.FontStyle.Bold);
            this.labelResult.ForeColor = System.Drawing.Color.FromArgb(199, 21, 133);
            this.labelResult.Location = new System.Drawing.Point(15, 15);
            this.labelResult.Name = "labelResult";
            this.labelResult.Size = new System.Drawing.Size(370, 80);
            this.labelResult.TabIndex = 0;
            this.labelResult.Text = "Your selection will appear here...";

            // Form settings
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(255, 255, 255);
            this.ClientSize = new System.Drawing.Size(450, 500);
            this.Controls.Add(this.panelResult);
            this.Controls.Add(this.panelInput);
            this.Controls.Add(this.panelHeader);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Advanced Settings";
            this.panelHeader.ResumeLayout(false);
            this.panelHeader.PerformLayout();
            this.panelInput.Controls.Add(this.groupBoxGender);
            this.panelResult.ResumeLayout(false);
        }
    }
}