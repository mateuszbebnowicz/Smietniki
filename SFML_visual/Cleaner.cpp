#include "Cleaner.h"
#include <fstream>


Cleaner::Cleaner(int x, int y): dPosX(x), dPosY(y), dBaseX(x), dBaseY(y)
{
	std::ifstream name;
	std::ifstream surname;
	std::string sur;

	name.open("names.txt");
	surname.open("surnames.txt");

	int n = (rand() % 23) + 1;
	int k = (rand() % 23) + 1;

	if (name.good() && surname.good())
	{
		for (int i = 0; i < n; i++)
		{
			std::getline(name, sName);
		}
		for (int i = 0; i < k; i++)
		{
			std::getline(surname, sur);
		}
		sName += " ";
		sName += sur;
		std::cout << sName << std::endl;
	}
}

void Cleaner::move(sVec v, std::vector<Cleaner *> & cl)
{
	if (collision(v, cl))
	{
		cState = _collided;
		return;
	}

	if (dPosX + v.x > -1 && dPosX + v.x < 30)
		dPosX += v.x;

	if (dPosY + v.y > -1 && dPosY + v.y < 30)
		dPosY += v.y;
}

void Cleaner::administrate(sVec v, std::vector<Cleaner *> & cl, std::vector<Field *> & tr)
{
	if (cState == _collided)
	{
		throwTrash(tr);
		cState = _default;
	}
	move(v, cl);
	getTrash(tr);
}