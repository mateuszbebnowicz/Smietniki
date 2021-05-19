#pragma once

#include <list>
#include <vector>
#include <string>
#include <utility>

#include "Smieci.h"
#include "struktury.h"


class Cleaner
{
public:
	virtual sVec getPosition() = 0;
	virtual char getProf() = 0;

	void administrate(sVec v, std::vector<Cleaner *> & cl, std::vector<Field *> & tr);

protected:
	int dPosX, dPosY;
	int dBaseX, dBaseY;

	std::list<Field *> lBackpack;
	std::string sName;




	enum eProf
	{
		_Bio = 'b',
		_Bag = 'w',
		_Plastic = 'y',
		_Plum = 'g',
	};

	eProf cProf;

	enum eStates
	{
		_default = 'd',
		_full = 'f',
		_cleaning = 'c',
		_collided = 'x',
	};

	eStates cState;

	Cleaner(int x, int y);

	virtual bool collision(sVec v, std::vector<Cleaner *> & cl) = 0;
	virtual void move(sVec v, std::vector<Cleaner *> & cl) = 0;
	virtual bool getTrash(std::vector<Field *> & tr) = 0;
	virtual bool throwTrash(std::vector<Field *> & tr) = 0;
};