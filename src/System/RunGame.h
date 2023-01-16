#pragma once
#include "GameObjects/Player.h"
#include "GameObjects/Asteroid.h"

enum GameStates
{
	Playing,
	Win,
	Lost
};

struct GameConfigs
{
	static GameConfigs instance;
	static const int maxAsteroids = 20;
};

class RunGame
{
private:

	Player* player;
	//Asteroid asteroids[GameConfigs.maxAsteroids];


public:
	RunGame();
	~RunGame();

	void Start();
	
	void Update();
	void CheckInput();
	void MoveEntities();
	void CheckCollisions();

};