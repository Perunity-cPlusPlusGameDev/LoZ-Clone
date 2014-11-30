#pragma once
#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>
#include "gui.h"
#include "resourceManager.h"

class gameMenu
{
public:
	void LoadMenu(const std::string& fileName, sf::Texture mainMenuTexture, sf::RenderWindow &window, int x, int y);
	void Settings();
	void ProcessEvents();
	bool GetSettingStatus();
private:
	sf::Music music;
	sf::Sprite mainMenu;
	sf::RenderWindow windowSetting;
	Gui gui;
	bool isSettingOpen = false;
	ResourceManager rm;
};
#endif