#pragma once
#include <SFML/Audio.hpp>

class Efekt_Body
{
public:
	virtual void Efekt(std::vector < sf::Int16 > &sound, int &leveldistortion, int &sleep, int &frequency) = 0;

	virtual ~Efekt_Body() = default;
};

