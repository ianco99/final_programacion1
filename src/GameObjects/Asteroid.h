#pragma once
#include "BaseClasses/BaseEntity.h"

class Asteroid : BaseEntity
{
private:


public:
	Asteroid();
	~Asteroid();

	void Draw() override;
	void Erase() override;
};