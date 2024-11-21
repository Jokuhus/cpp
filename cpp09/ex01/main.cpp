#include <string>
#include <iostream>
#include "RPN.hpp"

int	main(int argc, char**argv)
{
	std::string	arg;
	RPN	rpn;

	for (int i = 1; i < argc; ++i)
	{
		arg = arg + argv[i];
	}
	
	try
	{
		for (unsigned int i = 0; i < arg.size(); ++i)
			rpn.AddToStack(arg[i]);
		rpn.ShowResult();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}