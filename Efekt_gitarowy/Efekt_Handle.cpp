#include "Efekt_Handle.h"

Efekt_Handle::Efekt_Handle(FileType type)
{
	switch (type)
	{
	case FileType::Pitch:
		fBodyObj = std::make_unique <Efekt_Body_Delay>();
		break;

	case FileType::Distortion:
		fBodyObj = std::make_unique <Efekt_Body_Distortion>();
		break;

	case FileType::Echo:
		fBodyObj = std::make_unique <Efekt_Body_Echo>();
		break;

	case FileType::Tremole:
		fBodyObj = std::make_unique <Efekt_Body_Tremole>();
		break;

	default:
		break;
	}
}

void Efekt_Handle::Efekt(std::vector < sf::Int16 > &sound, int &leveldistortion, int &sleep, int &frequency)
{
	return fBodyObj->Efekt(sound, leveldistortion, sleep, frequency);
}
