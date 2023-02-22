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
	void ShootBullet();

	void ChangeDirection(Vector2 newDirection);
	void Move() override;

	bool CheckCollision(BaseEntity* entity) override;

	void Draw() override;
	void Erase() override;
	int GetScore();

	Bullet* GetBullets(int index);
	Vector2 GetBody();
	Vector2 GetPosition();
};