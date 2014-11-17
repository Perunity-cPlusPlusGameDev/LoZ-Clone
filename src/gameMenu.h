#pragma once
#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>
#include "gui.h"

class gameMenu
{
public:
	void LoadMenu(const std::string& fileName, sf::RenderWindow &window, int x, int y, Gui gui);
	void Settings();
	void ProcessEvents();
private:
	sf::Music music;
	sf::Sprite mainMenu;
	sf::Texture mainMenuTexture;
	sf::RenderWindow windowSetting;
	void MakeText(std::string btnName, sf::RenderWindow &window, int x, int y);
};
#endif