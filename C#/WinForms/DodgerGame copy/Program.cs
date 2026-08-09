using System.Windows.Forms;

namespace DodgerGame
{
    public class GameForm : Form
    {
        private int playerScore = 0;
        private Random randomGenerator = new Random();

        private PictureBox playerCharacter;
        private Label scoreDisplay;
        private System.Windows.Forms.Timer gameUpdateTimer;

        private List<PictureBox> fallingEnemies = new List<PictureBox>();
        private int enemySpawnCounter = 0;
        private int enemySpawnInterval = 50;

        public GameForm()
        {
            ConfigureGameWindow();
            CreatePlayerCharacter();
            CreateScoreLabel();
            SetupGameTimer();
            AddKeyboardControls();
        }

        private void ConfigureGameWindow()
        {
            Text = "Dodger Game";
            Size = new Size(800, 600);
            KeyPreview = true;
            BackColor = Color.Black;
            DoubleBuffered = true;
        }

        private void CreatePlayerCharacter()
        {
            playerCharacter = new PictureBox
            {
                Size = new Size(50, 50),
                BackColor = Color.Blue,
                Left = 400,
                Top = 500
            };
            Controls.Add(playerCharacter);
        }

        private void CreateScoreLabel()
        {
            scoreDisplay = new Label
            {
                Text = "Score: 0",
                Location = new Point(10, 10),
                Font = new Font("Arial", 12),
                BackColor= Color.White,
            };
            Controls.Add(scoreDisplay);
        }

        private void SetupGameTimer()
        {
            gameUpdateTimer = new System.Windows.Forms.Timer
            {
                Interval = 20
            };
            gameUpdateTimer.Tick += UpdateGameState;
            gameUpdateTimer.Start();
        }

        private void AddKeyboardControls()
        {
            KeyDown += MovePlayerCharacter;
        }

        private void UpdateGameState(object sender, EventArgs e)
        {
            MoveEnemies();
            CheckForCollisions();
            TrySpawnEnemies();
        }

        private void MovePlayerCharacter(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Left && playerCharacter.Left > 0)
                playerCharacter.Left -= 10;

            if (e.KeyCode == Keys.Right && playerCharacter.Left < this.ClientSize.Width - playerCharacter.Width)
                playerCharacter.Left += 10;
        }

        private void MoveEnemies()
        {
            for (int i = fallingEnemies.Count - 1; i >= 0; i--)
            {
                fallingEnemies[i].Top += 5;

                if (fallingEnemies[i].Top > ClientSize.Height)
                {
                    Controls.Remove(fallingEnemies[i]);
                    fallingEnemies.RemoveAt(i);

                    IncrementScore();
                }
            }
        }

        private void IncrementScore()
        {
            playerScore++;
            scoreDisplay.Text = "Score: " + playerScore;

            if (enemySpawnInterval > 10)
                enemySpawnInterval--;
        }

        private void TrySpawnEnemies()
        {
            enemySpawnCounter++;

            if (enemySpawnCounter >= enemySpawnInterval)
            {
                SpawnEnemy();
                enemySpawnCounter = 0;
            }
        }

        private void SpawnEnemy()
        {
            int[] availableLanes = { 0, 200, 400, 600 };
            int selectedLane = availableLanes[randomGenerator.Next(availableLanes.Length)];

            bool laneIsFree = true;
            foreach (var existingEnemy in fallingEnemies)
            {
                if (existingEnemy.Left == selectedLane)
                {
                    laneIsFree = false;
                    break;
                }
            }

            if (laneIsFree)
            {
                PictureBox newEnemy = new PictureBox
                {
                    Size = new Size(200, 40),
                    BackColor = Color.Red,
                    Left = selectedLane,
                    Top = -40
                };

                fallingEnemies.Add(newEnemy);
                Controls.Add(newEnemy);
            }
        }

        private void CheckForCollisions()
        {
            foreach (var enemy in fallingEnemies)
            {
                if (playerCharacter.Bounds.IntersectsWith(enemy.Bounds))
                {
                    EndGame();
                    return;
                }
            }
        }

        private void EndGame()
        {
            gameUpdateTimer.Stop();
            MessageBox.Show($"Game Over! Your score: {playerScore}", "Dodger Game");
            Close();
        }

        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new GameForm());
        }
    }
}