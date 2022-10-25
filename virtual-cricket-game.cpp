#include "game.h"
using namespace std;

//g++ virtual-cricket-game.cpp player.cpp team.cpp game.cpp -std=c++17 -o virtual-cricket-game.exe
//virtual-cricket-game.exe
void lighting(){
	system("Color 04");
	Sleep(15);
	system("Color 06");
	Sleep(15);
	system("Color 05");
	Sleep(15);
	system("Color 01");
	Sleep(15);
	system("Color 07");
}

void pressEnter(){
	cout << "\n\t\t\tPress Enter to Continue\n";
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

int main()
{
	Game obj;
	obj.greet();
	lighting();
	Sleep(10);
	obj.instructions();
	pressEnter();
	obj.showPlayers();
	cout << "let\'s select players for team A and team B ....\nHere we go ..." << "\n";
	pressEnter();
	obj.selectPlayers();
	pressEnter();
	obj.displayPlayers();
	cout << "let\'s toss..." << "\n";
	pressEnter();
	obj.toss();
	obj.startFirstInnings();
	obj.startSecondInnings();
	obj.summary();
	return 0;
}

