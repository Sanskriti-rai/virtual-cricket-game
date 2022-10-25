#include "game.h"
using namespace std;


Game::Game(){
	playersPerTeam=4;
	maxBalls=6;
	totalPlayers=11;

	players[0] = "Virat";
	players[1] = "Rohit";
	players[2] = "Dhawan";
	players[3] = "Pant";
	players[4] = "Karthik";
	players[5] = "KLRahul";
	players[6] = "Jadeja";
	players[7] = "Hardik";
	players[8] = "Bumrah";
	players[9] = "BKumar";
	players[10] = "Ishant";

	isFisrtInning=false;
	teamA.teamName = "Team-A";
	teamB.teamName = "Team-B";
}

void Game::greet(){	
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
	cout << "\t\t\t\t\t\t" << "CRIC-IN" << "\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
	cout << "\t\t\t\t\t" << "***********************" << "\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
	cout << "\t\t\t\t\t" << "Welcome to virtual cricket game" << "\n";
	cout << "\t\t\t\t\t\t" << "greetings" << "\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n\n";
}

void Game::instructions(){
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
	cout << "\t\t\tplease read the given instructions carefully ...." << "\n";
	cout << "1.\tCreate two teams namely team A and team B with 4 players in each from a given pool of 11 players." << "\n";
	cout << "2.\tlead the toss and the winner team will have the choice to choose between batting and bolwing." << "\n";
	cout << "3.\teach inning will of 6 balls" << "\n";
	cout << "4.\tthe team with maximum score will win." << "\n";
	cout << "\t\t\t\tBEST OF LUCK :) " << "\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n\n";
}

void Game::showPlayers(){
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
	cout << "\t\t\t\t\t\tPool of players " << "\n";
	cout << "\t\t\t\t\t" << "*******************************" << "\n";
	for(int i=0 ;i<11 ;i++)
	cout << "\t\t\t\t\t\t" << i << " -> " << players[i] << "\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n\n";

}

int Game::getInput(){
	int n;
	cin>>n;
	while(!cin >> n){
		cin.clear();//clear error flags
		cin.ignore(numeric_limits<streamsize>::max(),'\n');//clear input buffer
		cout << "invalid input ..\nplease try again..." << "\n";
	}
	return n;
}

void Game::selectPlayers(){
	cout << "**********************************************************************************************************************" << "\n";
	cout << "\t\t\t\t\tSelction of players for Team A and Team B" << "\n";
	cout << "**********************************************************************************************************************" << "\n";

	for(int i=1; i<5; i++){
	label1:
	cout << "\t\t\tSelect player " << i << " for team A : ";
		int index = getInput();
		if(index>=11||index<0){
			cout << "\t\t\tinvalid input...\n\t\t\tplease try again....\n";
			goto label1;
		}else if(!validation(index)){
			cout << "\t\t\tplayer already selected...\n\t\t\tplease try again..." << "\n";
			goto label1;
		}else{
			Player obj1;
			obj1.setData(index);
			obj1.name = players[index];
			teamA.players.push_back(obj1);	
		}
		label2:
		cout << "\t\t\tSelect player " << i << " for team B : ";
		index = getInput();
		if(index>=11||index<0){
			cout << "\t\t\tinvalid input...\n\t\t\tplease try again....\n";
			goto label2;
		}else if(!validation(index)){
			cout << "\t\t\tplayer already selected...\n\t\t\tplease try again..." << "\n";
			goto label2;
		}else{
			Player obj2;
			obj2.setData(index);
			obj2.name = players[index];
			teamB.players.push_back(obj2);
		}
	}
}

bool Game::validation(int index){
	int size;
	size =teamA.players.size();
	for(int i=0; i<size; i++){
		if(teamA.players[i].getData()==index)
			return false;
	}

	size =teamB.players.size();
	for(int i=0; i<size; i++){
		if(teamB.players[i].getData()==index)
			return false;
	}

	return true;
}


void Game::displayPlayers(){
	int size;

	size = teamA.players.size();
	cout << "\n---------------------------------------------------------------------------------" << "\n";
		cout << "\t\tTeam A Players" << "\t\t|\t\tTeam B Players" << "\n";
	cout << "---------------------------------------------------------------------------------" << "\n";
	for(int i=0; i<size; i++){
		cout << "|\t\t[" << i << "]  " << teamA.players[i].name << "\t\t|\t\t"
		"[" << i << "]  " << teamB.players[i].name << "\t\t|\n";
	}
	cout << "---------------------------------------------------------------------------------" << "\n";

}

	int Game::toss(){
	cout << "\t\t\t\t\t" << "***********************" << "\n";
	cout << "\t\t\t\t\t--------tossing--------" << "\n";
	cout << "\t\t\t\t\t" << "***********************" << "\n";
	Sleep(60);
	srand(time(NULL));
	int n=rand() % 2;
	switch(n){
		case 0:cout << "team A won the toss...\ncongratulation...\n" << "\n";
		choice(teamA);
		break;
		case 1:cout << "team B won the toss...\ncongratulation...\n" << "\n";
		choice(teamB);
		break;
	}
	return 0;
}

void Game::choice(Team winner){
	int c;
	cout << "enter your choice :\n" << "1. BAT\n" << "2. BOWL" << "\n";
	cin >> c;
	switch(c){
		case 1:cout << winner.teamName << " choose to bat first";
		if(winner.teamName.compare("Team-A")==0){
			battingTeam = &teamA;
			bowlingTeam = &teamB;
		}else{
			battingTeam = &teamB;
			bowlingTeam = &teamA;
		}
		break;
		case 2:cout << winner.teamName << " choose to bowl first";
		if(winner.teamName.compare("Team-A")==0){
			battingTeam = &teamB;
			bowlingTeam = &teamA;
		}else{
			battingTeam = &teamA;
			bowlingTeam = &teamB;
		}
		break;
		default: cout << "invalid response...please try again..." << "\n";
		choice(winner);
	}
}

