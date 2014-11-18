#include "gui.h"
void Gui::Init(std::string name)
{
	if(!gameFont.loadFromFile("Fonts/"+name+".ttf")){
		std::cout << "Font " << name <<" cannot be found!\n";
	}
}
void Gui::MakeTextbox(std::string btnName, sf::RenderWindow &window, int x, int y, size_t textSize, sf::Color color, bool withBox)
{
	sf::Vector2f fontPosition(x, y);
	sf::Text gameText(btnName, gameFont, textSize);
	gameText.setColor(color);
	sf::FloatRect textRect = gameText.getLocalBounds();
	gameText.setOrigin(textRect.width / 2, textRect.height / 2);
	gameText.setPosition(fontPosition);


	if(withBox)
	{
		textbox.setSize(sf::Vector2f(textRect.width+5, textRect.height+5));
		textbox.setFillColor(sf::Color(0,0,0,50));
		//textbox.setOutlineColor(sf::Color(0, 0, 0));
		//textbox.setOutlineThickness(0.5);
		textbox.setOrigin(textRect.width / 2, textRect.height / 2);
		textbox.setPosition(fontPosition);
		window.draw(textbox);
	}

	window.draw(gameText);
}