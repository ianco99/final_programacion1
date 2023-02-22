#pragma once
#include <vector>
#include <chrono>
#include <time.h>

#include "GameObjects/Player.h"
#include "GameObjects/Asteroid.h"
#include "HudClass.h"

#include "AwesomeLibrary.h"

enum class GameStates
{
	Playing,
	Win,
	Lost
};

class RunGame
{

private:
	HudClass* hudClass;
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
	void SpawnAsteroid();

	void Update();

	void CheckGameState();
	void CheckInput();
	void MoveEntities();
	void CheckCollisions();
	void CheckOutOfBounds();
	void DrawEntities();

	void EndGame();
};