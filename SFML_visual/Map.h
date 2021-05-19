#pragma once
#include <vector>

#include "SFML/Graphics.hpp"
#include "CleanerX.h"

class Map
{
public:
	Map(int c, int t, int m);

	void admin(sf::RenderWindow & w);
	void draw();
private:
	int dTrashNum;

	std::vector <Field *> vChart;
	std::vector <Cleaner *> vCleaners;
	//std::vector <Messer *> vMessers;

	bool arrangeTrash(int t);
	bool arrangeCleaners(int c);
	//bool arrangeMessers(int m);
};