#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contact[8];
		int		total;
		int		current;
	public:
		PhoneBook();
		~PhoneBook();
		void	ADD();
		void	SEARCH();
};

#endif
