#pragma once
struct Vector2
{
	int x;
	int y;
};

static struct GameConfigs
{
public:
	static const int startingAsteroids = 5;
	static const int maxAsteroids = 20;
	static const int maxBullets = 10;
	static const int screenWidth = 100;
	static const int screenHeight = 28;
};