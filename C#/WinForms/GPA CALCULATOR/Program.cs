using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GPACalculator
{
    public partial class Form1 : Form
    {
        private List<Course> courses;
        private DataGridView dgvCourses;
        private TextBox txtCourseName;
        private ComboBox cbGrade;
        private NumericUpDown nudCreditHours;
        private Button btnAddCourse;
        private Button btnRemoveCourse;
        private Button btnClearAll;
        private Label lblCurrentGPA;
        private Label lblTotalCredits;
        private Label lblTotalPoints;
        private GroupBox gbCourseEntry;
        private GroupBox gbResults;

        public Form1()
        {
            InitializeComponent();
            courses = new List<Course>();
            SetupGradeComboBox();
            UpdateGPADisplay();
        }

        private void InitializeComponent()
        {
            this.SuspendLayout();

            // Form properties
            this.Text = "GPA Calculator";
            this.Size = new Size(800, 600);
            this.StartPosition = FormStartPosition.CenterScreen;
            this.Font = new Font("Segoe UI", 9F);

            // Course Entry GroupBox
            gbCourseEntry = new GroupBox();
            gbCourseEntry.Text = "Add Course";
            gbCourseEntry.Location = new Point(12, 12);
            gbCourseEntry.Size = new Size(760, 120);
            gbCourseEntry.Font = new Font("Segoe UI", 9F, FontStyle.Bold);

            // Course Name
            Label lblCourseName = new Label();
            lblCourseName.Text = "Course Name:";
            lblCourseName.Location = new Point(15, 30);
            lblCourseName.Size = new Size(100, 23);
            lblCourseName.Font = new Font("Segoe UI", 9F);

            txtCourseName = new TextBox();
            txtCourseName.Location = new Point(120, 27);
            txtCourseName.Size = new Size(200, 23);
            txtCourseName.Font = new Font("Segoe UI", 9F);

            // Grade
            Label lblGrade = new Label();
            lblGrade.Text = "Grade:";
            lblGrade.Location = new Point(340, 30);
            lblGrade.Size = new Size(50, 23);
            lblGrade.Font = new Font("Segoe UI", 9F);

            cbGrade = new ComboBox();
            cbGrade.Location = new Point(395, 27);
            cbGrade.Size = new Size(80, 23);
            cbGrade.DropDownStyle = ComboBoxStyle.DropDownList;
            cbGrade.Font = new Font("Segoe UI", 9F);

            // Credit Hours
            Label lblCreditHours = new Label();
            lblCreditHours.Text = "Credit Hours:";
            lblCreditHours.Location = new Point(490, 30);
            lblCreditHours.Size = new Size(80, 23);
            lblCreditHours.Font = new Font("Segoe UI", 9F);

            nudCreditHours = new NumericUpDown();
            nudCreditHours.Location = new Point(575, 27);
            nudCreditHours.Size = new Size(60, 23);
            nudCreditHours.Minimum = 0.5M;
            nudCreditHours.Maximum = 10M;
            nudCreditHours.DecimalPlaces = 1;
            nudCreditHours.Increment = 0.5M;
            nudCreditHours.Value = 3M;
            nudCreditHours.Font = new Font("Segoe UI", 9F);

            // Buttons
            btnAddCourse = new Button();
            btnAddCourse.Text = "Add Course";
            btnAddCourse.Location = new Point(120, 70);
            btnAddCourse.Size = new Size(100, 30);
            btnAddCourse.BackColor = Color.FromArgb(0, 120, 215);
            btnAddCourse.ForeColor = Color.White;
            btnAddCourse.FlatStyle = FlatStyle.Flat;
            btnAddCourse.Font = new Font("Segoe UI", 9F);
            btnAddCourse.Click += BtnAddCourse_Click;

            btnRemoveCourse = new Button();
            btnRemoveCourse.Text = "Remove Selected";
            btnRemoveCourse.Location = new Point(230, 70);
            btnRemoveCourse.Size = new Size(120, 30);
            btnRemoveCourse.BackColor = Color.FromArgb(215, 0, 0);
            btnRemoveCourse.ForeColor = Color.White;
            btnRemoveCourse.FlatStyle = FlatStyle.Flat;
            btnRemoveCourse.Font = new Font("Segoe UI", 9F);
            btnRemoveCourse.Click += BtnRemoveCourse_Click;

            btnClearAll = new Button();
            btnClearAll.Text = "Clear All";
            btnClearAll.Location = new Point(360, 70);
            btnClearAll.Size = new Size(100, 30);
            btnClearAll.BackColor = Color.FromArgb(150, 150, 150);
            btnClearAll.ForeColor = Color.White;
            btnClearAll.FlatStyle = FlatStyle.Flat;
            btnClearAll.Font = new Font("Segoe UI", 9F);
            btnClearAll.Click += BtnClearAll_Click;

            // Add controls to GroupBox
            gbCourseEntry.Controls.AddRange(new Control[] {
                lblCourseName, txtCourseName, lblGrade, cbGrade,
                lblCreditHours, nudCreditHours, btnAddCourse, btnRemoveCourse, btnClearAll
            });

            // DataGridView for courses
            dgvCourses = new DataGridView();
            dgvCourses.Location = new Point(12, 140);
            dgvCourses.Size = new Size(760, 300);
            dgvCourses.AutoGenerateColumns = false;
            dgvCourses.AllowUserToAddRows = false;
            dgvCourses.AllowUserToDeleteRows = false;
            dgvCourses.ReadOnly = true;
            dgvCourses.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
            dgvCourses.MultiSelect = false;
            dgvCourses.BackgroundColor = Color.White;
            dgvCourses.BorderStyle = BorderStyle.Fixed3D;
            dgvCourses.Font = new Font("Segoe UI", 9F);

            // Setup DataGridView columns
            SetupDataGridView();

            // Results GroupBox
            gbResults = new GroupBox();
            gbResults.Text = "GPA Results";
            gbResults.Location = new Point(12, 450);
            gbResults.Size = new Size(760, 100);
            gbResults.Font = new Font("Segoe UI", 9F, FontStyle.Bold);

            lblCurrentGPA = new Label();
            lblCurrentGPA.Text = "Current GPA: 0.00";
            lblCurrentGPA.Location = new Point(20, 30);
            lblCurrentGPA.Size = new Size(200, 25);
            lblCurrentGPA.Font = new Font("Segoe UI", 12F, FontStyle.Bold);
            lblCurrentGPA.ForeColor = Color.FromArgb(0, 120, 215);

            lblTotalCredits = new Label();
            lblTotalCredits.Text = "Total Credits: 0.0";
            lblTotalCredits.Location = new Point(250, 30);
            lblTotalCredits.Size = new Size(150, 25);
            lblTotalCredits.Font = new Font("Segoe UI", 10F);

            lblTotalPoints = new Label();
            lblTotalPoints.Text = "Total Points: 0.00";
            lblTotalPoints.Location = new Point(420, 30);
            lblTotalPoints.Size = new Size(150, 25);
            lblTotalPoints.Font = new Font("Segoe UI", 10F);

            gbResults.Controls.AddRange(new Control[] { lblCurrentGPA, lblTotalCredits, lblTotalPoints });

            // Add all controls to form
            this.Controls.AddRange(new Control[] { gbCourseEntry, dgvCourses, gbResults });

            this.ResumeLayout(false);
        }

        private void SetupDataGridView()
        {
            dgvCourses.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name = "CourseName",
                HeaderText = "Course Name",
                DataPropertyName = "CourseName",
                Width = 300
            });

            dgvCourses.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name = "Grade",
                HeaderText = "Grade",
                DataPropertyName = "Grade",
                Width = 80
            });

            dgvCourses.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name = "CreditHours",
                HeaderText = "Credit Hours",
                DataPropertyName = "CreditHours",
                Width = 100
            });

            dgvCourses.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name = "GradePoints",
                HeaderText = "Grade Points",
                DataPropertyName = "GradePoints",
                Width = 100
            });

            dgvCourses.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name = "QualityPoints",
                HeaderText = "Quality Points",
                DataPropertyName = "QualityPoints",
                Width = 120
            });
        }

        private void SetupGradeComboBox()
        {
            cbGrade.Items.AddRange(new string[] {
                "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "F"
            });
            cbGrade.SelectedIndex = 0;
        }

        private void BtnAddCourse_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(txtCourseName.Text))
            {
                MessageBox.Show("Please enter a course name.", "Validation Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            if (cbGrade.SelectedItem == null)
            {
                MessageBox.Show("Please select a grade.", "Validation Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            Course newCourse = new Course
            {
                CourseName = txtCourseName.Text.Trim(),
                Grade = cbGrade.SelectedItem.ToString(),
                CreditHours = (double)nudCreditHours.Value
            };

            courses.Add(newCourse);
            RefreshDataGridView();
            UpdateGPADisplay();
            ClearInputs();
        }

        private void BtnRemoveCourse_Click(object sender, EventArgs e)
        {
            if (dgvCourses.SelectedRows.Count > 0)
            {
                int selectedIndex = dgvCourses.SelectedRows[0].Index;
                if (selectedIndex >= 0 && selectedIndex < courses.Count)
                {
                    courses.RemoveAt(selectedIndex);
                    RefreshDataGridView();
                    UpdateGPADisplay();
                }
            }
            else
            {
                MessageBox.Show("Please select a course to remove.", "Selection Required", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void BtnClearAll_Click(object sender, EventArgs e)
        {
            if (courses.Count > 0)
            {
                DialogResult result = MessageBox.Show("Are you sure you want to clear all courses?", "Confirm Clear", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (result == DialogResult.Yes)
                {
                    courses.Clear();
                    RefreshDataGridView();
                    UpdateGPADisplay();
                }
            }
        }

        private void RefreshDataGridView()
        {
            dgvCourses.DataSource = null;
            dgvCourses.DataSource = courses.ToList();
        }

        private void UpdateGPADisplay()
        {
            double totalCredits = courses.Sum(c => c.CreditHours);
            double totalQualityPoints = courses.Sum(c => c.QualityPoints);
            double gpa = totalCredits > 0 ? totalQualityPoints / totalCredits : 0;

            lblCurrentGPA.Text = $"Current GPA: {gpa:F2}";
            lblTotalCredits.Text = $"Total Credits: {totalCredits:F1}";
            lblTotalPoints.Text = $"Total Points: {totalQualityPoints:F2}";

            // Color code GPA
            if (gpa >= 3.5)
                lblCurrentGPA.ForeColor = Color.Green;
            else if (gpa >= 2.0)
                lblCurrentGPA.ForeColor = Color.Orange;
            else
                lblCurrentGPA.ForeColor = Color.Red;
        }

        private void ClearInputs()
        {
            txtCourseName.Clear();
            cbGrade.SelectedIndex = 0;
            nudCreditHours.Value = 3M;
            txtCourseName.Focus();
        }
    }

    public class Course
    {
        public string CourseName { get; set; }
        public string Grade { get; set; }
        public double CreditHours { get; set; }

        public double GradePoints
        {
            get
            {
                return Grade switch
                {
                    "A+" => 4.0,
                    "A" => 4.0,
                    "A-" => 3.7,
                    "B+" => 3.3,
                    "B" => 3.0,
                    "B-" => 2.7,
                    "C+" => 2.3,
                    "C" => 2.0,
                    "C-" => 1.7,
                    "D+" => 1.3,
                    "D" => 1.0,
                    "D-" => 0.7,
                    "F" => 0.0,
                    _ => 0.0
                };
            }
        }

        public double QualityPoints
        {
            get { return GradePoints * CreditHours; }
        }
    }

    // Program entry point
    public static class Program
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