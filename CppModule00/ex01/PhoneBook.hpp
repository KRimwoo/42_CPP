#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	int		idx;
public:
	PhoneBook(/* args */);
	~PhoneBook();
	void	addContact(Contact contact);
	void	searchContact();

};

#endif~