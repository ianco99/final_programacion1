#pragma once
#include "BaseClasses/BaseEntity.h"

#include "Bullet.h"

class Player : public BaseEntity
{
private:
	Bullet* bullets[10];
	int score;

public:
	Player(Vector2 body, Vector2 startPosition, Vector2 direction, Vector2 velocity, Color color, int health, int damage);
	~Player();

	void InitBullets();

	void ChangeDirection(Vector2 newDirection);
	void Move();

	void Draw() override;
	void Erase() override;
	int GetScore();
};