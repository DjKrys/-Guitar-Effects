#include "Button.h"

Button::Button()
{
}

Button::Button(int x, int y, std::string name, sf::RenderWindow& app)
{
	_x = x;
	_y = y;
	sf::Font font;
	font.loadFromFile("images/arial.ttf");
	Name.setFont(font);
	Name.setFillColor(sf::Color::Black);
	Name.setStyle(sf::Text::Bold);
	Name.setCharacterSize(32);
	Name.setString(name);
	sf::FloatRect text = Name.getLocalBounds();
	Name.setOrigin(text.left + text.width / 2.0f,
		text.top + text.height / 2.0f);
	Name.setPosition( _x   , _y );

	Rectangle.setSize(sf::Vector2f(Name.getLocalBounds().width + 20.f, 50.f));
	Rectangle.setOutlineThickness(3.f);
	Rectangle.setOutlineColor(sf::Color(0, 0, 0));
	sf::FloatRect Rect = Rectangle.getLocalBounds();
	Rectangle.setOrigin(Rect.left + Rect.width / 2.0f,
		Rect.top + Rect.height / 2.0f);
	Rectangle.setPosition(_x, _y);
	app.draw(Rectangle);
	app.draw(Name);
}

Button::~Button()
{
}

int Button::getRect()
{
	int y = Rectangle.getLocalBounds().width;
	return y;
}



