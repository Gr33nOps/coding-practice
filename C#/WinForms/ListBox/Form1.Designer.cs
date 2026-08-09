namespace Lab18_ListBoxOperations
{
    partial class Form1
    {
        private System.ComponentModel.IContainer components = null;
        private System.Windows.Forms.TextBox textBoxName;
        private System.Windows.Forms.Button buttonAdd;
        private System.Windows.Forms.Button buttonDelete;
        private System.Windows.Forms.ListBox listBoxNames;
        private System.Windows.Forms.Label labelTitle;
        private System.Windows.Forms.Label labelInstruction;
        private System.Windows.Forms.Panel panelHeader;
        private System.Windows.Forms.Panel panelCard;

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
            this.labelTitle = new System.Windows.Forms.Label();
            this.panelCard = new System.Windows.Forms.Panel();
            this.buttonDelete = new System.Windows.Forms.Button();
            this.listBoxNames = new System.Windows.Forms.ListBox();
            this.buttonAdd = new System.Windows.Forms.Button();
            this.textBoxName = new System.Windows.Forms.TextBox();
            this.labelInstruction = new System.Windows.Forms.Label();
            this.panelHeader.SuspendLayout();
            this.panelCard.SuspendLayout();
            this.SuspendLayout();

            // panelHeader
            this.panelHeader.BackColor = System.Drawing.Color.FromArgb(240, 248, 255);
            this.panelHeader.Controls.Add(this.labelTitle);
            this.panelHeader.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelHeader.Location = new System.Drawing.Point(0, 0);
            this.panelHeader.Name = "panelHeader";
            this.panelHeader.Size = new System.Drawing.Size(420, 60);
            this.panelHeader.TabIndex = 0;

            // labelTitle
            this.labelTitle.AutoSize = true;
            this.labelTitle.Font = new System.Drawing.Font("Arial", 16F, System.Drawing.FontStyle.Bold);
            this.labelTitle.ForeColor = System.Drawing.Color.FromArgb(25, 25, 112);
            this.labelTitle.Location = new System.Drawing.Point(100, 15);
            this.labelTitle.Name = "labelTitle";
            this.labelTitle.Size = new System.Drawing.Size(220, 26);
            this.labelTitle.TabIndex = 0;
            this.labelTitle.Text = "Name List Manager";

            // panelCard
            this.panelCard.BackColor = System.Drawing.Color.White;
            this.panelCard.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panelCard.Controls.Add(this.buttonDelete);
            this.panelCard.Controls.Add(this.listBoxNames);
            this.panelCard.Controls.Add(this.buttonAdd);
            this.panelCard.Controls.Add(this.textBoxName);
            this.panelCard.Controls.Add(this.labelInstruction);
            this.panelCard.Location = new System.Drawing.Point(20, 80);
            this.panelCard.Name = "panelCard";
            this.panelCard.Size = new System.Drawing.Size(380, 340);
            this.panelCard.TabIndex = 1;

            // labelInstruction
            this.labelInstruction.AutoSize = true;
            this.labelInstruction.Font = new System.Drawing.Font("Arial", 10F);
            this.labelInstruction.Location = new System.Drawing.Point(20, 20);
            this.labelInstruction.Name = "labelInstruction";
            this.labelInstruction.Size = new System.Drawing.Size(190, 16);
            this.labelInstruction.TabIndex = 0;
            this.labelInstruction.Text = "Enter a name and click Add:";
            this.labelInstruction.ForeColor = System.Drawing.Color.FromArgb(25, 25, 112);

            // textBoxName
            this.textBoxName.Font = new System.Drawing.Font("Arial", 10F);
            this.textBoxName.Location = new System.Drawing.Point(20, 50);
            this.textBoxName.Name = "textBoxName";
            this.textBoxName.Size = new System.Drawing.Size(250, 23);
            this.textBoxName.TabIndex = 1;
            this.textBoxName.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textBoxName.BackColor = System.Drawing.Color.FromArgb(245, 245, 245);
            this.textBoxName.ForeColor = System.Drawing.Color.FromArgb(25, 25, 112);

            // buttonAdd
            this.buttonAdd.BackColor = System.Drawing.Color.FromArgb(152, 251, 152);
            this.buttonAdd.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonAdd.FlatAppearance.BorderSize = 0;
            this.buttonAdd.Font = new System.Drawing.Font("Arial", 10F, System.Drawing.FontStyle.Bold);
            this.buttonAdd.ForeColor = System.Drawing.Color.FromArgb(25, 25, 112);
            this.buttonAdd.Location = new System.Drawing.Point(280, 50);
            this.buttonAdd.Name = "buttonAdd";
            this.buttonAdd.Size = new System.Drawing.Size(80, 30);
            this.buttonAdd.TabIndex = 2;
            this.buttonAdd.Text = "Add";
            this.buttonAdd.UseVisualStyleBackColor = false;
            this.buttonAdd.Click += new System.EventHandler(this.buttonAdd_Click);

            // listBoxNames
            this.listBoxNames.BackColor = System.Drawing.Color.FromArgb(245, 245, 245);
            this.listBoxNames.ForeColor = System.Drawing.Color.FromArgb(25, 25, 112);
            this.listBoxNames.Font = new System.Drawing.Font("Arial", 10F);
            this.listBoxNames.FormattingEnabled = true;
            this.listBoxNames.Location = new System.Drawing.Point(20, 90);
            this.listBoxNames.Name = "listBoxNames";
            this.listBoxNames.Size = new System.Drawing.Size(340, 186);
            this.listBoxNames.TabIndex = 3;

            // buttonDelete
            this.buttonDelete.BackColor = System.Drawing.Color.FromArgb(255, 192, 203);
            this.buttonDelete.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonDelete.FlatAppearance.BorderSize = 0;
            this.buttonDelete.Font = new System.Drawing.Font("Arial", 10F, System.Drawing.FontStyle.Bold);
            this.buttonDelete.ForeColor = System.Drawing.Color.FromArgb(25, 25, 112);
            this.buttonDelete.Location = new System.Drawing.Point(280, 290);
            this.buttonDelete.Name = "buttonDelete";
            this.buttonDelete.Size = new System.Drawing.Size(80, 30);
            this.buttonDelete.TabIndex = 4;
            this.buttonDelete.Text = "Delete";
            this.buttonDelete.UseVisualStyleBackColor = false;
            this.buttonDelete.Click += new System.EventHandler(this.buttonDelete_Click);

            // Form settings
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(255, 255, 255);
            this.ClientSize = new System.Drawing.Size(420, 430);
            this.Controls.Add(this.panelCard);
            this.Controls.Add(this.panelHeader);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "ListBox Name Manager";
            this.panelHeader.ResumeLayout(false);
            this.panelHeader.PerformLayout();
            this.panelCard.ResumeLayout(false);
            this.panelCard.PerformLayout();
            this.ResumeLayout(false);
        }
    }
}