using System;
using System.Drawing;
using System.Windows.Forms;

namespace HelloWorldApp
{
    public partial class Form1 : Form
    {
        private Button btnHello;
        private Label lblMessage;

        public Form1()
        {
            InitializeComponent();
        }

        private void InitializeComponent()
        {
            // Form properties
            this.Text = "Hello World Application";
            this.Size = new Size(400, 200);
            this.StartPosition = FormStartPosition.CenterScreen;

            // Button
            btnHello = new Button();
            btnHello.Text = "Click Me!";
            btnHello.Size = new Size(100, 30);
            btnHello.Location = new Point(150, 50);
            btnHello.Click += BtnHello_Click;

            // Label
            lblMessage = new Label();
            lblMessage.Text = "";
            lblMessage.Size = new Size(200, 30);
            lblMessage.Location = new Point(100, 100);
            lblMessage.TextAlign = ContentAlignment.MiddleCenter;
            lblMessage.Font = new Font("Arial", 12, FontStyle.Bold);

            // Add controls to form
            this.Controls.Add(btnHello);
            this.Controls.Add(lblMessage);
        }

        private void BtnHello_Click(object sender, EventArgs e)
        {
            lblMessage.Text = "Hello World!";
        }
    }

    // Program entry point
    static class Program
    {
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
