#include <iostream>
#include <algorithm>
#include "ContactManager.h"
#include "Name.h"
#include "Address.h"

vector<string> Split(const string& str, const string& delimiter) {
    vector<string> parts;
    size_t start = 0;
    size_t end = str.find(delimiter);

    while (end != string::npos) {
        parts.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
        end = str.find(delimiter, start);
    }

    parts.push_back(str.substr(start, end));

    return parts;
}

ContactManager::ContactManager() {
    // Default Constructor
}

void ContactManager::addContact(Contact contact) {
    contacts.push_back(contact);
}

void ContactManager::showContacts() const {
    for (const auto& contact : contacts) {
        contact.showContact(); 
    }
}

void ContactManager::saveContacts(ostream& out) {
    for (const auto& contact : contacts) {
        out << contact.FormatForSave() << endl;
    }
}

void ContactManager::loadContacts(istream& in) {
    string line;
    while (getline(in, line)) {
        vector<string> parts = Split(line, ",");
        if (parts.size() >= 7) {
            Name name(parts[0], parts[1], parts[2]);
            Address address(parts[3], parts[4], parts[5]);
            Contact newContact(name, address, parts[6]);
            addContact(newContact);
        }
    }
}

Contact ContactManager::getContact(int id) {
    auto match = find_if(contacts.begin(), contacts.end(), [id](Contact& obj) {return obj.getID() == id; });
    if (match != contacts.end()) {
        return *match;
    }
    else {
        Name name("", "", "");
        Address address("", "", "");
        Contact defaultContact(name, address, "");
        return defaultContact;
    }
}

vector<Contact> ContactManager::getContacts(std::string l_Name)
{
    auto match = find_if(contacts.begin(), contacts.end(), [l_Name](Contact& obj) {return obj.getName() == l_Name; });
    vector<Contact> ContactList;
    while (match != contacts.end()) {
        ContactList.push_back(*match);
        match = find_if(++match, contacts.end(), [l_Name](Contact& obj) {return obj.getName() == l_Name; });
    }
    return ContactList;
}
