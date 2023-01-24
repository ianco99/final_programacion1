#include "Asteroid.h"

Asteroid::Asteroid(Vector2 body, Vector2 startPosition, Vector2 direction, Vector2 velocity, Color color, int health, int damage) : BaseEntity(body, startPosition, direction, velocity, color, health, damage)
{
	cout << "Created asteroid object" << endl;
}

Asteroid::~Asteroid()
{
	cout << "Destroyed asteroid object" << endl;
}

void Asteroid::Draw()
{
	goToCoordinates(this->position.x, this->position.y);
	cout << "O";
}

void Asteroid::Erase()
{
	goToCoordinates(this->position.x, this->position.y);
	cout << " ";
}
