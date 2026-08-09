using System;
using System.Windows.Forms;

namespace StudentGradeCalculator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnCalculate_Click(object sender, EventArgs e)
        {
            try
            {
                string studentName = txtStudentName.Text.Trim();

                if (string.IsNullOrEmpty(studentName))
                {
                    MessageBox.Show("Please enter the student's name!", "Missing Information",
                                  MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    txtStudentName.Focus();
                    return;
                }

                if (string.IsNullOrEmpty(txtMath.Text) || string.IsNullOrEmpty(txtEnglish.Text) ||
                    string.IsNullOrEmpty(txtScience.Text))
                {
                    MessageBox.Show("Please fill in all subject scores!", "Missing Scores",
                                  MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }

                double mathScore = Convert.ToDouble(txtMath.Text);
                double englishScore = Convert.ToDouble(txtEnglish.Text);
                double scienceScore = Convert.ToDouble(txtScience.Text);

                if (mathScore < 0 || mathScore > 100 || englishScore < 0 || englishScore > 100 ||
                    scienceScore < 0 || scienceScore > 100)
                {
                    MessageBox.Show("Please enter scores between 0 and 100!", "Invalid Score",
                                  MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }

                double average = (mathScore + englishScore + scienceScore) / 3;
                string letterGrade = GetLetterGrade(average);

                lblAverage.Text = $"Average: {average:F2}%";
                lblGrade.Text = $"Grade: {letterGrade}";

                string message = $"Great job, {studentName}!\nYour final grade is {letterGrade} with an average of {average:F2}%";

                if (average >= 90)
                    message += "\nExcellent work! Keep it up!";
                else if (average >= 80)
                    message += "\nGood job! You're doing well!";
                else if (average >= 70)
                    message += "\nNot bad! Keep studying!";
                else if (average >= 60)
                    message += "\nYou can do better! Don't give up!";
                else
                    message += "\nDon't worry, everyone learns at their own pace!";

                MessageBox.Show(message, "Grade Results", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Please enter valid numbers for all scores!", "Input Error",
                              MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            txtStudentName.Clear();
            txtMath.Clear();
            txtEnglish.Clear();
            txtScience.Clear();
            lblAverage.Text = "Average:";
            lblGrade.Text = "Grade:";
            txtStudentName.Focus();
        }

        private string GetLetterGrade(double average)
        {
            if (average >= 90)
                return "A";
            else if (average >= 80)
                return "B";
            else if (average >= 70)
                return "C";
            else if (average >= 60)
                return "D";
            else
                return "F";
        }
    }
}