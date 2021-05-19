#include "CleanerX.h"

/////////////////////////////
//       BIO_CLEANER       //
/////////////////////////////

BioCleaner::BioCleaner(int x, int y) : Cleaner(x, y)
{
	cProf = _Bio;
}

sVec BioCleaner::getPosition()
{
	return { dPosX, dPosY };
}

char BioCleaner::getProf()
{
	return cProf;
}

void BioCleaner::move(sVec v, std::vector<Cleaner *> & cl)
{
	Cleaner::move(v, cl);
}

bool BioCleaner::collision(sVec v, std::vector<Cleaner *> & cl)
{
	for (auto & c : cl)
	{
		if (sVec(dPosX, dPosY) + v == c->getPosition())
			return true;
	}
	return false;
}

bool BioCleaner::getTrash(std::vector<Field *> & tr)
{
	if (tr[dPosX + dPosY * 30] != nullptr && tr[dPosX + dPosY * 30]->getType() == cProf)
	{
		delete tr[dPosX + dPosY * 30];
		tr[dPosX + dPosY * 30] = nullptr;

		lBackpack.push_back(new Bio);

		switch (rand() % 2)
		{
		case 0:
			//tr[dPosX + dPosY * 30] = new Plum;
			break;
		default:
			break;
		}
		std::cout << "zebranko, mam teraz: " << lBackpack.size() << " w eq\n";
		return true;
	}
	return false;
}

bool BioCleaner::throwTrash(std::vector<Field *> & tr)
{
	int r = 0;
	std::cout << "kolizja\n";

	while (!lBackpack.empty())
	{
		int ylb = (dPosY - r > 0 ? dPosY - r : dPosY);
		int yhb = (dPosY + r < 30 ? dPosY + r : dPosY);

		for (int y = ylb; y < yhb; y++)
		{
			int xlb = (dPosX - r > 0 ? dPosX - r : dPosX);
			int xhb = (dPosX + r < 30 ? dPosX + r : dPosX);

			for (int x = xlb; x < xhb; x++)
			{
				if ((y - dPosY) * (y - dPosY) + (x - dPosX) * (x - dPosX) <= r * r && tr[x + y * 30] == nullptr)
				{
					if (lBackpack.empty()) 
						return false;
					lBackpack.pop_back();
					tr[x + y * 30] = new Bio;
				}
			}
		}
		r++;
	}
	return false;
}

/////////////////////////////
//       PLUM_CLEANER      //
/////////////////////////////

PlumCleaner::PlumCleaner(int x, int y) : Cleaner(x, y)
{
	cProf = _Plum;
}

sVec PlumCleaner::getPosition()
{
	return { dPosX, dPosY };
}

char PlumCleaner::getProf()
{
	return cProf;
}

void PlumCleaner::move(sVec v, std::vector<Cleaner *> & cl)
{
	if(cState != _cleaning)
		Cleaner::move(v, cl);
}

bool PlumCleaner::collision(sVec v, std::vector<Cleaner *> & cl)
{
	for (auto & c : cl)
	{
		if (sVec(dPosX, dPosY) + v == c->getPosition())
			return true;
	}
	return false;
}

bool PlumCleaner::getTrash(std::vector<Field *> & tr)
{
	if (tr[dPosX + dPosY * 30] != nullptr && tr[dPosX + dPosY * 30]->getType() == cProf)
	{
		if (tr[dPosX + dPosY * 30]->dDurability > 0)
		{
			tr[dPosX + dPosY * 30]->dDurability--;
			cState = _cleaning;
		}
		else
		{
			delete tr[dPosX + dPosY * 30];
			tr[dPosX + dPosY * 30] = nullptr;
			lBackpack.push_back(new Plum);

			cState = _default;
		}
		std::cout << "zebranko, mam teraz: " << lBackpack.size() << " w eq\n";
		return true;
	}
	return false;
}

bool PlumCleaner::throwTrash(std::vector<Field *> & tr)
{
	int r = 0;

	while (!lBackpack.empty())
	{
		int ylb = (dPosY - r > 0 ? dPosY - r : dPosY);
		int yhb = (dPosY + r < 30 ? dPosY + r : dPosY);

		for (int y = ylb; y < yhb; y++)
		{
			int xlb = (dPosX - r > 0 ? dPosX - r : dPosX);
			int xhb = (dPosX + r < 30 ? dPosX + r : dPosX);

			for (int x = xlb; x < xhb; x++)
			{
				if ((y - dPosY) * (y - dPosY) + (x - dPosX) * (x - dPosX) <= r * r && tr[x + y * 30] == nullptr)
				{
					if (lBackpack.empty())
						return false;
					lBackpack.pop_back();
					tr[x + y * 30] = new Plum;
				}
			}
		}
		r++;
	}
	return true;
}

