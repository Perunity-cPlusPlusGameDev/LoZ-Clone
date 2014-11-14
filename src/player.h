#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	void Run();
	void DrawPlayer(sf::RenderWindow& window);	
private:
	void Render();
	void Update();
	void LoadPlayer();	
	void ProcessInput();
	void CheckCollision();
	void GetPos();
	void Move();
	sf::Sprite tile;
	sf::Texture tileTexture;
	// sf::RenderWindow window;
};



