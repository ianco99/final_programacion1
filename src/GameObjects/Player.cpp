#include "Player.h"

Player::Player(Vector2 body, Vector2 startPosition, Vector2 direction, Vector2 velocity, Color color, int health, int damage) : BaseEntity (body, startPosition, direction,velocity, color, health, damage)
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
		this->bullets[i] = new Bullet({ 1,1 }, this->position, { 0,-1 }, { 0,1 }, Color::WHITE, 1, 1);
		cout << "Created bullet object" << endl;
	}
}

void Player::Draw()
{

}

void Player::Erase()
{

}

int Player::GetScore()
{
	return 0;
}