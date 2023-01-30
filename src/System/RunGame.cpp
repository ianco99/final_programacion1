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
	hideCursor();

	goToCoordinates(10, 10);
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

		this->EndGame();
	}
}

void RunGame::Init()
{
	player = new Player({ 5,5 }, { GameConfigs::screenWidth / 2, GameConfigs::screenHeight - GameConfigs::screenHeight / 8 }, { 1,1 }, { 1,1 }, Color::GREEN, 3, 1);
	player->InitBullets();

	for (int i = 0; i < GameConfigs::maxAsteroids; i++)
	{
		entities.push_back(new Asteroid({ 1,1 }, { GameConfigs::screenWidth / 2, GameConfigs::screenHeight / 8 }, { 0,-1 }, { 1,1 }, Color::GREEN, 3, 1));
	}

	cout << '\n' << "Press anything to continue" << endl;

	_getch();
	system("CLS");
}

void RunGame::Update()
{
	CheckInput();
	MoveEntities();
	CheckCollisions();
	DrawEntities();
}

void RunGame::CheckInput()
{
	int input = _getch_nolock();

	switch (input)
	{
	case 87://W
	case 119:
		this->player->Erase();
		this->player->ChangeDirection({ 0,-1 });
		break;

	case 65://A
	case 97:
		this->player->Erase();
		this->player->ChangeDirection({ -1,0 });
		break;
	case 83://S
	case 115:
		this->player->Erase();
		this->player->ChangeDirection({ 0,1 });
		break;
	case 68://D
	case 100:
		this->player->Erase();
		this->player->ChangeDirection({ 1,0 });
		break;
	default:
		this->player->ChangeDirection({ 0,0 });
		break;
	}
}

void RunGame::MoveEntities()
{
	player->Move();
}

void RunGame::CheckCollisions()
{
	for (int i = 0; i < entities.size(); i++)
	{
		//entities[i]->CheckCollision(player);
	}
}

void RunGame::DrawEntities()
{
	this->player->Draw();

	for (int i = 0; i < 20; i++)
	{
		this->entities[i]->Draw();
	}
}

void RunGame::EndGame()
{
	delete this->player;
	for (int i = 0; i < entities.size(); i++)
	{
		delete entities[i];
	}
	entities.clear();
}