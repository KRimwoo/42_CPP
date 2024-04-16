#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->size = 0;
}

PhoneBook::~PhoneBook()
{
}

int	PhoneBook::getSize()
{
	return (this->size);
}

std::string	PhoneBook::getInput(std::string prompt)
{
	std::string input;
	std::cout << prompt;
	std::getline(std::cin, input);
	return (input);
}

bool	PhoneBook::isSpace(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
			return (false);
	}
	return (true);
}

bool	PhoneBook::isEmpty(Contact contact)
{
	if (contact.getFirstName() == "" || isSpace(contact.getFirstName()))
		return (true);
	if (contact.getLastName() == "" || isSpace(contact.getLastName()))
		return (true);
	if (contact.getNickname() == "" || isSpace(contact.getNickname()))
		return (true);
	if (contact.getPhoneNumber() == "" || isSpace(contact.getPhoneNumber()))
		return (true);
	if (contact.getDarkestSecret() == "" || isSpace(contact.getDarkestSecret()))
		return (true);
	return (false);
}

void	PhoneBook::setNewContact(Contact *target, Contact source)
{
	target->setFirstName(source.getFirstName());
	target->setLastName(source.getLastName());
	target->setNickname(source.getNickname());
	target->setPhoneNumber(source.getPhoneNumber());
	target->setDarkestSecret(source.getDarkestSecret());
}

bool	PhoneBook::addContact()
{
	Contact		newContact;
	std::string	input;
	bool		isValid;

	std::cout << std::string(43, '=') << std::endl;
	std::cout << "Adding new contact..." << std::endl;
	std::cout << std::string(43, '-') << std::endl;

	input = this->getInput("Enter first name: ");
	if (std::cin.fail())
		return (false);
	newContact.setFirstName(input);
	input = this->getInput("Enter last name: ");
	if (std::cin.fail())
		return (false);
	newContact.setLastName(input);
	input = this->getInput("Enter nickname: ");
	if (std::cin.fail())
		return (false);
	newContact.setNickname(input);
	input = this->getInput("Enter phone number: ");
	if (std::cin.fail())
		return (false);
	newContact.setPhoneNumber(input);
	input = this->getInput("Enter darkest secret: ");
	if (std::cin.fail())
		return (false);
	newContact.setDarkestSecret(input);
	isValid = !this->isEmpty(newContact);
	if (!isValid)
	{
		std::cout << "\n...invalid contact! Failed adding contact." << std::endl;
		std::cout << std::string(43, '-') << std::endl;
		return (true);
	}
	if (this->size < 8)
	{
		setNewContact(&this->contacts[this->size], newContact);
		this->size++;
	}
	else
	{
		for (int i = 0; i < 7; i++)
		{
			setNewContact(&this->contacts[i], this->contacts[i+1]);
		}
		setNewContact(&this->contacts[7], newContact);
	}
	std::cout << "\n...Contact added!" << std::endl;
	std::cout << std::string(43, '=') << std::endl;
	return (true);
}

bool	PhoneBook::searchContact()
{
	std::string	index;
	int			indexNum;

	index  = getInput("\nEnter index: ");
	if (std::cin.fail())
		return (false);
	for (unsigned int i = 0; i < index.length(); i++)
	{
		if (!isdigit(index[i]))
		{
			std::cout << "Invalid index!\n" << std::endl;
			return (true);
		}
	}
	indexNum = std::stoi(index);
	if (indexNum < 1 || indexNum > this->size)
	{
		std::cout << "Index out of range!\n" << std::endl;
		return (true);
	}
	printContact(this->contacts[indexNum - 1]);
	return (true);
}

void	PhoneBook::printPhoneBook()
{
	std::cout << std::string(43, '=') << std::endl;
	std::cout << "Searching contact..." << std::endl;
	int	size = this->getSize();
	std::cout << std::string(43, '-') << std::endl;
	std::cout << std::setw(10) << "Index" << "|"<< std::setw(10) 
		<< "First name" << "|"<< std::setw(10) << "Last name" 
		<< "|"<< std::setw(10) << "Nickname" << std::endl;
	std::cout << std::string(43, '-') << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::string firstName = this->contacts[i].getFirstName();
		std::string lastName = this->contacts[i].getLastName();
		std::string nickName = this->contacts[i].getNickname();
		if (firstName.length() > 10)
			firstName.replace(9, firstName.length() - 9, ".");
		if (lastName.length() > 10)
			lastName.replace(9, lastName.length() - 9, ".");
		if (nickName.length() > 10)
			nickName.replace(9, nickName.length() - 9, ".");
		std::cout << std::setw(10) << i + 1 << "|"<< std::setw(10) 
		<< firstName << "|" << std::setw(10) << lastName << "|" << std::setw(10) 
		<< nickName << std::endl;
	}
	std::cout << std::string(43, '-') << std::endl;
}

void	PhoneBook::printContact(Contact contact)
{
	std::cout << std::string(43, '-') << std::endl;
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
	std::cout << std::string(43, '-') << std::endl;
}
