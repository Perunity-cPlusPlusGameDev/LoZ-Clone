#include "command.h"

void Command::atCommand(Player &player, std::string &str) {
	if (str.length()) {
		if (str[0] != '@') {
			std::cout << std::endl << "Invalid command" << std::endl;
		} else {
			std::string buf;
			std::istringstream iss(str);
			
			while (iss >> buf) {
				cmdVec.push_back(buf);
			}
			doCommand(player, cmdVec[0]);
			cmdVec.clear();
		}
		
	}
	str.clear();
}

void Command::doCommand(Player &player, std::string cmd) {
	if (cmd == "@tp") {
		teleport(player);
	}
}
void Command::teleport(Player &player) {
	player.SetPos(atof(cmdVec[1].c_str()), atof(cmdVec[2].c_str()), atoi(cmdVec[3].c_str()));
	std::cout << "\nWarped!\n";
}