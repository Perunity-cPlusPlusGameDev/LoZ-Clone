#include "resourceManager.h"

sf::Texture ResourceManager::LoadTexture(std::string fileName)
{
	if(!texture.loadFromFile("Textures/"+fileName+".png"))
	{
		std::cout << "Player texture file cannot be found!" << std::endl;
	}
	return texture;

}
