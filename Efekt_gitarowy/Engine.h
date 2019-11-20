#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Button.h"
#include <windows.h>
#include "Efekt_Handle.h"
#include <stdio.h>
#include <mmsystem.h>
#include <vector>
#include <cstdio>
#include <time.h>
#include <sstream>


class Engine
{
private:
	Engine();
	Engine(const Engine &);
	~Engine();

	sf::Vector2i Mouse_Position;

	const int SCRWIDTH = 500;
	const int SCRHEIGHT = 514;

public:
	static Engine &getEngine();

	int leveldistortion = 5000;
	int sleep = 150;
	int frequency = 0;
	void menu();
};

