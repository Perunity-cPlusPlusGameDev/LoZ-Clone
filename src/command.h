#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "player.h"
class Command {
public:
	void atCommand(Player &player, std::string &str);
	void doCommand(Player &player, std::string cmd);
	void teleport(Player &player);
private:
	std::vector<std::string> cmdVec;
};

