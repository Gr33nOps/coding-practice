namespace EmployeeSalarySlip
{
    partial class Form1
    {
        private System.ComponentModel.IContainer components = null;
        private System.Windows.Forms.Panel panelHeader;
        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.Panel panelInput;
        private System.Windows.Forms.Label lblEmployeeName;
        private System.Windows.Forms.TextBox txtEmployeeName;
        private System.Windows.Forms.Label lblEmployeeID;
        private System.Windows.Forms.TextBox txtEmployeeID;
        private System.Windows.Forms.Label lblHourlyRate;
        private System.Windows.Forms.TextBox txtHourlyRate;
        private System.Windows.Forms.Label lblHoursWorked;
        private System.Windows.Forms.TextBox txtHoursWorked;
        private System.Windows.Forms.Label lblOvertimeHours;
        private System.Windows.Forms.TextBox txtOvertimeHours;
        private System.Windows.Forms.Button btnCalculate;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.Button btnPrint;
        private System.Windows.Forms.Panel panelSalarySlip;
        private System.Windows.Forms.Label lblResults;
        private System.Windows.Forms.Label lblRegularPay;
        private System.Windows.Forms.Label lblOvertimePay;
        private System.Windows.Forms.Label lblGrossPay;
        private System.Windows.Forms.Label lblTax;
        private System.Windows.Forms.Label lblNetPay;

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
            this.panelInput = new System.Windows.Forms.Panel();
            this.btnCalculate = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.btnPrint = new System.Windows.Forms.Button();
            this.txtOvertimeHours = new System.Windows.Forms.TextBox();
            this.lblOvertimeHours = new System.Windows.Forms.Label();
            this.txtHoursWorked = new System.Windows.Forms.TextBox();
            this.lblHoursWorked = new System.Windows.Forms.Label();
            this.txtHourlyRate = new System.Windows.Forms.TextBox();
            this.lblHourlyRate = new System.Windows.Forms.Label();
            this.txtEmployeeID = new System.Windows.Forms.TextBox();
            this.lblEmployeeID = new System.Windows.Forms.Label();
            this.txtEmployeeName = new System.Windows.Forms.TextBox();
            this.lblEmployeeName = new System.Windows.Forms.Label();
            this.panelSalarySlip = new System.Windows.Forms.Panel();
            this.lblNetPay = new System.Windows.Forms.Label();
            this.lblTax = new System.Windows.Forms.Label();
            this.lblGrossPay = new System.Windows.Forms.Label();
            this.lblOvertimePay = new System.Windows.Forms.Label();
            this.lblRegularPay = new System.Windows.Forms.Label();
            this.lblResults = new System.Windows.Forms.Label();
            this.panelHeader.SuspendLayout();
            this.panelInput.SuspendLayout();
            this.panelSalarySlip.SuspendLayout();
            this.SuspendLayout();

            // panelHeader
            this.panelHeader.BackColor = System.Drawing.Color.FromArgb(173, 216, 230);
            this.panelHeader.Controls.Add(this.lblTitle);
            this.panelHeader.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelHeader.Location = new System.Drawing.Point(0, 0);
            this.panelHeader.Name = "panelHeader";
            this.panelHeader.Size = new System.Drawing.Size(700, 70);
            this.panelHeader.TabIndex = 0;

            // lblTitle
            this.lblTitle.AutoSize = true;
            this.lblTitle.Font = new System.Drawing.Font("Segoe UI", 18F, System.Drawing.FontStyle.Bold);
            this.lblTitle.ForeColor = System.Drawing.Color.FromArgb(44, 62, 80);
            this.lblTitle.Location = new System.Drawing.Point(200, 20);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(300, 32);
            this.lblTitle.TabIndex = 0;
            this.lblTitle.Text = "Weekly Salary Slip";

            // panelInput
            this.panelInput.BackColor = System.Drawing.Color.White;
            this.panelInput.Controls.Add(this.btnPrint);
            this.panelInput.Controls.Add(this.btnClear);
            this.panelInput.Controls.Add(this.btnCalculate);
            this.panelInput.Controls.Add(this.txtOvertimeHours);
            this.panelInput.Controls.Add(this.lblOvertimeHours);
            this.panelInput.Controls.Add(this.txtHoursWorked);
            this.panelInput.Controls.Add(this.lblHoursWorked);
            this.panelInput.Controls.Add(this.txtHourlyRate);
            this.panelInput.Controls.Add(this.lblHourlyRate);
            this.panelInput.Controls.Add(this.txtEmployeeID);
            this.panelInput.Controls.Add(this.lblEmployeeID);
            this.panelInput.Controls.Add(this.txtEmployeeName);
            this.panelInput.Controls.Add(this.lblEmployeeName);
            this.panelInput.Location = new System.Drawing.Point(30, 90);
            this.panelInput.Name = "panelInput";
            this.panelInput.Size = new System.Drawing.Size(320, 430);
            this.panelInput.TabIndex = 1;

            // lblEmployeeName
            this.lblEmployeeName.AutoSize = true;
            this.lblEmployeeName.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.lblEmployeeName.Location = new System.Drawing.Point(20, 20);
            this.lblEmployeeName.Name = "lblEmployeeName";
            this.lblEmployeeName.Size = new System.Drawing.Size(105, 19);
            this.lblEmployeeName.TabIndex = 1;
            this.lblEmployeeName.Text = "Employee Name:";
            this.lblEmployeeName.ForeColor = System.Drawing.Color.FromArgb(44, 62, 80);

            // txtEmployeeName
            this.txtEmployeeName.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.txtEmployeeName.Location = new System.Drawing.Point(20, 45);
            this.txtEmployeeName.Name = "txtEmployeeName";
            this.txtEmployeeName.Size = new System.Drawing.Size(280, 25);
            this.txtEmployeeName.TabIndex = 2;
            this.txtEmployeeName.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtEmployeeName.BackColor = System.Drawing.Color.FromArgb(245, 245, 245);
            this.txtEmployeeName.ForeColor = System.Drawing.Color.FromArgb(44, 62, 80);

            // lblEmployeeID
            this.lblEmployeeID.AutoSize = true;
            this.lblEmployeeID.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.lblEmployeeID.Location = new System.Drawing.Point(20, 80);
            this.lblEmployeeID.Name = "lblEmployeeID";
            this.lblEmployeeID.Size = new System.Drawing.Size(83, 19);
            this.lblEmployeeID.TabIndex = 3;
            this.lblEmployeeID.Text = "Employee ID:";
            this.lblEmployeeID.ForeColor = System.Drawing.Color.FromArgb(44, 62, 80);

            // txtEmployeeID
            this.txtEmployeeID.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.txtEmployeeID.Location = new System.Drawing.Point(20, 105);
            this.txtEmployeeID.Name = "txtEmployeeID";
            this.txtEmployeeID.Size = new System.Drawing.Size(120, 25);
            this.txtEmployeeID.TabIndex = 4;
            this.txtEmployeeID.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtEmployeeID.BackColor = System.Drawing.Color.FromArgb(245, 245, 245);
            this.txtEmployeeID.ForeColor = System.Drawing.Color.FromArgb(44, 62, 80);

            // lblHourlyRate
            this.lblHourlyRate.AutoSize = true;
            this.lblHourlyRate.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.lblHourlyRate.Location = new System.Drawing.Point(20, 140);
            this.lblHourlyRate.Name = "lblHourlyRate";
            this.lblHourlyRate.Size = new System.Drawing.Size(77, 19);
            this.lblHourlyRate.TabIndex = 5;
            this.lblHourlyRate.Text = "Hourly Rate:";
            this.lblHourlyRate.ForeColor = System.Drawing.Color.FromArgb(44, 62, 80);

            // txtHourlyRate
            this.txtHourlyRate.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.txtHourlyRate.Location = new System.Drawing.Point(20, 165);
            this.txtHourlyRate.Name = "txtHourlyRate";
            this.txtHourlyRate.Size = new System.Drawing.Size(120, 25);
            this.txtHourlyRate.TabIndex = 6;
            this.txtHourlyRate.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtHourlyRate.BackColor = System.Drawing.Color.FromArgb(245, 245, 245);
            this.txtHourlyRate.ForeColor = System.Drawing.Color.FromArgb(44, 62, 80);

            // lblHoursWorked
            this.lblHoursWorked.AutoSize = true;
            this.lblHoursWorked.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.lblHoursWorked.Location = new System.Drawing.Point(20, 200);
            this.lblHoursWorked.Name = "lblHoursWorked";
            this.lblHoursWorked.Size = new System.Drawing.Size(90, 19);
            this.lblHoursWorked.TabIndex = 7;
            this.lblHoursWorked.Text = "Hours Worked:";
            this.lblHoursWorked.ForeColor = System.Drawing.Color.FromArgb(44, 62, 80);

            // txtHoursWorked
            this.txtHoursWorked.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.txtHoursWorked.Location = new System.Drawing.Point(20, 225);
            this.txtHoursWorked.Name = "txtHoursWorked";
            this.txtHoursWorked.Size = new System.Drawing.Size(120, 25);
            this.txtHoursWorked.TabIndex = 8;
            this.txtHoursWorked.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtHoursWorked.BackColor = System.Drawing.Color.FromArgb(245, 245, 245);
            this.txtHoursWorked.ForeColor = System.Drawing.Color.FromArgb(44, 62, 80);

            // lblOvertimeHours
            this.lblOvertimeHours.AutoSize = true;
            this.lblOvertimeHours.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.lblOvertimeHours.Location = new System.Drawing.Point(20, 260);
            this.lblOvertimeHours.Name = "lblOvertimeHours";
            this.lblOvertimeHours.Size = new System.Drawing.Size(99, 19);
            this.lblOvertimeHours.TabIndex = 9;
            this.lblOvertimeHours.Text = "Overtime Hours:";
            this.lblOvertimeHours.ForeColor = System.Drawing.Color.FromArgb(44, 62, 80);

            // txtOvertimeHours
            this.txtOvertimeHours.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.txtOvertimeHours.Location = new System.Drawing.Point(20, 285);
            this.txtOvertimeHours.Name = "txtOvertimeHours";
            this.txtOvertimeHours.Size = new System.Drawing.Size(120, 25);
            this.txtOvertimeHours.TabIndex = 10;
            this.txtOvertimeHours.Text = "0";
            this.txtOvertimeHours.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtOvertimeHours.BackColor = System.Drawing.Color.FromArgb(245, 245, 245);
            this.txtOvertimeHours.ForeColor = System.Drawing.Color.FromArgb(44, 62, 80);

            // btnCalculate
            this.btnCalculate.BackColor = System.Drawing.Color.FromArgb(144, 238, 144);
            this.btnCalculate.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnCalculate.FlatAppearance.BorderSize = 0;
            this.btnCalculate.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Bold);
            this.btnCalculate.ForeColor = System.Drawing.Color.FromArgb(44, 62, 80);
            this.btnCalculate.Location = new System.Drawing.Point(20, 330);
            this.btnCalculate.Name = "btnCalculate";
            this.btnCalculate.Size = new System.Drawing.Size(80, 40);
            this.btnCalculate.TabIndex = 11;
            this.btnCalculate.Text = "Calculate";
            this.btnCalculate.UseVisualStyleBackColor = false;
            this.btnCalculate.Click += new System.EventHandler(this.btnCalculate_Click);

            // btnClear
            this.btnClear.BackColor = System.Drawing.Color.FromArgb(255, 182, 193);
            this.btnClear.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnClear.FlatAppearance.BorderSize = 0;
            this.btnClear.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Bold);
            this.btnClear.ForeColor = System.Drawing.Color.FromArgb(44, 62, 80);
            this.btnClear.Location = new System.Drawing.Point(110, 330);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(80, 40);
            this.btnClear.TabIndex = 12;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = false;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);

            // btnPrint
            this.btnPrint.BackColor = System.Drawing.Color.FromArgb(135, 206, 250);
            this.btnPrint.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnPrint.FlatAppearance.BorderSize = 0;
            this.btnPrint.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Bold);
            this.btnPrint.ForeColor = System.Drawing.Color.FromArgb(44, 62, 80);
            this.btnPrint.Location = new System.Drawing.Point(200, 330);
            this.btnPrint.Name = "btnPrint";
            this.btnPrint.Size = new System.Drawing.Size(80, 40);
            this.btnPrint.TabIndex = 13;
            this.btnPrint.Text = "Print Slip";
            this.btnPrint.UseVisualStyleBackColor = false;
            this.btnPrint.Click += new System.EventHandler(this.btnPrint_Click);

            // panelSalarySlip
            this.panelSalarySlip.BackColor = System.Drawing.Color.White;
            this.panelSalarySlip.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panelSalarySlip.Controls.Add(this.lblNetPay);
            this.panelSalarySlip.Controls.Add(this.lblTax);
            this.panelSalarySlip.Controls.Add(this.lblGrossPay);
            this.panelSalarySlip.Controls.Add(this.lblOvertimePay);
            this.panelSalarySlip.Controls.Add(this.lblRegularPay);
            this.panelSalarySlip.Controls.Add(this.lblResults);
            this.panelSalarySlip.Location = new System.Drawing.Point(360, 90);
            this.panelSalarySlip.Name = "panelSalarySlip";
            this.panelSalarySlip.Size = new System.Drawing.Size(310, 430);
            this.panelSalarySlip.TabIndex = 14;
            this.panelSalarySlip.Visible = false;

            // lblResults
            this.lblResults.AutoSize = true;
            this.lblResults.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Bold);
            this.lblResults.ForeColor = System.Drawing.Color.FromArgb(75, 0, 130);
            this.lblResults.Location = new System.Drawing.Point(20, 20);
            this.lblResults.Name = "lblResults";
            this.lblResults.Size = new System.Drawing.Size(120, 25);
            this.lblResults.TabIndex = 14;
            this.lblResults.Text = "Salary Details";

            // lblRegularPay
            this.lblRegularPay.AutoSize = true;
            this.lblRegularPay.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.lblRegularPay.Location = new System.Drawing.Point(20, 60);
            this.lblRegularPay.Name = "lblRegularPay";
            this.lblRegularPay.Size = new System.Drawing.Size(80, 19);
            this.lblRegularPay.TabIndex = 15;
            this.lblRegularPay.Text = "Regular Pay:";
            this.lblRegularPay.ForeColor = System.Drawing.Color.FromArgb(44, 62, 80);

            // lblOvertimePay
            this.lblOvertimePay.AutoSize = true;
            this.lblOvertimePay.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.lblOvertimePay.Location = new System.Drawing.Point(20, 90);
            this.lblOvertimePay.Name = "lblOvertimePay";
            this.lblOvertimePay.Size = new System.Drawing.Size(86, 19);
            this.lblOvertimePay.TabIndex = 16;
            this.lblOvertimePay.Text = "Overtime Pay:";
            this.lblOvertimePay.ForeColor = System.Drawing.Color.FromArgb(44, 62, 80);

            // lblGrossPay
            this.lblGrossPay.AutoSize = true;
            this.lblGrossPay.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Bold);
            this.lblGrossPay.Location = new System.Drawing.Point(20, 120);
            this.lblGrossPay.Name = "lblGrossPay";
            this.lblGrossPay.Size = new System.Drawing.Size(76, 19);
            this.lblGrossPay.TabIndex = 17;
            this.lblGrossPay.Text = "Gross Pay:";
            this.lblGrossPay.ForeColor = System.Drawing.Color.FromArgb(44, 62, 80);

            // lblTax
            this.lblTax.AutoSize = true;
            this.lblTax.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.lblTax.Location = new System.Drawing.Point(20, 150);
            this.lblTax.Name = "lblTax";
            this.lblTax.Size = new System.Drawing.Size(67, 19);
            this.lblTax.TabIndex = 18;
            this.lblTax.Text = "Tax (15%):";
            this.lblTax.ForeColor = System.Drawing.Color.FromArgb(44, 62, 80);

            // lblNetPay
            this.lblNetPay.AutoSize = true;
            this.lblNetPay.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Bold);
            this.lblNetPay.ForeColor = System.Drawing.Color.FromArgb(199, 21, 133);
            this.lblNetPay.Location = new System.Drawing.Point(20, 180);
            this.lblNetPay.Name = "lblNetPay";
            this.lblNetPay.Size = new System.Drawing.Size(71, 21);
            this.lblNetPay.TabIndex = 19;
            this.lblNetPay.Text = "Net Pay:";

            // Form settings
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(255, 255, 255);
            this.ClientSize = new System.Drawing.Size(700, 550);
            this.Controls.Add(this.panelSalarySlip);
            this.Controls.Add(this.panelInput);
            this.Controls.Add(this.panelHeader);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Weekly Salary Slip Generator";
            this.panelHeader.ResumeLayout(false);
            this.panelHeader.PerformLayout();
            this.panelInput.ResumeLayout(false);
            this.panelInput.PerformLayout();
            this.panelSalarySlip.ResumeLayout(false);
            this.panelSalarySlip.PerformLayout();
            this.ResumeLayout(false);
        }
    }
}