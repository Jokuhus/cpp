#include <fstream>
#include <string>
#include "replaceString.hpp"

replaceString::replaceString(void)
{
}

replaceString::replaceString(std::string str1, std::string str2)
{
	this->strFrom = str1;
	this->strTo = str2;
	this->lenFrom = str1.length();
	this->lenTo = str2.length();
}

replaceString::~replaceString(void)
{
}

void	replaceString::replaceBuffer(void)
{
	size_t	pos = 0;

	pos = this->strBuffer.find(this->strFrom, pos);
	while (pos != this->strBuffer.npos)
	{
		this->strBuffer.erase(pos, this->lenFrom);
		this->strBuffer.insert(pos, this->strTo);
		pos += this->lenTo;
		pos = this->strBuffer.find(this->strFrom, pos);
	}
}

void	replaceString::replaceFile(std::ifstream &in, std::ofstream &out)
{
	while (!in.eof())
	{
		std::getline(in, this->strBuffer);
		if (!in.eof())
			this->strBuffer.append("\n");
		this->replaceBuffer();
		out << this->strBuffer;
	}
}
