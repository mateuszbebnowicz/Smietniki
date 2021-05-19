#pragma once

class Field
{
public:
	virtual char getType() = 0;

	enum eType
	{
		_Bio = 'b',
		_Bag = 'w',
		_Plum = 'g',
		_Plastic = 'y',
	};

	int dDurability = 1;

protected:
	char cType;
};