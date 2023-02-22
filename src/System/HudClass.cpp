#include "HudClass.h"

HudClass::HudClass(Player* player)
{
	cout << "Created Hud Class object" << endl;
	this->player = player;
}

HudClass::~HudClass()
{
	cout << "Destroyed Hud Class object" << endl;
}

void HudClass::DisplayGameStats()
{
	setForegroundColor(Color::RED);
	goToCoordinates(105, 4);
	for (int i = 0; i < player->GetHealth(); i++)
	{
		cout << (char)3;
	}

	setForegroundColor(Color::WHITE);
	goToCoordinates(105, 6);
	cout << player->GetScore();
	goToCoordinates(105, 8);
	cout << Asteroid::GetAsteroidCount();
}

void HudClass::DrawBorder()
{
	drawFrame(1, 1, GameConfigs::screenWidth, GameConfigs::screenHeight);
}