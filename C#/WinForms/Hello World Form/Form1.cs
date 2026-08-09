namespace Hello_World_Form
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Hello, World!");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            DateTime birth = Birth.Value;
            DateTime current = Current.Value;

            int age = current.Year - birth.Year;

            if (current < birth.AddYears(age))
            {
                age--;
            }

            lblAge.Text = $"Your age = {age}";
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            lblTime.Text = DateTime.Now.ToString("HH:mm:ss");
            lblDate.Text = DateTime.Now.ToString("MMM dd yyyy");
            lblDay.Text = DateTime.Now.ToString("dddd");
        }

        private void Form1_Load_1(object sender, EventArgs e)
        {
            timer1.Start();
        }
    }
}
