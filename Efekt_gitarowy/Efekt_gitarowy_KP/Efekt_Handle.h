#pragma once
#include <memory>
#include <SFML/Audio.hpp>
#include "Efekt_Body.h"
#include "Efekt_Body_Pitch.h"
#include "Efekt_Body_Distortion.h"
#include "Efekt_Body_Echo.h"
#include "Efekt_Body_Tremole.h"

class Efekt_Handle
{
private:
	using BodyPtr = std::unique_ptr <Efekt_Body>;

	BodyPtr fBodyObj;
public:
	enum class FileType
	{
		Pitch,
		Distortion,
		Echo,
		Tremole,
	};

	Efekt_Handle(FileType type);
	void Efekt(std::vector < sf::Int16 > &sound, int &leveldistortion, int &sleep, int &frequency);

	virtual ~Efekt_Handle() = default;
};

