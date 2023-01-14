#pragma once
#include "AwesomeLibrary.h"
#include "Utilities.h"

class BaseEntity
{
private:
	Vector2 body;

	Vector2 position;
	Vector2 direction;
	int velocity;	//Windows console works with entire pixels, instead of positions with floating point values

	int health;
	int damage;		//Damage dealt to other body on collision

public:
	BaseEntity();
	~BaseEntity();
	void Move();
	void CheckCollision(BaseEntity entity);
	void RecieveDamage(int damage);
	void Draw();

	int GetHealth();
};
