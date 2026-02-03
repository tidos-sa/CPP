#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>

class PhoneBook {
private:
    Contact _contacts[8];
    int     _index;
    int     _count;

    std::string _truncate(std::string str) const;
    void        _displayContactRow(int index) const;

public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void searchContact() const;
};

#endif
