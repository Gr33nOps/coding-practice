using HappyBirthdayApp;
using static System.Net.Mime.MediaTypeNames;

namespace HAPPY_BIRTHDAY;

public partial class App : Application
{
    public App()
    {
        InitializeComponent();
        MainPage = new AppShell();
    }
}