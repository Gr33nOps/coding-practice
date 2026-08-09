/*
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int aCount = 0;
        int bCount = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') {
                aCount++;
            }
        }
        int minDel = aCount;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'b') {
                bCount++;
            }
            else {
                aCount--;
            }
            int currDel = aCount + bCount;
            if (currDel < minDel) {
                minDel = currDel;
            }
        }
        return minDel;
    }
};
int main() {
    string str;
    Solution sol;
    cout << "Enter string: ";
    cin >> str;
    cout << "Minimum delection: " << sol.minimumDeletions(str);
    return 0;
}
*/

#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
int main() {
    string str;
    cout << "Enter: ";
    getline(cin, str);

    int n = str.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }

    cout << "----------------------------------------------------------------------------------------------\n";

    cout << "Sorting your characters alphabetically...";

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    for (int i = 0; i < n; i++) {
        if (str[i] != ' ' && ( str[i] != str [i + 1])) {
            cout << str[i];
            Sleep(200);
        }
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    cout << "\n----------------------------------------------------------------------------------------------\n";

    return 0;
}