#pragma once
#include "BaseClasses/BaseEntity.h"

#include "Bullet.h"

class Player : public BaseEntity
{
private:
	Bullet* bullets[10];
	int score;

public:
	Player(Vector2 body, Vector2 startPosition, Vector2 direction, Color color, int health, int damage);
	~Player();

	void InitBullets();
	void ShootBullet();

	void ChangeDirection(Vector2 newDirection);
	void Move() override;

	bool CheckCollision(BaseEntity* entity) override;

	void Draw() override;
	void Erase() override;

	int GetScore();
	void AddScore(int adder);

	Bullet* GetBullets(int index);
	Vector2 GetBody();
};