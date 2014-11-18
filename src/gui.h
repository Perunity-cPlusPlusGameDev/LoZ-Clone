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
	void Init(std::string name);
	void MakeTextbox(std::string btnName, sf::RenderWindow &window, int x, int y, size_t textSize, sf::Color color, bool withBox = false);
private:
	sf::Sprite mainMenu;
	sf::Texture mainMenuTexture;
	sf::Font gameFont;
	sf::Text gameText;
	sf::RectangleShape textbox;
};
#endif