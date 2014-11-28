#include "resourceManager.h"

sf::Texture ResourceManager::LoadTexture(std::string fileName)
{
	if(!texture.loadFromFile("Textures/"+fileName))
	{
		std::cout << "Texture " << fileName << " cannot be found!" << std::endl;
	}
	return texture;
}
