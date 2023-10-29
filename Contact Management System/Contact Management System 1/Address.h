#pragma once
#ifndef Address_H
#define Addess_H
#include <string>
using namespace std;

class Address {
private:
	string streetAddress;
	string state;
	string zip;
public:
	Address();
	Address(string sa, string s, string z);
	Address(const Address &a);
	void setStreetAddress(string sa);
	void setState(string state);
	void setZip(string zip);
	string getStreetAddress() const;
	string getState() const;
	string getZip() const;
	void showAddress() const;
	string FormatForSave(void) const;
	friend ostream& operator<<(ostream& out, const Address& a);
	friend istream& operator>>(istream& in, Address& a);
};

#endif Address_H