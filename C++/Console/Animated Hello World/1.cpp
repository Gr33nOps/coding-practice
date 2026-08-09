#include <iostream>
#include <windows.h>
using namespace std; 
int main() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	char arr[11] = { 'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
	string current = "";

	for (int i = 0; i <= 11; i++) {
		for (char c = 'a'; c <= arr[i]; c++) {
			Sleep(100);
			cout << current << c << endl;
		}
		current += arr[i];
	}
	return 0;
}