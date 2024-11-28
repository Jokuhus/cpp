#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"

int	main(int argc, char**argv)
{
	std::string					input;
	PmergeMe<std::vector<int> >	vec;
	PmergeMe<std::deque<int> >	deq;

	if (argc == 1)
	{
		std::cerr << "error: argument required\n";
		return 1;
	}
	for (int i = 1; i < argc; ++i)
	{
		input.append(argv[i]);
		input.append(" ");
	}

	try
	{
		vec.MakeSequence(input);
		deq.MakeSequence(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << "error: " << e.what() << '\n';
		return 1;
	}

	vec.Sort();
	deq.Sort();

	vec.PrintNotSorted();
	vec.PrintSorted();
	std::cout << "Time to process a range of " << vec.GetSize() \
			  << " elements with std::vector : " << vec.Duration() \
			  << " us\n";

	std::cout << "Time to process a range of " << deq.GetSize() \
			  << " elements with std::deque : " << deq.Duration() \
			  << " us\n";

	return 0;
}
