#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void Contact::setFirstName(std::string str) { _firstName = str; }
void Contact::setLastName(std::string str) { _lastName = str; }
void Contact::setNickname(std::string str) { _nickname = str; }
void Contact::setPhoneNumber(std::string str) { _phoneNumber = str; }
void Contact::setDarkestSecret(std::string str) { _darkestSecret = str; }

std::string Contact::getFirstName() const { return _firstName; }
std::string Contact::getLastName() const { return _lastName; }
std::string Contact::getNickname() const { return _nickname; }
std::string Contact::getPhoneNumber() const { return _phoneNumber; }
std::string Contact::getDarkestSecret() const { return _darkestSecret; }
