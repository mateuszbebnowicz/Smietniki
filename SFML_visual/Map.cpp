#include "Map.h"

Map::Map(int c, int t, int m)
{
	for (int i = 0; i < 900; i++)
	{
		vChart.push_back(nullptr);
	}
	arrangeTrash(t);
	arrangeCleaners(c);
}

bool Map::arrangeTrash(const int t)
{
	int x, y;

	for (int i = 0; i < t; i++)
	{
		pom:
		x = rand() % 30;
		y = rand() % 30;

		if(vChart[x + y * 30] != nullptr)
			goto pom;

		switch (rand() % 4)
		{
		case 0:
			vChart[x + y * 30] = new Bio;
			break;
		case 1:
			vChart[x + y * 30] = new Plum;
			break;
		case 2:
			vChart[x + y * 30] = new Plastic;
			break;
		case 3:
			vChart[x + y * 30] = new Bag;
			break;
		}
	}
	return true;
}

bool Map::arrangeCleaners(int c)
{
	int x, y;

	for (int i = 0; i < c; i++)
	{
	pom:
		x = rand() % 30;
		y = rand() % 30;

		for (int i = 0; i < vCleaners.size(); i++)
		{
			if (vCleaners[i]->getPosition() == sVec(x, y))
			{
				goto pom;
			}
		}

		switch (rand() % 4)
		{
		case 0:
			vCleaners.push_back(new BioCleaner(x, y));
			break;
		case 1:
			vCleaners.push_back(new PlumCleaner(x, y));
			break;
		case 2:
			vCleaners.push_back(new PlasticCleaner(x, y));
			break;
		case 3:
			vCleaners.push_back(new BagCleaner(x, y));
			break;
		}
	}
	return true;
}

void Map::draw()
{
	system("cls");
	for (int y = 0; y < 30; y++)
	{
		for (int x = 0; x < 30; x++)
		{
			if (vChart[x + y * 30] == nullptr)
			{
				std::cout << '.';
			}
			else if(vChart[x+y*30]->getType() == 'b')
			{
				std::cout << 'b';
			}
			else if(vChart[x + y * 30]->getType() == 'g')
			{
				std::cout << 'g';
			}
			else if (vChart[x + y * 30]->getType() == 'w')
			{
				std::cout << 'w';
			}
			else if (vChart[x + y * 30]->getType() == 'y')
			{
				std::cout << 'y';
			}
		}
		std::cout << std::endl;
	}
}

void Map::admin(sf::RenderWindow & w)
{
	w.clear();
	for (auto & cl : vCleaners)
	{
		int x, y;

	jump:

		x = (rand() % 3) - 1;
		y = (rand() % 3) - 1;

		if (x == 0 && y == 0)
			goto jump;
		cl->administrate(sVec(x, y), vCleaners, vChart);
	}

	sf::RectangleShape tile(sf::Vector2f(30, 30));
	tile.setOutlineColor(sf::Color::Black);
	tile.setOutlineThickness(-1);

	for (int y = 0; y < 30; y++)
	{
		for (int x = 0; x < 30; x++)
		{
			if (vChart[x + y * 30] == nullptr)
			{
				tile.setFillColor(sf::Color::White);
				tile.setPosition(sf::Vector2f(x * 30, y * 30));
				w.draw(tile);
			}
			else
			{
				tile.setFillColor(sf::Color::Green);
				tile.setPosition(sf::Vector2f(x * 30, y * 30));
				w.draw(tile);
			}
		}
	}
	for (auto & c : vCleaners)
	{
		tile.setFillColor(sf::Color::Red);
		tile.setPosition(sf::Vector2f(c->getPosition().x * 30, c->getPosition().y * 30));
		w.draw(tile);
	}
	w.display();
}