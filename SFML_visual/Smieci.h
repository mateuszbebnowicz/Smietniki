#pragma once
#include "Field.h"

/////////////////////////////
//           BIO           //
/////////////////////////////

class Bio : public Field
{
public:
	Bio();
	char getType();
};


/////////////////////////////
//          PLUM           //
/////////////////////////////

class Plum : public Field
{
public:
	Plum();
	char getType();
};


/////////////////////////////
//         PLASTIC         //
/////////////////////////////

class Plastic : public Field
{
public:
	Plastic();
	char getType();
};


/////////////////////////////
//           BAG           //
/////////////////////////////

class Bag : public Field
{
public:
	Bag();
	char getType();
};