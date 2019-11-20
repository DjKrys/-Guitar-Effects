#include "Engine.h"

Engine::Engine()
{
}

Engine::~Engine()
{
}

Engine & Engine::getEngine()
{
	static Engine engine;
	return engine;
}

void Engine::menu()
{
	sf::RenderWindow app(sf::VideoMode(SCRWIDTH, SCRHEIGHT), "Efekt gitarowy");

	sf::Text Heading, Distortion, Echo;
	sf::Font font;
	font.loadFromFile("images/arial.ttf");
	Heading.setFont(font);
	Heading.setString("Efekty gitarowe");
	Heading.setFillColor(sf::Color(128, 0, 128));
	Heading.setStyle(sf::Text::Bold);
	Heading.setCharacterSize(40);
	sf::FloatRect Head = Heading.getLocalBounds();
	Heading.setOrigin(Head.left + Head.width / 2.0f,
		Head.top + Head.height / 2.0f);
	Heading.setPosition(SCRWIDTH / 2, 50);

	sf::Texture t1;
	t1.loadFromFile("images/tlo.jpg");

	sf::Sprite sTlo(t1);

	sf::SoundBuffer bufferoryginal;
	bufferoryginal.loadFromFile("images/Ten_Songs_One_String.wav");
	sf::Sound soundoryginal;
	soundoryginal.setBuffer(bufferoryginal);

	const sf::Int16* samplesoryginal = bufferoryginal.getSamples();
	std::size_t count = bufferoryginal.getSampleCount();

	std::vector < sf::Int16 > samplesoryginal1;

	for (int i = 0; i < count; i++)
	{
		samplesoryginal1.push_back(samplesoryginal[i]);
	}

	std::string str;
	std::ostringstream itos_points;
	itos_points << leveldistortion;
	str = itos_points.str();

	while (app.isOpen())
	{
		sf::Event e;
		while (app.pollEvent(e))
		{
			if (e.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				app.close();
			}

			if (e.type == sf::Event::MouseMoved)
			{
				Mouse_Position = sf::Mouse::getPosition(app);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				leveldistortion += 500;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				leveldistortion -= 500;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
			{
				sleep += 5;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
			{
				sleep -= 5;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{	
				frequency += 5;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			{
				frequency -= 5;
			}

		}

		std::string distortion, echo, tremole;
		std::ostringstream dist, ech, tre;

		dist << leveldistortion;
		distortion = dist.str();

		ech << sleep;
		echo = ech.str();

		tre << frequency;
		tremole = tre.str();

		app.draw(sTlo);
		app.draw(Heading);

		Button p1(SCRWIDTH / 2, 125, "PLAY", app);
		Button p2(SCRWIDTH / 2, 185, "STOP", app);
		Button p3(SCRWIDTH / 2, 285, "DISTORTION", app);
		Button p4(SCRWIDTH / 2, 345, "TREMOLE", app);
		Button p5(SCRWIDTH / 2, 405, "PITCH", app);
		Button p6(SCRWIDTH / 2, 465, "ECHO", app);
		Button p7(420, 155, "CLEAR", app);

		Button l1(420, 285, distortion + "dB" , app);
		Button l2(420, 465, echo + "ms" , app);
		Button l3(420, 345, tremole + "Hz", app);




		if (Mouse_Position.x >= (SCRWIDTH / 2) - (p1.getRect() / 2) && Mouse_Position.x <= (SCRWIDTH / 2) + (p1.getRect() / 2) && Mouse_Position.y >= 100 && Mouse_Position.y <= 150 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			soundoryginal.play();
			std::cout << "Play" << std::endl;
		}
		else if (Mouse_Position.x >= (SCRWIDTH / 2) - (p2.getRect() / 2) && Mouse_Position.x <= (SCRWIDTH / 2) + (p2.getRect() / 2) && Mouse_Position.y >= 160 && Mouse_Position.y <= 210 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			soundoryginal.stop();
			std::cout << "Stop" << std::endl;
		}
		else if (Mouse_Position.x >= (SCRWIDTH / 2) - (p3.getRect() / 2) && Mouse_Position.x <= (SCRWIDTH / 2) + (p3.getRect() / 2) && Mouse_Position.y >= 260 && Mouse_Position.y <= 310 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Efekt_Handle Distortion(Efekt_Handle::FileType::Distortion);
			Distortion.Efekt(samplesoryginal1, leveldistortion, sleep, frequency);
			std::cout << "Distortion" << std::endl;
		}
		else if (Mouse_Position.x >= (SCRWIDTH / 2) - (p4.getRect() / 2) && Mouse_Position.x <= (SCRWIDTH / 2) + (p4.getRect() / 2) && Mouse_Position.y >= 320 && Mouse_Position.y <= 370 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Efekt_Handle Tremole(Efekt_Handle::FileType::Tremole);
			Tremole.Efekt(samplesoryginal1, leveldistortion, sleep, frequency);
			std::cout << "Tremole" << std::endl;
		}
		else if (Mouse_Position.x >= (SCRWIDTH / 2) - (p5.getRect() / 2) && Mouse_Position.x <= (SCRWIDTH / 2) + (p5.getRect() / 2) && Mouse_Position.y >= 380 && Mouse_Position.y <= 430 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Efekt_Handle Pitch(Efekt_Handle::FileType::Pitch);
			Pitch.Efekt(samplesoryginal1, leveldistortion, sleep, frequency);
			std::cout << "Pitch" << std::endl;
		}
		else if (Mouse_Position.x >= (SCRWIDTH / 2) - (p6.getRect() / 2) && Mouse_Position.x <= (SCRWIDTH / 2) + (p6.getRect() / 2) && Mouse_Position.y >= 440 && Mouse_Position.y <= 490 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Efekt_Handle Echo(Efekt_Handle::FileType::Echo);
			Echo.Efekt(samplesoryginal1, leveldistortion, sleep, frequency);
			std::cout << "Echo" << std::endl;
		}
		else if (Mouse_Position.x >= 420 - (p7.getRect() / 2) && Mouse_Position.x <= 420 + (p7.getRect() / 2) && Mouse_Position.y >= 130 && Mouse_Position.y <= 180 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 0; i < count; i++)
			{
				samplesoryginal1[i] = samplesoryginal[i];
			}
			std::cout << "Clear" << std::endl;
		}
		app.display();
	}
}
