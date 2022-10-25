#include <limits>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "team.h"

class Game
{
public:
	int playersPerTeam, maxBalls, totalPlayers;
	std::string players[11];

	Team teamA, teamB;
	Team *battingTeam, *bowlingTeam;
	Player *batsman, *bowler;
	bool isFisrtInning;
	Game();

	void greet();
	void instructions();
	void showPlayers();	
	int getInput();
	void selectPlayers();
	bool validation(int);
	void displayPlayers();
	int toss();
	void choice(Team);
	void startFirstInnings();
	void initializePlayers();
	void playInnings();
	void bat();
	bool validatingInnings();
	void displayScoreCard();
	void startSecondInnings();
	void summary();
};