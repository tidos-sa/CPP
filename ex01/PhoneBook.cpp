#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : _index(0), _count(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact() {
    std::string input;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, input);
    _contacts[_index].setFirstName(input);

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, input);
    _contacts[_index].setLastName(input);

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, input);
    _contacts[_index].setNickname(input);

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, input);
    _contacts[_index].setPhoneNumber(input);

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, input);
    _contacts[_index].setDarkestSecret(input);

    _index = (_index + 1) % 8;
    if (_count < 8)
        _count++;
    std::cout << "Contact added successfully!" << std::endl;
}

std::string PhoneBook::_truncate(std::string str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::_displayContactRow(int index) const {
    std::cout << "|" << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << _truncate(_contacts[index].getFirstName());
    std::cout << "|" << std::setw(10) << _truncate(_contacts[index].getLastName());
    std::cout << "|" << std::setw(10) << _truncate(_contacts[index].getNickname());
    std::cout << "|" << std::endl;
}

void PhoneBook::searchContact() const {
    if (_count == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (int i = 0; i < _count; i++) {
        _displayContactRow(i);
    }
    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "Enter index to display details: ";
    std::string input;
    if (!std::getline(std::cin, input)) return;

    if (input.length() == 1 && input[0] >= '0' && input[0] < '0' + _count) {
        int idx = input[0] - '0';
        std::cout << "First Name: " << _contacts[idx].getFirstName() << std::endl;
        std::cout << "Last Name: " << _contacts[idx].getLastName() << std::endl;
        std::cout << "Nickname: " << _contacts[idx].getNickname() << std::endl;
        std::cout << "Phone Number: " << _contacts[idx].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << _contacts[idx].getDarkestSecret() << std::endl;
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}
