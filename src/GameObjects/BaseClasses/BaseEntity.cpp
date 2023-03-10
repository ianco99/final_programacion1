#include "BaseEntity.h"
#include "AwesomeLibrary.h"

BaseEntity::BaseEntity(Vector2 body, Vector2 startPosition, Vector2 direction, Color color, int health, int damage)
{
	alive = false;

	this->body = body;

	this->position = startPosition;
	this->direction = direction;

	this->color = color;

	this->health = health;
	this->damage = damage;
}

BaseEntity::~BaseEntity()
{

}

void BaseEntity::Move()
{
	this->position.x += this->direction.x;
	this->position.y += this->direction.y;
}

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

void BaseEntity::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

Vector2 BaseEntity::GetPosition()
{
	return this->position;
}