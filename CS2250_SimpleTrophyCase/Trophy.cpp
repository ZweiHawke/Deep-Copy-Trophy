#include "Trophy.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Constructors
Trophy::Trophy() {
    this->name = new string("");
    this->level = new int(0);
    this->color = new Color(BRONZE);
}

Trophy::Trophy(string nameVal) {
    this->name = new string(nameVal);
    this->level = new int(1);
    this->color = new Color(GOLD);
}

Trophy::Trophy(string nameVal, int levelVal, Color colorVal) {
    this->name = new string(nameVal);
    this->level = new int(levelVal);
    this->color = new Color(colorVal);
}

// Copiers
Trophy::Trophy(const Trophy& trophy) {
    this->name = new string(*trophy.name);
    this->level = new int(*trophy.level);
    this->color = new Color(*trophy.color);
}

// Destructor
Trophy::~Trophy() {
    // cout << "TROPHY DESTROYED" << endl;
    delete name;
    delete level;
    delete color;
}

// Operators
ostream& operator<<(ostream& sout, const Trophy& v) {
    string colorName;
    switch (*v.color) {
    case 0:
        colorName = "BRONZE";
        break;

    case 1:
        colorName = "SILVER";
        break;

    case 2:
        colorName = "GOLD";
        break;
    }
    sout << "[ " << left;
    sout.width(30); 
    sout << *v.name << " : " << right;
    sout.width(2);
    sout << *v.level << " : " << left;
    sout.width(6);
    sout << colorName << " ]";
    return sout;
}

Trophy& Trophy::operator=(const Trophy& v) {
    if (&v != this) {
        *name = *(v.name);
        *level = *(v.level);
        *color = *(v.color);
    }
    return *this;
}

const bool Trophy::operator<(const Trophy& v) const {
    if (compareTrophy(v) == -1) {
        return true;
    }
    else {
        return false;
    }
}

const bool Trophy::operator>(const Trophy& v) const {
    //TODO Greater Than
    if (compareTrophy(v) == 1) {
        return true;
    }
    else {
        return false;
    }
}

const bool Trophy::operator==(const Trophy& v) const {
    //TODO Equal To
    if (compareTrophy(v) == 0) {
        return true;
    }
    else {
        return false;
    }
}

const bool Trophy::operator!=(const Trophy& v) const {
    //TODO Not Equal To
    if (compareTrophy(v) != 0) {
        return true;
    }
    else {
        return false;
    }
}

const bool Trophy::operator<=(const Trophy& v) const {
    if (compareTrophy(v) != 1) {
        return true;
    }
    else {
        return false;
    }
    return true;
}

const bool Trophy::operator>=(const Trophy& v) const {
    //TODO Greater Than Equal To
    if (compareTrophy(v) != -1) {
        return true;
    }
    else {
        return false;
    }
}

// Mutators
void Trophy::SetName(string nameVal) { *name = nameVal; }
void Trophy::SetLevel(int levelVal) { *level = levelVal; }
void Trophy::SetColor(Color colorVal) { *color = colorVal; }

// Facilitator
string Trophy::GetName() const { return *name; }
int Trophy::GetLevel() const { return *level; }
Color Trophy::GetColor() const { return *color; }

// Operators
/*
void Trophy::Print() {
  string colorName;
  switch (*color) {
  case 0:
    colorName = "GOLD";
    break;

  case 1:
    colorName = "SILVER";
    break;

  case 2:
    colorName = "BRONZE";
    break;
  }

  cout << this << endl;
}
*/
int Trophy::compareTrophy(const Trophy& v) const {
    string nval = *name;
        if (*level != v.GetLevel()) {
            //cout << "LEVEL INEQUAL" << endl;
            if (*level < v.GetLevel()) { return -1; }
            else if (*level > v.GetLevel()) { return 1; }
            else { return -2; }
        }
        else if (*color != v.GetColor()) {
            //cout << "COLOR INEQUAL" << endl;
            if (*color < v.GetColor()) { return -1; }
            else if (*color > v.GetColor()) { return 1; }
            else { return -2; }
        }
        else if (nval.compare(v.GetName()) != 0) {
            //cout << "NAME INEQUAL" << endl;
            return nval.compare(v.GetName());
        }
        else {
            //cout << "EQUAL" << endl;
            return 0;
        }
}