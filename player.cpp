#include "player.h"
using namespace std;

Player::Player(){
		ballsPlayed=0; 
		ballsBowled=0;
		runsGiven=0;
		runsScored=0; 
		wicketTaken=0;

}

void Player::setData(long long int id){
	this->id=id;
}

long long int Player::getData(){
	return id;
}