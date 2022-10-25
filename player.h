#include <string>

class Player
{
private:
	long long int id;
public:
	std::string name;
	int runsScored, ballsPlayed, ballsBowled, runsGiven, wicketTaken;

	Player();
	void setData(long long int);
	long long int getData();
	
};