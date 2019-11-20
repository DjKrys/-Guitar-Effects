#include "Efekt_Body_Distortion.h"

void Efekt_Body_Distortion::Efekt(std::vector < sf::Int16 > &sound, int &leveldistortion, int &sleep, int &frequency)
{
	for (int i = 0; i < sound.size() ; i++)
	{
		if (sound[i] > leveldistortion)
		{
			sound[i] = leveldistortion;
		}
		else if (sound[i] < (-1)*leveldistortion)
		{
			sound[i] = (-1)*leveldistortion;
		}
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
