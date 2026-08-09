using System;
using System.Windows.Forms;

namespace Lab19_AdvancedControls
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            LoadCountries();
        }

        private void LoadCountries()
        {
            comboBoxCountry.Items.Add("Please select a country...");
            comboBoxCountry.Items.Add("Pakistan");
            comboBoxCountry.Items.Add("United States");
            comboBoxCountry.Items.Add("Canada");
            comboBoxCountry.Items.Add("United Kingdom");
            comboBoxCountry.Items.Add("Australia");
            comboBoxCountry.Items.Add("Germany");
            comboBoxCountry.Items.Add("France");
            comboBoxCountry.Items.Add("Japan");
            comboBoxCountry.Items.Add("South Korea");
            comboBoxCountry.Items.Add("India");
            comboBoxCountry.Items.Add("Brazil");
            comboBoxCountry.Items.Add("Mexico");
            comboBoxCountry.Items.Add("Italy");
            comboBoxCountry.Items.Add("Spain");
            comboBoxCountry.Items.Add("Netherlands");
            comboBoxCountry.Items.Add("Sweden");

            comboBoxCountry.SelectedIndex = 0;
        }

        private void buttonSubmit_Click(object sender, EventArgs e)
        {
            string selectedGender = "";
            string selectedCountry = "";

            if (radioButtonMale.Checked)
            {
                selectedGender = "Male";
            }
            else if (radioButtonFemale.Checked)
            {
                selectedGender = "Female";
            }
            else
            {
                MessageBox.Show("Please select your gender!", "Missing Information",
                    MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            if (comboBoxCountry.SelectedIndex == 0 || comboBoxCountry.SelectedIndex == -1)
            {
                MessageBox.Show("Please choose a country from the list!", "Missing Information",
                    MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            selectedCountry = comboBoxCountry.SelectedItem.ToString();

            labelResult.Text = $"Thank you for your submission!\n\nGender: {selectedGender}\nCountry: {selectedCountry}";

            MessageBox.Show("Information submitted successfully!", "Success",
                MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void buttonClear_Click(object sender, EventArgs e)
        {
            DialogResult result = MessageBox.Show("Are you sure you want to clear all selections?",
                "Clear Form", MessageBoxButtons.YesNo, MessageBoxIcon.Question);

            if (result == DialogResult.Yes)
            {
                radioButtonMale.Checked = false;
                radioButtonFemale.Checked = false;
                comboBoxCountry.SelectedIndex = 0;
                labelResult.Text = "Your selection will appear here...";

                MessageBox.Show("Form has been cleared!", "Cleared",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }
    }
}