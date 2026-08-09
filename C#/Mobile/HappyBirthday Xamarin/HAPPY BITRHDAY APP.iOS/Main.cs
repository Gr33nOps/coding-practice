using System;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace HappyBirthdayApp
{
    public partial class App : Application
    {
        public App()
        {
            InitializeComponent();
            MainPage = new MainPage();
        }

        protected override void OnStart()
        {
        }

        protected override void OnSleep()
        {
        }

        protected override void OnResume()
        {
        }
    }

    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class MainPage : ContentPage
    {
        private bool _isAnimating = false;

        public MainPage()
        {
            InitializeComponent();
            StartCelebration();
        }

        private async void StartCelebration()
        {
            await System.Threading.Tasks.Task.Delay(500);

            // Animate the main title
            await birthdayLabel.ScaleTo(1.2, 1000);
            await birthdayLabel.ScaleTo(1.0, 1000);

            // Show the cake
            cakeLabel.IsVisible = true;
            await cakeLabel.FadeTo(1, 1000);

            // Show the message
            messageLabel.IsVisible = true;
            await messageLabel.FadeTo(1, 1000);

            // Start continuous balloon animation
            StartBalloonAnimation();
        }

        private async void StartBalloonAnimation()
        {
            _isAnimating = true;

            while (_isAnimating)
            {
                await balloon1.TranslateTo(0, -20, 1000);
                await balloon1.TranslateTo(0, 0, 1000);
                await balloon2.TranslateTo(0, -15, 800);
                await balloon2.TranslateTo(0, 0, 800);
                await balloon3.TranslateTo(0, -25, 1200);
                await balloon3.TranslateTo(0, 0, 1200);
            }
        }

        private async void OnCelebrationTapped(object sender, EventArgs e)
        {
            var button = sender as Button;

            // Button animation
            await button.ScaleTo(0.9, 100);
            await button.ScaleTo(1.0, 100);

            // Cake animation
            await cakeLabel.RotateTo(360, 1000);
            cakeLabel.Rotation = 0;

            // Show celebration message
            celebrationMessage.Text = "🎉 Hooray! Another year of awesome! 🎉";
            celebrationMessage.IsVisible = true;
            await celebrationMessage.FadeTo(1, 500);

            // Hide after 3 seconds
            await System.Threading.Tasks.Task.Delay(3000);
            await celebrationMessage.FadeTo(0, 500);
            celebrationMessage.IsVisible = false;
        }

        protected override void OnDisappearing()
        {
            _isAnimating = false;
            base.OnDisappearing();
        }
    }
}

// XAML Content for MainPage

<?xml version="1.0" encoding="utf-8" ?>
<ContentPage xmlns="http://xamarin.com/schemas/2014/forms"
             xmlns:x="http://schemas.microsoft.com/winfx/2009/xaml"
             x:Class="HappyBirthdayApp.MainPage"
             BackgroundColor="#FFE5F3">

    <ScrollView>
        <Grid Padding="20">
            <Grid.RowDefinitions>
                <RowDefinition Height="*" />
                <RowDefinition Height="Auto" />
                <RowDefinition Height="Auto" />
                <RowDefinition Height="Auto" />
                <RowDefinition Height="Auto" />
                <RowDefinition Height="*" />
            </Grid.RowDefinitions>

            <!-- Balloons Row -->
            <StackLayout Grid.Row="0" Orientation="Horizontal" 
                        HorizontalOptions="Center" VerticalOptions="End" Margin="0,0,0,20">
                <Label x:Name="balloon1" Text="🎈" FontSize="40" />
                <Label x:Name="balloon2" Text="🎈" FontSize="35" TextColor="Red" />
                <Label x:Name="balloon3" Text="🎈" FontSize="45" TextColor="Blue" />
            </StackLayout>

            <!-- Main Birthday Title -->
            <Label x:Name="birthdayLabel" 
                   Grid.Row="1"
                   Text="🎂 HAPPY BIRTHDAY! 🎂"
                   FontSize="32"
                   FontAttributes="Bold"
                   TextColor="#FF1493"
                   HorizontalOptions="Center"
                   HorizontalTextAlignment="Center"
                   Margin="0,20" />

            <!-- Cake -->
            <Label x:Name="cakeLabel" 
                   Grid.Row="2"
                   Text="🎂🕯️🎂"
                   FontSize="60"
                   HorizontalOptions="Center"
                   Opacity="0"
                   IsVisible="False"
                   Margin="0,20" />

            <!-- Birthday Message -->
            <Label x:Name="messageLabel" 
                   Grid.Row="3"
                   Text="Hope your special day is filled with happiness, laughter, and all your favorite things!"
                   FontSize="18"
                   TextColor="#4B0082"
                   HorizontalOptions="Center"
                   HorizontalTextAlignment="Center"
                   Opacity="0"
                   IsVisible="False"
                   Margin="20,10" />

            <!-- Celebration Button -->
            <Button Grid.Row="4"
                    Text="🎉 CELEBRATE! 🎉"
                    BackgroundColor="#FF69B4"
                    TextColor="White"
                    FontSize="18"
                    FontAttributes="Bold"
                    CornerRadius="25"
                    HeightRequest="50"
                    Margin="40,20"
                    Clicked="OnCelebrationTapped" />

            <!-- Dynamic Celebration Message -->
            <Label x:Name="celebrationMessage" 
                   Grid.Row="5"
                   Text=""
                   FontSize="16"
                   FontAttributes="Bold"
                   TextColor="#FF4500"
                   HorizontalOptions="Center"
                   HorizontalTextAlignment="Center"
                   Opacity="0"
                   IsVisible="False"
                   Margin="20,10" />

        </Grid>
    </ScrollView>

</ContentPage>
