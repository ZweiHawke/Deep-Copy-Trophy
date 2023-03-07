#include "TrophyCase.h"
#include "Trophy.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h> 
using namespace std;

// Constructors
TrophyCase::TrophyCase() {
	capacity = 10;
	trophies = new Trophy*[capacity];
	nbrOfTrophies = 0;
}

// Copier
TrophyCase::TrophyCase(const TrophyCase& val) {
	//cout << "COPY" << endl;
	trophies = new Trophy * [val.getAllocatedSize()];
	for (int i = 0; i < val.getNbrOfTrophies(); i++) {
		trophies[i] = new Trophy(*(val.trophies[i]));
	}
	nbrOfTrophies = val.getNbrOfTrophies();
	capacity = val.getAllocatedSize();
}

// Destructor
TrophyCase::~TrophyCase() {
	for (int i = 0; i < nbrOfTrophies; i++) {
		delete trophies[i];
	}
	delete[] trophies;
}

// Operators
ostream& operator<<(ostream& sout, const TrophyCase& v) {
	for (int i = 0; i < v.getNbrOfTrophies(); i++) {
		sout << *(v.trophies[i]) << endl;
	}
	return sout;
}

TrophyCase& TrophyCase::operator=(const TrophyCase& v) {
	if (&v != this) {
		//Delete Trophy List
		for (int i = 0; i < nbrOfTrophies; i++) {
			delete trophies[i];
		}
		delete[] trophies;
		//
		trophies = new Trophy*[v.getAllocatedSize()];
		for (int i = 0; i < v.getNbrOfTrophies(); i++) {
			trophies[i] = new Trophy(*(v.trophies[i]));
		}
		nbrOfTrophies = v.getNbrOfTrophies();
		capacity = v.getAllocatedSize();
	}
	return *this;
}

// Mutators

// Facilitator
int TrophyCase::getNbrOfTrophies() const {
	return nbrOfTrophies;
}

int TrophyCase::getAllocatedSize() const {
	return capacity;
}

// Operations
void TrophyCase::addTrophy(string tVal, int lVal, Color cVal) {
	if (nbrOfTrophies < capacity) {
		trophies[nbrOfTrophies] = new Trophy(tVal, lVal, cVal);
		//cout << *trophies[nbrOfTrophies] << endl;
		++nbrOfTrophies;
	}
	else {
		//cout << "CAPACITY TRIGGERED" << endl;
		capacity += round(capacity/10);
		//cout << capacity << " CAPACITY ADDED" << endl;
		Trophy** temp = new Trophy * [capacity];
		//cout << "EXPANDED" << endl;
		copy(trophies, trophies + nbrOfTrophies, temp);
		//cout << "ARRAY COPY" << endl;
		for (int i = 0; i < nbrOfTrophies; i++) {
			//delete trophies[i];
		}
		delete[] trophies;
		//cout << "ARRAY DELETED" << endl;
		trophies = temp;
		//cout << "TROPHY ARRAY REPLACED" << endl;
		//Add Trophy
		trophies[nbrOfTrophies] = new Trophy(tVal, lVal, cVal);
		//cout << "ADD NEW TROPHY AT CAPACITY" << endl;
		//cout << *trophies[nbrOfTrophies] << endl;
		++nbrOfTrophies;
		//cout << "ADD TROPHIES" << endl;
		//cout << *trophies[nbrOfTrophies] << endl;
	}
	sortTrophies(trophies);
}

bool TrophyCase::copyTrophy(string tVal) {
	int search = searchTrophies(tVal);
	if (search == -1) {
		return false;
	}
	else {
		Trophy result = *trophies[search];
		addTrophy(result.GetName(), result.GetLevel(), result.GetColor());
		return true;
	}
}

bool TrophyCase::deleteTrophy(string tVal) {
	int search = searchTrophies(tVal);
	if (search == -1) {
		return false;
	}
	else {
		delete trophies[search];
		trophies[search] = trophies[nbrOfTrophies-1];
		//cout << nbrOfTrophies << endl;
		--nbrOfTrophies;
		sortTrophies(trophies);
		return true;
	}
}

bool TrophyCase::renameTrophy(string tVal, string nVal) {
	int search = searchTrophies(tVal);
	if (search == -1) {
		return false;
	}
	else {
		trophies[search]->SetName(nVal);
		sortTrophies(trophies);
		return true;
	}
}

bool TrophyCase::relevelTrophy(string tVal, int lVal) {
	int search = searchTrophies(tVal);
	if (search == -1) {
		return false;
	}
	else {
		trophies[search]->SetLevel(lVal);
		sortTrophies(trophies);
		return true;
	}
}

bool TrophyCase::recolorTrophy(string tVal, Color cVal) {
	int search = searchTrophies(tVal);
	if (search == -1) {
		return false;
	}
	else {
		trophies[search]->SetColor(cVal);
		sortTrophies(trophies);
		return true;
	}
}

//Helpers
int TrophyCase::searchTrophies(string tVal) {
	int pos = -1;
	for (int i = 0; i < nbrOfTrophies; i++) {
		if (trophies[i]->GetName() == tVal) {
			pos = i;
			break;
		}
	}
	return pos;
}

void TrophyCase::sortTrophies(Trophy* arr[]) {
	int i, j;
	//cout << "SORTING" << endl;
	//cout << nbrOfTrophies << " TROPHIES" << endl;

	for (i = 0; i < nbrOfTrophies - 1; i++) {
		//cout << i << endl;
		for (j = 0; j < nbrOfTrophies - i - 1; j++) {
			//cout << j << endl;
			if (*arr[j] > *arr[j + 1]) {
				//cout << capacity << endl;
				swap(arr[j], arr[j + 1]);
			}
			//cout << "FAIL" << endl;
		}
	}
}

/*
void TrophyCase::swap(Trophy *x, Trophy *y) {
	Trophy temp = *x;
	*x = *y;
	*y = temp;
}
*/
