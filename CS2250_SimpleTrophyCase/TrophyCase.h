#ifndef TROPHYCASE_H
#define TROPHYCASE_H

#include "Trophy.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrophyCase;

class TrophyCase {
public:
	// Constructors
	TrophyCase();
	// Copier
	TrophyCase(const TrophyCase& val);
	// Destructor
	~TrophyCase();
	// Operators
	friend ostream& operator<<(ostream& sout, const TrophyCase& v);
	TrophyCase& operator=(const TrophyCase& v);
	// Mutators

	// Facilitator
	int getNbrOfTrophies() const;
	int getAllocatedSize() const;
	// Operations
	void addTrophy(string tVal, int lVal, Color cval);
	bool copyTrophy(string tVal);
	bool deleteTrophy(string tVal);
	bool renameTrophy(string tVal, string nVal);
	bool relevelTrophy(string tVal, int lVal);
	bool recolorTrophy(string tVal, Color cVal);

private:
	Trophy** trophies;
	int nbrOfTrophies;
	int capacity;
	int searchTrophies(string tVal);
	void sortTrophies(Trophy* arr[]);
	//void swap(Trophy* x, Trophy* y);
};

#endif