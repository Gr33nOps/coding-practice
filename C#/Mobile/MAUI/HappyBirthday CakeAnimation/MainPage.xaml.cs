using Microsoft.Maui.Controls;
using System;
using System.Drawing;
using System.Security.Cryptography;
using System.Threading.Tasks;

namespace HAPPY_BIRTHDAY;

public partial class MainPage : ContentPage
{
    private bool _isAnimating = false;
    private readonly string[] _celebrationMessages = {
        "🎉 Hooray! Another year of awesome! 🎉",
        "🌟 You're absolutely amazing! 🌟",
        "🎊 Time to party and celebrate YOU! 🎊",
        "🎈 Wishing you joy, laughter, and cake! 🎈",
        "🎁 Hope your day is as special as you are! 🎁"
    };

    public MainPage()
    {
        InitializeComponent();
        StartCakeAnimation();
    }

    private async void StartCakeAnimation()
    {
        while (true)
        {
            await Task.Delay(2000);
            await CakeEmoji.ScaleTo(1.2, 500, Easing.BounceIn);
            await CakeEmoji.ScaleTo(1.0, 500, Easing.BounceOut);
        }
    }

    private void OnNameChanged(object sender, TextChangedEventArgs e)
    {
        if (!string.IsNullOrWhiteSpace(e.NewTextValue))
        {
            PersonalizedMessage.Text = $"Happy Birthday, {e.NewTextValue}! 🎂✨";
            PersonalizedMessage.IsVisible = true;
        }
        else
        {
            PersonalizedMessage.IsVisible = false;
        }
    }

    private async void OnPlaySongClicked(object sender, EventArgs e)
    {
        if (_isAnimating) return;
        _isAnimating = true;

        SongButton.Text = "🎵 Playing...";

        // Animate the title
        var originalColor = MainTitle.TextColor;
        var colors = new[] { Colors.Red, Colors.Blue, Colors.Green, Colors.Orange, Colors.Purple };
        for (int i = 0; i < 10; i++)
        {
            MainTitle.TextColor = colors[i % colors.Length];
            await MainTitle.ScaleTo(1.1, 200);
            await MainTitle.ScaleTo(1.0, 200);
        }

        MainTitle.TextColor = originalColor;
        SongButton.Text = "🎵 Play Song";
        _isAnimating = false;
    }

    private async void OnCelebrateClicked(object sender, EventArgs e)
    {
        if (_isAnimating) return;
        _isAnimating = true;

        // Show celebration message
        var random = new Random();
        var message = _celebrationMessages[random.Next(_celebrationMessages.Length)];
        CelebrationMessage.Text = message;
        CelebrationFrame.IsVisible = true;

        // Animate celebration
        CelebrateButton.Text = "🎊 Celebrating!";

        // Cake animation
        await CakeFrame.ScaleTo(1.1, 300);
        await CakeFrame.RotateTo(5, 200);
        await CakeFrame.RotateTo(-5, 200);
        await CakeFrame.RotateTo(0, 200);
        await CakeFrame.ScaleTo(1.0, 300);

        // Celebration frame animation
        await CelebrationFrame.FadeTo(0, 0);
        await CelebrationFrame.FadeTo(1, 500);
        await CelebrationFrame.ScaleTo(1.05, 200);
        await CelebrationFrame.ScaleTo(1.0, 200);

        CelebrateButton.Text = "🎊 Celebrate";
        _isAnimating = false;

        // Hide celebration message after 5 seconds
        await Task.Delay(5000);
        await CelebrationFrame.FadeTo(0, 500);
        CelebrationFrame.IsVisible = false;
    }
}