#include "Address.h"

#include <string>
#include <iostream>
#include "Name.h"
using namespace std;

//Constructors
Name::Name()
{
	//Default constructor
}

Name::Name(string ln, string fn, string mn)
{
	last_name = ln;
	first_name = fn;
	middle_name = mn;
}

Name::Name(const Name &n)
{
	last_name = n.last_name;
	first_name = n.first_name;
	middle_name = n.middle_name;
}

//Setters
void Name::setLastName(string lastName)
{
	last_name = lastName;
}

void Name::setFirstName(string firstName)
{
	first_name = firstName;
}

void Name::setMiddleName(string middleName)
{
	middle_name = middleName;
}

//Getters
string Name::getLastName() const
{
	return last_name;
}

string Name::getFirstName() const
{
	return first_name;
}

string Name::getMiddleName() const
{
	return middle_name;
}

//Display
void Name::showName() const
{
	cout << last_name << ", " << first_name << " " << middle_name[0] << "." << endl;
}

string Name::FormatForSave(void) const
{
	return last_name + ", " + first_name + ", " + middle_name;
}

ostream& operator<<(ostream& out, const Name& n) {
	out << n.last_name << ", " << n.first_name << " " << n.middle_name[0] << "." << endl;
	return out;
}

istream& operator>>(istream& in, Name& n)
{
	cout << "Enter first name: ";
	getline(in, n.first_name);
	cout << "Enter last name: ";
	getline(in, n.last_name);
	cout << "Enter middle name: ";
	getline(in, n.middle_name);
	return in;
}


