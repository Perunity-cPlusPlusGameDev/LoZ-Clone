#include "resourceManager.h"

sf::Texture ResourceManager::LoadTexture(std::string fileName)
{
	if(!texture.loadFromFile("Textures/"+fileName+".png"))
	{
		std::cout << "Texture "+fileName+" cannot be found!" << std::endl;
	}
	return texture;
}
