#include "BaseEntity.h"
#include "AwesomeLibrary.h"

BaseEntity::BaseEntity(Vector2 body, Vector2 startPosition, Vector2 direction, Vector2 velocity,Color color, int health, int damage)
{
	alive = false;

	this->body = body;

	this->position = startPosition;
	this->direction = direction;
	this->velocity = velocity;

	this->color = color;

	this->health = health;
	this->damage = damage;
}

BaseEntity::~BaseEntity()
{

}

void BaseEntity::Move()
{

}

//void BaseEntity::CheckCollision(BaseEntity entity)
//{
//
//}

void BaseEntity::RecieveDamage(int damage)
{
	this->health -= damage;

	if (health <= 0)
		this->SetAlive(false);
}

int BaseEntity::GetHealth()
{
	return this->health;
}

int BaseEntity::GetDamage()
{
	return this->damage;
}

void BaseEntity::SetAlive(bool value)
{
	alive = value;
}

bool BaseEntity::GetAlive()
{
	return this->alive;
}


Vector2 BaseEntity::GetPosition()
{
	return this->position;
}