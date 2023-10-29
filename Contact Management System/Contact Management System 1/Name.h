#pragma once
#ifndef Name_H
#define Name_H
#include <string>
using namespace std;

class Name {
private:
	string last_name;
	string first_name;
	string middle_name;

public:
	Name();
	Name(string ln, string fn, string mn);
	Name(const Name &n);
	void setLastName(string lastName);
	void setFirstName(string firstName);
	void setMiddleName(string middleName);
	string getLastName() const;
	string getFirstName() const;
	string getMiddleName() const;
	void showName() const;
	string FormatForSave(void) const;
	friend ostream& operator<<(ostream& out, const Name& n);
	friend istream& operator>>(istream& in, Name& n);
};

#endif Name_H