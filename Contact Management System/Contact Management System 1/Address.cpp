#include "Address.h"

#include <string>
#include <iostream>
using namespace std;

//Constructors
Address::Address()
{
	//Default constructor
}

Address::Address(string sa, string s, string z)
{
	streetAddress = sa;
	state = s;
	zip = z;
}

Address::Address(const Address& a)
{
    streetAddress = a.streetAddress;
    state = a.state;
    zip = a.zip;
}

//Setters
void Address::setStreetAddress(string sa) {
	streetAddress = sa;
}

void Address::setState(string s) {
	state = s;
}

void Address::setZip(string z) {
	zip = z;
}

//Getters
string Address::getStreetAddress() const
{
	return streetAddress;
}

string Address::getState() const
{
	return state;
}

string Address::getZip() const
{
	return zip;
}

//Displays
void Address::showAddress() const {
	cout << streetAddress << ", " << state << " " << zip << endl;
}

string Address::FormatForSave(void) const
{
    return streetAddress + ", " + state + ", " + zip;
}

ostream& operator<<(ostream& out, const Address& a)
{
    out << a.streetAddress << ", " << a.state << " " << a.zip << endl;
    return out;
}

istream& operator>>(istream& in, Address& a)
{
    cout << "Enter street address: ";
    getline(in, a.streetAddress);
    cout << "Enter state: ";
    getline(in, a.state);
    cout << "Enter zip: ";
    getline(in, a.zip);
    return in;
}

