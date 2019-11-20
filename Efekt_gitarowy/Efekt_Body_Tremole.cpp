#include "Efekt_Body_Tremole.h"

void Efekt_Body_Tremole::Efekt(std::vector < sf::Int16 > &sound, int &leveldistortion, int &sleep, int &frequency)
{
	const float pi = 3.14159265359;
	float trem;

	for (int i = 0; i < sound.size(); i++)
	{
		sound[i] /= 2;
	}

	for (int i = 0; i < sound.size(); i++)
	{
		trem = 1 + (sin(2 * pi * i * frequency / sound.size()));
		sound[i] *= trem;
	}

	sf::Int16 *distortion1 = new sf::Int16[sound.size()];

	for (int i = 0; i < sound.size(); i++)
	{
		distortion1[i] = sound[i];
	}

	sf::SoundBuffer buffer;
	buffer.loadFromSamples(distortion1, sound.size(), 2, 44100);
	sf::Sound soundbuffer;
	soundbuffer.setBuffer(buffer);
	soundbuffer.play();
	system("pause");
}
