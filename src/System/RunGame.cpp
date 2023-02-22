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
	srand(time(NULL));

	goToCoordinates(10, 10);
	cout << "Press space to start game" << endl;
	goToCoordinates(10, 11);
	cout << "Press 'q' to start game" << endl;

	if (_getch() == ' ')
	{
		currentState = GameStates::Playing;

		Init();

		SpawnAsteroid();
		SpawnAsteroid();
		SpawnAsteroid();
		SpawnAsteroid();
		SpawnAsteroid();

		while (currentState == GameStates::Playing)
		{
			Update();
		}

		this->EndGame();
	}
}

void RunGame::Init()
{
	player = new Player({ 6,4 }, { 4, GameConfigs::screenHeight / 2 }, { 1,1 }, Color::GREEN, 3, 1);
	player->InitBullets();

	hudClass = new HudClass(player);

	SpawnInitialAsteroids();

	cout << '\n' << "Press anything to continue" << endl;

	_getch();
	system("CLS");
	hudClass->DrawBorder();
}

void RunGame::SpawnInitialAsteroids()
{
	for (int i = 0; i < GameConfigs::startingAsteroids; i++)
	{
		entities.push_back(new Asteroid({ 1,1 }, { 0,0 }, { -1,0 }, Color::GREEN, 1, 1));
		entities[i]->SetAlive(false);
	}
}

void RunGame::SpawnAsteroid()
{
	for (int i = 0; i < entities.size(); i++)
	{
		if (!entities[i]->GetAlive())
		{
			int initX = rand() % 5;
			int initY = rand() % (GameConfigs::screenHeight-5) + 5;

			entities[i]->SetPosition(GameConfigs::screenWidth-5 - initX, initY);
			entities[i]->SetAlive(true);
			break;
		}
	}

}

void RunGame::Update()
{
	curT = std::chrono::system_clock::now();
	dT = curT - preT;
	_deltaTime = dT.count();

	CheckCollisions();
	CheckOutOfBounds();

	if (_deltaTime < 1.0 / 24)
	{
		return;
	}
	preT = curT;

	CheckGameState();
	CheckInput();
	MoveEntities();
	DrawEntities();
	hudClass->DisplayGameStats();
}

void RunGame::CheckGameState()
{
	if (player->GetHealth() <= 0)
	{
		currentState = GameStates::Lost;
	}
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
		if (player->GetPosition().y >= 1)
		{
			this->player->Erase();
			this->player->ChangeDirection({ 0,-1 });
		}
		break;

	case 83://S
	case 115:
		if (player->GetPosition().y < GameConfigs::screenHeight-1)
		{
			this->player->Erase();
			this->player->ChangeDirection({ 0,1 });
		}
		break;

	case 69:
	case 101:
		this->player->ChangeDirection({ 0,0 });
		this->player->ShootBullet();

	default:
		this->player->ChangeDirection({ 0,0 });
		break;

		break;
	}
}

void RunGame::MoveEntities()
{
	player->Move();

	for (int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->GetAlive())
			entities[i]->Move();
	}
}

void RunGame::CheckCollisions()
{
	for (int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->GetAlive())
		{
			//player asteroid
			if (player->CheckCollision(entities[i]))
			{
				entities[i]->Erase();
				entities[i]->SetAlive(false);
				SpawnAsteroid();
				player->RecieveDamage(entities[i]->GetDamage());
				goToCoordinates(105, 4);
				cout << "   ";
			}

			//bullet asteroid
			for (int j = 0; j < GameConfigs::maxBullets; j++)
			{
				if (player->GetBullets(j)->GetAlive())
				{
					if (player->GetBullets(j)->CheckCollision(entities[i]))
					{
						entities[i]->Erase();
						entities[i]->SetAlive(false);
						SpawnAsteroid();
						player->GetBullets(j)->Erase();
						player->GetBullets(j)->RecieveDamage(entities[i]->GetDamage());
						player->AddScore(100);
					}
				}
			}
		}
	}
}

void RunGame::CheckOutOfBounds()
{
	for (int i = 0; i < GameConfigs::maxBullets; i++)
	{
		if (player->GetBullets(i)->GetPosition().x >= GameConfigs::screenWidth-5)
		{
			player->GetBullets(i)->Erase();
			player->GetBullets(i)->SetAlive(false);
		}
	}

	for (int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->GetPosition().x < 4)
		{
			entities[i]->Erase();
			entities[i]->SetAlive(false);
			SpawnAsteroid();
		}
	}

	if (player->GetPosition().y < 5)
	{
		player->Erase();
		player->SetPosition(player->GetPosition().x, 5);
	}

	if (player->GetPosition().y >= GameConfigs::screenHeight - 6)
	{
		player->Erase();
		player->SetPosition(player->GetPosition().x, GameConfigs::screenHeight - 6);
	}
}

void RunGame::DrawEntities()
{
	this->player->Draw();

	for (int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->GetAlive())
		{
			this->entities[i]->Erase();
			this->entities[i]->Draw();
		}
	}
}

void RunGame::EndGame()
{
	system("CLS");

	delete this->player;

	delete this->hudClass;

	for (int i = 0; i < entities.size(); i++)
	{
		delete this->entities[i];
	}
}