#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
	void Run();
private:
	void Update();
	void Render();
	void ProcessEvents();
	void ProcessInput();
	void LoadMap(const std::string& fileName);
	void DrawMap();
	sf::RenderWindow window;
	sf::Vector2i screenDimensions;
	sf::Clock timer;
	sf::Time timePerFrame;
};



