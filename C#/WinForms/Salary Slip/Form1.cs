using System;
using System.Drawing;
using System.Windows.Forms;

namespace EmployeeSalarySlip
{
    public partial class Form1 : Form
    {
        private double regularPay;
        private double overtimePay;
        private double grossPay;
        private double taxAmount;
        private double netPay;

        public Form1()
        {
            InitializeComponent();
        }

        private void btnCalculate_Click(object sender, EventArgs e)
        {
            try
            {
                if (string.IsNullOrEmpty(txtEmployeeName.Text.Trim()))
                {
                    MessageBox.Show("Please enter the employee's name!", "Missing Information",
                                  MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    txtEmployeeName.Focus();
                    return;
                }

                if (string.IsNullOrEmpty(txtEmployeeID.Text.Trim()))
                {
                    MessageBox.Show("Please enter the employee ID!", "Missing Information",
                                  MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    txtEmployeeID.Focus();
                    return;
                }

                if (string.IsNullOrEmpty(txtHourlyRate.Text) || string.IsNullOrEmpty(txtHoursWorked.Text))
                {
                    MessageBox.Show("Please fill in hourly rate and hours worked!", "Missing Information",
                                  MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }

                double hourlyRate = Convert.ToDouble(txtHourlyRate.Text);
                double hoursWorked = Convert.ToDouble(txtHoursWorked.Text);
                double overtimeHours = Convert.ToDouble(txtOvertimeHours.Text);

                if (hourlyRate <= 0)
                {
                    MessageBox.Show("Hourly rate must be greater than 0!", "Invalid Input",
                                  MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }

                if (hoursWorked < 0 || overtimeHours < 0)
                {
                    MessageBox.Show("Hours cannot be negative!", "Invalid Input",
                                  MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }

                regularPay = hoursWorked * hourlyRate;
                overtimePay = overtimeHours * hourlyRate * 1.5;
                grossPay = regularPay + overtimePay;
                taxAmount = grossPay * 0.15;
                netPay = grossPay - taxAmount;

                lblRegularPay.Text = $"Regular Pay: ${regularPay:F2}";
                lblOvertimePay.Text = $"Overtime Pay: ${overtimePay:F2}";
                lblGrossPay.Text = $"Gross Pay: ${grossPay:F2}";
                lblTax.Text = $"Tax (15%): ${taxAmount:F2}";
                lblNetPay.Text = $"Net Pay: ${netPay:F2}";

                string message = $"Salary calculated successfully for {txtEmployeeName.Text}!\n\n";
                message += $"Regular Hours: {hoursWorked} hrs × ${hourlyRate:F2} = ${regularPay:F2}\n";

                if (overtimeHours > 0)
                    message += $"Overtime Hours: {overtimeHours} hrs × ${hourlyRate * 1.5:F2} = ${overtimePay:F2}\n";

                message += $"Gross Pay: ${grossPay:F2}\n";
                message += $"Tax Deduction: ${taxAmount:F2}\n";
                message += $"Net Pay: ${netPay:F2}";

                MessageBox.Show(message, "Salary Calculation Complete",
                              MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Please enter valid numbers for rates and hours!", "Input Error",
                              MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            txtEmployeeName.Clear();
            txtEmployeeID.Clear();
            txtHourlyRate.Clear();
            txtHoursWorked.Clear();
            txtOvertimeHours.Text = "0";

            lblRegularPay.Text = "Regular Pay:";
            lblOvertimePay.Text = "Overtime Pay:";
            lblGrossPay.Text = "Gross Pay:";
            lblTax.Text = "Tax (15%):";
            lblNetPay.Text = "Net Pay:";

            panelSalarySlip.Visible = false;
            txtEmployeeName.Focus();
        }

        private void btnPrint_Click(object sender, EventArgs e)
        {
            if (netPay == 0)
            {
                MessageBox.Show("Please calculate the salary first!", "No Data",
                              MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            CreateSalarySlip();
            panelSalarySlip.Visible = true;

            MessageBox.Show("Salary slip generated! You can now see the formatted slip on the right.\nIn a real application, this would be sent to a printer.",
                          "Salary Slip Ready", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void CreateSalarySlip()
        {
            panelSalarySlip.Controls.Clear();

            Label titleSlip = new Label
            {
                Text = "WEEKLY SALARY SLIP",
                Font = new Font("Arial", 14, FontStyle.Bold),
                ForeColor = Color.DarkBlue,
                Location = new Point(50, 20),
                Size = new Size(200, 30)
            };

            Label companyName = new Label
            {
                Text = "ABC Company Ltd.",
                Font = new Font("Arial", 12, FontStyle.Bold),
                Location = new Point(80, 50),
                Size = new Size(150, 25)
            };

            Label empName = new Label
            {
                Text = $"Employee: {txtEmployeeName.Text}",
                Font = new Font("Arial", 10),
                Location = new Point(20, 90),
                Size = new Size(250, 20)
            };

            Label empID = new Label
            {
                Text = $"ID: {txtEmployeeID.Text}",
                Font = new Font("Arial", 10),
                Location = new Point(20, 115),
                Size = new Size(200, 20)
            };

            Label payDate = new Label
            {
                Text = $"Pay Date: {DateTime.Now.ToString("MM/dd/yyyy")}",
                Font = new Font("Arial", 10),
                Location = new Point(20, 140),
                Size = new Size(200, 20)
            };

            Label separator1 = new Label
            {
                Text = "--------------------------------",
                Font = new Font("Arial", 10),
                Location = new Point(20, 170),
                Size = new Size(250, 20)
            };

            Label regPaySlip = new Label
            {
                Text = $"Regular Pay: ${regularPay:F2}",
                Font = new Font("Arial", 10),
                Location = new Point(20, 200),
                Size = new Size(200, 20)
            };

            Label overtimePaySlip = new Label
            {
                Text = $"Overtime Pay: ${overtimePay:F2}",
                Font = new Font("Arial", 10),
                Location = new Point(20, 225),
                Size = new Size(200, 20)
            };

            Label grossPaySlip = new Label
            {
                Text = $"Gross Pay: ${grossPay:F2}",
                Font = new Font("Arial", 10, FontStyle.Bold),
                Location = new Point(20, 250),
                Size = new Size(200, 20)
            };

            Label taxSlip = new Label
            {
                Text = $"Tax (15%): -${taxAmount:F2}",
                Font = new Font("Arial", 10),
                Location = new Point(20, 275),
                Size = new Size(200, 20)
            };

            Label separator2 = new Label
            {
                Text = "--------------------------------",
                Font = new Font("Arial", 10),
                Location = new Point(20, 300),
                Size = new Size(250, 20)
            };

            Label netPaySlip = new Label
            {
                Text = $"NET PAY: ${netPay:F2}",
                Font = new Font("Arial", 12, FontStyle.Bold),
                ForeColor = Color.Red,
                Location = new Point(20, 330),
                Size = new Size(200, 25)
            };

            Label footer = new Label
            {
                Text = "Thank you for your hard work!",
                Font = new Font("Arial", 9, FontStyle.Italic),
                ForeColor = Color.Gray,
                Location = new Point(50, 380),
                Size = new Size(200, 20)
            };

            panelSalarySlip.Controls.AddRange(new Control[] {
                titleSlip, companyName, empName, empID, payDate, separator1,
                regPaySlip, overtimePaySlip, grossPaySlip, taxSlip, separator2,
                netPaySlip, footer
            });
        }
    }
}