# ContactManagementSystem
This C++ program manages a list of contacts with associated names, addresses, and phone numbers. It provides functionalities to add, display, save, and load contacts.
## Files

- **main.cpp**: Contains the main program that utilizes the ContactManager class and associated classes.
- **ContactManager.h / ContactManager.cpp**: Defines the ContactManager class responsible for managing contacts.
- **Contact.h / Contact.cpp**: Defines the Contact class, which represents an individual contact with a name, address, and phone number.
- **Name.h / Name.cpp**: Defines the Name class, which represents the name of a contact.
- **Address.h / Address.cpp**: Defines the Address class, which represents the address of a contact.

## Functions

### `vector<string> Split(const string& str, const string& delimiter)`

Splits a string `str` using the provided `delimiter` and returns a vector of strings containing the parts.

### `ContactManager::ContactManager()`

Default constructor for the ContactManager class.

### `void ContactManager::addContact(Contact contact)`

Adds a contact to the list of contacts.

### `void ContactManager::showContacts() const`

Displays all contacts in the list.

### `void ContactManager::saveContacts(ostream& out)`

Saves the contacts to an output stream in a format suitable for storage.

### `void ContactManager::loadContacts(istream& in)`

Loads contacts from an input stream and adds them to the list.

### `Contact ContactManager::getContact(int id)`

Retrieves a contact by its unique identifier `id`.

### `vector<Contact> ContactManager::getContacts(std::string l_Name)`

Retrieves all contacts with a specific last name `l_Name`.

## Name Class

### `Name::Name()`

Default constructor for the Name class.

### `Name::Name(string ln, string fn, string mn)`

Constructor that initializes the last name, first name, and middle name.

### ... (see `Name.h` and `Name.cpp` for more details)

## Address Class

### `Address::Address()`

Default constructor for the Address class.

### `Address::Address(string sa, string s, string z)`

Constructor that initializes the street address, state, and zip code.

### ... (see `Address.h` and `Address.cpp` for more details)

## Contact Class

### `Contact::Contact()`

Default constructor for the Contact class. Initializes a contact and assigns a unique identifier.

### `Contact::Contact(Name n, Address a, string p)`

Constructor that sets the name, address, and phone number for a contact.

### ... (see `Contact.h` and `Contact.cpp` for more details)

## Usage

To use this program, include the necessary header files and implement the desired functionality using the provided classes and functions.

**Example Usage**:

```cpp
#include <iostream>
#include "ContactManager.h"
#include "Name.h"
#include "Address.h"

int main() {
    // Create a ContactManager object
    ContactManager manager;

    // Add contacts
    Name name("Doe", "John", "A.");
    Address address("123 Main St", "CA", "12345");
    Contact contact(name, address, "555-1234");
    manager.addContact(contact);

    // Display contacts
    manager.showContacts();

    // Save contacts to a file
    ofstream outFile("contacts.txt");
    manager.saveContacts(outFile);
    outFile.close();

    // Load contacts from a file
    ifstream inFile("contacts.txt");
    manager.loadContacts(inFile);
    inFile.close();

    return 0;
}
```

## Note

Please make sure to include the necessary header files (`ContactManager.h`, `Name.h`, `Address.h`, `Contact.h`) in your program and link the corresponding source files (`ContactManager.cpp`, `Name.cpp`, `Address.cpp`, `Contact.cpp`) during compilation.
