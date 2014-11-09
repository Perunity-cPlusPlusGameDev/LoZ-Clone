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
	sf::RenderWindow window;
	sf::Vector2i screenDimensions;
	sf::Clock timer;
	sf::Time timePerFrame;
};



