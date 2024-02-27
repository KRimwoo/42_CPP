#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	Contact();
	~Contact();
	void		setFirstName(std::string first_name);
	void		setLastName(std::string last_name);
	void		setNickname(std::string nickname);
	void		setPhoneNumber(std::string phone_number);
	void		setDarkestSecret(std::string darkest_secret);

	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickname();
	std::string	getPhoneNumber();
	std::string	getDarkestSecret();
};


#endif