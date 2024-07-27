#include <iostream>
#include <sstream>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->total = 0;
	this->current = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::ADD()
{
	this->contact[this->current].AddContact();
	this->current = (this->current + 1) % 8;
	if (this->total < 8)
		this->total++;
}

void	PhoneBook::SEARCH()
{
	std::stringstream	ss;
	std::string			tmp;
	int					index;

	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << "|";
	std::cout << std::setw(10) << "index";
	std::cout << "|";
	std::cout << std::setw(10)  << "first name";
	std::cout << "|";
	std::cout << std::setw(10)  << "last name";
	std::cout << "|";
	std::cout << std::setw(10)  << "nickname";
	std::cout << "|" << std::endl;
	std::cout << " ------------------------------------------- " << std::endl;
	for (int i = 0; i < this->total; i++)
		this->contact[i].ShowList(i + 1);
	std::cout << "Index : ";
	if (!std::getline(std::cin, tmp))
		return ;
	ss << tmp;
	ss >> index;
	if (index > 0 && index <= this->total)
		this->contact[index - 1].ShowContact();
	else
		std::cerr << "Input is wrong!" << std::endl;
}
