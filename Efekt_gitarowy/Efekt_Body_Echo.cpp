#include "Efekt_Body_Echo.h"

void Efekt_Body_Echo::Efekt(std::vector < sf::Int16 > &sound, int &leveldistortion, int &sleep, int &frequency)
{
	sf::Int16 *distortion1 = new sf::Int16[sound.size()];


	for (int i = 0; i < sound.size(); i++)
	{
		distortion1[i] = sound[i];
	}

	sf::SoundBuffer buffer;
	buffer.loadFromSamples(distortion1, sound.size(), 2, 44100);
	sf::Sound sound1;
	sound1.setBuffer(buffer);

	sf::Sound sound2;
	sound2.setBuffer(buffer);

	sf::Sound sound3;
	sound3.setBuffer(buffer);

	sf::Sound sound4;
	sound4.setBuffer(buffer);

	sf::Sound sound5;
	sound5.setBuffer(buffer);

	sf::Sound sound6;
	sound6.setBuffer(buffer);

	sf::Sound sound7;
	sound7.setBuffer(buffer);


	sound1.play();
	Sleep(sleep);
	sound2.setVolume(50.f);
	sound2.play();
	Sleep(sleep);
	sound3.setVolume(40.f);
	sound3.play();
	Sleep(sleep);
	sound4.setVolume(30.f);
	sound4.play();
	Sleep(sleep);
	sound5.setVolume(20.f);
	sound5.play();
	Sleep(sleep);
	sound6.setVolume(10.f);
	sound6.play();
	Sleep(sleep);
	sound7.setVolume(5.f);
	sound7.play();
	system("pause");
}
