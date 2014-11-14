#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
class gameMenu
{
public:
	void loadMenu(const std::string& fileName, sf::RenderWindow &window, int x, int y);
private:
	sf::Music music;
	sf::Sprite mainMenu;
	sf::Texture mainMenuTexture;
};

