#pragma once
#include "GameObjects/Player.h"
#include "GameObjects/Asteroid.h"

#include "AwesomeLibrary.h"

enum class GameStates
{
	Playing,
	Win,
	Lost
};

static struct GameConfigs
{
	static GameConfigs instance;
	static const int maxAsteroids = 20;
	static const int screenWidth = 60;
	static const int screenHeight = 26;
};

class RunGame
{
private:

	GameStates currentState;
	Player* player;
	//Asteroid asteroids[GameConfigs.maxAsteroids];


public:
	RunGame();
	~RunGame();

	void Start();
	void Init();

	void Update();
	void CheckInput();
	void MoveEntities();
	void CheckCollisions();

};