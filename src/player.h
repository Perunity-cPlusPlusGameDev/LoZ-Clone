#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>


class Player
{
public:
	void Run();
	void SetPos(int posx, int posy, int speed);
	void GetPos(int &posX, int &posY);
	void CheckCollision();
	void DrawPlayer(sf::RenderWindow& window);
private:
	static const int TILE_SIZE = 32;
	void Render();
	void Update();
	void LoadPlayer();
	void ProcessInput();


	void Move();
	sf::Sprite tile;
	sf::Texture tileTexture;
	int x;
	int y;
};