/////////////////////////////
//     PLASTIC_CLEANER     //
/////////////////////////////

PlasticCleaner::PlasticCleaner(int x, int y) : Cleaner(x, y)
{
	cProf = _Plastic;
}

sVec PlasticCleaner::getPosition()
{
	return { dPosX, dPosY };
}

char PlasticCleaner::getProf()
{
	return cProf;
}

bool PlasticCleaner::collision(sVec v, std::vector<Cleaner *> & cl)
{
	for (auto & c : cl)
	{
		if (sVec(dPosX, dPosY) + v == c->getPosition())
			return true;
	}
	return false;
}


void PlasticCleaner::move(sVec v, std::vector<Cleaner *> & cl)
{
	Cleaner::move(v, cl);
}

bool PlasticCleaner::getTrash(std::vector<Field *> & tr)
{
	if (tr[dPosX + dPosY * 30] != nullptr && tr[dPosX + dPosY * 30]->getType() == cProf)
	{
		delete tr[dPosX + dPosY * 30];
		tr[dPosX + dPosY * 30] = nullptr;

		lBackpack.push_back(new Plastic);
		std::cout << "zebranko, mam teraz: " << lBackpack.size() << " w eq\n";
		return true;
	}
	return false;
}

bool PlasticCleaner::throwTrash(std::vector<Field *> & tr)
{
	int r = 0;
	std::cout << "kolizja\n";

	while (!lBackpack.empty())
	{
		int ylb = (dPosY - r > 0 ? dPosY - r : dPosY);
		int yhb = (dPosY + r < 30 ? dPosY + r : dPosY);

		for (int y = ylb; y < yhb; y++)
		{
			int xlb = (dPosX - r > 0 ? dPosX - r : dPosX);
			int xhb = (dPosX + r < 30 ? dPosX + r : dPosX);

			for (int x = xlb; x < xhb; x++)
			{
				if ((y - dPosY) * (y - dPosY) + (x - dPosX) * (x - dPosX) <= r * r && tr[x + y * 30] == nullptr)
				{
					if (lBackpack.empty())
						return false;
					tr[x + y * 30] = new Plastic;
					lBackpack.pop_back();
				}
			}
		}
		r++;
	}
	return true;
}

/////////////////////////////
//       BAG_CLEANER       //
/////////////////////////////

BagCleaner::BagCleaner(int x, int y) : Cleaner(x, y)
{
	cProf = _Bag;
}

sVec BagCleaner::getPosition()
{
	return { dPosX, dPosY };
}

char BagCleaner::getProf()
{
	return cProf;
}

void BagCleaner::move(sVec v, std::vector<Cleaner *> & cl)
{
	Cleaner::move(v, cl);
}

bool BagCleaner::collision(sVec v, std::vector<Cleaner *> & cl)
{
	for (auto & c : cl)
	{
		if (sVec(dPosX, dPosY) + v == c->getPosition())
			return true;
	}
	return false;
}

bool BagCleaner::getTrash(std::vector<Field *> & tr)
{
	if (tr[dPosX + dPosY * 30] != nullptr && tr[dPosX + dPosY * 30]->getType() == cProf)
	{
		delete tr[dPosX + dPosY * 30];
		tr[dPosX + dPosY * 30] = nullptr;

		lBackpack.push_back(new Bag);
		std::cout << "zebranko, mam teraz: " << lBackpack.size() << " w eq\n";
		return true;
	}
	return false;
}

bool BagCleaner::throwTrash(std::vector<Field *> & tr)
{
	for (int i = 0; i < 5; i++)
		lBackpack.push_back(new Bag);
	int r = 0;
	std::cout << "kolizja\n";

	while (!lBackpack.empty())
	{
		int ylb = (dPosY - r > 0 ? dPosY - r : dPosY);
		int yhb = (dPosY + r < 30 ? dPosY + r : dPosY);

		for (int y = ylb; y < yhb; y++)
		{
			int xlb = (dPosX - r > 0 ? dPosX - r : dPosX);
			int xhb = (dPosX + r < 30 ? dPosX + r : dPosX);

			for (int x = xlb; x < xhb; x++)
			{
				if ((y - dPosY) * (y - dPosY) + (x - dPosX) * (x - dPosX) <= r * r && tr[x + y * 30] == nullptr)
				{
					if (lBackpack.empty())
						return false;
					lBackpack.pop_back();
					tr[x + y * 30] = new Bag;
				}
			}
		}
		r++;
	}
	return true;
}