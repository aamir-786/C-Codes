#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
    string address;
};

class AddressBook {
private:
    vector<Contact> contacts;

public:
    void addContact() {
        Contact newContact;
        cout << "Enter Name: ";
        getline(cin, newContact.name);

        cout << "Enter Phone Number: ";
        getline(cin, newContact.phoneNumber);

        cout << "Enter Address: ";
        getline(cin, newContact.address);

        contacts.push_back(newContact);

        cout << "Contact added successfully!\n";
    }

    void displayContacts() {
        if (contacts.empty()) {
            cout << "No contacts available.\n";
        } else {
            cout << "Contacts:\n";
            for (const auto& contact : contacts) {
                cout << "Name: " << contact.name << "\n";
                cout << "Phone Number: " << contact.phoneNumber << "\n";
                cout << "Address: " << contact.address << "\n\n";
            }
        }
    }

    void searchContact(const string& query) {
        bool found = false;
        for (const auto& contact : contacts) {
            if (contact.name.find(query) != string::npos ||
                contact.phoneNumber.find(query) != string::npos ||
                contact.address.find(query) != string::npos) {
                cout << "Name: " << contact.name << "\n";
                cout << "Phone Number: " << contact.phoneNumber << "\n";
                cout << "Address: " << contact.address << "\n\n";
                found = true;
            }
        }

        if (!found) {
            cout << "No matching contacts found.\n";
        }
    }
};

int main() {
    AddressBook addressBook;
    int choice;
    string searchQuery;

    do {
        cout << "\nPhone/Contact Address System\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contacts\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Consume the newline character left in the stream

        switch (choice) {
            case 1:
                addressBook.addContact();
                break;
            case 2:
                addressBook.displayContacts();
                break;
            case 3:
                cout << "Enter search query: ";
                getline(cin, searchQuery);
                addressBook.searchContact(searchQuery);
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
