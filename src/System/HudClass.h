#pragma once
#include "GameObjects/Player.h"
#include "AwesomeLibrary.h"

#include "GameObjects/Asteroid.h"

#include "Utilities.h"

class HudClass
{
private:

	Player* player;

public:
	HudClass(Player* player);
	~HudClass();

	void DisplayGameStats();

	void DrawBorder();
};
