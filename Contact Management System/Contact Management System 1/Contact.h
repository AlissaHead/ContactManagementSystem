#pragma once
#ifndef Contact_H
#define Contact_H

#include <string>
#include "Name.h"
#include "Address.h"
using namespace std;

class Contact {
private:
	Name name;
	Address address;
	string phone;
	int identifier;
	void setIdentifier();
public:
	static int totalCt;

	Contact();
	Contact(Name n, Address a, string p);
	Contact(const Contact& c);

	void setName(string fn, string ln, string mn);
	void setAddress(string sa, string s, string z);
	void setPhone(string p);

	string getName() const;
	string getAddress() const;
	string getPhone() const;
	int getID(void);

	void showContact() const;
	string FormatForSave(void) const;
	
	friend ostream& operator<<(ostream& out, const Contact& c);
	friend istream& operator>>(istream& in, Contact& c);
};

#endif Contact_H