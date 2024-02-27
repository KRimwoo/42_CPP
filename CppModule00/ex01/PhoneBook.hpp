#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
private:
	Contact	contacts[8];
	int		size;
public:
	PhoneBook();
	~PhoneBook();

	int		getSize();
	std::string	getInput(std::string prompt);
	bool	isSpace(std::string str);
	bool	isEmpty(Contact contact);
	void	setNewContact(Contact *target, Contact source);
	bool	addContact();
	bool	searchContact();
	void	printPhoneBook();
	void	printContact(Contact contact);
};

#endif