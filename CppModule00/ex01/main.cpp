#include "PhoneBook.hpp"

int	main(void)
{
    std:: string    command;
    PhoneBook       phoneBook;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if(std::cin.fail())
            return (0);
        if (command == "EXIT")
        {
            std::cout << "\nExiting..." << std::endl;
            break;
        }
        else if (command == "ADD")
        {
            if (phoneBook.addContact() == false)
                return (0);
        }
        else if (command == "SEARCH")
        {
            if (phoneBook.getSize() == 0)
            {
                std::cout << "Phonebook is empty. Add first!\n\n";
                continue;
            }
            phoneBook.printPhoneBook();
            if (phoneBook.searchContact() == false)
                return (0);
        }
        else
            std::cout << "Invalid command!" << std::endl;
    }
    return (0);
}