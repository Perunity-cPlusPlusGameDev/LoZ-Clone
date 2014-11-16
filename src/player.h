#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Entity.h"
class Player: public Entity
{
public:
	void ProcessInput();
private:
	void CheckCameraBorder(float &x, float &y);

public:

private:
	sf::View view;
};
#endif