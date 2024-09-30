#include <iostream>
#include "UI.h"
using namespace std;

int main() {
	string gameTitle = "Game";
	SetConsoleTitleA("Game");
	loadingConsole();
	Sleep(1000);
	system("cls");
	showCursor(true);
	/*cout << "Hello World\n";
	int j;
	cout << "Enter J: ";
	hideInputText(true);
	cin >> j;
	cout<< "\nValue of J is : " << j << endl;*/

	mainMenu(gameTitle);

	system("pause");
	return 0;
}

