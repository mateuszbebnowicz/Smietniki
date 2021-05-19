#include "Smieci.h"

/////////////////////////////
//           BIO           //
/////////////////////////////

Bio::Bio()
{
	cType = _Bio;
}

char Bio::getType()
{
	return cType;
}

/////////////////////////////
//          PLUM           //
/////////////////////////////

Plum::Plum()
{
	cType = _Plum;
	dDurability = 10;
}

char Plum::getType()
{
	return cType;
}

/////////////////////////////
//           BAG           //
/////////////////////////////

Bag::Bag()
{
	cType = _Bag;
}

char Bag::getType()
{
	return cType;
}


/////////////////////////////
//         PLASTIC         //
/////////////////////////////

Plastic::Plastic()
{
	cType = _Plastic;
}

char Plastic::getType()
{
	return cType;
}