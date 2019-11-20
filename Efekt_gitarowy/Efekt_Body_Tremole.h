#pragma once
#include "Efekt_Body.h"

class Efekt_Body_Tremole : public Efekt_Body
{
public:
	virtual void Efekt(std::vector < sf::Int16 > &sound, int &leveldistortion, int &sleep, int &frequency);
};

