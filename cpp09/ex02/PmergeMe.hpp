#ifndef _PMERGEME_HPP_
	#define _PMERGEME_HPP_

#include <string>
#include <exception>
#include <ctime>
#include <iostream>
#include <sstream>

// #include <algorithm>

#include "groupIndex.hpp"

template<class Container>
class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();

		void			MakeSequence(std::string& input);
		void			Sort();
		void			PrintNotSorted() const;
		void			PrintSorted() const;
		double			Duration() const;
		unsigned int	GetSize() const;

	private:
		PmergeMe(const PmergeMe&);
		PmergeMe&	operator=(const PmergeMe&);

		std::string		_input;
		Container		_NotSorted;
		Container		_Sorted;
		std::clock_t	_start;
		std::clock_t	_finish;

	class WrongArgument : public std::exception
	{
		virtual const char*	what() const throw();
	};
};

template<class Container>
PmergeMe<Container>::PmergeMe()
{
}

template<class Container>
PmergeMe<Container>::~PmergeMe()
{
}

template<class Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& obj)
{
	*this = obj;
}

template<class Container>
PmergeMe<Container>&	PmergeMe<Container>::operator=(const PmergeMe& obj)
{
	if (this != obj)
	{
		_input = obj._input;
		_NotSorted = obj._NotSorted;
		_Sorted = obj._Sorted;
		_start = obj._start;
		_finish = obj._finish;
	}
	return *this;
}

template<class Container>
void	PmergeMe<Container>::MakeSequence(std::string& input)
{
	std::stringstream	ss(input);
	int					nbr;

	while (!ss.eof())
	{
		ss >> nbr;
		if (ss.fail())
		{
			if (!ss.eof())
				throw PmergeMe<Container>::WrongArgument();
			else
				break ;
		}
		if (nbr < 0)
			throw PmergeMe<Container>::WrongArgument();
		_NotSorted.push_back(nbr);
		_Sorted.push_back(nbr);
	}
}

template<class Container>
void	PmergeMe<Container>::Sort()
{
	_start = std::clock();
	MergeInsertionSort(MakeGroupIndex<Container>(0, 1),
					   MakeGroupIndex<Container>(_Sorted.size(), 1),
					   _Sorted);
	_finish = std::clock();

	// if (std::is_sorted(_Sorted.begin(), _Sorted.end()))
	// 	std::cout << "\nOK\n" << std::endl;
	// else
	// 	std::cout << "\nFAIL\n" << std::endl;
}

template<class Container>
void	PmergeMe<Container>::PrintNotSorted() const
{
	typename Container::const_iterator	it = _NotSorted.begin();

	std::cout << "Before: ";
	for (; it != _NotSorted.end(); ++it)
	{
		std::cout << *it;
		if (it != --(_NotSorted.end()))
			std::cout << " ";
	}
	std::cout << std::endl;
}

template<class Container>
void	PmergeMe<Container>::PrintSorted() const
{
	typename Container::const_iterator	it = _Sorted.begin();

	std::cout << "After: ";
	for (; it != _Sorted.end(); ++it)
	{
		std::cout << *it;
		if (it != --(_Sorted.end()))
			std::cout << " ";
	}
	std::cout << std::endl;
}

template<class Container>
double	PmergeMe<Container>::Duration() const
{
	return static_cast<double>(_finish - _start) / CLOCKS_PER_SEC * 1000;
}

template<class Container>
unsigned int	PmergeMe<Container>::GetSize() const
{
	return _NotSorted.size();
}

template<class Container>
const char*	PmergeMe<Container>::WrongArgument::what() const throw()
{
	return "wrong argument form";
}

#endif
