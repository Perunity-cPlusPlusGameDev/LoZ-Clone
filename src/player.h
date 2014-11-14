#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	void Run();
	void DrawPlayer(sf::RenderWindow& window);
private:
	static const int TILE_SIZE = 32;
	void Render();
	void Update();
	void LoadPlayer();
	void ProcessInput();
	void CheckCollision();
	void GetPos();
	void Move();
	sf::Sprite tile;
	sf::Texture tileTexture;
};



