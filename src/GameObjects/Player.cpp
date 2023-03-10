#include "Player.h"
#include "System/RunGame.h"

Player::Player(Vector2 body, Vector2 startPosition, Vector2 direction, Color color, int health, int damage) : BaseEntity(body, startPosition, direction, color, health, damage)
{
	cout << "Created player object" << endl;
	this->score = 0;
}

Player::~Player()
{
	cout << "Destroyed player object" << endl;

	for (int i = 0; i < GameConfigs::maxBullets; i++)
	{
		delete bullets[i];
	}
}

void Player::InitBullets()
{
	for (int i = 0; i < GameConfigs::maxBullets; i++)
	{
		this->bullets[i] = new Bullet(false, { 3,1 }, this->position, { 0,-1 }, Color::YELLOW, 1, 1);
		bullets[i]->SetAlive(false);
		cout << "Created bullet object" << endl;
	}
}

void Player::ShootBullet()
{
	int counter = 0;
	for (int i = 0; i < GameConfigs::maxBullets; i++)
	{
		if (counter == 2)
			break;

		if (!bullets[i]->GetAlive())
		{
			if (counter == 0)
			{
				bullets[i]->StartBullet({ position.x + body.x / 2,position.y + 1 }, { 1,0 });
				bullets[i]->SetAlive(true);
				counter++;
			}
			else if (counter == 1)
			{
				bullets[i]->StartBullet({ position.x + body.x / 2,position.y + 3 }, { 1,0 });
				bullets[i]->SetAlive(true);
				counter++;
			}
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
	if (entity->GetPosition().x >= this->position.x &&
		entity->GetPosition().x <= this->position.x + this->body.x &&
		entity->GetPosition().y >= this->position.y &&
		entity->GetPosition().y <= this->position.y + this->body.y)
	{
		return true;
	}

	return false;

}

void Player::Draw()
{

	setForegroundColor(color);
	//Left wings
	goToCoordinates(this->position.x, this->position.y);
	cout << (char)205 << (char)205 << (char)187;
	goToCoordinates(this->position.x + 2, this->position.y + 1);
	cout << (char)254 << (char)175;

	//Center ship
	goToCoordinates(this->position.x + 1, this->position.y + 2);
	cout << "[" << (char)204 << "]" << (char)205 << (char)205 << (char)16;

	//Right wings
	goToCoordinates(this->position.x + 2, this->position.y + 3);
	cout << (char)254 << (char)175;
	goToCoordinates(this->position.x, this->position.y + 4);
	cout << (char)205 << (char)205 << (char)188;

	for (int i = 0; i < GameConfigs::maxBullets; i++)
	{
		if (bullets[i]->GetAlive())
		{
			bullets[i]->Erase();
			bullets[i]->Draw();
		}
	}

	setForegroundColor(Color::WHITE);
}

void Player::Erase()
{
	for (int i = 0; i <= body.y; i++)
	{
		goToCoordinates(this->position.x, this->position.y + i);
		for (int j = 0; j <= body.x; j++)
		{
			cout << ' ';
		}
	}

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
	return score;
}

void Player::AddScore(int adder)
{
	score += adder;
}

Bullet* Player::GetBullets(int index)
{
	return this->bullets[index];
}

Vector2 Player::GetBody()
{
	return this->body;
}