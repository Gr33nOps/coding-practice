#define _CRT_SECURE_NO_WARNINGS // Suppress the deprecation warnings
#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <ctime>
#include <vector>
#include <map>
#include <cstdlib>
#include <iomanip>
using namespace std;

void SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void ClearScreen() {
    system("cls");
}

void PrintLine(char ch, int length, int color) {
    SetColor(color);
    for (int i = 0; i < length; ++i) {
        cout << ch;
    }
    cout << endl;
    SetColor(7); // Reset to default color
}

void getSystemTime(int& h, int& m, int& s, int& d, int& mo, int& y, string& dayOfWeek) {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);
    h = ltm.tm_hour;
    m = ltm.tm_min;
    s = ltm.tm_sec;
    d = ltm.tm_mday;
    mo = 1 + ltm.tm_mon;
    y = 1900 + ltm.tm_year;

    const char* days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    dayOfWeek = days[ltm.tm_wday];
}

bool isValidDate(int d, int mo, int y) {
    if (y > 9999 || y < 1000)
        return false;
    if (mo < 1 || mo > 12)
        return false;
    if (d < 1 || d > 31)
        return false;
    if (mo == 2) {
        bool isLeap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        return isLeap ? d <= 29 : d <= 28;
    }
    if (mo == 4 || mo == 6 || mo == 9 || mo == 11)
        return d <= 30;
    return true;
}

class Alarm {
public:
    int hour, minute, second;
    bool snoozed;
    Alarm(int h, int m, int s) : hour(h), minute(m), second(s), snoozed(false) {}
};

class DCLOCK {
private:
    int h, m, s, d, mo, y;
    string dayOfWeek;
    vector<Alarm> alarms;
    map<string, int> timeZones;
    vector<string> quotes;
    string currentTheme;
    time_t quoteStartTime; // Track start time of current quote

public:
    DCLOCK() : h(0), m(0), s(0), d(0), mo(0), y(0), currentTheme("Dark"), quoteStartTime(0) {
        timeZones["UTC"] = 0;
        timeZones["EST"] = -300;
        timeZones["CST"] = -360;
        timeZones["MST"] = -420;
        timeZones["PST"] = -480;
        timeZones["IST"] = 330;

        quotes.push_back("Keep going, you're doing great!");
        quotes.push_back("Every moment is a fresh beginning.");
        quotes.push_back("Believe you can and you're halfway there.");
        quotes.push_back("The only limit is your mind.");
        quotes.push_back("Push yourself, because no one else is going to do it for you.");
    }

    void getdata(bool autoSet) {
        if (autoSet) {
            getSystemTime(h, m, s, d, mo, y, dayOfWeek);
        }
        else {
            while (true) {
                cout << "Enter Date (DD/MM/YYYY): ";
                cin >> d >> mo >> y;
                if (isValidDate(d, mo, y)) break;
                cout << "Invalid date. Please try again." << endl;
            }
            cout << "Enter Time (HH:MM:SS): ";
            scanf("%d:%d:%d", &h, &m, &s);
            cout << "Enter Day of the Week: ";
            cin.ignore();
            getline(cin, dayOfWeek);
        }
    }

    void display() {
        while (true) {
            ClearScreen();
            PrintLine('=', 30, 14); // Yellow line
            cout << dayOfWeek << ", " << (d < 10 ? "0" : "") << d << "/" << (mo < 10 ? "0" : "") << mo << "/" << y << " ";
            cout << (h < 10 ? "0" : "") << h << ":"
                << (m < 10 ? "0" : "") << m << ":"
                << (s < 10 ? "0" : "") << s << " ";
            cout << (h < 12 ? "AM" : "PM") << " (" << currentTheme << ")" << endl;
            PrintLine('=', 30, 14); // Yellow line

            cout << getCurrentQuote() << endl;

            for (auto& alarm : alarms) {
                SetColor(12); // Red for alarm
                cout << "Alarm set for: " << (alarm.hour < 10 ? "0" : "") << alarm.hour << ":"
                    << (alarm.minute < 10 ? "0" : "") << alarm.minute << ":"
                    << (alarm.second < 10 ? "0" : "") << alarm.second << endl;
                SetColor(7); // Reset to default color

                if (h == alarm.hour && m == alarm.minute && s == alarm.second && !alarm.snoozed) {
                    SetColor(12); // Red for alarm
                    cout << "ALARM! Press 'S' to snooze." << endl;
                    if (_kbhit() && _getch() == 'S') {
                        snoozeAlarm(alarm);
                    }
                    SetColor(7); // Reset to default color
                }
            }

            SetColor(7); // Reset to default color
            cout << "Press 'M' for Menu" << endl;

            if (_kbhit()) {
                char input = _getch();
                if (input == 'M' || input == 'm') {
                    showMenu();
                }
            }

            Sleep(1000); // Wait for 1 second
            incrementTime();
        }
    }

    string getCurrentQuote() {
        // If no quote has been displayed yet or 10 seconds have passed, select a new quote
        if (quoteStartTime == 0 || difftime(time(0), quoteStartTime) >= 10) {
            srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
            quoteStartTime = time(0); // Update start time of current quote
        }
        return quotes[rand() % quotes.size()];
    }

