#include "GameLoop.h"

#include "raylib.h"

#include "Scenes/Credits.h"
#include "Scenes/GamePlay.h"
#include "Scenes/MainMenu.h"

using namespace game::scenes;

namespace game
{
	const std::string GameName = "FlappyBird";

	int screenWidth = 1024;
	int screenHeight = 768;

	Scene currentScene = Scene::Menu;

	auto prevScene = Scene::Menu;

	bool programLoop = true;

	bool isMultiplayer = false;

	static void Init();

	static void Input();
	static void Update();
	static void Draw();

	static void DeInit();

	void Play()
	{
		Init();

		while (!WindowShouldClose() && programLoop)
		{
			Input();
			Update();
			Draw();

			prevScene = currentScene;
		}

		DeInit();
	}

	void Init()
	{
		InitWindow(screenWidth, screenHeight, GameName.c_str());
		SetConfigFlags(FLAG_VSYNC_HINT);
		SetExitKey(KEY_NULL);

		mainmenu::Init();
		gameplay::Init();
		credits::Init();
	}

	void Input()
	{
		switch (currentScene)
		{
		case Scene::Menu:
			mainmenu::Input();
			break;

		case Scene::GameplayMultiplayer:
			__fallthrough
		case Scene::Gameplay:
			gameplay::Input();
			break;

		case Scene::Credits:
			credits::Input();
			break;
		}
	}

	void Update()
	{
		switch (currentScene)
		{
		case Scene::Menu:
			mainmenu::Update();
			break;

		case Scene::GameplayMultiplayer:
			__fallthrough
		case Scene::Gameplay:
			gameplay::Update();
			break;

		case Scene::Credits:
			credits::Update();
			break;

		case Scene::Exit:
			programLoop = false;
			break;
		}
	}

	void Draw()
	{
		BeginDrawing();

		ClearBackground(WHITE);

		switch (currentScene)
		{
		case Scene::Menu:
			mainmenu::Draw();
			break;

		case Scene::GameplayMultiplayer:
			__fallthrough
		case Scene::Gameplay:
			gameplay::Draw();
			break;

		case Scene::Credits:
			credits::Draw();
			break;
		}

		EndDrawing();
	}

	void DeInit()
	{
		mainmenu::DeInit();
		gameplay::DeInit();
		credits::DeInit();

		CloseWindow();
	}
}

