#include "player.h"
#include <vector>

class Team
{
public:
	Team();
	std::string teamName;
	int totalRuns, wicketLosts, totalBallsBowled;
	std::vector <Player> players;
	
};