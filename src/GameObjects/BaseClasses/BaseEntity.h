#pragma once
#include "AwesomeLibrary.h"
#include "Utilities.h"

class BaseEntity
{
protected:
	Vector2 body;

	Vector2 position;
	Vector2 direction;
	Vector2 velocity;	//Windows console works with entire pixels, instead of positions with floating point values

	Color color;

	bool alive;

	int health;
	int damage;		//Damage dealt to other body on collision

public:
	BaseEntity(Vector2 body, Vector2 startPosition, Vector2 direction,Vector2 velocity,Color color,int health, int damage);
	~BaseEntity();
	virtual bool CheckCollision(BaseEntity* entity) = 0;
	void RecieveDamage(int damage);
	virtual void Move();
	virtual void Draw() = 0;
	virtual void Erase() = 0;

	int GetHealth();
	int GetDamage();

	void SetAlive(bool value);
	bool GetAlive();
	void SetPosition(int x, int y);
	Vector2 GetPosition();
};
