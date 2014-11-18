#pragma once
#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>


class Gui
{
public:
	Gui();
	void MakeText(std::string btnName, sf::RenderWindow &window, int x, int y, size_t textSize);
private:
	sf::Sprite mainMenu;
	sf::Texture mainMenuTexture;
	sf::Font gameFont;
	sf::Text gameText;
};
#endif