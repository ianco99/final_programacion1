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

	if (_getch() == ' ')
	{
		currentState = GameStates::Playing;

		Init();

		while (currentState == GameStates::Playing)
		{
			Update();
		}

		//EndGame();
	}
}

void RunGame::Init()
{
	this->player = new Player({ 3,3 }, { GameConfigs::screenWidth / 2, GameConfigs::screenHeight - GameConfigs::screenHeight / 8 }, { 1,1 }, Color::GREEN, 3, 1);

}

void RunGame::Update()
{
	CheckInput();
	MoveEntities();
	CheckCollisions();
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