void Game::startFirstInnings(){
	cout << "\n\t\t\t-----------------------------------" << "\n";
	cout << "\t\t\t\tStart First Innings" << "\n";
	cout << "\t\t\t-----------------------------------" << "\n\n";

	isFisrtInning = true;
	initializePlayers();
	playInnings();
}

void Game::initializePlayers(){
	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];
	cout << battingTeam->teamName << " - " << batsman->name << " is batting" << "\n";
	cout << bowlingTeam->teamName << " - " << bowler->name << " is bowlling" << "\n";
		// cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

void Game::playInnings(){
	for(int i=0; i<maxBalls; i++){
		cin.clear();
		fflush(stdin);
		cout << "\npress enter to bowl..." << "\n";
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Bowling...";
		Sleep(10);
		bat();

		if (!validatingInnings())
		{
			break;
		}
	}
}

void Game::bat(){
	srand(time(NULL));
	int runsScored = rand() % 7;

	batsman->runsScored += runsScored;
	battingTeam->totalRuns += runsScored;
	batsman->ballsPlayed += 1;

	bowler->ballsBowled += 1;
	bowlingTeam->totalBallsBowled += 1;
	bowler->runsGiven += runsScored;


	if(runsScored!=0){
		cout << "\n" <<bowler->name << " to " << batsman->name << " " << runsScored << " runs." << "\n";
		displayScoreCard();
	}else{	
		cout << "\n" <<bowler->name << " to " << batsman->name << " OUT!" << "\n"; 

		battingTeam->wicketLosts += 1;
		bowler->wicketTaken += 1;

		int nextPlayer = battingTeam->wicketLosts;
		batsman = &battingTeam->players[nextPlayer];
		displayScoreCard();
	}
}

bool Game::validatingInnings(){
	if(isFisrtInning){
		if(battingTeam->wicketLosts==playersPerTeam || bowlingTeam->totalBallsBowled==maxBalls){
			cout << "\t\t\tFirst Innings Ends " << "\n";
			cout << battingTeam->teamName << " " << battingTeam->totalRuns << " -"
			" " << battingTeam->wicketLosts << " ( " << bowlingTeam->totalBallsBowled << " ) " << "\n";
			cout << bowlingTeam->teamName << " needs " << battingTeam->totalRuns + 1 << " runs to win the match." << "\n";
			return false;
		}
	}else{
		if (battingTeam->wicketLosts==playersPerTeam || bowlingTeam->totalBallsBowled==maxBalls || battingTeam->totalRuns>bowlingTeam->totalRuns)
		{
			cout << "\t\t\tSecond Innings Ends " << "\n";
			cout << battingTeam->teamName << " " << battingTeam->totalRuns << " -"
			" " << battingTeam->wicketLosts << " ( " << bowlingTeam->totalBallsBowled << " ) " << "\n";
			if(battingTeam->totalRuns>bowlingTeam->totalRuns){
				cout << battingTeam->teamName << " Won The Match." << "\n\n\n";
			}else{
				cout << bowlingTeam->teamName << " Won The Match." << "\n\n\n";

			}
			return false;
		}
	}
	return true;
}

void Game::displayScoreCard(){
	cout << "----------------------------------------------------------------------" << "\n";
	cout << "\t" << battingTeam->teamName << " " << battingTeam->totalRuns << " - " << battingTeam->wicketLosts << " "
	"(" << bowler->ballsBowled << ")" << " | " << batsman->name << " " <<  batsman->runsScored << " "
	"("  << batsman->ballsPlayed << ")\t" << bowler->name << " " << bowler->ballsBowled << " - " << bowler->runsGiven << " -"
	" " << bowler->wicketTaken << "\n";
	cout << "----------------------------------------------------------------------" << "\n";

}

void Game::startSecondInnings(){
	cout << "\n\t\t\t-----------------------------------" << "\n";
	cout << "\t\t\t\tStart Second Innings" << "\n";
	cout << "\t\t\t-----------------------------------" << "\n\n";

	isFisrtInning = false;

	Team *temp;
	temp = battingTeam;
	battingTeam = bowlingTeam;
	bowlingTeam = temp;


	initializePlayers();
	playInnings();
}

void Game::summary(){
	cout << "\tTeam-A " << teamA.totalRuns << " - " << teamA.wicketLosts << "\n";
	cout << "--------------------------------" << "\n";
	cout << "--------------------------------" << "\n";
	cout << "|\tPlayers\tBatting\tBowling\t|" << "\n";
	for(int i=0; i<4; i++){
		cout << "|\t" << teamA.players[i].name << "\t" << teamA.players[i].runsScored << "\t" << teamA.players[i].ballsBowled <<"-"
		"" << teamA.players[i].runsGiven << "-" << teamA.players[i].wicketTaken << "\t|" << "\n";
	}
	cout << "--------------------------------" << "\n\n\n";

	cout << "\tTeam-B " << teamB.totalRuns << " - " << teamB.wicketLosts << "\n";
	cout << "--------------------------------" << "\n";
	cout << "--------------------------------" << "\n";
	cout << "|\tPlayers\tBatting\tBowling\t|" << "\n";
	for(int i=0; i<4; i++){
		cout << "|\t" << teamB.players[i].name << "\t" << teamB.players[i].runsScored << "\t" << teamB.players[i].ballsBowled <<"-"
		"" << teamB.players[i].runsGiven << "-" << teamB.players[i].wicketTaken << "\t|" << "\n";
	}
	cout << "--------------------------------" << "\n";

}