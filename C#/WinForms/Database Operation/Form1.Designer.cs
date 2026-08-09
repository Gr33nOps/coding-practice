namespace StudentManager
{
    partial class StudentForm
    {
        private System.ComponentModel.IContainer components = null;
        private System.Windows.Forms.Panel panelHeader;
        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.GroupBox grpStudentInfo;
        private System.Windows.Forms.Label lblId;
        private System.Windows.Forms.TextBox txtId;
        private System.Windows.Forms.Label lblName;
        private System.Windows.Forms.TextBox txtName;
        private System.Windows.Forms.Label lblAge;
        private System.Windows.Forms.TextBox txtAge;
        private System.Windows.Forms.Label lblGrade;
        private System.Windows.Forms.ComboBox cmbGrade;
        private System.Windows.Forms.Button btnInsert;
        private System.Windows.Forms.Button btnUpdate;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.DataGridView dgvStudents;
        private System.Windows.Forms.Label lblStatus;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        private void InitializeComponent()
        {
            this.panelHeader = new System.Windows.Forms.Panel();
            this.lblTitle = new System.Windows.Forms.Label();
            this.grpStudentInfo = new System.Windows.Forms.GroupBox();
            this.lblId = new System.Windows.Forms.Label();
            this.txtId = new System.Windows.Forms.TextBox();
            this.lblName = new System.Windows.Forms.Label();
            this.txtName = new System.Windows.Forms.TextBox();
            this.lblAge = new System.Windows.Forms.Label();
            this.txtAge = new System.Windows.Forms.TextBox();
            this.lblGrade = new System.Windows.Forms.Label();
            this.cmbGrade = new System.Windows.Forms.ComboBox();
            this.btnInsert = new System.Windows.Forms.Button();
            this.btnUpdate = new System.Windows.Forms.Button();
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.dgvStudents = new System.Windows.Forms.DataGridView();
            this.lblStatus = new System.Windows.Forms.Label();
            this.panelHeader.SuspendLayout();
            this.grpStudentInfo.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvStudents)).BeginInit();
            this.SuspendLayout();

            // panelHeader
            this.panelHeader.BackColor = System.Drawing.Color.FromArgb(33, 33, 33);
            this.panelHeader.Controls.Add(this.lblTitle);
            this.panelHeader.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelHeader.Location = new System.Drawing.Point(0, 0);
            this.panelHeader.Name = "panelHeader";
            this.panelHeader.Size = new System.Drawing.Size(450, 50);
            this.panelHeader.TabIndex = 0;

            // lblTitle
            this.lblTitle.AutoSize = true;
            this.lblTitle.Font = new System.Drawing.Font("Verdana", 14F, System.Drawing.FontStyle.Bold);
            this.lblTitle.ForeColor = System.Drawing.Color.FromArgb(255, 193, 7);
            this.lblTitle.Location = new System.Drawing.Point(110, 15);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(230, 23);
            this.lblTitle.TabIndex = 0;
            this.lblTitle.Text = "Student Dashboard";

            // grpStudentInfo
            this.grpStudentInfo.BackColor = System.Drawing.Color.FromArgb(44, 44, 44);
            this.grpStudentInfo.Controls.Add(this.dgvStudents);
            this.grpStudentInfo.Controls.Add(this.btnClear);
            this.grpStudentInfo.Controls.Add(this.btnDelete);
            this.grpStudentInfo.Controls.Add(this.btnUpdate);
            this.grpStudentInfo.Controls.Add(this.btnInsert);
            this.grpStudentInfo.Controls.Add(this.cmbGrade);
            this.grpStudentInfo.Controls.Add(this.lblGrade);
            this.grpStudentInfo.Controls.Add(this.txtAge);
            this.grpStudentInfo.Controls.Add(this.lblAge);
            this.grpStudentInfo.Controls.Add(this.txtName);
            this.grpStudentInfo.Controls.Add(this.lblName);
            this.grpStudentInfo.Controls.Add(this.txtId);
            this.grpStudentInfo.Controls.Add(this.lblId);
            this.grpStudentInfo.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.grpStudentInfo.Font = new System.Drawing.Font("Verdana", 10F, System.Drawing.FontStyle.Bold);
            this.grpStudentInfo.ForeColor = System.Drawing.Color.FromArgb(255, 193, 7);
            this.grpStudentInfo.Location = new System.Drawing.Point(20, 60);
            this.grpStudentInfo.Name = "grpStudentInfo";
            this.grpStudentInfo.Size = new System.Drawing.Size(410, 460);
            this.grpStudentInfo.TabIndex = 1;
            this.grpStudentInfo.TabStop = false;
            this.grpStudentInfo.Text = "Student Records";

            // lblId
            this.lblId.AutoSize = true;
            this.lblId.Font = new System.Drawing.Font("Verdana", 9F);
            this.lblId.Location = new System.Drawing.Point(15, 25);
            this.lblId.Name = "lblId";
            this.lblId.Size = new System.Drawing.Size(65, 14);
            this.lblId.TabIndex = 0;
            this.lblId.Text = "Student ID:";
            this.lblId.ForeColor = System.Drawing.Color.FromArgb(224, 224, 224);

            // txtId
            this.txtId.Font = new System.Drawing.Font("Verdana", 9F);
            this.txtId.Location = new System.Drawing.Point(100, 22);
            this.txtId.Name = "txtId";
            this.txtId.Size = new System.Drawing.Size(290, 22);
            this.txtId.TabIndex = 1;
            this.txtId.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtId.BackColor = System.Drawing.Color.FromArgb(66, 66, 66);
            this.txtId.ForeColor = System.Drawing.Color.FromArgb(224, 224, 224);

            // lblName
            this.lblName.AutoSize = true;
            this.lblName.Font = new System.Drawing.Font("Verdana", 9F);
            this.lblName.Location = new System.Drawing.Point(15, 55);
            this.lblName.Name = "lblName";
            this.lblName.Size = new System.Drawing.Size(78, 14);
            this.lblName.TabIndex = 2;
            this.lblName.Text = "Student Name:";
            this.lblName.ForeColor = System.Drawing.Color.FromArgb(224, 224, 224);

            // txtName
            this.txtName.Font = new System.Drawing.Font("Verdana", 9F);
            this.txtName.Location = new System.Drawing.Point(100, 52);
            this.txtName.Name = "txtName";
            this.txtName.Size = new System.Drawing.Size(290, 22);
            this.txtName.TabIndex = 3;
            this.txtName.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtName.BackColor = System.Drawing.Color.FromArgb(66, 66, 66);
            this.txtName.ForeColor = System.Drawing.Color.FromArgb(224, 224, 224);

            // lblAge
            this.lblAge.AutoSize = true;
            this.lblAge.Font = new System.Drawing.Font("Verdana", 9F);
            this.lblAge.Location = new System.Drawing.Point(15, 85);
            this.lblAge.Name = "lblAge";
            this.lblAge.Size = new System.Drawing.Size(30, 14);
            this.lblAge.TabIndex = 4;
            this.lblAge.Text = "Age:";
            this.lblAge.ForeColor = System.Drawing.Color.FromArgb(224, 224, 224);

            // txtAge
            this.txtAge.Font = new System.Drawing.Font("Verdana", 9F);
            this.txtAge.Location = new System.Drawing.Point(100, 82);
            this.txtAge.Name = "txtAge";
            this.txtAge.Size = new System.Drawing.Size(290, 22);
            this.txtAge.TabIndex = 5;
            this.txtAge.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtAge.BackColor = System.Drawing.Color.FromArgb(66, 66, 66);
            this.txtAge.ForeColor = System.Drawing.Color.FromArgb(224, 224, 224);

            // lblGrade
            this.lblGrade.AutoSize = true;
            this.lblGrade.Font = new System.Drawing.Font("Verdana", 9F);
            this.lblGrade.Location = new System.Drawing.Point(15, 115);
            this.lblGrade.Name = "lblGrade";
            this.lblGrade.Size = new System.Drawing.Size(42, 14);
            this.lblGrade.TabIndex = 6;
            this.lblGrade.Text = "Grade:";
            this.lblGrade.ForeColor = System.Drawing.Color.FromArgb(224, 224, 224);

            // cmbGrade
            this.cmbGrade.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbGrade.Font = new System.Drawing.Font("Verdana", 9F);
            this.cmbGrade.FormattingEnabled = true;
            this.cmbGrade.Items.AddRange(new object[] { "A", "B", "C", "D", "F" });
            this.cmbGrade.Location = new System.Drawing.Point(100, 112);
            this.cmbGrade.Name = "cmbGrade";
            this.cmbGrade.Size = new System.Drawing.Size(290, 22);
            this.cmbGrade.TabIndex = 7;
            this.cmbGrade.BackColor = System.Drawing.Color.FromArgb(66, 66, 66);
            this.cmbGrade.ForeColor = System.Drawing.Color.FromArgb(224, 224, 224);

            // btnInsert
            this.btnInsert.BackColor = System.Drawing.Color.FromArgb(0, 191, 165);
            this.btnInsert.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnInsert.FlatAppearance.BorderSize = 0;
            this.btnInsert.Font = new System.Drawing.Font("Verdana", 9F, System.Drawing.FontStyle.Bold);
            this.btnInsert.ForeColor = System.Drawing.Color.FromArgb(255, 255, 255);
            this.btnInsert.Location = new System.Drawing.Point(100, 145);
            this.btnInsert.Name = "btnInsert";
            this.btnInsert.Size = new System.Drawing.Size(50, 50);
            this.btnInsert.TabIndex = 8;
            this.btnInsert.Text = "Add";
            this.btnInsert.UseVisualStyleBackColor = false;
            this.btnInsert.Click += new System.EventHandler(this.btnInsert_Click);

            // btnUpdate
            this.btnUpdate.BackColor = System.Drawing.Color.FromArgb(255, 179, 0);
            this.btnUpdate.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnUpdate.FlatAppearance.BorderSize = 0;
            this.btnUpdate.Font = new System.Drawing.Font("Verdana", 9F, System.Drawing.FontStyle.Bold);
            this.btnUpdate.ForeColor = System.Drawing.Color.FromArgb(255, 255, 255);
            this.btnUpdate.Location = new System.Drawing.Point(160, 145);
            this.btnUpdate.Name = "btnUpdate";
            this.btnUpdate.Size = new System.Drawing.Size(50, 50);
            this.btnUpdate.TabIndex = 9;
            this.btnUpdate.Text = "Edit";
            this.btnUpdate.UseVisualStyleBackColor = false;
            this.btnUpdate.Click += new System.EventHandler(this.btnUpdate_Click);

            // btnDelete
            this.btnDelete.BackColor = System.Drawing.Color.FromArgb(239, 83, 80);
            this.btnDelete.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnDelete.FlatAppearance.BorderSize = 0;
            this.btnDelete.Font = new System.Drawing.Font("Verdana", 9F, System.Drawing.FontStyle.Bold);
            this.btnDelete.ForeColor = System.Drawing.Color.FromArgb(255, 255, 255);
            this.btnDelete.Location = new System.Drawing.Point(220, 145);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(50, 50);
            this.btnDelete.TabIndex = 10;
            this.btnDelete.Text = "Del";
            this.btnDelete.UseVisualStyleBackColor = false;
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);

            // btnClear
            this.btnClear.BackColor = System.Drawing.Color.FromArgb(97, 97, 97);
            this.btnClear.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnClear.FlatAppearance.BorderSize = 0;
            this.btnClear.Font = new System.Drawing.Font("Verdana", 9F, System.Drawing.FontStyle.Bold);
            this.btnClear.ForeColor = System.Drawing.Color.FromArgb(255, 255, 255);
            this.btnClear.Location = new System.Drawing.Point(280, 145);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(50, 50);
            this.btnClear.TabIndex = 11;
            this.btnClear.Text = "Clr";
            this.btnClear.UseVisualStyleBackColor = false;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);

            // dgvStudents
            this.dgvStudents.AllowUserToAddRows = false;
            this.dgvStudents.AllowUserToDeleteRows = false;
            this.dgvStudents.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgvStudents.BackgroundColor = System.Drawing.Color.FromArgb(66, 66, 66);
            this.dgvStudents.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvStudents.Location = new System.Drawing.Point(15, 205);
            this.dgvStudents.MultiSelect = false;
            this.dgvStudents.Name = "dgvStudents";
            this.dgvStudents.ReadOnly = true;
            this.dgvStudents.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgvStudents.Size = new System.Drawing.Size(380, 240);
            this.dgvStudents.TabIndex = 12;
            this.dgvStudents.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgvStudents_CellClick);

            // lblStatus
            this.lblStatus.AutoSize = true;
            this.lblStatus.Font = new System.Drawing.Font("Verdana", 9F, System.Drawing.FontStyle.Bold);
            this.lblStatus.Location = new System.Drawing.Point(20, 530);
            this.lblStatus.Name = "lblStatus";
            this.lblStatus.Size = new System.Drawing.Size(0, 14);
            this.lblStatus.TabIndex = 13;
            this.lblStatus.ForeColor = System.Drawing.Color.FromArgb(255, 82, 82);

            // Form settings
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(33, 33, 33);
            this.ClientSize = new System.Drawing.Size(450, 560);
            this.Controls.Add(this.lblStatus);
            this.Controls.Add(this.grpStudentInfo);
            this.Controls.Add(this.panelHeader);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "StudentForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Student Dashboard";
            this.panelHeader.ResumeLayout(false);
            this.panelHeader.PerformLayout();
            this.grpStudentInfo.ResumeLayout(false);
            this.grpStudentInfo.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvStudents)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();
        }
    }
}