#ifndef _BITCOINEXCHANGE_HPP_
	#define _BITCOINEXCHANGE_HPP_

	#include <map>
	#include <string>
	#include <exception>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();

		void	SetData();
		void	Convert(std::string) const;

	private:
		void		insertData(std::string&);
		void		printResult(const std::string&) const;
		bool		ifInvalidInput(const std::string&, std::string&, std::string&) const;
		float		findPrice(const std::string&) const;
		float		calculatePrice(const std::string&, const std::string&) const;
		bool		checkDate(const std::string&) const;
		bool		checkValue(const std::string&) const;
		std::string	trimString(std::string&) const;

		std::string	trimDateData(std::string&) const;
		float		trimPriceData(std::string&) const;

		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange&	operator=(const BitcoinExchange&);

		std::map<std::string, float>	_data;

	class WrongDataForm : public std::exception
	{
		virtual const char*	what() const throw();
	};
	class CouldNotOpenFile : public std::exception
	{
		virtual const char*	what() const throw();
	};
};

#endif
