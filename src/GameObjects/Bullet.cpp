#include "Bullet.h"

Bullet::Bullet(Vector2 body, Vector2 startPosition, Vector2 direction, Vector2 velocity, Color color, int health, int damage) : BaseEntity(body, startPosition, direction, velocity, color, health, damage)
{
	cout << "Created player object" << endl;
}

Bullet::~Bullet()
{
	cout << "Destroyed player object" << endl;
}

void Bullet::Draw()
{

}

void Bullet::Erase()
{

}