#ifndef TROPHY_H
#define TROPHY_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum Color { BRONZE, SILVER, GOLD };
class Trophy;

class Trophy {
public:
	// Constructors
	Trophy();
	Trophy(string nameVal);
	Trophy(string nameVal, int levelVal, Color colorVal);

	// Copier
	Trophy(const Trophy& trophy);

	// Destructor
	~Trophy();

	// Operator
	friend ostream& operator<<(ostream& sout, const Trophy& v);
	Trophy& operator=(const Trophy& v);
	const bool operator < (const Trophy& v) const;
	const bool operator > (const Trophy& v) const;
	const bool operator == (const Trophy& v) const;
	const bool operator != (const Trophy& v) const;
	const bool operator <= (const Trophy& v) const;
	const bool operator >= (const Trophy& v) const;

	// Mutators
	void SetName(string nameVal);
	void SetLevel(int levelVal);
	void SetColor(Color colorVal);

	// Facilitator
	string GetName() const;
	int GetLevel() const;
	Color GetColor() const;

	// Operators
	void Print();

private:
	string* name;
	int* level;
	Color* color;
	int compareTrophy(const Trophy& v) const;
};

#endif