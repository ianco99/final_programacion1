#pragma once
#include "BaseClasses/BaseEntity.h"

class Bullet : public BaseEntity
{

public:
	Bullet(bool alive, Vector2 body, Vector2 startPosition, Vector2 direction, Vector2 velocity, Color color, int health, int damage);
	~Bullet();
	
	void StartBullet(Vector2 bulletPos, Vector2 bulletDir);

	void Move() override;

	bool CheckCollision(BaseEntity* entity) override;

	void Draw() override;
	void Erase() override;
};