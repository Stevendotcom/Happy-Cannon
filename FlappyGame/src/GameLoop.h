#pragma once

#include "raylib.h"
#include <iostream>

namespace game
{
	enum class Scene
	{
		Menu,
		Gameplay,
		GameplayMultiplayer,
		HowToPlay,
		Credits,
		Exit,
		None
	};

	extern int screenWidth;
	extern int screenHeight;

	extern const std::string GameName;

	extern Scene currentScene;

	extern bool programLoop;

	extern bool isMultiplayer;

	extern float timer;

	extern float score;

	extern Font defFont;

	void Play();
}