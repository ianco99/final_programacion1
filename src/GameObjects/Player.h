#pragma once
#include "BaseClasses/BaseEntity.h"

#include "Bullet.h"

class Player : BaseEntity
{
private:
	Bullet* bullets[GameConfigs::maxBullets];
	int score;

public:
	Player(Vector2 body, Vector2 startPosition, Vector2 velocity, Color color, int health, int damage);
	~Player();

	void InitBullets();

	void Draw() override;
	void Erase() override;
	int GetScore();
};