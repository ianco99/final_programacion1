#pragma once
#include <vector>
#include <chrono>
#include <time.h>

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
public:
	static const int startingAsteroids = 5;
	static const int maxAsteroids = 20;
	static const int maxBullets = 10;
	static const int screenWidth = 100;
	static const int screenHeight = 26;
};

class RunGame
{

private:
	vector<BaseEntity*> entities;
	Player* player;
	GameStates currentState;
	//Asteroid* asteroids[20];
	//Asteroid* asteroids[GameConfigs::maxAsteroids];


public:
	RunGame();
	~RunGame();

	void Start();
	void Init();
	void SpawnInitialAsteroids();

	void Update();
	void CheckInput();
	void MoveEntities();
	void CheckCollisions();
	void CheckOutOfBounds();
	void DrawEntities();

	void EndGame();
};