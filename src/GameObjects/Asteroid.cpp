#include "Asteroid.h"

Asteroid::Asteroid(Vector2 body, Vector2 startPosition, Vector2 direction, Vector2 velocity, Color color, int health, int damage) : BaseEntity(body, startPosition, direction, velocity, color, health, damage)
{
	cout << "Created player object" << endl;
}

Asteroid::~Asteroid()
{
	cout << "Destroyed player object" << endl;
}

void Asteroid::Draw()
{

}

void Asteroid::Erase()
{

}
