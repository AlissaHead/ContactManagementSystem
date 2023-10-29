#include <string>
#include <format>
#include <iostream>

#include "Name.h"
#include "Address.h"
#include "Contact.h"
using namespace std;

int Contact::totalCt = 0;

void Contact::setIdentifier()
{
	totalCt++;
	identifier = totalCt;
}

//Constructors
Contact::Contact() //Contact::identifier is undefined Error C26495
{
	//Default constructor
	setIdentifier();
}

Contact::Contact(Name n, Address a, string p) : name(n), address(a), phone(p) {
	setIdentifier();
}

Contact::Contact(const Contact &c)
{
	name = c.name;
	address = c.address;
	phone = c.phone;
}

//Setters
void Contact::setName(string fn, string ln, string mn)
{
	this->name.setFirstName(fn);
	this->name.setLastName(ln);
	this->name.setMiddleName(mn);
}

void Contact::setAddress(string sa, string s, string z)
{
	this->address.setStreetAddress(sa);
	this->address.setState(s);
	this->address.setZip(z);
}

void Contact::setPhone(string p)
{
	phone = p;
}

//Getters
string Contact::getName() const
{
	return name.getLastName() + " " + name.getFirstName() + " " + name.getMiddleName();
}

string Contact::getAddress() const
{
	return address.getStreetAddress() + ", " + address.getState() + " - " + address.getZip();
}

string Contact::getPhone() const
{
	return phone;
}

int Contact::getID(void)
{
	return identifier;
}

//Displays
void Contact::showContact() const {
	name.showName();
	address.showAddress();
	cout << phone << endl;
}

string Contact::FormatForSave(void) const
{
	return name.FormatForSave() + " - " + address.FormatForSave() + " - " + phone;
}

ostream& operator<<(ostream& out, const Contact& c)
{
	out << c.name;
	out << c.address;
	out << c.phone << endl;
	return out;
}

istream& operator>>(istream& in, Contact& c)
{
	in >> c.name;
	in >> c.address;
	cout << "Enter phone number: ";
	getline(in, c.phone);
	return in;
}


