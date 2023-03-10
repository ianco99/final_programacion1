#include "Bullet.h"

Bullet::Bullet(bool alive, Vector2 body, Vector2 startPosition, Vector2 direction, Color color, int health, int damage) : BaseEntity(body, startPosition, direction, color, health, damage)
{
	this->alive = alive;
	cout << "Created bullet object" << endl;
}

Bullet::~Bullet()
{
	cout << "Destroyed bullet object" << endl;
}

void Bullet::StartBullet(Vector2 bulletPos, Vector2 bulletDir)
{
	alive = true;
	position = bulletPos;
	direction = bulletDir;
}

void Bullet::Move()
{

	this->position.x += this->direction.x;
	this->position.y += this->direction.y;
}

bool Bullet::CheckCollision(BaseEntity* entity)
{
	if (entity->GetPosition().x == this->position.x)
	{
		if (entity->GetPosition().y == this->position.y)
		{
			return true;
		}
	}

	return false;

}

void Bullet::Draw()
{
	setForegroundColor(color);
	goToCoordinates(position.x, position.y);
	cout << '>';
	setForegroundColor(Color::WHITE);
}

void Bullet::Erase()
{
	goToCoordinates(position.x, position.y);
	cout << ' ';
	goToCoordinates(position.x - 1, position.y);
	cout << ' ';
}