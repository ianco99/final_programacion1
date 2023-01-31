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
			bullets[i]->StartBullet({ position.x + body.x / 2,position.y}, { 0,1 });
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
}

void Player::Draw()
{
	goToCoordinates(this->position.x, this->position.y);
	cout << "  " << (char)30 << "  ";
	goToCoordinates(this->position.x, this->position.y + 1);
	cout << " " << (char)40 << (char)206 << (char)41 << " ";
	goToCoordinates(this->position.x, this->position.y + 2);
	cout << (char)30 << (char)188 << " " << (char)200 << (char)30;

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
	for (int i = 0; i < body.y; i++)
	{
		goToCoordinates(this->position.x, this->position.y + i);
		for (int j = 0; j < body.x; j++)
		{
			cout << " ";
		}
	}
}

int Player::GetScore()
{
	return 0;
}

Vector2 Player::GetBody()
{
	return this->body;
}

Vector2 Player::GetPosition()
{
	return this->position;
}