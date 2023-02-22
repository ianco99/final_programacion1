#include "System/RunGame.h"

int main()
{

	RunGame* runGame = new RunGame;
	
	runGame->Start();
	delete runGame;
	return 0;
}