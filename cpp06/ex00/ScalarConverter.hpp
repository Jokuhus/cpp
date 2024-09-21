#ifndef _SCALARCONVERTER_HPP_
# define _SCALARCONVERTER_HPP_

# include <string>

class ScalarConverter
{
	//OCCF
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& obj);
	public:
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& obj);

	public:
		static void convert(const std::string& input);
};

#endif
