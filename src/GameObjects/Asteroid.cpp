#include "Asteroid.h"

Asteroid::Asteroid(Vector2 body, Vector2 startPosition, Vector2 direction, Color color, int health, int damage) : BaseEntity(body, startPosition, direction, color, health, damage)
{
	asteroidCount++;
	cout << "Created asteroid object" << endl;
}

Asteroid::~Asteroid()
{

}

bool Asteroid::CheckCollision(BaseEntity* entity)
{
	if (entity->GetPosition().x == this->position.x)
		if (entity->GetPosition().y == this->position.y)
		{
			return true;
		}

	return false;

}

void Asteroid::Move()
{
	this->position.x += this->direction.x;
	this->position.y += this->direction.y;

	goToCoordinates(this->position.x + 1, this->position.y);
	cout << " ";
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

int Asteroid::GetAsteroidCount()
{
	return asteroidCount;
}