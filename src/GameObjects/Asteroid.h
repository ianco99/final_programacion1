#pragma once
#include "BaseClasses/BaseEntity.h"

class Asteroid : public BaseEntity
{
private:


public:
	Asteroid(Vector2 body, Vector2 startPosition, Vector2 direction, Vector2 velocity, Color color, int health, int damage);
	~Asteroid();

	bool CheckCollision(BaseEntity* entity) override;

	void Draw() override;
	void Erase() override;
};