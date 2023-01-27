#pragma once
#include "BaseClasses/BaseEntity.h"

class Bullet : public BaseEntity
{
private:


public:
	Bullet(Vector2 body, Vector2 startPosition, Vector2 direction, Vector2 velocity, Color color, int health, int damage);
	~Bullet();
	
	void Draw() override;
	void Erase() override;
};

//Bullet::Bullet()
//{
//}
//
//Bullet::~Bullet()
//{
//}