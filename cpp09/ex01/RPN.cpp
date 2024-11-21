#include <iostream>
#include <cstdlib>
#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN& obj)
{
	*this = obj;
}

RPN&    RPN::operator=(const RPN& obj)
{
	if (this != &obj)
	{
		_stack = obj._stack;
	}
	return *this;
}

void    RPN::AddToStack(char c)
{
	if (std::isdigit(c))
		takeDigit(c);
	else if (c == '+')
		addition();
	else if (c == '-')
		subtraction();
	else if (c == '*')
		multiplication();
	else if (c == '/')
		division();
	else if (c == ' ')
		return;
	else
		throw	RPN::WrongArgumnet();
}

void	RPN::ShowResult() const
{
	if (_stack.size() != 1)
		throw	RPN::WrongArgumnet();
	std::cout << _stack.top() << std::endl;
}

void	RPN::checkStack() const
{
	if (_stack.size() < 2)
		throw	RPN::WrongArgumnet();
}

void	RPN::takeDigit(char c)
{
	double	nbr = c - '0';
	_stack.push(nbr);
}

void	RPN::addition()
{
	checkStack();
	
	double	b = _stack.top();
	_stack.pop();
	double	a = _stack.top();
	_stack.pop();

	_stack.push(a + b);
}

void	RPN::subtraction()
{
	checkStack();

	double	b = _stack.top();
	_stack.pop();
	double	a = _stack.top();
	_stack.pop();

	_stack.push(a - b);
}

void	RPN::multiplication()
{
	checkStack();

	double	b = _stack.top();
	_stack.pop();
	double	a = _stack.top();
	_stack.pop();

	_stack.push(a * b);
}

void	RPN::division()
{
	checkStack();

	double	b = _stack.top();
	if (b == 0)
		throw	RPN::DivideByZero();
	_stack.pop();
	double	a = _stack.top();
	_stack.pop();

	_stack.push(a / b);
}

const char*	RPN::WrongArgumnet::what() const throw()
{
	return "Error";
}

const char*	RPN::DivideByZero::what() const throw()
{
	return "Error: divide by zero";
}