#pragma once
#ifndef ContactManager_H
#define ContactManager_H
#include "Contact.h"
#include <string>
#include <vector>

class ContactManager {
private:
	vector<Contact> contacts;
public:
	ContactManager();
	Contact getContact(int id);
	vector<Contact> getContacts(std::string l_Name);
	void addContact(Contact contact);
	void showContacts() const;
	void saveContacts(ostream &out);
	void loadContacts(istream &in);
};

#endif