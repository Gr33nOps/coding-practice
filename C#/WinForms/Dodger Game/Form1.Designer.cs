namespace Dodger_Game
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            player = new PictureBox();
            gameTimer = new System.Windows.Forms.Timer(components);
            scoreLabel = new Label();
            ((System.ComponentModel.ISupportInitialize)player).BeginInit();
            SuspendLayout();
            // 
            // player
            // 
            player.BackColor = SystemColors.Highlight;
            player.Location = new Point(329, 376);
            player.Name = "player";
            player.Size = new Size(40, 40);
            player.TabIndex = 0;
            player.TabStop = false;
            // 
            // gameTimer
            // 
            gameTimer.Enabled = true;
            gameTimer.Interval = 20;
            // 
            // scoreLabel
            // 
            scoreLabel.AutoSize = true;
            scoreLabel.Font = new Font("Segoe UI", 14F);
            scoreLabel.ImageAlign = ContentAlignment.TopLeft;
            scoreLabel.Location = new Point(31, 51);
            scoreLabel.Name = "scoreLabel";
            scoreLabel.Size = new Size(95, 32);
            scoreLabel.TabIndex = 1;
            scoreLabel.Text = "score: 0";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(scoreLabel);
            Controls.Add(player);
            Name = "Form1";
            Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)player).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private PictureBox player;
        private System.Windows.Forms.Timer gameTimer;
        private Label scoreLabel;
    }
}
