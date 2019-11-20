#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Button
{
private:
	int _x, _y;
	std::string name;

	sf::Text Name;
	sf::RectangleShape Rectangle;
public:
	Button();
	Button(int x, int y, std::string name, sf::RenderWindow& app);
	~Button();

	int getRect();
};

