#include "HudClass.h"

HudClass::HudClass(Player* player)
{
	this->player = player;
	//gameDimensions = { 20, 100 };
}

HudClass::~HudClass()
{

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
}

void HudClass::DrawBorder()
{
	drawFrame(1, 1, GameConfigs::screenWidth, GameConfigs::screenHeight);
}

//Vector2 HudClass::GetGameDimensions()
//{
//	//return gameDimensions;
//}