#include "RunGame.h"

#include "AwesomeLibrary.h"


static auto curT = std::chrono::system_clock::now();
static auto preT = std::chrono::system_clock::now();

static std::chrono::duration<float> dT;
static float _deltaTime;

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
	player = new Player({ 5,5 }, { 4, GameConfigs::screenHeight - GameConfigs::screenHeight / 8 }, { 1,1 }, { 1,1 }, Color::GREEN, 3, 1);
	player->InitBullets();

	/*for (int i = 0; i < GameConfigs::maxAsteroids; i++)
	{*/
	entities.push_back(new Asteroid({ 1,1 }, { GameConfigs::screenWidth / 2, GameConfigs::screenHeight / 8 }, { 0,-1 }, { 1,1 }, Color::GREEN, 3, 1));
	//}

	cout << '\n' << "Press anything to continue" << endl;

	_getch();
	system("CLS");
}

void RunGame::Update()
{
	curT = std::chrono::system_clock::now();
	dT = curT - preT;
	_deltaTime = dT.count();

	if (_deltaTime < 1.0 / 30)
	{
		return;
	}
	preT = curT;

	CheckInput();
	MoveEntities();
	CheckCollisions();
	DrawEntities();
}

void RunGame::CheckInput()
{
	int input = 0;

	if (_kbhit())
		input = _getch();

	switch (input)
	{
	case 87://W
	case 119:

		this->player->Erase();
		this->player->ChangeDirection({ 0,-1 });
		break;

	case 83://S
	case 115:
		this->player->Erase();
		this->player->ChangeDirection({ 0,1 });
		break;
	default:
		this->player->ChangeDirection({ 0,0 });
		break;
	case 69:
		this->player->ChangeDirection({ 0,0 });

		this->player->ShootBullet();
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
		for (int j = 0; j < GameConfigs::maxBullets; j++)
		{
			if (i != j)
			{
				if (entities[i]->CheckCollision(player->GetBullets(j)))
				{
					entities[i]->RecieveDamage(entities[j]->GetDamage());
					entities[j]->RecieveDamage(entities[i]->GetDamage());
				}

			}

		}
	}
}

void RunGame::DrawEntities()
{
	this->player->Draw();

	for (int i = 0; i < entities.size(); i++)
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