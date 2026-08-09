namespace StudentGradeCalculator
{
    partial class Form1
    {
        private System.ComponentModel.IContainer components = null;
        private System.Windows.Forms.Panel panelHeader;
        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.Panel panelCard;
        private System.Windows.Forms.Label lblStudentName;
        private System.Windows.Forms.TextBox txtStudentName;
        private System.Windows.Forms.Label lblMath;
        private System.Windows.Forms.TextBox txtMath;
        private System.Windows.Forms.Label lblEnglish;
        private System.Windows.Forms.TextBox txtEnglish;
        private System.Windows.Forms.Label lblScience;
        private System.Windows.Forms.TextBox txtScience;
        private System.Windows.Forms.Button btnCalculate;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.Label lblResult;
        private System.Windows.Forms.Label lblAverage;
        private System.Windows.Forms.Label lblGrade;

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
            this.lblTitle = new System.Windows.Forms.Label();
            this.panelCard = new System.Windows.Forms.Panel();
            this.lblStudentName = new System.Windows.Forms.Label();
            this.txtStudentName = new System.Windows.Forms.TextBox();
            this.lblMath = new System.Windows.Forms.Label();
            this.txtMath = new System.Windows.Forms.TextBox();
            this.lblEnglish = new System.Windows.Forms.Label();
            this.txtEnglish = new System.Windows.Forms.TextBox();
            this.lblScience = new System.Windows.Forms.Label();
            this.txtScience = new System.Windows.Forms.TextBox();
            this.btnCalculate = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.lblResult = new System.Windows.Forms.Label();
            this.lblAverage = new System.Windows.Forms.Label();
            this.lblGrade = new System.Windows.Forms.Label();
            this.panelHeader.SuspendLayout();
            this.panelCard.SuspendLayout();
            this.SuspendLayout();

            // panelHeader
            this.panelHeader.BackColor = System.Drawing.Color.FromArgb(255, 182, 193);
            this.panelHeader.Controls.Add(this.lblTitle);
            this.panelHeader.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelHeader.Location = new System.Drawing.Point(0, 0);
            this.panelHeader.Name = "panelHeader";
            this.panelHeader.Size = new System.Drawing.Size(450, 60);
            this.panelHeader.TabIndex = 0;

            // lblTitle
            this.lblTitle.AutoSize = true;
            this.lblTitle.Font = new System.Drawing.Font("Arial", 16F, System.Drawing.FontStyle.Bold);
            this.lblTitle.ForeColor = System.Drawing.Color.FromArgb(51, 51, 51);
            this.lblTitle.Location = new System.Drawing.Point(100, 15);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(250, 26);
            this.lblTitle.TabIndex = 0;
            this.lblTitle.Text = "Grade Calculator";

            // panelCard
            this.panelCard.BackColor = System.Drawing.Color.White;
            this.panelCard.Controls.Add(this.lblGrade);
            this.panelCard.Controls.Add(this.lblAverage);
            this.panelCard.Controls.Add(this.lblResult);
            this.panelCard.Controls.Add(this.btnClear);
            this.panelCard.Controls.Add(this.btnCalculate);
            this.panelCard.Controls.Add(this.txtScience);
            this.panelCard.Controls.Add(this.lblScience);
            this.panelCard.Controls.Add(this.txtEnglish);
            this.panelCard.Controls.Add(this.lblEnglish);
            this.panelCard.Controls.Add(this.txtMath);
            this.panelCard.Controls.Add(this.lblMath);
            this.panelCard.Controls.Add(this.txtStudentName);
            this.panelCard.Controls.Add(this.lblStudentName);
            this.panelCard.Location = new System.Drawing.Point(25, 70);
            this.panelCard.Name = "panelCard";
            this.panelCard.Size = new System.Drawing.Size(400, 400);
            this.panelCard.TabIndex = 1;

            // lblStudentName
            this.lblStudentName.AutoSize = true;
            this.lblStudentName.Font = new System.Drawing.Font("Arial", 11F);
            this.lblStudentName.Location = new System.Drawing.Point(20, 20);
            this.lblStudentName.Name = "lblStudentName";
            this.lblStudentName.Size = new System.Drawing.Size(95, 18);
            this.lblStudentName.TabIndex = 1;
            this.lblStudentName.Text = "Student Name:";
            this.lblStudentName.ForeColor = System.Drawing.Color.FromArgb(51, 51, 51);

            // txtStudentName
            this.txtStudentName.Font = new System.Drawing.Font("Arial", 11F);
            this.txtStudentName.Location = new System.Drawing.Point(20, 45);
            this.txtStudentName.Name = "txtStudentName";
            this.txtStudentName.Size = new System.Drawing.Size(360, 24);
            this.txtStudentName.TabIndex = 2;
            this.txtStudentName.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtStudentName.BackColor = System.Drawing.Color.FromArgb(240, 240, 240);
            this.txtStudentName.ForeColor = System.Drawing.Color.FromArgb(51, 51, 51);

            // lblMath
            this.lblMath.AutoSize = true;
            this.lblMath.Font = new System.Drawing.Font("Arial", 11F);
            this.lblMath.Location = new System.Drawing.Point(20, 80);
            this.lblMath.Name = "lblMath";
            this.lblMath.Size = new System.Drawing.Size(80, 18);
            this.lblMath.TabIndex = 3;
            this.lblMath.Text = "Math Score:";
            this.lblMath.ForeColor = System.Drawing.Color.FromArgb(51, 51, 51);

            // txtMath
            this.txtMath.Font = new System.Drawing.Font("Arial", 11F);
            this.txtMath.Location = new System.Drawing.Point(20, 105);
            this.txtMath.Name = "txtMath";
            this.txtMath.Size = new System.Drawing.Size(120, 24);
            this.txtMath.TabIndex = 4;
            this.txtMath.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtMath.BackColor = System.Drawing.Color.FromArgb(240, 240, 240);
            this.txtMath.ForeColor = System.Drawing.Color.FromArgb(51, 51, 51);

            // lblEnglish
            this.lblEnglish.AutoSize = true;
            this.lblEnglish.Font = new System.Drawing.Font("Arial", 11F);
            this.lblEnglish.Location = new System.Drawing.Point(20, 140);
            this.lblEnglish.Name = "lblEnglish";
            this.lblEnglish.Size = new System.Drawing.Size(93, 18);
            this.lblEnglish.TabIndex = 5;
            this.lblEnglish.Text = "English Score:";
            this.lblEnglish.ForeColor = System.Drawing.Color.FromArgb(51, 51, 51);

            // txtEnglish
            this.txtEnglish.Font = new System.Drawing.Font("Arial", 11F);
            this.txtEnglish.Location = new System.Drawing.Point(20, 165);
            this.txtEnglish.Name = "txtEnglish";
            this.txtEnglish.Size = new System.Drawing.Size(120, 24);
            this.txtEnglish.TabIndex = 6;
            this.txtEnglish.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtEnglish.BackColor = System.Drawing.Color.FromArgb(240, 240, 240);
            this.txtEnglish.ForeColor = System.Drawing.Color.FromArgb(51, 51, 51);

            // lblScience
            this.lblScience.AutoSize = true;
            this.lblScience.Font = new System.Drawing.Font("Arial", 11F);
            this.lblScience.Location = new System.Drawing.Point(20, 200);
            this.lblScience.Name = "lblScience";
            this.lblScience.Size = new System.Drawing.Size(97, 18);
            this.lblScience.TabIndex = 7;
            this.lblScience.Text = "Science Score:";
            this.lblScience.ForeColor = System.Drawing.Color.FromArgb(51, 51, 51);

            // txtScience
            this.txtScience.Font = new System.Drawing.Font("Arial", 11F);
            this.txtScience.Location = new System.Drawing.Point(20, 225);
            this.txtScience.Name = "txtScience";
            this.txtScience.Size = new System.Drawing.Size(120, 24);
            this.txtScience.TabIndex = 8;
            this.txtScience.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtScience.BackColor = System.Drawing.Color.FromArgb(240, 240, 240);
            this.txtScience.ForeColor = System.Drawing.Color.FromArgb(51, 51, 51);

            // btnCalculate
            this.btnCalculate.BackColor = System.Drawing.Color.FromArgb(124, 252, 0);
            this.btnCalculate.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnCalculate.FlatAppearance.BorderSize = 0;
            this.btnCalculate.Font = new System.Drawing.Font("Arial", 11F, System.Drawing.FontStyle.Bold);
            this.btnCalculate.ForeColor = System.Drawing.Color.FromArgb(51, 51, 51);
            this.btnCalculate.Location = new System.Drawing.Point(20, 265);
            this.btnCalculate.Name = "btnCalculate";
            this.btnCalculate.Size = new System.Drawing.Size(60, 60);
            this.btnCalculate.TabIndex = 9;
            this.btnCalculate.Text = "Calc";
            this.btnCalculate.UseVisualStyleBackColor = false;
            this.btnCalculate.Click += new System.EventHandler(this.btnCalculate_Click);

            // btnClear
            this.btnClear.BackColor = System.Drawing.Color.FromArgb(255, 105, 180);
            this.btnClear.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnClear.FlatAppearance.BorderSize = 0;
            this.btnClear.Font = new System.Drawing.Font("Arial", 11F, System.Drawing.FontStyle.Bold);
            this.btnClear.ForeColor = System.Drawing.Color.FromArgb(51, 51, 51);
            this.btnClear.Location = new System.Drawing.Point(90, 265);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(60, 60);
            this.btnClear.TabIndex = 10;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = false;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);

            // lblResult
            this.lblResult.AutoSize = true;
            this.lblResult.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold);
            this.lblResult.ForeColor = System.Drawing.Color.FromArgb(139, 0, 139);
            this.lblResult.Location = new System.Drawing.Point(20, 335);
            this.lblResult.Name = "lblResult";
            this.lblResult.Size = new System.Drawing.Size(65, 19);
            this.lblResult.TabIndex = 11;
            this.lblResult.Text = "Results";

            // lblAverage
            this.lblAverage.AutoSize = true;
            this.lblAverage.Font = new System.Drawing.Font("Arial", 11F);
            this.lblAverage.Location = new System.Drawing.Point(20, 365);
            this.lblAverage.Name = "lblAverage";
            this.lblAverage.Size = new System.Drawing.Size(67, 18);
            this.lblAverage.TabIndex = 12;
            this.lblAverage.Text = "Average:";
            this.lblAverage.ForeColor = System.Drawing.Color.FromArgb(51, 51, 51);

            // lblGrade
            this.lblGrade.AutoSize = true;
            this.lblGrade.Font = new System.Drawing.Font("Arial", 11F);
            this.lblGrade.Location = new System.Drawing.Point(20, 395);
            this.lblGrade.Name = "lblGrade";
            this.lblGrade.Size = new System.Drawing.Size(52, 18);
            this.lblGrade.TabIndex = 13;
            this.lblGrade.Text = "Grade:";
            this.lblGrade.ForeColor = System.Drawing.Color.FromArgb(51, 51, 51);

            // Form settings
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(245, 245, 220);
            this.ClientSize = new System.Drawing.Size(450, 500);
            this.Controls.Add(this.panelCard);
            this.Controls.Add(this.panelHeader);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Grade Calculator";
            this.panelHeader.ResumeLayout(false);
            this.panelHeader.PerformLayout();
            this.panelCard.ResumeLayout(false);
            this.panelCard.PerformLayout();
            this.ResumeLayout(false);
        }
    }
}