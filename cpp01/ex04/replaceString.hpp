#ifndef REPLACE_STRING_CPP
# define REPLACE_STRING_CPP

# include <fstream>
# include <string>

class replaceString
{
	private:
		std::string	strBuffer;
		std::string	strFrom;
		std::string	strTo;
		size_t		lenFrom;
		size_t		lenTo;
		replaceString(void);
		void	replaceBuffer(void);
	public:
		replaceString(std::string, std::string);
		~replaceString(void);
		void	replaceFile(std::ifstream&, std::ofstream&);
};

#endif