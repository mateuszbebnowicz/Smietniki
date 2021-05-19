#pragma once
#include "Cleaner.h"

/////////////////////////////
//       BIO_CLEANER       //
/////////////////////////////

class BioCleaner : public Cleaner
{
public:
	BioCleaner(int x, int y);

	sVec getPosition();
	char getProf();

private:
	void move(sVec v, std::vector<Cleaner *> & cl);
	bool getTrash(std::vector<Field *> & tr);
	bool throwTrash(std::vector<Field *> & tr);
	bool collision(sVec v, std::vector<Cleaner *> & cl);
};


/////////////////////////////
//       PLUM_CLEANER      //
/////////////////////////////

class PlumCleaner : public Cleaner
{
public:
	PlumCleaner(int x, int y);

	sVec getPosition();
	char getProf();

private:
	void move(sVec v, std::vector<Cleaner *> & cl);
	bool getTrash(std::vector<Field *> & tr);
	bool throwTrash(std::vector<Field *> & tr);
	bool collision(sVec v, std::vector<Cleaner *> & cl);
};


/////////////////////////////
//     PLASTIC_CLEANER     //
/////////////////////////////

class PlasticCleaner : public Cleaner
{
public:
	PlasticCleaner(int x, int y);

	sVec getPosition();
	char getProf();

private:
	void move(sVec v, std::vector<Cleaner *> & cl);
	bool getTrash(std::vector<Field *> & tr);
	bool throwTrash(std::vector<Field *> & tr);
	bool collision(sVec v, std::vector<Cleaner *> & cl);
};


/////////////////////////////
//       BAG_CLEANER       //
/////////////////////////////

class BagCleaner : public Cleaner
{
public:
	BagCleaner(int x, int y);

	sVec getPosition();
	char getProf();

private:
	void move(sVec v, std::vector<Cleaner *> & cl);
	bool getTrash(std::vector<Field *> & tr);
	bool throwTrash(std::vector<Field *> & tr);
	bool collision(sVec v, std::vector<Cleaner *> & cl);
};