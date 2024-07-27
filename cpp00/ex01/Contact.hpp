#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		int			phone_number;
		std::string	darkest_secret;
	public:
		Contact();
		~Contact();
		void	AddContact();
		void	ShowList(int index);
		void	PrintString(std::string string);
		void	ShowContact();
};

#endif