    void showMenu() {
        ClearScreen();
        char choice;
        while (true) {
            PrintLine('=', 30, 11); // Cyan line
            cout << "Menu:" << endl;
            cout << "1. Set Time Automatically" << endl;
            cout << "2. Enter Custom Time" << endl;
            cout << "3. Start Stopwatch" << endl;
            cout << "4. Set Alarm" << endl;
            cout << "5. View Alarms" << endl;
            cout << "6. Set Time Zone" << endl;
            cout << "7. Change Theme" << endl;
            cout << "8. Exit Program" << endl;
            cout << "9. Return to Clock" << endl; // New option
            PrintLine('=', 30, 11); // Cyan line
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case '1':
                getdata(true);
                return; // Return to the main display
            case '2':
                getdata(false);
                return; // Return to the main display
            case '3':
                startStopwatch();
                break;
            case '4':
                setAlarm();
                break;
            case '5':
                viewAlarms();
                break;
            case '6':
                setTimeZone();
                break;
            case '7':
                changeTheme();
                break;
            case '8':
                exit(0);
            case '9':
                return; // Return to the clock display
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

    void startStopwatch() {
        int hh = 0, mm = 0, ss = 0;
        char input;
        while (true) {
            ClearScreen();
            cout << "Stopwatch: ";
            cout << setfill('0') << setw(2) << hh << ":" << setw(2) << mm << ":" << setw(2) << ss;
            cout << endl << "Press 'S' to start/pause, 'R' to reset, or 'M' to return to menu." << endl;
            if (_kbhit()) {
                input = _getch();
                if (input == 'S' || input == 's') {
                    while (_kbhit()) _getch(); // Clear input buffer
                    while (!_kbhit()) {
                        Sleep(1000);
                        if (++ss == 60) {
                            ss = 0;
                            if (++mm == 60) {
                                mm = 0;
                                ++hh;
                            }
                        }
                        ClearScreen();
                        cout << "Stopwatch: ";
                        cout << setfill('0') << setw(2) << hh << ":" << setw(2) << mm << ":" << setw(2) << ss;
                        cout << endl << "Press 'S' to start/pause, 'R' to reset, or 'M' to return to menu." << endl;
                        if (_kbhit()) {
                            input = _getch();
                            if (input == 'S' || input == 's') {
                                break;
                            }
                            else if (input == 'R' || input == 'r') {
                                hh = mm = ss = 0;
                            }
                            else if (input == 'M' || input == 'm') {
                                return;
                            }
                        }
                    }
                }
                else if (input == 'R' || input == 'r') {
                    hh = mm = ss = 0;
                }
                else if (input == 'M' || input == 'm') {
                    return;
                }
            }
        }
    }

    void setAlarm() {
        ClearScreen();
        int hour, minute, second;
        cout << "Enter Alarm Time (HH:MM:SS): ";
        scanf("%d:%d:%d", &hour, &minute, &second);
        Alarm alarm(hour, minute, second);
        alarms.push_back(alarm);
        cout << "Alarm set successfully!" << endl;
        system("pause");
    }

    void viewAlarms() {
        ClearScreen();
        if (alarms.empty()) {
            cout << "No alarms set." << endl;
        }
        else {
            cout << "List of Alarms:" << endl;
            for (size_t i = 0; i < alarms.size(); ++i) {
                cout << i + 1 << ". ";
                cout << (alarms[i].hour < 10 ? "0" : "") << alarms[i].hour << ":"
                    << (alarms[i].minute < 10 ? "0" : "") << alarms[i].minute << ":"
                    << (alarms[i].second < 10 ? "0" : "") << alarms[i].second;
                if (alarms[i].snoozed) {
                    cout << " (Snoozed)";
                }
                cout << endl;
            }
        }
        system("pause");
    }

    void setTimeZone() {
        ClearScreen();
        string timezone;
        cout << "Available Timezones:" << endl;
        for (auto& tz : timeZones) {
            cout << tz.first << endl;
        }
        cout << "Enter Timezone: ";
        cin >> timezone;
        auto it = timeZones.find(timezone);
        if (it != timeZones.end()) {
            int offset = it->second;
            cout << "Timezone set to " << timezone << " (Offset: " << offset << " mins)" << endl;
        }
        else {
            cout << "Invalid timezone." << endl;
        }
        system("pause");
    }

    void changeTheme() {
        ClearScreen();
        cout << "Available Themes:" << endl;
        cout << "1. Dark" << endl;
        cout << "2. Light" << endl;
        cout << "Enter theme number to select: ";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            currentTheme = "Dark";
            break;
        case 2:
            currentTheme = "Light";
            break;
        default:
            cout << "Invalid theme choice." << endl;
            system("pause");
            return;
        }
    }

    void snoozeAlarm(Alarm& alarm) {
        alarm.snoozed = true;
        cout << "Alarm snoozed for 5 minutes." << endl;
        Sleep(5 * 60 * 1000); // Snooze for 5 minutes (5 * 60 * 1000 milliseconds)
        alarm.snoozed = false;
    }

    void incrementTime() {
        s++;
        if (s == 60) {
            s = 0;
            m++;
        }
        if (m == 60) {
            m = 0;
            h++;
        }
        if (h == 12) {
            h = 0;
        }
        if (h == 0 && m == 0 && s == 0) {
            d++;
        }
        if (!isValidDate(d, mo, y)) {
            d = 1;
            mo++;
        }
        if (mo > 12) {
            mo = 1;
            y++;
        }
    }
};

int main() {
    SetColor(11); // Cyan initial color
    cout << "Welcome to the Digital Clock Program!" << endl;
    SetColor(7); // Reset to default color

    DCLOCK D;
    D.getdata(true); // Set time automatically by default
    D.display();

    return 0;
}
