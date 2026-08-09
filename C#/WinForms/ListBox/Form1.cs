using System;
using System.Windows.Forms;

namespace Lab18_ListBoxOperations
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            string nameToAdd = textBoxName.Text.Trim();

            if (nameToAdd == "")
            {
                MessageBox.Show("Please enter a name first!", "Empty Name",
                    MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            if (listBoxNames.Items.Contains(nameToAdd))
            {
                MessageBox.Show("This name already exists in the list!", "Duplicate Name",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }

            listBoxNames.Items.Add(nameToAdd);
            textBoxName.Clear();
            textBoxName.Focus();

            MessageBox.Show($"'{nameToAdd}' has been added to the list!", "Success",
                MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            if (listBoxNames.SelectedIndex == -1)
            {
                MessageBox.Show("Please select a name from the list first!", "No Selection",
                    MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            string selectedName = listBoxNames.SelectedItem.ToString();

            DialogResult result = MessageBox.Show($"Are you sure you want to delete '{selectedName}'?",
                "Confirm Delete", MessageBoxButtons.YesNo, MessageBoxIcon.Question);

            if (result == DialogResult.Yes)
            {
                listBoxNames.Items.RemoveAt(listBoxNames.SelectedIndex);
                MessageBox.Show($"'{selectedName}' has been removed from the list!", "Deleted",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }
    }
}