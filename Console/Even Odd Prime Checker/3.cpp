#include <iostream>
#include <Windows.h>
using namespace std;

void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

bool isPrime(int num) {
	if (num <= 1) return false;
	for (int i = 2; i * i <= num; ++i) { 
		if (num % i == 0) return false; 
	}
	return true; 
}

int main() {
	int num = 0;
	int limit;

	cout << "Enter the starting number: ";
	cin >> num;

	cout << "Enter the limit (0 for no limit): ";
	cin >> limit;

	do {
		if (num % 2 == 0) {
			setColor(10); 
			cout << num << " is even";
		}
		else {
			setColor(12); 
			cout << num << " is odd";
		}
		if (isPrime(num)) {
			setColor(14); // Yellow for prime
			cout << " and prime";
		}
		cout << endl;
		num++;
		Sleep(100);

		if (limit != 0 && num > limit) {
			break;
		}

	} while (true);

	setColor(7);

	return 0;
}
