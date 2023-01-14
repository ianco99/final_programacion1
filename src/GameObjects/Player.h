#pragma once
#include "BaseClasses/BaseEntity.h"

class Player : BaseEntity
{
private:
	//Bullet[10] bullets
	int score;

public:
	Player(Vector2 body, Vector2 startPosition, Vector2 velocity, Color color, int health, int damage);
	~Player();

	int GetScore();
};