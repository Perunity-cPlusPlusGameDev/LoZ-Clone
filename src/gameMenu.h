#pragma once
#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>


class gameMenu
{
public:
	void LoadMenu(const std::string& fileName, sf::RenderWindow &window, int x, int y);
private:
	sf::Music music;
	sf::Sprite mainMenu;
	sf::Texture mainMenuTexture;
	sf::Font gameFont;
	sf::Text gameText;
	void MakeText(std::string btnName, sf::RenderWindow &window, int x, int y);
};
#endif