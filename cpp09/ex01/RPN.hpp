#ifndef _RPN_HPP_
    #define _RPN_HPP_

#include <stack>
#include <exception>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN&);
		RPN&	operator=(const RPN&);

		void	AddToStack(char);
		void	ShowResult() const;

	private:
		void	checkStack() const;
		void	takeDigit(char);
		void	addition();
		void	subtraction();
		void	multiplication();
		void	division();

		std::stack<double>	_stack;

	class WrongArgumnet : public std::exception
	{
		virtual const char*	what() const throw();
	};
	class DivideByZero : public std::exception
	{
		virtual const char*	what() const throw();
	};
};

#endif