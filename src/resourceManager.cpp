#include "resourceManager.h"

sf::Texture ResourceManager::LoadTexture(std::string fileName)
{
	if(!texture.loadFromFile("Textures/"+fileName))
	{
		std::cout << "Texture " << fileName << " cannot be found!" << std::endl;
	}
	return texture;
}
void ResourceManager::PlayMusic(std::string fileName) {
	if (!music.openFromFile(fileName)) {
		std::cout << "Music file cannot be found!\n";
	}
	music.play();
	music.setLoop(true);
	music.setVolume(50);
	std::cout << "Music Loaded\n";
}