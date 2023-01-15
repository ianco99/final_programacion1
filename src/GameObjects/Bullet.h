#pragma once
#include "BaseClasses/BaseEntity.h"

class Bullet : BaseEntity
{
private:


public:
	Bullet();
	~Bullet();

	void Draw() override;
	void Erase() override;
};

//Bullet::Bullet()
//{
//}
//
//Bullet::~Bullet()
//{
//}