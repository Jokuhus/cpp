#include <iostream>
#include <sstream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact()
{
	this->first_name = "Default";
	this->last_name = "Default";
	this->nickname = "Default";
	this->phone_number = 0;
	this->darkest_secret = "default";
}

Contact::~Contact()
{
}

void	Contact::AddContact()
{
	std::stringstream	ss;
	std::string			tmp;

	std::cout << "first name : ";
	if (!std::getline(std::cin, this->first_name))
		return ;
	std::cout << "last name : ";
	if (!std::getline(std::cin, this->last_name))
		return ;
	std::cout << "nickname : ";
	if (!std::getline(std::cin, this->nickname))
		return ;
	std::cout << "phone number : ";
	if (!std::getline(std::cin, tmp))
		return ;
	ss << tmp;
	ss >> this->phone_number;
	std::cout << "darkest secret : ";
	if (!std::getline(std::cin, darkest_secret))
		return ;
}

void	Contact::ShowList(int index)
{
	std::cout << "|";
	std::cout << std::setw(10) << index;
	std::cout << "|";
	this->PrintString(this->first_name);
	std::cout << "|";
	this->PrintString(this->last_name);
	std::cout << "|";
	this->PrintString(this->nickname);
	std::cout << "|" << std::endl;
	std::cout << " ---------- ---------- ---------- ---------- " << std::endl;
}

void	Contact::PrintString(std::string string)
{
	if (string.size() > 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << string[i];
		std::cout << ".";
	}
	else
		std::cout << std::setw(10) << string;
}

void	Contact::ShowContact()
{
	std::cout << "first name : " << this->first_name << std::endl;
	std::cout << "last name : " << this->last_name << std::endl;
	std::cout << "nickname : " << this->nickname << std::endl;
	std::cout << "phone number : " << this->phone_number << std::endl;
	std::cout << "darkest secret : " << this->darkest_secret << std::endl;
}
