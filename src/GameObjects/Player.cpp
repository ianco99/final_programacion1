#include "Player.h"
#include "System/RunGame.h"

Player::Player(Vector2 body, Vector2 startPosition, Vector2 direction, Vector2 velocity, Color color, int health, int damage) : BaseEntity(body, startPosition, direction, velocity, color, health, damage)
{
	cout << "Created player object" << endl;
	this->score = 0;
}

Player::~Player()
{
	cout << "Destroyed player object" << endl;
}

void Player::InitBullets()
{
	for (int i = 0; i < 10; i++)
	{
		this->bullets[i] = new Bullet(false, { 1,1 }, this->position, { 0,-1 }, { 0,1 }, Color::WHITE, 1, 1);
		cout << "Created bullet object" << endl;
	}
}

void Player::ShootBullet()
{
	for (int i = 0; i < 10; i++)
	{
		if (!bullets[i]->GetAlive())
		{
			bullets[i]->StartBullet({ position.x + body.x / 2,position.y}, { 0,-1 });
			break;
		}
	}
}

void Player::ChangeDirection(Vector2 newDirection)
{
	this->direction = newDirection;
}

void Player::Move()
{
	this->position.x += this->direction.x;
	this->position.y += this->direction.y;

	for (int i = 0; i < GameConfigs::maxBullets; i++)
	{
		if (bullets[i]->GetAlive())
			bullets[i]->Move();
	}
}

bool Player::CheckCollision(BaseEntity* entity)
{
	if (entity->GetPosition().x == this->position.x)
		if (entity->GetPosition().y == this->position.y)
			return true;
	return false;

}

void Player::Draw()
{
	//Center ship
	goToCoordinates(this->position.x-1, this->position.y);
	cout << "[" << (char)204 << "]" << (char)205 << (char)205 << (char)16;

	//Left wings
	goToCoordinates(this->position.x, this->position.y - 1);
	cout << (char)254 << (char)175;
	goToCoordinates(this->position.x-2, this->position.y - 2);
	cout << (char)205 << (char)205 << (char)187;

	//Right wings
	goToCoordinates(this->position.x, this->position.y + 1);
	cout << (char)254 << (char)175;
	goToCoordinates(this->position.x - 2, this->position.y + 2);
	cout << (char)205 << (char)205 << (char)188;

	for (int i = 0; i < GameConfigs::maxBullets; i++)
	{
		if (bullets[i]->GetAlive())
		{
			bullets[i]->Draw();
		}
	}
}

void Player::Erase()
{
	//Center ship
	goToCoordinates(this->position.x - 1, this->position.y);
	cout << " " << ' ' << " " << ' ' << ' ' << ' ';

	//Left wings
	goToCoordinates(this->position.x, this->position.y - 1);
	cout << ' ' << ' ';
	goToCoordinates(this->position.x - 2, this->position.y - 2);
	cout << ' ' << ' ' << ' ';

	//Right wings
	goToCoordinates(this->position.x, this->position.y + 1);
	cout << ' ' << ' ';
	goToCoordinates(this->position.x - 2, this->position.y + 2);
	cout << ' ' << ' ' << ' ';
}

int Player::GetScore()
{
	return 0;
}

Bullet* Player::GetBullets(int index)
{
	return this->bullets[index];
}

Vector2 Player::GetBody()
{
	return this->body;
}