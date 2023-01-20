#include "RunGame.h"

#include "AwesomeLibrary.h"

RunGame::RunGame()
{
	std::cout << "Program started" << std::endl;
}

RunGame::~RunGame()
{
	std::cout << "Program ended" << std::endl;
}

void RunGame::Start()
{
	goToCoordinates(10,10);
	cout << "Press space to start game" << endl;
	goToCoordinates(10, 11);
	cout << "Press 'q' to start game" << endl;
}

void RunGame::Update()
{

}

void RunGame::CheckInput()
{

}

void RunGame::MoveEntities()
{

}

void RunGame::CheckCollisions()
{

}