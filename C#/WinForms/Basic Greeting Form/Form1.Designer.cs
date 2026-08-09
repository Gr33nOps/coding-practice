namespace GreetingApp
{
    partial class MainForm
    {
        private System.ComponentModel.IContainer components = null;
        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.Label lblName;
        private System.Windows.Forms.TextBox txtName;
        private System.Windows.Forms.Button btnGreet;
        private System.Windows.Forms.Label lblGreeting;
        private System.Windows.Forms.Panel panelHeader;
        private System.Windows.Forms.Panel panelInput;

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
            this.panelInput = new System.Windows.Forms.Panel();
            this.lblGreeting = new System.Windows.Forms.Label();
            this.btnGreet = new System.Windows.Forms.Button();
            this.txtName = new System.Windows.Forms.TextBox();
            this.lblName = new System.Windows.Forms.Label();
            this.panelHeader.SuspendLayout();
            this.panelInput.SuspendLayout();
            this.SuspendLayout();

            // panelHeader
            this.panelHeader.BackColor = System.Drawing.Color.FromArgb(240, 248, 255);
            this.panelHeader.Controls.Add(this.lblTitle);
            this.panelHeader.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelHeader.Location = new System.Drawing.Point(0, 0);
            this.panelHeader.Name = "panelHeader";
            this.panelHeader.Size = new System.Drawing.Size(340, 60);
            this.panelHeader.TabIndex = 0;

            // lblTitle
            this.lblTitle.AutoSize = true;
            this.lblTitle.Font = new System.Drawing.Font("Arial", 16F, System.Drawing.FontStyle.Bold);
            this.lblTitle.ForeColor = System.Drawing.Color.FromArgb(25, 25, 112);
            this.lblTitle.Location = new System.Drawing.Point(50, 15);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(200, 26);
            this.lblTitle.TabIndex = 0;
            this.lblTitle.Text = "Greet Me!";

            // panelInput
            this.panelInput.BackColor = System.Drawing.Color.White;
            this.panelInput.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panelInput.Controls.Add(this.lblGreeting);
            this.panelInput.Controls.Add(this.btnGreet);
            this.panelInput.Controls.Add(this.txtName);
            this.panelInput.Controls.Add(this.lblName);
            this.panelInput.Location = new System.Drawing.Point(20, 80);
            this.panelInput.Name = "panelInput";
            this.panelInput.Size = new System.Drawing.Size(300, 220);
            this.panelInput.TabIndex = 1;

            // lblName
            this.lblName.AutoSize = true;
            this.lblName.Font = new System.Drawing.Font("Arial", 10F);
            this.lblName.ForeColor = System.Drawing.Color.FromArgb(25, 25, 112);
            this.lblName.Location = new System.Drawing.Point(20, 20);
            this.lblName.Name = "lblName";
            this.lblName.Size = new System.Drawing.Size(80, 16);
            this.lblName.TabIndex = 0;
            this.lblName.Text = "Your Name:";

            // txtName
            this.txtName.Font = new System.Drawing.Font("Arial", 10F);
            this.txtName.Location = new System.Drawing.Point(20, 45);
            this.txtName.Name = "txtName";
            this.txtName.Size = new System.Drawing.Size(260, 23);
            this.txtName.TabIndex = 1;
            this.txtName.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtName.BackColor = System.Drawing.Color.FromArgb(245, 245, 245);
            this.txtName.ForeColor = System.Drawing.Color.FromArgb(25, 25, 112);

            // btnGreet
            this.btnGreet.BackColor = System.Drawing.Color.FromArgb(152, 251, 152);
            this.btnGreet.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnGreet.FlatAppearance.BorderSize = 0;
            this.btnGreet.Font = new System.Drawing.Font("Arial", 10F, System.Drawing.FontStyle.Bold);
            this.btnGreet.ForeColor = System.Drawing.Color.FromArgb(25, 25, 112);
            this.btnGreet.Location = new System.Drawing.Point(20, 85);
            this.btnGreet.Name = "btnGreet";
            this.btnGreet.Size = new System.Drawing.Size(100, 40);
            this.btnGreet.TabIndex = 2;
            this.btnGreet.Text = "Greet!";
            this.btnGreet.UseVisualStyleBackColor = false;
            this.btnGreet.Click += new System.EventHandler(this.btnGreet_Click);

            // lblGreeting
            this.lblGreeting.AutoSize = true;
            this.lblGreeting.Font = new System.Drawing.Font("Arial", 11F, ((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic)));
            this.lblGreeting.ForeColor = System.Drawing.Color.FromArgb(199, 21, 133);
            this.lblGreeting.Location = new System.Drawing.Point(20, 145);
            this.lblGreeting.Name = "lblGreeting";
            this.lblGreeting.Size = new System.Drawing.Size(0, 18);
            this.lblGreeting.TabIndex = 3;

            // Form settings
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(255, 255, 255);
            this.ClientSize = new System.Drawing.Size(340, 320);
            this.Controls.Add(this.panelInput);
            this.Controls.Add(this.panelHeader);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Greet Me App";
            this.panelHeader.ResumeLayout(false);
            this.panelHeader.PerformLayout();
            this.panelInput.ResumeLayout(false);
            this.panelInput.PerformLayout();
            this.ResumeLayout(false);
        }
    }
}