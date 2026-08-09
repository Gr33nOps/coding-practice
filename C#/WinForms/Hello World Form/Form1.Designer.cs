namespace Hello_World_Form
{
    partial class Form1
    {
        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            button1 = new Button();
            label1 = new Label();
            Birth = new DateTimePicker();
            Current = new DateTimePicker();
            button2 = new Button();
            label2 = new Label();
            label3 = new Label();
            lblAge = new Label();
            lblTime = new Label();
            timer1 = new System.Windows.Forms.Timer(components);
            lblDate = new Label();
            lblDay = new Label();
            SuspendLayout();
            // 
            // button1
            // 
            button1.Location = new Point(12, 53);
            button1.Name = "button1";
            button1.Size = new Size(203, 112);
            button1.TabIndex = 1;
            button1.Text = "PRESS ME";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(37, 19);
            label1.Name = "label1";
            label1.Size = new Size(138, 20);
            label1.TabIndex = 2;
            label1.Text = "HELLO WORLD APP";
            // 
            // Birth
            // 
            Birth.Location = new Point(321, 19);
            Birth.Name = "Birth";
            Birth.Size = new Size(228, 27);
            Birth.TabIndex = 3;
            // 
            // Current
            // 
            Current.Location = new Point(321, 83);
            Current.Name = "Current";
            Current.Size = new Size(228, 27);
            Current.TabIndex = 4;
            // 
            // button2
            // 
            button2.Location = new Point(346, 123);
            button2.Name = "button2";
            button2.Size = new Size(106, 42);
            button2.TabIndex = 7;
            button2.Text = "Calculate";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(248, 19);
            label2.Name = "label2";
            label2.Size = new Size(40, 20);
            label2.TabIndex = 8;
            label2.Text = "Birth";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(248, 85);
            label3.Name = "label3";
            label3.Size = new Size(57, 20);
            label3.TabIndex = 9;
            label3.Text = "Current";
            // 
            // lblAge
            // 
            lblAge.AutoSize = true;
            lblAge.Location = new Point(248, 134);
            lblAge.Name = "lblAge";
            lblAge.Size = new Size(62, 20);
            lblAge.TabIndex = 10;
            lblAge.Text = "Age = 0";
            // 
            // lblTime
            // 
            lblTime.AutoSize = true;
            lblTime.Font = new Font("Segoe UI", 28.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            lblTime.Location = new Point(574, 9);
            lblTime.Name = "lblTime";
            lblTime.Size = new Size(119, 62);
            lblTime.TabIndex = 11;
            lblTime.Text = "time";
            // 
            // timer1
            // 
            timer1.Interval = 1000;
            timer1.Tick += timer1_Tick;
            // 
            // lblDate
            // 
            lblDate.AutoSize = true;
            lblDate.Font = new Font("Segoe UI", 16.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            lblDate.Location = new Point(583, 85);
            lblDate.Name = "lblDate";
            lblDate.Size = new Size(71, 38);
            lblDate.TabIndex = 12;
            lblDate.Text = "date";
            // 
            // lblDay
            // 
            lblDay.AutoSize = true;
            lblDay.Font = new Font("Segoe UI", 16.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            lblDay.Location = new Point(583, 134);
            lblDay.Name = "lblDay";
            lblDay.Size = new Size(61, 38);
            lblDay.TabIndex = 13;
            lblDay.Text = "day";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(lblDay);
            Controls.Add(lblDate);
            Controls.Add(lblTime);
            Controls.Add(lblAge);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(button2);
            Controls.Add(Current);
            Controls.Add(Birth);
            Controls.Add(label1);
            Controls.Add(button1);
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load_1;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button button1;
        private Label label1;
        private DateTimePicker Birth;
        private DateTimePicker Current;
        private Button button2;
        private Label label2;
        private Label label3;
        private Label lblAge;
        private Label lblTime;
        private System.Windows.Forms.Timer timer1;
        private System.ComponentModel.IContainer components;
        private Label lblDate;
        private Label lblDay;
    }
}
