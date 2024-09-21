#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	std::string	cmd;

	while (true)
	{
		if (std::cin.eof())
			break ;
		std::cout << "Command : ";
		if (!std::getline(std::cin, cmd))
			break ;
		if (cmd == "EXIT")
			break ;
		else if (cmd == "ADD")
			phone_book.ADD();
		else if (cmd == "SEARCH")
			phone_book.SEARCH();
		else
			std::cerr << "Incorrect command" << std::endl;
	}
	return (0);
}