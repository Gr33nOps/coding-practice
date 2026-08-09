using System;
using System.Windows.Forms;

namespace GreetingApp
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void btnGreet_Click(object sender, EventArgs e)
        {
            string name = txtName.Text.Trim();

            if (string.IsNullOrEmpty(name))
            {
                MessageBox.Show("Please enter your name first!", "Empty Name",
                               MessageBoxButtons.OK, MessageBoxIcon.Warning);
                txtName.Focus();
                return;
            }

            DateTime currentTime = DateTime.Now;
            string timeGreeting;

            if (currentTime.Hour < 12)
                timeGreeting = "Good Morning";
            else if (currentTime.Hour < 17)
                timeGreeting = "Good Afternoon";

            else
                timeGreeting = "Good Evening";

            lblGreeting.Text = $"{timeGreeting}, {name}!";
        }
    }
}