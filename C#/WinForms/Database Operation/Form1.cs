using System;
using System.Collections.Generic;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;

namespace StudentManager
{
    public partial class StudentForm : Form
    {
        private List<Student> students;
        private DataTable studentTable;

        public StudentForm()
        {
            InitializeComponent();
            InitializeData();
            LoadSampleData();
        }

        private void InitializeData()
        {
            students = new List<Student>();

            studentTable = new DataTable();
            studentTable.Columns.Add("ID", typeof(string));
            studentTable.Columns.Add("Name", typeof(string));
            studentTable.Columns.Add("Age", typeof(int));
            studentTable.Columns.Add("Grade", typeof(string));

            dgvStudents.DataSource = studentTable;
        }

        private void LoadSampleData()
        {
            students.Add(new Student { Id = "123", Name = "Abdul Rahman", Age = 20, Grade = "A" });
            students.Add(new Student { Id = "456", Name = "Hassan Tariq", Age = 21, Grade = "A" });

            RefreshGrid();
            ShowStatus("Sample data loaded successfully.", Color.Green);
        }

        private void RefreshGrid()
        {
            studentTable.Clear();
            foreach (var student in students)
            {
                studentTable.Rows.Add(student.Id, student.Name, student.Age, student.Grade);
            }
        }

        private void btnInsert_Click(object sender, EventArgs e)
        {
            if (!ValidateInput()) return;

            string id = txtId.Text.Trim();

            if (students.Any(s => s.Id.Equals(id, StringComparison.OrdinalIgnoreCase)))
            {
                ShowStatus("Student ID already exists! Please use a different ID.", Color.Red);
                txtId.Focus();
                return;
            }

            Student newStudent = new Student
            {
                Id = id,
                Name = txtName.Text.Trim(),
                Age = int.Parse(txtAge.Text),
                Grade = cmbGrade.SelectedItem.ToString()
            };

            students.Add(newStudent);
            RefreshGrid();
            ClearForm();
            ShowStatus($"Student '{newStudent.Name}' added successfully!", Color.Green);
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            if (!ValidateInput()) return;

            string id = txtId.Text.Trim();
            Student existingStudent = students.FirstOrDefault(s => s.Id.Equals(id, StringComparison.OrdinalIgnoreCase));

            if (existingStudent == null)
            {
                ShowStatus("Student ID not found! Please select a student from the list.", Color.Red);
                return;
            }

            existingStudent.Name = txtName.Text.Trim();
            existingStudent.Age = int.Parse(txtAge.Text);
            existingStudent.Grade = cmbGrade.SelectedItem.ToString();

            RefreshGrid();
            ClearForm();
            ShowStatus($"Student '{existingStudent.Name}' updated successfully!", Color.Green);
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            string id = txtId.Text.Trim();

            if (string.IsNullOrEmpty(id))
            {
                ShowStatus("Please enter Student ID or select a student from the list.", Color.Red);
                return;
            }

            Student studentToDelete = students.FirstOrDefault(s => s.Id.Equals(id, StringComparison.OrdinalIgnoreCase));

            if (studentToDelete == null)
            {
                ShowStatus("Student ID not found!", Color.Red);
                return;
            }

            DialogResult result = MessageBox.Show($"Are you sure you want to delete student '{studentToDelete.Name}'?",
                                                "Confirm Delete", MessageBoxButtons.YesNo, MessageBoxIcon.Question);

            if (result == DialogResult.Yes)
            {
                students.Remove(studentToDelete);
                RefreshGrid();
                ClearForm();
                ShowStatus($"Student '{studentToDelete.Name}' deleted successfully!", Color.Green);
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            ClearForm();
            ShowStatus("Form cleared.", Color.Blue);
        }

        private void dgvStudents_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex >= 0 && e.RowIndex < dgvStudents.Rows.Count)
            {
                DataGridViewRow row = dgvStudents.Rows[e.RowIndex];

                txtId.Text = row.Cells["ID"].Value.ToString();
                txtName.Text = row.Cells["Name"].Value.ToString();
                txtAge.Text = row.Cells["Age"].Value.ToString();
                cmbGrade.SelectedItem = row.Cells["Grade"].Value.ToString();

                ShowStatus("Student selected. You can now Update or Delete.", Color.Blue);
            }
        }

        private bool ValidateInput()
        {
            if (string.IsNullOrWhiteSpace(txtId.Text))
            {
                ShowStatus("Please enter Student ID.", Color.Red);
                txtId.Focus();
                return false;
            }

            if (string.IsNullOrWhiteSpace(txtName.Text))
            {
                ShowStatus("Please enter Student Name.", Color.Red);
                txtName.Focus();
                return false;
            }

            if (!int.TryParse(txtAge.Text, out int age) || age < 1 || age > 100)
            {
                ShowStatus("Please enter a valid age (1-100).", Color.Red);
                txtAge.Focus();
                return false;
            }

            if (cmbGrade.SelectedIndex == -1)
            {
                ShowStatus("Please select a grade.", Color.Red);
                cmbGrade.Focus();
                return false;
            }

            return true;
        }

        private void ClearForm()
        {
            txtId.Clear();
            txtName.Clear();
            txtAge.Clear();
            cmbGrade.SelectedIndex = -1;
            txtId.Focus();
        }

        private void ShowStatus(string message, Color color)
        {
            lblStatus.Text = message;
            lblStatus.ForeColor = color;
        }
    }

    public class Student
    {
        public string Id { get; set; }
        public string Name { get; set; }
        public int Age { get; set; }
        public string Grade { get; set; }
    }
}