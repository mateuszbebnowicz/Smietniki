#pragma once
#include <iostream>

struct sVec
{
	int x, y;

	sVec()
	{
		x = 0;
		y = 0;
	}
	sVec(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	bool operator==(sVec a)
	{
		if (this->x == a.x && this->y == a.y)
			return true;
		return false;
	}
	
	sVec operator+(sVec a)
	{
		return { this->x + a.x, this->y + a.y };
	}
};
