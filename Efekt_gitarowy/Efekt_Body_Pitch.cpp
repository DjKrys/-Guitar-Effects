#include "Efekt_Body_Pitch.h"

void Efekt_Body_Delay::Efekt(std::vector < sf::Int16 > &sound, int &leveldistortion, int &sleep, int &frequency)
{
	std::vector < sf::Int16 > pitchsample;

	for (int i = 0; i < sound.size(); i+=2)
	{
		pitchsample.push_back(sound[i]);
	}

	for (int i = 0; i < sound.size(); i++)
	{
		sound[i] = 0;
	}

	for (int i = 0; i < pitchsample.size(); i++)
	{
		sound[i] = pitchsample[i];
	}
	
	sf::Int16 *pitchsound = new sf::Int16[sound.size()];

	for (int i = 0; i < sound.size(); i++)
	{
		pitchsound[i] = sound[i];
	}

	sf::SoundBuffer buffer;
	buffer.loadFromSamples(pitchsound, sound.size(), 2, 44100);
	sf::Sound soundbuffer;
	soundbuffer.setBuffer(buffer);
	soundbuffer.play();
	system("pause");
}
