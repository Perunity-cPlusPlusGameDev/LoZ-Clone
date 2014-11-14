#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	void Run();
	void DrawPlayer();	
private:
	void Render();
	void Update();
	void LoadPlayer();	
	void ProcessInput();
	void CheckCollision();
	void Move();
	void GetPos();
	sf::Sprite tile;
	sf::Texture tileTexture;
	sf::RenderWindow window;
};



