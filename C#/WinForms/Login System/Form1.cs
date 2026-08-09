using System;
using System.Drawing;
using System.Windows.Forms;

namespace LoginSystem
{
    public partial class LoginForm : Form
    {
        private string correctUsername = "zain";
        private string correctPassword = "123";
        private int loginAttempts = 0;
        private int maxAttempts = 3;

        public LoginForm()
        {
            InitializeComponent();
            this.KeyPreview = true;
            this.KeyDown += LoginForm_KeyDown;
        }

        private void LoginForm_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                btnLogin_Click(sender, e);
            }
        }

        private void btnLogin_Click(object sender, EventArgs e)
        {
            string username = txtUsername.Text.Trim();
            string password = txtPassword.Text;

            if (string.IsNullOrEmpty(username))
            {
                ShowStatus("Please enter a username.", Color.Red);
                txtUsername.Focus();
                return;
            }

            if (string.IsNullOrEmpty(password))
            {
                ShowStatus("Please enter a password.", Color.Red);
                txtPassword.Focus();
                return;
            }

            if (username == correctUsername && password == correctPassword)
            {
                ShowStatus("Login successful! Welcome back!", Color.Green);

                System.Windows.Forms.Timer timer = new System.Windows.Forms.Timer();
                timer.Interval = 2000;
                timer.Tick += (s, args) =>
                {
                    timer.Stop();
                    MessageBox.Show("Welcome to the system!\n\nYou have successfully logged in.",
                                  "Login Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    this.Close();
                };
                timer.Start();
            }
            else
            {
                loginAttempts++;
                int remainingAttempts = maxAttempts - loginAttempts;

                if (remainingAttempts > 0)
                {
                    ShowStatus($"Invalid login! {remainingAttempts} attempts remaining.", Color.Red);
                    txtPassword.Clear();
                    txtPassword.Focus();
                }
                else
                {
                    ShowStatus("Too many failed attempts! Access denied.", Color.Red);
                    btnLogin.Enabled = false;
                    txtUsername.Enabled = false;
                    txtPassword.Enabled = false;

                    MessageBox.Show("Account locked due to multiple failed login attempts.\nPlease contact administrator.",
                                  "Access Denied", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            txtUsername.Clear();
            txtPassword.Clear();
            lblStatus.Text = "";
            txtUsername.Focus();

            if (!btnLogin.Enabled)
            {
                btnLogin.Enabled = true;
                txtUsername.Enabled = true;
                txtPassword.Enabled = true;
                loginAttempts = 0;
            }
        }

        private void chkShowPassword_CheckedChanged(object sender, EventArgs e)
        {
            if (chkShowPassword.Checked)
            {
                txtPassword.PasswordChar = '\0';
            }
            else
            {
                txtPassword.PasswordChar = '*';
            }
        }

        private void ShowStatus(string message, Color color)
        {
            lblStatus.Text = message;
            lblStatus.ForeColor = color;
        }
    }
}