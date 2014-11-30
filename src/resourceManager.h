#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class ResourceManager
{
public:
	sf::Texture LoadTexture(std::string fileName);
	void PlayMusic(std::string fileName);
private:
	sf::Texture texture;
	sf::Music music;
};