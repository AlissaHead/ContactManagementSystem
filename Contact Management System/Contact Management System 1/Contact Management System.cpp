#include <iostream>
#include "ContactManager.h"
#include "Contact.h"
#include "Name.h"
#include "Address.h"
#include <fstream>

int main() {
    // Instantiate a ContactManager object
    ContactManager manager;

    // Load contacts from a file
    ifstream inFile("C:\\Users\\Scorp\\source\\repos\\Contact Management System 1\\x64\\Debug\\contacts.txt");
    if (inFile.is_open()) {
        manager.loadContacts(inFile);
        inFile.close();
    }
    else {
        cout << "File failed to open." << endl;
        return 1;
    }

    // Display contacts
    cout << "Contacts loaded from file:" << endl;
    manager.showContacts();

    // Add a new contact
    Name newName("John", "Doe", "M.");
    Address newAddress("123 Main St", "CA", "12345");
    Contact newContact(newName, newAddress, "555-1234");
    manager.addContact(newContact);

    // Display contacts after adding
    cout << "\nContacts after adding a new contact:" << endl;
    manager.showContacts();

    // Search for contacts
    string searchName = "John Doe M.";
    vector<Contact> searchResults = manager.getContacts(searchName);

    cout << "\nSearch results for \"" << searchName << "\":" << endl;
    for (const auto& contact : searchResults) {
        contact.showContact();
    }

    // Save contacts to a file
    ofstream outFile("updated_contacts.txt");
    if (outFile.is_open()) {
        manager.saveContacts(outFile);
        outFile.close();
        cout << "\nContacts saved to file." << endl;
    }
    else {
        cout << "Unable to open file for saving." << endl;
    }

    return 0;
}


