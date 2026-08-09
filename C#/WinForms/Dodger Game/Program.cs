
namespace Dodger_Game
{
    public partial class Form1 : Form
    {
        int score = 0;
        Random rand = new Random();
        List<PictureBox> enemies = new List<PictureBox>();
        int playerSpeed = 10;


        private void keyDown(object sender, KeyEventArgs e) 
        {
            if(e.KeyCode == Keys.Left && player.Left > 0)
                player.Left -= playerSpeed;
            if (e.KeyCode == Keys.Right && player.Right < this.ClientSize.Width)
                player.Left += playerSpeed;
        }
        private void moveEnemeies() 
        {
            for (int i = enemies.Count - 1; i >= 0; i--) 
            {
                enemies[i].Top += 5;

                if (enemies[i].Top > this.ClientSize.Height) 
                {
                    this.Controls.Remove(enemies[i]);
                    enemies.RemoveAt(i);
                    score++;
                    scoreLabel.Text = $"Score: {score}";
                }
            }
        }
        private void addEnemy() 
        {
            if (rand.Next(0, 20) == 1) 
            {
                PictureBox enemy = new PictureBox
                {
                    Size = new Size(40, 40),
                    BackColor = Color.Red,
                    Left = rand.Next(0, this.ClientSize.Width),
                    Top = -40
                };
                enemies.Add(enemy);
                this.Controls.Add(enemy);
                enemy.BringToFront();
            }
        }
        private void collisionCheck()
        {
            foreach (var enemy in enemies)
            {
                if (player.Bounds.IntersectsWith(enemy.Bounds)) 
                {
                    gameTimer.Stop();
                    MessageBox.Show("$\"Game Over!\\nScore: {score}");
                    Application.Exit();
                }
            }
        }
        private void gameTimer_tick(object sender, EventArgs e) 
        {
            moveEnemeies();
            collisionCheck();
            addEnemy();
        }
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles(); // Enable visual styles for the application
            Application.SetCompatibleTextRenderingDefault(false); // Set the default text rendering
            Application.Run(new Form1()); // Start the form (Form1)
        }
    }
}